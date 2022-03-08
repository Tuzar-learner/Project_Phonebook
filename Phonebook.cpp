#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int mobno;
class mobile_sim
	{
int balance;
int phno;
char service_provider[10];
public:
mobile_sim()
		{
balance=0;
phno=999999999;
strcpy(service_provider,"Unknown");
		}
void getdata()
		{
cout<<"Enter your phone number (8 digits only) : ";
cin>>phno;
begin:
if(phno>=100000000)
			{
cout<<"\nThe phone number is longer than 8 digits";
cout<<"\nPlease re-enter your phone number : ";
cin>>phno;
goto begin;
			}
if(phno<10000000)
{
cout<<"\nThe phone number is lesser than 8 digits";
cout<<"\nPlease re-enter your phone number : ";
cin>>phno;
goto begin;
}
cout<<"Enter your balance : ";
cin>>balance;
th:
cout<<"Enter the service provider : \n";
cout<<"Available service providers are : \n";
cout<<"1 for jio\n";
cout<<"2 for airtel\n";
cout<<"3 for idea\n";
cout<<"4 for vodofone\n";
cout<<"5 for bsnl\n";
cout<<"Enter your choice : ";
int cho;
cin>>cho;
switch(cho)
{
case 1:
{
strcpy(service_provider,"jio");
break;
}
case 2:
{
strcpy(service_provider,"airtel");
break;
}
case 3:
{
strcpy(service_provider,"idea");
break;
}
case 4:
{
strcpy(service_provider,"vodofone");
break;
}
case 5:
{
strcpy(service_provider,"bsnl");
break;
default:
cout<<"\nWrong Choice Re-";
goto th;
}
}
}
int retbalance()
{
return(balance);
}
int retphno()
{
return(phno);
}
void disp()
{
cout<<"\n\nPhone number : "<<phno;
cout<<"\nBalance : "<<balance;
cout<<"\nService Provider : ";
puts(service_provider);
}
}s;
fstream fp;
void search()
{
fp.open("mobile_sim.dat",ios::in|ios::binary);
int f=0,r;
cout<<"Enter the phone number to be searched : ";
cin>>r;
fp.read((char*)&s,sizeof(s));
while(!fp.eof())
{
if(r==s.retphno())
{
cout<<"\nRecord found\n";
s.disp();
f=0;
break;
}
else
{
f=1;
}
if(f==1)
{
cout<<"Record not found";
break;
}
fp.close();
}
}
void searchbal()
{
fp.open("mobile_sim.dat",ios::in|ios::binary);
int f=0,r;
cout<<"Enter the balance to be searched : ";
cin>>r;
fp.read((char*)&s,sizeof(s));
while(!fp.eof())
{
if(r==s.retbalance())
{
cout<<"\nRecord found\n";
s.disp();
f=0;
break;
}
else
{
f=1;
}
if(f==1)
{
cout<<"Record not found";
break;
}
fp.close();
}
}
int create()
{
fp.open("mobile_sim.dat",ios::out|ios::binary);
cout<<"Enter the number of times that the data to be read : ";
cin>>mobno;
for(int i=1;i<=mobno;i++)
{
s.getdata();
fp.write((char*)&s,sizeof(s));
}
return(mobno);
fp.close();
}
void display()
{
fp.open("mobile_sim.dat",ios::in|ios::binary);
if(mobno==0)
{
cout<<"\nNo data is entered\n";
}
for(int i=1;i<=mobno;i++)
{
fp.read((char*)&s,sizeof(s));
s.disp();
fp.close();
}
}
void append()
{
fp.open("mobile_sim.dat",ios::app|ios::binary);
s.getdata();
fp.write((char*)&s,sizeof(s));
fp.close();
mobno++;
}
void main()
{
int ab;
char ch,c;
do
{
cout<<"\n________________________________________________________________________";
cout<<"\n________________________PROJECT_:_MOBILE_BILLING________________________\n\n";
cout<<"                           WELCOME_TO_MY_PROGRAM\n\n";
cout<<"Press 1 to 'READ' data\n";
cout<<"Press 2 to 'APPEND' data\n";
cout<<"Press 3 to 'SEARCH' data\n";
cout<<"Press 4 to 'DELETE' data\n";
cout<<"Press 5 to 'DISPLAY' data\n\n";
thu:
cout<<"Enter your choice : ";
cin>>ab;
switch(ab)
{
case 1:
{
create();
cout<<"\n\nYour data is entered.";
break;
}
case 2:
{
append();
break;
}
case 3:
{
cout<<"\n\tPress a to search a particular number\n";
cout<<"\tPress b to search balance\n";
cout<<"\nEnter your choice : ";
cin>>c;
cout<<endl;
if(c=='a')
{
search();
}
if(c=='b')
{
searchbal();
}
break;
}
//Case 4 Delete option will be added
case 5:
{
display();
break;
}
default:
cout<<"Wrong Choice. Re-";
goto thu;
}
cout<<"\nDo you want to continue the program (y/n) : ";
cin>>ch;
}
while(ch!='n');
getch();
}
