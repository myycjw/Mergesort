#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int maxn = 10e5 + 10;
int i, j, k;
int n, m, q;
int a[maxn];
void merge(int A[], int l, int r, int mid) {
	i = l;
	j = mid + 1;
	for (k = l; k <= r; k++)
		a[k - l] = A[k];
	for (k = l; k <= r; k++) {
		if (i > mid) {
			A[k] = a[j - l];
			j++;
		}
		else if (j > r) {
			A[k] = a[i - l];
			i++;
		}
		else if (a[i - l] > a[j - l]) {
			A[k] = a[j - l];
			j++;
		}
		else {
			A[k] = a[i - l];
			i++;
		}
	}
}

void merge_sort(int A[], int l, int r) {
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	merge_sort(A, l, mid);
	merge_sort(A, mid + 1, r);
	merge(A, l, r, mid);

}

int A[maxn];
int main() {
	scanf("%d", &n);//����A�������м�������
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);//����A���е�ÿ��Ԫ��
	merge_sort(A, 0, n-1);
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	return 0;
}
