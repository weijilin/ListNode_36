#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// ��������
// �����������⣺���������ܲ������麯���� ������ԣ�ʲô����½�����ý�����������������ó��麯����
class Base
{
public:
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	Derived()
	{
		_p = new int[10];
	}

	~Derived()
	{
		if (_p)
		{
			delete[] _p;
		}
		cout << "Derived::~Derived()" << endl;

		// call Base::~Base();
	}

protected:
	int* _p;
};

int main()
{
	Base* pb = new Derived;
	delete pb;

	return 0;
}
#endif

#if 0
// C++98--���������ܰ����û�������д�ļ��
// C++11----override: �ñ����������û�����������Ƿ�Ի����е�ĳ���麯��������д
//                     �ǣ�����ɹ�
//                     �񣺱��뱨��
// ע�⣺overrideֻ������������麯��
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	//void TestFunc2()  ���뱨��������TestFunc2�����麯��
	virtual void TestFunc2() // OK
	{
		cout << "Base::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
};

class Derived : public Base
{
public:
	// �����ĺ������ֲ�ͬ
	//virtual void TetsFunc1()override  // ������������ͬ��û�й�����д
	virtual void TestFunc1()override    // OK
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	// ����TestFunc2�����麯��
	virtual void TestFunc2()override
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	// ������麯���Ĳ����б�ͬ
	// virtual void TestFunc3(int)override  ���뱨���������TestFunc3�麯�������б�ͬ
	virtual void TestFunc3()override
	{
		cout << "Derived::TestFunc3()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}

int main()
{
	Base b;
	Derived d;
	TestFunc(b);
	TestFunc(d);
	return 0;
}
#endif


// final��������麯�����������麯�����ܱ���������д
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
};

class Derived : public Base
{
public:
	virtual void TestFunc1()final
	{
		cout << "Derived::TestFunc1()" << endl;
	}
};

class D : public Derived
{
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.TestFunc1();
}

int main()
{
	Base b;
	Derived d;
	D dd;
	TestFunc(b);
	TestFunc(d);
	TestFunc(dd);
	return 0;
}
