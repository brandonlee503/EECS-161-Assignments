#include <iostream>
#include <cmath>
using namespace std;

void which_func();
void f1();
void f2();
void f3();
void f4();
void f5();
float a_prompt();
float b_prompt();
void f1_rect(float, float);
void f1_trap(float, float);
void f2_rect(float, float);
void f2_trap(float, float);
void f3_rect(float, float);
void f3_trap(float, float);
void f4_rect(float, float);
void f4_trap(float, float);
void f5_rect(float, float);
void f5_trap(float, float);
int choose_method();

int main()
{
	which_func();
	return 0;
}

void which_func()
{
	int func;
	cout<<"which function? 1=2x^5+x^3-10x+2, 2=6x^2-x+10, 3= 5x+3, 4= 2x^3 +120, 5= 2x^2"<<endl;
	cin>>func;
	if (func==1)
		f1();
	else if (func==2)
		f2();
	else if (func == 3)
		f3();
	else if (func == 4)
		f4();
	else if (func == 5)
		f5();
}

float a_prompt()
{
	float a;
	cout<<"what do you want your first bound (a) to be?"<<endl;
	cin>> a;
	return a;
}

float b_prompt()
{
	float b;
	cout<<"what do you want your second boudn (b) to be?"<<endl;
	cin>> b;
	return b;
}

void f1()
{
	float a, b, rect_choice, play_again, method; //boundaries where a= start and b = end
	a= a_prompt();
	b = b_prompt();
	method= choose_method();
	if (method==1)
		f1_rect(a, b);
	else if (method ==2)
		f1_trap(a, b);
	else if (method ==3)
	{
		f1_rect(a, b);
		f1_trap(a, b);
	}
	cout<<"press 1 to play again!"<<endl;
	cin>>play_again;
	if (play_again==1)
		which_func();
}

void f2()
{
	float a, b, rect_choice, play_again, method; //boundaries where a= start and b = end
	a= a_prompt();
	b = b_prompt();
	method= choose_method();
	if (method==1)
		f2_rect(a, b);
	else if (method ==2)
		f2_trap(a, b);
	else if (method ==3)
	{
		f2_rect(a, b);
		f2_trap(a, b);
	}
	cout<<"press 1 to play again!"<<endl;
	cin>>play_again;
	if (play_again==1)
		which_func();
}
void f3()
{
	float a, b, rect_choice, play_again, method; //boundaries where a= start and b = end
	a= a_prompt();
	b = b_prompt();
	method= choose_method();
	if (method==1)
		f3_rect(a, b);
	else if (method ==2)
		f3_trap(a, b);
	else if (method ==3)
	{
		f3_rect(a, b);
		f3_trap(a, b);
	}
	cout<<"press 1 to play again!"<<endl;
	cin>>play_again;
	if (play_again==1)
		which_func();
}

void f4()
{
	float a, b, rect_choice, play_again, method; //boundaries where a= start and b = end
	a= a_prompt();
	b = b_prompt();
	method= choose_method();
	if (method==1)
		f4_rect(a, b);
	else if (method ==2)
		f4_trap(a, b);
	else if (method ==3)
	{
		f4_rect(a, b);
		f4_trap(a, b);
	}
	cout<<"press 1 to play again!"<<endl;
	cin>>play_again;
	if (play_again==1)
		which_func();
}

void f5()
{
	float a, b, rect_choice, play_again, method; //boundaries where a= start and b = end
	a= a_prompt();
	b = b_prompt();
	method= choose_method();
	if (method==1)
		f5_rect(a, b);
	else if (method ==2)
		f5_trap(a, b);
	else if (method ==3)
	{
		f5_rect(a, b);
		f5_trap(a, b);
	}
	cout<<"press 1 to play again!"<<endl;
	cin>>play_again;
	if (play_again==1)
		which_func();
}


int choose_method()
{
	int method;
	cout<<"whould you like to calculate the area using rectangles, trapazoids, or both? (rect=1, trap=2, both= 3) "<<endl;
	cin>> method;
	return method;
}

