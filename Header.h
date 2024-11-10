#pragma once
#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;
struct Student
{
    char name[21];
    char surname[21];
    short marks[5];
};
struct ShortStudent
{
    char surname[21];
    float ball;
};
ShortStudent** write_middle_ball_to_new_srtucture(Student**, const short&);

void sorting_structures(ShortStudent**, const short&);

void print_students(ShortStudent**, const short&);

short number_of_ex_marks(const Student*);

void print_students_with_most_ex_marks(Student**, const short&);

short input_mark(const short&);

Student** initialization_students(const short&);

short input_number();

template<typename T>
void deleting(T**& students, const short& number_of_students)
{
	for (short i = 0; i < number_of_students; i++)
	{
		delete[] students[i];//удаление указателя на структуру
	}
	delete[] students;//удаление указателя на указатели 
	students = nullptr;//присваивание указателю значение нуль
}

