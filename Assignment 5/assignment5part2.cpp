/********************************************************************* 
 ** Program Filename: assignment5part2
 ** Author: Brandon Lee
 ** Date: 3/9/14
 ** Description: Assignment 5 Part 2
 ** Input: A sentence (string)
 ** Output: Number of things inside string (int)
 *********************************************************************/ 
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int check_a(int, string); int check_b(int, string); int check_c(int, string);
int check_d(int, string); int check_e(int, string); int check_f(int, string);
int check_g(int, string); int check_h(int, string); int check_i(int, string);
int check_j(int, string); int check_k(int, string); int check_l(int, string);
int check_m(int, string); int check_n(int, string); int check_o(int, string);
int check_p(int, string); int check_q(int, string); int check_r(int, string);
int check_s(int, string); int check_t(int, string); int check_u(int, string);
int check_v(int, string); int check_w(int, string); int check_x(int, string);
int check_y(int, string); int check_z(int, string);

int check_space(int, string);
int numbers(int, string);
int punct(int, string);

void fifteenlines(int, string);
void other(int, string);

int main()
{
	string user_input;
	cout << "Please enter a sentence: ";
	getline(cin, user_input);
	int m1=user_input.size();
	fifteenlines(m1, user_input);
	other(m1, user_input);
	return 0;
}

/*********************************************************************
 ** Function: fifteenlines
 ** Description: Exists because I was scared main would go over 15 lines
 ** Parameters: int m1 and string user_input
 ** Pre-Conditions: User must input valid statements
 ** Post-Conditions: Initiates next function in program
 *********************************************************************/
void fifteenlines(int m1, string user_input)
{
	int spaces=0, number=0, a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0;
	int l=0, n=0, m=0, o=0, k=0, j=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0;
	number=numbers(m1, user_input); spaces=check_space(m1, user_input); a=check_a(m1, user_input); b=check_b(m1, user_input); c=check_c(m1, user_input);
	d=check_d(m1, user_input); e=check_e(m1, user_input); f=check_f(m1, user_input); g=check_g(m1, user_input); h=check_h(m1, user_input); i=check_i(m1, user_input);
	j=check_j(m1, user_input); k=check_k(m1, user_input); l=check_l(m1, user_input); m=check_m(m1, user_input); n=check_n(m1, user_input); o=check_o(m1, user_input);
	p=check_p(m1, user_input); q=check_q(m1, user_input); r=check_r(m1, user_input); s=check_s(m1, user_input); t=check_t(m1, user_input); u=check_u(m1, user_input);
	v=check_v(m1, user_input); w=check_w(m1, user_input); x=check_x(m1, user_input); y=check_y(m1, user_input); z=check_z(m1, user_input);
}

/*********************************************************************
 ** Function: check_a-check_z and punt, numbers, and check_space
 ** Description: Finds the number of characters of each letter in the alphabet
 ** Parameters: int m1 and string user_input
 ** Pre-Conditions: Input must match character
 ** Post-Conditions: Must output number of letters of each letter in alphabet
 *********************************************************************/
