#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s;
vector<int> sort_str;

bool comp(int i, int j){
    return s[j]>s[i];
}

int main()
{
    cin >> n;
    cin >> s;
    int len = s.size();
    for(int i = 0; i < len; i++){
        sort_str.push_back(i);
    }
    stable_sort(sort_str.begin(), sort_str.end(), comp);
    string result = "";
    int now_num = sort_str[n-1];
    for(int i = 0; i < len; i++){
        cout << s[now_num];
        result = result + s[now_num];
        now_num = sort_str[now_num];
    }
    cout<<endl<<result;
    return 0;
}
