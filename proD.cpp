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
typedef long double ld;
struct data
{
    int u, v;
    ll w;
};

int n, m;
long long s1 = 0, s2 = 1e18;
data a[maxn];
int root[maxn];
vector <int> kq;

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
}

bool comp(data p, data q)
{
    return p.w < q.w;
}

int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

void Kruskal1()
{
    sort(a+1, a+m+1, comp);
    memset(root, 0, sizeof(root));
    for (int i = 1; i <= m; i++)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
		if (p != q){
			root[p] = q;
			s1 += a[i].w;
			kq.PB(i);
		}
    }
}
void Krusal2(int z)
{
    ll res = 0;
    reset(root);
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        if(i == z) continue;
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
		if (p != q){
			root[p] = q;
			res += a[i].w;
			++cnt;
		}
    }
    if (cnt == n - 1)s2 = min(s2, res);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
	nhap();
    Kruskal1();
    for (int z : kq) Krusal2(z);
    cout << s1 << " " << s2;
}
