

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */

/* https://www.geeksforgeeks.org/counting-inversions/ */

int swaps = 0;
int rev_swaps = 0;

int _mergeSort(int arr[], int temp[], int left, int right, bool reverse);
int merge(int arr[], int temp[], int left, int mid,
		int right);
int reverse_merge(int arr[], int temp[], int left, int mid,
		int right);

/* This function sorts the
input array and returns the
number of inversions in the array */
int mergeSort(int arr[], int array_size, bool reverse)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1, reverse);
}

/* An auxiliary recursive function
that sorts the input array and
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right, bool reverse)
{
	int mid, inv_count = 0;
	if (right > left) {
		/* Divide the array into two parts and
		call _mergeSortAndCountInv()
		for each of the parts */
		mid = (right + left) / 2;

		/* Inversion count will be sum of
		inversions in left-part, right-part
		and number of inversions in merging */
		inv_count += _mergeSort(arr, temp, left, mid, reverse);
		inv_count += _mergeSort(arr, temp, mid + 1, right, reverse);

		/*Merge the two parts*/
		inv_count += reverse ? reverse_merge(arr, temp, left, mid + 1, right) : merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			/* this is tricky -- see above
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
	(if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

/* This funt merges two sorted arrays
and returns inversion count in the arrays.*/
int reverse_merge(int arr[], int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] >= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			/* this is tricky -- see above
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
	(if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // solution comes here
    int n;
    cin >> n;

    int arr[n];
    int max = -1;
    int maxIdx = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > max) {
            max = arr[i];
            maxIdx = i;
        }
    }

    int n1 = maxIdx + 1;
    int n2 = n - (maxIdx + 1);

    int arr1[maxIdx + 1];
    int arr2[n - (maxIdx + 1)];

    memcpy(arr1, &arr[0], (maxIdx + 1)*sizeof(*arr));
    memcpy(arr2, &arr[maxIdx + 1], (n - (maxIdx + 1))*sizeof(*arr));

    swaps = mergeSort(arr1, sizeof(arr1) / sizeof(arr1[0]), false);
    rev_swaps = mergeSort(arr2, sizeof(arr2) / sizeof(arr2[0]), true);

    cout << swaps + rev_swaps << endl;
}

