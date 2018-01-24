//
// Created by kryvashek on 24.01.18.
//

#include "student.h"

Student::Student( string & surname ) :
	_surname( surname ),
	_average( .0 ),
	_test( F )
	{}

void Student::AddTest( Mark m ) {
	_test = m;
}

void Student::AddMark( Mark m ) {
	_average += ( ( double )m - _average ) / ( double )( _marks.size() + 1 );
	_marks.push_back( m );
}

double Student::Average() {
	return .25 * ( double )_test + .75 * _average;
}