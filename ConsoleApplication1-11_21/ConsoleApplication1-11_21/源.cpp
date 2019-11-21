#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// 析构函数
// 常见的面试题：析构函数能不能是虚函数？ 如果可以，什么情况下建议最好将基类的析构函数设置成虚函数？
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
// C++98--编译器不能帮助用户进行重写的检测
// C++11----override: 让编译器帮助用户检测派生类是否对基类中的某个虚函数进行重写
//                     是：编译成功
//                     否：编译报错
// 注意：override只能修饰子类的虚函数
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	//void TestFunc2()  编译报错：基类中TestFunc2不是虚函数
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
	// 与基类的函数名字不同
	//virtual void TetsFunc1()override  // 报错：函数名不同，没有构成重写
	virtual void TestFunc1()override    // OK
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	// 基类TestFunc2不是虚函数
	virtual void TestFunc2()override
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	// 与基类虚函数的参数列表不同
	// virtual void TestFunc3(int)override  编译报错：与基类中TestFunc3虚函数参数列表不同
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


// final如果修饰虚函数：表明该虚函数不能被派生类重写
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
