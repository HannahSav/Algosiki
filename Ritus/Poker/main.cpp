#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m , s, a, ans, last_ans;
set<int> on_table;
vector<int> on_table_vec;

void try_to_push(int first_mean, int last_mean){
    int last_one = min(n, last_mean+m-(last_mean-first_mean + 1));
    if(last_ans >= last_mean)
        ans += last_one - last_ans;
    else
        ans += last_one - last_mean + 1;
    last_ans = last_one;
}

int main()
{
    ans = 0;
    cin >> n>> m>> s;
    int size1 = 0;
    for(int i = 0; i< m; i++){
        cin >> a;
        on_table.insert(a);
        if(on_table.size() > size1){
            size1++;
            on_table_vec.push_back(a);
        }
    }
    sort(on_table_vec.begin(), on_table_vec.end());
    int m2 = on_table_vec.size();
    int last_from_table;
    last_ans = m-1;
    for(int i = 0; i < m; i++){
        last_from_table = i+m-s-1;
        if(last_from_table >= m2){
            cout << ans;
            return 0;
        }
        if(on_table_vec[last_from_table] - on_table_vec[i] < m)
            try_to_push(on_table_vec[i], on_table_vec[last_from_table]);
    }
    cout << ans;
    return 0;
}
