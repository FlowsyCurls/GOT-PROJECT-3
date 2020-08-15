#include <iostream>
#include "restclient-cpp/restclient.h"
#include "src/Commands.h"
#include "src/Repository.h"
#include "json.hpp"
#include "src/RepositoryList.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {

    if(argc > 1){

        cout << argv[1] << endl;

        json j;

        string s(argv[2]);

        j["name"] = s;

        RestClient::Response r = RestClient::post("http://localhost:8080/Repository", "application/json", j.dump());

    }


    return 0;

}