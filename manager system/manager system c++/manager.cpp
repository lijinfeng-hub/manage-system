#include<iostream>
#include"manager.h"
Manager::Manager(string id, string name, int did)
{
	this->m_id = id;
	this->m_detid = did;
	this->m_name = name;
}
void Manager::showinfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t职工部门:" << this->getdetid() << "\t岗位职责：完成老板交给的任务，并且下发任务给员工" << endl;
}
string Manager::getdetid()
{
	return "经理";
}