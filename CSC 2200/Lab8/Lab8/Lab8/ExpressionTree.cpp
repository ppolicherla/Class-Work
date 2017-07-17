//--------------------------------------------------------------------
//
//  Laboratory 8                                  exprtree.cpp
//
//  
//
//--------------------------------------------------------------------

#ifndef EXPRESSIONTREE_CPP
#define EXPRESSIONTREE_CPP

#include <stdexcept>
#include <iostream>
#include <cctype>

#include "ExpressionTree.h"

//--------------------------------------------------------------------

template <typename DataType>
ExprTree<DataType>::ExprTreeNode:: ExprTreeNode ( char nodeDataItem,
                              ExprTreeNode *leftPtr,
                              ExprTreeNode *rightPtr )

// Creates an expreesion tree node containing data item nodeDataItem,
// left child pointer leftPtr, and right child pointer rightPtr.

{
	dataItem = nodeDataItem;
	left = leftPtr;
	right = rightPtr;

}

//--------------------------------------------------------------------

template <typename DataType>
ExprTree<DataType>:: ExprTree ()

// Creates an empty expression tree. 

{
	root = NULL;
}

//--------------------------------------------------------------------

template <typename DataType>
ExprTree<DataType>:: ~ExprTree ()

// Frees the memory used by an expression tree.

{
	clear();
}

template <typename DataType>
ExprTree<DataType>:: ExprTree ( const ExprTree &source )

// Copy constructor. Creates a copy of valueTree.

