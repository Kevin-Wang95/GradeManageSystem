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
	cout << "Please enter: A, T, S ?	";	//ѡ������ϵͳ
	char Menu; cin >> Menu;
	switch (Menu)
	{
	case 'A':admin_system(); break;			//����Աϵͳ
	case 'T':teacher_system(); break;		//��ʦϵͳ
	case 'S':student_system(); break;		//ѧ��ϵͳ
	default: cerr << "Error!" << endl;
	}
	return 0;
}