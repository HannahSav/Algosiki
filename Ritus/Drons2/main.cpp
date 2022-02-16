#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, res;
vector<int> vec;
multiset<int> now_set;

void clap(int now, int i){
    if(now == n)
        return;
    now_set.insert(vec[now]);
    while(now_set.size() > 1 && now_set.count(*now_set.begin())>1)
    {
        now_set.insert(*now_set.begin()+1);
        now_set.erase(now_set.begin());
        now_set.erase(now_set.begin());
    }
    if(now_set.size() == 1){
        res++;
    }
    clap(now+1,i);
}

int main()
{
    cout.tie(0); iostream::sync_with_stdio(0);
    cin >> n;
    res = 0;
    vec.resize(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    for(int i = 0; i < n; i++){
        now_set.clear();
        clap(i, i);
    }
    cout << res;
    return 0;
}
