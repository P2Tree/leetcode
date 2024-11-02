#include "Utils/graph.h"
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<int> path;
    vector<vector<int>> paths;
    dfs(graph, paths, path, 0);

    return paths;
  }
  void dfs(vector<vector<int>> &graph, vector<vector<int>> &paths,
           vector<int> path, int val) {
    if (val == graph.size() - 1) {
      path.push_back(val);
      paths.push_back(path);
      return;
    }
    path.push_back(val);
    for (auto &node : graph[val]) {
      dfs(graph, paths, path, node);
    }
  }
};

void test(vector<vector<int>> &graph) {
  Solution so;
  auto res = so.allPathsSourceTarget(graph);
  cout << "path num: " << res.size() << endl;
  for (auto &r : res) {
    for (auto &s : r) {
      cout << s << "->";
    }
    cout << endl;
  }
}

void testx(vector<vector<int>> &graph) {
  Graph G(graph);
  G.print();
  G.printPaths();
}

int main() {
  vector<vector<int>> graph1 = {{1, 2}, {3}, {3}, {}};
  testx(graph1);
  vector<vector<int>> graph2 = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
  testx(graph2);
  return 0;
}
