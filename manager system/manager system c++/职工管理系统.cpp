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
	m_work = new employee("1", "����", 1);
	m_work->showinfo();
	delete m_work;
	m_work = new Manager("2", "����", 2);
	m_work->showinfo();
	delete m_work;
	m_work = new boss("3", "����", 3);
	m_work->showinfo();
	delete m_work;*/
	WorkManager m_workmanager;
	while (true)
	{
		m_workmanager.Show_menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			m_workmanager.exitsystem();
			break;
		case 1://����ְ��
			m_workmanager.Add_emp();
			break;
		case 2://��ʾְ��
			m_workmanager.show_emp();
			break; 
		case 3://ɾ��ְ��
			m_workmanager.del_emp();
			break;
		case 4://�޸�ְ��
			m_workmanager.mod_emp();
			break;
		case 5://����ְ��
			m_workmanager.find_emp();
			break;
		case 6://����ְ��
			m_workmanager.sort_emp();
			break;
		case 7://����ĵ�
			m_workmanager.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}