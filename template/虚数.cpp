const int N=100005,M=N*2;
int h[N],to[M],ne[M],tot;
void add(int x,int y){ //连边
  to[++tot]=y;ne[tot]=h[x];h[x]=tot;
}
int dep[N],fa[N][20],siz[N];
int dfn[N],cnt; //dfs序
int s[N],top;   //栈
int n,k,q,a[N],ans;

void dfs(int x, int f){ //树上倍增
  dfn[x]=++cnt;
  dep[x]=dep[f]+1; fa[x][0]=f; siz[x]=1; 
  for(int i=1; i<=19; i++) 
    fa[x][i]=fa[fa[x][i-1]][i-1];
    
  for(int i=h[x]; i; i=ne[i]){
    int y=to[i];
    if(y==f) continue;
    dfs(y,x);
    siz[x]+=siz[y];
  }
}
int lca(int x, int y){ //求lca
  if(dep[x]<dep[y])swap(x, y);
  for(int i=19; ~i; i--)
    if(dep[fa[x][i]]>=dep[y])
      x=fa[x][i];
  if(x==y) return y;
  
  for(int i=19; ~i; i--)
    if(fa[x][i]!=fa[y][i])
      x=fa[x][i], y=fa[y][i];
  return fa[x][0];
}
int cmp(int a,int b){ 
  return dfn[a]<dfn[b];
}
void build(){ //建虚树
  sort(a+1,a+k+1,cmp); //按dfs序排序
  tot=0; //清空
  s[top=1]=1; //根节点入栈
  if(a[1]!=1) s[++top]=a[1];
  for(int i=2; i<=k; i++){ //枚举查询点
    int l=lca(s[top],a[i]);
    // 对当前链连边,top出栈
    while(top>1 && dep[s[top-1]]>=dep[l]) 
      add(s[top-1],s[top]), top--;
    // 对lca和top连边,top出栈,lca入栈
    if(l!=s[top]) add(l,s[top]), s[top]=l;
    // 查询点入栈
    s[++top]=a[i];
  }
  while(top) //对最后一条链连边,top出栈
    add(s[top-1],s[top]), top--;
}