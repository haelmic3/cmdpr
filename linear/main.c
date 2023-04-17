#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float f2m3b(float x)
{
	return 2.*x+3;
}
void run(){
	// data generator
	float(*fgen)(float) = f2m3b;
	// random sample over data
	struct{
		struct{	float min; float max; } range;
		float spread;
	} sample = {-100., 100., 0.5};
	// function aproximator
	struct{ float slope; float offset;} aprox={.0,.0};

	// updating function aproximation
	unsigned const       total =  5000; // number of itterations
	unsigned remaining = total;
	float xacc = 0.; // accumulated sample for calculating average
	float yacc = 0.;
	for(;remaining--;)
	{
		int randnumber = rand();
		float randnormal = (float)randnumber/RAND_MAX;
		int fuzznumber = rand();
		float fuzznormal = (float)fuzznumber/RAND_MAX;
		float fuzzfactor = sample.spread*fuzznormal-(sample.spread/2.0);
		// A random number between 0.0 and 1.0 for sampling the range.
		// Floats are less precice as they get bigger at finer resolutions
		// so long as the range is greater than one, the resolution will be as fine as possible.
		float x = randnormal*(sample.range.max-sample.range.min)+sample.range.min + fuzzfactor;
		float y = fgen(x) + fuzzfactor;
		// Let x and y be our dependent variables.
		// With the assumption that this data corrisponds to a linear function.
		float n = total - remaining;
		float aX = (xacc += x) / n;
		float aY = (yacc += y) / n;
		// taking an average. The smaller we stay the more precice the average.
		// the longer this runs things will start going out of hand
		// so it is important that the loop is limited.
		// Using both float and integer hardware, not sure but might help performance.
		//unsigned skip = 1;
		{ // may be a good idea to skip the first 3 as they tend to be bad guesses
			float b = aY - (aprox.slope*aX);
			float m = x-aX?/*(x-aX)*/(y-aY)/((x-aX)/*(x-aX)*/):0;
			//float count = total  - remaining  - skip +1;
			aprox.offset = (aprox.offset + b) /2;
			aprox.slope  = (aprox.slope  + m) /2;
			// Calculating 
		}
		printf(" 2x+3 | %fx+%f ",aprox.slope,aprox.offset);
	}
}
int main(){
	clock_t time_in = clock();
	clock_t time_en;
	srand(0);
	run();
	time_en = clock();
	fflush(stdout);
	fprintf(stderr,"\n");
	printf("%fs\n",((double)time_en-time_in)/CLOCKS_PER_SEC);
	return 0;
}
