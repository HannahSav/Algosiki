#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > card;
vector<vector<int> > dist;
int n, m, x0, y0, x1, y1;
set< vector<int> > will_be_next;

void put_vec_for_set(int i , int j, int now_dist, int direction){
    //cout << "i = "<< i<< " j = "<< j<< endl;
    if(i >= 0 && i < n && j >= 0 && j < m && dist[i][j] == -1){
        if(card[i][j] < 3){
            vector <int> vec;
            vec.push_back(now_dist + card[i][j]);
            vec.push_back(i);
            vec.push_back(j);
            will_be_next.insert(vec);
            dist[i][j] = vec[0];
            card[i][j] = direction;
            //cout << "add "<< i<< " "<< j<< endl;
        }
    }
}

void add_all(int i, int j, int now_dist){
    put_vec_for_set(i, j-1, now_dist, -4);
    put_vec_for_set(i, j+1, now_dist, -2);
    put_vec_for_set(i+1, j, now_dist, -3);
    put_vec_for_set(i-1, j, now_dist, -1);
}

void do_u_de_way(int i, int j){
    if(i != x0 || j != y0){
    if(card[i][j] == -1){
        do_u_de_way(i+1, j);
        cout<<"N";
    }
    if(card[i][j] == -2){
        do_u_de_way(i, j-1);
        cout<<"E";
    }
    if(card[i][j] == -3){
        do_u_de_way(i-1, j);
        cout<<"S";
    }
    if(card[i][j] == -4){
        do_u_de_way(i, j+1);
        cout<<"W";
    }
    }
}

int main()
{
    char c;
    cin >> n >> m>> x0>>y0>>x1>>y1;
    x0--;
    y0--;
    x1--;
    y1--;
    card.resize(n);
    dist.resize(m);
    for(int i = 0; i < n; i++){
        card[i].resize(m);
        dist[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            dist[i][j] = -1;
            cin >> c;
            if(c == '.')
                card[i][j] = 1;
            if(c == 'W')
                card[i][j] = 2;
            if(c == '#')
                card[i][j] = 3;
        }
    }
    add_all(x0, y0, 0);
    vector<int> now_vec;
    //cout<< will_be_next.size();
    while(dist[x1][y1] == -1 && will_be_next.size() > 0){
        now_vec = *will_be_next.begin();
        will_be_next.erase(now_vec);
        //cout<< "look at "<< now_vec[1]<<" "<< now_vec[2]<< endl;
        add_all(now_vec[1], now_vec[2], now_vec[0]);
    }
    cout << dist[x1][y1]<< endl;
    do_u_de_way(x1, y1);
    return 0;
}
