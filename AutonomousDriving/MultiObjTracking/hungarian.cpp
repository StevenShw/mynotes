#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<vector<int>> graph;  // 二分图的邻接矩阵
vector<int> match;          // 匹配结果

bool dfs(int u, vector<bool>& visited) {
  for (int v = 0; v < graph[u].size(); v++) {
    if (graph[u][v] &&
        !visited
            [v]) {  // visited的作用是：
                    // 当前左节点u遍历到当前右节点v，之前已经访问过的左节点必然已经有被连接了，当需要让别的左节点去找新的右节点时就不必再去进行重复计算了
      visited[v] = true;
      if (match[v] == -1 ||
          dfs(match[v],
              visited)) {  // 如果发现自己想匹配的已经被匹配过了，那么就让之前匹配的左边的节点取找新的，如果能找到就会让出来，不然当前节点就尝试去看一下一个右边节点
        match[v] = u;
        std::cout << "-- match[" << v << "] = " << u << std::endl;
        return true;
      }
    }
  }
  return false;
}

int hungarian_algorithm() {
  int n = graph.size();
  int m = graph[0].size();
  match.assign(m, -1);

  int cnt = 0;
  for (int u = 0; u < n; u++) {
    vector<bool> visited(m, false);
    if (dfs(u, visited)) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n, m;
  //   cin >> n >> m;
  n = 4;
  m = 2;
  graph.assign(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      graph[i][j] = i * 100 + j * 10 + 1;
    }
  }

  for (int i = 0; i < graph.size(); i++) {
    std::cout << std::endl;
    for (int j = 0; j < graph[0].size(); j++) std::cout << graph[i][j] << " ";
  }
  std::cout << std::endl;

  int max_matching = hungarian_algorithm();
  cout << "Maximum matching: " << max_matching << endl;
  for (int i = 0; i < match.size(); i++) {
    if (match[i] != -1) {
      cout << match[i] << " -> " << i << endl;
    }
  }
  return 0;
}