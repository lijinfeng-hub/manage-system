#include<iostream>
using namespace std;
#include"boss.h"
boss::boss(string id, string name, int did)
{
	this->m_detid = did;
	this->m_id = id;
	this->m_name = name;
}
void boss::showinfo()
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t职工部门:" << this->getdetid() << "\t岗位职责：管理公司所有的事务" << endl;
 }
string boss::getdetid()
{
	return "老板";
 }