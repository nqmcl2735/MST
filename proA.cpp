//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 300005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct canh{
	int u, v, w;
};
int ans = 0;
canh edg[maxn];
int n, m;
int par[maxn];
int root(int v) {
    return par[v] == 0
            ? v
            : (par[v] = root(par[v]));
}
void noi(int i)
{
	int x = edg[i].u;
	int y = edg[i].v;
	x = root(x);
	y = root(y);
	if(x == y)
	{
        return ;
    }
    par[x] = y;
    ans += edg[i].w;
}
bool cmp(canh i, canh j)
{
	return (i.w < j.w);
}
int main() {
	cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    cin >> edg[i].u >> edg[i].v >> edg[i].w;
    sort(edg + 1, edg + m + 1, cmp);
    for (int i = 1; i <= m; i ++)
    noi(i);
    cout << ans;
}
