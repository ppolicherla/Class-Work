
#include "Text.h"
#include <string>

Text::Text ( const char *charSeq )
{
	bufferSize = strlen(charSeq) + 1;

	buffer = new char[bufferSize];

	strcpy(buffer, charSeq);
}

Text::Text ( const Text &other )
{
	bufferSize = other.getLength() + 1;

	buffer = new char[bufferSize];

	strcpy(buffer, other.buffer);
}

void Text::operator = ( const Text &other )
{
	if (&other != this)
	{
		if (bufferSize != (other.getLength() + 1))
		{
			delete[] buffer;
			bufferSize = other.getLength() + 1;
			buffer = new char[bufferSize];
		}

		strcpy(buffer, other.buffer);
	}
}

Text::~Text ()
{
	delete[] buffer;
}

int Text::getLength () const
{
	return bufferSize-1;
}

char Text::operator [] ( int n ) const
{
	if (n >= 0 && n<bufferSize)
	{
		return *(buffer + n);
	}

	else
	{
		return '\0';
	}
}

void Text::clear ()
{
	for (int i = 0; i<bufferSize; i++)
	{
		buffer[i] = '\0';
	}
	bufferSize = 1;
}

void Text::showStructure () const
{
	for (int i = 0; i<bufferSize - 1; i++)
	{
		cout << buffer[i];
	}

	cout << endl;
}

Text Text::toUpper( ) const
{
	Text textCopy(*this);

	for (int i = 0; i<bufferSize; i++)
	{
		if (textCopy.buffer[i]>96 && textCopy.buffer[i]<123)
			textCopy.buffer[i] -= 32;
	}

	return textCopy;
	
}

Text Text::toLower( ) const
{
	Text textCopy(*this);

	for (int i = 0; i<textCopy.bufferSize; i++)
	{
		if (textCopy.buffer[i]>64 && textCopy.buffer[i]<91)
			textCopy.buffer[i] += 32;
	}

	return textCopy;
}

bool Text::operator == ( const Text& other ) const
{
	if (strcmp((*this).buffer, other.buffer) == 0)
	{
		return true;
	}
	return false;
}

bool Text::operator <  ( const Text& other ) const
{
	if (strcmp((*this).buffer, other.buffer) < 0)
	{
		return true;
	}
	return false;
}

bool Text::operator >  ( const Text& other ) const
{
	if (strcmp((*this).buffer, other.buffer) > 0)
	{
		return true;
	}
	return false;
}