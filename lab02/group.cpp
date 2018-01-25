//
// Created by kryvashek on 24.01.18.
//

#include <iostream>
#include <algorithm>
#include "group.h"

Student & Group::AddStudent( string & surname ) {
	_students.push_back( std::move( Student( surname ) ) );
	return _students.back();
}

void Group::SortByAverage() {
	std::sort( _students.begin(), _students.end(), Student::CompareByAverage );
}

void Group::SortBySurname() {
	std::sort( _students.begin(), _students.end(), Student::CompareBySurname );
}

Group::StudentIterator Group::Begin() {
	return _students.cbegin();
}

Group::StudentIterator Group::End() {
	return _students.cend();
}