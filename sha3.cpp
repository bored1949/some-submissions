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
        ll n, m;
        cin >> n >> m;
        vector<string> s;
        for(int i=0; i<n; i++)
        {
            string x;
            cin >> x;
            s.push_back(x);
        }
        ll mn = inf, temp = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                temp = 0;
                for(int k=0; k<m; k++)
                {
                    temp += abs((ll)s[i][k] - (ll)s[j][k]);
                }
                mn = min(mn, temp);
            }
        }
        cout << mn << endl;
    }
    return 0;
}
