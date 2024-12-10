#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
using ll = long long;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define pq priority_queue
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define trav(a,x) for(auto& a: x)
#define sz(x) (int)x.size()
#define make_unique(v) v.erase(unique(all(v)), v.end());
 
template<class T> using minpq = pq<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

#define F0R(i, b) for(int i = 0; i < (b); ++i)

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void uwu(){
	vector<string> g;
	string s;
	while(cin >> s){
		g.pb(s);
	}
	int n = sz(g), m = sz(g[0]);
	array<int, 3> init;
	FOR(i,0,n) FOR(j,0,m) if(g[i][j] == '^') init = {i, j, 0};
	debug(n, m);
	auto test = [&]() -> int{
		array<int, 3> cur = init;
		set<array<int, 3>> res;
		FOR(step,0, 2 * n * m){
			if(res.count(cur)) return true;
			res.insert(cur);
			int nr = cur[0] + dx[cur[2]];
			int nc = cur[1] + dy[cur[2]];
			if(nr < 0 || nr >= n || nc < 0 || nc >= m) return false;
			if(g[nr][nc] == '#'){
				cur[2]++;
				cur[2] %= 4;
				continue;
			}
			cur[0] = nr; cur[1] = nc;
		}
		return true;
	};
	int ans = 0;
	FOR(i,0,n) FOR(j,0,m) if(g[i][j] == '.'){
		g[i][j] = '#';
		ans += test();
		g[i][j] = '.';
	}
	cout << ans << endl;
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	// cin>>t;
	while(t--){
		uwu();
	}
}
