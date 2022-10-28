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
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
    {
        ll n, q;
        cin >> n >> q;
        ll a[n];
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        sort(a, a+n, greater<ll>());
        ll b[n] = {0};
        b[0] = a[0];
        for(int i=1; i<n; i++)
        {
            b[i] = b[i-1] + a[i];
        }
        vector<pair<ll, ll>>que;
        for(int i=0; i<q; i++)
        {
            ll x;
            cin >> x;
            que.push_back({x, i});
        }
        sort(que.begin(), que.end());
        ll it = 0;
        ll qt = 0;
        ll ans[q];
        for(int i=0; i<q; i++)
        {
            ans[i] = -1;
        }
        while(1)
        {
            if(it==n)
            {
                break;
            }
            if(qt==q)
            {
                break;
            }
            if(que[qt].first > b[it])
            {
                it++;
            }
            else
            {
                ans[que[qt].second] = it+1;
                qt++;
            }
        }
        for(int i=0; i<q; i++)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
