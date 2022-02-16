#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> a;

int maxCrossingSum(int l, int m, int r)
{

    int sum = 0;

    int left_sum = -30000;

    for (int i = m; i >= l; i--) {

        sum = sum + a[i];

        if (sum > left_sum)

            left_sum = sum;
    }

    sum = 0;

    int right_sum = -30000;

    for (int i = m + 1; i <= r; i++) {

        sum = sum + a[i];

        if (sum > right_sum)

            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int l, int r)
{

    if (l == r)
        return a[l];

    int m = (l + r) / 2;

    return max(max(maxSubArraySum(l, m), maxSubArraySum(m + 1, r)), maxCrossingSum(l, m, r));
}

int main()
{
    int n, b;
    cin >> n;
    if (n != 0) {
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.push_back(b);
    }
    int answer = maxSubArraySum(0, n - 1);
    if (answer < 0)
        answer = 0;
    cout << answer;
    } else {
        cout << 0;
    }
    return 0;
}
