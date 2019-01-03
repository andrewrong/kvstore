//
// Created by fenglin on 2019/1/2.
//

#include "client/KvStoreClient.h"
#include <iostream>
#include <vector>

using std::cout;
using std::vector;
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

    int i = 1000;
    for(; i >= 0; --i) {
        string tmp = std::to_string(i);
        if(!client.put("key_" + tmp, "value_" + tmp)) {
            cout << "key:" << tmp << " put is error" << endl;
        }
    }

    vector<std::pair<string, string>> result;
    client.scan("", [&result](const string& key, const string& value) {
            if(key.empty()) {
                return;
            }
            result.push_back(std::make_pair(key, value));
    });

    for(auto& item : result) {
        cout << item.first << ":" << item.second << endl;
    }
    cout << result.size() << endl;

    string delKey = "delKey";
    if(client.put(delKey, "delKey")) {
        if(client.del(delKey)) {
            string value;

            if(client.get(delKey, value)) {
                cout << "delkey valuee:" << value << endl;
            } else {
                cout << "get is error" << endl;
            }
        }
    }else {
        cout << "delKey is error" << endl;
    }

}
