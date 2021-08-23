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
struct canh{
	int u, v, pos;
	int w;
	bool thuocC = 0;
};
canh edg[maxn];
canh C[maxn];
int n, m, k;
int tplt;
int par[maxn];
int cntC;
int root(int v) {
    return !par[v]
            ? v
            : (par[v] = root(par[v]));
}
//void noi(canh ef)
//{
//	int x = ef.u;
//	int y = ef.v;
//	x = root(x);
//	y = root(y);
//	if(x == y)
//    {
//        return ;
//    }
//    par[x] = y;
//}
bool cmp(canh i, canh j)
{
	return (i.w < j.w);
}
bool comp(canh i, canh j)
{
    return (i.pos < j.pos);
}
void Sol()
{
    cntC = 0;
    sort(edg + 1, edg + m + 1, cmp);
    for (int i = 1; i <= m; i ++) {
        int x = edg[i].u;
        int y = edg[i].v;
        x = root(x);
        y = root(y);
        if(x != y) {
            par[x] = y;
            if (edg[i].w)
            {
                edg[i].thuocC = 1;
                C[++ cntC] = edg[i];
            }
        }
    }
    if (cntC > k)
    {
        cout << "-1";
        exit(0);
    }
    reset(par);
    for (int i = 1; i <= cntC; i ++) {
        int x = C[i].u;
        int y = C[i].v;
        x = root(x);
        y = root(y);
        if(x != y)
            par[x] = y;
    }
    for (int i = 1; i <= m; i ++) {
        if (edg[i].w && !edg[i].thuocC) {
            int x = edg[i].u;
            int y = edg[i].v;
            x = root(x);
            y = root(y);
            if(x != y) {
                par[x] = y;
                edg[i].thuocC = 1;
                C[++ cntC] = edg[i];
            }
        }
        if (cntC == k) break;
    }
    if (cntC < k)
    {
        cout << "-1";
        exit(0);
    }
    for (int i = 1; i <= m; i ++) {
        if (!edg[i].w)
        {
            int x = edg[i].u;
            int y = edg[i].v;
            x = root(x);
            y = root(y);
            if(x != y) {
                par[x] = y;
                C[++ cntC] = edg[i];
            }
        }
        if (cntC == n - 1) break;
    }
    sort(C + 1, C + cntC + 1, comp);
    for (int i = 1; i <= cntC; i ++)
        cout << C[i].pos << " ";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
    {
        canh ch;
        cin >> edg[i].u >> edg[i].v >> edg[i].w;
        edg[i].pos = i;
    }
    Sol();
}
