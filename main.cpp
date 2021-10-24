#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>

using namespace std;

int main() {
    cpr::Response response;
    string UrlRequest = "http://httpbin.org/";
    string key, value;
    vector<cpr::Pair> parameters;
    while (cin >> key && key != "post" && key != "get") {
        cin >> value;
        parameters.push_back({move(key), move(value)});
    }
    UrlRequest += key;
    if (key == "get") {
        bool first = true;
        for (auto& p: parameters) {
            if (first)UrlRequest += '?';
            else UrlRequest += '&';
            UrlRequest += p.key;
            UrlRequest += '=';
            UrlRequest += p.value;
            first = false;
        }
        response = cpr::Get(cpr::Url(UrlRequest));
    } else {
        response = cpr::Post(cpr::Url(UrlRequest), cpr::Payload(parameters.begin(), parameters.end()));
    }
    cout << response.text;

    return 0;
}
