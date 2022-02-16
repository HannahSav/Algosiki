#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <stdint.h>
#include <math.h>

using namespace std;

int n, k, inf;
string s;
vector<int> koeff;
unordered_map<long long, int> numbers;
vector<vector<int> > numbers_vec;
vector<int> dist;
set<int> not_used;
vector<vector<int> > parent;
set<vector<int> > que;
vector<vector<int> > now_vec;
vector<int> vec;
vector<vector <int> > res;
vector<int> find_vec;


long long make_num( vector<int>  vec){
    long long res = 0;
    for(int i = 0; i < 10; i++){
        //cout << vec[i]<< " ";
        res = res*10+ vec[i];
    }
    return res;
}


vector<vector<int> > make_connections(int num){ //weight, number
    res.clear();
    int swichch;
    int find_num;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j != numbers_vec[num][i]){
                find_vec = numbers_vec[num];
                find_vec[i] = j;
                long long number = (make_num(find_vec));
                //cout << "long = "<< number<< endl;

                if(numbers.find(number) != numbers.end())
                {
                    //cout << "1..";
                    find_num = numbers.at(number);
                    //cout << "long = "<< number<< endl;
                    if(not_used.find(find_num) != not_used.end()){
                        vec.clear();
                        vec.push_back(numbers.at(number));
                        vec.push_back(koeff[i]);
                        res.push_back(vec);
                    }
                }
            }
        }
         for(int j = i+1; j < 10; j++){
            find_vec.clear();
            find_vec = numbers_vec[num];
            swichch = find_vec[i];
            find_vec[i] = find_vec[j];
            find_vec[j] = swichch;
            long long number = make_num(find_vec);
            if(numbers.find(number) != numbers.end())
                {
                    find_num = numbers.at(number);
                    if(not_used.find(find_num) != not_used.end()){
                        vec.clear();
                        vec.push_back(numbers.at(number));
                        vec.push_back(koeff[i]);
                        res.push_back(vec);
                    }
                }
        }
    }
    return res;
}

int dextra(int num){
    while(!que.empty()){
        num = (*que.begin())[1];
        not_used.erase(num);
        que.erase(que.begin());
        //not_used.erase(num);
        if (num == n-1)
            return dist[num];
        //cout << num<< endl;
        now_vec = make_connections(num);
        //cout << now_vec.size();
        for(int i = 0; i< now_vec.size(); i++){
           // cout << now_vec[i][0]<< ":" << now_vec[i][1]<< endl;
           // cout << dist[now_vec[i][0]] << " -> "<< dist[num] + now_vec[i][1]<< endl;
            if(dist[now_vec[i][0]] > dist[num] + now_vec[i][1]){
                vec.clear();
                vec.push_back(dist[now_vec[i][0]]);
                vec.push_back(now_vec[i][0]);
                que.erase(vec);
                dist[now_vec[i][0]] = dist[num] + now_vec[i][1];
                parent[now_vec[i][0]][0] = num;
                parent[now_vec[i][0]][1] = parent[num][1] + 1;
                vec[0] = dist[now_vec[i][0]];
                que.insert(vec);
            }
        }
    }
    return -1;
}

void print_parents(int num){
    if(num != 0){
        print_parents(parent[num][0]);
        cout<< parent[num][0] + 1 << " ";
    }
}

int main()
{

    cin >> n;
    inf  = INT32_MAX;
    dist.resize(n);
    parent.resize(n);
    vector<int> vec;
    numbers_vec.resize(n);
    for(int i = 0;i < 10; i++)
        {
            cin >> k;
            koeff.push_back(k);
        }
    for(int i = 0; i < n; i++){
        vec.clear();
        dist[i] = inf;
        not_used.insert(i);
        cin>>s;
        for(int j = 0; j < 10; j++)
            vec.push_back((s[j]) - '0');
        numbers_vec[i] = vec;
        //vec.push_back(i);
       // cout << make_num(vec)<< endl;
        numbers[make_num(vec)] = i;
        parent[i].resize(2);
        parent[i][0] = -1;
        parent[i][1] = 1;
    }
    dist[0] = 0;
    que.clear();
    vec.clear();
    vec.push_back(0);
    vec.push_back(0);
    que.insert(vec);
    int ans = dextra(0);
    cout << ans << endl;
    if(ans != -1){
        cout<<parent[n-1][1]<< endl;
        print_parents(n-1);
        cout << n;
    }
    return 0;
}
