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
#define maxn 505
#define MOD
#define Task "proE"
using namespace std;
//ifstream fi(Task".inp");
//ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
struct canh{
	int u, v;
	int w;
};
int n, m;
vector <canh> edg;
int par[maxn];
int root(int v) {
    return !par[v]
            ? v
            : (par[v] = root(par[v]));
}
void krusal()
{
    reset(par);
    canh edge;
    cin >> edge.u >> edge.v >> edge.w;
    edg.PB(edge);
    for (int i = sz(edg) - 1; i > 0; i --)
        if (edg[i].w < edg[i - 1].w) swap(edg[i], edg[i - 1]);
        else break;
    int sum = 0;
    vector<canh> vt;
    for (int i = 0; i < sz(edg); i ++)
    {
        int x = edg[i].u;
        int y = edg[i].v;
        x = root(x);
        y = root(y);
        if (x != y)
        {
            par[x] = y;
            sum += edg[i].w;
            vt.PB(edg[i]);
        }
    }
    edg = vt;
    if (sz(edg) == n - 1) cout << sum << "\n";
    else cout << "-1\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m;
    while (m --)
        krusal();
}
