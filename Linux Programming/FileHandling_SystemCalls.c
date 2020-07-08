#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int ch,fd,n; 
	char block[20]; 
	char title[]="No. Name   Salary";
	
	do{
		printf("\nMENU\n\t1.Create new file\n\t2.Write to file\n\t3.Read from file\n\t4.Exit\n\nPlease select a choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
      		fd = creat("tmp1.txt", S_IRUSR|S_IWUSR);
      		write(fd,title,sizeof(title)-1);
      		write(fd,"\n",1);
      		close(fd);
      		printf("\nFile Created Successfully\n");
			break;
			case 2:
printf("\nEnter emp no, emp name ,emp salary in single line\n");
memset(block,'\0',100);
	 fd = open("tmp1.txt",O_WRONLY|O_APPEND , S_IRUSR|S_IWUSR);
				
	while( n=read(0,block,100) )	
     	{
     	      if(n==1) { break; }
      	 n=write(fd,block,n);
        	 memset(block,'\0',100); 
     	}
   			    close(fd);
   			    printf("\nData written successfully\n");
				break;
			case 3:
				 memset(block,'\0',100);
			    fd = open("tmp1.txt",O_RDONLY, S_IRUSR);
   			    while( n= read(fd,block,100) )
   			    {
   			    	if(n==1) { break; }
    				printf("%s",block);
     			    memset(block,'\0',100);
      		    }
    		   close(fd);   
				break;		
			case 4:
				break;
			default: printf("\nInvalid choice ! \n");
		}
	}while(ch!=4);
	return 0;
}

