/*
 ============================================================================
 Name        : Sports.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct date
{
	int day,month,year;
};
struct record
{
	struct date d;
	int regno;
	char name[20];
	char sport[20];
	char owner[20];
	char mobile[13];
	int flag;
};
void input(struct record[],int);
void display(struct record);
int search(struct record[],int);
void delete(struct record[],int,int);
void modify(struct record[],int);

int i,flag;
int main(void)
{
	static int recno;
	int choice,cont,pos,conf;
	struct record data[20];
	do
		{
		puts("\nMENU:\n1.Input New Record\n2.Display Records\n3.Search\n4.Delete\n5.Modify\n6.Exit");
		fflush(0);
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:
					input(data,recno);
					data[recno].regno=(recno+100);
					recno++;
					puts("To continue press 1 else 0");
					scanf("%d",&cont);
				break;
			case 2:
				if(recno==0)
					printf("No records Entered!");
				else
				{
					printf("\nReg. No.\tReg. Date\t\tName\t\tSport\t\tOwner\t\tMobile");
					for(i=0;i<recno;i++)
						display(data[i]);
				}
				puts("\nTo continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 3:
				if(recno==0)
					printf("No records Entered!");
				else
				{
					pos=search(data,recno);
					if(pos!=-1)
					{
						printf("Record Found!\n");
						printf("\nReg. No.\tReg. Date\t\tName\t\tSport\t\tOwner\t\tMobile");
						display(data[pos]);
					}
					else
						printf("Record not Found!!\n");
				}
				puts("\nTo continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 4:
				if(recno==0)
					printf("No records Entered!");
				else
				{
					pos=search(data,recno);
					if(pos!=-1)
					{
						printf("\nReg. No.\tReg. Date\t\tName\t\tSport\t\tOwner\t\tMobile");
						display(data[pos]);
						printf("\n---Enter 1 to confirm delete---\n\t");
						scanf("%d",&conf);
						if(conf==1)
							{
								delete(data,pos,recno);
								recno--;
							}
						else
							printf("\tDelete Cancelled\n");
					}
					else
						printf("Record not Found!!\n");
				}
				puts("To continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 5:
				if(recno==0)
					printf("No records Entered!");
				else
				{
					pos=search(data,recno);
					if(pos!=-1)
					{
						printf("\nReg. No.\tReg. Date\t\tName\t\tSport\t\tOwner\t\tMobile");
						display(data[pos]);
						printf("\n---Enter 1 to confirm edit---\n\t");
						scanf("%d",&conf);
						if(conf==1)
						{
							modify(data,pos);
							printf("Record Successfully Modified!!\n");
						}
						else
							printf("Modification Aborted!!\n");
					}
					else
						printf("Record not found!!\n");
				}
				puts("To continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 6:
				cont=0;
				break;
			default:
				printf("---INVALID INPUT---");
				puts("To continue press 1 else 0");
				scanf("%d",&cont);
			}
		}while(cont==1);
	return EXIT_SUCCESS;
}
void input(struct record rec[],int no)
{
	flag=0;
	printf("Enter date of Registration:\n");
	do
	{printf("\tDate:\t");
	scanf("%d",&rec[no].d.day);
	printf("\tMonth:\t");
	scanf("%d",&rec[no].d.month);
	printf("\tYear:\t");
	scanf("%d",&rec[no].d.year);
	if(rec[no].d.day<=0||rec[no].d.day>31||rec[no].d.month<=0||rec[no].d.month>12||rec[no].d.year<=0)
		{
			flag=1;
			printf("\tInvalid Date!!!Enter another value!\n");
		}
	}while(flag==1);
	printf("Enter name of Student:\t");
	scanf("\n");
	gets(rec[no].name);
	printf("Enter name of the Sport:\t");
	scanf("\n");
	gets(rec[no].sport);
	printf("Enter name of owner:\t");
	scanf("\n");
	gets(rec[no].owner);
	printf("Enter mobile no.:\t");
	scanf("%s",&rec[no].mobile);
	rec[no].flag=0;
}
void display(struct record rec)
{
	printf("\n%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%s\t\t%s",rec.regno,rec.d.day,rec.d.month,rec.d.year,rec.name,rec.sport,rec.owner,rec.mobile);
}
int search(struct record rec[],int rno)
{
	int choice,rquery,pos=-1;
	char nquery[20];
	printf("Search with:\n\t1.Reg.ID\n\t2.Name\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("Enter Reg.ID:\t");
		scanf("%d",&rquery);
		for(i=0;i<rno;i++)
			if(rec[i].regno==rquery)
				{
					pos=i;
					break;
				}
	break;
	case 2:
		printf("Enter name to search:\t");
		scanf("\n");
		gets(nquery);
		for(i=0;i<rno;i++)
			if(strcmp(rec[i].name,nquery)==0)
			{
				pos=i;
				break;
			}
	break;
	default:
		printf("---INVALID INPUT---");
	break;
	}
	return pos;
}
void delete(struct record rec[],int no,int rno)
{
	for(i=no;i<(rno-1);i++)
		rec[i]=rec[i+1];
	printf("\tRecord Deleted Successfully!!\n");
}
void modify(struct record rec[],int rno)
{
	int choice,cont;
	do
	{
		printf("\nModify:\n\t1.Name\n\t2.Sport\n\t3.Mobile No.\n\t4.Back to Main Menu:\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter new Name:\t");
			scanf("\n");
			gets(rec[rno].name);
			puts("To go back to Update Menu, press 1 else 0");
			scanf("%d",&cont);
			break;
		case 2:
			printf("Enter New Sport:\t");
			scanf("\n");
			gets(rec[rno].sport);
			puts("To go back to Update Menu, press 1 else 0");
			scanf("%d",&cont);
			break;
		case 3:
			printf("Enter new Mobile No.:\t");
			scanf("%s",&rec[rno].mobile);
			puts("To go back to Update Menu, press 1 else 0");
			scanf("%d",&cont);
			break;
		case 4:
			cont=0;
			break;
		default:
			printf("---Invalid Input---");
			puts("To go back to Update Menu, press 1 else 0");
			scanf("%d",&cont);
			break;
		}
	}while(cont==1);
}
