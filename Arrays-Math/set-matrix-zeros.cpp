class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Brute Force
        //Time complexity-O(n*m)*O(n+m)
        //Space complexity-O(m*n)
        //My solution

        // int m=matrix.size();
        // int n=matrix[0].size();
        // vector<vector<int>>resMatrix(matrix);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==0){
        //             for(int k=0;k<n;k++){
        //                 resMatrix[i][k]=0;
        //             }
        //             for(int k=0;k<m;k++){
        //                 resMatrix[k][j]=0;
        //             }
        //         }
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         matrix[i][j]=resMatrix[i][j];
        //     }
        // }

        //Brute-Force in terms of time
        //It depends upon the range

        //Time complexity-O(n*m)*O(n+m)
        //Space complexity-O(1)


        // int m=matrix.size();
        // int n=matrix[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==0){
        //             //row traversal
        //             for(int k=0;k<n;k++){
        //                 if(k!=j && matrix[i][k]!=0){
        //                     matrix[i][k]=INT_MIN;
        //                 }
        //             }
        //             //col traversal
        //             for(int k=0;k<m;k++){
        //                 if(k!=i && matrix[k][j]!=0){
        //                     matrix[k][j]=INT_MIN;
        //                 }
        //             }
        //         }
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==INT_MIN){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

        //Optimised approach
        //Time complexity-O(2*m*n)
        //Space complexity-O(1)


         int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0) matrix[i][0] = 0;
    }
    }
};
