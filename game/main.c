#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//#define NDEBUUG // uncommented for removing code validation
#include<assert.h>


// WARNING buffer is assumed valid pointer to size memory
char* clear_buf(char*buffer,size_t size)
{
	size_t i,progress;
	assert(buffer!=NULL);
	// cannot assert buffer is valid memory
	assert(size);
	for(i = 0, progress = size; progress--; i++)
	{
		buffer[i] = 0;
	}
	return buffer;
}
void fprint_period(FILE*out,clock_t start, clock_t end)
{
	clock_t period = end - start;
	fprintf(out,"%lu.%07lusec",period/CLOCKS_PER_SEC,period%CLOCKS_PER_SEC*1000000/CLOCKS_PER_SEC);
}
int neol(int c)
{
	return c != '\n' && c != EOF && c!='\0';
}
#define BUF_CAP 128

int main(int argc,char* *argv)
{
	size_t buf_size;
	char buf[BUF_CAP];
	
	time_t tt_start, tt_end;
	clock_t ct_start, ct_end;
	printf("Starting\n");
	system("sleep 0");
	printf("Press Enter\n");
	tt_start = time(NULL);
	ct_start = clock();
	{
		buf_size = 0;
		while(neol(buf[buf_size++] = fgetc(stdin))) if(buf_size>=BUF_CAP)buf_size = BUF_CAP-1;
		if(buf_size>=BUF_CAP)buf_size = BUF_CAP-1;
		buf[buf_size] = 0;
	}
	ct_end=clock();
	tt_end=time(NULL);
	printf("After aproximately %ld seconds and ",tt_end-tt_start);
	fprint_period(stdout,ct_start,ct_end);
	printf(" of CPU time:\n%s\nwas written.\n",buf);
	
	return 0;
}
