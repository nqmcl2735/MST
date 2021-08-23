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
#define maxn 200005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, k;
struct canh{
	int u, v, w;
};
canh edg[100011];
int par[maxn];
int root(int v) {
    return !par[v]
            ? v
            : (par[v] = root(par[v]));
}
int tplt;
int ans = -1;
int d[505][505];
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
    if (tplt != k) {
        par[x] = y;
        tplt --;
    }
    else {
        cout << edg[i].w;
        exit(0);
    }
}
bool cmp(canh i, canh j)
{
	return (i.w < j.w);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> k;
    tplt = n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> d[i][j];
    int cnt = 0;
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++) {
            edg[++ cnt].u = i;
            edg[cnt].v = j;
            edg[cnt].w = d[i][j];
        }
    sort(edg + 1, edg + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i ++)
        noi(i);
}
