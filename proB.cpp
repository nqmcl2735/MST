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
#define maxn 10005
#define MOD
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef double ld;
int n, m;
ld kc[5005][5005];
ld d[5005];
pair <ld, ld> dinh[5005];
bool used[5005];
ld ans = 0;
void Push(int u)
{
    used[u] = 1;
    for (int v = 1; v <= n; v ++) {
        if (u == v) continue;
        if (used[v] == 0 && kc[u][v] < d[v])
			d[v] = kc[u][v];
    }
}
void Sol()
{
    fill(d, d+n+1, 1e9);
    Push(1);
    d[1] = 0;
    while (1){
        int u = 0;
        for (int i = 1; i <= n; i++)
            if (used[i] == 0 && d[i] < d[u]) u = i;
        if (u == 0) break;
        ans += d[u];
		Push(u);
    }
    printf("%0.2f", ans);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> dinh[i].F >> dinh[i].S;
    for (int i = 1; i < n; i ++)
        for (int j = i + 1; j <= n; j ++)
            kc[i][j] = kc[j][i] = sqrt((dinh[i].F - dinh[j].F)*(dinh[i].F - dinh[j].F) + (dinh[i].S - dinh[j].S)*(dinh[i].S - dinh[j].S));
    cin >> m;
    while (m --)
    {
        int u, v;
        cin >> u >> v;
        kc[u][v] = kc[v][u] = 0;
    }
    Sol();
}
