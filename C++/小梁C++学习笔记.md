
# C++学习笔记  

- [C++学习笔记](#c学习笔记)
  - [1 函数进阶知识](#1-函数进阶知识)
    - [1.1 函数默认参数](#11-函数默认参数)
    - [1.2 函数占位参数](#12-函数占位参数)
    - [1.3 函数的重载](#13-函数的重载)
      - [1.3.1 函数重载概述](#131-函数重载概述)
      - [1.3.2 函数重载注意事项](#132-函数重载注意事项)
  - [2 类和对象](#2-类和对象)
    - [2.1 封装](#21-封装)
      - [2.1.1 封装的意义](#211-封装的意义)
      - [2.1.2 C++中struct和class的区别](#212-c中struct和class的区别)
      - [2.1.3 成员属性设置为私有](#213-成员属性设置为私有)
    - [2.2 对象的初始化和清理](#22-对象的初始化和清理)
      - [2.2.1 构造函数和析构函数](#221-构造函数和析构函数)
      - [2.2.2 函数的分类以及调用](#222-函数的分类以及调用)
      - [4.2.3 构造函数的调用规则](#423-构造函数的调用规则)
      - [2.2.3 深拷贝和浅拷贝](#223-深拷贝和浅拷贝)
      - [2.2.4 初始化列表](#224-初始化列表)
      - [2.2.5 类对象作为类成员](#225-类对象作为类成员)
      - [2.2.6 静态成员](#226-静态成员)
    - [2.3 C++对象模型和this指针](#23-c对象模型和this指针)
      - [2.3.1 成员变量和成员函数分开储存](#231-成员变量和成员函数分开储存)

## 1 函数进阶知识

### 1.1 函数默认参数

在C++中函数是可以有默认参数的（**C语言不可以**）  
  
**代码示例如下：**

```C++
#include <iostream>
using namespace std;


int Func(int a, int b = 10, int c = 20)
{
    return a+b+c
}
```  

在上述代码中Func函数有三个形参分别为a，b，c，其中b和c有默认初始值，为默认参数  
注意：如果函数声明时设置了默认参数，那么在函数实现时不能有默认参数  
即：默认参数只能定义一次  

**示例代码如下：**  

```C++
#include <iostream>
using namespace std;

//如果我们在调用函数时传入了数据，那么函数执行的时候就使用我们自己的数据
//如果没有传入数据，则使用设置好的默认缺省值
//语法：返回值类型 函数名(形参 = 默认值){}
int Func(int a, int b, int c);
int Func(int a, int b = 20, int c = 10)
{
    return a+b+c;
}

//注意：如果函数的某个形参已经有默认值了，那么从这个参数往后的形参都得有默认值
```

### 1.2 函数占位参数

C++中函数的形参列表里可以有占位参数，用来作占位，调用函数时必须填补该位置  
  
**语法：** `返回值类型 函数名 (数据类型){}`  
  
**示例代码如下：**  

```C++
#include <iostream>
using namespace std;

//函数占位参数
void func(int a, int)
{
    cout << "占位" << endl;
}
//占位参数也可以有默认值
void func2(int a, int 10)
{
    cout <<"占位参数可以有默认值"<<endl;
}

int main()
{
    func(10,10);   //占位参数必须填补
    fun2c(10);     //占位参数有默认值
    system("pause");
}
```

### 1.3 函数的重载

#### 1.3.1 函数重载概述
  
**作用：** 函数名可以相同，提高复用性  
  
**函数重载满足条件：**  

- 同一作用域下  
- 函数名称相同  
- 函数参数**类型**不同 或者**个数**不同 或者**顺序**不同
  
**注意：** 函数的返回值不能作为函数重载的条件  
  
**示例代码：**  

```C++
#include <iostream>
using namespace std;

//函数重载需要函数在同一作用域下
void fun()
{

}
void fun(int a)
{

}
void fun(double b)
{

}

int main()
{
    fun();
    fun(10);
    fun(3.14);

    return 0;
}

```  

#### 1.3.2 函数重载注意事项  

- 引用作为重载条件
- 函数重载遇到函数默认参数

**示例代码：**  

```C++  
//函数重载注意事项
//1、引用作为重载条件
void fun(int &a)
{

}

void fun(const int &a)
{

}
//函数重载遇到默认参数
void fun2(int a)
{

}
void fun2(int a, int b = 10)
{

}
int main()
{
    fun(a);
    fun(10);

    fun2(10);  //此时会出现二义性

    return 0;
}
```  
  
## 2 类和对象  

C++面向对象的三大特性：**封装、继承、多态**  

<span style="color: yellow;" >C++认为万事万物皆为对象，对象有其属性和行为</span>

<br>  
<br>
<br>

**例如：**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;人可以作为对象,属性有姓名、年龄、身高······，行为有走、跑、跳、吃饭······  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;车也可以作为对象，属性有轮胎、方向盘、车灯······，行为有载人、放音乐······  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;具有相同性质的<span style="color: yellow" >对象</span>，我们可以抽象为<span style="color: yellow" >类</span>，人属于人类，车属于车类  
  
### 2.1 封装  

#### 2.1.1 封装的意义  

封装是C++面向对象三大特性之一  
  
<br>  
  
封装的意义  

- 将属性和行为作为一个整体，表现生活中的事物  
- 将属性和行为加以权限控制
  
<br>  
<br>  

**封装意义一：**  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在设计类的时候，属性和行为写在一起表现事物  

**语法：**`class 类名 {  访问权限：  属性/行为};`  

<br>

**示例代码：**  

```C++
//设计一个圆类来求圆的周长
const double PI = 3.14;

class Circle
{
    //访问权限
    //公共
public:
    //属性
    //半径
    int m_R
    //行为
    //获取一个圆的周长
    double CalPerimeter()
    {
        return 2 * PI * m_R;
    }

};

//类的使用需要先实例化,即创建对象,通过  .  访问类内部的属性和行为
int main
{
    Circle cl;
    cl.m_R = 10;

    cout<< "圆的周长为： "<< cl.CalPerimeter() <<endl;

    return 0;
}
```  

**示例代码：**  

```C++  
#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    std::string studentNumber;

public:
    void setStudentNumber(const std::string& number) {
        studentNumber = number;
    }

    void setName(const std::string& studentName) {
        name = studentName;
    }

    void displayStudentInfo() {
        std::cout << "Student Number: " << studentNumber << std::endl;
        std::cout << "Name: " << name << std::endl;
    }
};

int main() {
    Student student;
    student.setStudentNumber("20210001");
    student.setName("John Doe");
    student.displayStudentInfo();
    return 0;
}
```  

**封装意义二：**  
类在设计时可以把属性和行为放在不同的权限下，加以控制  

访问权限有三种：  

<br>  
<br>  

1. public 公共权限  
2. private 私有权限
3. protect 保护权限

**公共权限：** 类内类外都能访问  
**私有权限：** 只有类内才能访问，而且能够被继承的子类所访问  
**保护权限：** 只有类内才能访问，而且不能被继承的子类所访问  

#### 2.1.2 C++中struct和class的区别

在C++中struct和class**唯一**的区别就在于**默认的访问权限不同**  

区别：

- struct默认权限为公共  
- class 默认权限为私有  

示例代码：

```C++
class C1
{
    int a;  //默认权限为私有权限
}
struct C2
{
    int a;  //默认权限为公共权限
}
```  

#### 2.1.3 成员属性设置为私有  

**优点一：** 将所有成员属性设置为私有，可以自己控制读写权限  
**优点二：** 对于写权限我们可以检测数据的有效性  

**示例代码：**

```C++
class Person
{
public:
    //姓名设置可读可写
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }
//只要通过类提供的公共接口才能访问
private:

    string m_Name;
}
```

### 2.2 对象的初始化和清理  

- 生活中我们买的电子产品基本都会有出厂设置，在某一天我们不用的时候也会删除自己的一些信息数据来保证安全
- C++中的面向对象来源于生活，每个对象也会有初始设置以及对象销毁前清理数据的设置
  
#### 2.2.1 构造函数和析构函数

对象的**初始化**和**清理**也是两个非常重要的安全问题  

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;一个对象或者变量没有初始状态，对其使用后果是未知  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;同样使用完一个对象或变量，没有及时清理也会造成一定的安全问题  
  
<br>
<br>
<br>

C++利用了**构造函数**和**析构函数**解决上述问题，这两个函数会被编译器自动调用，完成对象的初始化和清理工作。
对象的初始化和清理工作是编译器强制要我们做的事情，因此如果我们**不提供构造和析构，编译器会提供**
**编译器提供的构造函数和析构函数是空实现。**  

<br>

- 构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用
- 析构函数：主要作用在于**对象销毁前**系统自动调用，执行一些清理工作

<br>

**构造函数语法：** 类名(){}  

1. 构造函数，没有返回值也不写void
2. 函数名称与类名相同
3. 构造函数可以有参数，因此可以发生重载
4. 程序在调用对象时会自动调用构造，无需手动调用，而且只会调用一次

<br>

**析构函数语法：** ~类名(){}

1. 析构函数，没有返回值也不写void
2. 函数名称与类名相同，在名称前面加上符号 ~
3. 析构函数不可以有参数，因此不能发生重载
4. 程序在对象销毁前自动调用析构，无需手动调用，而且只会调用一次

#### 2.2.2 函数的分类以及调用

**示例代码：**

```C++
#include <iostream>
using namespace std;

//构造函数：主要作用在于创建对象时为对象的成员属性赋值，由编译器自动调用
//析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作

class Person {

public:
 //1、构造函数
//没有返回值  也不用写void
//函数名与类名相同，可以有参数，可以发生重载
//创建对象的时候，构造函数会自动调用，而且值调用一次
//分类
//按照参数分   有参构造函数  无参构造函数
//按照类型分   普通构造函数  拷贝构造函数
    Person()
    {
        cout << "Person 无参构造函数的调用 " << endl;
    }
    Person(int age)
    {
        m_age = age;
        cout << "Person 有参构造函数的调用 " << endl;
    }
    //~~拷贝构造函数~~
    Person(const Person &p)
    {
        m_age = p.m_age;
        cout << "Person 拷贝构造函数的调用 " << endl;
    }
//1、析构函数
//没有返回值  也不用写void
//函数名与类名相同，在名称前面加上~
//程序在对象销毁时会自动调用析构函数，而且值调用一次
    ~Person()
    {
        cout << "Person 析构函数的调用 " << endl;
    }
    //构造函数和析构函数都是必须要有的实现，如果程序员未提供，编译器会提供一个空实的构造和析构
    int m_age;

void test01()
{


    //1、括号法调用构造析构   注意事项：调用默认构造不要加()
    //Person p();    编译器会认为这是一个函数的声明
    Person p;//默认构造函数的调用
    Person p1(10);//有参构造函数的调用
    Person p2(p1);//拷贝构造函数的调用
    //2、显示法
    //Person p;
    //Person p1 = Person(10);//有参构造
    //Person p2 = Person(p1);//拷贝构造
    //Person(10);//匿名对象  特点：当前代码执行完毕，系统会立即回收匿名对象
    //注意事项  不要用拷贝构造函数初始化匿名对象    编译器会认为  Person(p1) ===    Person p1
    //Person(p1)
    //3、隐式法
    //Person p;
    //Person p1 = 10;//有参构造
    //Person p2 = p1;//拷贝构造
}
int main()
{
    test01();
    system("pause");
    return 0;
}
```

#### 4.2.3 构造函数的调用规则

**示例代码：**

```C++
#include <iostream>
using namespace std;

//拷贝构造函数调用时机

//1、使用一个已经创建的对象来初始化一个新对象
//2、值传递的方式给函数参数传值
//3、值的方式返回局部对象
class Person {

public:
        
    Person()
    {
        cout << "Person 无参构造函数的调用 " << endl;
    }
    Person(int age)
    {
        m_age = age;
        cout << "Person 有参构造函数的调用 " << endl;
    }
    Person(const Person& p)
    {
        m_age = p.m_age;
        cout << "Person 拷贝构造函数的调用 " << endl;
    }
    ~Person()
    {
        cout << "Person 析构函数的调用 " << endl;
    }

    int m_age;
}   

//1、使用一个已经创建的对象来初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);
}
//2、值传递的方式给函数参数传值
void dowork(Person p)
{

}
void test02()
{
    Person p1;
    dowork(p1);
    //值传递会创建一个临时拷贝副本
}
//3、值的方式返回局部对象
Person dowork2()
{
    Person p;

    return p;
}

void test03()
{
    Person p1 = dowork2();
}
int main()
{
    test01();
    system("pause");

    return 0;
}


//1、创建一个类，编译器会为我们提供一个默认构造函数、一个默认析构函数、一个拷贝构造函数
//2、如果我们自己提供了一个有参构造函数，那么编译器将不会提供一个默认构造函数
//3、如果我们自己提供了一个拷贝构造函数，编译器将不会提供默认构造函数和析构函数
```

#### 2.2.3 深拷贝和浅拷贝

浅拷贝：简单的赋值拷贝操作  
深拷贝：在堆区重新申请空间，进行拷贝操作

<br>

**示例代码：**

```C++
class Person
{
public:
    Person()
    {

    }

    Person(int age, int height)
    {
        m_age = age;
        m_height = new int(height);
    }
    Person(const Person &p)
    {
        m_age = p.m_age;
        //m_height = height; 默认拷贝即此操作  为浅拷贝
        m_height = new int(*p.m_height);
    }
    //当我们在堆区开辟了数据时，需要手动释放，此时需要程序员提供析构代码
    ~Person()
    {
        if(m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
    }

private:
    int m_age;
    int *m_height;

}

void test01()
{

    Person p(12,160);

    Person p2(p);

}
void main
{

    test01();
    //由于函数内对象时存放在栈区的，遵循先进后出规则
    //所以test01()执行时，p2会被先释放，即m_height指针会被释放，然后p释放时会出现重复释放的问题
    //因此需要深拷贝操作解决问题
}
```

**总结：** 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

#### 2.2.4 初始化列表

**示例列表：**  

```C++
class Person
{
public:
    //无参构造函数
    Person()
    {

    }
    //传统方式初始化
    Person(int a, int b, int c)
    {
        m_A = a;
        m_B = b;
        m_C = c;
    }

    //初始化列表
    Person(int a, int b, int c) :m_A = a, m_B = b, m_C = c
    {

    }

private:
    int m_A;
    int m_B;
    int m_C;
}
```  

#### 2.2.5 类对象作为类成员  

<br>

C++中类的成员可以是另一个类的对象，我们称该成员为对象成员  

<br>

示例代码：  

```C++
class A;
class B
{
    A a;
}
```
  
B类中有对象A作为成员  

<br>
<br>

那么当创建B对象时，A与B的构造和析构的顺序时？  
当有其他类对象作为本类成员时，构造时先构造类对象，再构造自身  
析构的顺序和构造相反

**示例代码：**

```C++

```

#### 2.2.6 静态成员

静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员

静态成员分为：  

- 静态成员变量
  - 所有对象共享同一份数据
  - 在编译阶段分配内存
  - 类内声明，类外初始化
- 静态成员函数
  - 所有对象共享同一个函数
  - 静态成员函数只能访问静态成员变量

**示例一：** 静态成员变量

```C++
#include <iostream>
using namespace std;

//静态成员变量
class Person
{
public:
    //1、所有对象共享同一份数据
    //2、编译阶段就分配内存
    //3、类内声明，类外初始化
    static int m_A;
private:
    //静态成员变量也是有访问权限的
    static int m_B;
};

int Person::m_A = 200;

void test01()
{
    Person p1;

    cout << p1.m_A << endl;

    Person p2;

    p2.m_A = 100;

    cout << p2.m_A << endl;

}

void test02()
{
    //静态成员变量有两种访问方式

    //1、通过类名访问
    cout << Person::m_A << endl;
    //2、通过对象访问
    Person p;

    cout << p.m_A << endl;

}

int main()
{
        
    test01();
    system("pause");

    return 0;
}
```

<br>

### 2.3 C++对象模型和this指针

#### 2.3.1 成员变量和成员函数分开储存

