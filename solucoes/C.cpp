#include <bits/stdc++.h>

#define MAXM 100
#define MAXN 100

using namespace std;

typedef long long ll;

ll modpow(ll x, ll n, ll p) {
  ll ans = 1;
  while (n) {
    if (n&1) ans = (ans*x)%p;
    n >>= 1;
    x = (x*x)%p;
  }
  return ans;
}

int main() {
  int p,M,N;
  scanf("%d %d %d",&p,&M,&N);
  static int A[MAXM+5][MAXN+5];
  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
      scanf("%d",&A[m][n]);
    }
  }
  // eliminacao gaussiana
  int dim = 0;
  for (int m = 0, n = 0; n < N; n++) {
    int i;
    for (i = m; i < M && A[i][n] == 0; i++);
    if (i == M) continue;
    dim++;
    if (i != m) swap(A[i],A[m]);
    ll inv = modpow(A[m][n],p-2,p);
    for (int j = n; j < N; j++) A[m][j] = (A[m][j]*inv)%p;
    for (i = m+1; i < M; i++) {
      ll mul = (p-A[i][n])%p;
      for (int j = n; j < N; j++) A[i][j] = (A[i][j]+(A[m][j]*mul)%p)%p;
    }
    m++;
  }
  printf("%d\n",M-dim);
  return 0;
}
