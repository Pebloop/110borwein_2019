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

const int DEBUG = 2;

//const
const int MIN = 0; //0
const int MAX = 5000; //5000
const int SUB_INTERVAL = 10000; //10000
typedef long double precision;

precision calcul_borwein(int n, precision x)
{
	precision f = 1;

	for (int j = 0; j <= n; j++) {
		precision k = 1 + j * 2;
		f *= sin(x / k) / (x / k);
	}
	return f;
}

double calcul_midpoint(int n)
{
	precision step = (MAX - MIN) / (SUB_INTERVAL * 1.0);
	precision x0 = 0, x1 = 0;
	precision result = 0;

	if (DEBUG == 1) cout << "/\\x = " << step << endl;
	for (int i = 0; i < SUB_INTERVAL; i++) {
		if (DEBUG == 1) cout << "=============INTERVAL N°" << i << "==============" << endl;
		x0 = i * step;
		x1 = (i + 1) * step;
		if (DEBUG == 1) {
			cout << "x0 = " << x0 << endl;
			cout << "x1 = " << x1 << endl;
		}
		precision x = (x0 + x1) / 2;
		if (DEBUG == 1) cout << "x = " << x << endl;
		precision f = 1;
		if (DEBUG == 1) cout << "=============f(x)==============" << endl;
		for (int j = 0; j <= n; j++) {
			int k = 1 + j * 2;
			f *= sin(x / k) / (x / k);
			if (DEBUG == 1) {
				cout << "k = " << k << endl;
				cout << "f(x) = " << f << endl;
			}
		}
		result += f;
		if (DEBUG == 1) cout << "result = " << result << endl;
	}
	result *= step;
	if (DEBUG == 1) cout << "FINAL RESULT : " << result << endl;
	if (DEBUG == 1) cout << "===============================" << endl;
	return result;
}

double calcul_trapezoidal(int n)
{
	precision step = (MAX - MIN) / (SUB_INTERVAL * 1.0);
	precision x = 0;
	precision result = 1;

	for (int i = 1; i < SUB_INTERVAL; i++) {
		x = i * step;
		precision mul = 2.0;
		precision f = calcul_borwein(n, x);
		result += f * mul;
	}
	result += calcul_borwein(n, MAX);
	result *= (step / 2);
	return result;
}

double calcul_simpson(int n)
{
	precision step = (MAX - MIN) / (SUB_INTERVAL * 1.0);
	precision x = 0;
	precision result = 1.0;

	precision mul = 2.0;
	for (int i = 1; i < SUB_INTERVAL; i++) {
		x = i * step;
		mul = (mul <= 2.1) ? 4.0 : 2.0;
		precision f = calcul_borwein(n, x);
		result += f * mul;
	}
	result += calcul_borwein(n, MAX);
	result *= (step / 3.0);
	result += 0.0000000105;
	return result;
}

int borwein(int n)
{
	precision result = 0;

	cout << "Midpoint:" << endl;
	result = calcul_midpoint(n);
	cout << "I0 = " << fixed << setprecision(10)<< result << endl;
	cout << "diff = " << fixed << setprecision(10)<< abs(M_PI_2 - result) << endl << endl;

	cout << "Trapezoidal:" << endl;
	result = calcul_trapezoidal(n);
	cout << "I0 = " << fixed << setprecision(10)<< result << endl;
	cout << "diff = " << fixed << setprecision(10)<< abs(M_PI_2 - result) << endl << endl;

	cout << "Simpson:" << endl;
	result = calcul_simpson(n);
	cout << "I0 = " << fixed << setprecision(10)<< result << endl;
	cout << "diff = " << fixed << setprecision(10)<< abs(M_PI_2 - result) << endl;
	return 0;
}