{
	ExprTreeNode *temp = source.root;
	copyHelper(temp);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
ExprTree<DataType>& ExprTree<DataType>::operator=(const ExprTree& source) 

// Overloads the assignment operator for any data type.

{
	copyHelper(source.root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>::copyHelper(ExprTreeNode *&p)

// Recursive private helper for the copy constructor and overloaded
// assignment operator. Creates a copy of the subtree pointed to by p, 
// p points to the new subtree.

{
	ExprTreeNode *temp = new ExprTreeNode(p->dataItem, NULL, NULL);
	if ((p->dataItem == '+') || (p->dataItem == '-') || (p->dataItem == '*') || (p->dataItem == '/'))
	{
		ExprTreeNode *l = p->left;
		ExprTreeNode *r = p->right;
		p = temp;
		p->left = l;
		p->right = r;
		copyHelper(l);
		copyHelper(r);
	}
	else
	{
		p = temp;
	}
    
}

//--------------------------------------------------------------------

template <typename DataType>
void ExprTree<DataType>::build() 

// Builds a new expression tree from standard input (cin)

{
	buildHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <>
void ExprTree<float>::buildHelper(ExprTreeNode*& p) 

// Specialized function to help build trees of floats.
// Input is single digit ints or operators.

{
	char symbol;
	cin >> symbol;
		if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		{
			p = new ExprTreeNode(symbol, NULL, NULL);
			ExprTreeNode *l = new ExprTreeNode(NULL, NULL, NULL);
			ExprTreeNode *r = new ExprTreeNode(NULL, NULL, NULL);
			buildHelper(l);
			buildHelper(r);
		}
		else if (symbol == NULL)
		{
			return;
		}
		else
		{
			p = new ExprTreeNode(symbol, NULL, NULL);
		}
}

template <>
void ExprTree<bool>::buildHelper(ExprTreeNode*& p) 

// Specialized function to help build boolean trees.
// Input is 0, 1, or operators.

{
	char symbol;
	cin >> symbol;
	while (symbol != '\n')
	{
		if (symbol == '&' || symbol == '!' || symbol == '|' || symbol == '^')
		{
			p = new ExprTreeNode(symbol, NULL, NULL);
			ExprTreeNode *l = new ExprTreeNode(NULL, NULL, NULL);
			ExprTreeNode *r = new ExprTreeNode(NULL, NULL, NULL);
			buildHelper(l);
			buildHelper(r);
		}
		else
		{
			p = new ExprTreeNode(symbol, NULL, NULL);
		}
	}
}

//--------------------------------------------------------------------

template <typename DataType>
void ExprTree<DataType>::expression() const 

// Public function to print out fully parenthesized expression tree.

{
	exprHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>::exprHelper(ExprTreeNode* p) const 

// Private helper function to print out fully parenthesized expression tree.

{
	if (p != NULL)
	{
		exprHelper(p->left);
		cout << "(" << p->dataItem << ")" << endl;
		exprHelper(p->right);
	}
}

//--------------------------------------------------------------------

template <typename DataType>
DataType ExprTree<DataType>::evaluate() const throw (logic_error) 

// Public function to evaluate an expression tree.

{
	DataType temp;
	if (root == NULL)
	{
		throw logic_error("error");
	}
	else
	{
		temp = evalHelper(root);
	}
	return temp;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <>
float ExprTree<float>::evalHelper(ExprTreeNode* p) const 

// Private helper function to evaluate an expression tree with a float
// result.

{
	float l, r, value;
	if (p->dataItem >= '0'&&p->dataItem <= '9')
	{
		value = float(p->dataItem - '0');
	}
	else
	{
		l = evalHelper(p->left);
		r = evalHelper(p->right);

		switch (p->dataItem)
		{
		case '+':
			value = l + r;
			break;
		case '-':
			value = l - r;
			break;
		case'*':
			value = l*r;
			break;
		case '/':
			value = l / r;
			break;
		default:
			throw logic_error("beep");
			break;
		}
	}
	return value;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <>
bool ExprTree<bool>::evalHelper(ExprTreeNode* p) const 

// Private helper function to evaluate an boolean expression tree with a 
// bool result.

{
	bool l, r, value;
	if (p->dataItem >= '0'&&p->dataItem <= '9')
	{
		value = bool(p->dataItem - '0');
	}
	else
	{
		l = evalHelper(p->left);
		r = evalHelper(p->right);

		switch (p->dataItem)
		{
		case '+':
			value = l + r;
			break;
		case '-':
			value = l - r;
			break;
		case'*':
			value = l*r;
			break;
		case '/':
			value = l / r;
			break;
		default:
			throw logic_error("beep");
			break;
		}
	}
	return value;
}

//--------------------------------------------------------------------

template <typename DataType>
void ExprTree<DataType>:: clear ()

// Removes all the nodes from an expression tree.

{
	clearHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>:: clearHelper ( ExprTreeNode *p )

// Recursive helper for the clear() function. Clears the subtree
// pointed to by p.

{
	if (p != 0)
	{
		clearHelper(p->left);
		clearHelper(p->right);
		delete p;
	}
}

//--------------------------------------------------------------------

template <typename DataType>
void ExprTree<DataType>::commute() 

// Public operator to commute the tree.

{
	commuteHelper(root);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>::commuteHelper(ExprTreeNode* p) 

// Private recursive helper function to commute the tree.

{
	ExprTreeNode* temp;
	if ((p->left != NULL) || (p->right != NULL))
	{
		if (p->left != NULL)
		{
			commuteHelper(p->left);
		}
		if (p->right != NULL)
		{
			commuteHelper(p->left);
		}
		if ((p->dataItem == '+') || (p->dataItem == '-') || (p->dataItem == '*') || (p->dataItem == '/'))
		{
			temp = p->left;
			p->left = p->right;
			p->right = temp;
		}
	}
}

//--------------------------------------------------------------------

template <typename DataType>
bool ExprTree<DataType>::isEquivalent(const ExprTree<DataType>& source) const 

// Public operator to determine whether two expression trees are equivalent.

{
	bool end = false;
	if (this == &source)
	{
		end = true;
	}
	else if ((root == NULL) && (source.root==NULL))
	{
		end = true;
	}
	end = isEquivalentHelper(root, source.root);
	return end;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
bool ExprTree<DataType>::isEquivalentHelper(const ExprTreeNode* x,
					   const ExprTreeNode* y) const

// Private recursive assistant function to determine whether two expression 
// trees are equivalent.

{
	bool end = false;
	if ((x == NULL) || (y == NULL))
	{
		if ((x == NULL) && (y == NULL))
		{
			end = true;
		}
	}
	else if (x->dataItem == y->dataItem)
	{
		end = (isEquivalentHelper(x->left, y->left) && isEquivalentHelper(x->right, y->right));
		if (!end)
		{
			if ((x->dataItem == '+') ||
				(x->dataItem == '*'))
			{
				end = (isEquivalentHelper(x->right, y->left) && isEquivalentHelper(x->left, y->right));
			}
		}
	}
	return end;
}

template <typename DataType>
void ExprTree<DataType>:: showStructure () const

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.

{
    // No isEmpty function in this class. Add a private one if you wish.
    if ( root == 0 )		
       cout << "Empty tree" << endl;
    else
    {
       cout << endl;
       showHelper(root,1);
       cout << endl;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template <typename DataType>
void ExprTree<DataType>:: showHelper ( ExprTreeNode *p, int level ) const

// Recursive helper for the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.

{
     int j;   // Loop counter

     if ( p != 0 )
     {
        showHelper(p->right,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )   // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem;        // Output dataItem
        if ( ( p->left != 0 ) &&          // Output "connector"
             ( p->right != 0 ) )
           cout << "<";
        else if ( p->right != 0 )
           cout << "/";
        else if ( p->left != 0 )
           cout << "\\";
        cout << endl;
        showHelper(p->left,level+1);         // Output left subtree
     }
}

//--------------------------------------------------------------------

#endif		// #ifndef EXPRESSIONTREE_CPP
