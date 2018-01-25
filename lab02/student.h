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
	bool			_tested;
	double			_average;
	Mark			_test;
	unsigned long	_marks;

public:
	explicit Student( string & surname );
	Student( Student && student ) noexcept;
	Student & operator=( Student && student ) noexcept;
	void SetTest( Mark m );
	void AddMark( Mark m );
	double Average() const;
	const string & Surname() const;

	static bool CompareByAverage( Student & one, Student & two );
	static bool CompareBySurname( Student & one, Student & two );
};

#endif //C_STUDENT_H
