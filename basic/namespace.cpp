//自定义命名空间
namespace A{
    int a = 10;
}
namespace B{
    int a = 20;
}
void test(){
    cout << "A::a : " << A::a << endl;
    cout << "B::a : " << B::a << endl;
}

//命名空间只能全局范围内定义
//命名空间可嵌套命名空间
namespace A{
    int a = 10;
    namespace B{
        int a = 20;
    }
}
void test(){
    cout << "A::a : " << A::a << endl;
    cout << "A::B::a : " << A::B::a << endl;
}

//命名空间是开放的，即可以随时把新的成员加入已有的命名空间中
namespace A{
    int a = 10;
}

namespace A{
    void func(){
        cout << "hello namespace!" << endl;
    }
}

void test(){
    cout << "A::a : " << A::a << endl;
    A::func();
}

//声明和实现可分离
#pragma once

namespace MySpace{
    void func1();
    void func2(int param);
}

void MySpace::func1(){
    cout << "MySpace::func1" << endl;
}
void MySpace::func2(int param){
    cout << "MySpace::func2 : " << param << endl;
}

/*
无名命名空间，意味着命名空间中的标识符只能在本文件内访问，相当于给这个标识符加上了static，使得其可以作为内部连接
*/
namespace{
    
    int a = 10;
    void func(){ cout << "hello namespace" << endl; }
}
void test(){
    cout << "a : " << a << endl;
    func();
}


//命名空间别名
namespace veryLongName{
    
    int a = 10;
    void func(){ cout << "hello namespace" << endl; }
}

void test(){
    namespace shortName = veryLongName;
    cout << "veryLongName::a : " << shortName::a << endl;
    veryLongName::func();
    shortName::func();
}


//using声明可使得指定的标识符可用
namespace A{
    int paramA = 20;
    int paramB = 30;
    void funcA(){ cout << "hello funcA" << endl; }
    void funcB(){ cout << "hello funcA" << endl; }
}

void test(){
    //1. 通过命名空间域运算符
    cout << A::paramA << endl;
    A::funcA();
    //2. using声明
    using A::paramA;
    using A::funcA;
    cout << paramA << endl;
    //cout << paramB << endl; //不可直接访问
    funcA();
    //3. 同名冲突
    //int paramA = 20; //相同作用域注意同名冲突
}

/*
using声明碰到函数重载
如果命名空间包含一组用相同名字重载的函数，using声明就声明了这个重载函数的所有集合
*/
namespace A{
    void func(){}
    void func(int x){}
    int  func(int x,int y){return x+y;}
}
void test(){
    using A::func;
    func();
    func(10);
    func(10, 20);
}

/*
using编译指令
using编译指令使整个命名空间标识符可用
注意：使用using声明或using编译指令会增加命名冲突的可能性。也就是说，如果有名称空间，并在代码中使用作用域解析运算符，则不会出现二义性。
*/
namespace A{
    int paramA = 20;
    int paramB = 30;
    void funcA(){ cout << "hello funcA" << endl; }
    void funcB(){ cout << "hello funcB" << endl; }
}

void test01(){
    using namespace A;
    cout << paramA << endl;
    cout << paramB << endl;
    funcA();
    funcB();

    //不会产生二义性
    int paramA = 30;
    cout << paramA << endl;
}

namespace B{
    int paramA = 20;
    int paramB = 30;
    void funcA(){ cout << "hello funcA" << endl; }
    void funcB(){ cout << "hello funcB" << endl; }
}

void test02(){
    using namespace A;
    using namespace B;
    //二义性产生，不知道调用A还是B的paramA
    //cout << paramA << endl;
}
