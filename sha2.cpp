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
ll m, n;
ll a[300][300];
ll lu(ll x, ll y)
{
    ll sum = 0;
    ll it1 = x, it2 = y;
    it1--;
    it2--;
    while(it1>=0 && it2>=0)
    {
        sum += a[it1][it2];
        it1--;
        it2--;
    }
    return sum;
}
ll ru(ll x, ll y)
{
    ll sum = 0;
    ll it1 = x, it2 = y;
    it1--;
    it2++;
    while(it1>=0 && it2<m)
    {
        sum += a[it1][it2];
        it1--;
        it2++;
    }
    return sum;
}
ll ld(ll x, ll y)
{
    ll sum = 0;
    ll it1 = x, it2 = y;
    it1++;
    it2--;
    while(it1<n && it2>=0)
    {
        sum += a[it1][it2];
        it1++;
        it2--;
    }
    return sum;
}
ll rd(ll x, ll y)
{
    ll sum = 0;
    ll it1 = x, it2 = y;
    it1++;
    it2++;
    while(it1<n && it2<m)
    {
        sum += a[it1][it2];
        it1++;
        it2++;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> a[i][j];
            }
        }
        ll ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ll temp = a[i][j] + lu(i, j) + ru(i, j) + ld(i, j) + rd(i, j);
                ans = max(ans, temp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
