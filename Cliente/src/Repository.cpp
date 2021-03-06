//
// Created by julian_camacho on 13/8/20.
//

#include "Repository.h"


void Repository::createDir() {
    int status = mkdir(this->name.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (status == -1)
        cerr << "Error" << endl;
    else
        cout << "Directories are created" << endl;
}

void Repository::createGotIgnoreFile(){
    // Create and open a text file
    ofstream gotIgnore(this->name + "/.gotignore");
    cout << "Creado el gotignore" << endl;
    gotIgnore.close();
}

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

json Repository::generateListFilesJson(){

    json j;

    vector<FileNode*> fileNodes = this->getFiles();

    for (int i = 0; i < fileNodes.size(); ++i) {
        json objFile;
        //Creo objeto que representan los archivos individuales
        objFile["name"] = fileNodes[i]->getName();
        objFile["toCommit"] = fileNodes[i]->isToCommit();
        objFile["huffmanCode"] = fileNodes[i]->getHuffmanCode();

        //Meto el objeto a la lista json
        j.push_back(objFile);

    }

    return j;
}

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

json Repository::addToJson(json repoList){
    repoList[this->getName()] = {};
    return repoList;
}


json Repository::initCommand(json repoList) {
    this->createDir();
    this->createGotIgnoreFile();
    return this->addToJson(repoList);
}

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

void Repository::addCommandSingleFile(string file){
    vector<string> toIgnoreFiles = readGotIgnoreFile();
    //if (isFileIgnored(file, toIgnoreFiles)) {
    //Meterlo a la lista de los archivos que tiene el server
    //file.toCommit = true;
    //}
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
}

