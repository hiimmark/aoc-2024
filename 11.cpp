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
	vector<ll> a;
	ll x;
	while(cin >> x) a.pb(x);
	
	// part 1
	
	// FOR(op,0,75){
		// vector<ll> b;
		// trav(i, a){
			// if(i == 0){
				// b.pb(1);
				// continue;
			// }
			// string str = to_string(i);
			// if(sz(str) % 2 == 0){
				// string left = str.substr(0, sz(str) / 2);
				// string right = str.substr(sz(str) / 2);
				// b.pb(stoll(left));
				// b.pb(stoll(right));
			// }
			// else{
				// b.pb(i * 2024);
			// }
		// }
		// a = b;
	// }
	// cout << sz(a) << endl;
	
	map<ll, ll> cnt;
	trav(i, a) cnt[i]++;
	FOR(op,0,75){
		map<ll, ll> cnt2;
		trav(i, cnt){
			if(i.F == 0){
				cnt2[1] += i.S;
				continue;
			}
			string str = to_string(i.F);
			if(sz(str) % 2 == 0){
				string left = str.substr(0, sz(str) / 2);
				string right = str.substr(sz(str) / 2);
				cnt2[stoll(left)] += i.S;
				cnt2[stoll(right)] += i.S;
			}
			else{
				cnt2[i.F * 2024] += i.S;
			}
		}
		cnt = cnt2;
	}
	ll ans = 0;
	trav(i, cnt) ans += i.S;
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
