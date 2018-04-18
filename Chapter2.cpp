#include "stdafx.h"
#include <iostream>

using namespace std;
//using namespace TEST;

// �Ű����� default ���� ������ �� �ִ�.
int TestFunc(int nParam = 10) {
	cout << "TestFunc in GLOBAL" << endl;
	return nParam;
}

// �Լ� ���ø� ���
template <typename T>
T TemplateFunc(T a) {
	cout << "�Ű����� a : " << a << endl;
	return a;
}

// ���ӽ����̽�
// ���� �۾��� ������ �Լ� �̸��� ��ġ�� �ʰ� ���ӽ����̽��� Ȱ������
namespace TEST
{
	int g_nData = 2000;
	void TestFunc(int nParam = 20) {
		cout << "TestFunc in TEST namepace" << endl;
	}

	namespace INNER
	{
		int g_nData = 4000;
	}
}

int _tmain(int argc, _TCHAR* argv[]) {
	cout << TestFunc() << endl; // 10
	
	// 1. default �Ű����� ����Ʈ ���� �ݵ�� ������ �Ű��������� ���
	// 2. �Ű����� �������϶� ����Ʈ�� ������ '���' �Ű������� �� ����Ѵ�.
	// 3. �Ű������� ���μ��� ����ϸ� ���ʺ��� ����ǰ�, ¦ ������ ����Ʈ �� ����.
	// ������������� �翬�� ����. �Ѿ��.

	// �Լ� ���� ����
	// �޼��� �����ε�
	// ���� �Լ� �̸�, �ٸ� �Ű����� ���� or ���� ���� ���� ���ǰ� ������.
	// Add(int a, int b); Add(double a, double b); ȣ��� �����Ϸ��� �ڷ��� ���� �˾Ƽ� ȣ���Ѵ�.
	
	// �Ұ����� ���� �Ʒ� �ΰ�
	// 1. ��ȯ ���ĸ� �ٸ� ��� int Add(int a, int b); double Add(int a, int b);
	// 2. ȣ�� ��Ģ�� �ٸ� ��� int __cdecl Add(int a, int b); int __stdcall Add(int a, int b);

	// �Լ� ���� ������ ���� - �ڵ� �ߺ�, ���ʿ��� �ڵ� ����
	// �׷��Ƿ�
	// �Լ� ���ø��� �������
	cout << "int\t" << TemplateFunc(3) << endl;
	cout << "double\t" << TemplateFunc(3.5) << endl;
	cout << "char\t" << TemplateFunc('A') << endl;
	cout << "char*\t" << TemplateFunc("TestString") << endl; // ����� �����ڰ� �ȵȴٴ��� �̰� �� �ǳ�... ������ ������?

																 
	// �ζ��� �Լ�
	// C�� ������ ����̴�.
	// __inline �� �ƴ� inline int AddNew(...) �̷������� �Լ� ��ȯ ���� �տ� inline�� �߰����ָ� �ȴ�.

	// ���ӽ����̽�
	TestFunc(); //TEST�� using �����ϸ�, �۷ι� TestFunc �Լ��� ȣ���ϴ°��� TEST�Լ��� TestFunc�Լ��� ȣ���ϴ°��� ��ȣ�ϱ� ������ ������ ������ �߻�
	::TestFunc(); // ����� ����
	TEST::TestFunc();
	cout << "TEST �ȿ� �ִ� g_nData����? " << TEST::g_nData << endl; //2000

	// using ���� - ���� ����ϴ� ���ӽ����̽��� �ִٸ� using �������� �����ϴ°� ���ϴ�.
	// using namespace TEST;
	// �����ϸ�
	// �׳� TestFunc(); �� TEST ���ӽ����̽� ���� TestFunc �Լ��� ȣ���� �� �ִ�.

	// ��ø ���ӽ����̽��� �����ϴ�
	cout << "TEST �ȿ� INNER �ȿ� �ִ� g_nData����? " << TEST::INNER::g_nData << endl; //4000

	
	// �ĺ��� �˻� ����
	// ���� �Լ��� ���
	// 1 ���� ��� ����
	// 2 ���� ��� ������ �����ϰ� �ִ� ���� ��� ����
	// 3 ���� �ֱٿ� ����� ���� ������ �Լ�
	// 4 using ����� ���ӽ����̽� Ȥ�� ���� ���ӽ����̽�. ������ �ĺ��ڰ� �����ϸ� ������ ����

	// Ŭ���� �޼����� ���
	// 1 ���� ��� ����
	// 2 ���� ��� ������ �����ϰ� �ִ� ���� ��� ����
	// 3 Ŭ���� ���
	// 4 �θ� Ŭ���� ���
	// 5 ���� �ֱٿ� ����� ���� ������ �Լ�

	// �̰� �� �����ϸ鼭 �ڿ������� ������.
}