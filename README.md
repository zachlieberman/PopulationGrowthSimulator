# PopulationGrowthSimulator
Final Project that generated data, tables, and graphs for population growth.

Analyze.cpp: Imports lopop and analyzes the data by mean and standard deviation. 

Hipop.dat: Data file with Higher population numbers organized by year, population, popgrowth, bprob, dprob, ration in that order.

Lowpop.dat: Data file with Lower population numbers organized by year, population, popgrowth, bprob, dprob, ration in that order.

Mepop.dat: Data file with Medium population numbers organized by year, population, popgrowth, bprob, dprob, ration in that order.

Simulate.cpp: The first program run that creates random numbers and places them in bins based on how large or small they are. This dat file is then used in Analyze.cpp

Visualize.cpp: Takes analyzed results and displays it to the user as a dat file (visualize.dat).

Visualize.dat: Is used in GNU plot as a graph to show results of population growth.

HOW TO RUN: 
1. In the terminal, type 'g++ -Wall -o simulate simulate.cpp', then type './simulate', this creates the numbers and sends info to a dat file.
2. In the terminal, type 'g++ -Wall -o analyze analyze.cpp', then type './analyze', this finds the mean and std dev and sends info in a dat file.
3. In the terminal, type 'g++ -Wall -o visualize visualize.cpp', then type './visualize',this creates the graph that displays the results and puts it in a dat file.
4. In the terminal, if you have GNU plot, type 'gnu plot' to enter GNU plot and in there type 'plot "visualize.dat" and the final graph will appear.
