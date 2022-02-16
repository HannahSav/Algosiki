// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> field(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '.') {
				field[i][j] = -1;
			} else {
				field[i][j] = s[j] - '0';
			}
		}
	}

	vector<vector<int>> nodes(n, vector<int>(m));
	vector<pii> cells;
	int cnt_nodes = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (field[i][j] != -1) {
				nodes[i][j] = cnt_nodes++;
				cells.push_back({i, j});
			}
		}
	}

	vector<vector<int>> graph(cnt_nodes);

	auto add_word = [&](int x1, int y1, int x2, int y2) {
		vector<int> cur_nodes;
		for (int x = x1; x < x2; ++x) {
			for (int y = y1; y < y2; ++y) {
				cur_nodes.push_back(nodes[x][y]);
			}
		}

		for (int i = 0; i < szof(cur_nodes) - i - 1; ++i) {
			graph[cur_nodes[i]].push_back(cur_nodes[szof(cur_nodes) - i - 1]);
			graph[cur_nodes[szof(cur_nodes) - i - 1]].push_back(cur_nodes[i]);
		}
	};

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (field[i][j] != -1) {
				if (i == 0 || field[i - 1][j] == -1) {
					int k = i;
					while (k < n && field[k][j] != -1) {
						++k;
					}
					add_word(i, j, k, j + 1);
				}
				if (j == 0 || field[i][j - 1] == -1) {
					int k = j;
					while (k < m && field[i][k] != -1) {
						++k;
					}
					add_word(i, j, i + 1, k);
				}
			}
		}
	}

	vector<int> visited;
	vector<bool> used(cnt_nodes);

	vector<vector<int>> ans(n, vector<int>(m));

	queue<int> qu;

	for (int i = 0; i < cnt_nodes; ++i) {
		if (!used[i]) {
			visited.clear();
			qu.push(i);
			used[i] = true;
			while (szof(qu)) {
				int v = qu.front();
				qu.pop();
				visited.push_back(v);
				for (int to : graph[v]) {
					if (!used[to]) {
						used[to] = true;
						qu.push(to);
					}
				}
			}

			int cur_best = INF;
			int mem = -1;
			for (int d = 0; d < 10; ++d) {
				int val = 0;
				for (int v : visited) {
					auto [x, y] = cells[v];
					val += abs(field[x][y] - d);
				}
				if (val < cur_best) {
					cur_best = val;
					mem = d;
				}
			}

			for (int v : visited) {
				auto [x, y] = cells[v];
				ans[x][y] = mem;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (field[i][j] == -1) {
				cout << ".";
			} else {
				cout << ans[i][j];
			}
		}
		cout << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
