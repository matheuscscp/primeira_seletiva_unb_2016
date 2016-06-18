#include <bits/stdc++.h>

using namespace std;

int main() {
  int N,d=0,t=0;
  cin >> N;
  string tmp;
  while (N--) {
    cin >> tmp;
    if (tmp == "douche")  d++;
    else                  t++;
  }
  cout << "Douche: " << d << endl;
  cout << "Turd: " << t << endl;
  if (d < t)      cout << "Turd Sandwich eh o novo mascote!\n";
  else if (t < d) cout << "Giant Douche venceu!\n";
  else            cout << "Um novo turno sera necessario.\n";
  return 0;
}
