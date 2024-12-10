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

template<typename T>
vector<string> split(T str, char sep){
	vector<string> output;
	size_t start = 0, end = 0;
	while((end = str.find(sep,start)) != string::npos){
		if(end != start)output.push_back(str.substr(start,end-start));
		start = end+1;
	}
	
	if(end != start)output.push_back(str.substr(start));
	return output;
	
}

void uwu(){
	int ans = 0;
	while(1){
		if(cin.eof()) break;
		string s; getline(cin, s);
		auto spl = split(s, ' ');
		vector<int> v;
		trav(i, spl) v.pb(stoi(i));
		if(!is_sorted(all(v))) reverse(all(v));
		if(is_sorted(all(v))){
			int ok = 1;
			FOR(i,0,sz(v) - 1){
				ll d = abs(v[i+1] - v[i]);
				ok &= d >= 1 && d <= 3;
			}
			if(ok){
				ans++;
				goto outer;
			}
		}
		FOR(rem,0,sz(v)){
			vector<int> a = v;
			a.erase(a.begin() + rem, a.begin() + rem + 1);
			if(!is_sorted(all(a))) reverse(all(a));
			if(is_sorted(all(a))){
				int ok = 1;
				FOR(i,0,sz(a) - 1){
					ll d = abs(a[i+1] - a[i]);
					ok &= d >= 1 && d <= 3;
				}
				if(ok){
					ans++;
					goto outer;
				}
			}
		}
		outer:;
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
