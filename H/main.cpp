#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    int k;
    cin >> n>> k;
    vector<int> prises;
    int prise;
    for(int i = 0; i < n; i++){
        cin >> prise;
        prises.push_back(prise);
    }
    sort(prises.begin(), prises.end());
    long long int ans = 0;
    int iter = 1;
    for(int i = prises.size()-1; i >= 0; i--){
        if(iter != k){
            ans+=prises[i];
            iter++;
        }
        else
            iter = 1;
    }
    cout<< ans;
    return 0;
}
