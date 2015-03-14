/********************************************************************* 
 ** Program Filename: assignment5part1
 ** Author: Brandon Lee
 ** Date: 3/9/14
 ** Description: Assignment 5 Part 1
 ** Input: N value
 ** Output: NxN matrix and N-1xN-1 matrix calculated iterivative and recursively
 *********************************************************************/ 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//FUNCTION PROTOTYPES
int **create_2d(int rows, int cols);

int user_input();

void print_array(int rows, int cols, int **array);
void calculate_result(int **array, int **array1, int cols, int rows);
void calculate_result_recursive(int **array, int **array1, int cols, int rows, int i, int j);
void delete_array(int **array, int rows, int cols);

/*********************************************************************
 ** Function: **create_2d
 ** Description: Creates 2D array and fills array with values
 ** Parameters: int row, int cols
 ** Pre-Conditions: user input must be an int
 ** Post-Conditions: Must create 2D matrix with values
 *********************************************************************/
int **create_2d(int rows, int cols)//Create 2D array
{
   int **array = new int*[rows]; //Creates rows in array
   for (int x=0; x < rows; x++)
   {
       array[x] = new int[cols];
   }
   int i=0;//Fills array with elements
   srand(time(NULL));
   for(int r=0; r < rows; ++r)
   {
      for(int c=0; c < cols; ++c)
      {
      	array[r][c]=(rand()%10);
		//	array[r][c]=i; //This sets all elements to 1 for easy calculation
        //  i++;
     	}
   }
   return array;   
}

int main()
{
   int n = user_input();
   int **array = create_2d(n,n);
   int **array1;

	array1 = new int *[n];
		for(int i=0; i<n; ++i)
		{
			array1[i] = new int[n];
		}
	int i1=0, j1=0;	
	print_array(n,n,array);
	cout << "Here is your new matrix calculated iteratively: " << endl;
	calculate_result(array,array1,n,n);
	cout << "Here is your new matrix calculated recursively: " << endl;
   calculate_result_recursive(array, array1, n, n, i1, j1);
   delete_array(array,n,n);
   return 0;
}

/*********************************************************************
 ** Function: user_input
 ** Description: Takes in user input and checks if input is valid
 ** Parameters: int n
 ** Pre-Conditions: user input must be an int
 ** Post-Conditions: Must return n value
 *********************************************************************/
int user_input() //Checks if user inputs valid n value
{
   int n = 1;
   while (n = 1)
   {
      cout << "Please enter N value: ";
      cin >> n;
   
      if(n <= 1 || n>=65535)
      {
         cout << "Error, please input again: ";
         continue;
      }
      else
      {
         break;
      }  	  
   }
   return n;
}

/*********************************************************************
 ** Function: print_array
 ** Description: Physically prints out the array
 ** Parameters: int rows, int cols, int array
 ** Pre-Conditions: user input must be a ints and array
 ** Post-Conditions: Must print out array correctly
 *********************************************************************/
void print_array(int rows, int cols, int **array) //Prints array with ** double pointer
{
   for (int i=0; i < rows; i++)
   {
	    for (int j=0; j < cols; j++)
	    {
	        cout << array[i][j] << " ";
	    }
	cout << endl;	
   }
}

/*********************************************************************
 ** Function: calculate_result
 ** Description: Iteratively calculates (n-1)x(n-1) matrix
 ** Parameters: int array, int newarray, int cols, int rows
 ** Pre-Conditions: user input must be a ints and array
 ** Post-Conditions: Must calculate and print out array correctly
 *********************************************************************/
void calculate_result(int **array, int **array1, int cols, int rows)
{
   for(int i=0; i < (rows-1); i++)
	{
		for(int j=0; j < (cols-1); j++)
		{
		array1[i][j] = array[i][j] + array[i][j+1] + array[i+1][j] + array[i+1][j+1];
		cout << array1[i][j] << " ";
		}	
	cout << endl;
	}
}

/*********************************************************************
 ** Function: calculate_result_recursive
 ** Description: Recursively calculates (n-1)x(n-1) matrix
 ** Parameters: int array, int newarray, int cols, int rows, int i, int j
 ** Pre-Conditions: User input must be a ints and array
 ** Post-Conditions: Must calculate and print out array correctly
 *********************************************************************/
void calculate_result_recursive(int **array, int **array1, int cols, int rows, int i, int j)
{
	if(i==rows-1)//End program once reach end of rows
	{
		return;
	}
	else if(i<(rows-1) && j<(cols-1))//Actual calculation
	{
		array1[i][j] = array[i][j] + array[i][j+1] + array[i+1][j] + array[i+1][j+1];
		cout << array1[i][j] << " ";	
   		calculate_result_recursive(array, array1, cols, rows, i, j+1);
	}
	else if(j>=(cols-1))//Moves one row down once reaching end of cols
	{
		j=0;
		cout<<endl;	
		calculate_result_recursive(array, array1, cols, rows, i+1, j);
	}
}

/*********************************************************************
 ** Function: delete_array
 ** Description: Deletes the dynamic array after usage
 ** Parameters: int array, int cols, int rows
 ** Pre-Conditions: User input must be a ints and array
 ** Post-Conditions: Must delete dynamic array to prevent memory leak
 *********************************************************************/
void delete_array(int **array, int rows, int cols)
{
	for (int i=0; i < rows; i++)
   {
      delete array[i]; 
   }
   delete array;
}
