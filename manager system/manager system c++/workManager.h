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
//�˳�ϵͳ
	void exitsystem();
	//չʾ�˵�
	void Show_menu();
//��¼ְ��������
	int m_empNUm;
	//ְ������ָ��
	work** m_emparr;
	//���ְ��
	void Add_emp();
	void save();
	//�ж��ļ��Ƿ�Ϊ��
	bool m_fileempty;
	//ͳ���ļ�����
	int get_empnum();
	//��ʼ��Ա��
	void init_emp();
	//��ʾԱ��
	void show_emp();
	//ɾ��ְ��
	void del_emp();
	//�ж�ְ���Ƿ���ڣ���������򷵻�ְ������������λ�ã������ڷ���-1
	int isexit(string id);
	//�޸�ְ��
	void mod_emp();
	//����Ա��
	void find_emp();
	//��Ա����������
	void sort_emp();
	//����ļ�
	void clean_file();
	//��������
	~WorkManager();
};
