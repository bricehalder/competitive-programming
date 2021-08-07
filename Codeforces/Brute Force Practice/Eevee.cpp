#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
     vector<string> eeveelutions = {"vaporeon", "jolteon", "flareon",
     "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

     int n;
     int bad;
     string guess;

     cin >> n >> guess;

     for (string s : eeveelutions) {
         if (s.size() != guess.size()) { continue; }
         bad = 0;
         for (size_t i = 0; i < guess.size(); ++i) {
             if (isalpha(guess[i])) {
                     if (guess[i] != s.at(i)) { bad++; }
             }
         }
         if (bad == 0) {
             cout << s << endl;
             break;
         }
     }
    return 0;
}
