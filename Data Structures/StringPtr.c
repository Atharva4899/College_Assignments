/*
 ============================================================================
 Name        : Assgn3.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int i,j,k,flag;
int strln(char*);
void copy(char*,char*,int);
void reverse(char*,char*,int);
int compare(char*,char*,int,int);
int sstr(char[],char[],int,int);


int main(void)
{

	int cont,choice,strl1,strl2,cmp,count;
	char string1[20],string2[20];
	char* s1;
	char* s2;
	s1=string1;		//Assigning Pointers to Strings
	s2=string2;
	do
	{
		puts("------MENU------");		//Menu Driven Program
		puts("   1.String Length\n   2.Copy String\n   3.Reverse String\n   4.Compare Strings");
		puts("   5.Check Pallindrome\n   6.Substring\n   7.Exit");
		fflush(0);
		puts("Enter your choice:\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				puts("Enter a string:\t");
				scanf("\n");
				gets(string1);		//Input First String
				strl1=strln(s1);		//Call to strln
				printf("Length of given string is: %d\n",strl1);
				puts("To continue press 1 else 0:\t");
				scanf("%d",&cont);
				break;
		case 2:
			puts("Enter a string:\t");
			scanf("\n");
			gets(string1);	//Input First String
			strl1=strln(s1);
			copy(s1,s2,strl1);	//Call to copy
			printf("\tCopied Successfully:\n");
			puts(string2);		//Display Copied String
			puts("To continue press 1 else 0:\t");
			scanf("%d",&cont);
		break;
		case 3:
			puts("Enter a string:\t");
			scanf("\n");
			gets(string1);	//Input First String
			strl1=strln(s1);
			reverse(s1,s2,strl1);	//Call to reverse
			printf("Reversed String is:\t");
			puts(string2);		//Display Reversed String
			puts("To continue press 1 else 0:\t");
			scanf("%d",&cont);
		break;
		case 4:
			puts("Enter string 1:\t");
			scanf("\n");
			gets(string1);		//Input First String
			strl1=strln(s1);
			puts("Enter string 2:\t");
			scanf("\n");
			gets(string2);		//Input Second String
			strl2=strln(s2);
			cmp=compare(s1,s2,strl1,strl2);		//Call to compare
			if(cmp==0)		//Check output of compare and display appropriate string
				printf("\n\tBoth strings are equal!");
			else if(cmp==1||cmp==3)
				{
				printf("\n\tHigher string is:\t");
				puts(string1);
				}
			else if(cmp==2||cmp==4)
			{
				printf("\n\tHigher string is:\t");
				puts(string2);
			}
			puts("To continue press 1 else 0:\t");
			scanf("%d",&cont);
		break;
		case 5:
			puts("Enter string 1:\t");
			scanf("\n");
			gets(string1);		//Input First String
			strl1=strln(s1);
			reverse(s1,s2,strl1);		//Reverse given string
			cmp=compare(s1,s2,strl1,strl1);		//Compare with original string
			if(cmp==0)		//Check if equal
				printf("\n\tGiven string is Pallindrome\n");
			else
				printf("\n\tGiven string is not Pallindrome\n");
			puts("To continue press 1 else 0:\t");
			scanf("%d",&cont);
		break;
		case 6:
			puts("Enter string 1:\t");
			scanf("\n");
			gets(string1);		//Input first String
			strl1=strln(s1);
			puts("Enter string for counting occurrence:\t");
			scanf("\n");
			scanf("%s",string2);		//Get string to count WITHOUT SPACES
			fflush(stdin);
			strl2=strln(s2);
			count=sstr(string1,string2,strl1,strl2);	//Call to sstr
			printf("\n\tEntered string occurs %d times",count);//Print Occurence
			puts("\nTo continue press 1 else 0:\t");
			scanf("%d",&cont);
		break;
		case 7:
			cont=0;
		break;
		default:
			printf("\n\tIncorrect Input!!!");
			puts("\nTo continue press 1 else 0:\t");
			scanf("%d",&cont);
		break;
		}
	}while(cont==1);
	return EXIT_SUCCESS;
}
int strln(char* str)
{
	i=0;
	while(*str!='\0')
		{
		i++;		//Increase WordCount
		str++;
		}
	return i;
}
void copy(char* str1,char* str2,int l)
{
	for(i=0;i<l;i++)		//Copy char to char
		{
			*str2=*str1;
			str1++;
			str2++;
		}
	*str2='\0';
}
void reverse(char* str1,char* rev,int l)
{
	str1+=(l-1);	//Set stringPtr to end of string
	for(i=0;i<l;i++)
	{
		*rev=*str1;	//Copy char to char
		rev++;
		str1--;
	}
	*rev='\0';
}
int compare(char* s1,char* s2,int l1,int l2)
{
	int t;
	flag=0;
	if(l1==l2)		//Check if lengths are equal
	{
		for(i=0;i<l1;i++)
		{
			if(*s1==*s2)	//Check char to char
				{
					flag=0;
					s1++;
					s2++;
				}
			else
			{
				flag=1;
				break;
			}
		}
	}
	else
		flag=1;
	if(flag==1)
	{	//t required to check count of iterations for checking
		if(l1==l2)
			t=l1;
		else if(l1>l2)
			t=l2;
		else
			t=l1;
		for(i=0;i<t;i++)
		{
			if(*s1==*s2)
				{
					s1++;
					s2++;
					continue;
				}
			else if(*s1<*s2)
			{
				flag=3;	//s1 is higher
				break;
			}
			else if(*s1>*s2)
			{
				flag=4;	//s2 is higher
				break;
			}
		}
	}
	if(flag==1)
	{
		if(l1>l2)
			flag=2;
	}
	return flag;
}
int sstr(char s1[],char s2[],int l1,int l2)
{
	int count=0;
	for(i=0;i<l1;i++)
	{
		k=0;

		if(s1[i]==s2[k])
		{
			k=i+1;
			for(j=1;j<l2;j++)
			{
				if(s1[k++]!=s2[j])
				{
						break;
				}
			}
			if(j==l2)
				count++;
		}
	}
	return count;
}
