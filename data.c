#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void formatHelp() {
    fprintf(stderr, "TruthGen v2.0.0\n");
    fprintf(stderr, "Usage: truthGen [binary expression]\n\n");
    fprintf(stderr, "Description: The TruthGen utility reads a boolean expression from the command line,\n");
    fprintf(stderr, "and prints the corresponding truth table for all possible combinations of the expression.\n");
    fprintf(stderr, "For proper usage, ensure that all variables and subexpressions are bracketed [Ex. ((p)&(q))]\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "\t--help: Display this help text.\n");
    fprintf(stderr, "\t--usage: Display usage of TruthGen utility.\n");
    fprintf(stderr, "Available Operators: \n");
    fprintf(stderr, "\t& : Performs an AND operation.\n");
    fprintf(stderr, "\t| : Performs an OR operation.\n");
    fprintf(stderr, "\t~ : Performs a NOT operation.\n");
    fprintf(stderr, "Examples: \n");
    fprintf(stderr, "\ttruthGen '((p)|(q))'\n");
    fprintf(stderr, "\ttruthGen '((p)&(q)|(~(r)))'\n");
    fprintf(stderr, "This will output a truth table with all the possible permutations of the provided boolean expressions.\n");

    exit(0);
}



void usage()
{
	fprintf(stderr,"truthGen [binairy expression]");
	fprintf(stderr, "\t& : Performs an AND operation.\n");
	fprintf(stderr, "\t| : Performs an OR operation.\n");
   	fprintf(stderr, "\t~ : Performs a NOT operation.\n");
	fprintf(stderr, "For proper usage, ensure that all variables and subexpressions are bracketed [Ex. ((p)&(q))]\n"); 	
}
