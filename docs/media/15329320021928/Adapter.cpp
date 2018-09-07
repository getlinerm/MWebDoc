/*
适配器模式
将一个类的接口转换成客户希望的另外一个接口。使得原本由于接口不兼容而不能一起工作的那些类可以在一起工作。
*/
#include <iostream>
using namespace std;

class Target
{
public:
  virtual void Request(){ cout << "普通的请求" << endl; }
};

class Adaptee
{
public:
  void SpecificalRequest(){ cout << "特殊的请求" << endl; }
};

class Adapter :public  Target
{
private:
  Adaptee* ada;    //尽量少用多继承，此处使用继承加组合的方式实现
public:
  virtual void Request()
  {
	ada->SpecificalRequest();
	Target::Request();
  }
  Adapter(){ ada = new Adaptee(); }
  ~Adapter(){ delete ada; }
};

int main()
{
  Target * tg = new Adapter();
  tg->Request();
  system("pause");
  return 0;
}