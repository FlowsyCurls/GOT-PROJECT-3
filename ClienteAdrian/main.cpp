#include <iostream>
#include "restclient-cpp/restclient.h"
#include "src/Commands.h"
#include "src/Repository.h"
#include "src/json.hpp"
#include "src/RepositoryList.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {

    //Validar si los argumentos son nulos, para que no se caiga



    //cout << argc << endl;
    if(argc < 2){
        return 0;
    }
    json repoList = getRepositoriesFromJson2();
    json commitRegister = getCommitRegisterFromJson();

    string command = argv[1];

    if (command == "init" && argv[2] != NULL) {

        cout << argv[2] << endl;
        Repository* repo = new Repository(argv[2]);
        repoList = repo->initCommand(repoList);
        //string  s = "prueba";

        cout << argv[1] << endl;

        json j;

        string s(argv[2]);

        j["name"] = s;

        RestClient::Response r = RestClient::post("http://localhost:8080/Repository", "application/json", j.dump());

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


        } else /*if(repoList[argv[3]] != NULL)*/{
            Repository* repo = new Repository(argv[3]);

            //Si el directorio a actualizar en el repo especificado existe

            json nodeFile = repo->addCommandSingleFile(s);
            json fileNodeList = repoList[argv[3]];

            //Si está vacío, crea la lista y mete el nodo del archivo a ésta
            if(fileNodeList.size() <= 0){
                cout << "Lista de repo nula" << endl;
                fileNodeList = json::array();
                fileNodeList.push_back(nodeFile);
            } else {
                cout << "Lista repo contiene: " << fileNodeList << endl;
                fileNodeList.push_back(nodeFile);
                cout << "Queda: " << fileNodeList << endl;
            }

            cout << "Lista de nodos: " << fileNodeList << endl;


        repoList[argv[3]] = fileNodeList;

        }
    }

    if (command == "help"){
        parseContent("./resources/Help.txt");
    }

    if (command == "commit" && argv[2] != NULL && argv[3] != NULL){

        //Recuperar el json con los commits realizados

        Repository* repo = new Repository(argv[3]);

        json fileNodeList = repoList[argv[3]];
        json toCommitFilesNode;

        for (int i = 0; i < fileNodeList.size(); ++i) {
            if(fileNodeList[i]["toCommit"] == true){
                toCommitFilesNode.push_back(fileNodeList[i]);
            }
        }

        json commitStructure = repo->createCommit(argv[3], argv[2], fileNodeList);

        cout << commitStructure << endl;

        //Enviar el commit, se envía y se recive un id del commit que se acaba de hacer
        //id = Respones Restrc

        if(commitRegister[argv[3]] == NULL){

            json listCommit = json::array();
            //Commit to server devuelve el id del commit que hago
            listCommit.push_back(commitToServer(commitStructure));
            commitRegister[argv[3]] = listCommit;

        } else {
            commitRegister[argv[3]].push_back(commitToServer(commitStructure));
        }

    }

    if(command == "rollback" && argv[2] != NULL && argv[3] != NULL && argv[4] != NULL){
        //Enviar al server el file: argv[2], idCommit: argv[3], nombre repo: argv[4]
        //El server devuelve el huffman del archivo y lo sobreescribe en el json

        //Se hace un repo ara hacer uso de la función rollbackCommand
        Repository* repo = new Repository(argv[4]);

        json rollbackInfo;

        rollbackInfo["file"] = argv[2];
        rollbackInfo["idCommit"] = argv[3];
        rollbackInfo["repositoryName"] = argv[4];

        string huffman = repo->rollbackCommand(rollbackInfo);

        cout << huffman << endl;

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