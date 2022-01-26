// Source : https://leetcode.com/problems/reshape-the-matrix/
// Author : Jiahao Liang
// Date   : 01-19-2022

/*********************************************************************************** 

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
|1 2|
|3 4| = |1 2 3 4|
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

Example 2:
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
 

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
-1000 <= mat[i][j] <= 1000
1 <= r, c <= 300

***********************************************************************************/ 

//loop with nested loop through the original matrix, and keep track of the row and col in the new matrix.
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int validArea = mat.size() * mat[0].size();
        if(validArea != r * c)
        {
            return mat;
        }
        int row = 0, col = 0;
        std::vector<std::vector<int>> result(r, vector<int>(c));
        for(size_t i = 0; i < mat.size(); ++i)
        {
            for(size_t j = 0; j < mat[0].size(); ++j)
            {
                result[row][col] = mat[i][j];
                ++col;
                if(col == c)
                {
                    col = 0;
                    ++row;
                }
            }
        }
        return result;
    }
};

//Iterate each row column-by-column, 
//wrap around when you reach the end on one row and move to the next row. Here, 
//we are copying all elements of one row and then moving on to the next row.
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int validArea = mat.size() * mat[0].size();
        if(validArea != r * c)
        {
            return mat;
        }
        int row = 0, col = 0;
        std::vector<std::vector<int>> result(r, vector<int>(c));
        for(size_t i = 0; i < validArea; ++i)
        {
            result[i/c][i%c] = mat[i/mat[0].size()][i%mat[0].size()];
        }
        return result;
    }
};
