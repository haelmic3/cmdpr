#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>

#define rlu(x) (x<0?0:x)
#define sum(a,b) (a+b)
/**/typedef double type;
// */typedef int type;
typedef size_t size;

typedef struct graph{
	type*block;
	size size;
}graph;

uint64_t raxor64seed(uint64_t n)
{
	static uint64_t a = 1082269761;
	if(n)a = n;
	return a;
}
uint64_t raxor64()
{
	uint64_t x = raxor64seed(0);
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return raxor64seed(x);
}
type raxnorm()
{
	uint64_t n = raxor64();
	type r = n/18446744073709551616.;
	return r;//?r:(n>>(1+8*sizeof(type)));
}
type* vec_sum_len_out_vec(const size n, type*a,  const type * b)
{
	size i;
	type*e = a;
	for(i=n; i--; a++,b++)*a = sum(*a,*b);
	return e;
}
type* vec_sum_len_out_vec_vec(const size n, type*out, const type* a, const type* b)
{
	size i;
	type*e = out;
	for(i=n; i--; e++,a++,b++)*e = sum(*a, *b);
	return out;
}
size size_sum_len_vec(size n, const size* a)
{
	size t;
	for(;n--;a++)t+=*a;
	return t;
}
type type_sum_len_vec(size n, const size* a)
{
	type t;
	for(;n--;a++)t+=*a;
	return t;
}
void program()
{
	size layout[] = {8,4,2,1,2,4,8};
	size size = sizeof(layout)/sizeof(size);
	type data[size_sum_len_vec(size,layout)];
	
}
int main()
{
	fprintf(stderr, "\n");
	program();
	fflush(stdout);
	fprintf(stderr, "\n\n");
	return 0;
}
