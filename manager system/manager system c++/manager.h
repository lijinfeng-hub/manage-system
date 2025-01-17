#pragma once
#include<iostream>
#include"work.h"
using namespace std;
class Manager :public work
{
public:
	Manager(string id, string name, int did);
	void work::showinfo();
	string work::getdetid();
};