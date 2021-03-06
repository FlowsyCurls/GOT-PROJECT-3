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
/*
void addCommand(string repoName) {
    for (int i = 0; i < repositories.size(); ++i) {
        if (repositories.at(i)->getName() == repoName){
            repositories.at(i)->addCommand();
            break;
        }
    }
}*/

void createJsonFile2(json j){
    ofstream file;
    cout << "Crea json" << endl;
    file.open("./config/config.json", ios::out);
    file << j.dump();
    file.close();
}



string parseContent(const string& file){
    ifstream toParseFile(file);
    string line;
    if (toParseFile.is_open()) {
        while (getline(toParseFile, line)) {
            cout << line << '\n';
        }
        toParseFile.close();
    }
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
