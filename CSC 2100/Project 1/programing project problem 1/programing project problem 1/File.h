#ifndef File_H
#define File_H
#include "Document.h"
class File : public Document //public inheritance from document class
{
public:
	File();//default constructor
	File(string pName); // constructor with parameter
	string getPathName() const;//function to return the path name
	void setPathName(string pName); //function to redefine the path name
	File& operator=(const File& obj);//overloading operator function that sets one object equal to another 
private:
	string pathName;
};
#endif