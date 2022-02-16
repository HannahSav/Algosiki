#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, parent_num, ans;
set<int> not_used_points;
set<int> now_circle;
vector<int> graph;

void find_circle(int point_num){
    now_circle.insert(point_num);
    if(not_used_points.find(graph[point_num]) != not_used_points.end()){
        //cout << point_num<< "  1\n";
        if(now_circle.find(graph[point_num]) != now_circle.end()){
          //  cout << point_num <<" 2"<< endl;
            ans++;
        }
        else{
            find_circle(graph[point_num]);
        }
    }
    not_used_points.erase(point_num);
}

int main()
{
    ans = 0;
    cin >> n;
    graph.resize(n);
    for(int i = 0; i< n; i++){
        not_used_points.insert(i);
        cin >> parent_num;
        graph[i] = parent_num - 1;
    }
    while(not_used_points.size() > 0){
        now_circle.clear();
        find_circle(*not_used_points.begin());
        //for(int i = 0; i < now_circle.size())
    }
    cout<< ans;
    return 0;
}
