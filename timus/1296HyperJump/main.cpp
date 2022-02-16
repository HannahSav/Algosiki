#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;

vector<int> recursion(int start, int finish){ // 0-левый край(макс), 1 - правый край(макс), 2-вцелом, 3-вся сумма
    vector<int> to_return;
    if(start==finish){
        to_return.push_back(numbers[start]);
        to_return.push_back(numbers[start]);
        to_return.push_back(numbers[start]);
        to_return.push_back(numbers[start]);
    }else{
        vector<int> return_left = recursion(start, (finish+start)/2);
        vector<int> return_right = recursion((finish+start)/2+1, finish);
        to_return.push_back(max(return_left[0], max((return_left[3]+max(return_right[0], return_right[3])), 0)));
        to_return.push_back(max(return_right[1], max(return_right[3]+max(return_left[1], return_left[3]), 0)));
        to_return.push_back(max(return_left[2],max(return_right[2],
                        max(max(return_left[3], return_left[1])+max(return_right[0], return_right[3]), 0))));
        to_return.push_back(return_left[3]+return_right[3]);
    }
    return to_return;
}

int main()
{
    int n;
    cin >> n;
    if(n == 0) cout<< 0;
    else{
        int number;
        for(int i = 0; i < n; i++){
            cin >> number;
            numbers.push_back(number);
        }
        cout<< recursion(0, n-1)[2]<< endl;
    }
    return 0;
}
