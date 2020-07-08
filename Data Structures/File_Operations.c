/*
 ============================================================================
 Name        : Fileop.c
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
};
void input(struct record*);
void create(struct record*);
void display(struct record*);
int search(struct record*);
void delete(struct record*);
void modify(struct record*);
int i,flag;
int main(void)
{
	setvbuf( stdout, NULL, _IONBF, 0 );
	int choice,cont,conf,pos;
	struct record data;
	do
		{
		puts("\nMENU:\n1.Create Database\n2.Input New Record\n3.Display Records\n4.Search\n5.Delete\n6.Modify\n7.Exit");
		fflush(0);
		scanf("%d",&choice);
		switch(choice)
			{
			case 1:
				create(&data);
				puts("To continue press 1 else 0");
				scanf("%d",&cont);
				break;
			case 2:
				input(&data);
				puts("To continue press 1 else 0");
				scanf("%d",&cont);
				break;
			case 3:
				printf("\nReg. No.\tReg. Date\t\tName\t\tSport\t\tOwner\t\tMobile");
				display(&data);
				puts("\nTo continue press 1 else 0");
				scanf("%d",&cont);
				break;
			case 4:
				pos=search(&data);
				if(pos!=-1)
				{
					printf("Record Found!\n");
					printf("\nReg. No.\tReg. Date\t\tName\t\tSport\t\tOwner\t\tMobile");
					printf("\n%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%s\t\t%s",data.regno,data.d.day,data.d.month,data.d.year,data.name,data.sport,data.owner,data.mobile);
				}
				else
					printf("Record not Found!!\n");
				puts("\nTo continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 5:
					pos=search(&data);
					if(pos!=-1)
					{
						printf("\nReg. No.\tReg. Date\t\tName\t\tSport\t\tOwner\t\tMobile");
						printf("\n%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%s\t\t%s",data.regno,data.d.day,data.d.month,data.d.year,data.name,data.sport,data.owner,data.mobile);
						printf("\n---Enter 1 to confirm delete---\n\t");
						scanf("%d",&conf);
						if(conf==1)
							{
								delete(&data);
							}
						else
							printf("\tDelete Cancelled\n");
					}
					else
						printf("Record not Found!!\n");
				puts("To continue press 1 else 0");
				scanf("%d",&cont);
				break;
			case 6:
				pos=search(&data);
				if(pos!=-1)
				{
					printf("\nReg. No.\tReg. Date\t\tName\t\tSport\t\tOwner\t\tMobile");
					printf("\n%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%s\t\t%s",data.regno,data.d.day,data.d.month,data.d.year,data.name,data.sport,data.owner,data.mobile);
					printf("\n---Enter 1 to confirm edit---\n\t");
					scanf("%d",&conf);
					if(conf==1)
					{
						modify(&data);
					}
					else
						printf("Modification Aborted!!\n");
				}
				else
					printf("Record not found!!\n");
				puts("To continue press 1 else 0");
				scanf("%d",&cont);
				break;
			case 7:
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
void create(struct record* rec)
{
	FILE *fp=fopen("str.bin","w+");
		int no,rno=100;
		flag=0;
		printf("\nHow many records to be entered??");
		scanf("%d",&no);
		for(i=0;i<no;i++)
		{
			printf("Enter date of Registration:\n");
			do
			{
				printf("\tDate:\t");
				scanf("%d",&rec->d.day);
				printf("\tMonth:\t");
				scanf("%d",&rec->d.month);
				printf("\tYear:\t");
				scanf("%d",&rec->d.year);
				if(rec->d.day<=0||rec->d.day>31||rec->d.month<=0||rec->d.month>12||rec->d.year<=0)
				{
					flag=1;
					printf("\tInvalid Date!!!Enter another value!\n");
				}
			}while(flag==1);
			printf("Enter name of Student:\t");
			scanf("\n");
			gets(rec->name);
			printf("Enter name of the Sport:\t");
			scanf("\n");
			gets(rec->sport);
			printf("Enter name of owner:\t");
			scanf("\n");
			gets(rec->owner);
			printf("Enter mobile no.:\t");
			scanf("%s",rec->mobile);
			rec->regno=rno;
			rno++;
			fwrite(rec,sizeof(*rec),1,fp);
			}
		fclose(fp);
}
void input(struct record* rec)
{
	FILE *fp=fopen("str.bin","r");
	int no,rno=100;
	while((fread(rec,sizeof(*rec),1,fp))==1)
		rno=rec->regno;
	fclose(fp);
	fp=fopen("str.bin","a+");
	flag=0;
	printf("\nHow many records to be entered??");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		printf("Enter date of Registration:\n");
		do
		{
			printf("\tDate:\t");
			scanf("%d",&rec->d.day);
			printf("\tMonth:\t");
			scanf("%d",&rec->d.month);
			printf("\tYear:\t");
			scanf("%d",&rec->d.year);
			if(rec->d.day<=0||rec->d.day>31||rec->d.month<=0||rec->d.month>12||rec->d.year<=0)
			{
				flag=1;
				printf("\tInvalid Date!!!Enter another value!\n");
			}
		}while(flag==1);
		printf("Enter name of Student:\t");
		scanf("\n");
		gets(rec->name);
		printf("Enter name of the Sport:\t");
		scanf("\n");
		gets(rec->sport);
		printf("Enter name of owner:\t");
		scanf("\n");
		gets(rec->owner);
		printf("Enter mobile no.:\t");
		scanf("%s",rec->mobile);
		rec->regno=++rno;
		fwrite(rec,sizeof(*rec),1,fp);
		}
	fclose(fp);
}
void display(struct record* rec)
{
	FILE *fp=fopen("str.bin","r+");
	while((fread(rec,sizeof(*rec),1,fp))==1)
	{
		printf("\n%d\t\t%d/%d/%d\t\t%s\t\t%s\t\t%s\t\t%s",rec->regno,rec->d.day,rec->d.month,rec->d.year,rec->name,rec->sport,rec->owner,rec->mobile);
	}
	fclose(fp);
}
int search(struct record* rec)
{
	FILE *fp=fopen("str.bin","r");
	int choice,rquery;
	char nquery[20];
	printf("Search with:\n\t1.Reg.ID\n\t2.Name\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("Enter Reg.ID:\t");
		scanf("%d",&rquery);
		while((fread(rec,sizeof(*rec),1,fp))==1)
			if(rec->regno==rquery)
				{
					return 1;
				}
	break;
	case 2:
		printf("Enter name to search:\t");
		scanf("\n");
		gets(nquery);
		while((fread(rec,sizeof(*rec),1,fp))==1)
			if(strcmp(rec->name,nquery)==0)
			{
				return 1;
			}
	break;
	default:
		printf("---INVALID INPUT---");
	break;
	}
	return -1;
}
void delete(struct record* rec)
{
	FILE *fp=fopen("str.bin","r");
	FILE *fp1=fopen("str1.bin","w");
	struct record temp;
	while((fread(&temp,sizeof(temp),1,fp))==1)
		if(temp.regno!=rec->regno)
			fwrite(&temp,sizeof(temp),1,fp1);
	fclose(fp);
	fclose(fp1);
	remove("str.bin");
	rename("str1.bin","str.bin");
	printf("\tRecord Deleted Successfully!!\n");
}
void modify(struct record* rec)
{
	FILE *fp=fopen("str.bin","r+");
	FILE *fp1=fopen("str1.bin","w+");
	struct record temp;
	while((fread(&temp,sizeof(temp),1,fp))==1)
	{
		if(temp.regno!=rec->regno)
			fwrite(&temp,sizeof(temp),1,fp1);
		else
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
						gets(temp.name);
						puts("To go back to Update Menu, press 1 else 0");
						scanf("%d",&cont);
						break;
					case 2:
						printf("Enter New Sport:\t");
						scanf("\n");
						gets(temp.sport);
						puts("To go back to Update Menu, press 1 else 0");
						scanf("%d",&cont);
						break;
					case 3:
						printf("Enter new Mobile No.:\t");
						scanf("%s",temp.mobile);
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
			fwrite(&temp,sizeof(temp),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	remove("str.bin");
	rename("str1.bin","str.bin");
	printf("\tRecord Modified Successfully!!\n");
}

