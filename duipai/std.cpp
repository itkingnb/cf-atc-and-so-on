#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 7;
int N, M, tower[MAX];

#define endl '\n'
/*并查集组件*/
int fa[MAX];
inline int find(int n)
{
     if (n == fa[n])
          return n;
     return fa[n] = find(fa[n]);
}
inline void merge(int x, int y)
{
     fa[find(x)] = find(y);
}

/*vector 组件*/
vector<int> son[MAX];
void swap_int(int &a, int &b)
{
     int tmp = a;
     a = b;
     b = tmp;
}

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     cin >> N >> M;
     int sum = N - 1;
     for (register int i = 1; i <= N; i++)
     {
          int tt;
          cin >> tt;
          tower[i] = tt;//i是这个塔的
          fa[i] = i;//并查集处理
          son[tt].push_back(i);//这个塔上有个i
     }
     for (register int i = 2; i <= N; i++)
     {
          if (tower[i] == tower[i - 1])
               sum--;//先看看初始状态总共有多少贴贴
     }
     cout << sum << endl;
     for (register int k = 1; k <= M - 1; k++)
     {
          int x, y;
          cin >> x >> y;
          int fx = find(x);
          int fy = find(y);//先抓到祖先
          if (son[fx].size() > son[fy].size())
          {
               swap_int(fx, fy);//偏偏处理size小的，贪一把
          }
          for (register int i = 0; i < son[fx].size(); i++)
          {
               int v = son[fx][i];
               if (find(tower[v - 1]) == fy)
                    sum--;//他的上位在塔里，sum--
               if (find(tower[v + 1]) == fy)
                    sum--;//他的下位在塔里，sum--
               son[fy].push_back(v);//倒出vector
          }
          merge(fx, fy);//合并
          cout << sum << endl;
     }
}
