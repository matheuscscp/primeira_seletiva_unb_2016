#include <bits/stdc++.h>

#define MAXN 100000

using namespace std;

int main() {
  int N, maxp = 0;
  scanf("%d",&N);
  static char mask[MAXN+5][10];
  for (int n = 0; n < N; n++) {
    scanf("%s",mask[n]);
    for (int i = 0; i <= 8; i += 2) if (mask[n][i] != '-') maxp += 2;
  }
  int pts = 0;
  for (int k = 0; k < 2; k++) {
    char buf[10];
    for (int n = 0; n < N; n++) {
      scanf("%s",buf);
      for (int i = 0; i <= 8; i += 2) {
        if (mask[n][i] != buf[i]) pts--;
        else if (mask[n][i] != '-') pts++;
      }
    }
  }
  printf("%d\n",pts);
  if (pts == maxp) printf("CONGRATULATIONS, YOU ARE FAGS!\n");
  else if (pts == -N*10) printf("GAME OVER, YOU SUCK!\n");
  return 0;
}
