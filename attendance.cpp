#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

vector<string> username;
vector<string> password;
vector<int> attend;
auto idx;

int studentLogin();
int adminLogin();
int studentView();
int adminView();
int registerStudent();
int markMyAttendance(string username);
int checkCredentials(string userName, string password);
int delay();


int registerStudent()
{
    cout<<"\n ----- Form to Register Student ---- \n";	

    string name, username, password, rollno, address, father, mother;
    
    cout<<"\n Enter Name : ";     cin>>name;
    cout<<"\n Enter Username : ";     cin>>username;
    cout<<"\n Enter password : ";     cin>>password;
    cout<<"\n Enter rollno : ";     cin>>rollno;
    getchar();
    
    char add[100];
    cout<<"\n Enter address : ";     cin.getline(add, 100);
    cout<<"\n Enter father : ";     cin>>father;
    cout<<"\n Enter mother : ";     cin>>mother;
    
    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {   int recordFound =0; 
	   string line;
	    while(getline(read, line)) {
    	if(line == username+".dat" )
    	{
    		recordFound = 1 ;
    	    break;
		}
        }
        if(recordFound == 1)
        {
    	cout<<"\n Username already Register. Please choose another username ";
    	getchar(); getchar();
    	delay();
    	read.close();
    	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();

	ofstream out1;
	string temp = username+".dat";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username<<"\n"; 	out1<<password<<"\n";
	out1<<rollno<<"\n"; 	out1<<add<<"\n"; 	out1<<father<<"\n";
	out1<<mother<<"\n";
	out1.close();

	cout<<"\n Student Registered Successfully !!";
    
    cout<<"\n Please any key to continue..";
	getchar(); getchar();
	return 0;		
}

void delay()
{
cout<<"\n SAVING...";
for(int i=0; i<3; i++){
    for(int j=0; j<20000; j++){
    	for(int k=0; k<20000; k++){
		}
    }
}  
cout<<"\n EXITING...";
for(int i=0; i<3; i++){
   for(int j= 0; j<20000; j++) { 
     for(int k=0; k<20000; k++){
	}
	}
	}
}

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
cout<<"\n Press any key for Main Menu";
getchar();
getchar();
}
return 0;
}

int studentView()
{	
string uname, pass;
cout<<"\n Enter username -";
cin>>uname;

cout<<"\n Enter password -";
cin>>pass;

int res = checkCredentials(uname, pass);

if(res  == 0)
{
   cout<<"\n Error! Invalid Credentials!";
   cout<<"\n Press any key for Main Menu";
   getchar(); getchar();	
   return 0;
} 
int goBack = 0;
do{
system("cls");
cout<<"\n ENTER 1 - Mark Attendance for today \n 2 - Count my Attendance till date \n 3 - Return";
cout<<"ENTER YOUR CHOICE";
int choice;
cin>>choice;
switch(choice)
{
	case 1: markMyAttendance(username);
	break;
	case 2: countMyAttendance(username);
	break;
	case 0: goBack = 1;
	break;
    default: cout<<"\n Invalid choice entered. Try again.";
    getchar();           	
}   
}
while(goBack == 0) 
}

int adminView()
{	
int goBack = 0;
while(1)
{
system("cls");
cout<<"\n ENTER 0 - Return back \n 1 - Register a Student \n 2 - Delete all students name that are registered \n 3 - Delete a student through rollno \n 4 - Check list of students registered by userame \n 5 - Check present attendance of any student through rollno \n 6 - Get complete list of students with their attendance";
int choice;

cout<<"ENTER YOUR CHOICE";
cin>>choice;

switch(choice)
{
	case 1: registerStudent();
	break;  
	case 2: deleteAllStudents();
	break;
	case 3: deleteStudentbyRollno();
	break;
	case 4: checkListOfStudentsRegistered();
	break;
	case 5: checkPresenseCountbyRollno();
	break;
	case 6: getListOfStudentsWithTheirPresenseCount();
	break;
	case 0: goBack = 1;
	break;
    default: cout<<"\n Invalid choice entered. Try again.";
    getchar();           	
}   
if(goBack == 1)
{
break;
}     
}
return 0;
}

int checkCredentials(string uname, string pass)
{
	int i;
	auto it = find(username.begin(),username.end(),uname)
	if(it == username.end())
	return 0;
	else
	{
		if(password[it - password.begin()] != pass)
		return 0;
		else
		{
			idx = it - password.begin();
			return 1;
		}
	}  		
}

int markMyAttendance(string username)
{
attend[idx]++;
cout<<"\n Marked Attendance for today";	
cout<<"\n Press any key to continue.";
getchar();
return 0;	
} 


int main() {
	
while(1)
{
	system("cls");
	cout<<"\n ATTENDANCE MANAGEMENT SYSTEM \n";
	char ex;
	do{
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
		    system("cls");
        	cout<<"\n Are you sure, you want to exit? Press y for yes or n for no \n";
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
               break;
            else{
             	cout<<"\n Invalid choice entered.";
             	getchar();
			}
            break;   	 
    default: cout<<"\n Invalid choice entered. Try again.";
	}
	while(ex == 'n' || ex == 'N')
	}   		        

}	
return 0;
} 