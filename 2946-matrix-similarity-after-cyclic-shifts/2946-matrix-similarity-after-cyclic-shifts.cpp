class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = mat[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2==0){
                    int index = (j - k % m + m) % m;
                    arr[i][index] = mat[i][j];
                }
                else{
                    int index = (j + k) % m;
                    arr[i][index] = mat[i][j];
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(arr[i][j] != mat[i][j] ) return false;
            }

        }
        return true;
    }
};