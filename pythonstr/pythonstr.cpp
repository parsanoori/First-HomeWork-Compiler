#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool is_three_cot(istream &i) {
    auto p = i.tellg();
    bool result = true;
    char c;
    for (int j = 0; j < 3; j++) {
        i.get(c);
        if (c != '"')
            result = false;
    }
    i.seekg(p);
    return result;
}


bool is_id_valid(istream &i) {
    i >> ws;
    char c = i.get();
    if (isdigit(c))
        return false;
    while (i.get(c))
        if (isspace(c))
            return true;
        else if (isalnum(c))
            continue;
        else return false;
    return false;
}

bool is_py_str_valid(istream &i) {
    if (!is_id_valid(i))
        return false;
    char c;
    i >> ws;
    i.get(c);
    if (c != '=')
        return false;
    i >> ws;
    if (!is_three_cot(i))
        return false;
    i.ignore(3);
    while ((c = i.peek()) != -1) {
        if (is_three_cot(i))
            return true;

        if (c != '\\') {
            i.ignore(1);
            continue;
        }
        i.ignore(1);
        if (is_three_cot(i))
            i.ignore(3);
        else {
            i.ignore(1);
            continue;
        }
    }
    return false;
}

int main() {
    ifstream i("teststr.py");
    cout << (is_py_str_valid(i) ? "true" : "false") << endl;
    return 0;
}
#pragma clang diagnostic pop
