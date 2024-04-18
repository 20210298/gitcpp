#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;

class Employee {
	char name[100];
public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}
	void ShowYourName() {
		cout << name << endl;
	}
	virtual int GetPay() const {	//이름, 형식이 완전히 동일해야함
		return 0;
	};
	virtual void ShowSalaryInfo() {}; //이름, 형식이 완전히 동일해야함
};

class PermanentWorker :public Employee {
	int salary;
public:
	PermanentWorker(const char* name, int money) : Employee(name) {
		this->salary = money;
	}
	int GetPay() const {
		return this->salary;
	}
	void ShowSalaryInfo() {
		ShowYourName();
		cout << "Salary: " << this->salary << endl << endl;
	}
};

class TemporaryWorker :public Employee {
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay) : Employee(name) {
		this->payPerHour = pay;
		this->workTime = 0;
	}
	void AddWorkTime(int time) {
		this->workTime += time;
	}
	int GetPay() const {
		return this->workTime * this->payPerHour;
	}
	void ShowSalaryInfo() {
		ShowYourName();
		cout << "Salary: " << this->GetPay() << endl << endl;
	}
};

class SalesWorker :public PermanentWorker {
	int saleResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money) {
		this->bonusRatio = ratio;
		this->saleResult = 0;
	}
	void AddSaleResult(int val) {
		this->saleResult += val;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + this->saleResult * this->bonusRatio;
	}
	void ShowSalaryInfo() {
		ShowYourName();
		cout << "Salary: " << this->GetPay() << endl << endl;
	}
};

class EmployeeHandler {
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {};
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		} //주석처리
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		} //주석처리
		cout << "Total Salary: " << sum << endl << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main() {
	//급여 관리를 목적으로 설계된 핸들러 객체 생성
	EmployeeHandler handler;
	//정규직 등록
	handler.AddEmployee(new PermanentWorker("Kim", 200));
	handler.AddEmployee(new PermanentWorker("Lee", 350));
	//비정규직 등록
	TemporaryWorker* tmp = new TemporaryWorker("Choi", 10);
	tmp->AddWorkTime(10);
	handler.AddEmployee(tmp);
	//영업직 등록
	SalesWorker* seller = new SalesWorker("Hong", 200, 0.1);
	seller->AddSaleResult(1000);
	handler.AddEmployee(seller);
	//이번 달에 지급해야할 급여 정보
	handler.ShowAllSalaryInfo();
	//이번 달에 지급해야할 총 급여
	handler.ShowTotalSalary();
	return 0;
}