#include <bits/stdc++.h>

#define MAXN 400

using namespace std;

int N;
double x[MAXN+5], y[MAXN+5], d[MAXN+5][MAXN+5], dp[MAXN+5][MAXN+5];

// f(i,j) = resposta do poligono feito pelo lado ij e vertices entre i e j
double f(int i, int j) {
  double& ans = dp[i][j];
  if (ans >= 0) return ans;
  if (j <= i+2) return ans = 0; // no maximo triangulo
  ans = min(d[i+1][j]+f(i+1,j),d[i][j-1]+f(i,j-1));
  for (int k = i+2; k <= j-2; k++) ans = min(ans,d[i][k]+f(i,k)+d[k][j]+f(k,j));
  return ans;
}

int main() {
  scanf("%d",&N);
  for (int i = 0; i < N; i++) {
    scanf("%lf %lf",&x[i],&y[i]);
    for (int j = 0; j < i; j++) {
      double dx = x[i]-x[j], dy = y[i]-y[j];
      d[i][j] = sqrt(dx*dx+dy*dy);
      d[j][i] = d[i][j];
      dp[i][j] = -1;
      dp[j][i] = -1;
    }
    d[i][i] = 0;
    dp[i][i] = -1;
  }
  printf("%.4lf\n",f(0,N-1));
  return 0;
}
