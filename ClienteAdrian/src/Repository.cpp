
#include <restclient-cpp/restclient.h>
#include "Repository.h"

/**
 * Crea el directorio de del repositorio creado
 */
void Repository::createDir() {
    int status = mkdir(this->name.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (status == -1)
        cerr << "Error" << endl;
    else
        cout << "Directories are created" << endl;
}

/**
 * Crea el archivo gotignore
 */
void Repository::createGotIgnoreFile(){
    // Create and open a text file
    ofstream gotIgnore(this->name + "/.gotignore");
    cout << "Creado el gotignore" << endl;
    gotIgnore.close();
}

/**
 * Lee el contenido del gotignore
 * @return
 */
vector<string> Repository::readGotIgnoreFile(){
    // read and open a text file
    ifstream gotIgnore(this->name + "/.gotignore");
    vector<string> toIgnoreFiles;
    string line;
    if (gotIgnore.is_open()){
        while ( getline (gotIgnore,line) ){
            cout << line << '\n';
            toIgnoreFiles.push_back(line);
        }
        gotIgnore.close();
    }
    return toIgnoreFiles;
}

/**
 * Obtiene los archivos de un directorio
 * @return
 */
vector<FileNode*> Repository::getDirFiles() {
    struct dirent *entry;
    DIR *dir = opendir(this->name.c_str());
    vector<FileNode*> listDir;
    if (dir != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            string s1(entry->d_name);
            if(s1 != "." && s1 != ".."){
                listDir.push_back(new FileNode(entry->d_name));
            }
        }
    }
    closedir(dir);
    generateListFilesJson();
    return listDir;
}

/**
 * Genera un json con los archivos de un directorio
 * @return
 */
json Repository::generateListFilesJson(){

    json j;

    vector<FileNode*> fileNodes = this->getFiles();

    for (int i = 0; i < fileNodes.size(); ++i) {
        json objFile;
        //Creo objeto que representan los archivos individuales
        objFile["name"] = fileNodes[i]->getName();
        objFile["toCommit"] = fileNodes[i]->isToCommit();
        objFile["huffmanCode"] = fileNodes[i]->getHuffmanCode();
        objFile["content"] = fileNodes[i]->getContent();

        //Meto el objeto a la lista json
        j.push_back(objFile);

    }

    return j;
}

/**
 * Revisa si un archivo está en el gotignore, por lo que debe ser ignorado
 * @param file
 * @param ignoredFiles
 * @return
 */
bool Repository::isFileIgnored(string file, vector<string> ignoredFiles){
    bool isIgnored = false;
    for (auto & ignoredFile : ignoredFiles) {
        if (file == ignoredFile){
            isIgnored = true;
            break;
        }
    }
    return isIgnored;
}

/**
 * Añade un archivo al json de repositorios
 * @param repoList
 * @return
 */
json Repository::addToJson(json repoList){
    repoList[this->getName()] = {};
    return repoList;
}

/**
 * Ejecuta lo necesario para inicializar un repositorio
 * @param repoList
 * @return
 */
json Repository::initCommand(json repoList) {
    this->createDir();
    this->createGotIgnoreFile();
    return this->addToJson(repoList);
}

/**
 * Ejecuta lo necesario para añadir los archivos en la carpeta del repositorio
 * @param repoList
 * @return
 */
void Repository::addCommand() {
    vector<string> toIgnoreFiles = readGotIgnoreFile();
    vector<FileNode*> toAdd;
    vector<FileNode*> toAddFiles = getDirFiles();
    for (auto & toAddFile : toAddFiles) {
        if (!isFileIgnored(toAddFile->getName(), toIgnoreFiles)){ //&& cambió el archivo (hay que actualizarlo)
            //Meterlo a la lista de los archivos que tiene el server
            toAdd.push_back(toAddFile); //Los meto al repo
            toAddFile->setToCommit(true);
        }
    }
    setFiles(toAdd);
}

/**
 * Ejecuta lo necesario para añadir un solo archivo de la carpeta del repositorio
 * @param repoList
 * @return
 */
json Repository::addCommandSingleFile(string file){
    vector<string> toIgnoreFiles = readGotIgnoreFile();

    if (!isFileIgnored(file, toIgnoreFiles)) {

        json j;

        j["name"] = file;
        j["toCommit"] = true;
        j["huffmanCode"] = "";

        //Meterlo a la lista de los archivos que tiene el server
        return j;
    }
}

/**
 * Ejecuta lo necesario para hacer un commit al server
 * @param repoList
 * @return
 */
json Repository::createCommit(string name, string message, json listFileNodes){
    json commit;
    commit["repositoryName"] = name;
    commit["message"] = message;
    commit["fileList"] = listFileNodes;

    return commit;

}

/**
 * Ejecuta lo necesario para hacer un rollback
 * @param repoList
 * @return
 */
string Repository::rollbackCommand(json rollbackInfo){

    RestClient::Response r = RestClient::post("http://localhost:8080/rollback", "application/json", rollbackInfo.dump());
    return r.body;

}

string Repository::resetCommand(json){

}

const string &Repository::getName() const {
    return name;
}

void Repository::setName(const string &name) {
    Repository::name = name;
}

void Repository::setFiles(const vector<FileNode *> &files) {
    Repository::files = files;
}

const vector<FileNode*> &Repository::getFiles() const {
    return files;
}

void Repository::clearList(){
    files.clear();
}

Repository::Repository(string pName) {
    Repository::name = pName;
    Repository::files = {};
}
