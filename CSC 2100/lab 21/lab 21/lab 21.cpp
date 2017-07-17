//programmed by: Pavan Policherla
// lab 21
// 11/30/2015

#include <iostream>
#include<string>
#include<vector>
using namespace std;

int sequence(vector<string> arr, string key, int size);

int main()
{
	vector<string> array = { "Sandy","Monday", "Pavan", "Armando", "Justin" };
	string key;

	cout << "Please enter a name to be searched for: ";
	cin >> key;

	cout << "that name is at index " << sequence(array, key, array.size()) << endl;
}

int sequence(vector<string> arr, string key, int size)
{
	if (size == 0)
	{
		return -1;
	}
	if (key == arr[size - 1])
	{
		return size - 1;
	}
	else
	{
		return sequence(arr, key, size - 1);
	}
}