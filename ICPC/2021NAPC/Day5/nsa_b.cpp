#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define debug(content) if (DEBUG_MODE) cout << "DEBUG: " << content << endl
#define DEBUG_MODE 0

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool StringToHex(const std::string &inStr, unsigned char *outStr)
{
    size_t len = inStr.length();
    for (size_t i = 0; i < len; i += 2) {
        sscanf(inStr.c_str() + i, "%2hhx", outStr);
        ++outStr;
    }
    return true;
}

std::string string_to_hex(const std::string& input)
{
    static const char hex_digits[] = "0123456789abcdef";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    string hex;
    cin >> hex;

    debug("hex size: " << hex.size() + 1);

    unsigned char bytes[hex.size() + 1] = {};
    
    StringToHex(hex, bytes);

    size_t cur = 0;
    char tag;
    string header;

    while (cur < 12) {
        header.push_back(bytes[cur++]);
    }
    // cout << header << endl;
    assert(header == "tlv_format_6");

    bitset<8> next;

    int loops = 7;
    while (cur < hex.size() / 2 + 1) {
        tag = bytes[cur++];

        string tag_name;
        bool dump = true;

        switch (tag) {
            case 0x01: tag_name = "VICTIM_ID"; dump = false; break;
            case 0x02: tag_name = "VERSION"; dump = false; break;
            case 0x06: tag_name = "FILENAME"; dump = false; break;
            case 0x13: tag_name = "KEY_HASH"; dump = false; break;
            case 0x08: tag_name = "IV"; break;
            case 0x09: tag_name = "NONCE"; break;
            case 0x27: tag_name = "ENC_DATA"; break;
            default: tag_name = "UNKNOWN";
        }
        
        cout << tag_name << ":";
        if (cur >= hex.size()) break;

        next = bytes[cur++];

        // debug("next: " << next);

        vector<bitset<8>> encoded;
        while (next[7] && cur < hex.size() + 1) {
            encoded.push_back(next);
            next = bytes[cur++];
        }

        if (!next[7]) {
            encoded.push_back(next);
        }

        // debug("encoded: " << encoded.size());
        // rep(i, 0, sz(encoded)) {
        //     debug(encoded[i]);
        // }

        int length = 0, counter = 0;
        for (int i = encoded.size() - 1; i >= 0; i--) {
            bitset<8> cur = encoded[i];
            cur.set(7, false);
            
            rep(i, 0, sz(cur)) {
                if (cur[i]) {
                    length += pow(2, counter);
                }
                counter++;
            }
        }


        debug("length: " << length);

        vector<char> out;
        rep(i, 0, length) {
            out.push_back(bytes[cur++]);
            if (cur >= hex.size()) break;
        }

        debug("out: " << out.size());

        
        string s;
        rep(i, 0, sz(out)) {
            s.push_back(out[i]);
        }

        if (dump) {
            s = string_to_hex(s);
        }
        cout << s << endl;

        debug("cur: " << cur);

        if (!loops--) break;
    }

    debug("hex size: " << hex.size() + 1);
}
