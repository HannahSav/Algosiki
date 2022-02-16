#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

vector<vector<string> > inputs;

bool comp(string s1, string s2){
    string new_str1 = s1+s2;
    string new_str2 = s2+s1;
    if(new_str2>new_str1)
        return 1;
    return 0;
}

int main()
{
    string input;
    ifstream cin;
    cin.open("number.in");
    inputs.resize(10);
    while(cin >> input){
        inputs[input[0] - '0'].push_back(input);
    }
    cin.close();
    for(int i = 0; i<=9; i++){
        sort(inputs[i].begin(), inputs[i].end(), comp);
    }
    ofstream cout;
    cout.open("number.out");
    for(int i = 9; i>=0; i--)
        for(int j = inputs[i].size() - 1; j>=0; j--)
            cout<<inputs[i][j];
    cout.close();
    return 0;
}
