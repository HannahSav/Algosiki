#include <iostream>
#include <vector>

using namespace std;

vector<int> stoila_koord;
int k;
int n;
long long int sum;

vector<int> try_put_cows(long long int dist)
{
    int now_dist = 0;
    int count_cows = 1;
    int now_stoilo = -1;
    long long int min_dist = sum;
    vector<int> ans;
    ans.clear();
    while (count_cows < k && now_stoilo < n - 2) {
        now_stoilo++;
        now_dist += stoila_koord[now_stoilo];
        if (now_dist >= dist) {
            count_cows++;
            if (now_dist < min_dist)
                min_dist = now_dist;
            now_dist = 0;
        }
    }
    ans.push_back(count_cows);
    ans.push_back(now_stoilo);
    ans.push_back(min_dist);
    return ans;
}

void bin(long long int l, long long int r)
{
    long long int mid;
    vector<int> result_of_try; //0 - count_cows, 1 - count_sloila, 2-min dist
    while ((r - l) > 1) {
        result_of_try.clear();
        mid = ((r + l) / 2);
        result_of_try = try_put_cows(mid);
        if (result_of_try[0] == k && result_of_try[1] == n - 2) {
            if (result_of_try[2] == mid) {
                cout << mid;
                return;
            }
            else {
                l = mid;
            }
        }
        else {
            if (result_of_try[0] < k && result_of_try[1] == n - 2)
                r = mid;
            if (result_of_try[0] == k && result_of_try[1] < n - 2)
                l = mid;
        }
    }
    cout << l;
}

int main()
{
    cin >> n;
    cin >> k;
    int koord_prev;
    int koord;
    sum = 0;
    cin >> koord;
    for (int i = 1; i < n; i++) {
        koord_prev = koord;
        cin >> koord;
        stoila_koord.push_back(koord - koord_prev);
        sum += koord;
    };
    bin(1, sum);
    return 0;
}
