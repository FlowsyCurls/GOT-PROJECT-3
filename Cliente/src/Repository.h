//
// Created by julian_camacho on 13/8/20.
//

#ifndef GOT_REPOSITORY_H
#define GOT_REPOSITORY_H
#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#include <dirent.h>
#include "FileNode.h"
#include "../json.hpp"

using json = nlohmann::json;
using namespace std;

class Repository {
    string name;
    vector<FileNode*> files;

public:
    Repository();

    Repository(string pName);

    const string &getName() const;

    void setName(const string &name);

    const vector<FileNode*> &getFiles() const;

    void setFiles(const vector<FileNode *> &files);

    void clearList();

    void createDir();

    void createGotIgnoreFile();

    vector<string> readGotIgnoreFile();

    json initCommand(json repoList);

    void addCommand();

    vector<FileNode*> getDirFiles();

    bool isFileIgnored(string file, vector<string> ignoredFiles);

    json addCommandSingleFile(string file);

    json addToJson(json repoList);

    json generateListFilesJson();
};


#endif //GOT_REPOSITORY_H
