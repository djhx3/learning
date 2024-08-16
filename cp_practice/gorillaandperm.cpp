#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const char nl = '\n';

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> permutation(n);
        for (int i = 0, j = k; i <= n-k; i++, j++) {
            permutation[i] = j;
        }
        for (int i = n-k+1; i < n; i++) {
            permutation[i] = i -n +k;
        }
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << nl;
    }
    return 0;
}