//
// Created by julian_camacho on 14/8/20.
//

#include "RepositoryList.h"
#include "Repository.h"
#include "../json.hpp"



void RepositoryList::addRepository(Repository* repo) {
    this->repositories.push_back(repo);
}

/**
 * createJsonFile Crea el archivo json a partir de un string
 * @param json string en formato json
 */
void RepositoryList::createJsonFile(json j){
    ofstream file;
    cout << "Crea json" << endl;
    file.open("./config/config.json", ios::out);
    file << j.dump();
    file.close();
}


RepositoryList::RepositoryList() {

}

json RepositoryList::getRepositoriesFromJson() {
    string path = "./config/config.json";
    // read a JSON file
    ifstream i(path);
    json j;
    i >> j;
    cout << j << endl;
    cout << j["repoList"] << endl;
    return j;
}

void RepositoryList::changeRepositoryFromJson() {

}

const vector<Repository *> &RepositoryList::getRepositories() const {
    return repositories;
}

void RepositoryList::setRepositories(const vector<Repository *> &repositories) {
    RepositoryList::repositories = repositories;
}

void RepositoryList::addCommand(string repoName) {
    for (int i = 0; i < repositories.size(); ++i) {
        if (repositories.at(i)->getName() == repoName){
            repositories.at(i)->addCommand();
            break;
        }
    }
}