void f1_rect(float a, float b)
{	
	float num_rect, dx, i, sum=0;
	cout<<"we're in f1_rect!"<<endl;
	cout<<"How many rectangles would you like to use today?"<<endl;
	cin>> num_rect;
	dx= (b-a)/num_rect;
	for(i=a; i<b; i+=dx)
		sum+=(2*pow(i, 5)+pow(i,3)-10*i+2)*dx;
	cout<<"in 2x^5+x^3-10x+2, using " << num_rect <<" rectangles, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}
	
void f1_trap(float a, float b)
{
	float num_trap, dx, i, sum=0;
	cout<<"we're in f1_trap!"<<endl;
	cout<<"How many trapezoids would you like to use today?" <<endl;
	cin>> num_trap;
	dx = (b-a)/num_trap;
	for (i=a; i<b; i+=dx)
		sum+= (.5*(dx*((2*pow(i, 5)+pow(i,3)- 10*i + 2)+(2*pow(i+dx, 5)+pow(i+dx, 3)-(i+dx)*10 +2))));
	cout<<"in 2x^5+x^3-10x+2, using " << num_trap <<" trapazoids, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}


void f2_rect(float a, float b)
{	
	float num_rect, dx, i, sum=0;
	cout<<"we're in f2_rect!"<<endl;
	cout<<"How many rectangles would you like to use today?"<<endl;
	cin>> num_rect;
	dx= (b-a)/num_rect;
	for(i=a; i<b; i+=dx)
		sum+=(6*pow(i, 2) - i + 10)*dx;
	cout<<"in 6x^2-x+10, using " << num_rect <<" rectangles, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}

void f2_trap(float a, float b)
{
	float num_trap, dx, i, sum=0;
	cout<<"we're in f2_trap!"<<endl;
	cout<<"How many trapezoids would you like to use today?" <<endl;
	cin>> num_trap;
	dx = (b-a)/num_trap;
	for (i=a; i<b; i+=dx)
		sum+= (dx*((6*pow(i, 2)- i + 10)+(6*pow(i+dx, 2)-(i+dx) +10)))*.5;
	cout<<"in 6x^2-x+10, using " << num_trap <<" trapazoids, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}

void f3_rect(float a, float b)
{	
	float num_rect, dx, i, sum=0;
	cout<<"we're in f2_rect!"<<endl;
	cout<<"How many rectangles would you like to use today?"<<endl;
	cin>> num_rect;
	dx= (b-a)/num_rect;
	for(i=a; i<b; i+=dx)
		sum+=((5*i +3)*dx);
	cout<<"in 5x+3, using " << num_rect <<" rectangles, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}

void f3_trap(float a, float b)
{
	float num_trap, dx, i, sum=0;
	cout<<"we're in f2_trap!"<<endl;
	cout<<"How many trapezoids would you like to use today?" <<endl;
	cin>> num_trap;
	dx = (b-a)/num_trap;
	for (i=a; i<b; i+=dx)
		sum+= (dx*((5*i+3)+(5*(i+dx)+3)))*.5;
	cout<<"in 5x+3, using " << num_trap <<" trapazoids, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}

void f4_rect(float a, float b)
{	
	float num_rect, dx, i, sum=0;
	cout<<"we're in f2_rect!"<<endl;
	cout<<"How many rectangles would you like to use today?"<<endl;
	cin>> num_rect;
	dx= (b-a)/num_rect;
	for(i=a; i<b; i+=dx)
		sum+=((2*pow(i,3) +120)*dx);
	cout<<"in 2x^3+120, using " << num_rect <<" rectangles, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}

void f4_trap(float a, float b)
{
	float num_trap, dx, i, sum=0;
	cout<<"we're in f2_trap!"<<endl;
	cout<<"How many trapezoids would you like to use today?" <<endl;
	cin>> num_trap;
	dx = (b-a)/num_trap;
	for (i=a; i<b; i+=dx)
		sum+= (dx*((2*pow(i,3)+ 120) + (2*pow(i+dx,3)+ 120)))*.5;
	cout<<"in 2x^3+120, using " << num_trap <<" trapazoids, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}

void f5_rect(float a, float b)
{	
	float num_rect, dx, i, sum=0;
	cout<<"we're in f2_rect!"<<endl;
	cout<<"How many rectangles would you like to use today?"<<endl;
	cin>> num_rect;
	dx= (b-a)/num_rect;
	for(i=a; i<b; i+=dx)
		sum+=(2*pow(i,2))*dx;
	cout<<"in 2x^2, using " << num_rect <<" rectangles, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}

void f5_trap(float a, float b)
{
	float num_trap, dx, i, sum=0;
	cout<<"we're in f2_trap!"<<endl;
	cout<<"How many trapezoids would you like to use today?" <<endl;
	cin>> num_trap;
	dx = (b-a)/num_trap;
	for (i=a; i<b; i+=dx)
		sum+= (dx*((2*pow(i,2)) + (2*pow(i+dx,2))))*.5;
	cout<<"in 2x^2, using " << num_trap <<" trapazoids, "<<" the approximated Riemann sum is:" <<sum <<endl;
	return;
}


#include <iostream>
#include <cmath>

using namespace std;

//Function Prototypes
int which_function();
int method();
float input_variables(float w);

int main()
{
	which_function();
	input_variables();
}

int which_function() //Determines which function the user wants to integrate
{
	int wtfunction; //I'm funny
	while(true) //Loop
	{
		cout << "Choose a function (1, 2, 3, 4, 5): " << endl;
		cin >> wtfunction;
		if (wtfunction != 1 && wtfunction != 2 && wtfunction != 3 && wtfunction != 4 && wtfunction != 5)
			{
				cout << "Please enter a valid input: " << endl;
				continue;
			}
		else
		{
			cout << "You have selected function " << wtfunction << " to integrate!" << endl;
			break;
		}

	}
	return 0;
}


float input_variables(float *w, float *n, float *a, float *b)
{
	float n, a, b, fx; //Takes in user input of all variables and also calculates the width of each rectangle
	/*Key:
	  n = number of rectangles 
	  a = beginning x value
	  b = ending x value
	  w = width of each rectangle, (b-a)/n
	  f(x) or fx = height of rectangle
	*/

	cout << "Please input n value: " << endl;
	cin >> n;
	cout << "Please input a value: " << endl;
	cin >> a;
	cout << "Please input b value: " << endl;
	cin >> b;
	cout << "Please input f(x) value: " << endl;
	cin >> fx;

	*w = (b-a)/n; 


/*
#include <iostream>
#include <cmath>

using namespace std;

//Function prototypes
int method();
float rectanglem();
void input_variables(float *w);
double f(int);

int main()
{	
	method();
	rectanglem();
	return 0;
}

int method() //Checks which method of integration user wants
{
	while(true) //Loop
	{
	int m;
	cout << "Please enter prefered method of integration (1 = rectangle) (2 = trapezoid): " << endl;
	cin >> m;
	if (m != 1 && m != 2)
		{
			cout << "Please enter valid method" << endl; //Error checking
			continue;
		}
	else
		{ 
			if (m = 1)
				{
					cout << "You have selected the rectangle method!" << endl;
					return true;
					break;
				}
			else
				{
					cout << "You have selected the trapezoid method!" << endl;
					return false;
					break;
				}
		}
	}
}


float rectanglem() //Rectangle Method
{
	float w, n, a, b, area;
	input_variables(&w), input_variables(&n), input_variables(&a), input_variables(&b);

	cout << w << endl;

    area = (f(a)+f(b))/2;
 
    for(int i=1;i<n;i++)
		{
			area += f(a+i*w);
		}
	area = area*w;
	cout << "The area under your curve is: ";
	cout << area;
	return 0;
}




void input_variables(float *w, float *n, float *a, float *b)
{
	float n, a, b, fx; //Takes in user input of all variables and also calculates the width of each rectangle
	/*Key:
	  n = number of rectangles 
	  a = beginning x value
	  b = ending x value
	  w = width of each rectangle, (b-a)/n
	  f(x) or fx = height of rectangle
	*/
/*
	cout << "Please input n value: " << endl;
	cin >> n;
	cout << "Please input a value: " << endl;
	cin >> a;
	cout << "Please input b value: " << endl;
	cin >> b;
	cout << "Please input f(x) value: " << endl;
	cin >> fx;

	*w = (b-a)/n; 
}

*/

/*
#include <iostream>
#include <cmath>

 using namespace std;
 double f(float);

 int main(){

    float a;
    float b;
    int n;
    float h;
    float x;
    float area;
 
     cout << "What is the left x value? ";
     cin >> a;
     cout << "What is the right x value? ";
     cin >> b;
     cout << "How many pieces do you want to use? ";
     cin >> n;
 
     h = (b-a)/n;
     area = (f(a)+f(b))/2;
 
           for(int i=1;i<n;i++){
           area+= f(a+i*h);
           }
           area = area*h;
           cout << "The area under the curve of f(x) = x^4+3 is ";
		   cout << area;
           }
     double f(float x)
	 {
     return x*x*x*x+3;
     }

*/