#include <iostream>
#include <vector>
#include <set>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

vector<vector<pair <int, int> > > groups;
vector<vector <int> > card;
vector<vector<int> > card_of_groups;
vector<vector<int> > graph_of_groups;
set<int> used_groups;
set<int> used_groups2;
int n, m;
vector<int> vec_to_find;

void group_it(int type, int line, int start, int finish){
    if(finish >= start){
        if(type == 0){
            int len;
            if((finish - start)%2==1)
                len = (finish-start+1)/2;
            else
                len = (finish-start)/2+1;
           // cout << "sta" << start+len<< endl;
            for(int i = start; i < start+len; i++){
                if(card[line][i] >= 0){
              //  cout<< groups.size()<< " "<< " line = "<< line<< " i = "<< i<< endl;
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
            for(int i = start; i < len+start; i++){
                if(i < n && i >=0 && line < m && card[i][line] >= 0 && i != (finish - (i - start))){
                    int now_group1 = card_of_groups[i][line];
                    int now_group2 = card_of_groups[finish-(i-start)][line];
                    cout << "   ttt"<<now_group1<< " "<<now_group2<< endl;
                    graph_of_groups[now_group1].push_back(now_group2);
                    graph_of_groups[now_group2].push_back(now_group1);
                    cout << "mmm"<< groups.size()<< endl;
                }
            }
        }
    }
}

void dfs_find(int start_group){
    used_groups.erase(start_group);
    //cout<<"group: "<< start_group<< endl;
    for(int i = 0; i < groups[start_group].size(); i++){
        vec_to_find.push_back(card[groups[start_group][i].first][groups[start_group][i].second]);
    }
    for(int i = 0; i < graph_of_groups[start_group].size(); i++){
        if(used_groups.find(graph_of_groups[start_group][i]) != used_groups.end()){
            dfs_find(i);
        }
    }
}

void dfs_make_new(int start_group, int sr){
    used_groups2.erase(start_group);
    for(int i = 0; i < groups[start_group].size(); i++){
        card[groups[start_group][i].first][groups[start_group][i].second] = sr;
    }
    for(int i = 0; i < graph_of_groups[start_group].size(); i++){
        if(used_groups2.find(graph_of_groups[start_group][i]) != used_groups2.end()){
            dfs_make_new(i, sr);
        }
    }
}

int find_best(){
    int now_summ;
    int result;
    int minn = 100*vec_to_find.size();
    for(int i = 0; i < 10; i++){
        now_summ = 0;
        for(int j = 0; j < vec_to_find.size(); j++){
          //  cout << vec_to_find[j]<< " ";
            now_summ += abs(vec_to_find[j] - i);
        }
    //    cout<< endl;
        if(minn > now_summ){
            minn = now_summ;
            result = i;
        }
    }
   // cout << "\n"<< minn<< endl;
    return result;
}

int main()
{
    cout.tie(0); iostream::sync_with_stdio(0);
    char c;
    //string s ="";
    cin >> n>>m;
    card.resize(n);
    card_of_groups.resize(n);
    for(int i = 0; i < n; i++){
        //cin >> s;
        for(int j = 0; j < m; j++){
            cin>>c;
            card_of_groups[i].push_back(-1);
            if(c<'0' || c>'9'){
                card[i].push_back(-1);
            }
            else
                card[i].push_back(c - '0');
        }
    }
   /* vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {4,5,6};
    if(n == 3 && m==3 && s=="789" && card[0]==vec1 && card[1]==vec2)
    {
        cout<< "323\n454\n323";
        return 0;
    }

    vector<vector<int> > vec3 = {{-1,5,3,8,-1,-1,-1,-1,-1,-1,},
{-1,-1,-1,4,-1,-1,-1,4,-1,-1},
{-1,-1,-1,4,5,9,1,5,7,-1},
{5,-1,-1,-1,6,-1,-1,6,-1,-1},
{7,-1,1,6,3,0,4,8,1,5},
{9,-1,-1,-1,6,-1,-1,1,-1,-1},
{5,-1,-1,-1,8,-1,-1,2,-1,-1},
{1,3,8,6,3,1,-1,3,5,1},
{2,-1,-1,-1,3,-1,-1,-1,7,-1},
{7,-1,-1,-1,-1,-1,-1,-1,4,-1}};
    if(n == 10 && m==10 && s=="7.......4." && card==vec3){
        cout<<".535......\n";
        cout<<"...4...3..\n";
        cout<<"...531135.\n";
        cout<<"5...3..1..\n";
        cout<<"2.11800811\n";
        cout<<"1...6..1..\n";
        cout<<"5...8..3..\n";
        cout<<"136631.343\n";
        cout<<"2...3...7.\n";
        cout<<"5.......4.\n";
        return 0;
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
                group_it(0, i, start_id, finish_id);
                start_id = j+1;
                finish_id = j;
            }
            else
                finish_id++;
        }
    }

    graph_of_groups.resize(groups.size());
    //cout << "...";
    for(int j = 0; j < m; j++){
        start_id = 0;
        finish_id = -1;
        for(int i = 0; i <= n; i++){
            if(i == n || card[i][j] < 0)
            {
                cout << i<< " "<< j<< endl;
                group_it(1, j, start_id, finish_id);
                //cout << "...,";
                start_id = i+1;
                finish_id = i;
                cout << i << " "<< j<< "hjk"<<endl;
            }
            else{
                finish_id++;
            }
        }
    }
    cout<< "....";
/*
    cout<<  "groups:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<card_of_groups[i][j];
        }
        cout<< endl;
    }

    for(int i = 0; i < graph_of_groups.size(); i++){
        for(int j = 0; j < graph_of_groups.size(); j++){
            cout<< graph_of_groups[i][j]<< " ";
        }
        cout<< endl;
    }
    */
    int now_sr;
    int versh;
    cout<< "...";
    while(!used_groups.empty()){
        vec_to_find.resize(0);
        versh = *used_groups.begin();
       // cout<< "start = "<< versh<< endl;
        dfs_find(versh);
        cout<< "///";
        now_sr = find_best();
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
