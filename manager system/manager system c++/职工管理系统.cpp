#include<iostream>
using namespace std;
#include"workManager.h"
#include"work.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
int choice = 0;
int main()
{
	/*work* m_work = NULL;
	m_work = new employee("1", "张三", 1);
	m_work->showinfo();
	delete m_work;
	m_work = new Manager("2", "李四", 2);
	m_work->showinfo();
	delete m_work;
	m_work = new boss("3", "王五", 3);
	m_work->showinfo();
	delete m_work;*/
	WorkManager m_workmanager;
	while (true)
	{
		m_workmanager.Show_menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			m_workmanager.exitsystem();
			break;
		case 1://增加职工
			m_workmanager.Add_emp();
			break;
		case 2://显示职工
			m_workmanager.show_emp();
			break; 
		case 3://删除职工
			m_workmanager.del_emp();
			break;
		case 4://修改职工
			m_workmanager.mod_emp();
			break;
		case 5://查找职工
			m_workmanager.find_emp();
			break;
		case 6://排序职工
			m_workmanager.sort_emp();
			break;
		case 7://清空文档
			m_workmanager.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}