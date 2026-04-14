#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define all(x) (x).begin(), (x).end()
using namespace std;
struct DSU {
	std::vector<int> f, siz;
	
	DSU() {}
	DSU(int n) {
		init(n);
	}
	
	void init(int n) {
		f.resize(n);
		std::iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}
	
	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}
	
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	
	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		siz[x] += siz[y];
		f[y] = x;
		return true;
	}
	
	int size(int x) {
		return siz[find(x)];
	}
};

void solve(){
	int n,m;
	cin>>n>>m;
	ll ans=0;
	ll mod=1e9+7;
	ll ans2=1;
	vector<vector<pii>>a(1000010);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		if(u!=v){
			a[w].push_back({u,v});
		}
	}
	DSU dsu(n);
	for(int i=1;i<=1000000;i++){
		if(a[i].size()==0){
			continue;
		}
		if(a[i].size()==1){
			if(dsu.same(a[i][0].first,a[i][0].second)){
				continue;
			}
			ans+=i;
			dsu.merge(a[i][0].first,a[i][0].second);
		}
		if(a[i].size()==2){
			map<pair<int,int>,int>cnt;
			for(int j=0;j<a[i].size();j++){
				cnt[{min(dsu.find(a[i][j].first),dsu.find(a[i][j].second)),max(dsu.find(a[i][j].first),dsu.find(a[i][j].second))}]++;
			}
			for(auto x:cnt){
				if(x.first.first!=x.first.second){
					ans2*=x.second;
					ans2%=mod;
					ans+=i;
					dsu.merge(x.first.first,x.first.second);
				}
			}
		}	
		if(a[i].size()==3){
			map<pair<int,int>,int>cnt;
			for(int j=0;j<a[i].size();j++){
				if(min(dsu.find(a[i][j].first),dsu.find(a[i][j].second))!=max(dsu.find(a[i][j].first),dsu.find(a[i][j].second))){
					cnt[{min(dsu.find(a[i][j].first),dsu.find(a[i][j].second)),max(dsu.find(a[i][j].first),dsu.find(a[i][j].second))}]++;
				}
			}
			if(cnt.size()!=3){
				for(auto x:cnt){
					if(x.first.first!=x.first.second){
						ans2*=x.second;
						ans2%=mod;
						ans+=i;
						dsu.merge(x.first.first,x.first.second);
					}
				}
			}else{
				vector<pair<int,int>>t;
				for(auto x:cnt){
					t.push_back(x.first);
				}
				sort(t.begin(),t.end());
				if(t[0].first==t[1].first&&t[0].second==t[2].first&&t[1].second==t[2].second){
					ans2*=3;
					ans2%=mod;
					ans+=i*2;
					dsu.merge(t[0].first,t[0].second);
					dsu.merge(t[1].first,t[1].second);
				}else{
					ans+=i*3;
					for(auto x:t){
						dsu.merge(x.first,x.second);
					}
				}
			}
		}
	}
	cout<<ans<<" "<<ans2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++){
		solve();
		cout<<'\n';
	}
	return 0;
}