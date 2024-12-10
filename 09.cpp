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
	string s; cin >> s;
	int n = sz(s);
	vector<int> new_s;
	FOR(i,0,n){
		if(i % 2 == 0){
			FOR(j,0,s[i] - '0'){
				new_s.pb(i/2);
			}
		}
		else{
			FOR(j,0,s[i] - '0'){
				new_s.pb(-1);
			}
		}
	}
	vector<set<int>> start_pos(10);
	vector<array<int, 3>> stk;
	FOR(i,0,sz(new_s)){
		int j = i;
		while(j < sz(new_s) && new_s[i] == new_s[j]) j++;
		if(new_s[i] == -1){
			start_pos[j - i].insert(i);
		}
		else{
			stk.pb({new_s[i], i, j - i});
		}
		i = j - 1;
	}
	reverse(all(stk));
	for(auto [label, index, len] : stk){
		// iterate over spots greater
		pair<int, int> min_at = {1e9, 1e9}; // {min index, length}
		FOR(gap, len, 10){
			if(!start_pos[gap].empty()){
				ckmin(min_at, {*start_pos[gap].begin(), gap});
			}
		}
		if(min_at.F < index){
			// place it here
			start_pos[min_at.S].erase(min_at.F);
			start_pos[min_at.S - len].insert(min_at.F + len);
			FOR(i,min_at.F, min_at.F + len) new_s[i] = label;
			FOR(i,index,index + len) new_s[i] = -1;
		}
	}
	// debug(new_s);
	ll ans = 0;
	FOR(i,0,sz(new_s)){
		if(new_s[i] != -1){
			ans += (ll) new_s[i] * i;
		}
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
