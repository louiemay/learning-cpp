#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
	vector<int>::iterator slow = nums.begin(), fast = slow;
	while (++fast != nums.end()) {
		if (*slow != *fast) {
			slow++;
			swap(*slow, *fast);
		}
	}
	return slow - nums.begin() + 1;
}

int main()
{
	vector<int> nums1{ 1,1,2,2,3,3,4,4,4 };
	vector<int> nums2{ 1,2,3,4,5 };

	cout << removeDuplicates(nums1) << "\n";
	for (const auto& i : nums1)
		cout << i << " ";
	cout << "\n";

	cout << removeDuplicates(nums2) << "\n";
	for (const auto& i : nums2)
		cout << i << " ";
	cout << "\n";


	return 0;
}


