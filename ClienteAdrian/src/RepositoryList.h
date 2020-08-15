//
// Created by julian_camacho on 14/8/20.
//

#ifndef GOT_REPOSITORYLIST_H
#define GOT_REPOSITORYLIST_H
#include "Repository.h"
#include "json.hpp"
#include <string>

using json = nlohmann::json;


class RepositoryList {

    vector<Repository*> repositories;

public:

    RepositoryList();

    void addRepository(Repository* repo);

    json getRepositoriesFromJson();

    void changeRepositoryFromJson();

    const vector<Repository *> &getRepositories() const;

    void setRepositories(const vector<Repository *> &repositories);

    void generateJson();

    void createJsonFile(string json);

    void addCommand(string repoName);

    void createJsonFile(json j);
};



#endif //GOT_REPOSITORYLIST_H
