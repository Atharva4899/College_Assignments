#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct tab
{
	char mne[5];
	int add;
}t={"",-1};
typedef struct tab tab;
tab st[20]={"",-1};
tab lt[20]={"",-1};

void load_lt_st()
{
	int ad,i=0;
	char mn[5];
	
	for(i=0;i<20;i++)
	{
		strcpy(st[i].mne,"");
		strcpy(lt[i].mne,"");
		st[i].add=-1;
		lt[i].add=-1;
	}
	
	i=0;
	
	FILE* f=fopen("symbol table.txt","r");
	while(fscanf(f,"%s %d",mn,&ad)!=EOF)
	{
		strcpy(st[i].mne,mn);
		st[i].add=ad;
		//printf("%s %d\n",mn,ad);
		i++;
	}
	fclose(f);
	
	i=0;
	
	f=fopen("literal table.txt","r");
	while(fscanf(f,"%s %d",mn,&ad)!=EOF)
	{
		strcpy(lt[i].mne,mn);
		lt[i].add=ad;
		//printf("%s %d\n",mn,ad);
		i++;
	}
	fclose(f);
}

void print_lt_st()
{
	int i;
	for(i=0;st[i].add!=-1;i++)
	{
		printf("%s %d\n",st[i].mne,st[i].add);
	}
	
	for(i=0;lt[i].add!=-1;i++)
	{
		printf("%s %d\n",lt[i].mne,lt[i].add);
	}
}

int find_sym_add(char sym[])
{
	int i;
	for(i=0;st[i].add!=-1;i++)
	{
		if(strcmp(sym,st[i].mne)==0)
			return st[i].add;
	}
}

int find_lit_add(char lit[])
{
	int i;
	for(i=0;lt[i].add!=-1;i++)
	{
		if(strcmp(lit,lt[i].mne)==0)
			return lt[i].add;
	}
}

void is_handler(int lc,char ins[],char op1[],char op2[])
{
	FILE* op=fopen("mc.txt","a");
	int i,ad;
	char opc[3];
	opc[0]=ins[4];
	opc[1]=ins[5];
	opc[2]='\0';
	
	int opcode=atoi(opc);
	
	int o1=op1[3]-'0';
	
	if(op2[1]=='S')
	{
		char sym[10];
		for(i=3;op2[i]!=')';i++)
		{
			sym[i-3]=op2[i];
		}
		sym[i-3]='\0';
		int index;
		index=atoi(sym);
		//printf("%s\n",sym);
		ad=st[index].add;
	}
	else if(op2[1]=='L')
	{
		char lit[10];
		for(i=3;op2[i]!=')';i++)
		{
			lit[i-3]=op2[i];
		}
		lit[i-3]='\0';
		//printf("%s\n",sym);
		ad=find_lit_add(lit);
	}
	else if(op2[1]=='C')
	{
		char con[10];
		for(i=3;op2[i]!=')';i++)
		{
			con[i-3]=op2[i];
		}
		con[i-3]='\0';
		//printf("%s\n",sym);
		ad=atoi(con);
	}
	
	fprintf(op,"%d\t+%d\t%d\t%d\n",lc,opcode,o1,ad);
	fclose(op);
}

void dl_handler(int lc,char ins[],char op1[],char op2[])
{
	FILE* op=fopen("mc.txt","a");
	
	char opc[3];
	opc[0]=ins[4];
	opc[1]=ins[5];
	opc[2]='\0';
	
	int opcode=atoi(opc);
	
	if(opcode==1)	//ds
	{
		fprintf(op,"%d\t00\t00\t00\n",lc);
	}
	else
	{
		char con[10];
		int i;
		for(i=3;op1[i]!=')';i++)
		{
			con[i-3]=op1[i];
		}
		con[i-3]='\0';
		
		fprintf(op,"%d\t00\t00\t%s\n",lc,con);
	}
	
	fclose(op);
}

void ad_handler(int lc,char ins[],char op1[],char op2[])
{
	FILE* op=fopen("mc.txt","a");
	
	char opc[3];
	opc[0]=ins[4];
	opc[1]=ins[5];
	opc[2]='\0';
	
	int opcode=atoi(opc);
	
	if(opcode==5 || opcode==2)
	{
		fprintf(op,"%d\t00\t00\t00\n",lc);
	}
	
	fclose(op);
}

void lit_handler(int lc,char op2[])
{
	FILE* op=fopen("mc.txt","a");
	int i=1;
	char lit[5];
	while(op2[i]!='\'')
	{
		lit[i-1]=op2[i];
		i++;
	}
	lit[i-1]='\0';
	fprintf(op,"%d\t00\t00\t%s\n",lc,lit);
	fclose(op);
}

int main()
{
	load_lt_st();
	//print_lt_st();
	
	char line[50],ins[8],op1[8],op2[8];
	int lc;
	
	FILE* ip=fopen("intermediate.txt","r");
	FILE* op=fopen("mc.txt","w");
	fclose(op);
	
	while(fscanf(ip,"%d\t%s\t%s\t%s",&lc,ins,op1,op2)!=EOF)
	{
		if(ins[1]=='I')
			is_handler(lc,ins,op1,op2);
		else if(ins[1]=='D')
			dl_handler(lc,ins,op1,op2);
		else if(ins[1]=='A')
			//ad_handler(lc,ins,op1,op2);
			continue;
		else if(ins[1]=='-')
			lit_handler(lc,op2);
	}
	
	fclose(ip);
	
	return 0;
}
