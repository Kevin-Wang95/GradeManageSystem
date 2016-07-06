#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<string>
#include<conio.h>
#include<fstream>
#include"baseclass.h"
#include"menu_ColorTextChoose.h"

using namespace std;
using std::cout;
using std::cin;

void input_stu();
void chag_stu();
void serh_stu();
void input_tech();
void chag_tech();
void serh_tech();
void order_student();

void serh_course_tech(int);		//搜索所教授的课程名单
void serh_fail_tech();			//搜索教授课程不及格学生名单

void serh_course_stu(int);		//搜索学生所有课程成绩
void serh_fail_stu(int);		//搜索学生不及格课程

bool verify(int, int, char);			//验证身份

void admin_system()
{
	ColorTextChoose_admin ad_m;
	cout << "请输入管理员工号: ";
	int n; cin >> n;
	cout << "请输入管理员密码: ";
	int pass; cin >> pass;
	//验证管理员身份
	if (!verify(n, pass, 'a'))
	{
		cerr << "The username or password is wrong!" << endl;
		system("pause");
		return;
	}
	for (;;)
	{
		switch (ad_m.TextGoing())
		{
		case 0:input_stu(); break;
		case 1:chag_stu(); break;
		case 2:serh_stu(); break;
		case 3:input_tech(); break;
		case 4:chag_tech(); break;
		case 5:serh_tech(); break;
		case 6:
		case -1:return;
		default:cerr << "Error! " << endl; system("pause");
		}
	}
}

void teacher_system()
{
	ColorTextChoose_teacher t_m;
	cout << "请输入教师工号: ";
	int n; cin >> n;
	cout << "请输入密码: ";
	int pass; cin >> pass;
	//验证教师身份
	if (!verify(n, pass, 't'))
	{
		cerr << "The username or password is wrong!" << endl; system("pause");
		return;
	}
	for (;;)
	{
		switch (t_m.TextGoing())
		{
		case 0:input_stu(); break;
		case 1:chag_stu(); break;
		case 2:serh_stu(); break;
		case 3:serh_course_tech(n); order_student(); break;
		case 4:serh_course_tech(n); serh_fail_tech(); break;
		case 5:
		case -1:return;
		default:cerr << "Error!" << endl; system("pause");
		}
	}
}

void student_system()
{
	ColorTextChoose_student st_m;
	cout << "请输入学生编号: ";
	int n; cin >> n;
	cout << "请输入学生密码: ";
	int pass; cin >> pass;
	//验证学生身份
	if (!verify(n, pass, 's'))
	{
		cerr << "The username or password is wrong!" << endl; system("pause");
		return;
	}

	for (;;)
	{
		switch (st_m.TextGoing())
		{
		case 0:serh_course_stu(n); break;
		case 1:serh_fail_stu(n); break;
		case 2:
		case -1:return;
		default:cerr << "Error!" << endl; system("pause");
		}
	}
}

