#pragma once
#include<iostream>
#include<string>

using namespace std;
class work
{
public:
	//
	virtual void showinfo()=0;
	virtual string getdetid() = 0;
	string m_id;
	string m_name;
	int m_detid;
};