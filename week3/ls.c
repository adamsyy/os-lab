#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#define DATA_SIZE 1000
void lsandgrep(){
 char fn[10],pat[10],temp[200];
FILE *fp;
char dirname[10];
DIR*p;
struct dirent *d;
printf("Enter directory name\n");
scanf("%s",dirname);
p=opendir(dirname);
if(p==NULL)
  {
  perror("Cannot find directory");
  exit(0);
  }
while(d=readdir(p))
  printf("%s\n",d->d_name);


}
int main(){
		lsandgrep();
		return 0;
}