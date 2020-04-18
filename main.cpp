/*
** EPITECH PROJECT, 2020
** 110borwein
** File description:
** main
*/

//libC
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h> 

//mylibs
#include "borwein.h"

//namespaces
using namespace std;

//functions

int display_usage()
{
	cout << "USAGE" << endl;
	cout << "    ./110borwein n" << endl << endl;
	cout << "DESCRIPTION" << endl;
	cout << "    n    constant defining the integral to be computed" << endl;
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		perror("wrong number of arguments, exit program\n");
		return 84;
	}
	if (!strcmp(argv[1], "-h"))
		return display_usage();
	int n = 0;
	try {
		n = stoi(argv[1]);
	} catch (invalid_argument const &e) {
        perror("not an int, exit program\n");
    	return 84;
    } catch ( out_of_range const &e) {
        perror("overflow error, exit program\n");
    	return 84;
    }
	if (n < 0)
		return 84;
	return borwein(n);
}
