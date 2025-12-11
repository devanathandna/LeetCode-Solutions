class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> rows, cols;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            rows[x].insert(y);
            cols[y].insert(x);
        }

        int count = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            bool left = false, right = false;
            auto it = rows[x].lower_bound(y);
            if (it != rows[x].begin()) left = true;
            ++it;
            if (it != rows[x].end()) right = true;

    
            bool down = false, up = false;
            auto it2 = cols[y].lower_bound(x);
            if (it2 != cols[y].begin()) down = true;
            ++it2;
            if (it2 != cols[y].end()) up = true;

            if (left && right && up && down) {
                count++;
            }
        }

        return count;
    }
};