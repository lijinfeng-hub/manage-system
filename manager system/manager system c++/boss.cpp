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
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\tְ������:" << this->getdetid() << "\t��λְ�𣺹���˾���е�����" << endl;
 }
string boss::getdetid()
{
	return "�ϰ�";
 }