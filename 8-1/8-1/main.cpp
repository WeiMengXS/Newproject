#include<iostream>
using namespace std;
int a[] = { 1, 0, 3, 4, 6, 5, 7, 2 };
int tmp[8];

// ¹é²¢ÅÅĞò£¨C-µİ¹é°æ£©
//void merge_sort_recursive(int arr[], int reg[], int start, int end) {
//	if (start >= end)
//		return;
//	int len = end - start, mid = (len >> 1) + start;
//	int start1 = start, end1 = mid;
//	int start2 = mid + 1, end2 = end;
//	merge_sort_recursive(arr, reg, start1, end1);
//	merge_sort_recursive(arr, reg, start2, end2);
//	int k = start;
//	while (start1 <= end1 && start2 <= end2)
//		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
//	while (start1 <= end1)
//		reg[k++] = arr[start1++];
//	while (start2 <= end2)
//		reg[k++] = arr[start2++];
//	for (k = start; k <= end; k++)
//		arr[k] = reg[k];
//}
void merge(int a[], int ret[], int l, int r)
{
	if (l >= r)
		return;
	int len =r-l;
	int mid = (l + r) / 2;
	int start1 = l, end1 = mid;
	int start2 = mid + 1, end2 = r;
	merge(a, ret, start1, end1);
	merge(a, ret, start2, end2);
	int k = l;
	while (start1 <= end1&&start2 <= end2)
		ret[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	while (start1 <= end1)
		ret[k++] = a[start1++];
	while (start2 <= end2)
		ret[k++] = a[start2++];
	k = l;
	start1 = l;
	while (k <= r)
	{
		a[start1++] = ret[k++];
	}

}
int main()
{
	int len = sizeof(a) / sizeof(a[0]);
	int reg[8];
	merge(a, reg, 0, len - 1);

	for (int i = 0; i<len; i++)
	{
		cout << a[i] << endl;
	}
	system("pause");
	return 0;
}