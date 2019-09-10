/*
Alex Arbuckle
Professor Michael Essmyer
CS201R : Program 2
12 September 2019
*/

#include <cmath> // including math library in order to successfully complete the rounding-up of numbers
#include <iostream> // allowing input and output of data
using namespace std; // makes code shorter by preventing me from writing std::

int funcPaint(string strParameter) { // initializing function that returns area of all walls

	int funcInput, funcLength, funcHeight, funcArea = 0, funcIncrement = 1; // declaring variables

	cout << "\n\nAmount of " << strParameter << " Walls : "; // asking for input
	cin >> funcInput; // getting input

	while (funcIncrement <= funcInput) { // while statement to iterate through amount of input walls

		cout << "\n" << strParameter << " Wall : " << funcIncrement << " : Length : "; // outputting wall # and asking for length
		cin >> funcLength; // getting length

		cout << "\n" << strParameter << " Wall : " << funcIncrement << " : Height : "; // outputting wall # and asking for width
		cin >> funcHeight; // getting width

		funcArea = funcArea + (funcLength * funcHeight); // getting and adding to the entirety of area
		funcIncrement += 1; // incrementing  up to next wall, or breaking out of while statement

	}

	return funcArea; // after while statement, return total area variable

}

int main() { // where program begins execution

	string strInput; // declaring a string going to be used for various input
	int intInterior = 0, intExterior = 0; // declaring and assigning variables

	cout << "Welcome to RooPaint Shop!\n\n"; // welcome happiness (yay)

	while (true) { //  while statement to break once valid input (1-3) is entered

		cout << "1.\t<Interior Painting>\n" << "2.\t<Exterior Painting>\n" << "3.\t<Interior & Exterior Painting>\n\n"; // menu
		cout << "Input : "; // asking for input
		cin >> strInput; // getting input

		if (strInput == "1") { intInterior = funcPaint("Interior"); break; } // interior branch to find interior area and break out of while statement

		else if (strInput == "2") { intExterior = funcPaint("Exterior"); break; } // exterior branch to find exterior area and break out of while statement

		else if (strInput == "3") { intInterior = funcPaint("Interior"); intExterior = funcPaint("Exterior"); break; } // finds both and breaks out of while statement

		else { cout << "\nInput was invalid.\n\n"; } // should the input not be within (1-3)

	}

	if ((intInterior != 0) && (intExterior != 0)) { // if both interior and exterior exist

		cout << "\n\nTotal Interior & Exterior Area : " << (intInterior + intExterior) << " sq ft\nRequired : "; // outputting results 
		cout << (ceil(intInterior / 400.0) + ceil(intExterior / 400.0)) << " can(s)"; // # cans required
		cout << "\nTotal : $ " << ((ceil(intInterior / 400.0)) * 100) + ((ceil(intExterior / 400.0)) * 150) << "\n\n"; // total $ required

	}

	else if (intInterior != 0) { // 

		cout << "\n\nTotal Interior Area : " << intInterior << " sq ft\nRequired : " << (ceil(intInterior / 400.0)) << " can(s)"; // outputting results
		cout << "\nTotal : $ " << (ceil(intInterior / 400.0) * 100) << "\n\n"; // total $ required

	}

	else if (intExterior != 0) { // 

		cout << "\n\nTotal Exterior Area : " << intExterior << " sq ft\nRequired : " << (ceil(intExterior / 400.0)) << " can(s)"; // outputting results
		cout << "\nTotal : $ " << (ceil(intExterior / 400.0) * 150) << "\n\n"; //  total $ required

	}

	cout << "Thanks for coming to RooPaint Shop!\n"; // thanks for coming

	return 0; // we ended without 0 issues

}