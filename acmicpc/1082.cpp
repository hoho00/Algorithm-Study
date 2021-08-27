#include<iostream> 
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[500001];
int sorted[500001];
int cnt = 0;
void merge(int left, int mid, int right)
{
	int low = left;
	int k = left;
	int high = mid + 1;
	while (low <= mid && high <= right)
	{
		if (arr[low] <= arr[high])
		{
			sorted[k++] = arr[low++];
		}
		else
		{
			cnt += mid - low + 1;
			sorted[k++] = arr[high++];
		}
	}
	if (low <= mid)
	{
		for (int i = low; i <= mid; i++)
			sorted[k++] = arr[i];
	}
	else
	{
		for (int i = high; i <= right; i++)
			sorted[k++] = arr[i];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sorted[i];
}


void merge_sort(int left, int right)
{
	if (left < right)
	{
		int m = (left + right) / 2;
		merge_sort(left, m);
		merge_sort(m + 1, right);
		merge(left, m, right);
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	merge_sort(1, N);
	cout << cnt;
}
