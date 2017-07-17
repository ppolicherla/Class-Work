// Programmed By: Pavan Policherla
// project problem 1
// 11/15/2015


#include <iostream>
using namespace std;
#include "Document.h"
#include "Email.h"
#include "File.h"

//function to find keyword in the document object
bool ContainsKeyword(const Document& docObj, string Keyword)
{
	if (docObj.getText().find(Keyword) != string::npos)
		return true;
	return false;
}


int main()
{
	//declaration of class variables to be used
	string send, recieve, title, text, pathName, keywrd;
	//declaration of email object
	Email email;
	//using set functions to set the email information
	cout << "Enter the sender name: ";
	getline(cin, send);
	email.setSender(send);
	cout << "Enter the recipient name: ";
	getline(cin, recieve);
	email.setRecipient(recieve);
	cout << "Enter the title name: ";
	getline(cin, title);
	email.setTitle(title);
	cout << "Enter the text: ";
	getline(cin, text);
	email.setText(text);
	cout << endl;
	//outputting the email information
	cout << "Email" << endl;
	cout << "Sender's Name: " << email.getSender() << endl;
	cout << "Recipient'sName:" << email.getRecipient() << endl;
	cout << "Title: " << email.getTitle() << endl;
	cout << "Message: " << email.getText() << endl << endl << endl;
	cout << "Enter the keyword: ";
	getline(cin, keywrd);
	//finding a keyword in the email
	if (ContainsKeyword(email, keywrd))
	{
		cout << "There is a keyword" << endl;
	}
	else
	{
		cout << "There is no keyword" << endl;
	}

	File file;//declaring a file object
	//seting the file object information
	cout << "Enter the pathname: ";
	getline(cin, pathName);
	file.setPathName(pathName);
	cout << "Enter the text: ";
	getline(cin, text);
	file.setText(text);
	//outputing the file info
	cout << "File" << endl;
	cout << "PathName: " << file.getPathName() << endl;
	cout << "Messge: " << file.getText() << endl << endl << endl;
	cout << "Enter the keyword:";
	getline(cin, keywrd);
	//finding a keyword in the file
	if (ContainsKeyword(file, keywrd))
	{
		cout << "There is a keyword!" << endl;
	}
	else
	{
		cout << "There is no keyword" << endl;
	}
	return 0;
}