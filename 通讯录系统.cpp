#include <iostream>
using namespace std;
#define MAX 1000
#include <string>
struct Person
{
	string m_name;
	int m_gender;
	int m_age;
	string m_tele;
	string m_address;
};
struct Addressbook
{
	struct Person array[MAX];
	int size;
};
void showmenu()
{
	cout << "************************" << endl;
	cout << "******1.�����ϵ��******" << endl;
	cout << "******2.��ʾ��ϵ��******" << endl;
	cout << "******3.ɾ����ϵ��******" << endl;
	cout << "******4.������ϵ��******" << endl;
	cout << "******5.�޸���ϵ��******" << endl;
	cout << "******6.�����ϵ��******" << endl;
	cout << "******0.�˳�ͨѶ¼******" << endl;
	cout << "************************" << endl;
}
void addperson(struct Addressbook* abs)
{
	if (abs->size == MAX)
	{
		cout << "��ϵ���������޷���ӣ�" << endl;

	}
	else
	{   
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->array[abs->size].m_name = name;

		cout << "�������Ա�" << endl;
		cout << "1------��" << endl;
		cout << "2------Ů" << endl;
		int gender = 0;
		cin >> gender;
		abs->array[abs->size].m_gender = gender;

		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->array[abs->size].m_age = age;

		cout << "��������룺" << endl;
		string tele;
		cin >> tele;
		abs->array[abs->size].m_tele = tele;

		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->array[abs->size].m_address = address;

		abs->size++;

		cout << "�����ϣ�" << endl;
		system("pause");
		system("cls");

	}
}
void showperson(struct Addressbook* abs)
{
	if (abs->size == 0)
	{
		cout << "����ϵ��" << endl;

	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->array[i].m_name << endl;
			cout << "���䣺" << abs->array[i].m_age << endl;
			cout << "�Ա�" << abs->array[i].m_gender << endl;
			cout << "���룺" << abs->array[i].m_tele<< endl;
			cout << "��ַ��" << abs->array[i].m_address << endl;
		}

	}
	system("pause");
	system("cls");
}
int isExist(Addressbook* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->array[i].m_name == name)
			return i;
		else
			return -1;
	}
}
void deleteperson(Addressbook* abs)
{
	cout << "������������" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "���޴���"<< endl;
	}
	else
	{
		int ret = isExist(abs, name);
		{
			for (int i = ret; i < abs->size; i++)
			{
				abs->array[i] = abs->array[i = 1];
			}
			abs->size--;
		}
		cout << "ɾ�����" << endl;
	}
	system("pause");
	system("cls");
	
}
void searchperson(Addressbook* abs)
{
	cout << "������������" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		int i = isExist(abs, name);
		cout << "������" << abs->array[i].m_name << endl;
		cout << "���䣺" << abs->array[i].m_age << endl;
		cout << "�Ա�" << abs->array[i].m_gender << endl;
		cout << "���룺" << abs->array[i].m_tele << endl;
		cout << "��ַ��" << abs->array[i].m_address << endl;
	}
	system("pause");
	system("cls");

}
void modifyperson(Addressbook* abs)
{
	cout << "������������" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		int i = isExist(abs, name);
		cout << "������������" << endl;
		string name;
		cin >> name;
		abs->array[i].m_name = name;

		cout << "�������Ա�" << endl;
		cout << "1------��" << endl;
		cout << "2------Ů" << endl;
		int gender = 0;
		cin >> gender;
		abs->array[i].m_gender = gender;

		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->array[i].m_age = age;

		cout << "��������룺" << endl;
		string tele;
		cin >> tele;
		abs->array[i].m_tele = tele;

		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->array[i].m_address = address;

		cout << "�޸���ϣ�" << endl;
	}
	system("pause");
	system("cls");
}
void emptyperson(Addressbook* abs)
{
	abs->size = 0;
	cout << "ɾ���ɹ�" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbook abs;
	abs.size = 0;
	while (true)
	{
		showmenu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
			deleteperson(&abs);
			break;
		case 4:
			searchperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			emptyperson(&abs);
			break;
		case 0:
			cout << "��лʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}