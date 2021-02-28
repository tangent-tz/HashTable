#include "HashTable.h"
#include "spellCheck.h"

// Opens a file and reads the contents into a vector
// PARAM: infile = name of the file to be opened
// PRE: the file contains words separated by white space
// POST: returns a vector containing the contents of infile
	vector<string> readFile(string infile)
	{
		cout<<"enter readfile"<<endl;
		ifstream ist(infile.c_str());
		if (ist.fail())
			throw runtime_error(infile + " not found");
		istream_iterator<string> start(ist), end;
		vector<string> result(start, end);
		ist.close();
		
		return result;
	}
int main()
{	
	HashTable test(5);
	vector <string> temp;
	temp=readFile("word.txt");
	for (int i=0;i<temp.size();i++)
	{
   		test.insert(temp[i]);
	}
	//test.Test();

	vector <string> save;

	save=missingSpace(test,"rate");
	for (int i=0;i<save.size();i++)
	{
   		cout<<save[i]<<endl;
	}


	return 0;
}