int check_a(int m1, string user_input)
{
	int a=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='a'||user_input.at(i)=='A')
			a++;
	}
	cout << "Number of A's: "<< a << endl;
	return a;
}
int check_b(int m1, string user_input)
{
	int b=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='b'||user_input.at(i)=='B')
			b++;
	}
	cout << "Number of B's: "<< b << endl;
	return b;
}
int check_c(int m1,  string user_input)
{
	int c=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='c'||user_input.at(i)=='C')
			c++;
	}
	cout << "Number of C's: "<< c << endl;
	return c;
}
int check_d(int m1, string user_input)
{
	int d=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='d'||user_input.at(i)=='D')
			d++;
	}
	cout << "Number of D's: "<< d << endl;
	return d;
}
int check_e(int m1, string user_input)
{
	int e=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='e'||user_input.at(i)=='E')
			e++;
	}
	cout << "Number of E's: "<< e << endl;
	return e;
}
int check_f(int m1, string user_input)
{
	int f=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='f'||user_input.at(i)=='F')
			f++;
	}
	cout << "Number of F's: "<< f << endl;
	return f;
}
int check_g(int m1, string user_input)
{
	int g=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='g'||user_input.at(i)=='G')
			g++;
	}
	cout << "Number of G's: "<< g << endl;
	return g;
}
int check_h(int m1, string user_input)
{
	int h=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='h'||user_input.at(i)=='H')
			h++;
	}
	cout << "Number of H's: "<< h << endl;
	return h;
}
int check_i(int m1, string user_input)
{
	int i=0;
	for(int x=0; x<m1; x++)
	{
		if(user_input.at(x)=='i'||user_input.at(x)=='I')
			i++;
	}
	cout << "Number of I's: "<< i << endl;
	return i;
}
int check_j(int m1, string user_input)
{
	int j=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='j'||user_input.at(i)=='J')
			j++;
	}
	cout << "Number of J's: "<< j << endl;
	return j;
}
int check_k(int m1, string user_input)
{
	int k=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='k'||user_input.at(i)=='K')
			k++;
	}
	cout << "Number of K's: "<< k << endl;
	return k;
}
int check_l(int m1, string user_input)
{
	int l=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='l'||user_input.at(i)=='L')
			l++;
	}
	cout << "Number of L's: "<< l << endl;
	return l;
}
int check_m(int m1, string user_input)
{
	int m=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='m'||user_input.at(i)=='M')
			m++;
	}
	cout << "Number of M's: "<< m << endl;
	return m;
}
int check_n(int m1, string user_input)
{
	int n=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='n'||user_input.at(i)=='N')
			n++;
	}
	cout << "Number of N's: "<< n << endl;
	return n;
}
int check_o(int m1, string user_input)
{
	int o=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='o'||user_input.at(i)=='O')
			o++;
	}
	cout << "Number of O's: "<< o << endl;
	return o;
}
int check_p(int m1, string user_input)
{
	int p=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='p'||user_input.at(i)=='P')
			p++;
	}
	cout << "Number of P's: "<< p << endl;
	return p;
}
int check_q(int m1, string user_input)
{
	int q=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='q'||user_input.at(i)=='Q')
			q++;
	}
	cout << "Number of Q's: "<< q << endl;
	return q;
}
int check_r(int m1, string user_input)
{
	int r=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='r'||user_input.at(i)=='R')
			r++;
	}
	cout << "Number of R's: "<< r << endl;
	return r;
}
int check_s(int m1, string user_input)
{
	int s=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='s'||user_input.at(i)=='S')
			s++;
	}
	cout << "Number of S's: "<< s << endl;
	return s;
}
int check_t(int m1, string user_input)
{
	int t=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='t'||user_input.at(i)=='T')
			t++;
	}
	cout << "Number of T's: "<< t << endl;
	return t;
}
int check_u(int m1, string user_input)
{
	int u=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='U'||user_input.at(i)=='u')
			u++;
	}
	cout << "Number of U's: "<< u << endl;
	return u;
}
int check_v(int m1, string user_input)
{
	int v=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='v'||user_input.at(i)=='V')
			v++;
	}
	cout << "Number of V's: "<< v << endl;
	return v;
}
int check_w(int m1, string user_input)
{
	int w=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='w'||user_input.at(i)=='W')
			w++;
	}
	cout << "Number of W's: "<< w << endl;
	return w;
}
int check_x(int m1, string user_input)
{
	int x=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='x'||user_input.at(i)=='X')
			x++;
	}
	cout << "Number of X's: "<< x << endl;
	return x;
}
int check_y(int m1, string user_input)
{
	int y=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='y'||user_input.at(i)=='Y')
			y++;
	}
	cout << "Number of Y's: "<< y << endl;
	return y;
}
int check_z(int m1, string user_input)
{
	int z=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)=='z'||user_input.at(i)=='Z')
			z++;
	}
	cout << "Number of Z's: "<< z << endl;
	return z;
}
int punct(int m1, string user_input)
{
	int stuff=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)==','||user_input.at(i)=='.')
			stuff++;
	}
	return stuff;
}
int numbers(int m1, string user_input)
{
	int number=0;
	for(int i=0; i<m1; i++)
	{
		if((user_input.at(i)=='0')||(user_input.at(i)=='1')||(user_input.at(i)=='2')||(user_input.at(i)=='3')||(user_input.at(i)=='4')||(user_input.at(i)=='5')||
		  (user_input.at(i)=='6')||(user_input.at(i)=='7')||(user_input.at(i)=='8')||(user_input.at(i)=='9'))
			number++;
	}
	cout << "Number of Digits: "<< number << endl;
	return number;
}
int check_space(int m1, string user_input)
{
	int spaces=0;
	for(int i=0; i<m1; i++)
	{
		if(user_input.at(i)==' ')
			spaces++;
	}
	cout << "Number of user_input: "<< spaces+1 << endl;
	return spaces;
}

/*********************************************************************
 ** Function: other
 ** Description: Same thing as earlier except checks for puntuation
 ** Parameters: int m1 and string user_input
 ** Pre-Conditions: Input must match character
 ** Post-Conditions: Must output number commas/periods
 *********************************************************************/
void other(int m1, string user_input)
{
	int punc=0, desu=0;
       	punc=punct(m1, user_input);
	cout << "Number of commas/periods: "<< punc << endl;
}