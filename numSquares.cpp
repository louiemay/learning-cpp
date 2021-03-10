#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numSquares(int n)
{
	if (n == 0)
		return 0;
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	bool* visisted = new bool[n + 1]();
	visisted[n] = true;
	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();
		int num = front.first;
		int step = front.second;
		if (num == 0)
			return step;
		for (int i = 1; num - i*i >= 0; i++) {
			int a = num - i*i;
			if (!visisted[a]) {
				if (a == 0) 
					return step + 1;
				q.push(make_pair(num - i*i, step + 1));
				visisted[num - i*i] = true;
			}
		}
	}
	return 0;
}

int main()
{
	cout << numSquares(12) << "\n";    // 3
	cout << numSquares(13) << "\n";    // 2
	return 0;
}



