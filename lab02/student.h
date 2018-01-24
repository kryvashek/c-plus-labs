//
// Created by kryvashek on 24.01.18.
//

#ifndef C_STUDENT_H
#define C_STUDENT_H

#include <string>
#include <vector>

using std::vector;
using std::string;

enum Mark {
	F = 0, E, D, C, B, A
};

struct Student {
private:
	const string	_surname;
	double			_average;
	Mark			_test;
	vector< Mark >	_marks;

public:
	explicit Student( string & surname );
	void AddTest( Mark m );
	void AddMark( Mark m );
	double Average();
};

#endif //C_STUDENT_H
