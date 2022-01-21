// Source : https://leetcode.com/problems/pascals-triangle/
// Author : Jiahao Liang
// Date   : 01-21-2022

/*********************************************************************************** 

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30

***********************************************************************************/ 

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;
        for(size_t i = 0; i < numRows; ++i)
        {
            std::vector<int> row(i+1, 1);
            for(size_t j = 1; j < i; ++j)
            {
                row[j] = result[i-1][j-1] + result[i-1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
