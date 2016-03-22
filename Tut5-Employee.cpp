//Priyen Munien 214529934

#include <iostream>
#include <string>

using namespace std;
class Employee
{
public:
	Employee();

	void getFirstName(string);		
	void getLastName(string);		
	void getEmployeeNum(double);			
	void Salary(float);
	float initSalary;

	static int getCount;
	
private:
	string FirstName;
	string LastName;
	string EmployeeNum;

	static int Count;
};

Employee::Employee()
{
	FirstName = "Priyen";
	LastName = "Munien";
	EmployeeNum = "2000";
	initSalary = 0;
	++Count;
}

void Employee::getFirstName(string FN)
{
	FirstName = FN;
}

void Employee::getLastName(string LN)
{
	LastName = LN;
}

void Employee::getEmployeeNum(double Num)
{
	Num = 0;
}

void Employee::Salary(float Sal)
{
	initSalary = Sal;
}


class Executive:public Employee {
public:

	Executive();
	void getBonus(float);
	float GrossSalary();

private:
	float Bonus;

};

Executive::Executive()
{
	Bonus = 0;
}

void Executive::getBonus(float bonus)
{
	Bonus = bonus;
}

float Executive::GrossSalary()
{
	return (this -> initSalary) + (this -> Bonus);
}

class Programmer : public Employee {
public:
	Programmer();
	void getExp(string);	
	float initPSalary(float);

private:
	string Exp;
}; 

Programmer::Programmer()
{

	string Exp = "Junior" ;
}

void Programmer::getExp( string exp)
{
  Exp = exp;
}

float Programmer::initPSalary(float Sal)
{
	if ((this -> Exp) == "Junior")
	{
		cout << "Junior Programmer: " << endl;
			return (this -> initSalary);
	}

	else if ((this -> Exp) == "Senior")
	{
		cout << "Senior Programmer: " << endl;
		return ((this -> initSalary) + 10000);
	}
		
	else if ((this -> Exp) == "Expert")
	{
		cout << "Expert Programmer: " << endl;
		return ((this -> initSalary) + 45000);
	}

	else 
		cout << "invalid entry" << endl;
	return (this -> initSalary);
} 

class Salesperson : public Employee {
public:
	Salesperson();
	void getSales(float);
    float initSPsalary();

private:
	float Sales;

};

Salesperson::Salesperson()
{
	Sales = 0;
}

void Salesperson::getSales(float sale)
{
	Sales = sale;
}

float Salesperson::initSPsalary()
{
	cout << "Including 1.5% sales commission" << endl;
	float comm;	
	comm = (this -> Sales*(1.5/100));

		return ((this -> initSalary) + comm);
}


class Temp : public Employee {
public:
	Temp();
	void getHours(int);
	
	float initTsalary();

private:
	int	Hours;
	float Rate;
};

Temp::Temp()
{
	Hours = 0;
	Rate = 65;
}

float Temp::initTsalary()
{
	return ((this -> Hours)*Rate);
}

int Employee::Count = 0;


int main()
{
	Employee tests;
	Executive cal;
	Programmer pro;
	Salesperson sp;
	Temp tmp;
	float sal;


	cout << "Executive Salary: " << endl;
	cal.Salary(45000);
	cal.getBonus(20000);
	sal = cal.GrossSalary();

	cout << sal << endl;

	cout << "Programmer's Salary: " << endl;
	pro.Salary(45000);
	pro.getExp("Senior");
	sal = pro.initPSalary(0);
	cout << sal << endl;

	cout << "Salesperson's Salary: " << endl;
	sp.Salary(45000);
	sp.getSales(500);

	sal = sp.initSPsalary();

	cout << sal << endl;

	cout << "Temp's Salary: " << endl;
	tmp.Salary(45000);
	tmp.getHours(20);
	
	sal = tmp.initTsalary();

	cout << sal << endl;
	return 0;
}
