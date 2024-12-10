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

bool is_int(char c){
	return c >= '0' && c <= '9';
}

void uwu(){
	string s;
	ll ans = 0;
	bool ok = 1;
	while(cin >> s){
		int n = sz(s);
		FOR(i,0,n){
			string v = s.substr(i, 4);
			if(v == "do()"){
				ok = 1;
			}
			if(s.substr(i,7) == "don't()"){
				ok = 0;
			}
			if(v == "mul("){
				int j = i + 4;
				string a;
				while(j < n && is_int(s[j])){
					a.pb(s[j]);
					j++;
				}
				if(s[j] == ','){
					j++;
					string b;
					while(j < n && is_int(s[j])){
						b.pb(s[j]);
						j++;
					}
					if(ok && s[j] == ')'){
						ans += stoll(a) * stoll(b);
					}
				}
			}
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
