#include <bits/stdc++.h>

#define MAXN 1000000

using namespace std;

typedef long long ll;
enum { WHITE, GRAY, BLACK };

struct Edge {
  int g,id;
  Edge(int g, int id) : g(g), id(id) {}
};

vector<vector<Edge>> G, GT;
vector<char> color;
stack<int> S;
vector<int> scc;
int SCC = 0;

// DFS's do kosaraju
void dfs1(int u) {
  color[u] = GRAY;
  for (auto& v : G [u]) if (color[v.id] == WHITE) dfs1(v.id);
  color[u] = BLACK;
  S.push(u);
}
void dfs2(int u) {
  scc[u] = SCC;
  color[u] = GRAY;
  for (auto& v : GT[u]) if (color[v.id] == WHITE) dfs2(v.id);
  color[u] = BLACK;
}

// f(u) = lucro maximo saindo do vertice u
ll f(int u) {
  static ll dp[MAXN+5];
  static bool mark[MAXN+5] = {};
  ll& ans = dp[u];
  if (mark[u]) return ans;
  mark[u] = true;
  ans = 0;
  for (auto& v : G[u]) {
    int g = (scc[v.id] != scc[u] ? v.g : 0);
    ans = max(ans,g+f(v.id));
  }
  return ans;
}

int main() {
  int N,M,F;
  cin >> N >> M >> F;
  G  = vector<vector<Edge>>(N+1); // grafo original
  GT = vector<vector<Edge>>(N+1); // grafo transposto
  for (int m = 0; m < M; m++) {
    int g,A,B;
    cin >> g >> A >> B;
    G [A].emplace_back(g,B);
    GT[B].emplace_back(g,A);
  }
  // kosaraju
  color = vector<char>(N+1,WHITE);
  dfs1(F);
  color = vector<char>(N+1,WHITE);
  scc = vector<int>(N+1,0);
  while (!S.empty()) {
    int u = S.top(); S.pop();
    if (color[u] == WHITE) {
      SCC++;
      dfs2(u);
    }
  }
  cout << f(F) << endl;
  return 0;
}
