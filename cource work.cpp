#include"Header.h"

int main()
{
	SetConsoleCP(CP_UTF8); // Задание кодировки UTF-8
	SetConsoleOutputCP(CP_UTF8); // Задание кодировки UTF-8

	short number_of_students = input_number();//ввод количества студентов с помощью фукнции

	Student** students = initialization_students(number_of_students); //ввод данных о студентах

	ShortStudent** new_students = write_middle_ball_to_new_srtucture(students, number_of_students);//создание нового массива структур 

	sorting_structures(new_students, number_of_students);//сортировка структур по убыванию среднего балла

	print_students(new_students, number_of_students);//вывод структур студентов 

	print_students_with_most_ex_marks(students, number_of_students);//вывод студентов с максимальным количеством отличных лценок

	deleting(students, number_of_students);//очистка памяти 
	deleting(new_students, number_of_students);//очистка памяти

	system("pause");//заморозка консоли
	return 0;
}