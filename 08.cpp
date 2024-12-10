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

void uwu(){
	vector<string> g;
	string s;
	while(cin >> s) g.pb(s);
	int n = sz(g);
	set<pair<int, int>> bruh;
	FOR(x1,0,n) FOR(y1,0,n) FOR(x2,0,n) FOR(y2,0,n){
		if(x1 != x2 || y1 != y2){
			if(g[x1][y1] != '.'){
				if(g[x1][y1] == g[x2][y2]){
					int dx = x2 - x1, dy = y2 - y1;
					pair<int, int> p1 = {x2 + dx, y2 + dy}, p2 = {x1 - dx, y1 - dy};
					FOR(mult,0,1000000){
						pair<int, int> p = {x2 + mult * dx, y2 + mult * dy};
						if(p.F < 0 || p.F >= n || p.S < 0 || p.S >= n) break;
						bruh.insert(p);
					}
					FOR(mult,0,1000000){
						pair<int, int> p = {x1 - mult * dx, y1 - mult * dy};
						if(p.F < 0 || p.F >= n || p.S < 0 || p.S >= n) break;
						bruh.insert(p);
					}
				}
			}
		}
	}
	cout << sz(bruh) << endl;
}

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	// cin>>t;
	while(t--){
		uwu();
	}
}
