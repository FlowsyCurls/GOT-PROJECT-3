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

void printList(vector<FileNode> list){
    for (auto & i : list) {
        cout << i.getName() << endl;
    }
}

json getRepositoriesFromJson2() {
    string path = "./config/config.json";
    // read a JSON file
    ifstream i(path);
    json j;
    i >> j;
    cout << j << endl;
    return j;
}

json getCommitRegisterFromJson() {
    string path = "./config/commitRegister.json";
    // read a JSON file
    ifstream i(path);
    json j;
    i >> j;
    cout << j << endl;
    return j;
}

//Hace el commit a la base de datos, la base de datos devuelve un id para identificar cada commit
string commitToServer(json commitStructure){

    RestClient::Response r = RestClient::post("http://localhost:8080/newCommit", "application/json", commitStructure.dump());
    cout << r.body << endl;
    return r.body;
}

void createJsonFile2(json j){
    ofstream file;
    cout << "Crea json" << endl;
    file.open("./config/config.json", ios::out);
    file << j.dump();
    file.close();
}

void createJsonCommitRegister(json j){
    ofstream file;
    cout << "Crea json" << endl;
    file.open("./config/commitRegister.json", ios::out);
    file << j.dump();
    file.close();
}

void resetContent(string content, string path){

    ofstream outDir;
    outDir.open (path);
    outDir << content;
    outDir.close();

}

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
