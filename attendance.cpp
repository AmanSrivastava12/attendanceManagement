#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;

string username[100]={""};
string password[100]={""};
int attend[100]={0};
int rollno[100]={-1};
int idx;
int counter=0;

void studentLogin();
void adminLogin();
void studentView();
void adminView();
int registerStudent();
void markMyAttendance();
void countMyAttendance();
int checkCredentials(string uname, string pass);
void delay();
void getListOfStudentsWithTheirCount();
void checkCountbyRollno(int roll);
void checkListOfStudentsRegistered();
void deleteStudentbyRollno(int roll);
void deleteAllStudents();

int registerStudent()
{
    cout<<"\n --- Form to Register Student --- \n";	
    string name, uname, pass, address, father, mother;
	int roll,j=0,k=0,i;
    cout<<"\nEnter Name of the student (only first name) : ";
	cin>>name;
    cout<<"\nEnter username : ";
	cin>>uname;
    cout<<"\nEnter password : ";
	cin>>pass;
    cout<<"\nEnter rollno : ";
	cin>>roll;
    cout<<"\nEnter your address (only city) : ";
	cin>>address;
    cout<<"\nEnter your father's name (only first name) : ";
	cin>>father;
    cout<<"\nEnter your mother's name (only first name) : ";
	cin>>mother;
	for(i=0;i<counter;i++)
	{
		if(uname==username[i])
		{
		j=1;
		break;
		}
	}
	while(j!=0)
	{
	j=0;
	cout<<"\nUsername already registered. Please choose another username."<<endl;
	cout<<"\nEnter a new username :\n";
	cin>>uname;
	for(i=0;i<counter;i++)
	{
		if(uname==username[i])
		{
		j=1;
		break;
		}
	}
	}
	for(i=0;i<counter;i++)
	{
		if(roll==rollno[i])
		{
		k=1;
		break;
		}
	}
    while(k!=0)
	{
	k=0;
	cout<<"This Roll Number is already assigned to a different user. Please choose another Roll Number.\n"<<endl;
	cout<<"Enter a new Roll Number : \n";
	cin>>roll;
	for(i=0;i<counter;i++)
	{
		if(roll==rollno[i])
		{
		k=1;
		break;
		}
	}
	}
	username[counter]=uname;
	password[counter]=pass;
	attend[counter]=0;
	rollno[counter]=roll;
	counter++;
	cout<<"\nStudent Registered Successfully!";
    cout<<"\nPress any key to continue.";
	getch();		
	return roll;
}

void delay()
{
cout<<"\nSAVING...";
for(int i=0; i<3; i++){
    for(int j=0; j<20000; j++){
    	for(int k=0; k<20000; k++){
		}
    }
}  
cout<<"\nEXITING...";
for(int i=0; i<3; i++){
   for(int j= 0; j<20000; j++) { 
     for(int k=0; k<20000; k++){
	}
	}
	}
}

int checkCredentials(string uname, string pass)
{
	int i,j=-1;
	for(i=0;i<counter;i++)
	{
		if(username[i]==uname)
		j=i;
	}
	if(j==-1)
	return 0;
	else
	{
		if(password[j] != pass)
		return 0;
		else
		{
			idx = j;
			return 1;
		}
	}  		
}

void markMyAttendance()
{
attend[idx]++;
cout<<"\nMarked Attendance for today";	
cout<<"\nPress any key to continue.";
getch();
} 

void countMyAttendance()
{
cout<<"\nAttendance till date is - "<<attend[idx];	
cout<<"\nPress any key to continue.";
getch();	
} 

void studentView()
{	
string uname, pass;
cout<<"\nEnter username - ";
cin>>uname;
cout<<"Enter password - ";
cin>>pass;
int res = checkCredentials(uname, pass);
if(counter==0)
{
	cout<<"\nNo students registered till now.\n";
	return;
}
if(res == 0)
{
   cout<<"\nError! Invalid Credentials!";
   cout<<"\nPress any key for Main Menu.\n";
   getch();
   return;
} 
int goBack = 0;
do{
system("cls");
cout<<"\n1 - Mark Attendance for today \n2 - Count my Attendance till date \n3 - Return\n";
cout<<"\nENTER YOUR CHOICE : ";
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
    default: cout<<"\nInvalid choice entered. Try again.";
    getch();           	
}   
} while(goBack == 0);
return;
}

void studentLogin()
{
system("cls");
cout<<"\nSTUDENT LOGIN -\n";	
studentView();
delay();
getch;
cout<<"\n\n";
return;
}

