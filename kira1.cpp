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
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2)
        {
            swap(l1, l2);
            swap(r1, r2);
        }
        if(r1>=l2)
        {
            cout << max(l2, l1) << endl;
        }
        else
        {
            cout << l1 + l2 << endl;
        }
    }
    return 0;
}
