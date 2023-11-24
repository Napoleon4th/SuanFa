//
// Created on 2023/11/24.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

string simplifyPath(string path) {
    stack<string> s;
    istringstream iss(path);
    string token;

    while (getline(iss, token, '/')) {
        if (token == "..") {
            if (!s.empty()) {
                s.pop();
            }
        } else if (token != "." && !token.empty()) {
            s.push(token);
        }
    }

    string result = "";
    while (!s.empty()) {
        result = "/" + s.top() + result;
        s.pop();
    }

    return result.empty() ? "/" : result;
}

int main() {
    string input;
    cin >> input;

    string result = simplifyPath(input);

    cout << result << endl;

    return 0;
}
