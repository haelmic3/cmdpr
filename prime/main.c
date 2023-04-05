#include<stdio.h>
#include<stdlib.h>
typedef double type;
type tdmod(type x,type m)
{
	return x - (long long)(x/m) * m;
}
type factorial(type n)
{
	type a = n;
	for(;--n;)a*=n;
	return a;
}

int wilson(type n)
{
	return tdmod(factorial(n-(type)1)+(type)1,n);
}
int main()
{
	int d;
	printf("Enter number value:");
	scanf("%d",&d);
	printf("Hello, World!\n%d\n%s\n",d,wilson(d)?"prime":"not prime");
	return 0;
}
