#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <locale>

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

using namespace std;

#define ll long long

char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y'};

string exception = "qu";

int syllables(string word) {
    int count = 1;

    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word.size();
}

int main() {

    string str;
    getline(cin, str);

    vector<string> tokens = split(str, ' ');

    for (string &tok : tokens) {
        cout << syllables(tok) << "  ";
    }


    cout << endl;

    cout << str;
    return 0;
}
