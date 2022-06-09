#include <iostream> 

#include <ctime> 

#include <stdio.h> 



using namespace std;



const unsigned int NUM = 50000;



void CreateArray(int* A, int* B, const int NUM) {



	srand(1);



	for (int i = 0; i < NUM; i++)



		A[i] = B[i] = (int)rand();



}



void RestoreArray(int* A, int* B, const int NUM)

{

	for (int i = 0; i < NUM; i++)

		A[i] = B[i];

}



void PasteSort(int* arr, int size)

{

	int j;

	for (int i = 1; i < size; i++) {

		j = i;

		while (arr[j] < arr[j - 1]) {

			swap(arr[j], arr[j - 1]);

			if (j-- == 0)

				break;

		}

	}

}



int findpivot(int* A, int i, int j) {

	int firstkey;

	firstkey = A[i];

	for (int k = i + 1; k <= j; k++) {

		if (A[k] > firstkey)

			return k;

		else if (A[k] < firstkey)

			return i;

	}

	return -1;

}



int partition(int* A, int i, int j, int pivot) {

	int l, r;

	l = i;

	r = j;

	do {

		swap(A[l], A[r]);

		while (A[l] < pivot)

			l++;

		while (A[r] >= pivot)

			r--;

	} while (l <= r);



	return l;

}



void quicksort(int* A, int i, int j) {

	int pivot;

	int pivotindex;

	int k;

	pivotindex = findpivot(A, i, j);

	if (pivotindex != -1) {

		pivot = A[pivotindex];

		k = partition(A, i, j, pivot);

		quicksort(A, i, k - 1);

		quicksort(A, k, j);

	}

}



int main()
{
	int A[NUM];
	int B[NUM];

	for (int i = 0; i < 5; i++)
	{
		CreateArray(A, B, NUM);
		clock_t  begt, endt;
		begt = clock();
		PasteSort(A, NUM);
		endt = clock();
		printf("time=%d\n", endt - begt);
		RestoreArray(A, B, NUM);
		begt = clock();
		quicksort(A, 0, NUM - 1);
		endt = clock();
		printf("time=%d\n", endt - begt);
	}
	return 0;
}
