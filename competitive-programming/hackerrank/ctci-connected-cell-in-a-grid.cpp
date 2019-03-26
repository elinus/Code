#include <bits/stdc++.h>

using namespace std;

int movex[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int movey[8] = {1, 0, -1, -1, -1, 0, 1, 1};

bool check(int x, int y, int n, int m, vector<vector<int>> &grid) {
    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
        return true;
    return false;
}

int findLargest(vector<vector<int>> &grid, int x, int y, int n, int m) {
    if (check(x, y, n, m, grid)) {
        int count = grid[x][y]--;
        for (int k = 0; k < 8; ++k) {
            count += findLargest(grid, x + movex[k], y + movey[k], n, m);
        }
        return count;
    }
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();

    int max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == 1) {
                int size = findLargest(grid, i, j, n, m);
                if (size > max) {
                    max = size;
                }
            }
        }
    }
    return max;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);
    cout << res << "\n";
    //fout << res << "\n";

    //fout.close();

    return 0;
}
