#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;
typedef long long ll;
typedef long long int64;
typedef long long lint;
typedef long long lli;

#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 63, sizeof(x))
#define fill(x, y) memset(x, y, sizeof(x))
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define BEG_END(v) v.begin(), v.end()

using namespace std;

// int qp(int a,ll b){int
// ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int qp(int a, ll b, int mo) {
  int ans = 1;
  do {
    if (b & 1)
      ans = 1ll * ans * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return ans;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// int n, m, x, y;
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
// int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// string str;
// cin >> n >> m;
// vector<string> s(n);
// vector<vector<int>> bind(n, vector<int>(2));
// for (int i = 0; i < n; i++)
//   cin >> s[i];

struct P {
  int x;
  int y;
};

int main() {
  int N;
  cin >> N;

  vector<int> T(N);
  vector<P> X(N);
  rep(i, N) { cin >> T[i] >> X[i].x >> X[i].y; }

  P current = {0, 0};
  int passed = 0;

  rep(i, N) {
    int sum = X[i].x + X[i].y;
    P temp = {abs(current.x - X[i].x), abs(current.y - X[i].y)};
    int dist = temp.x + temp.y;
    if ((T[i] - passed) < dist || (abs(dist - (T[i] - passed)) % 2) == 1) {
      cout << "No" << endl;
      return 0;
    }
    current.x = X[i].x;
    current.y = X[i].y;
    passed = T[i];
  }
  cout << "Yes" << endl;

  return 0;
}