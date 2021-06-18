#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define rep(i,a,b) for(int i=a;i< b;i++)
#define endl "\n"
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define fr first
#define sc second
#define INF (int)(1e18)
#define pb push_back
#define ppb pop_back
#define sz(x) (int)((x).size())
#define vi vector<int>
#define vvi vector<vector<int>>
#define PI 3.14159265358979323846
using namespace std;
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
const int N = 2e5 + 5;

void test_case()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	set<int> zr, one, minus;
	rep(i, 0, n) {
		if (a[i] == 0) zr.insert(i);
		else {
			if (minus.count(i)) {
				minus.erase(i);
			} else {
				one.insert(i);
			}
			if (one.count(a[i])) {
				one.erase(a[i]);
			} else {
				minus.insert(a[i]);
			}
		}
	}
	assert(sz(one) == sz(minus));
	while (sz(one)) {
		a[*minus.begin()] = *one.begin();
		minus.erase(minus.begin());
		one.erase(one.begin());
	}
	for (auto it = zr.begin(); it != zr.end(); it++) {
		auto t = it;
		if (++t == zr.end()) {
			a[*it] = *zr.begin(); continue;
		}
		a[*it] = *(++t);
	}
	for (int x : a) cout << x << ' ' ;
}
signed main()
{
	fast_io;
#ifdef SIEVE
	sieve();
#endif
#ifdef NCR
	init();
#endif
	int t = 1;
	// cin >> t;
	rep(i, 0, t) {
		//cout<< "Case #" << i+1 << ": ";
		test_case();
	}
	return 0;
}
//taskkill -im main.exe -f
