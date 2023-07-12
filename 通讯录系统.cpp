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
	cout << "******1.添加联系人******" << endl;
	cout << "******2.显示联系人******" << endl;
	cout << "******3.删除联系人******" << endl;
	cout << "******4.查找联系人******" << endl;
	cout << "******5.修改联系人******" << endl;
	cout << "******6.清空联系人******" << endl;
	cout << "******0.退出通讯录******" << endl;
	cout << "************************" << endl;
}
void addperson(struct Addressbook* abs)
{
	if (abs->size == MAX)
	{
		cout << "联系人已满，无法添加！" << endl;

	}
	else
	{   
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->array[abs->size].m_name = name;

		cout << "请输入性别：" << endl;
		cout << "1------男" << endl;
		cout << "2------女" << endl;
		int gender = 0;
		cin >> gender;
		abs->array[abs->size].m_gender = gender;

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->array[abs->size].m_age = age;

		cout << "请输入号码：" << endl;
		string tele;
		cin >> tele;
		abs->array[abs->size].m_tele = tele;

		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->array[abs->size].m_address = address;

		abs->size++;

		cout << "添加完毕！" << endl;
		system("pause");
		system("cls");

	}
}
void showperson(struct Addressbook* abs)
{
	if (abs->size == 0)
	{
		cout << "无联系人" << endl;

	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->array[i].m_name << endl;
			cout << "年龄：" << abs->array[i].m_age << endl;
			cout << "性别：" << abs->array[i].m_gender << endl;
			cout << "号码：" << abs->array[i].m_tele<< endl;
			cout << "地址：" << abs->array[i].m_address << endl;
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
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "查无此人"<< endl;
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
		cout << "删除完成" << endl;
	}
	system("pause");
	system("cls");
	
}
void searchperson(Addressbook* abs)
{
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		int i = isExist(abs, name);
		cout << "姓名：" << abs->array[i].m_name << endl;
		cout << "年龄：" << abs->array[i].m_age << endl;
		cout << "性别：" << abs->array[i].m_gender << endl;
		cout << "号码：" << abs->array[i].m_tele << endl;
		cout << "地址：" << abs->array[i].m_address << endl;
	}
	system("pause");
	system("cls");

}
void modifyperson(Addressbook* abs)
{
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		int i = isExist(abs, name);
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		abs->array[i].m_name = name;

		cout << "请输入性别：" << endl;
		cout << "1------男" << endl;
		cout << "2------女" << endl;
		int gender = 0;
		cin >> gender;
		abs->array[i].m_gender = gender;

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->array[i].m_age = age;

		cout << "请输入号码：" << endl;
		string tele;
		cin >> tele;
		abs->array[i].m_tele = tele;

		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->array[i].m_address = address;

		cout << "修改完毕！" << endl;
	}
	system("pause");
	system("cls");
}
void emptyperson(Addressbook* abs)
{
	abs->size = 0;
	cout << "删除成功" << endl;
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
			cout << "感谢使用！" << endl;
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