#include "File.h"
File::File()//default constructor
{
}
File::File(string pName) // constructor with parameter
{
	pathName = pName;
}
string File::getPathName() const //function to return the path name
{
	return pathName;
}
void File::setPathName(string pName) //function to redefine the path name
{
	pathName = pName;
}
File& File::operator=(const File& obj) //overloading operator function that sets one object equal to another 
{
	Document::operator=(obj);
	pathName = obj.pathName;
	return *this;
}