#include <bits/stdc++.h>
using namespace std;

long long T,n,x,a[200005];

long long get_xor(int l,int r) {return a[r]^a[l-1];}//区间异或值

long long dfs(long long x)
{
	if(x <= n) return get_xor(x,x);//在a中直接返回
	if(x/2 <= n) return get_xor(1,x/2);//可以直接得出就直接得出
	long long the_ans = get_xor(1,n);//必定包含a所有数的异或和
	if(((x/2)&1) == 0) the_ans ^= dfs(x/2);//说明x/2号元素不能被抵消，递归下去计算
	if((n&1) == 0) the_ans ^= dfs(n+1);//说明n+1号元素不能被抵消，递归下去计算，注意这里dfs(n+1)是O(1)求解的
	return the_ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> x >> x;
		for(int i = 1;i <= n;i++) cin >> a[i];
		for(int i = 1;i <= n;i++) a[i] ^= a[i-1];//以便求区间异或
		cout << dfs(x) << '\n';
	}
	return 0;
}