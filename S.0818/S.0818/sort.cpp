#include "sort.h"
#include <stdlib.h>
//插入排序
void InsertSort(int *src, int n){
	int i, j;
	int tmp;
	for (i = 1; i < n; i++){

		tmp = src[i];

		for (j = i; j > 0 && src[j - 1] > tmp; j--){
			src[j] = src[j - 1];
		}

		src[j] = tmp;
	}
}
//希尔排序
void ShellSort(int *src, int n){
	int i, j, k;
	int gap, tmp;
	for (gap = n / 2; gap; gap /= 2){

		for (k = 0; k < gap; k++, gap /= 2){

			for (i = gap + k; i < n; i += gap){

				tmp = src[i];

				for (j = i; j >= gap && src[j - gap] > tmp; j -= tmp){
					src[j] = src[j - gap];
				}

				src[j] = tmp;
			}
		}
	}
}
//归并排序
void dealMergeSort(int *src, int *tmp, int start, int end){
	if (start >= end){
		return;
	}
	int mid = (start + end) / 2;
	dealMergeSort(src, tmp, start, mid);
	dealMergeSort(src, tmp, mid + 1, end);
	int a = start;
	int b = mid + 1;
	int c = start;

	while (a <= mid && b <= end){
		if (src[a] < src[b]){
			tmp[c] = src[a];
			a++;
		}
		else{
			tmp[c] = src[b];
			b++;
		}
		c++;
	}
	for (; a <= mid; a++, c++){
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++){
		tmp[c] = src[b];
	}
	int i;
	for (i = start; i <= end; i++){
		src[i] = tmp[i];
	}
}
void MergeSort(int *src, int n){

	int *tmp = (int*)malloc(n*sizeof(int));

	dealMergeSort(src, tmp, 0, n - 1);

	free(tmp);
}
//快速排序
//小的放在枢纽元左边，大的放在枢纽元右边。
void swapArgs(int *pa, int *pb){
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int doublePointWay2(int * src, int start, int end){
	int a = start, b = end - 1;
	int mid = (start + end) / 2;
	swapArgs(src + mid, src + end);
	while (a <= b){
		while (a < end && src[a] <= src[end]){
			a++;
		}

		while (b > 0 && src[b] >= src[end]){
			b--;
		}
		if (a == b && (a == 0 || a == end)){
			break;
		}
		
		if (a < b){
			swapArgs(src + a, src + b);

		}
	}
	swapArgs(src + a, src + end);//返回枢纽元
	return a;
}

int doublePointWay1(int * src, int start, int end){
	int a = start, b = end;
	int flag = 0;

	while (src[b] > src[a]){
		b--;
	}

	while (a < b){
		swapArgs(src + b, src + a);
		flag = !flag;

		while (src[b] >= src[a]){
			flag ? a++ : b--;
		}
	}
	return flag ? b : a;//b动返回a，a动返回a
}

void dealQuickSort(int * src, int start, int end){
	int mid;
	if (start < end){
		mid = doublePointWay2(src, start, end);
		dealQuickSort(src, start, mid - 1);
		dealQuickSort(src, mid + 1, end);

	}
}

void QuickSort(int *src, int n){//快排函数

	dealQuickSort(src, 0, n - 1);
}


