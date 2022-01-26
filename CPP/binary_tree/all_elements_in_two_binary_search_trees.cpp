// Source : https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Author : Jiahao Liang
// Date   : 01-26-2022

/*********************************************************************************** 

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:
Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

Constraints:
The number of nodes in each tree is in the range [0, 5000].
-105 <= Node.val <= 105

***********************************************************************************/ 


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        inOrderTraversal(root1, result);
        inOrderTraversal(root2, result);
        sort(result.begin(), result.end());
        return result;
    }
    void inOrderTraversal(TreeNode* root, vector<int>& result){
        if(root != nullptr)
        {
            inOrderTraversal(root->left, result);
            result.push_back(root->val);
            inOrderTraversal(root->right, result);
        }
    }
};
