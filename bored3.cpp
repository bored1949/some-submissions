#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
#define sz(a) (ll)a.size()
const ll N = 1e5 + 7;
const ll inf = 1e15;
const ll mod = 1e9 + 7;
ll please(string s)
{
    ll it1 = 0, it2 = sz(s) - 1;
    string ss = "";
    while (it1 <= it2)
    {
        if (s[it1] == '0')
        {
            it1++;
        }
        else
        {
            break;
        }
    }
    while (it2 >= it1)
    {
        if (s[it2] == '0')
        {
            it2--;
        }
        else
        {
            break;
        }
    }
    for (int i = it1; i <= it2; i++)
    {
        ss += s[i];
    }
    ll ones = 0, zeros = 0;
    for (int i = 0; i < sz(ss); i++)
    {
        if (ss[i] == '0')
        {
            zeros++;
        }
    }
    ll n = sz(ss);
    if (n == 0)
    {
        // cout << 0 << endl;
        return 0;
        // continue;
    }
    ll pre1[n], pre0[n];
    pre1[0] = 1;
    pre0[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pre1[i] = pre1[i - 1];
        pre0[i] = pre0[i - 1];
        if (ss[i] == '1')
        {
            pre1[i]++;
        }
        else
        {
            pre0[i]++;
        }
    }
    ll cost = zeros;
    if (cost == 0)
    {
        // cout << 0 << endl;
        return 0;
        // continue;
    }
    ll id = -1;
    for (int i = 0; i < n; i++)
    {
        ll tc = zeros - pre0[i];
        tc = max(tc, pre1[i]);
        if (tc <= cost)
        {
            cost = tc;
            id = i;
        }
        // cout << i << " " << cost << " " << tc << " " << pre1[i] << " " << pre0[i] << endl;
    }
    string pp = "";
    for (int i = id + 1; i < n; i++)
    {
        pp += ss[i];
    }
    ones = 0;
    if (id != -1)
        ones = pre1[id];
    // cout << cost << endl;
    n = sz(pp);
    ll post1[n], post0[n];
    post1[n - 1] = 1;
    post0[n - 1] = 0;
    zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if (pp[i] == '0')
        {
            zeros++;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        post1[i] = post1[i + 1];
        post0[i] = post0[i + 1];
        if (pp[i] == '1')
        {
            post1[i]++;
        }
        else
        {
            post0[i]++;
        }
    }
    // cout << pp << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        ll tc = zeros - post0[i];
        tc = max(tc, post1[i] + ones);
        if (tc <= cost)
        {
            cost = tc;
            id = i;
        }
        // cout << i << " " << cost << " " << tc << " " << pre1[i] << " " << pre0[i] << endl;
    }
    // cout << cost << endl;
    return cost;
}
ll work(string s)
{
    ll it1 = 0, it2 = sz(s) - 1;
    string ss = "";
    while (it1 <= it2)
    {
        if (s[it1] == '0')
        {
            it1++;
        }
        else
        {
            break;
        }
    }
    while (it2 >= it1)
    {
        if (s[it2] == '0')
        {
            it2--;
        }
        else
        {
            break;
        }
    }
    for (int i = it1; i <= it2; i++)
    {
        ss += s[i];
    }
    ll ones = 0, zeros = 0;
    for (int i = 0; i < sz(ss); i++)
    {
        if (ss[i] == '0')
        {
            zeros++;
        }
    }
    ll n = sz(ss);
    if (n == 0)
    {
        // cout << 0 << endl;
        return 0;
        // continue;
    }
    ll post1[n], post0[n];
    post1[n - 1] = 1;
    post0[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        post1[i] = post1[i + 1];
        post0[i] = post0[i + 1];
        if (ss[i] == '1')
        {
            post1[i]++;
        }
        else
        {
            post0[i]++;
        }
    }
    // cout << pp << endl;
    ll cost = zeros;
    ll id = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        ll tc = zeros - post0[i];
        tc = max(tc, post1[i]);
        if (tc <= cost)
        {
            cost = tc;
            id = i;
        }
        // cout << i << " " << cost << " " << tc << " " << pre1[i] << " " << pre0[i] << endl;
    }
    string pp = "";
    for (int i = 0; i < id; i++)
    {
        pp += ss[i];
    }
    ones = 0;
    if (id != -1)
        ones = post1[id];
    n = sz(pp);
    ll pre1[n], pre0[n];
    pre1[0] = 1;
    pre0[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pre1[i] = pre1[i - 1];
        pre0[i] = pre0[i - 1];
        if (pp[i] == '1')
        {
            pre1[i]++;
        }
        else
        {
            pre0[i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll tc = zeros - pre0[i];
        tc = max(tc, pre1[i] + ones);
        if (tc <= cost)
        {
            cost = tc;
            id = i;
        }
        // cout << i << " " << cost << " " << tc << " " << pre1[i] << " " << pre0[i] << endl;
    }
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        ll ans = min(please(s), work(s));
        cout << ans << endl;
    }
    return 0;
}
