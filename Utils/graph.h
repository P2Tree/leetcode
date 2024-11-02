#include <iostream>
#include <vector>
class Graph {
public:
  Graph(std::vector<std::vector<int>> &data) {
    graph.resize(data.size());
    graph = data;
    node_num = data.size();
  };
  Graph() = delete;

  void print() const {
    for (int i = 0; i < node_num; ++i) {
      std::cout << i << ": ";
      for (auto &node : graph[i]) {
        std::cout << node << ", ";
      }
      std::cout << std::endl;
    }
  }

  void printPaths(const int start = 0, const int end = -1) {
    std::vector<int> path;
    std::vector<std::vector<int>> paths;
    int endx = end == -1 ? graph.size() - 1 : end;
    dfsForPrintPaths(paths, path, start, endx);

    std::cout << "path num: " << paths.size() << std::endl;
    for (auto &p : paths) {
      for (auto &n : p) {
        std::cout << n << "->";
      }
      std::cout << std::endl;
    }
  }
  void dfsForPrintPaths(std::vector<std::vector<int>> &paths,
                        std::vector<int> path, const int val, const int end) {
    if (val == end) {
      path.push_back(val);
      paths.push_back(path);
      return;
    }
    path.push_back(val);
    for (auto &node : graph[val]) {
      dfsForPrintPaths(paths, path, node, end);
    }
  }

private:
  std::vector<std::vector<int>> graph;
  size_t node_num;
};
