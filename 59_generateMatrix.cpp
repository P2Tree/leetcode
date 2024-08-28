#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> ret(n, vector<int>(n, 0));
  if (n == 1) {
    ret[0][0] = 1;
    return ret;
  } else if (n == 2) {
    ret[0][0] = 1;
    ret[0][1] = 2;
    ret[1][1] = 3;
    ret[1][0] = 4;
    return ret;
  }

  int i = 0, j = 0, is = 1, js = 1;
  int ie = n - 1, je = n - 1;
  int x = 1;
  while (is <= ie && js <= je) {
    for (; j < je; j++) {
      ret[i][j] = x++;
    }
    for (; i < ie; i++) {
      ret[i][j] = x++;
    }
    for (; j >= js; j--) {
      ret[i][j] = x++;
    }
    for (; i >= is; i--) {
      ret[i][j] = x++;
    }
    i++; j++;
    is++; js++;
    ie--; je--;
  }
  if (n % 2 != 0) {
    ret[n / 2][n / 2] = x;
  }
  return ret;
}

int main() {
  int n = 3;

  auto ret = generateMatrix(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ret[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  return 0;
}