void input_stu()
{
	ofstream fout("student.dat", ios::app);
	fout.seekp(ios::end);
	if (!fout) { cerr << "Error!Cannot open the file!"; system("pause"); exit(1); }
	cout << "选择输入模式:" << endl;
	cout << "1、对单一科目输入，输入q结束" << endl;
	cout << "2、输入单个学生的信息，输入q结束" << endl;
	int n; cin >> n;
	switch (n)
	{
	case 1:
		cout << "course mode(0 for score, 1 for pass): ";
		int temp_mode; cin >> temp_mode;
		if (!temp_mode)
		{
			cout << "course name: "; char *temp_cn = new char[20]; cin >> temp_cn;
			cout << "course number: "; int cn; cin >> cn;
			cout << "course credit: "; int cr; cin >> cr;
			do
			{
				cout << "student name: "; char* temp_sn = new char[20]; cin >> temp_sn;
				cout << "student number: "; int snum; cin >> snum;
				cout << "student age: "; int a; cin >> a;
				cout << "student sex(M/F): "; char s; cin >> s;
				cout << "course score: "; int sc; cin >> sc;
				cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
				cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
				cout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
					<< " " << temp_cn << " " << cn << " " << cr << " " << sc << endl;
				fout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
					<< " " << temp_cn << " " << cn << " " << cr << " " << sc << endl;
				cout << "Input success!" << endl;
				cout << "如果要退出，请输入q,否则请输入任意按键。" << endl;
				delete[] temp_sn;
			} while ((char)_getch() != 'q');
			delete[] temp_cn;
		}
		else
		{
			cout << "course name: "; char *temp_cn = new char[20]; cin >> temp_cn;
			cout << "course number: "; int cn; cin >> cn;
			cout << "course credit: "; int cr; cin >> cr;
			do
			{
				cout << "student name: "; char* temp_sn = new char[20]; cin >> temp_sn;
				cout << "student number: "; int snum; cin >> snum;
				cout << "student age: "; int a; cin >> a;
				cout << "student sex(M/F): "; char s; cin >> s;
				cout << "student grade: "; char gr; cin >> gr;
				cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
				cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
				cout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
					<< " " << temp_cn << " " << cn << " " << cr << " " << gr << endl;
				fout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
					<< " " << temp_cn << " " << cn << " " << cr << " " << gr << endl;
				cout << "Input success!" << endl;
				cout << "如果要退出，请输入q,否则请输入任意按键。" << endl;
				delete[] temp_sn;
			} while ((char)_getch() != 'q');
			delete[] temp_cn;
		};
		break;

	case 2:
		do
		{
			cout << "course mode(0 for score, 1 for pass): "; int temp_mode; cin >> temp_mode;
			if (!temp_mode)
			{
				cout << "student name: "; char* temp_sn = new char[20]; cin >> temp_sn;
				cout << "student number: "; int snum; cin >> snum;
				cout << "student age: "; int a; cin >> a;
				cout << "student sex(M/F): "; char s; cin >> s;
				cout << "course name: "; char *temp_cn = new char[20]; cin >> temp_cn;
				cout << "course number: "; int cn; cin >> cn;
				cout << "course credit: "; int cr; cin >> cr;
				cout << "course score: "; int sc; cin >> sc;
				cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
				cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
				cout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
					<< " " << temp_cn << " " << cn << " " << cr << " " << sc << endl;
				fout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
					<< " " << temp_cn << " " << cn << " " << cr << " " << sc << endl;
				cout << "Input success!" << endl;
				cout << "如果要退出，请输出q,否则请输入任意按键。" << endl;
				delete[] temp_sn; delete[] temp_cn;
			}
			else
			{
				cout << "student name: "; char* temp_sn = new char[20]; cin >> temp_sn;
				cout << "student number: "; int snum; cin >> snum;
				cout << "student age: "; int a; cin >> a;
				cout << "student sex(M/F): "; char s; cin >> s;
				cout << "course name: "; char *temp_cn = new char[20]; cin >> temp_cn;
				cout << "course number: "; int cn; cin >> cn;
				cout << "course credit: "; int cr; cin >> cr;
				cout << "course grade: "; char gr; cin >> gr;
				cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
				cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
				cout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
					<< " " << temp_cn << " " << cn << " " << cr << " " << gr << endl;
				fout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
					<< " " << temp_cn << " " << cn << " " << cr << " " << gr << endl;
				cout << "Input success!" << endl;
				cout << "如果要退出，请输入q,否则请输入任意按键。" << endl;
				delete[] temp_sn;
				delete[] temp_cn;
			}
		} while ((char)_getch() != 'q');
	}
	fout.close();
}

