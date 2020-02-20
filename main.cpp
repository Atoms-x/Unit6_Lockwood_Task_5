/*
	Teacher: Dr. Tyson McMillan, Ph.D. COSC 1436 
  STUDENT (McMillanite): Chet Lockwood
  Unit_6_Task_6
  IDE: Repl.it
*/

#include <iostream>  // Provides cout, cin, endl
#include <iomanip>
#include "accounts.h"
#include <fstream>
#include <algorithm>

using namespace std;

void printArray(int array[], int);
void averageTime(double array[], int);

//Main Functions ************************************************************************************************
int main() 
{
  int iterations = 0;
  double times[3];  //Time holding array
  int i = 0;
  
  while (iterations < 3)
  {
  sort(accountBalances, accountBalances+maxAccounts); //Built in Sorting Algorithm
  reverse(accountBalances, accountBalances+maxAccounts); //Reversing the Sorting Algorithm
  printArray(accountBalances, maxAccounts); //Print Array

  times[i] = cpuTime(); //Output time into time holding Array
    
  iterations++; //Iterate the while loop
  i++; //Iterate the array
  }

  cout << endl << "Time for Run 1: " << times[0] << endl;
  cout << "Time for Run 2: " << times[1] << endl;
  cout << "Time for Run 3: " << times[2] << endl;
  
  averageTime(times, 3); //Average the times

  return 0;
}
//Function Definitions ******************************************************************************************

//Function to print the Array
void printArray(int array[], int SIZE)
{
  ofstream inputFile;
  inputFile.open("Results.txt");

  inputFile << "\nPrinted Values in Array:\n";

  for(int i = 0; i < SIZE; i++)
    {
      inputFile << array[i] << ", ";
      //cout << array[i] << ", ";
    }
  inputFile.close();
}

//Function to calculate the average time to sort
void averageTime(double array[], int SIZE)
{
  double total = 0; //Accumulator
  double average; //Will hold the average

  for(int i = 0; i < SIZE; i++)
    total += array[i];

  average = (total / SIZE);
  
  cout << "\nAverage Time for Built-in-Sort Reverse: " << average;
}