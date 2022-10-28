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
        ll n, k;
        cin >> n >> k;
        ll a[n];
        map<ll, ll> m;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        vector<ll> v;
        for(int i=0; i<n; i++)
        {
            if(m[a[i]] >= k)
            {
                m[a[i]] = 0;
                v.push_back(a[i]);
            }
        }
        sort(v.begin(), v.end());
        if(sz(v) == 0)
        {
            cout << -1 << endl;
            continue;
        }
        if(sz(v) == 1)
        {
            cout << v[0] << " " << v[0] << endl;
            continue;
        }
        ll tl = v[0];
        ll tr = v[0];
        ll l = v[0];
        ll r = v[0];
        ll prev = v[0];
        for(int i=0; i<sz(v); i++)
        {
            if(abs(prev-v[i])>1)
            {
                // cerr << i << ": " << tl << " " << tr << " " << endl;
                if((r-l) < (tr - tl))
                {
                    r = tr;
                    l = tl;
                }
                tr = v[i];
                tl = v[i];
                prev = v[i];
            }
            else
            {
                tr = v[i];
                prev = v[i];
            }
        }
        if((r-l) < (tr - tl))
        {
            r = tr;
            l = tl;
        }
        cout << l << " " << r << endl;
    }
    return 0;
}