void chag_stu()
{
	ifstream fin("student.dat", ios::in);
	if (!fin) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	int aim;
	cout << "Aim student Number: ";
	cin >> aim;
	int control = 0;
	for (; fin.eof() == false;)
	{
		int temp_cm = -1;
		fin >> temp_cm;
		if (temp_cm == 0)
		{
			fin.seekg(-1, ios::cur);
			studentscore temp_stu;
			fin >> temp_stu;
			if (temp_stu.get_no() == aim)
			{
				if (control < 1)
				{
					cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
					cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
					control++;
				}
				temp_stu.display();
			}
		}
		else
		{
			if (temp_cm == 1)
			{
				fin.seekg(-1, ios::cur);
				studentpass temp_stu;
				fin >> temp_stu;
				if (temp_stu.get_no() == aim)
				{
					if (control < 1)
					{
						cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
						cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
						control++;
					}
					temp_stu.display();
				}
			}
		}
	}
	if (control < 1)
	{
		cout << "Error!Cannot find the student!" << endl; system("pause");
		return;
	}
	cout << "Aim course number: ";
	int aim_course;
	cin >> aim_course;
	fin.close();
	ifstream fin2("student.dat", ios::in);
	if (!fin2) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	for (; fin2.eof() == false;)
	{
		ofstream fout; fout.open("student.dat", ios::app);
		int temp_no = -1;
		fin2 >> temp_no;
		if (temp_no == 0)
		{
			fin2.seekg(-1, ios::cur);
			fout.seekp(fin2.tellg());
			studentscore temp_stu;
			fin2 >> temp_stu;
			if (temp_stu.get_no() != aim)
				continue;
			if (temp_stu.get_cournum() != aim_course)
				continue;
			temp_stu.display();
			bool whe_chg = false; cin.ignore();
			cout << "Change student name? y/n "; if (cin.get() == 'y') { char* temp_sn = new char[20]; cin >> temp_sn; temp_stu.set_name(temp_sn); delete[] temp_sn; whe_chg = true; } cin.ignore();
			cout << "Change student number? y/n "; if (cin.get() == 'y') { int snum; cin >> snum; temp_stu.set_no(snum); whe_chg = true; } cin.ignore();
			cout << "Change student age? y/n "; if (cin.get() == 'y') { int a; cin >> a; temp_stu.set_age(a);  whe_chg = true; } cin.ignore();
			cout << "Change student sex(M/F)? y/n "; if (cin.get() == 'y') { char s; cin >> s; temp_stu.set_sex(s); whe_chg = true; } cin.ignore();
			cout << "Change course name? y/n "; if (cin.get() == 'y') { char *temp_cn = new char[20]; cin >> temp_cn; temp_stu.set_courname(temp_cn); delete[] temp_cn; whe_chg = true; }
			cout << "Change course number? y/n "; if (cin.get() == 'y') { int cn; cin >> cn; temp_stu.set_cournum(cn); whe_chg = true; } cin.ignore();
			cout << "Change course credit? y/n "; if (cin.get() == 'y') { int cr; cin >> cr; temp_stu.set_credit(cr); whe_chg = true; } cin.ignore();
			cout << "Change course score? y/n "; if (cin.get() == 'y') { int sc; cin >> sc; temp_stu.set_score(sc); whe_chg = true; } cin.ignore();
			if (whe_chg == true)
				fout << temp_stu;
			cout << "change successful!" << endl; system("pause");
			return;
		}
		else
		{
			if (temp_no == 1)
			{
				fin2.seekg(-1, ios::cur);
				fout.seekp(fin2.tellg());
				studentpass temp_stu;
				fin2 >> temp_stu;
				if (temp_stu.get_no() != aim)
					continue;
				if (temp_stu.get_cournum() != aim_course)
					continue;
				temp_stu.display();
				bool whe_chg = false;
				cout << "Change student name? y/n "; if (cin.get() == 'y') { char* temp_sn = new char[20]; cin >> temp_sn; temp_stu.set_name(temp_sn); delete[] temp_sn; whe_chg = true; } cin.ignore();
				cout << "Change student number? y/n "; if (cin.get() == 'y') { int snum; cin >> snum; temp_stu.set_no(snum); whe_chg = true; } cin.ignore();
				cout << "Change student age? y/n "; if (cin.get() == 'y') { int a; cin >> a; temp_stu.set_age(a);  whe_chg = true; } cin.ignore();
				cout << "Change student sex(M/F)? y/n "; if (cin.get() == 'y') { char s; cin >> s; temp_stu.set_sex(s); whe_chg = true; } cin.ignore();
				cout << "Change course name? y/n "; if (cin.get() == 'y') { char *temp_cn = new char[20]; cin >> temp_cn; temp_stu.set_courname(temp_cn); delete[] temp_cn; whe_chg = true; }
				cout << "Change course number? y/n "; if (cin.get() == 'y') { int cn; cin >> cn; temp_stu.set_cournum(cn); whe_chg = true; } cin.ignore();
				cout << "Change course credit? y/n "; if (cin.get() == 'y') { int cr; cin >> cr; temp_stu.set_credit(cr); whe_chg = true; } cin.ignore();
				cout << "Change course grade? y/n "; if (cin.get() == 'y') { char gr; cin >> gr; temp_stu.set_grade(gr); whe_chg = true; } cin.ignore();
				if (whe_chg == true)
					fout << temp_stu;
				cout << "change successful!" << endl; system("pause");
				return;
			}
		}
		fout.close();
	}
	cout << "Cannot find the COURSE!" << endl; system("pause");
	fin2.close();
}

