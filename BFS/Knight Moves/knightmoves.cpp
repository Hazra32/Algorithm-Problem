#include <bits/stdc++.h>
using namespace std;

// Structure to represent a position on the chessboard
struct Position {
    int x, y, moves;
};

// Check if a position is within the board
bool isValid(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Convert algebraic notation to 0-based coordinates
pair<int,int> convertToCoordinates(string square) {
    int x = square[0] - 'a'; // column a-h -> 0-7
    int y = square[1] - '1'; // row 1-8 -> 0-7
    return {x, y};
}

// BFS function to find minimum knight moves
int knightMoves(string start, string end) {
    pair<int,int> s = convertToCoordinates(start);
    pair<int,int> e = convertToCoordinates(end);

    // Special case: start = end
    if (s == e) return 0;

    int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

    bool visited[8][8] = {false};
    queue<Position> q;

    q.push({s.first, s.second, 0});
    visited[s.first][s.second] = true;

    while (!q.empty()) {
        Position curr = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isValid(nx, ny) && !visited[nx][ny]) {
                if (nx == e.first && ny == e.second)
                    return curr.moves + 1;

                visited[nx][ny] = true;
                q.push({nx, ny, curr.moves + 1});
            }
        }
    }

    return -1; // should never happen on an 8x8 board
}

int main() {
    string start, end;
    while (cin >> start >> end) {
        int moves = knightMoves(start, end);
        cout << "To get from " << start << " to " << end
             << " takes " << moves << " knight moves." << endl;
    }
    return 0;
}

