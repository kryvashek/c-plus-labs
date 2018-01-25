//
// Created by kryvashek on 24.01.18.
//

#ifndef C_GROUP_H
#define C_GROUP_H

#include <map>
#include "student.h"

using std::map;

class Group {
private:
	vector< Student >	_students;

public:
	typedef vector< Student >::const_iterator	StudentIterator;

	Group() = default;
	Student & AddStudent( string & surname );
	void SortBySurname();
	void SortByAverage();
	StudentIterator Begin();
	StudentIterator End();
};


#endif //C_GROUP_H
