#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, m, full_ans;
    set<int> four_set;
    full_ans = 0;
    cin >> n>>m;
    int matrica[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrica[i][j];
        }
    }
    int i_to, j_to;
    if(n%2 == 0)
        i_to = n/2;
    else
        i_to = (n+1)/2;
    if(m%2 == 0)
        j_to = m/2;
    else
        j_to = (m+1)/2;
    int num1;
    int num2;
    int num3;
    int num4;
    for(int i = 0; i < i_to; i++){
        for(int j = 0; j < j_to; j++){
            four_set.clear();
            num1 = matrica[i][j];
            num2 = matrica[n - 1 -i][j];
            num3 = matrica[i][m - 1 - j];
            num4 = matrica[n-1-i][m-1-j];
            four_set.insert(num1);
            four_set.insert(num2);
            four_set.insert(num3);
            four_set.insert(num4);
            if(four_set.size() == 2){
                if((n%2 == 1 && i == (n-1)/2)||(m%2 == 1 && j == (m-1)/2) || (!(num1 == num2 && num3 == num4) && !(num1 == num3 && num2 == num4) && !(num1 == num4 && num2 == num3)))
                    full_ans+=1;
                else
                    full_ans+=2;
            }
            else{
                full_ans += four_set.size() - 1;
            }
        }
    }
    cout << full_ans;
    return 0;
}
