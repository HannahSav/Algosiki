#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <string>

using namespace std;

vector<int> rocks;

int summing(int i, int sum1, int sum2){
    if(i == rocks.size()-1){
        return abs(rocks - (sum1-sum2));
    }
    else{
        return min(summing(i+1, sum1+rocks[i], sum2), summing(i+1, sum1, sum2+rocks[1]));
    }
}

int main() {
	int n;
	int rock;
	int sum;
	cin >> n;
	for(int i = 0; i < n; i++){
        cin >> rock;
        rocks.push_back(rock);
	}
	cout << summing(0, 0, 0);
	return 0;
}
