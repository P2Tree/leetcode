#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  template <typename T> void printGrid(vector<vector<T>> &grid) {
    for (auto m = 0; m < grid.size(); m++) {
      for (auto n = 0; n < grid[0].size(); n++) {
        cout << grid[m][n] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  pair<int, int> findAUnvisitedPoint(vector<vector<bool>> &visited,
                                     vector<vector<char>> &grid) {
    for (auto m = 0; m < visited.size(); m++) {
      for (auto n = 0; n < visited[0].size(); n++) {
        if (visited[m][n] == false) {
          if (grid[m][n] == '0') {
            visited[m][n] = true;
            continue;
          } else {
            return make_pair(m, n);
          }
        }
      }
    }
    return make_pair(-1, -1);
  }

  int numIslands(vector<vector<char>> &grid) {
    queue<tuple<char, int, int>> round;
    int count = 0;
    const int num_x = grid.size();    // col
    const int num_y = grid[0].size(); // row
    vector<vector<bool>> visited;
    visited.assign(grid.size(), vector<bool>(grid[0].size(), false));

    while (true) {
      auto [x, y] = findAUnvisitedPoint(visited, grid);
      if (x == -1 && y == -1)
        break;
      round.push(make_tuple(grid[x][y], x, y));
      visited[x][y] = true;
      while (!round.empty()) {
        auto point = round.front();
        auto [val, x, y] = point;
        if (x - 1 >= 0 && grid[x - 1][y] == '1' && visited[x - 1][y] == false) {
          round.push(make_tuple(grid[x - 1][y], x - 1, y));
          visited[x - 1][y] = true;
        }
        if (x + 1 < num_x && grid[x + 1][y] == '1' &&
            visited[x + 1][y] == false) {
          round.push(make_tuple(grid[x + 1][y], x + 1, y));
          visited[x + 1][y] = true;
        }
        if (y - 1 >= 0 && grid[x][y - 1] == '1' && visited[x][y - 1] == false) {
          round.push(make_tuple(grid[x][y - 1], x, y - 1));
          visited[x][y - 1] = true;
        }
        if (y + 1 < num_y && grid[x][y + 1] == '1' &&
            visited[x][y + 1] == false) {
          round.push(make_tuple(grid[x][y + 1], x, y + 1));
          visited[x][y + 1] = true;
        }
        round.pop();
      }
      // printGrid(visited);
      count++;
    }

    return count;
  }
};

void test(vector<vector<char>> &grid, const int golden) {
  Solution so;
  cout << "map is: " << endl;
  for (int m = 0; m < grid.size(); ++m) {
    for (int n = 0; n < grid[0].size(); ++n) {
      cout << grid[m][n] << " ";
    }
    cout << endl;
  }
  cout << endl;
  auto res = so.numIslands(grid);

  cout << "the number of islands is: " << res << endl;
  assert(res == golden);
}

int main() {
  vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
  test(grid1, 1);

  vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};
  test(grid2, 3);
}
