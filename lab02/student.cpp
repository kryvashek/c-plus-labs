//
// Created by kryvashek on 24.01.18.
//

#include "student.h"
#include <limits>

Student::Student( string & surname ) :
	_surname( surname ),
	_tested( false ),
	_average( .0 ),
	_test( F )
	{}

Student::Student( Student && student ) noexcept {
	*this = std::move( student );
}

Student & Student::operator=( Student && student ) noexcept {
	const_cast< string & >( _surname ) = student._surname;
	_average = student._average;
	_tested = student._tested;
	_test = student._test;
	_marks = std::move( student._marks );
	return *this;
}

void Student::SetTest( Mark m ) {
	_tested = true;
	_test = m;
}

void Student::AddMark( Mark m ) {
	_average += ( ( double )m - _average ) / ( double )( _marks.size() + 1 );
	_marks.push_back( m );
}

double Student::Average() const {
	return ( _tested ? .25 * ( double )_test + .75 * _average : std::numeric_limits< double >::quiet_NaN() );
}

const string & Student::Surname() const {
	return _surname;
}

bool Student::CompareByAverage( Student & one, Student & two ) {
	return one.Average() > two.Average();
}

bool Student::CompareBySurname( Student & one, Student & two ) {
	return one.Surname() < two.Surname();
}
