#define For(n) for(int index = 0;index < n;++index)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<time.h>
using namespace std;
constexpr int CNT = 10000;
constexpr int NUM = 1000;

struct MyStruct
{
	char c[1000];
};

void test1()
{
	vector<string>v;
	For(CNT)
	{
		v.clear();
		For(NUM)
		{
			auto t = time(0);
			v.emplace_back(to_string(t + index));
		}
	}
}

void test2()
{
	vector<string>v;
	char tmp[15];
	For(CNT)
	{
		v.clear();
		For(NUM)
		{
			sprintf(tmp, "%d", time(0) + index);
			v.emplace_back(tmp);
		}
	}
}

void test3()
{
	vector<char*>v;
	For(CNT)
	{
		if (index != 0)
		{
			For(NUM)
			{
				delete v[index];
			}
		}
		v.clear();
		For(NUM)
		{
			auto c = new char[15];
			sprintf(c, "%d", time(0) + index);
			v.emplace_back(c);
		}
	}
}

void test4()
{
	char** ch = new char* [NUM];
	For(NUM)
	{
		ch[index] = nullptr;
	}
	For(CNT)
	{
		For(NUM)
		{
			if (!ch[index])
			{
				delete ch[index];
			}
			ch[index] = new char[15];
			sprintf(ch[index], "%d", time(0) + index);
		}
	}
}

void test5()
{
	vector<shared_ptr<MyStruct>>v;
	For(CNT)
	{
		v.clear();
		For(NUM)
		{
			v.emplace_back(make_shared<MyStruct>());
		}
	}
}

void test6()
{
	vector<MyStruct*>v;
	For(CNT)
	{
		if (index != 0)
		{
			For(NUM)
			{
				delete v[index];
			}
		}
		v.clear();
		For(NUM)
		{
			v.emplace_back(new MyStruct);
		}
	}
}

/*
	���Խ��ۣ�ʹ��to_string��sprintf�Ĳ����14969��11445��ʹ��vector<string>��vector<char*>�Ĳ����11445��6878��ʹ��vector<char*>��char** �Ĳ����6878��5143
			  ʹ��shared_ptr����ָ��Ĳ����5740��3593
*/


int main() {
	auto c1 = clock();
	test1();
	cout << "test1 use " << clock() - c1 << endl;//14969
	auto c2 = clock();
	test2();
	cout << "test2 use " << clock() - c2 << endl;//11445
	auto c3 = clock();
	test3();
	cout << "test3 use " << clock() - c3 << endl;//6878
	auto c4 = clock();
	test4();
	cout << "test4 use " << clock() - c4 << endl;//5143

	auto c5 = clock();
	test5();
	cout << "test5 use " << clock() - c5 << endl;//5740
	auto c6 = clock();
	test6();
	cout << "test6 use " << clock() - c6 << endl;//3593
	system("pause");
	return 0;
}