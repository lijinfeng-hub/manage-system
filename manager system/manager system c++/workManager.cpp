#include"workManager.h"
using namespace std;
WorkManager::WorkManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout<<"文件不存在"<<endl;
		this->m_empNUm = 0;
		this->m_emparr = NULL;
		this->m_fileempty = true;
		ifs.close();
		return;
	}
	//2，文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空！" << endl;
		this->m_empNUm = 0;
		this->m_emparr = NULL;
		this->m_fileempty = true;
		ifs.close();
		return;
	}
	//3,文件存在并且记录数据
	int num = this->get_empnum();
	//cout << "职工的人数为：" << num << endl;
	this->m_empNUm = num;
	//开辟空间
	this->m_emparr = new work * [this->m_empNUm];
	//将文件中的数据，存到数组中
	this->init_emp();
	/*for (int i = 0; i < this->m_empNUm; i++)
	{
		cout << "职工编号:" << this->m_emparr[i]->m_id
			<< "姓名：" << this->m_emparr[i]->m_name
			<< "部门：" << this->m_emparr[i]->m_detid << endl;
	}*/
}
void WorkManager::init_emp()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	string id, name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		work* m_work = NULL;
		if (did == 1)
		{
			m_work = new employee(id,name,did);
		}
		else if (did == 2)
		{
			m_work = new Manager(id, name, did);
		}
		else
		{
			m_work = new boss(id,name,did);
		}
		this->m_emparr[index] =  m_work;
		index++;
	}
	ifs.close();
}
int WorkManager::get_empnum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	string id, name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

void WorkManager::Show_menu()
{
	cout << "*********************************************************************" << endl;
	cout << "*********************  欢迎使用职工管理系统！  **********************" << endl;
	cout << "***********************   0.退出管理程序  ***************************" << endl;
	cout << "***********************   1.增加职工信息  ***************************" << endl;
	cout << "***********************   2.显示职工信息  ***************************" << endl;
	cout << "***********************   3.删除离职职工  ***************************" << endl;
	cout << "***********************   4.修改职工信息  ***************************" << endl;
	cout << "***********************   5.查找职工信息  ***************************" << endl;
	cout << "***********************   6.按照编号排序  ***************************" << endl;
	cout << "***********************   7.清空所有文档  ***************************" << endl;
	cout << "*********************************************************************" << endl;
	cout << endl;
}
void WorkManager::exitsystem()
{
	cout << "欢迎下次再使用" << endl;
	system("pause");
	exit(0);//退出程序
}

