#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define sz(a) (ll)a.size()
const ll N = 4e4 + 1;
const ll inf = 1e15;
const ll mod = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                a[i][j] = 0;
            }
        }
        if(k%n==0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
        int i=0, j=0;
        while(k--)
        {
            //cerr << "here " << i << " " << j << endl;
            a[i][j] = 1;
            i += 1;
            i %= n;
            j++;
            if(j>=n)
            {
                i++;
                j %= n;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                //cout << "here1 " << i << " " << j << endl;
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}


