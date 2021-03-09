#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& num, int start, int end)
{
	int p = num[end];
	int i = start;
	for (int j = i; j < end; ++j) {
		if (num[j] < p) {
			swap(num[i], num[j]);
			i++;
		}
	}
	swap(num[end], num[i]);
	return i;
}

void quicksort(vector<int>& num, int start, int end)
{
	if (start < end) {
		int pivot = partition(num, start, end);
		quicksort(num, 0, pivot - 1);
		quicksort(num, pivot + 1, end);
	}
}

void QuickSort(vector<int>& num, int n)
{
	quicksort(num, 0, n - 1);
}

int main()
{
	vector<int> num{ 1,7,3,8,9,4,2,6,7,5,8,3,5,10 };
	for (const auto& i : num)
		cout << i << " ";
	QuickSort(num, num.size());
	cout << "\n";
	for (const auto& i : num)
		cout << i << " ";
	return 0;
}

