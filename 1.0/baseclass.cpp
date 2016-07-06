#define _CRT_SECURE_NO_WARNINGS
#include"baseclass.h"

//定义status类的方法
status::status(char n, int pn, int pw)
{
	status_ = n;
	pass_name = pn;
	pass_word = pw;
}

int status::get_pn() const
{
	return pass_name;
}

int status::get_pw() const
{
	return pass_word;
}

char status::get_sta() const
{
	return status_;
}

void status::set_pn(int n)
{
	pass_name = n;
}

void status::set_pw(int n)
{
	pass_word = n;
}

void status::set_sta(char n)
{
	status_ = n;
}

istream & operator>>(istream & is, status & st)
{
	is >> st.status_ >> st.pass_name >> st.pass_word;
	return is;
}

//定义person类的方法
person::person(char *n, int no_, int a, char s)
{
	strcpy(name, n);
	age = a;
	sex = s;
	no = no_;
}

int person::get_age() const
{
	return age;
}

char* person::get_name() const
{
	char *temp = new char[20];
	strcpy(temp, name);
	return temp;
}

char person::get_sex() const
{
	return sex;
}

int person::get_no() const
{
	return no;
}

void person::set_age(int a)
{
	age = a;
}

void person::set_name(char *n)
{
	strcpy(name, n);
}

void person::set_sex(char n)
{
	sex = n;
}

void person::set_no(int n)
{
	no = n;
}

void person::print() const
{
	cout << get_name() << " " << get_no() << " " << get_age() << " " << get_sex() << endl;
}

//定义course类方法
course::course(int cm, int cn, char *n, int cr)
{
	coursemode = cm;
	coursenum = cn;
	strcpy(coursename, n);
	credit = cr;
}

char* course::get_courname() const
{
	char *temp = new char[20];
	strcpy(temp, coursename);
	return temp;
}

void course::set_courname(char *n)
{
	strcpy(coursename, n);
}

int course::get_courmode() const
{
	return coursemode;
}

void course::set_courmode(int i)
{
	coursemode = i;
}

int course::get_credit() const
{
	return credit;
}

void course::set_credit(int i)
{
	credit = i;
}

int course::get_cournum() const
{
	return coursenum;
}

void course::set_cournum(int i)
{
	coursenum = i;
}

//定义coursescore的方法
coursescore::coursescore(int cm, int cn, char *n, int cr, int sc) 
	:course(cm, cn, n, cr), score(sc) {}

int coursescore::get_score() const
{
	return score;
}

void coursescore::set_score(int i)
{
	score = i;
}

void coursescore::display() const
{
	cout << get_courmode() << " " << get_courname() << " " 
		<< get_cournum() << " " << get_credit() << " " << get_score() << endl;
}

//定义coursepass类
coursepass::coursepass(int cm, int cn, char *n, int cr, char gr) 
	:course(cm, cn, n, cr), grade(gr) {}

char coursepass::get_grade() const
{
	return grade;
}

void coursepass::set_grade(char c)
{
	grade = c;
}

void coursepass::display() const
{
	cout << get_courmode() << " " << get_courname() << " " << get_cournum() << " " << get_credit() << " " << get_grade() << endl;
}

//定义studentcsore类
studentscore::studentscore(char *n, int no_, int a, char s, int cm, int cn, char *m, int cr, int sc)
	:person(n, no_, a, s), coursescore(cm, cn, m, cr, sc) {}

void studentscore::display() const
{
	cout << get_courmode() << " " << get_no() << " " << get_name() << " " << get_age() << " " << get_sex() << " "
		<< get_courname() << " " << get_cournum() << " " << get_credit() << " " << get_score() << endl;
}

ostream & operator<<(ostream & os, studentscore & stus)
{
	os << stus.get_courmode() << " " << stus.get_no() << " " << stus.get_name() << " " << stus.get_age() << " " << stus.get_sex() << " "
		<< stus.get_courname() << " " << stus.get_cournum() << " " << stus.get_credit() << endl;
	return os;
}

