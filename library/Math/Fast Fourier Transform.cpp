#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

typedef long long LL;
typedef long double LD;
typedef pair <LL, LL> PLL;

const LL maxn = 100010;
const LL mod = 1000000007;


/**
    The following code for FFT has been taken from Emax,
    However, LL and LD has been used instead of int and double
*/

using cd = complex<LD>;
const LD PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    LL n = a.size();

    for (LL i = 1, j = 0; i < n; i++) {
        LL bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (LL len = 2; len <= n; len <<= 1) {
        LD ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (LL i = 0; i < n; i += len) {
            cd w(1);
            for (LL j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<LL> multiply(vector<LL> const& a, vector<LL> const& b) {

    assert(not a.empty());
    assert(not b.empty());

    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    LL n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (LL i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<LL> result(n);
    for (LL i = 0; i < n; i++)
        result[i] = round(fa[i].real());

    result.resize(a.size() + b.size() - 1);
    return result;
}


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    //    for polynomial x^2 + 2x + 3, a = {1, 2, 3}
    //                          x + 2, b = {1, 2}
    vector <LL> a({1, 2, 3}), b({1, 2});

    auto res = multiply(a, b);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
}
