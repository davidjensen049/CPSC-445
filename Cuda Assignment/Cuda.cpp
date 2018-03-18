/*
David Jensen
CPSC 445 Interterm 18'
Assignment 1 

*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>
#include <iterator>
#include <sstream>

using namespace std;


int main() // running everything with in the main method

{
	const string strFilename = "/bin/"; //this is going to allow the commands to be accesed from the bin
	while(true)
	{
		string userCommand; // creating a string that will handle the users commands/desires
		vector<char *> desire; //  creating a vector with the desire and char of the users imput

		cout << "\n Welcome to the Linux Command Shell: Please enter your desired command, if you wish to exit the program: Please type exit." << endl; //this is our welcome screen and message

		getline(cin, userCommand); //grab the line of cin function for the users command/desire

		
		istringstream inputStream(userCommand);
		vector<string> contents{istream_iterator<string>{inputStream}, istream_iterator<string>{}};//this is converting the stream words into a vector

		if(contents.front() == "Exit" || "exit" || "EXIT" || "EXit" || "EXIt" || "exIT")
			exit(0); //wanted to add some character to my code, and added different variations of exit that could be inputted by the user

		char * filename = const_cast<char *>((strFilename + contents.front()).c_str());

			for(auto const& content: contents) //this places the characters of the arguent automatically into the vector that was created earlier
			{
				desire.push_back(const_cast<char *>(content.c_str()));
			}
			desire.push_back(nullptr); // if the vector comes across null this is an exit and will tell it to terminate the program

			int pid, progress; // this is the fork and child progress/process function

			pid = fork(); //this forking allows the foregoring to be ran in parallel while continuing to run the program

			if(pid < 0) // this is thd child process, if an error is encountered. anything less than zero also equals error
			{
				cout << "Sorry, there was a problem with creating a child processe' in the fork command" << endl;
				exit(1);
			}

			if(pid == 0) // 0 equals all good, if everything works run the following command
			{
				execvp(filename, desire.data()); //execvp allows the bin and command to basically run parallel with the computer access the programmed commands.
				perror(filename);
				exit(1);

			}
			else
				waitpid(pid, &progress, 0); // this allows the other process, same functino as wait.

		}
	}
