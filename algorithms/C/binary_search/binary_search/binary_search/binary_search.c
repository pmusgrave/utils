#include <stdlib.h>
#include <stdio.h>

int getKey();
int searchForKey(int array[], int key, int lowerbound, int upperbound);

int main(void)
{
	int arr[10] = { 10,11,12,13,14,15,16,17,18,19 };
	int key;
	int i = 0;
	for (i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	key = getKey();
	int keyindex = searchForKey(arr, key, 0, 9);

	if (keyindex != -1) {
		printf("Key found at inded %d\n", keyindex);
	}
	else {
		printf("Key not found. Exiting.\n");
	}
	return keyindex;
}

int getKey()
{
	int k;
	printf("Enter search key: ");
	scanf_s("%i", &k);
	return k;
	
}

int searchForKey(int array[], int key, int lowerbound, int upperbound)
{
	int mid = (upperbound - lowerbound) / 2 + lowerbound;
	if (upperbound == lowerbound || key < array[lowerbound] || key > array[upperbound]) {
		return -1;
	}
	else if (key == array[mid]) {
		return mid;
	}
	else if (key == array[upperbound]) {
		return upperbound;
	}
	else if (key > array[mid]) {
		printf("Looking at index %d\n", mid);
		searchForKey(array, key, mid, upperbound);
	}
	else if (key < array[mid]) {
		printf("Looking at index %d\n", mid);
		searchForKey(array, key, lowerbound, mid);
	}
	
}