#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define termst 8
#define termt_size 20
typedef struct TerminalTab
{
	char keyw[10];
	int is_break;
	char token[10];
}tt;

tt termt[20]={{"if",0,"key1"},{"else",0,"key2"},{"while",0,"key3"},{"for",0,"key4"},{"int",0,"key5"},{"char",0,"key6"},{"include",0,"key7"},{"stdio.h",0,"key8"},{"(",1,"("},{")",1,")"},{"{",1,"{"},{"}",1,"}"},{"=",1,"="},{";",1,";"},{"#",1,"#"},{"<",1,"<"},{">",1,">"},{" ",1,""},{"\"",1,"\""},{"'",1,"'"}};

typedef struct idTab
{
	char id[20];
	char token[5];
}it;

typedef struct litTab
{
	char lit[30];
	char token[5];
}lt;

typedef struct UST
{
	char lexeme[20];
	char tab;
	int pos;
}ust;

ust UniTab[100];
it IdTab[30];
lt LtTab[30];

int litcount,idcount,unicount;

int check_id_present(char lex[])
{
	int i;
	for(i=0;i<idcount;i++)
	{
		if(strcmp(lex,IdTab[i].id)==0)
			return i;
	}
	return -1;
}

int check_lit_present(char lex[])
{
	int i;
	for(i=0;i<litcount;i++)
	{
		if(strcmp(lex,LtTab[i].lit)==0)
			return i;
	}
	return -1;
}

void keyword_handler(char lex[],int pos)
{
	FILE* op=fopen("output.txt","a");
	fprintf(op,"%s ",termt[pos].token);
	fclose(op);
	
	if(strcmp(lex," ")==0)
		return;
	
	strcpy(UniTab[unicount].lexeme,lex);
	UniTab[unicount].tab='K';
	UniTab[unicount].pos=pos;
	unicount++;
}

void id_handler(char lex[])
{
	char tok[6]="id";
	char id[3];
	int id_ind=check_id_present(lex);
	
	if(id_ind==-1)
	{
		int i=0;
		while(lex[i]!='\0')
		{
			if(isalpha(lex[i]) || isdigit(lex[i]))
			{
				i++;
			}
			else
			{
				printf("---Invalid Token---\n");
				return;
			}
		}
		sprintf(id,"%d",idcount+1);
		strcat(tok,id);

		strcpy(IdTab[idcount].id,lex);
		strcpy(IdTab[idcount].token,tok);
	}
	else
	{
		strcpy(tok,IdTab[id_ind].token);
	}
	

	strcpy(UniTab[unicount].lexeme,lex);
	UniTab[unicount].tab='I';
	UniTab[unicount].pos=(id_ind==-1)?idcount:id_ind;

	unicount++;
	if(id_ind==-1)
		idcount++;
	
	FILE* op=fopen("output.txt","a");
	fprintf(op,"%s ",tok);
	fclose(op);
}

void lit_handler(char lex[])
{
	char tok[6]="lit";
	char id[3];
	int lit_ind=check_lit_present(lex);
	if(lit_ind==-1)
	{
		if(lex[0]=='\"' || lex[0]=='\'')
		{
			//lex[strcspn(lex,"\'")]=0;
			//lex[strcspn(lex,"\"")]=0;
		}
		if(isdigit(lex[0]))
		{
			int i=0;
			while(lex[i]!='\0')
			{
				if(isdigit(lex[i]))
					i++;
				else
				{
					printf("---Invalid Token---\n");
					return;
				}
			}
		}
		
		sprintf(id,"%d",litcount+1);
		strcat(tok,id);

		strcpy(LtTab[litcount].lit,lex);
		strcpy(LtTab[litcount].token,tok);
	}
	else
	{
		strcpy(tok,LtTab[lit_ind].token);
	}
	

	strcpy(UniTab[unicount].lexeme,lex);
	UniTab[unicount].tab='L';
	
	UniTab[unicount].pos=(lit_ind==-1)?litcount:lit_ind;

	unicount++;
	if(lit_ind==-1)
		litcount++;
	
	FILE* op=fopen("output.txt","a");
	fprintf(op,"%s ",tok);
	fclose(op);
}

void check_lex(char lexeme[],int flag)
{
	printf("%s->%d",lexeme,flag);
	
	if(flag==0)
	{
		lit_handler(lexeme);
		return;
	}
	
	int i;
	for(i=0;i<termt_size;i++)
	{
		if(strcmp(termt[i].keyw,lexeme)==0)
		{
			keyword_handler(lexeme,i);
			return;
		}	
	}
	if(isdigit(lexeme[0]))
	{
		lit_handler(lexeme);
	}
	if(isalpha(lexeme[0]))
	{
		id_handler(lexeme);
	}
	
}

int check_term(char c)
{
	int i;
	for(i=termst;i<termt_size;i++)
	{
		if(c==termt[i].keyw[0])
			return 1;
	}
	return 0;
}

void print_tab()
{
	int i;
	FILE* op=fopen("output.txt","a");
	
	fprintf(op,"\n---Symbol Table---\n");
	
	for(i=0;i<idcount;i++)
	{
		fprintf(op,"%s\t%s\n",IdTab[i].id,IdTab[i].token);
	}
	
	fprintf(op,"\n---Literal Table---\n");
	
	for(i=0;i<litcount;i++)
	{
		fprintf(op,"%s\t%s\n",LtTab[i].lit,LtTab[i].token);
	}

	fprintf(op,"\n---Universal Symbol Table---\n");
	
	for(i=0;i<unicount;i++)
	{
		fprintf(op,"%s\t%c\t%d\n",UniTab[i].lexeme,UniTab[i].tab,UniTab[i].pos);
	}
	fclose(op);
}

void print_op()
{
	FILE* op=fopen("output.txt","r");
	char line[50];
	
	printf("\n\n---Output---\n\n");
	while(fgets(line,50,op)!=NULL)
	{
		printf("%s",line);
	}
	fclose(op);
}

int main()
{
	litcount=idcount=unicount=0;

	FILE* ip=fopen("input.txt","r");
	FILE* op=fopen("output.txt","w");
	fclose(op);

	char buffer[50];
	int fp,bp,i,lc=1;

	while(fgets(buffer,50,ip)!=NULL)
	{
		op=fopen("output.txt","a");
		fprintf(op,"%d ",lc);
		fclose(op);
		
		fp=bp=0;
		int flag=1;
		while(buffer[fp]!='\0')
		{
			if(buffer[fp]=='/' && buffer[fp+1]=='/')
			{
				break;
			}
			
			if(check_term(buffer[fp]))
			{	
				if(flag==0 && buffer[fp]!='"')
				{
					fp++;
					continue;
				}
				char lexeme[20];
				int j=0;
				if(bp<fp)
				{
					for(i=bp;i<fp;i++)
					{
						lexeme[j]=buffer[i];
						j++;
					}
					lexeme[j]='\0';
					check_lex(lexeme,flag);
					if(buffer[fp]=='"')
						flag=flag^1;
				}
				else
				{
					lexeme[0]=buffer[fp];
					lexeme[1]='\0';
					fp++;
					check_lex(lexeme,flag);
					if(buffer[fp-1]=='"')
						flag=flag^1;
				}				
				bp=fp;
				
			}
			else
			{
				fp++;
				if(buffer[fp-1]=='"')
					flag=flag^1;
			}
				
		}
		printf("\n");
		op=fopen("output.txt","a");
		fprintf(op,"\n");
		fclose(op);
		
		lc++;
	}
	fclose(ip);

	print_tab();
	
	print_op();

	return 0;
}