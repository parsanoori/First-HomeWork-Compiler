#include <iostream>
#include <cctype>
using namespace std;

bool is_correct_float(const string& s){
    if (s == ".")
        return false;
    return all_of(s.begin(),s.end(),[] (const char c) -> bool {
        return isdigit(c) || c == '.';
    }) && any_of(s.begin(),s.end(),[] (const char c) -> bool {
        return c == '.';
    });
}
int main()
{
    string s = "2345678.";
    cout << (is_correct_float(s) ? "true" : "false") << endl;
    return 0;
}
