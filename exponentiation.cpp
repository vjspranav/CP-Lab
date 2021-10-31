#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll loop_power(ll x, ll y)
{
    ll ans = 1LL;
    while (y > 0)
    {
        if (x & 1)
        {
            ans = x * ans;
        }
        y >>= 1;
        x *= x;
    }
    return ans;
}

ll recursive_power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll newY = y / 2LL;
    ll res = recursive_power(x, newY);
    if (y % 2)
        return res * res * x;
    else
        return res * res;
}

int main()
{
    ll m, p;
    cin >> m >> p;
    cout << "Recursive: " << recursive_power(m, p) << endl;
    cout << "Loop: " << recursive_power(m, p) << endl;
    return 0;
}