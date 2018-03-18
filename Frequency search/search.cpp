#include <fstream>
#include <iostream>
#include <stdio.h>
#include <omp.h>
using namespace std;

int main()
{
   int freq[128];     // frequencies of letters
   ifstream inFile;   // input file
   char ch; 

   inFile.open("postlab.txt");
   if (!inFile)
   {
      cout << "The input file could not be opened.";
      return 1;
   }
    #pragma omp parallel
   // initialize frequency counts to zero for each possible letter
   for (int k = 0; k < 128; k++)
   {
      freq[k] = 0;
   }

   // Read the file, keeping track of frequency with which each letter occurs
   ch = inFile.get();
   while (ch != EOF)
   {
      cout << ch;
      ch = toupper(ch);
      freq[ch]++;
      ch = inFile.get();
   }
   // Print the output table
  cout << endl << "Letter frequencies in this file are as follows." << endl;
  for (char ch = 'A'; ch <= 'Z'; ch++)
  {
      cout << ch << " : " << freq[ch] << endl;
  }
  return 0;
}