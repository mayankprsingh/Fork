
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
int n=0,i;
pid_t pid;
printf("Enter the digit :\n");
scanf("%d",&n);
if(n>0)
{
pid = fork();
if(pid == 0)
{
printf("Child is producing a sequence....\n");
for(i=n;i>=1;i=i/2)
{
printf("%d ",i);
}
printf("\nChild ends\n");
}
else
{
printf("Parent is waiting for child to complete....\n");
wait(NULL);
printf("Parent emds\n");
}
}
else if(n==0)
{
printf("With this input sequence can't be produced further\n");
}
else
{
printf("Invalid Input\nPLease Enter a non-negative integer\n");
main();
}

return 0;
}
