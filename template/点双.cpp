int n, m;
int to[M], nt[M], hd[N], idx;
int root, dfn[N], low[N], stk[N], top, t, cnt;
vector<int> dcc[N];

void add(int u, int v) {
	to[ ++ idx] = v;
	nt[idx] = hd[u];
	hd[u] = idx;
}

void tarjan(int u, int root) {
	dfn[u] = low[u] = ++ t;
	stk[ ++ top] = u;
	if(u == root && !hd[u]) {
		dcc[ ++ cnt].push_back(u);
		return;
	}
	
	for(int i = hd[u]; i; i = nt[i]) {
		int v = to[i];
		if(!dfn[v]) {
			tarjan(v, root);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) {
				++ cnt;
				int y;
				do {
					y = stk[top -- ];
					dcc[cnt].push_back(y);
				}while(y != v);
				dcc[cnt].push_back(u);
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}