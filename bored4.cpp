#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define sz(a) (ll)a.size()
const ll N = 1e5 + 7;
const ll inf = 1e15;
const ll mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[n][m];
        for(int i=0; i<n; i++)
        {
            string s;
            cin >> s;
            for(int j=0; j<m; j++)
            {
                if(s[j]=='E')
                {
                    a[i][j] = 0;
                }
                else
                {
                    a[i][j] = 1;
                }
            }
        }
        int it1 = -1, it2 = -1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i][j]==1)
                {
                    it1 = i;
                    it2 = j;
                    break;
                }
            }
            if(it1!=-1)
            {
                break;
            }
        }
        int f1 = 0, f2 = 0;
        if(it1!=-1)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<it2; j++)
                {
                    if(a[i][j]==1)
                    {
                        f1 = 1;
                    }
                }
            }
        }
        it1 = -1, it2 = -1;
        for(int j=0; j<m; j++)
        {
            for(int i=0; i<n; i++)
            {
                // cout << "ye " << i << " " << j << endl;
                if(a[i][j]==1)
                {
                    // cout << "oo " << endl;
                    it1 = i;
                    it2 = j;
                    break;
                }
            }
            if(it1!=-1)
            {
                break;
            }
        }
        // cout << it1 << " " << it2 << endl;
        if(it1!=-1)
        {
            for(int i=0; i<it1; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(a[i][j]==1)
                    {
                        f2 = 1;
                    }
                }
            }
        }
        // cout << it1 << " " << it2 << endl;
        if(f1==0 || f2==0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
