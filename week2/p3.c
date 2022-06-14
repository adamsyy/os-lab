#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
int pid,pid1,pid2;


pid=fork();
if(pid==-1)
{
printf("ERROR IN PROCESS CREATION \n");
exit(1);
}
if(pid!=0)
{
int i=10;
printf("PARENT PROCESS%d\n", i+1);
}
else
{
int i=20;
printf("CHILD PROCESS %d\n", i-1);
}
}
