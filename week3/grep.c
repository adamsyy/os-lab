#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include <fcntl.h>
int count=0;
void match_pattern(char *argv[])
{
    int fd,r,j=0;

    char temp,line[100];
    if((fd=open(argv[2],O_RDONLY)) != -1)
    {
        while((r=read(fd,&temp,sizeof(char)))!= 0)
        {
            if(temp!='\n')
            {
                line[j]=temp;
                j++;
            }
            else
            {
                if(strstr(line,argv[1])!=NULL){
										count++;
                    printf("%s\n",line);
									}
								
										
                memset(line,0,sizeof(line));
                j=0;
            }

        }
    }   
}

main(int argc,char *argv[])
{
    struct stat stt;
    if(argc==3)
    {
        if(stat(argv[2],&stt)==0){
				match_pattern(argv);
				printf("Occurences:  %d",count);
}
            

        else 
        {
            perror("stat()");
            exit(1);
        }
    }
}