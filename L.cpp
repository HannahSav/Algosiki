#include <iostream>
#include <queue>
#include <multiset>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout<< n<< k;
    int number;
    queue que;
    multiset<int> mset;
    for(int i = 0; i < k; i++){
        cin>>number;
        cout<< number;
        que.push_back(number);
        mset.insert(number);
        cout<< "i = "<< i<< endl;
    }
    cout<< mset.lower_bound()<< " ";
    for(int i  = k; i < n; i++){
        mset.erase(mset.find(que.front()));
        que.pop_front();
        cin>>number;
        que.push_back(number);
        mset.insert(number);
    }
    return 0;
}
