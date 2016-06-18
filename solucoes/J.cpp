#include <bits/stdc++.h>

#define MAXN 10000
#define ok(estado,indice) (((estado)>>(indice))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct Path {
  int u,ug,s,w;
  Path(int u, int ug, int s, int w) : u(u), ug(ug), s(s), w(w) {}
  bool operator<(const Path& other) const { return w > other.w; }
};

int main() {
  int N,M,K;
  cin >> N >> M >> K;
  int S,Gema,T,P[21]; memset(P,-1,sizeof P);
  cin >> S >> Gema >> T;
  for (int k = 0, tmp; k < K; k++) {
    cin >> tmp;
    P[tmp] = k;
  }
  vector<vector<ii>> G(N+1);
  for (int m = 0; m < M; m++) {
    int A,B,Mp;
    cin >> A >> B >> Mp;
    G[A].emplace_back(B,Mp);
    G[B].emplace_back(A,Mp);
  }
  // dijkstra
  vector<vector<vector<int>>> dist(N+1,vector<vector<int>>(N+1,vector<int>(1<<K,1000000000)));
  dist[S][Gema][0] = 0;
  priority_queue<Path> Q;
  Q.emplace(S,Gema,0,0);
  auto relax = [&](const Path& alt) {
    if (alt.w < dist[alt.u][alt.ug][alt.s]) {
      dist[alt.u][alt.ug][alt.s] = alt.w;
      Q.push(alt);
    }
  };
  while (!Q.empty()) {
    Path path = Q.top(); Q.pop();
    if (dist[path.u][path.ug][path.s] < path.w) continue;
    if (path.u == T && path.ug == T) { cout << path.w << endl; return 0; }
    for (auto& e : G[path.u]) {
      int alt = path.w+e.second;
      if (P[e.first] >= 0) {
        if (path.u == path.ug) {
          if (!ok(path.s,P[e.first])) { // vou deixar pra tras e liberar
            relax(Path(e.first,path.u,path.s|(1<<P[e.first]),alt));
          }
          else { // vou andar com o negocio normal
            relax(Path(e.first,e.first,path.s,alt));
          }
        }
        else { // vou andar e settar o bit
          relax(Path(e.first,path.ug,path.s|(1<<P[e.first]),alt));
        }
      }
      else if (path.u == path.ug) { // vou andar com o negocio normal
        relax(Path(e.first,e.first,path.s,alt));
      }
      else { // vou soh andar
        relax(Path(e.first,path.ug,path.s,alt));
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
