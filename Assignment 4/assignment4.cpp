/********************************************************************* 
 ** Program Filename: assignment4
 ** Author: Brandon Lee
 ** Date: 2/27/14
 ** Description: Assignment 4
 ** Input: An integer (for determining which function), starting value (float), ending value (float), method (int), # of rectangle/trapezoid (double)
 ** Output: Area under curve (double)
 *********************************************************************/ 
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

//DECLARE ALL THE PROTOTYPES
//The function number
void funt1(double, double, int, double);
void funt2(double, double, int, double);
void funt3(double, double, int, double);
void funt4(double, double, int, double);
void funt5(double, double, int, double);

//Function 1 Rectangle and Trapezoid
void funt1_rect(double, double, double);
void funt1_trapz(double, double, double);

//Function 2 Rectangle and Trapezoid
void funt2_rect(double, double, double);
void funt2_trapz(double, double, double);

//Function 3 Rectangle and Trapezoid
void funt3_rect(double, double, double);
void funt3_trapz(double, double, double);

//Function 4 Rectangle and Trapezoid
void funt4_rect(double, double, double);
void funt4_trapz(double, double, double);

//Function 5 Rectangle and Trapezoid
void funt5_rect(double, double, double);
void funt5_trapz(double, double, double);

//Chooses which function
void which_funt(int, double, double, int, double);


/*********************************************************************
 ** Function: main
 ** Description: Prompts user to input all command line arguements for the function.
 ** Parameters: floats, ints, strings
 ** Pre-Conditions: Must have correct number of arguements
 ** Post-Conditions: The final number must be a double
 *********************************************************************/
int main(int argc, char*argv[])
{
	float a, b, n;
	int f, m;
	string funt, start_point, end_point, method, deltax, test;
	if(argc!=11) //Check if enough inputs
	{
		cout << "Please input correct number of inputs." << endl;
		return 0;
	}
	for(int i=1; i<=9; i=i+2)
	{
		test=argv[i];

		if(test.at(1)=='f')
		{
			funt=argv[i+1];
			f=atoi(funt.c_str());
		}
		if(test.at(1)=='a')
		{
			start_point=argv[i+1];
			a=atoi(start_point.c_str());
		}
		if(test.at(1)=='b')
		{
			end_point=argv[i+1];
			b=atoi(end_point.c_str());
		}
		if(test.at(1)=='m')
		{
			method=argv[i+1];
			m=atoi(method.c_str());
		}
		if(test.at(1)=='n')
		{
			deltax=argv[i+1];
			n=atoi(deltax.c_str());
		}
	}
	which_funt(f, a, b, m, n);
	return 0;
}

/*********************************************************************
 ** Function: funt1 - funt5
 ** Description: Determines which method the user wants to take
 ** Parameters: An integer (m)
 ** Pre-Conditions: The number inputted must be 1-3.
 ** Post-Conditions: The final number must only contain 1's and 0's
 *********************************************************************/

//Function 1
void funt1(double a, double b, int m, double n)
{
	if(m==1)
	{
		funt1_rect(a, b, n);
	}
	if(m==2)
	{
		funt1_trapz(a, b, n);
	}
	if(m==3)
	{
		funt1_rect(a, b, n);
		funt1_trapz(a, b, n);
	}
}
//Function 2
void funt2(double a, double b, int m, double n)
{
	if(m==1)
	{
		funt2_rect(a, b, n);
	}
	if(m==2)
	{
		funt2_trapz(a, b, n);
	}
	if(m==3)
	{
		funt2_rect(a, b, n);
		funt2_trapz(a, b, n);
	}
}
//Function 3
void funt3(double a, double b, int m, double n)
{
	if(m==1)
	{
		funt3_rect(a, b, n);
	}
	if(m==2)
	{
		funt3_trapz(a, b, n);
	}
	if(m==3)
	{
		funt3_rect(a, b, n);
		funt3_trapz(a, b, n);
	}
}
//Function 4
void funt4(double a, double b, int m, double n)
{
	if(m==1)
	{
		funt4_rect(a, b, n);
	}
	if(m==2)
	{
		funt4_trapz(a, b, n);
	}
	if(m==3)
	{
		funt4_rect(a, b, n);
		funt4_trapz(a, b, n);
	}
}
//Function 5
void funt5(double a, double b, int m, double n)
{
	if(m==1)
	{
		funt5_rect(a, b, n);
	}
	if(m==2)
	{
		funt5_trapz(a, b, n);
	}
	if(m==3)
	{
		funt5_rect(a, b, n);
		funt5_trapz(a, b, n);
	}
}

