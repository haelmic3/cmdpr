#include<stdio.h>

typedef int Type;
typedef union type4{Type array[4];struct{Type a;Type b;Type c;Type d;};}Type4;
typedef union type3{Type array[3];struct{Type a;Type b;Type c;};}Type3;

Type sum(const Type a, const Type b)
{
	return a + b;
}
Type product(const Type a, const Type b)
{
	return a * b;
}
Type difference(const Type a, const Type b)
{
	return a - b;
}
Type quotent(const Type a, const Type b)
{
	return a / b;
}
Type copy(const Type c)
{
	return c;
}
Type negitive(const Type a)
{
	return -a;
}
Type4 fiboabbox(const Type a, const Type b)
{
	Type4 r;
	Type* rp = r.array;
	Type s = sum(a,b);
	Type t = sum(s,b);
	rp[0] = copy(a);
	rp[1] = copy(b);
	rp[2] = s;
	rp[3] = t;
	return r;
}
void printbox(Type4 r)
{
	printf("%d, %d, %d, %d",r.a,r.b,r.c,r.d);
}
Type3 pythtri(const Type4 r)
{
	Type3 t;
	Type *tp = t.array;
	const Type u = r.b;
	const Type v = r.c;
	const Type uu = product(u,u);
	const Type vv = product(v,v);
	const Type uv = product(u,v);
	tp[0] = difference(vv,uu);
	tp[1] = sum(uv,uv);
	tp[2] = sum(vv,uu);
	return t;
}
int main()
{
	printbox(fiboabbox(1,1));
	fflush(stdout);
	fprintf(stderr, "\n");
}
