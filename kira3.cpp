#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define sz(a) (ll)a.size()
const ll N = 1e5 + 7;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
vector<ll> edges[N];
ll bal[N];
ll vis[N];
string s;
ll dfs(int i)
{
    vis[i] = 1;
    ll f = 0;
    for(int j=0; j<sz(edges[i]); j++)
    {
        if(vis[edges[i][j]]==0)
        {
            f = 1;
            bal[i] += dfs(edges[i][j]);
        }
    }
    ll ret = bal[i];
    if(s[i-1]=='W')
    {
        bal[i]++;
    }
    else
    {
        bal[i]--;
    }
    return bal[i];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for(int i=0; i<n-1; i++)
        {
            cin >> a[i];
        }
        cin >> s;
        for(int i=0; i<n-1; i++)
        {
            edges[a[i]].push_back(i+2);
        }
        bal[1] = dfs(1);
        ll ans = 0;
        for(int i=1; i<=n; i++)
        {
            // cerr << bal[i] << " ";
            if(bal[i]==0)
            {
                // cerr << i << " ";
                ans++;
            }
        }
        // cerr << endl;
        cout << ans << endl;
        for(int i=0; i<=n; i++)
        {
            bal[i] = 0;
            vis[i] = 0;
            edges[i].clear();
        }
    }
    return 0;
}
