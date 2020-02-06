#include<stdio.h>
int GCD(int m,int n);
int main()
{
int m,n,G;
printf("Enter first number\n");
scanf("%d",&m);
printf("Enter second number\n");
scanf("%d",&n);
G=GCD(m,n);
printf("GCD of %d and %d=%d\n",m,n,G);
return 0;
}

int GCD(int m,int n)
{
if(n==0)
return m;
else 
return (GCD(n,m%n));
}

