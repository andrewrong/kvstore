//
// Created by fenglin on 2019/1/2.
//

#include "client/KvStoreClient.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    kvstore::KvStoreClient client("127.0.0.1:10001");
    if(client.put("hello", "world")) {
        cout << "put is success" << endl; 
    }
    
    string value;
    if(client.get("hello", value)) {
        if(value == "world") {
            cout << "get is success" << endl;
        }
    }
}
