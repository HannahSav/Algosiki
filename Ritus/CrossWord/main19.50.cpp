#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#include <math.h>

using namespace std;

vector<vector<pair <int, int> > > groups;
vector<vector <int> > card;
vector<vector<int> > card_of_groups;
vector<vector<int> > graph_of_groups;
set<int> used_groups;
set<int> used_groups2;
int num, summ, n, m;

void group_it(int type, int line, int start, int finish){
    if(finish >= start){
        if(type == 0){
            int len;
            if((finish - start)%2==1)
                len = (finish-start+1)/2;
            else
                len = (finish-start)/2+2;
            cout<< "line "<< line<< ":"<< start<< " "<< start+len<< " "<< finish<< endl;
            for(int i = start; i < start+len; i++){
                if(card[line][i] > 0){
                card_of_groups[line][i] = groups.size();
                card_of_groups[line][finish-(i-start)] = groups.size();
                used_groups.insert(groups.size());
                used_groups2.insert(groups.size());
                vector<pair<int, int> > local_set;
                local_set.push_back(make_pair(line, i));
                if(i != finish-(i-start))
                    local_set.push_back(make_pair(line, finish - (i-start)));
                groups.push_back(local_set);
                }
            }
        }
        else{
            int len;
            if((finish - start)%2==1)
                len = (finish-start+1)/2;
            else
                len = (finish-start)/2+2;
             //cout<< "line "<< line<< ":"<< start<< " "<< start+len<< " "<< finish<< endl;
            for(int i = start; i < len+start; i++){
                if(i < n && card[i][line] > 0){
                    cout << i<< "\n";
                    int now_group1 = card_of_groups[i][line];
                    int now_group2 = card_of_groups[finish-(i-start)][line];
                    //cout << "1:"<< now_group1<< " 2:"<< now_group2<< endl;
                    graph_of_groups[now_group1][now_group2] = 1;
                    graph_of_groups[now_group2][now_group1] = 1;
                }
            }
        }
    }
}

void dfs_find(int start_group){
    //cout << "dfs "<< start_group<< endl;
    used_groups.erase(start_group);
    for(int i = 0; i < groups[start_group].size(); i++){
        num++;
        summ+=card[groups[start_group][i].first][groups[start_group][i].second];
    }
    for(int i = start_group+1; i < graph_of_groups.size(); i++){
        if(graph_of_groups[start_group][i]==1 && used_groups.find(i) != used_groups.end()){
             //cout<< i<< " "<< graph_of_groups[start_group][i]<< endl;
            dfs_find(i);
        }
    }
}

void dfs_make_new(int start_group, int sr){
    used_groups2.erase(start_group);
    for(int i = 0; i < groups[start_group].size(); i++){
        card[groups[start_group][i].first][groups[start_group][i].second] = sr;
    }
    for(int i = start_group+1; i < graph_of_groups.size(); i++){
        if(graph_of_groups[start_group][i]==1 && used_groups2.find(i) != used_groups2.end()){
            //cout<< i<< " "<< graph_of_groups[start_group][i]<< endl;
            dfs_make_new(i, sr);
        }
    }
}

int main()
{
    char c;
    string s ="";
    cin >> n>>m;
    card.resize(n);
    card_of_groups.resize(n);
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            card_of_groups[i].push_back(-1);
            if(s[j]<'0' || s[j]>'9'){
                //cout << j<< endl;
                card[i].push_back(-1);
            }
            else
                card[i].push_back(s[j] - '0');
        }
       // cout<< endl;
    }
/*
    for(int i = 0; i < n; i++){
        for(int j = 0;j<m; j++){
            cout<< card[i][j];
        }
        cout<<endl;
    }
*/

    int start_id;
    int finish_id;
    for(int i  = 0; i < n; i++){
        start_id = 0;
        finish_id = -1;
        for(int j = 0; j <= m; j++){
            if(j == m || card[i][j] < 0)
            {
                cout << "i = "<< i<< " j = "<< j<< endl;
                group_it(0, i, start_id, finish_id);
                start_id = j+1;
                finish_id = j;
            }
            else
                finish_id++;
        }
    }
    ////
    cout << "after_first:\n";
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << card_of_groups[i][j]<< " ";

        }
        cout<< endl;
    }
    ////
    graph_of_groups.resize(groups.size());
    for(int i = 0; i < groups.size(); i++){
        for(int j = 0; j < groups.size(); j++)
            graph_of_groups[i].push_back(0);
    }

    ////

    /////
    for(int j = 0; j < m; j++){
        start_id = 0;
        finish_id = -1;
        for(int i = 0; i <= n; i++){
            if(i == n || card[i][j] < 0)
            {
                cout << i<< " "<< j<< endl;
                group_it(1, j, start_id, finish_id);
                start_id = i+1;
                finish_id = i;
            }
            else{
                finish_id++;
            }
        }
    }
    //cout<< "ff";

    cout<< "....";
        cout << "\n groups: \n";
    for(int i = 0; i < groups.size(); i++){
        for(int j = 0; j < groups.size(); j++){
            cout << graph_of_groups[i][j]<< " ";
        }
        cout << "\n";
    }

    int now_sr;
   // cout<< used_groups.size();
    int versh;
    while(!used_groups.empty()){
        summ = 0;
        num = 0;
        versh = *used_groups.begin();
        dfs_find(versh);
        now_sr = round(summ*1.0/num);
       // cout<< "...";
        dfs_make_new(versh, now_sr);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(card[i][j] == -1)
                cout << ".";
            else
                cout<< card[i][j];
        }
        cout<< endl;
    }
    return 0;
}
