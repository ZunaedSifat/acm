#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;
ll mod = 1e9+7;

ll bigmod(ll num, ll exp) {
    if (exp == 0) return 1;
    ll ans = bigmod(num, exp/2);
    ans = ans * ans % mod;
    if (exp & 1) ans = ans * num % mod;
    return ans;
}

struct Hash {
    vector <ll> hash[2], power[2];
    ll prime[2] = {131, 133};

    Hash(const string &str) {
        for (ll i = 0; i < 2; i++) {
            hash[i].resize(str.size()+1);
            power[i].resize(str.size()+1);
        }

        power[0][0] = power[1][0] = 1;
        for (ll hid = 0; hid < 2; hid++) {
            for (ll sid = 0; sid < str.size(); sid++) {
                hash[hid][sid+1] = (hash[hid][sid] + str[sid] * power[hid][sid]) % mod;
                power[hid][sid+1] = power[hid][sid] * prime[hid] % mod;
            }
        }
    }


    pll get_hash(ll l, ll r) { // 1-indexed
        assert(l <= r and l > 0);

        ll res[2];
        for (ll hid = 0; hid < 2; hid++) {
            res[hid] = (hash[hid][r] - hash[hid][l-1]) * bigmod(power[hid][l], mod-2) % mod;
        }

        return make_pair(res[0], res[1]);
    }
};

signed main() {

    string str;
    cin >> str;

    Hash hash(str);
    for (ll l = 0; l < str.size(); l++) {
        for (ll r = l; r < str.size(); r++) {
            auto hash_value = hash.get_hash(l+1, r+1);
            cout << l << " " << r << " " << hash_value.first << " " << hash_value.second << endl;
        }
    }

    return 0;

}