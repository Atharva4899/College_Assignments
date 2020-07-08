#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct RT
{
	char instr[10];
	int opcode;
}RT;

RT reg[]={{"areg",1},{"breg",2},{"creg",3},{"dreg",4}};
RT symt[50];
RT littab[50];

int symt_top=0;
int littab_top=0;
int pooltab_top=0;

int lc=0;

void write_sym_lit()
{
	FILE* st=fopen("symbol table.txt","w");
	FILE* lt=fopen("literal table.txt","w");
	
	int i;
	for(i=0;i<symt_top;i++)
	{
		if(symt[i].opcode!=-1)
		{
			fprintf(st,"%s %d\n",symt[i].instr,symt[i].opcode);
		}
		else
			printf("\nUndeclared Symbol!\n");
	}
	fclose(st);
	
	for(i=0;i<littab_top;i++)
	{
		fprintf(lt,"%s %d\n",littab[i].instr,littab[i].opcode);
	}
	fclose(lt);
}

void display_res()
{
	FILE* opt,*st;
	char c;
	
	opt=fopen("intermediate.txt","r");
	printf("\nIntermediate Code:\n\n");
	c=fgetc(opt);
	while(c != EOF)
	{
		printf("%c" , c);
		c=fgetc(opt);
	}
	fclose(opt);
	printf("\n");
	
	printf("\nSymbol Table:\n");
	st=fopen("symbol table.txt","r");
	c=fgetc(st);
	while(c != EOF)
	{
		printf("%c" , c);
		c=fgetc(st);
	}
	fclose(st);
	
	printf("\nLiteral Table:\n");
	st=fopen("literal table.txt","r");
	c=fgetc(st);
	while(c != EOF)
	{
		printf("%c" , c);
		c=fgetc(st);
	}
	fclose(st);
}

void imp_st(int op)
{
	FILE* opt=fopen("intermediate.txt","a");
	fprintf(opt,"%d\t(%s,%d)\t",lc,"IS",op);
	lc++;
	fclose(opt);
}

void write_lit()
{
	FILE* opt=fopen("intermediate.txt","a");
	int i;
	for(i=pooltab_top;i<littab_top;i++)
	{
		littab[i].opcode=lc;
		fprintf(opt,"%d\t---\t---\t%s\n",lc,littab[i].instr);
		lc++;
	}
	pooltab_top=littab_top;
	fclose(opt);
}

void a_dir(int op)
{
	FILE* opt;
	int i;
	switch(op)
	{
		case 1:
			printf("Cannot use START more than once...Exiting..\n");
			exit(0);
			break;
		case 2:
			write_lit();
			opt=fopen("intermediate.txt","a");
			fprintf(opt,"00\t000\t000\t000");
			fclose(opt);
			write_sym_lit();
			display_res();
			exit(0);
			break;
		case 3:
			opt=fopen("intermediate.txt","a");
			fprintf(opt,"%d\t(%s,%d)\t",lc,"AD",op);
			lc++;
			fclose(opt);
			break;
		case 4:
			break;
		case 5:
			opt=fopen("intermediate.txt","a");
			fprintf(opt,"%d\t(%s,%d)\t---\t---\n",lc,"AD",op);
			fclose(opt);
			lc++;
			write_lit();
			break;
	}
}

void st_ins(int op)
{
	FILE* opt=fopen("intermediate.txt","a");
	fprintf(opt,"%d\t(%s,%d)\t",lc,"DD",op);
	if(op==2)
		lc++;
	fclose(opt);
}

void label_handler(char ins[])
{
	int i=0;
	for(i=0;i<symt_top;i++)
	{
		if(strcmp(symt[i].instr,ins)==0)
		{
			if(symt[i].opcode==-1)
			{
				symt[i].opcode=lc;
				break;
			}
			else
			{
				printf("Duplication of Label!\n");
				exit(0);
			}
		}
	}
	if(i==symt_top)
	{
		strcpy(symt[i].instr,ins);
		symt[i].opcode=lc;
		symt_top++;
	}
}

int symbol_handler(char op2[])
{
	int i;
	for(i=0;i<symt_top;i++)
	{
		if(strcmp(symt[i].instr,op2)==0)
		{
			break;
		}
	}
	if(i==symt_top)
	{
		strcpy(symt[i].instr,op2);
		symt[i].opcode=-1;
		symt_top++;
	}
	return i;
}

