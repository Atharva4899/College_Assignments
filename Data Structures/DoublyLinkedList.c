/*
 ============================================================================
 Name        : DoublyLinkedList.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node
{
	char data;
	struct node* previous;
	struct node* next;
};

struct node* create(struct node*);
struct node* getnode();
void display(struct node*);
struct node* insert(struct node*);
struct node* deleteData(struct node*,char);
void displayReverse(struct node*);
int menu();

int main(void)
{
	setvbuf( stdout, NULL, _IONBF, 0 );
	struct node* s1=NULL;
	char query;
	int choice,cont;
	s1=create(s1);
	display(s1);
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:
			display(s1);
			printf("\n\tPress 1 for Main Menu, any other key to exit:\t");
			scanf("%d",&cont);
			break;
		case 2:
			s1=insert(s1);
			display(s1);
			printf("\n\tPress 1 for Main Menu, any other key to exit:\t");
			scanf("%d",&cont);
			break;
		case 3:
			printf("\nEnter data to delete:\t");
			scanf("\n");
			scanf("%c",&query);
			s1=deleteData(s1,query);
			display(s1);
			printf("\n\tPress 1 for Main Menu, any other key to exit:\t");
			scanf("%d",&cont);
			break;
		case 4:
			displayReverse(s1);
			printf("\n\tPress 1 for Main Menu, any other key to exit:\t");
			scanf("%d",&cont);
			break;
		case 5:
			cont=0;
			break;
		default:
			printf("\n\t---Invalid Input---\n");
			cont=1;
			break;
		}
	}while(cont==1);
	return EXIT_SUCCESS;
}

int menu()
{
	int choice;
	printf("\n\n\t:---MENU---:\n\n");
	printf("\t1.Display String\n\t2.Insert character\n\t3.Delete a character\n\t4.Display Reverse\n\t5.Exit\n");
	scanf("%d",&choice);
	return choice;
}
struct node* getnode()
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->previous=NULL;
	return temp;
}

struct node* create(struct node* head)
{
	char str[20];
	int l;
	struct node* temp;
	struct node* t=head;
	printf("Enter a string:\t");
	gets(str);
	l=strlen(str);
	for(int i=0;i<l;i++)
	{
		temp=getnode();
		temp->data=str[i];
		if(head==NULL)
		{
			head=temp;
			t=head;
		}
		else
		{
			t->next=temp;
			temp->previous=t;
			t=t->next;
		}
	}
	return head;
}

void display(struct node* head)
{
	if(head==NULL)
	{
		printf("\n\t---No Data!---\n");
	}
	else
	{
		struct node *t=head;
		//printf("\n");
		printf("\n\n:---LIST---:\n\n");
		while(t!=NULL)
		{
			printf("%c\t",t->data);
			t=t->next;
		}
		printf("\n");
	}
}

struct node* insert(struct node* head)
{
	struct node* temp;
	struct node* t=head;
	char d,data;
	int pos,choice;
	printf("\n---MENU---\n");
	printf("\t1.By data:\n\t2.By Position\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("\n\tEnter query:\t");
		scanf("\n");
		scanf("%c",&data);
		while(t->data!=data&&t->next!=NULL)
		{
			t=t->next;
		}
		if(t->data==data)
		{
			temp=getnode();
			printf("\n\tEnter a character:\t");
			scanf("\n");
			scanf("%c",&d);
			temp->data=d;
			temp->next=t->next;
			temp->previous=t;
			if(t->next!=NULL)
			(t->next)->previous=temp;
			t->next=temp;
		}
		else
		{
			printf("\n\t---Data does not exist!---\n");
		}
		break;
	case 2:
		printf("Enter Position(0 for beginning, -1 for end):\t");
		scanf("\n");
		scanf("%d",&pos);
		if(pos==0)
		{
			temp=getnode();
			head->previous=temp;
			temp->next=head;
			head=temp;
			printf("\n\tEnter a character:\t");
			scanf("\n");
			scanf("%c",&d);
			temp->data=d;
		}
		else if(pos==-1)
		{
			temp=getnode();
			while(t->next!=NULL)
			{
				t=t->next;
			}
			temp->previous=t;
			t->next=temp;
			printf("\n\tEnter a character:\t");
			scanf("\n");
			scanf("%c",&d);
			temp->data=d;
		}
		else
		{
			for(int i=0;i<pos-1;i++)
			{
				if(t!=NULL)
				{
					t=t->next;
				}
				else
					break;
			}
			if(t==NULL)
			{
				printf("\n\t---Position does not exist---\n");
			}
			else
			{
				temp=getnode();
				temp->next=t->next;
				temp->previous=t;
				if(t->next!=NULL)
				(t->next)->previous=t;
				t->next=temp;
				printf("Enter a character:\t");
				scanf("\n");
				scanf("%c",&d);
				temp->data=d;
			}
		}
		break;
	default:
		printf("\n\t---Invalid Input!---\n");
		break;
	}
	return head;
}

struct node* deleteData(struct node* head, char query)
{
	struct node* temp=head;
	while(temp->next!=NULL&&temp->data!=query)
	{
		temp=temp->next;
	}
	if(temp->data==query)
	{
		if(temp==head)
		{
			head=head->next;
			head->previous=NULL;
			free(temp);
			return head;
		}
		else
		{
			(temp->previous)->next=temp->next;
			if(temp->next!=NULL)
				(temp->next)->previous=temp->previous;
			free(temp);
			return head;
		}
	}
	else
		printf("\n\t---Data not found!---\n");
	return head;
}

void displayReverse(struct node* head)
{
	struct node* temp=head;
	if(head==NULL)
		{
			printf("\n\t---No Data!---\n");
		}
	else
	{
		//printf("\n");
		printf("\n\n:---REVERSED LIST---:\n\n");
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp!=NULL)
		{
			printf("%c\t",temp->data);
			temp=temp->previous;
		}
		printf("\n");
	}
}
