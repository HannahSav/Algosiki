#include <iostream>
#include <vector>

using namespace std;


void req(int n, int k){

}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for(int i = 0;i < n; i++){
        vec.push_back(i+1);
    }
    int del = k - 1;
    for(int i = 0; i < n - 1; i++){
        cout <<vec[del] << " ";
        vec.erase(vec.begin()+ del);
        del = (del + k - 1) % (n - i - 1);
    }
    cout<< vec[0];
    return 0;
}
