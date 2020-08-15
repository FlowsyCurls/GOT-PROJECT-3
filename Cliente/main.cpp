#include <iostream>
#include "restclient-cpp/restclient.h"
#include "src/Commands.h"
#include "src/Repository.h"
#include "json.hpp"
#include "src/RepositoryList.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {

    //Validar si los argumentos son nulos, para que no se caiga

    cout << argc << endl;
    if(argc < 2){
        return 0;
    }
    json repoList = getRepositoriesFromJson2();

    string command = argv[1];

    if (command == "init" && argv[2] != NULL) {

        Repository* repo = new Repository(argv[2]);
        repoList = repo->initCommand(repoList);
        // Que mande el init al server, crea el repo
    }

    if (command == "add" && argv[2] != NULL && argv[3] != NULL){
        if (argv[2] == "-A"){
            //El name del repo existe, le asigno la lista de objetos json
            if(repoList[argv[3]] != NULL){
                
            }
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

    RestClient::Response r = RestClient::get("http://localhost:8080/user_manager");
    cout << r.body << endl;

    RestClient::Response r1 = RestClient::get("http://localhost:8080/hola");
    cout << r1.body;*/

    return 0;

}
