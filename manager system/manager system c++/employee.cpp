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
	cout << "ְ����ţ�" << this->m_id
	 << "\tְ������:" << this->m_name 
	 << "\tְ������:" << this->getdetid() << "\t��λְ����ɾ�����������" << endl;

}
string employee::getdetid()
{
	return "Ա��";
}