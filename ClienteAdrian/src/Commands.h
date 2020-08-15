//
// Created by julian_camacho on 13/8/20.
//

#ifndef GOT_COMMANDS_H
#define GOT_COMMANDS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <dirent.h>
#include <sys/types.h>
#include <cstdlib>
#include <stdlib.h>
#include <sys/stat.h>
//#include "FileNode.h"
#include "Repository.h"

using namespace std;


/**
 * Imprime una lista
 * @param list
 */
void printList(vector<FileNode> list){
    for (auto & i : list) {
        cout << i.getName() << endl;
    }
}

/**
 * Actualiza los repositorios locales
 * @return json actualizado
 */
json getRepositoriesFromJson2() {
    string path = "./config/config.json";
    // read a JSON file
    ifstream i(path);
    json j;
    i >> j;
    cout << j << endl;
    return j;
}

/**
 * Actualiza el json de los commits
 * @return json
 */
json getCommitRegisterFromJson() {
    string path = "./config/commitRegister.json";
    // read a JSON file
    ifstream i(path);
    json j;
    i >> j;
    cout << j << endl;
    return j;
}

/**
 * Comunicación con el server para los commits
 * @param commitStructure
 * @return
 */
//Hace el commit a la base de datos, la base de datos devuelve un id para identificar cada commit
string commitToServer(json commitStructure){

    RestClient::Response r = RestClient::post("http://localhost:8080/newCommit", "application/json", commitStructure.dump());
    cout << r.body << endl;
    return r.body;
}

/**
 * Crea el json de los repositorios locales
 * @param j
 */
void createJsonFile2(json j){
    ofstream file;
    cout << "Crea json" << endl;
    file.open("./config/config.json", ios::out);
    file << j.dump();
    file.close();
}

/**
 * Crea el json de los commits
 * @param j
 */
void createJsonCommitRegister(json j){
    ofstream file;
    cout << "Crea json" << endl;
    file.open("./config/commitRegister.json", ios::out);
    file << j.dump();
    file.close();
}

/**
 * Ejecuta el comando reset
 * @param content
 * @param path
 */
void resetContent(string content, string path){
/*
    ifstream archivo(path);

    if(archivo.fail()){
        cerr << "Error al abrir el archivo " + path << endl;
        return;
    }else{

        ofstream archivo;  // objeto de la clase ofstream

        archivo.open(path);

        archivo << path;

        archivo.close();

    }



*/


    ofstream outDir;
    outDir.open (path);
    outDir << content;
    outDir.close();


}

/**
 * Lee el contenido de un archivo de texto
 * @param file
 * @return
 */
string parseContent(string file){

    fstream archive;

    string line;
    string content = "";

    if (!archive.is_open()){
        cout << "archivo no esta abierto" << endl;
        archive.open(file.c_str(), ios::in);

        while (!archive.eof()){
            getline(archive,line);
            content += line + "\n";
            cout <<line << endl;
        }

        archive.close();

    }

    return content;

    /*
    ifstream toParseFile(file);
    string line;
    if (toParseFile.is_open()) {
        while (getline(toParseFile, line)) {
            cout << line << '\n';
        }
        toParseFile.close();
    }
     */

}



vector<string> commitCommand(){
    vector<string> compressedFiles;
    //for (auto & file : fileVector) {
    /*if(file.toCommit == true){
        buildHuffmanTree(parseContent(file));
        compressedFiles.pushback(file);
    }*/
    //}
    return compressedFiles;
}

void statusCommand(){

}


//??
uint32_t checksum(std::ifstream& file)
{
    uint32_t checksum = 0;
    unsigned shift = 0;
    for (uint32_t ch = file.get(); file; ch = file.get()) {
        checksum += (ch << shift);
        shift += 8;
        if (shift == 32) {
            shift = 0;
        }
    }
    return checksum;
}


#endif //GOT_COMMANDS_H
