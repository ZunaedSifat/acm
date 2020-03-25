#include <bits/stdc++.h>
#define int long long
using namespace std;

#define x first
#define y second
#define one 1LL
#define all(x) begin(x), end(x)

#define endl "\n"
#define debug(x) cerr << #x << ": " << x << endl;

const int maxn = 200010;
const int mod = 1000000007;
const int inf = one<<60;

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;

	ch = getchar();
    while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	
    if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}

	if (minus) return -result;
	else return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}