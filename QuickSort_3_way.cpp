#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>


using namespace std;


// Function Declarations
void swap(int& a, int& b);

// General Implementation of Quicksort
int genPartition(vector<int>& arr, int low, int high);
void genQuickSort(vector<int>& arr, int low, int high);

// 3-Way Implementation of Quicksort
void threeWayPartition(vector<int>& arr, int l, int r, int& i, int& j);
void threeWayQuicksort(vector<int>& arr, int l, int r);

// Randomized Quicksort
// Uses general algorithm other than a different way
// to get partitioning index
int randPartition(vector<int>& arr, int low, int high);
void randQuickSort(vector<int>& arr, int low, int high);

// Function defintions

// Basic swap function
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// General fashion of implementing quicksort
int genPartition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			// increment index of smaller element
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void genQuickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		// Pi stands for Partitioning Index
		int pi = genPartition(arr, low, high);

		// Output the changing order of the 
		// vector elements as sorting takes place
		cout << "\t\tCurrent order of values: \n";
		cout << "\t\t";
		for (int num : arr)
		{
			cout << num << " ";
		}
		cout << endl << endl;

		// Separately sort elements before
		// partition and after partition
		genQuickSort(arr, low, pi - 1);
		genQuickSort(arr, pi + 1, high);
	}
}

// Algorithm for Quicksort using three sub arrays
void threeWayPartition(vector<int>& arr, int l, int r, int& i, int& j)
{
	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = arr[r];

	while (true)
	{
		// From left, find the first element greater than 
		// or equal to v. 
		while (arr[++i] < v);

		// From right, find the first element smaller than or 
		// equal to v 
		while (v < arr[--j])
			if (j == l)
				break;

		// If i and j cross, then we are done 
		if (i >= j) break;

		// Swap, so that smaller goes on left greater goes on right 
		swap(arr[i], arr[j]);

		// Move all same left occurrence of pivot to beginning of 
		// array and keep count using p 
		if (arr[i] == v)
		{
			p++;
			swap(arr[p], arr[i]);
		}

		// Move all same right occurrence of pivot to end of array 
		// and keep count using q 
		if (arr[j] == v)
		{
			q--;
			swap(arr[j], arr[q]);
		}
	}

	// Move pivot element to its correct index 
	swap(arr[i], arr[r]);

	// Move all left same occurrences from beginning 
	// to adjacent to arr[i] 
	j = i - 1;
	for (int k = l; k < p; k++, j--)
		swap(arr[k], arr[j]);

	// Move all right same occurrences from end 
	// to adjacent to arr[i] 
	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
		swap(arr[i], arr[k]);
}

// 3-way partition based quick sort 
void threeWayQuicksort(vector<int>& arr, int l, int r)
{
	if (r <= l) return;

	int i, j;

	// Output the changing order of the 
	// vector elements as sorting takes place
	cout << "Current order of values: \n";
	cout << "\t\t";
	for (int num : arr)
	{
		cout << num << " ";
	}
	cout << endl << endl;

	// Note that i and j are passed as reference 
	threeWayPartition(arr, l, r, i, j);

	// Recur 
	threeWayQuicksort(arr, l, j);
	threeWayQuicksort(arr, i, r);
}

// Function to choose a random pivot
int randPartition(vector<int>& arr, int low, int high)
{
	// Generate a random number in between 
	// low .. high 
	srand(time(NULL));
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high] 
	swap(arr[random], arr[high]);

	return genPartition(arr, low, high);
}

// Basically the same as the general quicksort algorithm
// just using a random pivot value
void randQuickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		// Pi stands for Partitioning Index
		int pi = randPartition(arr, low, high);

		// Output the changing order of the 
		// vector elements as sorting takes place
		cout << "\t\tCurrent order of values: \n";
		cout << "\t\t";
		for (int num : arr)
		{
			cout << num << " ";
		}
		cout << endl << endl;

		// Separately sort elements before
		// partition and after partition
		randQuickSort(arr, low, pi - 1);
		randQuickSort(arr, pi + 1, high);
	}
}


// Main function
int main()
{
	// Seed for use of rand() function
	srand(time(0));

	// Number of elements to be inserted into the vector
	int n = 12; 

	// User Input variable
	int userChoice;

	// Vector to be sorted
	vector<int> numbers(n);

	// Fill the vector
	for (int i = 0; i < n; i++)
	{
		numbers[i] = 1 + rand() % 999;
	}

	// Shows the begging numbers in the vector
	cout << "\t\tInitial Numbers: " << endl;
	cout << "\t\t";
	for (int num : numbers)
	{
		cout << num << " ";
	}
	cout << endl << endl;
	

	cout << "\t\tChoose your quicksort algorithm: " << endl;
	cout << "\t\t1. General." << endl;
	cout << "\t\t2. 3-Way." << endl;
	cout << "\t\t3. Randomized." << endl << endl;

	cin >> userChoice;

	if (userChoice == 1)
	{
		genQuickSort(numbers, 0, numbers.size() - 1);

		cout << "\t\tFinal Sorted Vector: " << endl;
		cout << "\t\t";
		for (int num : numbers)
		{
			cout << num << " ";
		}
		cout << endl << endl;
	}
	else if (userChoice == 2)
	{
		threeWayQuicksort(numbers, 0, numbers.size() - 1);

		cout << "\t\tFinal Sorted Vector: " << endl;
		cout << "\t\t";
		for (int num : numbers)
		{
			cout << num << " ";
		}
		cout << endl << endl;
	}
	else if (userChoice == 3)
	{
		randQuickSort(numbers, 0, numbers.size() - 1);

		cout << "\t\tFinal Sorted Vector: " << endl;
		cout << "\t\t";
		for (int num : numbers)
		{
			cout << num << " ";
		}
		cout << endl << endl;
	}
	else
	{
		cout << "\t\tInvalid choice." << endl << endl;
	}	

	return 0;
}