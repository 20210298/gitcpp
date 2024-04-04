#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
using namespace COMP_POS;

NameCard::NameCard(const char* name, const char* company, const char* phone, int pos) {
	this->name = new char[strlen(name) + 1];
	this->name = strcpy(this->name, name);
	this->company = new char[strlen(company) + 1];
	this->company = strcpy(this->company, company);
	this->phone = new char[strlen(phone) + 1];
	this->phone = strcpy(this->phone,phone);
	this->position = pos;	 
}
void NameCard::ShowNameCardInfo() {
	cout << "이름 : " << this->name << endl;
	cout << "회사 : " << this->company << endl;
	cout << "연락처 : " << this->phone << endl;
	cout << "직급 : " << this->position << endl;
}
NameCard::~NameCard() {
	delete[] name;
	delete[] company;
	delete[] phone;
}

NameCard::
