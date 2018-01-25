//
// Created by kryvashek on 24.01.18.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "group.h"

using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::istringstream;
using std::stod;

int main( int argc, char * argv[] ) {
	if( 5 != argc ) {
		cerr << "Wrong arguments count, expected 3 (input, good output, bad output, level)." << endl;
		return -1;
	}

	ifstream	input( argv[ 1 ] );
	ofstream	outputGood( argv[ 2 ] ),
				outputBad( argv[ 3 ] );
	double		level( stod( string( argv[ 4 ] ) ) );
	Group		group;
	string		lineString;

	if( input.is_open() && input.good() ) {
		while( getline( input, lineString ) ) {
			istringstream	inputLine( lineString );
			string			surname;
			unsigned		mark;

			inputLine >> surname;

			Student & student = group.AddStudent( surname );

			if( inputLine >> mark ) {
				student.SetTest( static_cast< Mark >( mark ) );

				while( inputLine >> mark )
					student.AddMark( static_cast< Mark >( mark ) );
			}
		}

		group.SortBySurname();

		for( auto student = group.Begin(); student != group.End(); student++ )
			if( student->Average() >= level )
				outputGood << student->Surname() << " : " << student->Average() << endl;
			else
				outputBad << student->Surname() << " : " << student->Average() << endl;
	}

	return 0;
}