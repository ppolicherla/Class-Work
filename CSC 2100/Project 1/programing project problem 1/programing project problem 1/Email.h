#ifndef Email_H
#define Email_H
#include "Document.h"

class Email : public Document //public inheritance of the document class
{
public:
	Email();//default constructor
	Email(string send, string recieve, string tittle, string txt);//constructor with parameters
	string getSender() const;//accessor function to return sender
	string getRecipient() const;//accessor function to return reciever
	string getTitle() const;//accessor funtion to return the title
	Email& operator=(const Email& obj);//overloading operator function that sets one object equal to another 
	void setSender(string send); //mutator function to set the sender
	void setRecipient(string recieve);//mutator function to set the reciever
	void setTitle(string tittle);//mutator function to set the title

private:
	string sender;
	string recipient;
	string title;
	string text;
};
#endif 