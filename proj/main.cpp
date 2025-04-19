#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

struct Cell {
    int x, y;
    Cell(int a, int b): x(a), y(b) {}
    bool operator==(const Cell& other) const {
        return x == other.x && y == other.y;
    }
};

class Maze {
private:
    int rows, cols;
    vector<vector<char>> grid;
    vector<vector<bool>> visited;

    bool isValid(int x, int y) {
        return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != '#' && !visited[x][y]);
    }

public:
    Maze(int r, int c): rows(r), cols(c) {
        grid.resize(rows, vector<char>(cols, '.'));
        visited.resize(rows, vector<bool>(cols, false));
    }

    void inputMaze() {
        cout << "Enter maze (use # for wall, . for path):\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> grid[i][j];
    }

    void printMaze(const vector<Cell>& path = {}) {
        vector<vector<char>> display = grid;
        for (const auto& cell : path) {
            if (display[cell.x][cell.y] == '.')
                display[cell.x][cell.y] = '*';
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << display[i][j] << ' ';
            cout << '\n';
        }
    }

    vector<Cell> getNeighbors(Cell cell) {
        vector<Cell> neighbors;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cell.x + dx[dir];
            int ny = cell.y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] != '#')
                neighbors.push_back(Cell(nx, ny));
        }
        return neighbors;
    }

    vector<Cell> bfs(Cell start, Cell end) {
        visited.assign(rows, vector<bool>(cols, false));
        queue<Cell> q;
        vector<vector<Cell>> parent(rows, vector<Cell>(cols, Cell(-1, -1)));

        q.push(start);
        visited[start.x][start.y] = true;

        while (!q.empty()) {
            Cell cur = q.front(); q.pop();
            if (cur == end) break;

            for (Cell next : getNeighbors(cur)) {
                if (!visited[next.x][next.y]) {
                    visited[next.x][next.y] = true;
                    parent[next.x][next.y] = cur;
                    q.push(next);
                }
            }
        }

        // Reconstruct path
        vector<Cell> path;
        if (!visited[end.x][end.y]) return path; // No path found

        for (Cell at = end; !(at == start); at = parent[at.x][at.y])
            path.push_back(at);
        path.push_back(start);
        reverse(path.begin(), path.end());
        return path;
    }

    vector<Cell> dfs(Cell start, Cell end) {
        visited.assign(rows, vector<bool>(cols, false));
        stack<Cell> s;
        vector<vector<Cell>> parent(rows, vector<Cell>(cols, Cell(-1, -1)));

        s.push(start);
        visited[start.x][start.y] = true;

        while (!s.empty()) {
            Cell cur = s.top(); s.pop();
            if (cur == end) break;

            for (Cell next : getNeighbors(cur)) {
                if (!visited[next.x][next.y]) {
                    visited[next.x][next.y] = true;
                    parent[next.x][next.y] = cur;
                    s.push(next);
                }
            }
        }

        // Reconstruct path
        vector<Cell> path;
        if (!visited[end.x][end.y]) return path; // No path found

        for (Cell at = end; !(at == start); at = parent[at.x][at.y])
            path.push_back(at);
        path.push_back(start);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    int rows, cols;
    cout << "Enter maze dimensions (rows cols): ";
    cin >> rows >> cols;

    Maze maze(rows, cols);
    maze.inputMaze();

    int sx, sy, ex, ey;
    cout << "Enter start cell (row col): ";
    cin >> sx >> sy;
    cout << "Enter end cell (row col): ";
    cin >> ex >> ey;

    Cell start(sx, sy), end(ex, ey);

    int choice;
    cout << "Choose algorithm: 1. BFS (shortest path)  2. DFS (any path)\n";
    cin >> choice;

    vector<Cell> path;
    if (choice == 1)
        path = maze.bfs(start, end);
    else
        path = maze.dfs(start, end);

    if (path.empty()) {
        cout << "No path found!\n";
    } else {
        cout << "Path found! Displaying maze with path (*):\n";
        maze.printMaze(path);
    }

    return 0;
}