void WorkManager::Add_emp()
{
	cout << "请输入一下添加职工的数量:" << endl;
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_empNUm + addnum;
		work**newspace=new work* [newsize];
		if (this->m_emparr != NULL)
		{
			for (int i = 0; i < this->m_empNUm; i++)
			{
				newspace[i] = this->m_emparr[i];
			}
		}
		for (int i = 0; i < addnum; i++)
		{
			string id; 
			string name;
			int dSelect;
			cout << "请输入" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位:" << endl;
			cout << "1,普通员工" << endl;
			cout << "2,经理" << endl;
			cout << "3,老板" << endl;
			cin >> dSelect;
			work* m_work = NULL;
			switch (dSelect)
			{
			case 1:
				m_work = new employee(id, name, 1);
				break;
			case 2:
				m_work = new Manager(id, name, 2);
				break;
			case 3:
				m_work = new boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[this->m_empNUm + i] = m_work;
		}
		delete[]this->m_emparr;
		this->m_emparr = newspace;
		this->m_empNUm = newsize;
		this->m_fileempty = false;
		cout << "成功添加了" << addnum <<"名职工" << endl;
		this->save();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
}
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);//用输出的方式打开文件--相当于写文件
		for (int i = 0; i < this->m_empNUm; i++)
		{
			ofs << this->m_emparr[i]->m_id << " "
				<< this->m_emparr[i]->m_name << " "
				<< this->m_emparr[i]->m_detid << endl;
		}
		ofs.close();
}
int WorkManager::isexit(string id)
{
	int index = -1;
	for (int i = 0; i < this->m_empNUm; i++)
	{
		if (this->m_emparr[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkManager::del_emp()
{
	if (this->m_fileempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要删除职工的编号" << endl;
		string id = "0";
		cin >> id;
		int index = this->isexit(id);
		if (index != -1)
		{
			for (int i = index ; i < this->m_empNUm-1; i++)
			{
				this->m_emparr[i] = this->m_emparr[i+1];
			}
			this->m_empNUm--;
			this->save();
			cout << "删除成功!" << endl;
		}
		else 
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManager::show_emp()
{
	if (this->m_fileempty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_empNUm; i++)
		{
			this->m_emparr[i]->showinfo();
		
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::mod_emp()
{
	if (this->m_fileempty)
	{
		cout << "文件不存在或存在为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号:" << endl;
		string id = "0";
		cin >> id;
		int ret=this->isexit(id);
		if (ret != -1)
		{
			delete this->m_emparr[ret];
			string newid = "0";
			string newname = "";
			int deselect = 0;
			cout << "查找到了：" << id << "号的职工，请输入新的ID号" << endl;
			cin >> newid;
			cout << "请输入新的姓名：" << endl;
			cin >> newname;
			cout << "请输入新的岗位：" << endl;
			cout << "1,普通职工" << endl;
			cout << "2，经理" << endl;
			cout << "3,老板" << endl;
			cin >> deselect;
			work* m_work = NULL;
			switch (deselect)
			{
			case 1:
				m_work = new employee(newid, newname, deselect);
				break;
			case 2:
				m_work = new Manager(newid, newname, deselect);
				break;
			case 3:
				m_work = new boss(newid, newname, deselect);
				break;
			default:
				break;
			}
			this->m_emparr[ret] = m_work;
			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人!" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManager::find_emp()
{
	if (this->m_fileempty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1,按照职工的编号" << endl;
		cout << "2,按照职工的姓名" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			string id = "0";
			cout << "请输入查找的id号" << endl;
			cin >> id;
			int ret=isexit(id);
			if (ret != -1)
			{
				cout << "查找成功!该职工的信息如下" << endl;
				this->m_emparr[ret]->showinfo();
			}
			else
			{
				cout << "查找失败，查无此人" <<  endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_empNUm; i++)
			{
				if (this->m_emparr[i]->m_name == name)
				{
					cout << "查找成功，职工编号为：" << this->m_emparr[i]->m_id <<"号职工信息如下：" << endl;
					this->m_emparr[i]->showinfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人，查找失败！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManager::sort_emp()
{
	if (this->m_fileempty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式：" << endl;
		cout << "1,按照职工编号进行升序" << endl;
		cout << "2,按照职工编号进行降序" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < m_empNUm; i++)
		{
			int minormax = i;
			for(int j=i+1;j<m_empNUm;j++)
			if (select == 1)
			{
				if (this->m_emparr[minormax]->m_id > m_emparr[j]->m_id)
				{
					minormax = j;
				}
			}
			else
			{
				if (this->m_emparr[minormax]->m_id < m_emparr[j]->m_id)
				{
					minormax = j;
				}
			}
			if (i != minormax)
			{
				work* tmp = this->m_emparr[i];
				this->m_emparr[i] = this->m_emparr[minormax];
				this->m_emparr[minormax] = tmp;
			}
		}

	}
	cout << "排序成功，排序后的结果为：" << endl;
	this->save();
	this->show_emp();
}
void WorkManager::clean_file()
{
	cout << "确认清空？" << endl;
	cout << "1,确认" << endl;
	cout << "2，返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(filename, ios::trunc);
		ofs.close();
		if (this->m_emparr != NULL)
		{
			for (int i = 0; i < m_empNUm; i++)
			{
				delete this->m_emparr[i];
				this->m_emparr[i] = NULL;
			}
			delete[]this->m_emparr;
			this->m_emparr = NULL;
			this->m_empNUm = 0;
			this->m_fileempty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
WorkManager::~WorkManager()
{
	for (int i = 0; i < m_empNUm; i++)
	{
		if (this->m_emparr[i] != NULL)
		{
			delete this->m_emparr[i];
		}
		delete[]this->m_emparr;
		this->m_emparr = NULL;
	}
}