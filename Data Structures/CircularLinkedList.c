/*
 ============================================================================
 Name        : CLL.c
 Author      : Atharva Kulkarni,F11,23329
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node
{
	int exp;
	float coeff;
	struct node* next;
};

struct node* getNode();
struct node* createPoly(struct node*);
struct node* insert(struct node*,int,float);
void display(struct node*);
struct node* add(struct node*, struct node*);
struct node* multiply(struct node*, struct node*);
float evaluate(struct node*, float);
int menu();

int main(void) {
	setvbuf( stdout, NULL, _IONBF, 0 );
	struct node* p1=NULL;
	struct node* p2=NULL;
	struct node* addition=NULL;
	struct node* mul=NULL;
	float a1,a2,e1,e2;
	int cont,choice;
	p1=createPoly(p1);
	display(p1);
	p2=createPoly(p2);
	display(p2);
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:
			printf("\n:---Polynomial 1---:\n");
			display(p1);
			printf("\n:---Polynomial 2---:\n");
			display(p2);
			printf("\n\tPress 1 for Main Menu, any other key to exit:\t");
			scanf("%d",&cont);
			break;
		case 2:
			addition=add(p1,p2);
			printf("\n:---Polynomial 1---:\n");
			display(p1);
			printf("\n:---Polynomial 2---:\n");
			display(p2);
			printf("\n:---Addition---:\n");
			display(addition);
			printf("\n\tPress 1 for Main Menu, any other key to exit:\t");
			scanf("%d",&cont);
			break;
		case 3:
			mul=multiply(p1,p2);
			printf("\n:---Polynomial 1---:\n");
			display(p1);
			printf("\n:---Polynomial 2---:\n");
			display(p2);
			printf("\n:---Multiplication---:\n");
			display(mul);
			printf("\n\tPress 1 for Main Menu, any other key to exit:\t");
			scanf("%d",&cont);
			break;
		case 4:
			printf("Enter value of x for evaluating Polynomial 1:\t");
			scanf("%f",&e1);
			a1=evaluate(p1,e1);
			printf("\n:---Polynomial 1---:\n");
			display(p1);
			printf("\n\tAnswer is:\t%f\n\n",a1);
			printf("Enter value of x for evaluating Polynomial 2:\t");
			scanf("%f",&e2);
			a2=evaluate(p2,e2);
			printf("\n:---Polynomial 2---:\n");
			display(p2);
			printf("\n\tAnswer is:\t%f\n\n",a2);
			printf("\n\tPress 1 for Main Menu, any other key to exit:\t");
			scanf("%d",&cont);
			break;
		case 5:
			cont=0;
			break;
		default:
			printf("\n\t---Invalid Input!---\n");
			cont=1;
			break;
		}
	}while(cont==1);
	return EXIT_SUCCESS;
}

int menu()
{
	int choice;
	printf("\n\n\t---MENU---\n\n");
	printf("\t1.Display Polynomials\n\t2.Add Polynomials\n\t3.Multiply Polynomials\n\t4.Evaluate\n\t5.Exit\n");
	scanf("%d",&choice);
	return choice;
}

struct node* getNode()
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->coeff=0;
	temp->exp=0;
	temp->next=NULL;
	return temp;
}

struct node* createPoly(struct node* p)
{
	int n;
	do
	{
		printf("\nEnter total terms in the polynomial:\t");
		scanf("%d",&n);
		if(n<=0)
		{
			printf("\n\t---Invalid Input---\n");
		}
	}while(n<=0);
	while(n!=0)
	{
		int exp1;
		float coeff1;
		printf("\nEnter Exponent:\t");
		scanf("%d",&exp1);
		do
		{
			printf("\nEnter Coefficient:\t");
			scanf("%f",&coeff1);
			if(coeff1==0)
			{
				printf("\n\t---Invalid Input---\n");
			}
		}while(coeff1==0);
		p=insert(p,exp1,coeff1);
		n--;
	}
	return p;
}

struct node* insert(struct node* p,int exp1,float coeff1)
{
	struct node* temp=getNode();
	temp->coeff=coeff1;
	temp->exp=exp1;
	struct node* t=p;
	if(p==NULL)
	{
		p=temp;
		p->next=p;
		return p;
	}
	if(temp->exp>p->exp)
	{
		temp->next=p;
		while(t->next!=p)
		{
			t=t->next;
		}
		t->next=temp;
		p=temp;
		return p;
	}
	if(temp->exp==p->exp)
	{
		p->coeff+=temp->coeff;
		free(temp);
		return p;
	}
	while(t->next!=p&&(t->next)->exp>temp->exp)
	{
		t=t->next;
	}
	if((t->next)->exp==temp->exp)
	{
		(t->next)->coeff+=temp->coeff;
		free(temp);
		return p;
	}
	temp->next=t->next;
	t->next=temp;
	return p;
}

void display(struct node* p)
{
	struct node* temp=p;
	do
	{
		printf("  +  (%f x^ %d)",temp->coeff,temp->exp);
		temp=temp->next;
	}while(temp!=p);
	printf("\n\n");
}

struct node* add(struct node* p1,struct node* p2)
{
	struct node* res=NULL;
	struct node* temp=p1;
	do
	{
		res=insert(res,temp->exp,temp->coeff);
		temp=temp->next;
	}while(temp!=p1);
	temp=p2;
	do
	{
		res=insert(res,temp->exp,temp->coeff);
		temp=temp->next;
	}while(temp!=p2);
	return res;
}

struct node* multiply(struct node* p1, struct node* p2)
{
	struct node* mul=NULL;
	struct node* temp1=p1;
	struct node* temp2=p2;
	do
	{
		do
		{
			mul=insert(mul,temp1->exp+temp2->exp,temp1->coeff*temp2->coeff);
			temp2=temp2->next;
		}while(temp2!=p2);
		temp1=temp1->next;
	}while(temp1!=p1);
	return mul;
}

float evaluate(struct node* p,float query)
{
	float res=0;
	struct node* temp=p;
	do
	{
		res+=temp->coeff*pow(query,temp->exp);
		temp=temp->next;
	}while(temp!=p);
	return res;
}
