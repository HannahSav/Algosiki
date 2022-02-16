#include <iostream>

using namespace std;

int main() {
	int n, k, m;
	cin >> n >> k >> m;
	int m_kol, k_kol;
	int ans = 0;
	while(n >= k){
        k_kol = n/k;
        m_kol = (k/m);
        m_kol = k_kol*m_kol;
        ans+=m_kol;
        n = n - m_kol*m;
        //cout << n << endl;
	}
	cout << ans;
	return 0;
}
