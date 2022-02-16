#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, maxx, max_len;
vector<vector<int> > card;
set <int> used;
set<vector<int> > ribs;//length, i, j;
vector<int> shortest_point_rib;

int find_min(int now_point, int direction){
    used.insert(now_point);
    vector<int> vec;
    for(int i = 0; i < n; i++){
        if(used.find(i) == used.end()){
            vec.clear();
            if(direction == 1)
                vec.push_back(card[now_point][i]);
            else
                vec.push_back(card[i][now_point]);
            vec.push_back(i);
            int len = vec[0];
            if(shortest_point_rib[i] > len)
                ribs.insert(vec);
            if(shortest_point_rib[i] < maxx){
                vec.clear();
                vec.push_back(shortest_point_rib[i]);
                vec.push_back(i);
                ribs.erase(vec);
                shortest_point_rib[i] = len;
            }
        }
    }
    if(used.size() == n)
        return -1;
    int new_one_point = (*ribs.begin())[1];
    int result = (*ribs.begin())[0];
    ribs.erase(ribs.begin());
    int answer = find_min(new_one_point, direction);
    if(answer < 0)
        return(result);
    return max(result, answer);
}

int main()
{
    cin >> n;
    maxx = 1000000000;
    card.resize(n);
    shortest_point_rib.resize(n);
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++){
        card[i].resize(n);
        shortest_point_rib[i] = maxx;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> card[i][j];
        }
    }
    int res1, res2;
    res1 = find_min(0, 1);
    ribs.clear();
    used.clear();
    for(int i = 0;i < n; i++){
        shortest_point_rib[i] = maxx;
    }
    res2 = find_min(0, 0);
    cout << max(res1, res2);
    return 0;
}
