#include "Header.h"

ShortStudent** write_middle_ball_to_new_srtucture(Student** students, const short& number_of_students)
{
	ShortStudent** new_students = new ShortStudent*[number_of_students];//выделение памяти 
	for (short i = 0; i < number_of_students; i++)
	{
		new_students[i] = new ShortStudent;//выделение памяти
		float middle_ball = 0.0;
		for (short j = 0; j < 5; j++)
			middle_ball += students[i]->marks[j];//суммирование оценок
		new_students[i]->ball = middle_ball / 5.0;//подсчет среднего балла
		strcpy_s(new_students[i]->surname, students[i]->surname);//копирование фамилии студента

	}
	return new_students;
}

void sorting_structures(ShortStudent** students, const short& number_of_students)
{
	for (int i = 0; i < number_of_students; i++)
	{
		for (int j = 0; j < number_of_students - 1; j++)
		{
			if (students[j]->ball < students[j + 1]->ball)
				swap(students[j], students[j + 1]);//меняем двух студентов местами 
		}
	}
}

void print_students(ShortStudent** students, const short& number_of_students)
{
	short number = 0;
	for (short i = 0; i < number_of_students; i++)
		cout << ++number << ". surname : " << students[i]->surname << "\tball = " << students[i]->ball << '\n';//вывод информации о студенте
}

short number_of_ex_marks(const Student* structure)
{
	short number = 0;
	for (short i = 0; i < 5; i++)
		if (structure->marks[i] == 5)
			number++;//подсчет отличных оценок
	return number;
}

void print_students_with_most_ex_marks(Student** students, const short& number_of_students)
{
	cout << "Students with most excellent marks";
	short max_number_of_ex_marks = 0;
	for (short i = 0; i < number_of_students; i++)
		max_number_of_ex_marks = max(max_number_of_ex_marks, number_of_ex_marks(students[i]));//подсчет максимального количества отличных оценок
	for (short i = 0; i < number_of_students; i++)
	{
		if (number_of_ex_marks(students[i]) == max_number_of_ex_marks)
		{
			cout << "\nsurname = " << students[i]->surname << '\t';
			for (short j = 0; j < 5; j++)
				cout << students[i]->marks[j] << ' ';//вывод студентов с наибольшим количеством отличных оценок

		}
	}
}

short input_mark(const short& index)
{
	short mark;
	cout << "Введите оценку № " << index + 1 << "\n->";
	cin >> mark;//ввод оценки
	while (cin.fail() || !(mark >= 2 && mark <= 5))//проверка оценки на соответствие диапазону [2;5]
	{
		cin.clear();//разблокировка потока 
		cin.ignore(SHRT_MAX, '\n');//очистка потока
		cout << "Ошибка!Введите оценку еще раз!\n->";
		cin >> mark;
	}
	return mark;
}

Student** initialization_students(const short& number_of_students)
{
	Student** students = new Student*[number_of_students];//выделение памяти
	for (short i = 0; i < number_of_students; i++)
	{
		students[i] = new Student;//выделение памяти
		cout << "Введите имя и фамилию студента № " << i + 1 << "\n->";
		cin >> students[i]->name >> students[i]->surname;//ввод фамиилии и имени студента
		cout << "Введите оценки студента\n";
		for (short j = 0; j < 5; j++)
			students[i]->marks[j] = input_mark(j);//ввод оценки студента
	}
	return students;
}

short input_number()
{
	short number;
	cout << "Введите количество студентов\n-> ";
	cin >> number;//ввод количества студентов
	while (cin.fail() || number < 1)//проверка на ошибку ввода и соответствие натуральному числу
	{
		cin.clear();
		cin.ignore(SHRT_MAX, '\n');
		cout << "Ошибка ввода!Повторите ввод\n->";
		cin >> number;
	}
	return number;
}
