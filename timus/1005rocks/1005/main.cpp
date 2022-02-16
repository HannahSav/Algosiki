#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

vector<int> rocks;

int summing(int i, int sum1, int sum2){
    int rock = rocks[i];
    if(i == rocks.size()-1){
        return abs(rock - abs(sum1-sum2));
    }
    else{
       return min(summing(i+1, rock+sum1, sum2), summing(i+1, sum1, sum2+rock));
    }
}

int main()
{
    int n;
    int rock;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> rock;
        rocks.push_back(rock);
    }
    cout << summing(0, 0, 0);
    return 0;
}
