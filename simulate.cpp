#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

double rand01(){
	static int needsrand=1;
	if(needsrand){
	  srand(time(NULL));
	  needsrand=0;
	}
	return (rand()/(1.0+RAND_MAX));

}

double birthprob (double bmax, double ration){
	if(ration<=1)
	{
		return bmax/(10*(1-ration)+1);
	}
	else {
		return bmax;
	}
}

double deathprob (double dmin, double ration){
	if(ration<=1){
		return dmin + 1/(10*ration + 1) - 0.09;
	}
	else{
		return dmin;
	}
}

int main(int argc, char *argv[]){
	double population;
	double popgrowth;
	int nyears;
	int year;
	int individual;
	double food;
	double ration;
	double bmax, dmin;
	double bprob, dprob;
	FILE *output;

	if(argc !=7)
	{
	printf("Syntax: Not the correct amount of arguments\n");
	exit(1);
	}

	population = atof(argv[1]);
	food = atof(argv[2]);
	bmax = atof(argv[3]);
	dmin = atof(argv[4]);
	nyears = atoi(argv[5]);
	output = fopen(argv[6],"w");

	for(year=0; year<nyears; year++){
	ration = food/population;
	bprob = birthprob(bmax, ration);
	dprob = deathprob(dmin, ration);
	popgrowth = 0;
		for(individual=0; individual<population; individual++){
			if(rand01()<bprob){
				popgrowth++;
			}
			if(rand01()<dprob){
				popgrowth--;
			}
		}
		population+=popgrowth;
		fprintf(output, "%d %lf %lf %lf %lf %lf\n", year, population, popgrowth, bprob, dprob, ration);
	}


}
