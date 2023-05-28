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

int div_cnt(const int n) {
  int cnt = 0;
  int temp = n;
  int div = 0;
  while (1) {
    div = temp % 2;
    if (div != 0 || temp == 0) {
      return cnt;
    }
    temp = temp / 2;
    cnt++;
  }

  return cnt;
}

int main() {
  int A, B, C, X;
  int n;

  cin >> A >> B >> C >> X;

  int cnt = 0;

  for (int a = 0; a <= A; a++) {
    for (int b = 0; b <= B; b++) {
      for (int c = 0; c <= C; c++) {
        int val = 500 * a + 100 * b + 50 * c;
        if (val == X) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;

  return 0;
}