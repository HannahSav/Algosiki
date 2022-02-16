#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > speads;

bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second<=p2.second)
        return 0;
    return 1;
}

void sorting(){
    int i = 1;
    pair<int, int> local_pair;
    while(i < speads.size()-1 && (speads[i].second <= speads[i+1].second)){
        local_pair = speads[i];
        speads[i] = speads[i+1];
        speads[i+1] = local_pair;
        i++;
    }
    i = 0;
    while(i < speads.size()-1 && (speads[i].second < speads[i+1].second)){
        local_pair = speads[i];
        speads[i] = speads[i+1];
        speads[i+1] = local_pair;
        i++;
    }
}

int main()
{
    int k;
    cin>>k;
    int number_of_speads;

    if(k <= 1){
        if(k!=0){
        cin>>number_of_speads;
        for(int i = 0; i< number_of_speads; i++)
            cout<< 1<< " ";
        }
    }
    else{
        for(int i = 0; i < k; i++){
            cin >> number_of_speads;
            speads.push_back(make_pair(i+1, number_of_speads));
        }
        sort(speads.begin(), speads.end(), comp);
        while(speads[0].second > 0 && speads[1].second > 0){
            cout << speads[0].first<< " "<< speads[1].first<< " ";
            speads[0].second--;
            speads[1].second--;
            sorting();
        }
        for(int i = 0; i< speads[0].second; i++)
            cout<< speads[0].first<< " ";
    }
    return 0;
}
