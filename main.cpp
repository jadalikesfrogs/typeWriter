/*
* Copy text from keyboard to file
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Open a file stream scecified by the user and attach it to a stream object.
@return none 
@param[in out] ofstream& ofs is the stream to be opened
*/
void open(ofstream& ofs);

/*
Copy the console input to the output stream stream specified
return none 
param[in out] ofstream& ofs is the stream to be "fed"
post		file attached to ofs has 0 or more characters inserted
post		cin has had 0 or more characters removed
*/
void copyKeyboardTo(ofstream& ofs); //ofs = output file stream


int main() {
	ofstream targetFile;
	// open a user specified file

	open(targetFile);
	//copy text

	copyKeyboardTo(targetFile);
	//close

	targetFile.close();
	return 0;
}

void open(ofstream& ofs)
{	//todo: what type of error checking do I need?

	string filename;
	//get a file name 
	
	
	cout << "Target file? ";
	cin >> filename;


	//what if the file already exists?
	// //what if the open operation fails?
	// open the file
	ofs.open(filename.c_str());
	cout << "Opened the file" << endl;


}

void copyKeyboardTo(ofstream& ofs)
{
	// get a char from the console input
	//while the current char is not  ~ 
	//put the char in the file
	//get anoother char from the console

	char aChar = '\0';
	cin.get(aChar);


	while (aChar != '~' && !cin.fail() && !ofs.fail()) {
		ofs.put(aChar);
		cin.get(aChar);
	}

	cout << "Copied to the file";
}
