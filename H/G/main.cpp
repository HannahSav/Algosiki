#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector <int> > letters; //0 - сама буква, 1 - ее вес, 2 - ее количество;

bool comp(vector<int> vec1, vector<int> vec2){
   // cout<<"vec1 = "<< (char)(vec1[0] + (int)('a'))<<" "<<vec1[1]<<" "<< vec1[2]<< endl;
   // cout<<"vec2 = "<< (char)(vec2[0] + (int)('a'))<<" "<<vec2[1]<<" "<< vec2[2]<< endl;
    if(vec2[1]>=vec1[1])
        return 0;
   // cout<< 0<< endl;
    return 1;
}

int main()
{
    string stroka;
    cin >> stroka;
    vector<int> little_vec;
    int ves;
    for(int i = 0; i < 26; i++){
        little_vec.clear();
        little_vec.push_back(i);
        cin >> ves;
        little_vec.push_back(ves);
        little_vec.push_back(0);
        letters.push_back(little_vec);
    }
    //cout<< "size = "<< letters.size()<< endl;
    for(int i = 0; i < stroka.size(); i++)
    {
        //cout<< "i = "<<stroka[i]-'a'<< endl;
        letters[stroka[i]-'a'][2]++;
        //cout<<"razmer "<< stroka[i] << "="<< letters[stroka[i]-'a'][3]<< endl;
    }
    sort(letters.begin(), letters.end(), comp);
    for(int i = 0; i<letters.size(); i++){
        if(letters[i][2] > 1){
            cout <<(char)(letters[i][0] + (int)('a'));
            //letters[i][2]--;
        }
    }
    for(int i = 0; i<letters.size(); i++){
        if(letters[i][2] == 1 ){
            cout <<(char)(letters[i][0] + (int)('a'));
            letters[i][2]--;
        }
        else{
            for(int j = letters[i][2]; j >=3; j--)
                cout <<(char)(letters[i][0] + (int)('a'));
        }
    }
    for(int i = letters.size()-1; i >=0; i--){
        if(letters[i][2]>0)
            cout<<(char)(letters[i][0] + (int)('a'));
    }
    return 0;
}

/*
bbeeeeeeeeeeeeeeeeeeee
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25


*/
