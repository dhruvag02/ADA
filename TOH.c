#include<stdio.h>

void TOH(int n,char src,char temp,char dest);
int main()
{
int n;
char src='A',temp='B',dest='C';
printf("Enter number of discs\n");
scanf("%d",&n);
TOH(n,src,temp,dest);
return 0;
}

void TOH(int n,char src,char temp,char dest)
{
if(n==1)
{printf("Move %d from %c to %c\n",n,src,dest);
return;}
TOH(n-1,src,dest,temp);
printf("Move %d from %c to %c\n",n,src,dest);
TOH(n-1,temp,src,dest);
}

