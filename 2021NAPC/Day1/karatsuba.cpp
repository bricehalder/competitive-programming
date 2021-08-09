#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn = 1e2 + 14, lg = 15;

typedef vector<int> lnum;
const int base = 1000*1000*1000;

void lnumprint(lnum& a) {
    printf ("%d", a.empty() ? 0 : a.back());
    for (int i=(int)a.size()-2; i>=0; --i)
        printf ("%09d", a[i]);
}

void lnumread(string& s, lnum& a) {
    for (int i=(int)s.length(); i>0; i-=9)
    if (i < 9)
        a.push_back (atoi (s.substr (0, i).c_str()));
    else
        a.push_back (atoi (s.substr (i-9, 9).c_str()));
}

lnum lnummul(lnum& a, lnum& b) {
    lnum c (a.size()+b.size());
    for (size_t i=0; i<a.size(); ++i)
        for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
            long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
            c[i+j] = int (cur % base);
            carry = int (cur / base);
        }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);

    string sa, sb;
    cin >> sa >> sb;

    lnum a, b;

    for (int i=(int)sa.length(); i>0; i-=9)
    if (i < 9)
        a.push_back (atoi (sa.substr (0, i).c_str()));
    else
        a.push_back (atoi (sa.substr (i-9, 9).c_str()));

    for (int i=(int)sb.length(); i>0; i-=9)
    if (i < 9)
        b.push_back (atoi (sb.substr (0, i).c_str()));
    else
        b.push_back (atoi (sb.substr (i-9, 9).c_str()));

    lnum c (a.size()+b.size());
    for (size_t i=0; i<a.size(); ++i)
        for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
            long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
            c[i+j] = int (cur % base);
            carry = int (cur / base);
        }

    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    printf ("%d", c.empty() ? 0 : c.back());
    for (int i=(int)c.size()-2; i>=0; --i)
        printf ("%09d", c[i]);

    printf("\n");
}