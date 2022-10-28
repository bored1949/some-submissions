#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define sz(a) (ll)a.size()
const ll N = 5e3 + 7;
const ll inf = 1e15;
const ll mod = 1e9 + 7;

ll dp[N][N];
int main()
{
    int n;
    cin >> n;
    ll a[n], b[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }
    ll isum = 0;
    for(int i=0; i<n; i++)
    {
        isum += a[i]*b[i];
    }
    ll ans = isum;
    for(int i=1; i<=n; i++)
    {
        for(int j=i-1; j>=1; j--)
        {
            dp[j][i] = dp[j+1][i-1] + a[j-1]*b[i-1] + b[j-1]*a[i-1] - a[j-1]*b[j-1] - a[i-1]*b[i-1];
            //cout << dp[j][j] << " ";
            ans = max(ans, dp[j][i] + isum);
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}
