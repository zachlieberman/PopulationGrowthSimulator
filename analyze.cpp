#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc, char*argv[]){
	int year;
	double population, popgrowth;
	int popmin, popmax;
	double dprob, bprob, ration;
	double sum=0;
	double sum2=0;
	double mean, stddev;
	int nvalues=0;
	FILE *input;

	if(argc!=4)
	{
		printf("Syntax: Incorrect amount of arguments\n");
		exit(1);
	}
	popmin = atof(argv[1]);
	popmax = atof(argv[2]);
	input = fopen(argv[3], "r");
	

	while(fscanf(input, "%d %lf %lf %lf %lf %lf", &year, &population, &popgrowth, &bprob, &dprob, &ration)!=EOF){
		if(population>=popmin&&population<=popmax){
		sum+=population;
		sum2+=pow(population, 2);
		nvalues++;
		}
	}

	mean=sum/nvalues;
	stddev = sqrt( (sum2-sum*sum/nvalues)/(nvalues-1) );

	printf("Mean population = %lf\n",mean);
	printf("Std. dev. = %lf\n", stddev);

}
