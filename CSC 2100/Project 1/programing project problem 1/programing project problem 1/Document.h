#ifndef Document_H
#define Document_H
#include <iostream>
#include <string>
using namespace std;

class Document
{
public:
	Document();//default constructor
	Document(string text);//constructor with text parameter
	string getText() const;//get text function
	void setText(string text);//set text function
	Document& operator=(const Document& doc);//overload operator function

private:
	string text;
};
#endif 