void literal_handler(char op2[])
{
	int i;
	for(i=pooltab_top;i<littab_top;i++)
	{
		if(strcmp(littab[i].instr,op2)==0)
			break;
	}
	if(i==littab_top)
	{
		strcpy(littab[i].instr,op2);
		littab[i].opcode=-1;
		littab_top++;
	}
}

int search_mt(char ins[])
{
	FILE* mt=fopen("mnemonic table.txt","r");
	
	char mn[10]="";
	char type[3]="";
	int op;
	
	while(fscanf(mt,"%s%d%s",mn,&op,type)!=EOF)
	{
		if(strcmp(mn,ins)==0)
		{
			if(strcmp(type,"is")==0)
			{
				imp_st(op);
				fclose(mt);
				return 1;
			}
			else if(strcmp(type,"ad")==0)
			{
				a_dir(op);
				fclose(mt);
				return 2;
			}
			else if(strcmp(type,"dd")==0)
			{
				st_ins(op);
				fclose(mt);
				return 3;
			}
		}
	}
	
	label_handler(ins);
	
	return 0;
}

void search_rt(char op1[])
{
	int i;
	FILE* op=fopen("intermediate.txt","a");
	/*if(strcmp(op1,"")==0)
	{
		fprintf(op,"-\t");
		fclose(op);
		return;
	}*/
	for(i=0;i<4;i++)
	{
		if(strcmp(reg[i].instr,op1)==0)
		{
			fprintf(op,"(R,%d)\t",reg[i].opcode);
			break;
		}
	}
	if(i==4)
		printf("\nInvalid Register!!\n");
	fclose(op);
}

void write_op2(char op2[],int f)
{
	FILE* opt=fopen("intermediate.txt","a");
	int pos;
	op2[strcspn(op2,"\n")]=0;
	/*if(strcmp(op2,"")==0)
	{
		fprintf(opt,"\t---\n");
		//fclose(opt);
	}*/
	if(op2[0]=='\'' && op2[strlen(op2)-1]=='\'')
	{
		literal_handler(op2);
		fprintf(opt,"(L,%s)",op2);
		//fclose(opt);
		
	}
	else if(!isdigit(op2[0]))
	{
		pos=symbol_handler(op2);
		fprintf(opt,"(S,%d)",pos);
		//fclose(opt);
	}
	else if(isdigit(op2[0]))
	{
		fprintf(opt,"(C,%s)",op2);
		//fclose(opt);
	}
	
	if(f==1)
		fprintf(opt,"\t---");
	fprintf(opt,"\n");
	fclose(opt);
	
}

int main()
{
	char op1[5]="";
	char op2[5]="";
	char instr[50]="";
	
	FILE* st=fopen("symbol table.txt","w");
	FILE* opt=fopen("intermediate.txt","w");
	fclose(opt);
	fclose(st);
	
	FILE* f=fopen("input.txt","r");
	
	char delim[]=" ";
	
	fgets(instr,50,f);
	char* ptr=strtok(instr,delim);
	if(strcmp(ptr,"start")==0)
	{
		ptr=strtok(NULL,delim);
		if(ptr!=NULL)
			lc=atoi(ptr);
	}
	else
	{
		printf("First statement has to be START");
		exit(0);
	}
	
	while(fgets(instr,50,f)!=NULL)
	{	
		int is_op=0;
		
		ptr=strtok(instr,delim);
		
		while(ptr!=NULL)
		{   
			ptr[strcspn(ptr,"\n")]=0;
			
			if(is_op==0)
			{
				is_op=search_mt(ptr);
				if(is_op==3)
					if(strcmp(ptr,"dc")==0)
						is_op=4;
			}
			else if(strcmp(op1,"")==0)
			{
				strcpy(op1,ptr);
			}
			else if(strcmp(op2,"")==0)
			{
				strcpy(op2,ptr);
			}	
			ptr=strtok(NULL,delim);
		}
		int flag=0;
		if(strcmp(op2,"")==0)
		{
			strcpy(op2,op1);
			strcpy(op1,"");
			flag=1;
		}
	
		if(strcmp(op1,""))
		{	
			search_rt(op1);
		}
		if(strcmp(op2,""))	
		{
			write_op2(op2,flag);
			if(is_op==3)
				lc+=atoi(op2);
		}
		
		strcpy(op1,"");
		strcpy(op2,"");
		is_op=0;
		
	}
	
	fclose(f);
	
	write_sym_lit();
	
	display_res();
	
	return 0;
}
