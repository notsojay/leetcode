// Source : https://leetcode.com/problems/detect-capital/
// Author : Jiahao Liang
// Date   : 01-23-2022

/*********************************************************************************** 

We define the usage of capitals in a word to be right when one of the following cases holds:
All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true

Example 2:
Input: word = "FlaG"
Output: false

***********************************************************************************/ 

class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag = 0, FLAG = 0;
        for(int i = 1; i < word.size(); i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
                FLAG = 1;
            if(word[i] >= 'a' && word[i] <= 'z')
                flag = 1;
        }
        if(flag && FLAG)
        {
            return 0;
        }
        if(FLAG && word[0] >= 'a' && word[0] <= 'z')
        {
            return 0;
        }
        return 1;
    }
};
