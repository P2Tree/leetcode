#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    queue<pair<int, int>> que;
    int max_area = 0;
    const int max_col = grid.size();
    const int max_row = grid[0].size();

    vector<vector<bool>> visited(grid.size(),
                                 vector<bool>(grid[0].size(), false));

    for (auto i = 0; i < max_col; i++) {
      for (auto j = 0; j < max_row; j++) {
        if (visited[i][j] == true)
          continue;
        int area = 0;
        visited[i][j] = true;
        if (grid[i][j] == 1) {
          que.push(make_pair(i, j));
        } else {
          continue;
        }
        while (!que.empty()) {
          auto [x, y] = que.front();
          if (x - 1 >= 0 && grid[x - 1][y] == 1 && visited[x - 1][y] == false) {
            visited[x - 1][y] = true;
            que.push(make_pair(x - 1, y));
          }
          if (x + 1 < max_col && grid[x + 1][y] == 1 &&
              visited[x + 1][y] == false) {
            visited[x + 1][y] = true;
            que.push(make_pair(x + 1, y));
          }
          if (y - 1 >= 0 && grid[x][y - 1] == 1 && visited[x][y - 1] == false) {
            visited[x][y - 1] = true;
            que.push(make_pair(x, y - 1));
          }
          if (y + 1 < max_row && grid[x][y + 1] == 1 &&
              visited[x][y + 1] == false) {
            visited[x][y + 1] = true;
            que.push(make_pair(x, y + 1));
          }
          que.pop();
          if (grid[x][y] == 1) {
            // cout << "points: " << x << ", " << y << endl;
            area++;
          }
        }
        if (area != 0) {
          if (area > max_area)
            max_area = area;
          // cout << "area: " << area << endl;
        }
      }
    }

    // for (auto i = 0; i < max_col; i++) {
    //   for (auto j = 0; j < max_row; j++) {
    //     cout << visited[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    return max_area;
  }
};

void test(vector<vector<int>> &grid, const int golden) {
  Solution so;
  cout << "map is: " << endl;
  for (int m = 0; m < grid.size(); ++m) {
    for (int n = 0; n < grid[0].size(); ++n) {
      cout << grid[m][n] << " ";
    }
    cout << endl;
  }
  cout << endl;
  auto res = so.maxAreaOfIsland(grid);

  cout << "the max area of islands is: " << res << endl;
  assert(res == golden);
}

int main() {
  vector<vector<int>> grid1 = {
      {1, 1, 1, 1, 0}, {1, 1, 0, 1, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 0, 0}};
  test(grid1, 9);

  vector<vector<int>> grid2 = {
      {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}};
  test(grid2, 4);

  vector<vector<int>> grid3 = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                               {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                               {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  test(grid3, 6);

  vector<vector<int>> grid4 = {{0, 1}, {1, 0}};
  test(grid4, 1);
}
