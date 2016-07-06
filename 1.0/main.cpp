#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
#include"baseclass.h"
using namespace std;

extern void admin_system();
extern void teacher_system();
extern void student_system();

int main()
{
	cout << "Your Identity?	 Admin, Teacher, Student" << endl;
	cout << "Please enter: A, T, S ?	";	//选择进入分系统
	char Menu; cin >> Menu;
	switch (Menu)
	{
	case 'A':admin_system(); break;			//管理员系统
	case 'T':teacher_system(); break;		//教师系统
	case 'S':student_system(); break;		//学生系统
	default: cerr << "Error!" << endl;
	}
	return 0;
}