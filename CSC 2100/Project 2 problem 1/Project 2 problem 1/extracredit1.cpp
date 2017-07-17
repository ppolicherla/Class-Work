// Programmed By: Pavan Policherla
// extracredit 1
// 11/30/2015

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//function headers
void selectionSort(int& selectioncount, int& selectassign, int list[], int num);
void bubbleSort(int& bubblecount, int& bubassign, int list[], int num);	
void insertionSort(int& insertioncount, int& insertassign, int list[], int num);	

int main()
{
	//creating the three lists to use in the three sorts
	int list1[5000];	
	int list2[5000];	
	int list3[5000];
	//initializing the counters for the sorts and assignments
	int bubblecount = 0;	
	int selectioncount = 0;	
	int insertioncount = 0;	
	int bubassign = 0;	
	int selectassign = 0;	
	int insertassign = 0;	
	//random number generator to fill the list
	srand(time(0));
	//populating the int array with random numbers
	for (int i = 0; i < 5000; i++)
	{
		list1[i] = rand() % 5000 + 1;
	}
	srand(time(0));

	for (int i = 0; i < 5000; i++)
	{
		list2[i] = rand() % 5000 + 1;
	}
	srand(time(0));

	for (int i = 0; i < 5000; i++)
	{
		list3[i] = rand() % 5000 + 1;
	}
	//calling the sort functions
	bubbleSort(bubblecount, bubassign, list1, 5000);
	selectionSort(selectioncount, selectassign, list2, 5000);
	insertionSort(insertioncount, insertassign, list3, 5000);
	//outputting results
	cout << "The number of comparisons are: " << endl;
	cout << " Bubble Sort: " << bubblecount << endl;
	cout << " Selection Sort: " << selectioncount << endl;
	cout << " Insertion Sort: " << insertioncount << endl << endl;

	cout << "The number of item assignments are: " << endl;
	cout << " Bubble Sort: " << bubassign << endl;
	cout << " Selection Sort: " << selectassign << endl;
	cout << " Insertion Sort: " << insertassign << endl << endl;

	return 0;
}

//function for selection sort
void selectionSort(int& selectioncount, int& selectassign, int list[], int num)	
{
	int pos;//position variable	
	int t;//value variable
	//looping throught the list
	for (int i = 0; i< num - 1; i++)
	{
		t = list[i];
		pos = i;
	//loop that will make comparisons and increment the counter for comparisons
		for (int j = i++; j<num; j++)
		{
			selectioncount++;

			if (t > list[j])
			{
				t = list[j];
				pos = j;
			}
		}
		//it will switch appropriate values and increment the assignemnt counter
		if (pos != i)
		{
			list[i] = list[pos];
			list[pos] = t;
			selectassign++;
		}

	}

}
//bubble sort function
void bubbleSort(int& bubblecount, int& bubassign, int list[], int num)	
{
	int list1;
	int j1;

	for (int i = 1; i <= num; i++)
	{
		//loop that will make comparisons and increment the counter for comparisons
		for (int j = 0; j < num - 1; j++)
		{
			bubblecount++;
			// it will switch appropriate values and increment the assignemnt counter
			if (list[j + 1] < list[j])
			{
				j1 = j + 1;
				list1 = list[j];
				list[j] = list[j1];
				list[j + 1] = list1;
				bubassign++;
			}
		}
	}
}
//insertion sort function
void insertionSort(int& insertioncount, int& insertassign, int list[], int num)	
{
	//loop that will make comparisons and increment the counter for comparisons
	for (int i = 1; i< num; i++)
	{
		int count = list[i];
		int n1 = i - 1;
		// it will switch appropriate values and increment the assignemnt counter
		while (list[n1]>count && n1 >= 0)
		{
			insertioncount++;
			insertassign++;
			list[n1 + 1] = list[n1];
			n1--;
		}
		{
			list[n1 + 1] = count;
			insertassign++;
		}
	}
}