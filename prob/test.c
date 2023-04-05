void raxnorm_distribution()
{
	const size count = 1LLU<<28;
	size i = count;
	size total = 0;
	type sum = 0.;
	type max = - INFINITY;
	type min = INFINITY;
	for(;--i;)
	{
		type r = raxnorm();
		sum += r;
		max = r > max ? r : max;
		min = r < min ? r : min;
		total+=(r<.5?0:1);
	}
	printf("max: %f\n",max);
	printf("min: %f\n",min);
	printf("mean: %f\n",sum/count);
	printf("%zu/%zu %f",total,count,((double)total)/((double)count));
}
