#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main ( int argc, char *argv[]){
  const int nbins=50;
  int bin[nbins];
  double binwidth;
  int binno;
  int overunderflow=0;
  int i;
  FILE *input;
  FILE *output;
  double popmin = atof(argv[1]);
  double popmax = atof(argv[2]);
  int year;
  double population;
  double popgrowth;
  double bprob;
  double dprob;
  double ration;

  if(argc!=5)
  {
	printf("Syntax: Incorrect amount of arguments\n");
	exit(1);
  }

  input = fopen(argv[3], "r");
  output = fopen(argv[4], "w");
  
  for(i=0;i<50;i++)
  {
	bin[i]=0;

  }

  binwidth = (popmax-popmin)/nbins;

  while(fscanf(input, "%d %lf %lf %lf %lf %lf", &year, &population, &popgrowth, &bprob, &dprob, &ration) !=EOF){
	binno = (population-popmin)/binwidth;
	
	if(binno<0 || binno>=50)
	{
		overunderflow++;
		continue;
	}

	bin[binno]++;
  }
  fclose(input);

  for(i=0;i<50;i++){
	population = popmin + binwidth*(0.5+i);
	fprintf(output, "%lf %d\n",population, bin[i]);
  }
  fprintf(output,"# Saw %d over/underflows\n",overunderflow);
  fclose(output);
}
