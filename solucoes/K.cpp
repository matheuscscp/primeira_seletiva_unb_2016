#include <bits/stdc++.h>

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
  int a,b,g,p;
  scanf("%d %d %d %d",&a,&b,&g,&p);
  // baby step giant step
  ll m = ll(sqrt(p)); while (m*m < p) m++;
  map<int, int> table;
  ll bstep = g;
  for (int i = 0; i < m; i++) {
    if (a == b) {
      printf("%d\n",i);
      return 0;
    }
    table[a] = i;
    a = (a*bstep)%p;
  }
  ll gstep = modpow(modpow(g,p-2,p),m,p);
  for (int i = 0; i < m; i++) {
    auto j = table.find(b);
    if (j != table.end()) {
      printf("%d\n",int(i*m + j->second));
      return 0;
    }
    b = (b*gstep)%p;
  }
  printf("-1\n");
  return 0;
}
