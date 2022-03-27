#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

vector<string> username;
vector<string> password;
vector<int> attend;
vector<int> rollno;
auto idx;

int studentLogin();
int adminLogin();
int studentView();
int adminView();
int registerStudent();
void markMyAttendance();
void countMyAttendance();
int checkCredentials(string userName, string password);
int delay();
void getListOfStudentsWithTheirCount();
void checkCountbyRollno(int roll);
void checkListOfStudentsRegistered();
void deleteStudentbyRollno(roll);


int registerStudent()
{
    cout<<"\n --- Form to Register Student --- \n";	

    string name, uname, pass, address, father, mother;
	int roll,j,k;
    cout<<"\n Enter Name of the student :";
	cin>>name;
    cout<<"\n Enter username : ";
	cin>>uname;
    cout<<"\n Enter password : ";
	cin>>pass;
    cout<<"\n Enter rollno : ";
	cin>>roll;
    cout<<"\n Enter your address : ";
	cin>>address;
    cout<<"\n Enter your father's name : ";
	cin>>father;
    cout<<"\n Enter your mother's name : ";
	cin>>mother;
	j = count(username.begin(),username.end(),uname);
	while(j!=0)
	{
	cout<<"Username already registered. Please choose another username"<<endl;
	cout<<"Enter a new username :\n";
	cin>>uname;
	j = count(username.begin(),username.end(),uname);
	}
	k = count(rollno.begin(),rollno.end(),roll);
    while(k!=0)
	{
	cout<<"This Roll Number is already assigned to a different user. Please choose another Roll Number"<<endl;
	cout<<"Enter a new Roll Number\n";
	cin>>roll;
	k = count(rollno.begin(),rollno.end(),roll);
	}
	username.push_back(uname);
	password.push_back(pass);
	attend.push_back(0);
	rollno.push_back(roll);
	cout<<"\n Student Registered Successfully!";
    cout<<"\n Press any key to continue.";
	getchar();		
	return roll;
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
	case 1: markMyAttendance();
	break;
	case 2: countMyAttendance();
	break;
	case 3: goBack = 1;
	break;
    default: cout<<"\n Invalid choice entered. Try again.";
    getchar();           	
}   
}
while(goBack == 0) 
}

int adminView()
{	
int roll,goBack = 0;
do
{
system("cls");
cout<<"\n ENTER 0 - Return back \n 1 - Register a Student \n 2 - Delete all students name that are registered \n 3 - Delete a student through rollno \n 4 - Check list of students registered by userame \n 5 - Check present attendance of any student through rollno \n 6 - Get complete list of students with their attendance";
int choice;
cout<<"ENTER YOUR CHOICE";
cin>>choice;
switch(choice)
{
	case 1: roll = registerStudent();
	break;  
	case 2: deleteAllStudents();
	break;
	case 3: deleteStudentbyRollno(roll);
	break;
	case 4: checkListOfStudentsRegistered();
	break;
	case 5: checkCountbyRollno(roll);
	break;
	case 6: getListOfStudentsWithTheirCount();
	break;
	case 0: goBack = 1;
	break;
    default: cout<<"\n Invalid choice entered. Try again.";
    getchar(); 
} while (goBack == 0);
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

void markMyAttendance()
{
attend[idx]++;
cout<<"\n Marked Attendance for today";	
cout<<"\n Press any key to continue.";
getchar();
} 

void countMyAttendance()
{
cout<<"\n Attendance till date is - "<<attend[idx];	
cout<<"\n Press any key to continue.";
getchar();	
} 

void getListOfStudentsWithTheirCount()
{
cout<<"\n All Students with their count -\n";
int i,n=attend.size();
for(i=0;i<n;i++)
{
	cout<<attend[i]<<endl;
}
cout<<"\n Press any key to continue.";
getchar();
}

void checkCountbyRollno(int roll)
{
cout<<"\n Attendance of the student with the given Roll Number is:\n";
int i,n=rollno.size();
for(i=0;i<n;i++)
{
	if(roll == rollno[i])
	break;
}
cout<<attend[i]<<endl;		
cout<<"\n Press any key to continue.";
getchar();
}

void checkListOfStudentsRegistered()
{
cout<<"\n List of all students registered";
int i,n = username.size();
for(i=0;i<n;i++)
{
	cout<<username[i]<<" "<<password[i]<<" "<<rollno[i]<<endl;
}
cout<<"\n Press any key to continue.";
getchar();
}

void deleteStudentbyRollno(int roll)
{
int i,j,n=rollno.size();
for(i=0;i<n;i++)
{
	if(roll == rollno[i])
	break;
}
for(j=i;j<(n-1);j++)
{
	username[j] = username[j+1];
	password[j] = password[j+1];
	attend[j] = attend[j+1];
	rollno[j] = rollno[j+1];
}
cout<<"\n Entry successfully deleted. \n";		
cout<<"\n Press any key to continue.";
getchar();
}

int main() {
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
return 0;
} 