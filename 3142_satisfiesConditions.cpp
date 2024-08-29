#include <iostream>
#include <vector>

using namespace std;

bool satisfiesConditions(vector<vector<int>> &grid) {
  auto m = grid.size();
  auto n = grid[0].size();
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < m - 1; ++j) {
      if (grid[j][i] != grid[j + 1][i])
        return false;
    }
    if (i != n - 1) {
      if (grid[0][i] == grid[0][i + 1])
        return false;
    }
  }
  return true;
}

int main() {
  vector<vector<int>> grid1 = {{1, 0, 2}, {1, 0, 2}};
  cout << (satisfiesConditions(grid1) == true ? "ok" : "not") << endl;

  vector<vector<int>> grid2 = {{1, 0, 2}, {1, 0, 3}};
  cout << (satisfiesConditions(grid2) == true ? "ok" : "not") << endl;

  vector<vector<int>> grid3 = {{1, 1, 2}, {1, 1, 2}};
  cout << (satisfiesConditions(grid3) == true ? "ok" : "not") << endl;

  vector<vector<int>> grid4 = {{1}, {1}};
  cout << (satisfiesConditions(grid4) == true ? "ok" : "not") << endl;

  vector<vector<int>> grid5 = {{1, 2, 3}};
  cout << (satisfiesConditions(grid5) == true ? "ok" : "not") << endl;

  vector<vector<int>> grid6 = {{1, 2, 2}};
  cout << (satisfiesConditions(grid6) == true ? "ok" : "not") << endl;

  return 0;
}
