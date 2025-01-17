#pragma once
#include<iostream>
#include"work.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define filename "empfile.txt"
using namespace std;
class WorkManager
{
public:
	WorkManager();
//退出系统
	void exitsystem();
	//展示菜单
	void Show_menu();
//记录职工的人数
	int m_empNUm;
	//职工数组指针
	work** m_emparr;
	//添加职工
	void Add_emp();
	void save();
	//判断文件是否为空
	bool m_fileempty;
	//统计文件人数
	int get_empnum();
	//初始化员工
	void init_emp();
	//显示员工
	void show_emp();
	//删除职工
	void del_emp();
	//判断职工是否存在，如果存在则返回职工所在数组中位置，不存在返回-1
	int isexit(string id);
	//修改职工
	void mod_emp();
	//查找员工
	void find_emp();
	//对员工进行排序
	void sort_emp();
	//清空文件
	void clean_file();
	//析构函数
	~WorkManager();
};