istream & operator>>(istream & is, studentscore & stus)
{
	char* n = new char[20]; int no_; int a; char s;
	int mo; char *cn = new char[20]; int cnum; int cre; int sco;
	/*cout << "Coursemode:"; */is >> mo; stus.set_courmode(mo);
	is >> no_; stus.set_no(no_);
	/*cout << "Student name:"; */is >> n; stus.set_name(n);
	/*cout << "Student age:"; */is >> a; stus.set_age(a);
	/*cout << "Student sex:";*/ is >> s; stus.set_sex(s);
	/*cout << "Coursename:"; */is >> cn; stus.set_courname(cn);
	/*cout << "Coursenumber:";*/ is >> cnum; stus.set_cournum(cnum);
	/*cout << "Course credit:"; */is >> cre; stus.set_credit(cre);
	/*cout << "Course score:"; */is >> sco; stus.set_score(sco);
	return is;
}

//定义studentpass类方法
studentpass::studentpass(char *n, int no_, int a, char s, int cm, int cn, char *m, int cr, char gr)
	:person(n, no_, a, s), coursepass(cm, cn, m, cr, gr) {}

void studentpass::display() const
{
	cout << get_courmode() << " " << get_no() << " " << get_name() << " " << get_age() << " " << get_sex() << " "
		<< get_courname() << " " << get_cournum() << " " << get_credit() << " " << get_grade() << endl;
}

ostream & operator<<(ostream & os, studentpass & stus)
{
	os << stus.get_courmode() << " " << stus.get_no() << " " << stus.get_name() << " " << stus.get_age() << " " << stus.get_sex() << " "
		<< stus.get_courname() << " " << stus.get_cournum() << " " << stus.get_credit() << " " << stus.get_grade() << endl;
	return os;
}

istream & operator>>(istream & is, studentpass & stus)
{
	char* n = new char[20]; int no_; int a; char s;
	int mo; char *cn = new char[20]; int cnum; int cre; char gra;
	is >> mo; stus.set_courmode(mo);
	is >> no_; stus.set_no(no_);
	/*	cout << "Student name:"; */is >> n; stus.set_name(n);
	/*	cout << "Student age:"; */is >> a; stus.set_age(a);
	/*	cout << "Student sex:"; */is >> s; stus.set_sex(s);
	/*	cout << "Coursename:"; */is >> cn; stus.set_courname(cn);
	/*	cout << "Coursenumber:"; */is >> cnum; stus.set_cournum(cnum);
	/*	cout << "Course credit:"; */is >> cre; stus.set_credit(cre);
	/*	cout << "Course grade:"; */is >> gra; stus.set_grade(gra);
	return is;
}

//定义teacher类

teacher::teacher(char *n, int no_, int a, char s, int cm, int cn, char *m, int cr) :person(n, no_, a, s), course(cm, cn, m, cr) {}

void teacher::display() const
{
	cout << get_courmode() << " " << get_no() << " " << get_name() << " " << get_age() << " " << get_sex() << " " << get_courname() << " " << get_cournum() << " " << get_credit() << endl;
}

ostream & operator<<(ostream &os, teacher &teach)
{
	os << teach.get_courmode() << " " << teach.get_no() << " " << teach.get_name() << " " << teach.get_age() << " " << teach.get_sex() << " "
		<< teach.get_courname() << " " << teach.get_cournum() << " " << teach.get_credit() << endl;
	return os;
}

istream & operator>>(istream &is, teacher &teach)
{
	char* n = new char[20]; int no_; int a; char s;
	int mo; char *cn = new char[20]; int cnum; int cre;
	/*	cout << "Coursemode:"*/; is >> mo; teach.set_courmode(mo);
	is >> no_; teach.set_no(no_);
	/*	cout << "Student name:"; */is >> n; teach.set_name(n);
	/*	cout << "Student age:"; */is >> a; teach.set_age(a);
	/*	cout << "Student sex:"; */is >> s; teach.set_sex(s);
	/*	cout << "Coursename:"; */is >> cn; teach.set_courname(cn);
	/*	cout << "Coursenumber:"; */is >> cnum; teach.set_cournum(cnum);
	/*	cout << "Course credit:"; */is >> cre; teach.set_credit(cre);
	return is;
}