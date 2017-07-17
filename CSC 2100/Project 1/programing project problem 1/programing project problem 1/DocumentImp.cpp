#include "Document.h"
Document::Document() //default constructor
{
}
Document::Document(string txt) // constructor with a string as a parameter
{
	text = txt;
}
string Document::getText() const//accesor function
{
	return text;
}
void Document::setText(string txt)//mutator function
{
	text = txt;
}
Document& Document::operator=(const Document& doc)//overloading operator
{
	text = doc.text;
	return *this;
}