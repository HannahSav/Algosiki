#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, count = 0;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    set<int> numbers;
    for (int i = 0; i < (n + 1)/2; i++) {
        for (int j = 0; j < (m + 1)/2; j++) {
            numbers.insert(a[i][j]);
            numbers.insert(a[n - i - 1][j]);
            numbers.insert(a[i][m - j - 1]);
            numbers.insert(a[n - i - 1][m - j - 1]);
            count += (int)numbers.size() - 1;
            numbers.clear();
        }
    }
    cout << count;
    return 0;
}
