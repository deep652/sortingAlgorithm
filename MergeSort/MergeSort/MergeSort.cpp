// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

void mergeSort(int *arr, int l, int h);
void merge(int *arr, int l, int h);

int main()
{
	int arr[8] = { 5,2,9,9,7,8,4,3 };

	cout << "Unsorted Array" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	mergeSort(arr, 0, 7);//what is the difference is passing an arr[] and arr as both have base address

	cout << "Sorted Arrary: " << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	getchar();
    return 0;
}

void mergeSort(int *arr, int l, int h)
{
	if (l < h)//as it is a recursive algo we will not use any while loop... and u know why! we will be using stack so..
	{
		int mid = (l + h) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, h);
		merge( arr, l, h);
	}
}

void merge(int *arr, int l, int h)
{
	int i, j, k,mid;
	i = l;
	k = 0; //this is important, can not start with l;
	mid = (l + h) / 2;
	j = mid + 1;
	int *tarr;
	tarr = new int[h - l + 1];
	
	while (i <= mid && j <= h)
	{
		if (arr[i] <= arr[j])
		{
			tarr[k++] = arr[i++];//same as incrementing the index after this statement
		}
		else
		{
			tarr[k++] = arr[j++];
		}
	}
	
	while (i <= mid)
	{
		tarr[k++] = arr[i++];
	}
	while (j <= h)
	{
		tarr[k++] = arr[j++];
	}
	
	for (i = l; i <= h; i++)
	{
		arr[i] = tarr[i-l];
	}
}