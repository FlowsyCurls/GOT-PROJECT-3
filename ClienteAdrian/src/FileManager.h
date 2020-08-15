//
// Created by julian_camacho on 13/8/20.
//

#ifndef GOT_FILEMANAGER_H
#define GOT_FILEMANAGER_H
#include <iostream>
#include <fstream>
#include "../json.hpp"
#include "Repository.h"

using namespace std;
using json = nlohmann::json;




void parseJson2(Repository* repo){
    json j;
    j[repo]["name"] = repo->getName();
    json fileNodeList;
    for (int k = 0; k < repo->getFiles().size(); ++k) {
        json fileNode;
        fileNode["name"] = repo->getFiles().at(k).getName();
        fileNode["toCommit"] = repo->getFiles().at(k).isToCommit();
        fileNodeList.push_back(fileNode);
    }
    j[repo]["files"] = fileNodeList;
    string n = j.dump();
    cout << n << endl;
    //createJsonFile(n);
}




#endif //GOT_FILEMANAGER_H