void serh_stu()
{
	ifstream fin("student.dat", ios::in);
	if (!fin) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	int aim;
	cout << "Aim student Number: ";
	cin >> aim;
	int control = 0;
	for (; fin.eof() == false;)
	{
		int temp_cm = -1;
		fin >> temp_cm;
		if (temp_cm == 0)
		{
			fin.seekg(-1, ios::cur);
			studentscore temp_stu;
			fin >> temp_stu;
			if (temp_stu.get_no() == aim)
			{
				if (control < 1)
				{
					cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
					cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
					control++;
				}
				temp_stu.display();
			}
		}
		else
		{
			if (temp_cm == 1)
			{
				fin.seekg(-1, ios::cur);
				studentpass temp_stu;
				fin >> temp_stu;
				if (temp_stu.get_no() == aim)
				{
					if (control < 1)
					{
						cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
						cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
						control++;
					}
					temp_stu.display();
				}
			}
		}
	}
	if (control < 1)
	{
		cout << "Error!Cannot find the student" << endl; system("pause");
		return;
	}
	fin.close();
	system("pause");
	return;
}

void input_tech()
{
	ofstream fout("teacher.dat", ios::app);
	fout.seekp(ios::end);
	if (!fout) { cerr << "Error!Cannot open the file!"; system("pause"); exit(1); }
	cout << "选择输入模式:" << endl;
	cout << "1、对同一老师输入所有科目，输入q结束" << endl;
	cout << "2、输入单个老师的信息，输入q结束" << endl;
	int n; cin >> n;
	switch (n)
	{
	case 1:
	{cout << "teacher number: "; int snum; cin >> snum;
	cout << "teacher name: "; char* temp_sn = new char[20]; cin >> temp_sn;
	cout << "teacher age: "; int a; cin >> a;
	cout << "teacher sex(M/F): "; char s; cin >> s;
	do
	{
		cout << "course mode: "; int temp_mode; cin >> temp_mode;
		cout << "course name: "; char *temp_cn = new char[20]; cin >> temp_cn;
		cout << "course number: "; int cn; cin >> cn;
		cout << "course credit: "; int cr; cin >> cr;
		cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
		cout << endl << "courm snum sname age sex courname cournum credit" << endl;
		cout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
			<< " " << temp_cn << " " << cn << " " << cr << endl;
		fout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
			<< " " << temp_cn << " " << cn << " " << cr << endl;
		cout << "Input success!" << endl;
		cout << "如果要退出，请输入q,否则请输入任意按键。" << endl;
		delete[] temp_cn;
	} while ((char)_getch() != 'q');
	delete[] temp_sn; 
	}
	break;
	case 2:
	{
	do
		{
			cout << "course mode(0 for score, 1 for pass): "; int temp_mode; cin >> temp_mode;
			cout << "teacher name: "; char* temp_sn = new char[20]; cin >> temp_sn;
			cout << "teacher number: "; int snum; cin >> snum;
			cout << "teacher age: "; int a; cin >> a;
			cout << "teacher sex(M/F): "; char s; cin >> s;
			cout << "course name: "; char *temp_cn = new char[20]; cin >> temp_cn;
			cout << "course number: "; int cn; cin >> cn;
			cout << "course credit: "; int cr; cin >> cr;
			cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
			cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
			cout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
				<< " " << temp_cn << " " << cn << " " << cr << endl;
			fout << temp_mode << " " << snum << " " << temp_sn << " " << a << " " << s
				<< " " << temp_cn << " " << cn << " " << cr << endl;
			cout << "Input success!" << endl;
			cout << "如果要退出，请输入q,否则请输入任意按键。" << endl;
			delete[] temp_sn;
			delete[] temp_cn;
		} while ((char)_getch() != 'q');
	}
	}
	fout.close();
}

