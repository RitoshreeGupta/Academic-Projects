/* 
Ritoshree Gupta
CIS 3501
Fall 2019
Prof. John P. Baugh
Purpose: Compare running times of quick and insertion sorting algorithms and determine which sorting performs better.
*/

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <time.h>
#include <fstream>
using namespace std;

//Function Prototypes
void randomNumGenerator(vector<int> &number, int n);
int Partition(vector<int> number, int low, int high);
void QuickSort(vector<int> number, int low, int high);
void QuickSortTime(vector<int> number, ofstream &outfile);
void InsertionSort(vector<int> number, ofstream &outfile);


/*
Pre-Condition: Initializing 5 vectors which will have upto 0 - 2500 random numbers of integer and perform sorting and run each algorithm 5 times on each set size 
Post-Condition: Run each algorithm 5 times on each set size successfully with the comparision of time
*/
int main() {

	ofstream outfile;
	outfile.open("Output.csv");

	// initializing 5 vectors for each set
	vector<int> num1; // store 250 random integers
	vector<int> num2; // store 500 random integers
	vector<int> num3; // store 750 random integers
	vector<int> num4; // store 1000 random integers
	vector<int> num5; // store 2500 random integers
		
	// calling the random number generator function which going to generate random integers 
		randomNumGenerator(num1, 250); 
		randomNumGenerator(num2, 500);
		randomNumGenerator(num3, 750);
		randomNumGenerator(num4, 1000);
		randomNumGenerator(num5, 2500);

		
		// declaring the size for output csv file 
		outfile << "Integer Sizes" << " ," << num1.size() << ", " << num2.size() << ", " << num3.size() << ", " << num4.size() << ", " << num5.size();
		outfile << endl;
		outfile << "QuickSort";

		// 5 sets of integers for Quick Sort
		int count = 1;
		while (count <= 5) {
			
			outfile  << " ,";
			cout << "Set of Integers (" << count << "): " << endl;
			QuickSortTime(num1, outfile);
			QuickSortTime(num2, outfile);
			QuickSortTime(num3, outfile);
			QuickSortTime(num4, outfile);
			QuickSortTime(num5, outfile);
			outfile << endl;
			cout << endl << endl;
			
			count++;
		}

		cout << endl << "--------------------------------------------------------------------" << endl;
		
		outfile << "InsertionSort";

		// 5 sets of integers for Insertion Sort
		int count2 = 1;
		while (count2 <= 5) {
			outfile << " ,";
			cout << endl << "Set of Integers (" << count2 << "): " << endl;
			InsertionSort(num1, outfile);
			InsertionSort(num2, outfile);
			InsertionSort(num3, outfile);
			InsertionSort(num4, outfile);
			InsertionSort(num5, outfile);
			outfile << endl;
			cout << endl; 

			count2++;
		}

	system("pause");
	return 0;
}


/*
Pre-Condition: This function will contain int type of vector of number and no number of random integers
Post-Condition: Int type of vector number take no number of random integers successfully.
*/
void randomNumGenerator(vector<int> &number, int no)
{
	int randomNum;

	srand(time(NULL));

	for (int i = 0; i < no; i++) {
		randomNum = rand();
		number.push_back(randomNum);
	}
}


/*
Pre-Condition: This function will contain int type of vector of number, integer of low which is starting index of vector and integer of high which is last index 
			   of vector
Post-Condition: This function return the position of pivot successfully.
*/
int Partition(vector<int>number, int low, int high)
{
	int pivot = number[high]; // selecting pivot position
	int i = (low - 1);  // index of smaller number

	for (int j = low; j <= high - 1; j++)
	{ 
		if (number[j] < pivot) 
		{
			i++;  // increment smaller number if current is smaller than pivot
			swap(number[i], number[j]); 
		}
	}
	swap(number[i + 1], number[high]); 
	return (i + 1);

}

/*
Pre-Condition: This function will contain integer type of vector of unsorted number, integer of low which is starting index of vector and integer of high which 
				is last index of vector.This function is going to sort separately and recursivly before and after position of partition.
Post-Condition: This function sort the before and after position of unsorted vector sucessfully.
*/

void QuickSort(vector<int>number, int low, int high)
{
	if (low < high)
	{
		int pos = Partition(number, low, high); // this variable contain partitioning index

		//sort elements before and after partition separately  
		QuickSort(number, low, pos - 1);
		QuickSort(number, pos + 1, high); 
	}
}

/*
Pre-Condition: This function has unsorted integers of number and ofstream outfile which going to store results to the ouput file
Post-Condition: The elements of the vector is sorted using algorithm of quick sort and outfile stores the time results to output file successfully.
*/

void QuickSortTime(vector<int> number, ofstream & outfile)
{
	auto start = std::chrono::high_resolution_clock::now();

	QuickSort(number, 0, number.size()-1);

	auto finish = std::chrono::high_resolution_clock::now();

	int time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

	cout << endl << "Time taken by QuickSort (size of " << number.size() << "): " << time2 << "ns";
	outfile << time2 << " ,";
}


/*
Pre-Condition: This function has unsorted integers of number and ofstream outfile which going to store results to the ouput file
Post-Condition: The elements of the vector is sorted using algorithm of insertion sort and outfile stores the time results to output file successfully.
*/

void InsertionSort(vector<int>number, ofstream &outfile) {

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 1; i < number.size(); i++)
	{
		int j = i;
		while (j > 0 && number[j] < number[j - 1])
		{
			int temp = number[j];
			number[j] = number[j - 1];
			number[j - 1] = temp;
			j--;
		}
	}

	auto finish = std::chrono::high_resolution_clock::now();
	int time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

	cout << endl << "Time taken by InsertionSort (size of " << number.size() << "): " << time << "ns";
	outfile << time << " ,";

}

