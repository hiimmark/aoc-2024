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

// if order.size() != n, then the graph has cycles
// ASSUMES 0 INDEXING
vector<int> toposort(vector<vector<int>>& G){
	int n = G.size();
	vector<int> deg(n), order;
	for(int i = 0; i < n; i++) for(int j: G[i]) deg[j]++;
	queue<int> q;
	for(int i = 0; i < n; i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		order.push_back(cur);
		for(int i: G[cur]){
			--deg[i];
			if(!deg[i]) q.push(i);
		}
	}
	return order;
}

void uwu(){
	vector<pair<int, int>> edges;
	string s;
	while(cin >> s){
		if(s.find('|') == string::npos) break;
		vector<string> spl = split(s, '|');
		edges.pb({stoi(spl[0]), stoi(spl[1])});
	}
	int n = 100;
	int ans = 0;
	while(cin >> s){
		vector<string> tmp = split(s, ',');
		vector<int> spl;
		trav(i, tmp) spl.pb(stoi(i));
		bool ok = 1;
		vector<int> at(n, -1);
		FOR(i,0,sz(spl)) at[spl[i]] = i;
		vector<vector<int>> g(n);
		trav(i, edges){
			if(at[i.F] != -1 && at[i.S] != -1){
				ok &= at[i.F] < at[i.S];
			}
		}
		if(!ok){
			// ans += spl[sz(spl) / 2];
			trav(i, edges){
				if(at[i.F] != -1 && at[i.S] != -1){
					g[i.F].pb(i.S);
				}
			}
			vector<int> topo = toposort(g);
			vector<int> order(n, -1);
			FOR(i,0,sz(topo)) order[topo[i]] = i;
			sort(all(spl), [&](int x, int y){
				return order[x] < order[y];
			});
			ans += spl[sz(spl) / 2];
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