void chag_tech()
{
	ifstream fin1("teacher.dat", ios::in);
	if (!fin1) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	int aim;
	cout << "Aim teacher Number: ";
	cin >> aim;
	int control = 0;
	for (; fin1.eof() == false;)
	{
		teacher temp_teach;
		fin1 >> temp_teach;
		if (temp_teach.get_no() == aim)
		{
			if (control < 1)
				{
					cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
					cout << endl << "courm snum sname age sex courname cournum credit" << endl;
					control++;
				}
				temp_teach.display();
		}
	}
	if (control < 1)
	{
		cout << "Error!Cannot find the teacher!" << endl; system("pause");
		return;
	}
	cout << "Aim course number: ";
	int aim_course;
	cin >> aim_course;
	fin1.close();
	ifstream fin("teacher.dat", ios::in);
	if (!fin) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	for (; fin.eof() == false;)
	{
		ofstream fout; fout.open("teacher.dat", ios::app);
		fout.seekp(fin.tellg());
		teacher temp_teach;
		fin >> temp_teach;
		if (temp_teach.get_no() != aim)
			continue;
		if (temp_teach.get_cournum() != aim_course)
			continue;
		temp_teach.display();
		bool whe_chg = false;
		cout << "Change teacher name? y/n"; if (cin.get() == 'y') { char* temp_sn = new char[20]; cin >> temp_sn; temp_teach.set_name(temp_sn);  delete[] temp_sn; whe_chg = true; } cin.ignore();
		cout << "Change teacher number? y/n "; if (cin.get() == 'y') { int snum; cin >> snum; temp_teach.set_no(snum); whe_chg = true; } cin.ignore();
		cout << "Change teacher age? y/n "; if (cin.get() == 'y') { int a; cin >> a; temp_teach.set_age(a); whe_chg = true; } cin.ignore();
		cout << "Change teacher sex(M/F)? y/n "; if (cin.get() == 'y') { char s; cin >> s; temp_teach.set_sex(s); whe_chg = true; } cin.ignore();
		cout << "Change course name? y/n "; if (cin.get() == 'y') { char *temp_cn = new char[20]; cin >> temp_cn; temp_teach.set_courname(temp_cn); delete[] temp_cn; whe_chg = true; } cin.ignore();
		cout << "Change course number? y/n "; if (cin.get() == 'y') { int cn; cin >> cn; temp_teach.set_cournum(cn); whe_chg = true; } cin.ignore();
		cout << "Change course credit? y/n "; if (cin.get() == 'y') { int cr; cin >> cr; temp_teach.set_credit(cr); whe_chg = true; } cin.ignore();
			fout << temp_teach;
		cout << "change successful!" << endl; system("pause");
		return;
		fout.close();
	}
	cout << "Cannot find the course!" << endl; system("pause");
	fin.close();
}

void serh_tech()
{
	ifstream fin("teacher.dat", ios::in);
	if (!fin) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	int aim;
	cout << "Aim teacher Number: ";
	cin >> aim;
	int control = 0;
	for (; fin.eof() == false;)
	{
		teacher temp_teach;
		fin >> temp_teach;
		if (temp_teach.get_no() == aim)
		{
			if (control < 1)
			{
				cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
				cout << endl << "courm snum sname age sex courname cournum credit" << endl;
				control++;
			}
			temp_teach.display();
		}
	}
	if (control < 1)
	{
		cout << "Error!Cannot find the teacher!" << endl; system("pause");
		return;
	}
	fin.close();
	system("pause");
}


void serh_course_tech(int n)
{
	teacher *temp_teach[20];
	for (int i = 0; i < 20; i++)
		temp_teach[i] = new teacher;
	int count = 0;
	//找出教师所有课程
	ifstream fin("teacher.dat", ios::in);
	if (!fin) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	int control = 0;
	for (; fin.eof() == false;)
	{
		fin >> *temp_teach[count];
		if (temp_teach[count]->get_no() == n)
		{
			if (control < 1)
			{
				cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
				cout << endl << "courm snum sname age sex courname cournum credit" << endl;
				control++;
			}
			count++;
		}
	}
	fin.close();
	//对课程排序，使得记通过的课排在记分数的课程后
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (temp_teach[j]->get_courmode() == 1 && temp_teach[j + 1]->get_courmode() == 0)
			{
				teacher *temp = new teacher;
				*temp = *temp_teach[j];
				*temp_teach[j] = *temp_teach[j + 1];
				*temp_teach[j + 1] = *temp;
				delete temp;
			}
		}
	}
	for (int i = 0; i < count; i++)
		temp_teach[i]->display();
	for (int i = 0; i < 20; i++)
		delete[] temp_teach[i];
	system("pause");
}

