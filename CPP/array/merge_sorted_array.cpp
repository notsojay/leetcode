// Source : https://leetcode.com/problems/merge-sorted-array/
// Author : Jiahao Liang
// Date   : 01-18-2022

/*********************************************************************************** 

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

***********************************************************************************/

/*
题目要求把两个数组合并成一个，而且给出了两个数组非空元素的数目：m，n。首先想这样一个问题，两个数组合并后的非空元素个数一定是m+n。
也就是说，如果输出的结果数组（题中的意思就是A了）是这种形式：[*,*,*,*, empty, empty...empty]的话（*表示非空元素），
那么最后一个非空元素的下标为m+n-1（下标从0开始）。
那就可以考虑分别设两个指针从后往前扫描A，B数组，并且从A[m+n-1]这个位置开始，再设置一个指针，从后往前给A的元素重新赋值。
扫描的规则是从后往前扫描，所以按照“谁大谁先赋值”的规则，举题目的例子如下：

A = [1, 2, 3, empty, empty] 
B = [4,5]
m = 3
n = 2
m + n - 1 = 4
所以，从A[4]这个位置，向前开始赋值：
（1）先比较A[2] = 3和B[1] = 5，因为B[1] > A[2]，所以令A[4] = B[1] = 5
（2）比较B[0]和A[2]，大者赋值给A[3]
（3）按照这个规则持续扫描，直到其中一个扫描完为止

可见，之所以采取从后往前，而不是从前往后，是为了避免大量元素移位造成的运算量。
但是，接下来，如果其中一个扫描完了怎么办？
如果是A先扫描完，可以想象，情况是这样：
假如 A = [4, 5, empty, empty, empty]，B = [1, 2, 6]，A一定先扫描完，此时A = [4, 5, 4, 5, 6]，B = [1, 2, 6]，那么须要将B的剩余部分[1, 2]分别赋值给A的还没赋值的部分；
如果是B先扫描完了，那情况就简单了，我们不需任何操作（因为A前面没有扫描的部分也是排好序的）。
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n -1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                --i;
            }
            else
            {
                nums1[k] = nums2[j];
                --j;
            }
            --k;
        }
        while(i >= 0)
        {
            nums1[k--] = nums1[i--];
        }
        while(j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
