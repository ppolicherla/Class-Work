#include "personType.h"
using namespace std;

class doctorType : public personType
{
public:
	void print() const;

	string getFirstName();

	string getLastName();
	
	string getSpecialty() const;

	void setName(string first, string last);

	void setSpecialty(string special);

	doctorType(string first = "", string last = "", string special = "");

private:
	string specialty;
};