void order_student()
{
	studentscore *temp1[40]; int student_count1 = 0;
	studentpass *temp2[40]; int student_count2 = 0;
	for (int i = 0; i < 40; i++)
	{
		temp1[i] = new studentscore;
		temp2[i] = new studentpass;
	}
	cout << "请输入待查询的课程号: ";
	int n; cin >> n;
	ifstream fin("student.dat", ios::in);
	int control = 0;
	int count = 0;
	for (; fin.eof() == false;)
	{
		int temp_cm = -1;
		fin >> temp_cm;
		if (temp_cm == 0)
		{
			fin.seekg(-1, ios::cur);
			fin >> *temp1[student_count1];
			if (temp1[student_count1]->get_cournum() == n)
			{
				if (control < 1)
				{
					cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
					cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
					control++;
				}
				student_count1++;
			}
		}
		else
		{
			if (temp_cm == 1)
			{
				fin.seekg(-1, ios::cur);
				fin >> *temp2[student_count2];
				if (temp2[student_count2]->get_cournum() == n)
				{
					if (control < 1)
					{
						cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
						cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
						control++;
					}
					student_count2++;
				}
			}
		}
		if (control < 1)
		{
			cout << "Cannot find the student!" << endl; system("pause");
		}
	}
	fin.close();
	//进行成绩排序
	for (int i = 0; i < student_count1 - 1; i++)
	{
		for (int j = 0; j < student_count1 - i - 1; j++)
		{
			if (temp1[j]->get_score() < temp1[j + 1]->get_score())
			{
				studentscore *temp = new studentscore;
				*temp = *temp1[j];
				*temp1[j] = *temp1[j + 1];
				*temp1[j + 1] = *temp;
				delete temp;
			}
		}
	}
	for (int i = 0; i < student_count2 - 1; i++)
	{
		for (int j = 0; j < student_count2 - i - 1; j++)
		{
			if (temp2[j]->get_grade() == 'F' || temp2[j + 1]->get_grade() == 'P')
			{
				studentpass *temp = new studentpass;
				*temp = *temp2[j];
				*temp2[j] = *temp2[j + 1];
				*temp2[j + 1] = *temp;
				delete temp;
			}
		}
	}
	//输出成绩
	for (int i = 0; i < student_count1; i++)
	{
		temp1[i]->display();
		delete[] temp1[i];
	}
	for (int i = 0; i < student_count2; i++)
	{
		temp2[i]->display();
		delete[] temp2[i];
	}
	system("pause");
}

void serh_fail_tech()
{
	cout << "请输入待查询的课程号: ";
	int n; cin >> n;
	ifstream fin("student.dat", ios::in);
	int control = 0;
	int count = 0;
	for (; fin.eof() == false;)
	{
		int temp_cm = -1;
		fin >> temp_cm;
		if (temp_cm == 0)
		{
			fin.seekg(-1, ios::cur);
			studentscore temp;
			fin >> temp;
			if (temp.get_cournum() == n)
			{
				if (control < 1)
				{
					cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
					cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
					control++;
				}
				if (temp.get_score() < 60)
				{
					temp.display();
					count++;
				}
			}
		}
		else
		{
			if (temp_cm == 1)
			{
				fin.seekg(-1, ios::cur);
				studentpass temp;
				fin >> temp;
				if (temp.get_cournum() == n)
				{
					if (control < 1)
					{
						cout << endl << "courm for course modem,snum for student number" << endl << "courname for course name,cournum for course number" << endl;
						cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
						control++;
					}
					if (temp.get_grade() == 'F')
					{
						temp.display();
						count++;
					}
				}
			}
		}
		if (control < 1)
		{
			cout << "Cannot find the student!" << endl; system("pause");
		}
	}
	fin.close();
	cout << "The number of student that fail is: " << count << endl;
	system("pause");
}

