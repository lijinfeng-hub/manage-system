#include"workManager.h"
using namespace std;
WorkManager::WorkManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout<<"�ļ�������"<<endl;
		this->m_empNUm = 0;
		this->m_emparr = NULL;
		this->m_fileempty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_empNUm = 0;
		this->m_emparr = NULL;
		this->m_fileempty = true;
		ifs.close();
		return;
	}
	//3,�ļ����ڲ��Ҽ�¼����
	int num = this->get_empnum();
	//cout << "ְ��������Ϊ��" << num << endl;
	this->m_empNUm = num;
	//���ٿռ�
	this->m_emparr = new work * [this->m_empNUm];
	//���ļ��е����ݣ��浽������
	this->init_emp();
	/*for (int i = 0; i < this->m_empNUm; i++)
	{
		cout << "ְ�����:" << this->m_emparr[i]->m_id
			<< "������" << this->m_emparr[i]->m_name
			<< "���ţ�" << this->m_emparr[i]->m_detid << endl;
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
	cout << "*********************  ��ӭʹ��ְ������ϵͳ��  **********************" << endl;
	cout << "***********************   0.�˳��������  ***************************" << endl;
	cout << "***********************   1.����ְ����Ϣ  ***************************" << endl;
	cout << "***********************   2.��ʾְ����Ϣ  ***************************" << endl;
	cout << "***********************   3.ɾ����ְְ��  ***************************" << endl;
	cout << "***********************   4.�޸�ְ����Ϣ  ***************************" << endl;
	cout << "***********************   5.����ְ����Ϣ  ***************************" << endl;
	cout << "***********************   6.���ձ������  ***************************" << endl;
	cout << "***********************   7.��������ĵ�  ***************************" << endl;
	cout << "*********************************************************************" << endl;
	cout << endl;
}
void WorkManager::exitsystem()
{
	cout << "��ӭ�´���ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

void WorkManager::Add_emp()
{
	cout << "������һ�����ְ��������:" << endl;
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
			cout << "������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ:" << endl;
			cout << "1,��ͨԱ��" << endl;
			cout << "2,����" << endl;
			cout << "3,�ϰ�" << endl;
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
		cout << "�ɹ������" << addnum <<"��ְ��" << endl;
		this->save();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������������" << endl;
	}
}
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);//������ķ�ʽ���ļ�--�൱��д�ļ�
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ��ְ���ı��" << endl;
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
			cout << "ɾ���ɹ�!" << endl;
		}
		else 
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManager::show_emp()
{
	if (this->m_fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ����Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��:" << endl;
		string id = "0";
		cin >> id;
		int ret=this->isexit(id);
		if (ret != -1)
		{
			delete this->m_emparr[ret];
			string newid = "0";
			string newname = "";
			int deselect = 0;
			cout << "���ҵ��ˣ�" << id << "�ŵ�ְ�����������µ�ID��" << endl;
			cin >> newid;
			cout << "�������µ�������" << endl;
			cin >> newname;
			cout << "�������µĸ�λ��" << endl;
			cout << "1,��ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3,�ϰ�" << endl;
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
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���!" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManager::find_emp()
{
	if (this->m_fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1,����ְ���ı��" << endl;
		cout << "2,����ְ��������" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			string id = "0";
			cout << "��������ҵ�id��" << endl;
			cin >> id;
			int ret=isexit(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�!��ְ������Ϣ����" << endl;
				this->m_emparr[ret]->showinfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" <<  endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_empNUm; i++)
			{
				if (this->m_emparr[i]->m_name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_emparr[i]->m_id <<"��ְ����Ϣ���£�" << endl;
					this->m_emparr[i]->showinfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "���޴��ˣ�����ʧ�ܣ�" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkManager::sort_emp()
{
	if (this->m_fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1,����ְ����Ž�������" << endl;
		cout << "2,����ְ����Ž��н���" << endl;
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
	cout << "����ɹ��������Ľ��Ϊ��" << endl;
	this->save();
	this->show_emp();
}
void WorkManager::clean_file()
{
	cout << "ȷ����գ�" << endl;
	cout << "1,ȷ��" << endl;
	cout << "2������" << endl;
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
		cout << "��ճɹ���" << endl;
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