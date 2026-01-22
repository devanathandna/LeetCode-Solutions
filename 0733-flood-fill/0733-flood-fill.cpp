class Solution {
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];
        if (oldColor == color) return image;  // nothing to do

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;   // mark visited by repainting

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    image[nx][ny] == oldColor) {

                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};
