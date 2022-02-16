#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long int n,m, a;
set<pair<long long int, long long int> > empty_V_first, empty_first_V;
vector<pair<long long int, long long int> > asks_V_first;

void delete_(long long int number){
    if(asks_V_first[number].first > 0){
        long long int V = asks_V_first[number].first;
        long long int first = asks_V_first[number].second;
       // cout<< "V = "<< V<< " first = "<< first<< endl;
        if(empty_first_V.size() > 0){
        long long int V_after, V_before, first_after, first_before;
        if(empty_first_V.lower_bound(make_pair(first, V)) == empty_first_V.end() || empty_first_V.size() < 2 ){
            V_after = (*--empty_first_V.end()).second;
            V_before = V_after;
            first_after = (*--empty_first_V.end()).first;
            first_before = first_after;
        }else{
            V_after = (*empty_first_V.lower_bound(make_pair(first, V))).second;
            first_after = (*empty_first_V.lower_bound(make_pair(first, V))).first;
            if(*empty_first_V.begin() == make_pair(first_after,V_after)){
                V_before = V_after;
                first_before = first_after;
            }else{
                V_before = (*--empty_first_V.lower_bound(make_pair(first, V))).second;
                first_before = (*--empty_first_V.lower_bound(make_pair(first, V))).first;
            }
        }
        if(first+V == first_after){
            empty_first_V.erase(make_pair(first_after, V_after));
            empty_V_first.erase(make_pair(V_after, first_after));
            V = V + V_after;
        }
        if(V_before+first_before == first){
            empty_first_V.erase(make_pair(first_before, V_before));
            empty_V_first.erase(make_pair(V_before, first_before));
            V = V + V_before;
            first = first_before;
        }
        }
        empty_first_V.insert(make_pair(first, V));
        empty_V_first.insert(make_pair(V, first));
        asks_V_first[number] = make_pair(-1, -1);
    }
     asks_V_first.push_back(make_pair(-1, -1));
}

void add(long long int kolvo){
    if(empty_first_V.empty()){
        cout << -1<< endl;
        asks_V_first.push_back(make_pair(-1, -1));
        return;
    }
    long long int V = (*--empty_V_first.end()).first;
    long long int first = (*--empty_V_first.end()).second;

    if(V < kolvo){
        cout<< -1<< endl;
        asks_V_first.push_back(make_pair(-1, -1));
        return;
    }
    cout << first+1<< endl;
    int new_first = first + kolvo;
    int new_V = V-kolvo;
    empty_first_V.erase(make_pair(first, V));
    empty_V_first.erase(make_pair(V, first));
    asks_V_first.push_back(make_pair(kolvo, first));
    if(V > kolvo){
        empty_first_V.insert(make_pair(new_first, new_V));
        empty_V_first.insert(make_pair(new_V, new_first));
       // cout<< "new_V " << new_V<< "new_first "<< new_first <<endl;
    }
}

int main()
{
    cin >> n>>m;
    empty_first_V.insert(make_pair(0, n));
    empty_V_first.insert(make_pair(n, 0));
    for(int i = 0; i < m; i++){
        cin >> a;
        if(a<0){
            delete_(a*(-1) - 1);
        }
        if(a>0){
            add(a);
        }
        /*cout<< "FREE LIST:\n";
        set<pair<long long int, long long int> >::iterator it;
        for(it = empty_V_first.begin(); it != empty_V_first.end(); it++){
            cout<< (*it).first<<" "<< (*it).second<< endl;
        }*/
    }
    return 0;
}
