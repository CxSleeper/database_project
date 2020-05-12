#include <iostream>
#include<string>

using namespace std;
int SIZE = 50;

class user_records 
{
public:
	string  username, password; // these will eventually go private
	//will eventually turn all functions into class functions
};



void new_user(user_records* usr)
{
	int i = 0;
	char response = 'y' ;
	while (i < SIZE && (response != 'n'&& response != 'N') ) // need to tighten up this function.  I want the loop to account for all input.
	{
		cout << "Enter your new username: ";
		cin >> usr[i].username;
		cout << "Enter your new password: ";
		cin >> usr[i].password;

		cout << "Create another user? \n Press N to exit user creation: ";
		cin >> response;
		i++;
	}
	//want this functioon to write to a doc file to remember data beyond program execution, it should append and not erase, it should also
	//check for duplicate users, password duplicates are okay.
}
bool is_valid_credentials(const user_records *usr)
{
	//want this function to read from an array that has been intialized with data from a doc file.
	int i = 0;
	string usr_check, pswd_check;
	cout << "Enter your user name: ";
	cin >> usr_check;
	cout << "Enter your password: ";
	cin >> pswd_check;
	for (i = 0; i < SIZE; i++)
	{// is there a way to accept case flaws when entering a user name?
		if (usr_check == usr[i].username) // these embedded loops will prevent someone from knowing if they got a user name right.
		{
			if (pswd_check == usr[i].password)
			{
				return true;
			}
		}
	}
	return false;
}



int main()
{
	user_records usr[50]; // end goal is using dynamic memory

	/*cout << "Enter your username: ";
	cin >> username;
	cout << "Enter Your password: ";
	cin >> password;*/
	 

	new_user(usr); // will create a condition asking user if they are new

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
