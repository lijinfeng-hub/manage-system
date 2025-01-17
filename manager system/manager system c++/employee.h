#pragma once
#include<iostream>
using namespace std;
#include"work.h"
class employee :public work
{
public:
	employee(string id,string name,int did);
	virtual void showinfo();
	virtual string getdetid();
};