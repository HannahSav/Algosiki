#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char c;
    int number;
    deque<int> que_start;
    deque<int> que_end;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == '-'){
            cout<<que_start.front()<< endl;
            que_start.pop_front();
        }else{
            cin >> number;
            if(c == '+')
                que_end.push_back(number);
            else
                que_end.push_front(number);
        }
        if(que_start.size() < que_end.size()){
            que_start.push_back(que_end.front());
            que_end.pop_front();
        }
    }
    return 0;
}
