#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>

using namespace std;
namespace RISK_LEVE {
	enum { RISK_A = 30, RISK_B = 20, RISK_C = 10 };
}

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
	EmployeeHandler() : empNum(0) {}
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

class ForeignSalesWorker:public SalesWorker {
	const int riskLevel;
public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk) :SalesWorker(name, money, ratio), riskLevel(risk) {}
	int GetRiskPay() const {
		return SalesWorker::GetPay() * this->riskLevel / 100;
	}
	int GetPay() const {
		return SalesWorker::GetPay()+this->GetRiskPay();
	}
	void ShowSalaryInfo() {
		ShowYourName();
		cout << "Salary: " << SalesWorker::GetPay() << endl;
		cout << "Risk pay: " << this->GetRiskPay() << endl;
		cout << "Sum: " << this->GetPay()<< endl << endl;
	}
};

int main() {
	EmployeeHandler handler; //급여 관리를 목적으로 설계된 핸들러 객체 생성
	ForeignSalesWorker* fSeller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVE::RISK_A);
	fSeller1->AddSaleResult(7000); //영업 실적 추가
	handler.AddEmployee(fSeller1);
	ForeignSalesWorker* fSeller2 = new ForeignSalesWorker("Choi", 1000, 0.1, RISK_LEVE::RISK_B);
	fSeller2->AddSaleResult(7000); //영업 실적 추가
	handler.AddEmployee(fSeller2);
	ForeignSalesWorker* fSeller3 = new ForeignSalesWorker("Kim", 1000, 0.1, RISK_LEVE::RISK_C);
	fSeller3->AddSaleResult(7000); //영업 실적 추가
	handler.AddEmployee(fSeller3);
	//이번 달 급여 지불 정보
	handler.ShowAllSalaryInfo();
	return 0;
}