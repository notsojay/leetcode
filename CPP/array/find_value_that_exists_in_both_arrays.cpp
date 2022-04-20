/*
Given two sets A and B represented as sorted sequences, 
describe an efficient algorithm for computing A⊕B, 
which is the set of elements that are in A or B, but not in both.
*/

#include <iostream>
#include <vector>

class Solution 
{
public:
	template<typename T>
	std::vector<T> getResult(std::vector<T> nums1, std::vector<T> nums2)
	{
		std::vector<T> result;
		auto i = nums1.begin(), j = nums2.begin();
		std::sort(nums1.begin(), nums1.end());
		std::sort(nums2.begin(), nums2.end());
		while(i != nums1.end() && j != nums2.end())
		{
			if(*i == *j)
			{
				T temp = *i;
				while(i != nums1.end() && *i == temp) ++i;
				while(j != nums2.end() && *j == temp) ++j;
			}
			else if(*i > *j)
			{
				result.push_back(*(j++));
			}
			else if(*i < *j)
			{
				result.push_back(*(i++));
			}
		}
		while(i != nums1.end())
			result.push_back(*(i++));
		while(j != nums2.end())
			result.push_back(*(j++));
		return result;
	}
};

int main(int argc, char *argv[]) 
{
	Solution test;
	std::vector<int> vec1 = {1, 3, 4, 6};
	std::vector<int> vec2 = {4, 1, 5, 7};
	std::vector<int> vec3 = test.getResult(vec1, vec2);
	for(auto &i : vec3)
		std::cout << i << " ";
	return 0;
}
