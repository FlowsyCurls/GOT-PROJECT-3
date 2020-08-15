#include <iostream>
#include "restclient-cpp/restclient.h"
#include "src/Commands.h"
#include "src/Repository.h"
#include "json.hpp"
#include "src/RepositoryList.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {



    RestClient::Response r = RestClient::post("http://localhost:8080/Repository?repository={\"name\": \"bla\"}", "application/json", "");



    return 0;

}