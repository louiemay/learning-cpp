#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int partition(vector<int>& nums, int start, int end)
{
	int pivot = nums[end];
	int i = start;
	for (int j = i; j < end; ++j) {
		if (nums[j] < pivot) {
			swap(nums[j], nums[i]);
			i++;
		}
	}
	swap(nums[i], nums[end]);
	return i;
}

int findKthLargest(vector<int>& nums, int k)
{
	int left = 0, right = nums.size() - 1;
	int target = nums.size() - k;

	while (true) {
		int pivot = partition(nums, left, right);
		if (pivot == target) {
			return nums[pivot];
		}
		else if (pivot < target) {
			left = pivot + 1;
		}
		else if (pivot > target) {
			right = pivot - 1;
		}
	}
}

int main()
{
	vector<int> nums{ 1,7,9,4,6,8,3,5,2 };
	int kth = 6;
	cout << kth << " largest: " << findKthLargest(nums, kth) << "\n";

	for (const auto& i : nums)
		cout << i << " ";

	return 0;
}





