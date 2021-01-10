#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

#define MAX 20
#define SWAP(a, b, temp) temp = a; a = b; b = temp;

int list[MAX];

void init_list()
{
	for(int i = 0; i < MAX; i++) {
		list[i] = (rand() % 1000) + 1;
	}
}

void print_list()
{
	for (int i = 0; i < MAX; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");
}

void selection_sort()
{
	printf("selection sort : ");
	int i, j, min, temp;
	for(i = 0; i < MAX - 1; i++) {
		min = i;
		for(j = i + 1; j < MAX; j++)
			if(list[j] < list[min])
				min = j;
		if(j != min)
			SWAP(list[i], list[min], temp);
	}
}

void insertion_sort()
{
	printf("insertion sort : ");
	int i, j, temp;
	for(i = 1; i < MAX; i++) {
		temp = list[i];
		for(j = i - 1; j >= 0 && list[j] > temp; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = temp;
	}
}

void bubble_sort()
{
	printf("bubble sort : ");
	int i, j, temp;
	for(i = MAX - 1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}
	}
}

void insertion_sort_for_shell(int first, int last, int gap)
{
	int i, j, temp;
	for(i = first + gap; i < last; i = i + gap) {
		temp = list[i];
		for(j = i - gap; j >= first && list[j] > temp; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = temp;
	}
}

void shell_sort()
{
	printf("shell sort : ");
	int i, gap;
	for (gap = MAX / 2; gap > 0; gap = gap / 2) {
		if((gap % 2) == 0) gap++;
		for(i = 0; i < gap; i++) 
			insertion_sort_for_shell(i, MAX - 1, gap);
	}
}

int sorted[MAX];
void merge(int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	
	while(i <= mid && j <= right) {
		if (list[i] < list[j]) {
			sorted[k] = list[i];
			i++;
		} else {
			sorted[k] = list[j];
			j++;
		}
		k++;
	}
	
	if (i > mid) {
		for (int l = j; l <= right; l++) 
			sorted[k++] = list[l];
	} else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}
	
	for (int l = left; l <= right; l++)
		list[l] = sorted[l];
	
}

void _merge_sort(int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;
		_merge_sort(left, mid);
		_merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

void merge_sort()
{
	printf("merge sort : ");
	_merge_sort(0, MAX);
}

int partition(int left, int right)
{
	int pivot, temp;
	int low, high;
	
	pivot = list[left];
	//printf("pivot : %d \n", pivot);
	low = left;
	high = right + 1;
	
	do {
		do {
			low++;
		} while (list[low] < pivot);
		
		do {
			high--;
		} while (list[high] > pivot);
		
		if (low < high) {
			//printf("SWAP %d %d\n", list[low], list[high]);
			 SWAP(list[low], list[high], temp);
		}	
	} while (low < high);
	
	SWAP(list[left], list[high], temp);
	
	return high;
}

void _quick_sort(int left, int right)
{
	if (left < right) {
		int q = partition(left, right);
		_quick_sort(left, q - 1);
		_quick_sort(q + 1, right);
	}
}

void quick_sort()
{
	printf("quick sort : ");
	_quick_sort(0, MAX - 1);
}

void heap_sort()
{
	printf("heap sort : ");
	init_heap();
	for(int i = 0; i < MAX; i++)
		insertMinHeap(list[i]);
	for(int i = 0; i < MAX; i++)
		list[i] = deleteMinHeap();
}

int main(void)
{
	srand(time(NULL));
	
	init_list();
	selection_sort();
	print_list();
	
	init_list();
	insertion_sort();
	print_list();
	
	init_list();
	bubble_sort();
	print_list();
	
	init_list();
	shell_sort();
	print_list();
	
	init_list();
	merge_sort();
	print_list();
	
	init_list();
	quick_sort();
	print_list();
	
	init_list();
	heap_sort();
	print_list();
}
