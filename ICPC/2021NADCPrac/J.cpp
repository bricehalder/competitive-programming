#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */

unsigned int reverseBits(unsigned int n)
{
    unsigned int rev = 0;
     
    while (n > 0)
    {
        rev <<= 1;
         
        if (n & 1 == 1)
            rev ^= 1;
        
        n >>= 1;
             
    }
     
    // required number
    return rev;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned int n;
    cin >> n;
    cout << reverseBits(n);
}