void getListOfStudentsWithTheirCount()
{
if(counter==0)
{
	cout<<"\nNo student data present to display.\n";
	getch();
	return;
}
cout<<"\nAll Students with their count -\n";
int i;
for(i=0;i<counter;i++)
{
	cout<<username[i]<<" "<<attend[i]<<endl;
}
cout<<"\nPress any key to continue.";
getch();
}

void checkCountbyRollno(int roll)
{
int i;
for(i=0;i<counter;i++)
{
	if(roll == rollno[i])
	break;
}
if(i==counter)
{
	cout<<"\nNo student present with the given roll number.\n";
	getch();
	return;
}
cout<<"\nAttendance of the student with the given Roll Number is:\n";
cout<<attend[i]<<endl;		
cout<<"\nPress any key to continue.";
getch();
}

void checkListOfStudentsRegistered()
{
if(counter==0)
{
	cout<<"\nNo student data present to display.\n";
	getch();
    return;
}
cout<<"\nList of all students registered -\n";
int i;
for(i=0;i<counter;i++)
{
	cout<<username[i]<<" "<<rollno[i]<<endl;
}
cout<<"\nPress any key to continue.";
getch();
}

void deleteStudentbyRollno(int roll)
{
int i,j;
for(i=0;i<counter;i++)
{
	if(roll == rollno[i])
	break;
}
if(i==counter)
{
	cout<<"\nNo student present with the entered roll number.\n";
	getch();
	return;
}
for(j=i;j<counter-1;j++)
{
	username[j] = username[j+1];
	password[j] = password[j+1];
	attend[j] = attend[j+1];
	rollno[j] = rollno[j+1];
}
counter--;
cout<<"\nEntry successfully deleted. \n";		
cout<<"\nPress any key to continue.";
getch();
}

void deleteAllStudents()
{
int i;
if(counter==0)
{
	cout<<"\nNo student data present to delete.\n";
	getch();
	return;
}
for(i=0;i<counter;i++)
{
	username[i]="";
	password[i]="";
	attend[i]=0;
	rollno[i]=-1;
}
counter=0;
cout<<"\nSuccessfully Deleted all students!";
cout<<"\nPress any key to continue.";
getch();
}

void adminView()
{	
int roll,goBack = 0;
do
{
system("cls");
cout<<"\n0 - Return back \n1 - Register a Student \n2 - Delete all students that are registered \n3 - Delete a student through rollno \n4 - Display list of students registered by userame \n5 - Check present attendance of any student through rollno \n6 - Get complete list of students with their attendance\n";
int choice;
cout<<"\nENTER YOUR CHOICE : ";
cin>>choice;
switch(choice)
{
	case 1: roll = registerStudent();
	break;  
	case 2: deleteAllStudents();
	break;
	case 3: cout<<"\nEnter the roll number - ";
	cin>>roll;
	deleteStudentbyRollno(roll);
	break;
	case 4: checkListOfStudentsRegistered();
	break;
	case 5: cout<<"\nEnter the roll number - ";
	cin>>roll;
	checkCountbyRollno(roll);
	break;
	case 6: getListOfStudentsWithTheirCount();
	break;
	case 0: goBack = 1;
	break;
    default: cout<<"\nInvalid choice entered. Try again.";
    getch();
} 
} while (goBack == 0);
return;
}

void adminLogin()
{
system("cls");
cout<<"\nADMIN LOGIN -\n";	
string uname;
string pass;
cout<<"\nEnter username - ";
cin>>uname;
cout<<"Enter password - ";
cin>>pass;
if(uname=="admin" && pass=="amansrivastava12") 
{
    adminView();	
    delay();
	getch();
	cout<<"\n\n";
}   
else
{
cout<<"\nError! Invalid Credentials!";	
cout<<"\nPress any key for Main Menu.";
getch();
}
return;
}

int main()
{
	system("cls");
	cout<<"\n ATTENDANCE MANAGEMENT SYSTEM \n\n";
	char ex='n';
	do{
	cout<<"1 - STUDENT LOGIN \n2 - ADMIN LOGIN \n3 - EXIT \n\n";
	int choice;
	cout<<"ENTER YOUR CHOICE : ";
	cin>>choice;
	switch(choice)
	{
	case 1: studentLogin();
	break;
	case 2: adminLogin();
	break;
	case 3: 
		    system("cls");
        	cout<<"\nAre you sure, you want to exit? Press y for yes or n for no \n";
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
               break;
            else
			{
             	cout<<"\nInvalid choice entered.";
             	getch();
			}
            break;   	 
    default: cout<<"\nInvalid choice entered. Try again.";
	}
	} while(ex == 'n' || ex == 'N'); 		        
return 0;
} 