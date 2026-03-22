class Solution {
public:
    bool possibleRotate(vector<vector<int>>&mat,vector<vector<int>>&target){
 
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=target[i][j]){
                    return false;
                }
            }
        }

        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();
        bool possible = false;
        for(int a=0;a<4;a++){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n/2;j++){
                    swap(mat[i][j],mat[i][n-j-1]);
                }
            }
            cout << "-----------------" << endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }

            if(possibleRotate(mat,target)){
                possible = true;
            }
        }

        return possible;
        
    }
};