/*
** EPITECH PROJECT, 2020
** 110borwein
** File description:
** 110borwein
*/

//libC
#include <iostream>
#include <iomanip>
#include <math.h> 

//mylibs
#include "borwein.h"

//namespaces
using namespace std;

const int DEBUG = 0;

//const
const int MIN = 0; //0
const int MAX = 5000; //5000
const int SUB_INTERVAL = 10000; //10000
typedef long double precision;

double calcul_midpoint(int n)
{
	precision step = (MAX - MIN) / (SUB_INTERVAL * 1.0);
	precision x0 = 0, x1 = 0;
	precision result = 0;

	if (DEBUG) cout << "/\\x = " << step << endl;
	for (int i = 0; i < SUB_INTERVAL; i++) {
		if (DEBUG) cout << "=============INTERVAL N°" << i << "==============" << endl;
		x0 = i * step;
		x1 = (i + 1) * step;
		if (DEBUG) {
			cout << "x0 = " << x0 << endl;
			cout << "x1 = " << x1 << endl;
		}
		precision x = (x0 + x1) / 2;
		if (DEBUG) cout << "x = " << x << endl;
		precision f = 1;
		if (DEBUG) cout << "=============f(x)==============" << endl;
		for (int j = 0; j <= n; j++) {
			int k = 1 + j * 2;
			f *= sin(x / k) / (x / k);
			if (DEBUG) {
				cout << "k = " << k << endl;
				cout << "f(x) = " << f << endl;
			}
		}
		result += f;
		if (DEBUG) cout << "result = " << result << endl;
	}
	result *= step;
	if (DEBUG) cout << "FINAL RESULT : " << result << endl;
	if (DEBUG) cout << "===============================" << endl;
	return result;
}

double calcul_trapezoidal(int n)
{
	return 0;
}

double calcul_simpson(int n)
{
	return 0;
}

int borwein(int n)
{
	double result = 0;

	cout << "Midpoint:" << endl;
	result = calcul_midpoint(n);
	cout << "IO = " << fixed << setprecision(10)<< result << endl;
	cout << "diff = " << fixed << setprecision(10)<< abs(M_PI_2 - result) << endl << endl;

	cout << "Trapezoidal:" << endl;
	result = calcul_trapezoidal(n);
	cout << "IO = " << fixed << setprecision(10)<< result << endl;
	cout << "diff = " << fixed << setprecision(10)<< abs(M_PI_2 - result) << endl << endl;

	cout << "Simpson:" << endl;
	result = calcul_simpson(n);
	cout << "IO = " << fixed << setprecision(10)<< result << endl;
	cout << "diff = " << fixed << setprecision(10)<< abs(M_PI_2 - result) << endl;
	return 0;
}