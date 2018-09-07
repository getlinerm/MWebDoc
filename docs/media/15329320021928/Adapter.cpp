/*
������ģʽ
��һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�ʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�������һ������
*/
#include <iostream>
using namespace std;

class Target
{
public:
  virtual void Request(){ cout << "��ͨ������" << endl; }
};

class Adaptee
{
public:
  void SpecificalRequest(){ cout << "���������" << endl; }
};

class Adapter :public  Target
{
private:
  Adaptee* ada;    //�������ö�̳У��˴�ʹ�ü̳м���ϵķ�ʽʵ��
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