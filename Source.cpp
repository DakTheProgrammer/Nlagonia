// Dakota Wilson
// Program 3 - Nlogonia
// CS 1044 - Intro to Computer Science
// due: 10/18/18
// This program is used to find out the place that someone is living on a
// cordate grid of a land area that was split up into four sections. Using 
// the given center point there is a set of data from an input file that goes
// through a loop that reads all inputs and outputs where the x and y 
// coordinates are located. I have also set it up so that if the point is on 
// the dividing lines it will out put that it is on the line and the two areas
// that it is in-between and if it is on the center it will output that the 
// coordinate is located in between all of the areas.
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
	int DivPointX, DivPointY, PointX, PointY;// Declares Xs and Ys as integers
	
	ifstream infile;
	infile.open("data1.txt");//Data2.txt, Data3.txt
	ofstream outfile;
	outfile.open("Output_Program3.txt");

	infile >> DivPointX >> DivPointY; //Reads the dvisions points X and Y

	outfile << "Dakota Wilson\n\n";
	outfile << "The Division point is " << DivPointX << "," << DivPointY <<
		"\n"; //Prints the division point to the file

	while(infile >> PointX >> PointY)//Loops for the total amount of inputs in 
                                     //file
	{
		
		if (DivPointX < PointX && DivPointY < PointY)
		{
			outfile << setw(6) << PointX << setw(8) << PointY << setw(8) <<
				"Kiowa" << "\n";//prints to file if the point lies in 1st 
			                    //quadrent
		}
		else if (DivPointX > PointX && DivPointY < PointY)
		{
			outfile << setw(6) << PointX << setw(8) << PointY << setw(11) <<
				"Comanche" << "\n";
		}
		else if (DivPointX > PointX && DivPointY > PointY)
		{
			outfile << setw(6) << PointX << setw(8) << PointY << setw(9) <<
				"Nocona" << "\n";
		}
		else if (DivPointX < PointX && DivPointY > PointY)
		{
			outfile << setw(6) << PointX << setw(8) << PointY << setw(8) <<
				"Tepee" << "\n";
		}
		else if (DivPointX < PointX && DivPointY == PointY)
		{
			outfile << setw(6) << PointX << setw(8) << PointY << setw(10) <<
				"DIVISA " << "Kiowa and Tepee" << "\n";
		}
		else if (DivPointX > PointX && DivPointY == PointY)
		{
			outfile << setw(6) << PointX << setw(8) << PointY << setw(10) <<
				"DIVISA " << "Comanche and Nocona" << "\n";//Prints to file if
			                                               //it lies between 
			                                               //the 2nd and 3rd 
			                                               //quadrents
		}
		else if (DivPointX == PointX && DivPointY < PointY)
		{
			outfile << setw(6) << PointX << setw(8) << PointY << setw(10) <<
				"DIVISA " << "Comanche and Kiowa" << "\n";
		}
		else if (DivPointX == PointX && DivPointY > PointY)
		{
			outfile << setw(6) << PointX << setw(8) << PointY << setw(10) <<
				"DIVISA " << "Nocona and Tepee" << "\n";
		}
		else
		{
			outfile << setw(6) << DivPointX << setw(8) << DivPointY << 
				setw(17) << "Division Point" << "\n";//if nothing else 
	//from above applys outputs to file that its in the division point
		}
	}//Ends loop continues code
infile.close();
outfile.close();
return 0;
}