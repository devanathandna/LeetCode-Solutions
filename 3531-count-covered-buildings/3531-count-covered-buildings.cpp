class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,set<int>>rows,cols;
        for(auto it:buildings){
            int x = it[0] , y = it[1];
            rows[x].insert(it[1]);
            cols[y].insert(it[0]);
        }
        int count=0;
        for(auto it:buildings){
            int x = it[0] ,y = it[1];
            bool up = false , down = up,left = down,right = left;
            auto idx = rows[x].lower_bound(y);
            if(idx!=rows[x].begin()) down = true;
            idx = rows[x].upper_bound(y);
            if(idx!=rows[x].end()) up = true;

            auto idy = cols[y].lower_bound(x);
            if(idy!=cols[y].begin()) left = true;
            idy = cols[y].upper_bound(x);
            if(idy!=cols[y].end()) right = true;

            if(left && right && up && down){
                count++;
            }
        }
        return count;
    }
};