#include <bits/stdc++.h>

#define MAXN 3000

using namespace std;

typedef long long ll;

int C, t;
struct Demon {
  int i,T,v,D,icpc;
  void init() {
    icpc = i+T/v;
  }
  bool operator<(const Demon& other) const {
    return other.dmg(t+C,t+2*C) < dmg(t+C,t+2*C);
  }
  ll dmg(int ta, int tb) const { // integral de ta ate tb de di(t) dt
    return dmg(tb)-dmg(ta);
  }
  ll dmg(int end) const { // integral de 0 ate end de di(t) dt
    if (end <= i) return 0;
    ll ans = F(min(end,icpc))-F(i);
    if (end > icpc) ans += D*(T*ll(end-icpc));
    return ans;
  }
  ll F(int x) const { // integral de Dv(t-i) dt (int x representa t)
    ll X = x;
    return (D>>1)*(v*(X*X)) - D*(v*(i*X));
  }
};

// fila de prioridade
Demon demon[MAXN+5];
int demons = 0;
bool empty() {
  return !demons;
}
void push(const Demon& d) {
  demon[demons++] = d;
}
Demon pop() {
  int ans = 0;
  for (int i = 1; i < demons; i++) if (demon[i] < demon[ans]) ans = i;
  swap(demon[ans],demon[--demons]);
  return demon[demons];
}

int main() {
  int N;
  cin >> N >> C;
  ll ans = 0;
  int end;
  Demon d;
  for (t = 0, end = 0; t < N; t++) {
    d.i = t;
    cin >> d.T >> d.v >> d.D;
    d.init();
    push(d);
    if (end <= t) {
      d = pop();
      end = t+C;
      ans += d.dmg(end);
    }
  }
  while (!empty()) {
    t = end;
    d = pop();
    end += C;
    ans += d.dmg(end);
  }
  cout << ans << endl;
  return 0;
}
