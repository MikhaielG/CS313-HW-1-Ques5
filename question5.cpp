/*
* Create a multi - level sort.For instance, for all selections of n > 10 you do sort X and
* within sort X, when you have a situation with n < 10 you do sort Y.Be creative.Time
* your sort against two “reasonably comparable” sorts(you may use libraries for the
* “reasonably comparable sorts”).
*/
#include <iostream>
#include <ctime>
#include "various_functions.h"
#include <array>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	srand(time(NULL));
	int size = 0;
	cout << "Array size: ";
	cin >> size;
	int* my_arr = new int[size];
	int* my_arr1 = new int[size];
	int* my_arr2 = new int[size];
	//filling arrays with random integers from 1 to 100
	for (int i = 0; i < size; i++) {
			my_arr[i] = rand() % 100 + 1;
			my_arr1[i] = my_arr[i];
			my_arr2[i] = my_arr[i];
	}
	

	//printing unsorted array
	//cout << "Unsorted array:\n";
	//print_array(my_arr, size);
	/*cout << "\n";
	print_array(my_arr1, size);
	cout << "\n";
	print_array(my_arr2, size);*/
	//cout << "\n";

	////measuring time for a quick sort
	auto qs_time = TimeFunc([&]() {QuickSort(my_arr, 0, size - 1); });
	cout << "time taken for the quick sort: " << qs_time << " microseconds\n";
	////print_array(my_arr, size);

	//measuring time for a merge sort
	auto ms_time = TimeFunc([&]() {MergeSort(my_arr1, 0, size - 1); });
	cout << "time taken for the merge sort: " << ms_time << " microseconds\n";
	//print_array(my_arr1, size);
	
	//measuring time for a multilevel sort
	auto s_time = TimeFunc([&]() {my_multi_lvl_sort(my_arr2, 0, size - 1); });
	cout << "time taken for the multilevel sort: " << s_time << " microseconds\n";
	//print_array(my_arr2, size);
	compare(qs_time, ms_time, s_time);
}