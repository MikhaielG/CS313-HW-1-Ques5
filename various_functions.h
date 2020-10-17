#pragma once
#include <chrono>
#include <iostream>
#include <ctime>
using namespace std;
using namespace std::chrono;

template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<microseconds>(end - begin).count();
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//quick sort
int Partition(
    int arr[],
    int startIndex,
    int endIndex)
{
    // Set the first item as pivot
    int pivot = arr[startIndex];

    // Left sublist and right sublist
    // are initially empty
    int middleIndex = startIndex;

    // Iterate through arr[1 ... n - 1]
    for (int i = startIndex + 1; i <= endIndex; ++i)
    {
        if (arr[i] < pivot)
        {
            // the current item is on the left sublist
            // prepare a seat by shifting middle index
            ++middleIndex;

            // the arr[middleIndex] is
            // the member of right sublist,
            // swap it to the current item which is
            // member of left list
            swap(arr[i], arr[middleIndex]);
        }
    }

    // By now, the arr[middleIndex] item is
    // member of left sublist.
    // We can swap it with the pivot
    // so the pivot will be in the correct position
    // which is between left sublist and right sublist
    swap(arr[startIndex], arr[middleIndex]);

    // return the index of pivot
    // to be used by next quick sort
    return middleIndex;
}

void QuickSort(
    int arr[],
    int startIndex,
    int endIndex)
{
    // Only perform sort process
    // if the end index is higher than start index
    if (startIndex < endIndex)
    {
        // Retrieve pivot position from Partition() function
        // This pivotIndex is the index of element that is already
        // in correct position
        int pivotIndex = Partition(arr, startIndex, endIndex);

        // Sort left sublist
        // arr[startIndex ... pivotIndex - 1]
        QuickSort(arr, startIndex, pivotIndex - 1);

        // Sort right sublist
        // arr[pivotIndex + 1 ... endIndex]
        QuickSort(arr, pivotIndex + 1, endIndex);
    }
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\n";
    }
}




void Merge(
    int arr[],
    int startIndex,
    int middleIndex,
    int endIndex)
{
    // Numbers of elements that will be sorted
    // from startIndex until endIndex
    int totalElements = endIndex - startIndex + 1;

    // Temporary array to store merged array
    int* tempArray = new int[totalElements];

    // Index of left subarray
    // arr[startIndex ... middleIndex]
    int leftIndex = startIndex;

    // Index of right subarray
    // arr[middleIndex + 1 ... endIndex]
    int rightIndex = middleIndex + 1;

    // Index of merged array
    int mergedIndex = 0;

    // Merge the two subarrays
    while (leftIndex <= middleIndex && rightIndex <= endIndex)
    {
        if (arr[leftIndex] <= arr[rightIndex])
        {
            // Store the left subarray's element
            // if it's lower than the right one
            tempArray[mergedIndex] = arr[leftIndex];

            // Go to next left subarray index
            ++leftIndex;
        }
        else
        {
            // Store the right subarray's element
            // if it's lower than the left one
            tempArray[mergedIndex] = arr[rightIndex];

            // Go to next right subarray index
            ++rightIndex;
        }

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in left subarray
    // that is not stored to merged array yet
    while (leftIndex <= middleIndex)
    {
        tempArray[mergedIndex] = arr[leftIndex];

        // Go to next left subarray index
        ++leftIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // If there're any remaining element in right subarray
    // that is not stored to merged array yet
    while (rightIndex <= endIndex)
    {
        tempArray[mergedIndex] = arr[rightIndex];

        // Go to next right subarray index
        ++rightIndex;

        // Go to next merged array index
        ++mergedIndex;
    }

    // Now, the merged array has been sorted
    // Copy the elements to the original array
    for (int i = 0; i < totalElements; ++i)
    {
        arr[startIndex + i] = tempArray[i];
    }

    // Remove the temporary array tempArray
    delete[] tempArray;

    return;
}



void MergeSort(
    int arr[],
    int startIndex,
    int endIndex)
{
    // Only perform sort process
    // if the end index is higher than start index
    if (startIndex < endIndex)
    {
        // Find middle index
        int middleIndex = (startIndex + endIndex) / 2;

        // Sort left subarray
        // arr[startIndex ... middleIndex]
        MergeSort(arr, startIndex, middleIndex);

        // Sort right subarray
        // arr[middleIndex + 1 ... endIndex]
        MergeSort(arr, middleIndex + 1, endIndex);

        // Merge the left and the right subarray
        Merge(arr, startIndex, middleIndex, endIndex);
    }

    return;
}
void my_multi_lvl_sort(int arr[] , int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int middleIndex = (startIndex + endIndex) / 2;
        if (middleIndex < 2000) {
            QuickSort(arr, startIndex, middleIndex);
            MergeSort(arr, middleIndex + 1, endIndex);
            Merge(arr, startIndex, middleIndex, endIndex);
            return;
        }
        
        else {
            MergeSort(arr, startIndex, middleIndex);
            MergeSort(arr, middleIndex + 1, endIndex);
            Merge(arr, startIndex, middleIndex, endIndex);
            return;
        }
    }
}

void compare(long long t1, long long t2, long long t3) {
    if ((t1 >= t2) && (t2 >= t3)) 
        cout << "The multi-level sort is the quickest for this case!\n";
    if ((t3 >= t1) && (t2 >= t1)) 
        cout << "The quick sort is the quickest for this case!\n";
    if((t3 >= t2) && (t1 >= t2))
        cout << "The merge sort is the quickest for this case!\n";
}

