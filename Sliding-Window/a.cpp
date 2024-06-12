/* Sliding Window Maximum (Maximum of all subarrays of size K)
Given an array and an integer K, find the maximum for each and every contiguous subarray of size K.
*/
/* Maximum of all subarrays of size K using Max-Heap: 
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k)
{
	vector<int> ans;
	priority_queue<pair<int, int> > heap;

	for (int i = 0; i < k; i++)
		heap.push({ arr[i], i });

	ans.push_back(heap.top().first);

	for (int i = k; i < arr.size(); i++) {
		heap.push({ arr[i], i });
		while (heap.top().second <= i - k)
			heap.pop();
		ans.push_back(heap.top().first);
	}

	return ans;
}

int main()
{
	vector<int> arr = { 2, 3, 7, 9, 5, 1, 6, 4, 3 };
	int k = 3;
	vector<int> result = maxSlidingWindow(arr, k);
	for (auto i : result)
		cout << i << " ";

	return 0;
}
