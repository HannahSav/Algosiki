#include <iostream>
#include <vector>
#include <set>

using namespace std;

int m, n;
vector<vector<int> > graph;
vector<int> graph_color;
set<int> not_used_points;

bool make_it_color(int point, int color){
    //cout << "point "<< point << " color "<< color<< " set "<< not_used_points.size()<< endl;
    if(not_used_points.find(point) == not_used_points.end()){
        if(graph_color[point] != color){
            //cout << "1..\n";
            return false;
        }
        return true;
    }else{
        not_used_points.erase(point);
        graph_color[point] = color;
        for(int i = 0; i < graph[point].size(); i++){
            if(!make_it_color(graph[point][i], color*(-1))){
                //cout << "2.."<<i<<"\n";
                return false;
            }
        }
        return true;
    }
}

int main()
{
    cin >> n >> m;
    graph.resize(n);
    graph_color.resize(n);
    int men1, men2;
    for(int i = 0; i < m; i++){
        cin >> men1 >> men2;
        men1--;
        men2--;
        graph[men1].push_back(men2);
        graph[men2].push_back(men1);
    }
    for(int i = 0; i < n; i++){
        not_used_points.insert(i);
        graph_color[i] = 0;
    }
    while(not_used_points.size() > 0){
        if(!make_it_color(*not_used_points.begin(), 1)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
