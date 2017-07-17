#include "Email.h"

Email::Email()//default constructor
{
}
Email::Email(string send, string recieve, string tittle, string txt) : Document(txt)//constructor for user defined variables
{
	sender = send;
	recipient = recieve;
	title = tittle;
	text = txt;
}
string Email::getSender() const//function to return the sender
{
	return sender;
}
string Email::getRecipient() const //function to return the reciever
{
	return recipient;
}
string Email::getTitle() const //function to return the title
{
	return title;
}
void Email::setSender(string send) //function to set the sender
{
	sender = send;
}
void Email::setRecipient(string recieve)//function to set the receiver
{
	recipient = recieve;
}
void Email::setTitle(string tittle)//function to set the title
{
	title = tittle;
}
Email& Email::operator=(const Email& obj)//overloading operator function that sets one object equal to another 
{
	Document::operator=(obj);
	sender = obj.sender;
	recipient = obj.recipient;
	title = obj.title;
	return *this;
}