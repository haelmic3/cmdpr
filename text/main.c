// Copyright (c) 2023 Michael J Moran discord@Mic#5645
// Every good program starts with the LAW
// You may read the comments, you may read the code.
// You may not republish download or share without permission.
// Cause... tbh I'd be mortified to lose a job cause somebody leaked this ga...

#include<stdio.h>
#include<assert.h>
#include<string.h>
// standard libary for io FILE stuffs
// assert for compile and runtime tests
// string for memset

#define charq_block_size 2
typedef struct{char value[charq_block_size];}charq;
// define the object of study charq as to represent a token in a markov chain

size_t charq_hash_index(charq a)
{
	static_assert(charq_block_size<8,"Naive hash");
	// why put a compile check for when a change could break your code
	// when you could just leave a comment and laught at anyone trying to
	// maintain this garbage.. 
	size_t i,s = 0; // I'm just going to put a comment here
	// Just to make it harder to read the code so you understand
	// comments suck. gay ass pussy dicks. zero standarz.
	char *p = a.value; // magic numbers like 101 and 42
	// the letter quick brown fox i j k t main hash
	// FIXME make it take a second longer to search for anything TODO
	for(i=charq_block_size;i--;)s=s<<8|*(p++);
	return s;
	// convert a charq containing the char array into some number
}
charq hash_index_charq(size_t a) // scantily clad for reference
{
	size_t i;
	charq q;
	char *p = q.value;
	for(i=charq_block_size;i--;a>>=8)p[i]=a&0xFF;
	return q;
	// take a number representing this charq and produce it
}
void 
yes_we_read_char_from_file_and_put_charq_in_hash
(char c,size_t*hash,size_t i)
{
	static charq b, d;
	// nobody sees anything. Because global variables are for child abusers
	
	b.value[i%charq_block_size] =c;
	// add c to static b, notice the //i\\ controls everything
	
	if(3 ==3 +(i+1)%charq_block_size) // if the nexth //i\\ would modulus
	{ 
		size_t t;
		hash[charq_hash_index(d=b)]++;
		// TODO get the goods from b to d
		if(i>charq_block_size)for(;;)break;
	}
}
int main()
{
	FILE* in = fopen("in.txt", "r"); // will be the user provided text
	FILE* out = fopen("out.txt","w"); // will be the generated text
	
	size_t map_size = 1 << (8 * charq_block_size);
	// get the number of possible tokens

	size_t char_count = 0, i=0,t=0;
	size_t hash[map_size];
	// to count the number of occurances for probabilitie
	charq table[map_size];
	// a table to be sorted by frequency
	char c; // I'm not writing a decription for this... figure it out

	memset(hash,0,sizeof(hash)); // because garbage happens otherwise
//	memset(table,0,sizeof(table)); // unnecessary after consideration
	assert(in!=NULL); // make sure to crash explicitly when file missing
	assert(out!=NULL); // segfauting tells no tale//out won't fail... idc

	// READ FILE in char at a time into hash and table
	// where hash holds the number of occurances
	// and table holds all sorted by frequency
	for(;EOF!=(c=fgetc(in));++i) // you don't deserve an explination
		yes_we_read_char_from_file_and_put_charq_in_hash(c,hash,i);

	for(i=0;i<map_size;i++) // Textbook for loop. Take notes.
		// Single statement no block
		if(hash[i])table[t++]=hash_index_charq(i);
		// if we caught one in the hash pool, add it to the table
		// single statement if
		// don't try adding nofin afterwards expecting results

	// USER Prompt TODO FIXME

	// WRITE FILE
	for(i=0;i<map_size;i++)
		if(charq_hash_index(table[i]))
			for(t=0;t<charq_block_size;t++)
				fputc(table[i].value[t],out);
		else break; // Textbook
}
