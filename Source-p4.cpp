#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
	cout << "Press enter to start the Program" << endl;

	bool cont = true;
	int x = 0;

	while (cont)
	{

	string inp, output1, output2, temp;
	int Max[10] = {};
	char c;
	int n, j, l;

//clearing out input text incase of error in computer
	if (cin.peek() == '\n')
		cin.ignore();

	string c1;
	cout << "Enter a rule: ";
	getline(cin, c1);

//couting the number of spaces in the sentence,
//therefore giving me the number of number of rules entered
	int Spaces = 0;
	for (size_t i = 0; i < c1.size(); i++)
		if (c1[i] == ' ')
			Spaces++;

//creating a token array that contains the rules seperated
	istringstream stream(c1);
	string token0;
	string token1;
	string token2;
	string token3;
	string token4;
	string token5;
	stream >> token0 >> token1 >> token2 >> token3 >> token4 >> token5;
	string tokens[5] = { token1, token2, token3, token4, token5 };

//pushing non-terminal unto string with arrow into output string
	c = c1[0];
	inp.push_back(c);
	output1 += inp + "\'->";
	inp += "->";
	output2 += inp;
	n = Spaces;

//this puts the rules individually into output string 
	for (int i = 0; i < n; i++)
	{
		Max[i] = tokens[i].size();
		inp += tokens[i];

		if (i != n - 1)
			inp += "|";
	}
//k starting at three checks the first terminal of the rule
	int k = 3;
	for (int i = 0; i < n; i++)
	{
		//cout << "k is " << k << endl;	 if the non-terminal matchest the firt terminal in the rule 
		if (inp[0] == inp[k])
		{
			if (inp[k] != '#')
			{
				for (l = k + 1; l < k + Max[i]; l++)
					output1.push_back(inp[l]);

				k = l + 1;

				output1.push_back(inp[0]);
				output1 += "\'|";
			}
		}
		else
		{
			if (inp[k] != '#')
			{
				for (j = k; j < k + Max[i]; j++)
					output2.push_back(inp[j]);

				k = j + 1;

				output2.push_back(inp[0]);
				output2 += "\'|";
			}
			else
			{
				output2.push_back(inp[0]);
				output2 += "\'";
			}
		}
	}

	output1 += "#";
 
//outputting the rules left most recursion
	cout << output2 << endl;
	cout << output1 << endl;
	cout << endl;

	string answer;
	cout << "More Rules?";
	cin >> answer;
	if (answer == "n" || answer == "N" )
		cont = false;
	x++;
}
	return 0;
}