/*********************************************************************
 ** Function: funct1_rect - funct5_trapz
 ** Description: Takes values from before (a, b, n) and determines n value and solves for integral using rectangle or trapezoid method
 ** Parameters: Doubles
 ** Pre-Conditions: The number of rectangles inputted must be a positive double.
 ** Post-Conditions: The final number must be a double
 *********************************************************************/

//Function 1 Rectangle
void funt1_rect(double a, double b, double n)
{
	double dx, i, sum=0;
	cout << "Using Function 1 (rectangles)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+=(2*pow(i, 5)+pow(i,3)-10*i+2)*dx;
	}
		cout << "The area under the curve is: " << sum << endl;
}
//Function 1 Trapezoid
void funt1_trapz(double a, double b, double n)
{
	double dx, i, sum;
	cout << "Using Function 1 (trapezoids)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+= (.5*(dx*((2*pow(i, 5)+pow(i,3)- 10*i + 2)+(2*pow(i+dx, 5)+pow(i+dx, 3)-(i+dx)*10 +2))));
	}
		cout << "The area under the curve is: " << sum << endl;
}

// Function 2 Rectangle
void funt2_rect(double a, double b, double n)
{
	double dx, i, sum;
	cout << "Using Function 2 (rectangles)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+=(6*pow(i, 2) - i + 10)*dx;
	}
		cout << "The area under the curve is: " << sum << endl;
}
//Function 2 Trapezoid
void funt2_trapz(double a, double b, double n)
{
	double dx, sum, i;
	cout << "Using Function 2 (trapezoids)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+= (dx*((6*pow(i, 2)- i + 10)+(6*pow(i+dx, 2)-(i+dx) +10)))*.5;
	}
		cout << "The area under the curve is: " << sum << endl;	
}

//Function 3 Rectangle
void funt3_rect(double a, double b, double n)
{
	double dx, sum, i;
	cout << "Using Function 3 (rectangles)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+=((5*i +3)*dx);
	}
		cout << "The area under the curve is: " << sum << endl;
}
//Function 3 Trapezoid
void funt3_trapz(double a, double b, double n)
{
	double i, dx, sum;
	cout << "Using Function 3 (trapezoids)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+= (dx*((5*i+3)+(5*(i+dx)+3)))*.5;
	}
		cout << "The area under the curve is: " << sum << endl;
}

//Function 4 Rectangle
void funt4_rect(double a, double b, double n)
{
	double i, dx, sum;
	cout << "Using Function 4 (rectangles)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+=((2*pow(i,3) +120)*dx);
	}
		cout << "The area under the curve is: " << sum << endl;		
}
//Function 4 Trapezoid
void funt4_trapz(double a, double b, double n)
{
	double dx, i, sum;
	cout << "Using Function 4 (trapezoids)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx){
		sum+= (dx*((2*pow(i,3)+ 120) + (2*pow(i+dx,3)+ 120)))*.5;
	}
		cout << "The area under the curve is: " << sum << endl;	
}

//Function 5 Rectangle
void funt5_rect(double a, double b, double n)
{
	double dx, i, sum;
	cout << "Using Function 5 (rectangles)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+=(2*pow(i,2))*dx;
	}
		cout << "The area under the curve is: " << sum << endl;		
}
//Function 5 Trapezoid
void funt5_trapz(double a, double b, double n)
{
	double dx, sum, i;
	cout << "Using Function 5 (trapezoids)" << endl;
	dx= (b-a)/n;
	for(i=a; i<b; i+=dx)
	{
		sum+= (dx*((2*pow(i,2)) + (2*pow(i+dx,2))))*.5;
	}
		cout << "The area under the curve is: " << sum << endl;
}


/*********************************************************************
 ** Function: which_funt
 ** Description: Determines which function the user wants to integrate
 ** Parameters: An integer
 ** Pre-Conditions: The number inputted must be a between 1 -5
 ** Post-Conditions: The output must be a function
 *********************************************************************/
//Chooses which function you want you use.
void which_funt(int f, double a, double b, int m, double n)
{
	if(f==1)
	{
		funt1(a, b, m, n);
	}
	if(f==2)
	{
		funt2(a, b, m, n);
	}
	if(f==3)
	{
		funt3(a, b, m, n);
	}
	if(f==4)
	{
		funt4(a, b, m, n);
	}
	if(f==5)
	{
		funt5(a, b, m, n);
	}
}