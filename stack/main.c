#include<stdio.h>
#include<string.h>

int main()
{
	const char a[]={'H','e','l','l','o',',',' '};
	const char b[]={'W','o','r','l','d','!','\n',0};
	char c[sizeof(a)+sizeof(b)];

	strncpy(c,a,sizeof(a));
	strncpy(&c[sizeof(a)],b,sizeof(b));
	
	printf("%s",c);
	return 0;
}
