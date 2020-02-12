#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;
struct subscriber
{
char phonenumber[20];
char name[50];
float amount;
}s;
void addrecords();
void listrecords();
void modifyrecords();
void deleterecords();
void searchrecords();
void payment();
char get;
int main()
{	int password;
	int phonenumber;
	char choice;
	system("cls");
	printf("\n\t\t*************************************************************");
	printf("  \n\t\t---WELCOME TO THE TELEPHONE BILLING MANAGEMENT SYSTEM---");
	printf("\n\t\t*************************************************************");
	Sleep(200);
	getch();
    system("cls");
	while (1)
	{
		system("cls");
		cout<<endl<<"Enter your choices : "<<endl;
		cout<<"A : for adding new records."<<endl;
		cout<<"L : for list of records."<<endl;
		cout<<"M : for modifying records."<<endl;
		cout<<"P : for payment."<<endl;
		cout<<"S : for searching records."<<endl;
		cout<<"D : for deleting records."<<endl;
		cout<<"E : for exit."<<endl;
		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
			case 'P':
				payment();break;
			case 'A':
				addrecords();break;
			case 'L':
				listrecords();break;
			case 'M':
				modifyrecords();break;
			case 'S':
				searchrecords();break;
			case 'D':
				deleterecords();break;
			case 'E':
				system("cls");
				printf("\n\n\t\t\t\t\tTHANK YOU\n");
				printf("\t\t\t\tFOR USING OUR SERVICE\n\n\n");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				cout<<"Incorrect Input"<<endl;
				cout<<"Press Any key to continue"<<endl;
				getch();
		}
	}
}
void addrecords()
{
	FILE *f;
	char test;
	f=fopen("c:/file2.ojs","ab+");
	if(f==0)
	{   f=fopen("c:/file2.ojs","wb+");
		system("cls");
		cout<<"please wait while we configure your computer"<<endl;
		cout<<"/nPress any key to continue"<<endl;
		getch();
	}
	while(1)
	{
		system("cls");
		cout<<"\n Enter phone number:";
		scanf("%s",&s.phonenumber);
		cout<<"\n Enter name:";
		fflush(stdin);
		scanf("%[^\n]",&s.name);
		cout<<"\n Enter amount:";
		scanf("%f",&s.amount);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		cout<<"1 record successfully added";Press Any key to continue
		cout<<"\n Press esc key to exit,press any other key to add other record:";
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}
void listrecords()
{
	FILE *f;
	int i;
	if((f=fopen("c:/file2.ojs","rb"))==NULL)
		exit(0);
	system("cls");
	cout<<"Phone Number\t\tUser Name\t\t\tAmount\n";
	for(i=0;i<79;i++)
		cout<<"-";
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%-10s\t\t%-20s\t\tBDT. %.2f /-",s.phonenumber,s.name,s.amount);
	}
	cout<<endl;
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}
void deleterecords()
{
	FILE *f,*t;
	int i=1;
	char phonenumber[20];
	if((t=fopen("c:/temp2.ojs","w+"))==NULL)
	exit(0);
	if((f=fopen("c:/file2.ojs","rb"))==NULL)
	exit(0);
	system("cls");
	cout<<"Enter the phone number to be deleted from the Database";
	fflush(stdin);
	scanf("%[^\n]",phonenumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{       i=0;
			continue;

		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)
	{       system("cls");
		printf("Phone number \"%s\" not found",phonenumber);
		remove("c:/file2.ojs");
		rename("c:/temp2.ojs","c:/file2.ojs");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	remove("c:/file2.ojs");
	rename("c:/temp2.ojs","c:/file2.ojs");
	system("cls");
	printf("The Number %s Successfully Deleted!!!!",phonenumber);
	fclose(f);
	fclose(t);
	getch();
}
void searchrecords()
{
	FILE *f;
	char phonenumber[20];
	int flag=1;
	f=fopen("c:/file2.ojs","rb+");
	if(f==0)
		exit(0);
	fflush(stdin);
	system("cls");
	cout<<"Enter Phone Number to search in our database";
	scanf("%s", phonenumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{	system("cls");
			cout<<" Record Found ";
			printf("\n\nPhonenumber: %s\nName: %s\nAmount: BDT.%0.2f\n",s.phonenumber,s.name,s.amount);
			flag=0;
			break;
		}
		else if(flag==1)
		{	system("cls");
			printf("Requested Phone Number Not found in our database");
		}
	}
	getch();
	fclose(f);
}
void modifyrecords()
{
	FILE *f;
	char phonenumber[20];
	long int size=sizeof(s);
	if((f=fopen("c:/file2.ojs","rb+"))==NULL)
		exit(0);
	system("cls");
	cout<<"Enter phone number of the subscriber to modify:";
	scanf("%[^\n]",phonenumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{
			system("cls");
			cout<<"\n Enter phone number:";
			scanf("%s",&s.phonenumber);
			cout<<"\n Enter name: ";
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			cout<<"\n Enter amount: ";
			scanf("%f",&s.amount);
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	fclose(f);
}
void payment()
{
	FILE *f;
	char phonenumber[20];
	long int size=sizeof(s);
	float amt;
	int i;
	if((f=fopen("c:/file2.ojs","rb+"))==NULL)
		exit(0);
	system("cls");
	cout<<"Enter phone number of the subscriber for payment";
	scanf("%[^\n]",phonenumber);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.phonenumber,phonenumber)==0)
		{
			system("cls");
			printf("\n Phone No: %s",s.phonenumber);
			printf("\n Name: %s",s.name);
			printf("\n Current amount: %f",s.amount);
			cout<<endl;
			for(i=0;i<79;i++)
				printf("-");
			printf("\n\nEnter amount of payment :");
			fflush(stdin);
			scanf(" %f",&amt);
			s.amount=s.amount-amt;
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	system("cls");
	printf("THANK YOU %s FOR YOUR TIMELY PAYMENTS",s.name);
	getch();
	fclose(f);
}

