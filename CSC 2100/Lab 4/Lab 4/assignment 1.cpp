//programmed by: Pavan Policherla
// lab 4 assignment 1
// 9/23/2015

#include<iostream>
#include<string>
using namespace std;
void removeVowel(string& input);
bool vowel(char v);
int main()
{
	string string;
	cout << "Please enter a word to be analyzed: ";
	cin >> string;
	cout << endl;
	removeVowel(string);
	cout << "new string is: " << string << endl;
}

void removeVowel(string& input)
{
	string temp = "";
	int substrSize = 0;
	int string = 0;
	bool start = false;

	for (int i = 0; i < input.length(); i++)
	{
		if (!vowel(input[i]))
		{
			substrSize++;
			if (!start)
			{
				string = i;
				start = true;
			}
		}
		else
		{
			temp = temp + input.substr(string, substrSize);
			substrSize = 0;
			string = 0;
			start = false;
		}
	}
	input = temp;
}

bool vowel(char v)
{
	if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u' || v == 'A' || v == 'E' || v == 'I' || v == 'O' || v == 'U')
	{
		return true;
	}
	else
	{
		return false;
	}
}