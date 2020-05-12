#include <iostream>
#include<string>

using namespace std;
int SIZE = 50;

class user_records 
{
public:
	string  username, password; // these will eventually go private
	//will eventually turn all functions into class functions
	class user_records *left;
	class user_records *right;
};

typedef class user_records node;

node *start = NULL;

node *getnode()
{
	node *newnode;
	newnode = new node[sizeof(node)]
	cout << "Enter new username: \n";
	cin >> newnode->username;
	cout << "Enter password: \n"
	cin>> newnode->password;
	newnode->right = NULL;
	newnode->left = NULL;
	return newnode;
}

void new_user()
{
	node *newnode;
	node *temp;

	newnode = getnode();
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		temp = start;
		while(temp->right != NULL)
		{
			temp = temp->right;
			temp->right = newnode;
			newnode->left = temp;
		}
	}
	//want this functioon to write to a doc file to remember data beyond program execution, it should append and not erase, it should also
	//check for duplicate users, password duplicates are okay.
}
bool is_valid_credentials()
{
	//want this function to read from an array that has been intialized with data from a doc file.
	int i = 0;
	node *temp = start;
	string usr_check, pswd_check;
	cout << "Enter your user name: ";
	cin >> usr_check;
	cout << "Enter your password: ";
	cin >> pswd_check;
	do
	{
		temp = temp->right;
		if(usr_check == temp->username)
		{
			if(pswd_check == temp->password)
			{
				return true;
			}
		}
	}
	while(temp->right != NULL);
	
	return false;
}



int main()
{
	/* user_records usr[50]; Changed from array to double linked list.*/ 

	/*cout << "Enter your username: ";
	cin >> username;
	cout << "Enter Your password: ";
	cin >> password;*/
	 

	new_user(); // will create a condition asking user if they are new

	if (is_valid_credentials(usr))
	{
		cout << "Access Granted" << endl;
	}
	else
	{
		cout << "Access Denied" << endl;
	}

	return 0;
}
