//
// Created by fenglin on 2018/12/29.
//

#include <string>
#include "src/service/KvStoreService.h"

using std::string;

int main() {
   kvservice::RunServer("127.0.0.1:10001");
}

