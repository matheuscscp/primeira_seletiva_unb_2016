#include <bits/stdc++.h>

#define MAXN 10000

using namespace std;

typedef long long ll;

int N;
struct Event { int type,Q,J; } event[MAXN+5];

bool simulate(ll energy) {
  ll cost = event[0].J;
  ll last = 0, curr, delta;
  for (int n = 1; n < N; n++) {
    switch (event[n].type) {
      case 1:
        curr = event[n].Q-1;
        delta = curr-last;
        energy -= delta*cost;
        if (energy <= 0) return false;
        cost = event[n].J;
        last = curr;
        break;
      case 2:
        curr = event[n].Q;
        delta = curr-last;
        energy -= delta*cost;
        if (energy <  0) return false;
        energy += event[n].J;
        if (energy == 0) return false;
        last = curr;
        break;
      case 3:
        curr = event[n].Q;
        delta = curr-last;
        energy -= delta*cost;
        if (energy <  0) return false;
    }
  }
  return true;
}

// busca binaria na energia minima
ll f(ll beg, ll end) {
  if (beg == end) return beg;
  ll mid = (beg+end)>>1;
  bool wins = simulate(mid);
  if (wins) return f(beg,mid);
  return f(mid+1,end);
}

int main() {
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> event[n].type >> event[n].Q;
    if (event[n].type < 3) cin >> event[n].J;
  }
  cout << f(1,10000000000L) << endl;
  return 0;
}
