// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int partition(int *arr, int l, int h);
void quickSort(int *arr, int l, int h);
void swap(int &a, int &b);

int main()
{
	int arr[] = { 3,2,5,6,9,7,8,9 };
	int l, h, mid;
	l = 0;
	h = sizeof(arr)/sizeof(arr[0]);
	mid = (l + h) / 2;
	cout << "Unsorted array" << endl;
	for (int i = 0; i < h; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	quickSort(arr, l, h);

	cout << "Sorted array" << endl;
	for (int i = 0; i < h; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	getchar();
    return 0;
}

void quickSort(int *arr, int l, int h)
{
	int pivot;
	if (l < h)
	{
		pivot = partition(arr, l, h);
		quickSort(arr, l, pivot);
		quickSort(arr, pivot+1, h);
	}
	
}

int partition(int *arr, int l, int h)
{
	int p;
	p = arr[l];
	int i, j;
	i = l;
	j = h;
	while (i < j)
	{
		do
		{
			i++;
		} while (arr[i] <= p);
		do
		{
			j--;
		} while(arr[j] > p);
		if ( i<j)
		{
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}

void swap(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}