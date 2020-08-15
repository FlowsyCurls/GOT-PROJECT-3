#include <iostream>
#include "restclient-cpp/restclient.h"
#include "src/Commands.h"
#include "src/Repository.h"
#include "json.hpp"
#include "src/RepositoryList.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {

<<<<<<< HEAD
    RestClient::Response r = RestClient::get("http://localhost:8080/Repositories");
    cout << r.body << endl;

=======
    //Validar si los argumentos son nulos, para que no se caiga

    //cout << argc << endl;
    if(argc < 2){
        return 0;
    }
>>>>>>> 19406b3444ea3090580dd2999b3978feae1d4f58
    json repoList = getRepositoriesFromJson2();

    string command = argv[1];

<<<<<<< HEAD
    cout << "argc " << argc << endl;

    if (command == "init" && argc > 2) {
=======
    if (command == "init" && argv[2] != NULL) {

<<<<<<< HEAD
>>>>>>> 19406b3444ea3090580dd2999b3978feae1d4f58
=======
        cout << argv[2] << endl;
>>>>>>> 1198f2de9edaf69bba879e491fe3be1ca0fde26b
        Repository* repo = new Repository(argv[2]);
        repoList = repo->initCommand(repoList);
        //string  s = "prueba";
        json j;

        //string s(argv[2]);
        j["name"] =  "hola";
        //
        RestClient::Response r = RestClient::post("http://localhost:8080/Repository?repository={\"name\": \"bla\"}", "application/json", "");
        // Que mande el init al server, crea el repo
    }
    cout << argv[2] << argv[3]  << endl;
    if (command == "add" && argv[2] != NULL && argv[3] != NULL){
        cout << "pasa" << endl;
        // s es el repo que indica el usuario o el comando -A
        string s(argv[2]);
        if (s == "-A"){
            //El name del repo existe, le asigno la lista de objetos json
            cout << "ejecuta add -A" << endl;
            Repository* repo = new Repository(argv[3]);
            //Se hacen repos para utilizar funcionalidades
            repo->addCommand();
            repoList[argv[3]] = repo->generateListFilesJson();


            //repoList[argv[3]] = repo->getFiles();


        } else if(repoList[s] != NULL){
            Repository* repo = new Repository(argv[3]);

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
