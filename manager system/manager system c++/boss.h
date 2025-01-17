#pragma once
#include<iostream>
using namespace std;
#include"work.h"
class boss :public work
{
public:
	boss(string id, string name, int did);
	virtual void showinfo() ;
	virtual string getdetid() ;
};