void serh_course_stu(int n) 
{
	//找出该生的所有课程
	studentscore * temp_stu1[40];
	studentpass * temp_stu2[40];
	for (int i = 0; i < 40; i++)
	{
		temp_stu1[i] = new studentscore;
		temp_stu2[i] = new studentpass;
	}
	int count_score = 0, count_pass = 0;
	ifstream fin("student.dat", ios::in);
	if (!fin) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	int control = 0;
	for (; fin.eof() == false;)
	{
		int temp_cm = -1;
		fin >> temp_cm;
		if (temp_cm == 0)
		{
			fin.seekg(-1, ios::cur);
			fin >> *temp_stu1[count_score];
			if (temp_stu1[count_score]->get_no() == n)
			{
				if (control < 1)
				{
					cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
					cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
					control++;
				}
				count_score++;
			}
		}
		else
		{
			if (temp_cm == 1)
			{
				fin.seekg(-1, ios::cur);
				fin >> *temp_stu2[count_pass];
				if (temp_stu2[count_pass]->get_no() == n)
				{
					if (control < 1)
					{
						cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
						cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
						control++;
					}
					count_pass++;
				}
			}
		}
	}
	fin.close();
	if (control < 1)
	{
		cout << "No grade data!" << endl;
		return;
	}
	//学生成绩排序
	for (int i = 0; i < count_score - 1; i++)
	{
		for (int j = 0; j < count_score - i - 1; j++)
		{
			if (temp_stu1[j]->get_score() < temp_stu1[j + 1]->get_score())
			{
				studentscore *temp = new studentscore;
				*temp = *temp_stu1[j];
				*temp_stu1[j] = *temp_stu1[j + 1];
				*temp_stu1[j + 1] = *temp;
				delete temp;
			}
		}
	}

	for (int i = 0; i < count_pass - 1; i++)
	{
		for (int j = 0; j < count_pass - i - 1; j++)
		{
			if (temp_stu2[j]->get_grade() == 'F' && temp_stu2[j + 1]->get_grade() == 'P')
			{
				studentpass *temp = new studentpass;
				*temp = *temp_stu2[j];
				*temp_stu2[j] = *temp_stu2[j + 1];
				*temp_stu2[j + 1] = *temp;
				delete temp;
			}
		}
	}
	//学生成绩显示
	int total_credit = 0, total_score = 0;
	for (int i = 0; i < count_score; i++)
	{
		temp_stu1[i]->display();
		total_credit += temp_stu1[i]->get_credit();
		total_score += temp_stu1[i]->get_credit() *temp_stu1[i]->get_score();
	}
	for (int i = 0; i < count_pass; i++)
		temp_stu2[i]->display();
	cout << "Average score: " << total_score / total_credit << endl;
	system("pause");
	for (int i = 0; i < 40; i++)
	{
		delete[] temp_stu1[i];
		delete[] temp_stu2[i];
	}
}

void serh_fail_stu(int n) 
{
	//找出该生的所有课程
	studentscore * temp_stu1[40];
	studentpass * temp_stu2[40];
	for (int i = 0; i < 40; i++)
	{
		temp_stu1[i] = new studentscore;
		temp_stu2[i] = new studentpass;
	}
	int count_score = 0, count_pass = 0;
	ifstream fin("student.dat", ios::in);
	if (!fin) { cerr << "Error!Cannot open the file!" << endl; system("pause"); exit(1); }
	int control = 0;
	for (; fin.eof() == false;)
	{
		int temp_cm = -1;
		fin >> temp_cm;
		if (temp_cm == 0)
		{
			fin.seekg(-1, ios::cur);
			fin >> *temp_stu1[count_score];
			if (temp_stu1[count_score]->get_no() == n)
			{
				if (control < 1)
				{
					cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
					cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
					control++;
				}
				count_score++;
			}
		}
		else
		{
			if (temp_cm == 1)
			{
				fin.seekg(-1, ios::cur);
				fin >> *temp_stu2[count_pass];
				if (temp_stu2[count_pass]->get_no() == n)
				{
					if (control < 1)
					{
						cout << endl << "courm for course modem,snum for student number" << "courname for course name,cournum for course number" << endl;
						cout << endl << "courm snum sname age sex courname cournum credit grade/score" << endl;
						control++;
					}
					count_pass++;
				}
			}
		}
	}
	fin.close();
	if (control < 1)
	{
		cout << "NO failed course!" << endl;
		return;
	}
	//查找不及格课程
	for (int i = 0; i < count_score; i++)
		if (temp_stu1[i]->get_score() < 60)
			temp_stu1[i]->display();
	for (int i = 0; i < count_pass; i++)
		if (temp_stu2[i]->get_grade() == 'F')
			temp_stu2[i]->display();
	system("pause");
	for (int i = 0; i < 40; i++)
	{
		delete[] temp_stu1[i];
		delete[] temp_stu2[i];
	}
}

bool verify(int n, int pass, char status_)
{
	ifstream fin("password.dat", ios::in);
	for (; fin.eof() == false;)
	{
		status check;
		fin >> check;
		if (check.get_sta() == status_)
		{
			if (check.get_pn() == n)
			{
				if (check.get_pw() == pass)
				{
					fin.close();
					return true;
				}
				else
				{
					fin.close();
					return false;
				}
			}
		}
	}
	fin.close();
	return false;
}