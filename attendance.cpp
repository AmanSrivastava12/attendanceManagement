#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int studentLogin();
int adminLogin();

int studentLogin()
{
system("cls");
cout<<"\n STUDENT LOGIN --";	
studentView();
delay();
return 0; 
}


int adminLogin()
{
system("cls");
cout<<"\n ADMIN LOGIN --";	

string username;
string password;

cout<<"\n Enter username -";
cin>>username;
cout<<"\n Enter password -";
cin>>password;

if(username=="admin" && password=="admin@2") 
{
    adminView();
    getchar();	
    delay();
}   
else
{
cout<<"\n Error! Invalid Credentials!";	
cout<<"\n Press any key for main menu ";
getchar();getchar();
}

return 0;
}


int main() {
	
while(1)
{
	system("cls");
	cout<<"\n ATTENDANCE MANAGEMENT SYSTEM \n";
	
	cout<<"ENTER 1 - STUDENT LOGIN \n 2 - ADMIN LOGIN \n 3 - EXIT \n";
	int choice;
	cout<<"ENTER YOUR CHOICE";
	cin>>choice;
	switch(choice)
	{
	case 1: studentLogin();
	break;
	case 2: adminLogin();
	break;
	case 3: 
	        while(1)
	        {
		    system("cls");
        	cout<<"\n Are you sure, you want to exit? Press y for yes or n for no \n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
             {
             	break;
             }
             else{
             	cout<<"\n Invalid choice entered.";
             	getchar();
             }

     	   }
            break;
             	 
    default: cout<<"\n Invalid choice entered. Try again.";
    getchar();
	}   		        

}	
return 0;
} 