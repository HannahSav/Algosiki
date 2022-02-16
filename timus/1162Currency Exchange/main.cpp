#include <iostream>
#include <vector>
#include <set>


using namespace std;

int n, m, s;
double a, b, v, rab, rba, cab, cba;
//vector<vector<int> > ribs_parametrs;
vector<vector<float> > ribs;
//vector< vector<vector<pair<float, float> > > > connection;
vector<float> dist;
//set<int> set_of_start;

/*bool ford_bel(int point){
    float res;
    for(int point2 = 0; point2 < connection[point].size(); point2++){
        for(int i = 0; i < connection[point][point2].size(); i++)
            res = (dist[point] - connection[point][point2][i].second)*connection[point][point2][i].first;
        if(dist[point2] + 0.000001 < res){
                //cout << "res = "<< res;
            dist[point2] = res;
            if(point2 == s)
                return true;
        }
    }
    return false;
}*/

int main()
{
    cin >> n >> m >> s>> v;
    s--;
    //ribs_parametrs.resize(m);
    ribs.resize(2*m);
   // connection.resize(n);
    dist.resize(n);
    /*for(int i = 0; i < n; i++)
        connection[i].resize(n);*/
    for(int i = 0; i < 2*m; i = i+2){
        //all_parametrs[i].resize(6);
        //cout<< "1..\n";
        cin>>a>>b>>rab>>cab>>rba>>cba;
        a--;
        b--;
        ribs[i].push_back(a);
        ribs[i].push_back(b);
        ribs[i].push_back(rab);
        ribs[i].push_back(cab);
        ribs[i+1].push_back(b);
        ribs[i+1].push_back(a);
        ribs[i+1].push_back(rba);
        ribs[i+1].push_back(cba);
        //connection[a][b].push_back(make_pair(rab, cab));
        //connection[b][a].push_back(make_pair(rba, cba));
    }
    for(int j = 0; j < n; j++){
        dist[j] = 0;
    }
    dist[s] = v;
    //bool ans = ford_bel(s);
    /*if(ans)
    {
        cout << "YES";
        return 0;
    }
    //cout << "2..\n";
    for(int k = 0; k < n-1; k++){
        for(int i = 0; i < n; i++){
            if(dist[i] > 0){
                ans = ford_bel(i);
                if(ans)
                {
                cout << "YES";
                return 0;
                }
            }
        }
    }
    //for(int j = 0; j < dist.size(); j++){
    //    cout << dist[j]<< " ";
    //}
    cout << "NO";*/
    for(int i = 0; i < n; i++){
        for(int j = 0; j<ribs.size(); j++){
            dist[ribs[j][1]] = max(dist[ribs[j][1]], (dist[ribs[j][0]]-ribs[j][3])*ribs[j][2]);
        }
    }
    for(int i  = 0; i < ribs.size(); i++){
        if((dist[ribs[i][0]] - ribs[i][3])*ribs[i][2]>dist[ribs[i][1]]+0.000001){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
