#include <bits/stdc++.h>

using namespace std;

int main() {
  char buf[25];
  scanf("%s",buf);
  int len = strlen(buf);
  int n = len>>1;
  for (int i = 0; i < n; i++) if (buf[i] != buf[len-1-i]) {
    printf("NAO\n");
    return 0;
  }
  printf("SIM\n");
  return 0;
}
