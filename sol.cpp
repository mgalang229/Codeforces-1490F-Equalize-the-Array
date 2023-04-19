#include <bits/stdc++.h>
using namespace std;

/*

a[i] (where 1 <= i <= N)
=> occurs 0 or C times

8
1 2 3 3 3 2 6 6

alternative approach:
1 2 3 4 5 6
1 2 3 0 0 2

  1 2 6 3 
  1 2 2 3
 -
  1 1 1 1
 ---------
  0 1 1 2

 removed = 0
 = ((n - current_freq_total - removed) - (m - i) * freq[i]) + removed
 = ((8 - 1 - 0) - (4 - 1) * 1) + 0
 = (7 - 3) + 0
 = 4
 removed = freq[i]

 removed = 1
 = ((8 - 4 - 1) - (4 - 3) * 2) + 1
 = (3 - 2) + 1
 = 2

*/

void test_case(int& tc) {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, int> mp;
	int mx = 0;
	for (int& x : a) {
		mp[x]++;
		mx = max(mx, mp[x]);
	}
	// ((n - current_freq_total - removed) - (m - j) * freq[i]) + removed
	int m = mp.size();
	int freq[m], index = 0;
	memset(freq, 0, sizeof(freq));
	for (pair<int, int> p : mp)
		freq[index++] = p.second;
	sort(freq, freq + m);
	// for (int i = 0; i < m; i++)
	// 	cout << freq[i] << " ";
	// cout << "\n";
	int mn = n, removed = 0;
	for (int i = 0; i < m; i++) {
		int j = i, current_freq_total = 0;
		while (j < m && freq[i] == freq[j]) {
			current_freq_total += freq[j++];
		}
		mn = min(mn, ((n - current_freq_total - removed) - (m - j) * freq[i]) + removed);
		// cout << ((n - current_freq_total - removed) - (m - j) * freq[i]) + removed << "\n";
		// cout << m - j << "\n\n";
		removed += current_freq_total;
		i = j - 1;
	}
	cout << mn << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
