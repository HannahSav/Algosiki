#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int fun(unordered_map<string,int> *pointM) {
    unordered_map<string, int> mp;
    string s;
    bool start = true;
    while (cin >> s) {
        if (s == "{") {
            if (start) {
                fun(pointM);
            } else {
                fun(&mp);
            }
        } else if (s == "}") {
            mp.clear();
            return 0;
        } else {
            if (start) {
                mp = *pointM;
            }
            start = false;
            auto pos = s.find("=");
            string s1 = s.substr(0,pos);
            string s2 = s.substr(pos+1);
            if (s2 < "A") {
                mp[s1] = stoi(s2);
            } else {
                if (mp.count(s2) == 0) {
                    mp[s1] = 0;
                } else if (s1 != s2) {
                    mp[s1] = mp[s2];
                }
                cout << mp[s1] << endl;
            }
        }
    }
}

int main() {
    unordered_map<string, int> m;
    fun(&m);
    return 0;
}
