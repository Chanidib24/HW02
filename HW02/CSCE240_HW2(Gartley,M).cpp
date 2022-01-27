//marilyn E. Gartley 

//fstream includes both classes ifstream and ofstream (Savitch_p. 518)
#include <fstream>
#include <cstdlib> //include for exit 
//when sending output to a file, your code must first use the member fuction open to open a file and connect it to  stream of type ofstream (Savitch p. 522)
#include <iostream>
//stringstream stream extraction operator to read the name and each score as an integer
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
//attribution: https://www.cplusplus.com/forum/beginner/276004/
using namespace std;

constexpr double PI = 3.141592653989792;


class Shape
{
public:
	// The name of the shape as it appears in the input
	virtual string name() = 0;

	// Read the shape info from the input. Note that the info does NOT
	// include the name. Main() reads the name
	virtual bool parse(istream&) = 0;

	// Print the shape. The base class prints the first part of the
	// output line.
	virtual void print(ostream&) = 0;
};

ostream& operator <<(ostream& os, Shape& s)
{
	s.print(os);
	return os;
}

// A 2D shape includes methods to compute the area and perimeter.
class TwoDShape :public Shape
{
public:
	virtual double area() = 0;
	virtual double perimeter() = 0;
	void print(ostream& os) {
		os << "area = " << area()
			<< ", perimeter = " << perimeter();
	}
};


/////////////////////////////////////////////////////////////////////
//                       TWO DIMENSIONAL SHAPES                    //
// After defining a new shape, add a line in main() to push an     //
// instance onto the "shapes" vector                               //
/////////////////////////////////////////////////////////////////////

class Square :public TwoDShape
{
	double side;
public:
	virtual string name() { return "SQUARE"; }
	virtual double area() { return side * side; }
	virtual double perimeter() { return 4 * side; }
	virtual bool parse(istream& is)
	{
		side = 0.0;
		is >> side;
		return bool(is);
	}
	virtual void print(ostream& os)
	{
		os << name() << ": side = " << side << ", ";
		TwoDShape::print(os);
	}
};

class Rectangle :public TwoDShape
{
	double side;
public:
	virtual string name() { return "RECTANGLE"; }
	virtual double area() { return side * side; }
	virtual double perimeter() { return 2 * side; }
	virtual bool parse(istream& is)
	{
		side = 0.0;
		is >> side;
		return bool(is);
	}
	virtual void print(ostream& os)
	{
		os << name() << ": side = " << side << ", ";
		TwoDShape::print(os);
	}
};

//int main()
	//{
	//double width, lngth, area, peri;
//area = (lngth * width);
//peri = 2 * (lngth + width);
//cout << " The area of the rectangle is : " << area << endl;
//cout << " The perimeter of the rectangle is : " << peri << endl;
//cout << endl;
//return 0;
//	}
//https://codescracker.com/cpp/program/cpp-program-calculate-area-perimeter.htm

int main()
{
	//declaring variables:

	ifstream inStream; 
	ofstream outStream;
	
	inStream.open("input.txt")
	outStream.open("output.txt")

	//declaring variables:
	string userChoice;
	
	//declare and initialize user's command choice variable 
	char userCommandchoice = '';
	
	if (inStream.is_open()) {

		cout << "Without adding a space following your numeric selection, \n"
			"please select one of the following two letters by typing in the number 1 or 2. \n"
			"Please enter the number 1 to calculate the area \n"
			"Please enter the number 2 to calculate the perimeter \n"
			"Please press the Enter\\Return Key once you are done. \n"
			cin >> userChoice;

		cout << "The number you select will result in a message that will be displayed "
			"to you from the program!! Hooray!"
			cin >> userCommandchoice;

	
		If(userCommandchoice == 1)
		{
			//int lineCount = 0;
			//while (getline(inStream, line)) {
				//lineCount++;
			//cout << "Hello, " << firstName << lastName << ".\n"
			string name;

			// Loop through each input line
			while (cin >> name) {			 // read the name of the shape

			// EOF is special. It means end of the file
				if (name == "EOF")
					break;

				bool found = false;	// indicates whether we found the shape name

				// Go through the known shapes look for the name. If you find it then
				// parse the rest of the line and print the shape's info
				for (auto& shape : shapes) {

					if (shape->name() == name) {
						// Found it. Now parse and print it
						shape->parse(cin);
						cout << *shape << '\n';
						found = true;
						break;
					}
				}

				if (!found) {
					cout << name << ": illegal shape\n";
				}
				// Clear any error and skip past the end of line
				cin.clear();
				cin.ignore(std::numeric_limits < streamsize >::max(), '\n');
			}
		}
		
		else if (userCommandchoice == 2)
		{
		string name;

		// Loop through each input line
		while (cin >> name) {			 // read the name of the shape

		// EOF is special. It means end of the file
			if (name == "EOF")
				break;

			bool found = false;	// indicates whether we found the shape name

			// Go through the known shapes look for the name. If you find it then
			// parse the rest of the line and print the shape's info
			for (auto& shape : shapes) {

				if (shape->name() == name) {
					// Found it. Now parse and print it
					shape->parse(cin);
					cout << *shape << '\n';
					found = true;
					break;
				}
			}

			if (!found) {
				cout << name << ": illegal shape\n";
			}
			// Clear any error and skip past the end of line
			cin.clear();
			cin.ignore(std::numeric_limits < streamsize >::max(), '\n');
		}
	


	//To find area of a square, use following formula :
	//area = len * len
		//len indicates the length of square.Because all the sides are of equal length in square, therefore get the length of sideand square it.
		//That will be the area.

	//Perimeter of Square Formula
	//To find perimeter of a square, use following formula :
	//	perimeter = 4 * len

	





	//c



		//end the program with endl as the last output action (p. 30) 
		cout << endl;
}

		