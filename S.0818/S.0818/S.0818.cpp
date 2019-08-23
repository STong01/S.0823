#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#define BUFSIZE 10000


void printArray(int *src, int n){
	int i;
	for (i = 0; i < n; i++){
		printf("%d ", src[i]);
	}
	putchar('\n');
}

int main(){
#if 0
	int src[10] = { 3, 1, 6, 7, 9, 2, 4, 8, 10, 5 };

	//InsertSort(src, 10);
	//ShellSort(src, 10);
	//MergeSort(src, 10);
	QuickSort(src, 10);

	printArray(src, 10);

#else
	srand(time(NULL));
	int i;

	int src[10000];

	for (i = 0; i < BUFSIZE;i++){
		src[i] = rand() % 5000 + 1;
	}
	//InsertSort(src, BUFSIZE);
	//ShellSort(src, BUFSIZE);
	//MergeSort(src, BUFSIZE);
	QuickSort(src, BUFSIZE);

	printArray(src, BUFSIZE);
	//for (i = 0; i < BUFSIZE; i++){
	//	if (src[i] > src[i + 1]){
	//		printf("%d\n",i);
	//	}
	//}


#endif
	system("pause");
	return 0;
}