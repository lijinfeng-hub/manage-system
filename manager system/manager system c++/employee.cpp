#include<iostream>
using namespace std;
#include"employee.h"
employee::employee(string id,string name,int did)
{
	this->m_name = name;
	this->m_id = id;
	this->m_detid = did;
}
void employee::showinfo()
{
	cout << "职工编号：" << this->m_id
	 << "\t职工姓名:" << this->m_name 
	 << "\t职工部门:" << this->getdetid() << "\t岗位职责：完成经理交给的任务" << endl;

}
string employee::getdetid()
{
	return "员工";
}