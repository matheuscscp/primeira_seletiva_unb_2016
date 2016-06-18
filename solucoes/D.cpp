#include <bits/stdc++.h>

#define MAXN  1000
#define MAXK  1000
#define MAXC  1000
#define MOD   1000000007

using namespace std;

typedef long long ll;

ll C(ll n, ll k) { // C(n,k) = n itens combinados k a k
  if (k == 0 || k == n) return 1;
  static ll dp[MAXK+5][MAXK+5] = {};
  ll& ans = dp[n][k];
  if (ans) return ans;
  return ans = (C(n-1,k-1)+C(n-1,k))%MOD;
}

ll c[MAXN+5];
ll f(ll n, ll k) { // f(n,k) = considerando itens de 1 a n e com k elementos
  if (k == 0) return 1;
  if (n == 0) return 0;
  static ll dp[MAXN+5][MAXK+5];
  static bool mark[MAXN+5][MAXK+5] = {};
  ll& ans = dp[n][k];
  if (mark[n][k]) return ans;
  mark[n][k] = true;
  int maxc = min(c[n],k);
  for (int i = 0; i <= maxc; i++) ans = (ans+(C(k,i)*f(n-1,k-i))%MOD)%MOD;
  return ans;
}

int main() {
  int N,K;
  scanf("%d %d",&N,&K);
  for (int n = 1, tmp; n <= N; n++) {
    scanf("%d",&tmp);
    c[n] = tmp;
  }
  printf("%d\n",int(f(N,K)));
  return 0;
}
