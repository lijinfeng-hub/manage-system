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
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\tְ������:" << this->getdetid() << "\t��λְ������ϰ彻�������񣬲����·������Ա��" << endl;
}
string Manager::getdetid()
{
	return "����";
}