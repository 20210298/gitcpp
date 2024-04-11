#include <cstring>
#include <iostream>

using namespace std;

class PermanentWorker {
	char name[100];
	int salary;
public:
	PermanentWorker(const char* name, int money) {
		strcpy(this->name, name);
		this->salary = money;
	}
	int GetPay() {
		return this->salary;
	}
	void ShowSalaryInfo() const {
		cout << "Name: " << this->name << endl;
		cout << "Salary: " << this->salary << endl;
	}
};

class EmployeeHandler {
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {};
	void AddEmployee(PermanentWorker* emp) {	
		empList[empNum] = emp;
		this->empNum++;
	}
	void ShowAllSalaryInfo() const {
		
	}
	void ShowTotalSalary() const {

	}
	~EmployeeHandler() {

	}
};