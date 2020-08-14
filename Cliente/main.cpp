#include <iostream>
#include "restclient-cpp/restclient.h"
#include "src/Commands.h"
#include "src/Repository.h"
#include "json.hpp"
#include "src/RepositoryList.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {

    json repoList = getRepositoriesFromJson2();
    string command = argv[1];

    if (command == "init") {
        Repository* repo = new Repository(argv[2]);
        repoList = repo->initCommand(repoList);
    }

    if (command == "add"){
        if (argv[2] == "-A"){
            //repoList->addCommand(argv[3]);
        } else{

        }
    }

    if (command == "help"){

    }
    createJsonFile2(repoList);


    /*
    for(int i = 0; i < argc; i++){
        printf("argumento %d, %s\n", i, argv[i]);
    }
*/
    //getDirFiles("/home/julian_camacho/Documentos");
    //RestClient::Response r = RestClient::get("http://www.google.com");
    //cout << r.body;

    return 0;

}
