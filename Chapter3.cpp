// Chapter3. Ŭ����
// ��ü���� ���α׷��� - �ݵ�� �ټ��� (�������� Ŭ������ ������ ����ϴ�) '�����'�� �������.

#include "stdafx.h"
#include <iostream>
using namespace std;

// ������ �ڵ�
class CTest {
public :
	// ������ - ���� ���ϸ� �ڵ�����
	CTest() {
		m_nData = 10; // 1. �����ڿ��� ��� ������ �ʱ�ȭ
	}
	// ��� ������ ����
	int m_nData;
	// ��� �Լ� ����
	void PrintData(void);
};

// Ŭ������ �Լ� ���Ǵ� �ܺο� ������ �����Ѵ�. why?
void CTest::PrintData(void) {
	cout << m_nData << endl;
}

class CTest2 {
public:
	// ������
	CTest2() : m_nData1(20), m_nData2(30) // 2. ������ �ʱ�ȭ ����� �̿��� ��� ������ �ʱ�ȭ
	{}
	// ��� ������ ����
	int m_nData1;
	int m_nData2;
};

class CTest3 {
public:
	// ������
	CTest3() {}
	// c++11���� ����� ���ÿ� ��� ���� �ʱ�ȭ ��������
	int m_nData1 = 40;
	int m_nData2 = 50;
};

// ����������
// public �ܺ� ���� ���
// protected �ܺ� ���� ����. ��Ӱ����� �Ļ�Ŭ���������� ���� ����
// private default��. �ܺ� & �Ļ� Ŭ�������� ��� ����.
class CTest4 {
	// �⺻ ���� �����ڴ� private 
	int m_nData;
public:
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

// �����ڿ� �Ҹ���
class CTest5 {
public:
	CTest5(){
		// ������
		cout << "CTest5 ������ ȣ��" << endl;
	}
	~CTest5() {
		// �Ҹ���(���⼭�� _tmain() �Լ� ���� ������ => CTest5 ��ü�� �Ҹ�ɶ� ȣ��ȴ�.)
		cout << "CTest5 �Ҹ��� ȣ��" << endl;
	}
};

// ���� ������ ������ Ŭ������ �����ڴ� main() �Լ����� ���� ȣ���!
class CTest6 {
public:
	CTest6() {
		// ������
		cout << "CTest6 ������ ȣ��" << endl;
	}
	~CTest6() {
		// �Ҹ���
		cout << "CTest6 �Ҹ��� ȣ��" << endl;
	}
};
CTest6 t6; // ���������� ����

// ������ �����ε�. �� ��� ����Ʈ ������ �ڵ� ���� �ȵ�.
class CTest7 {
	int m_nData;
public:
	CTest7() {
		// �⺻ ������ - �迭 ���� ������ ���� ���������ϴ�.
		cout << "CTest7 �⺻ ������ ȣ��" << endl;
	}
	CTest7(int nParam) {
		// ������
		cout << "CTest7 ������ ȣ��" << endl;
		m_nData = nParam;
	}
	~CTest7() {
		// �Ҹ���
		cout << "CTest7 �Ҹ��� ȣ��" << endl;
	}
};



// ����� �ڵ�
int _tmain(int argc, _TCHAR* argv[]) {
	cout << "_tmain start" << endl;
	CTest t;
	t.PrintData();

	CTest2 t2;
	cout << t2.m_nData1 << endl;
	cout << t2.m_nData2 << endl;

	CTest3 t3;
	cout << t3.m_nData1 << endl;
	cout << t3.m_nData2 << endl;

	CTest4 t4;
	t4.SetData(60);
	cout << t4.GetData() << endl;

	cout << "CTest5 ���� start" << endl;
	CTest5 t5;
	cout << "CTest5 ���� end" << endl;

	//CTest7 t7; // ����Ʈ �����ڰ� ��� ������ ���� �߻�
	CTest7 t7(3);

	
	// ���� ��ü�� ������ �Ҹ�
	// new�� delete�� ��ü�� ���� �� �Ҹ��ϴ� ������ �ڵ忡�� ��Ȯ�� �� �� �ִ�.
	// �����Ҵ� ���� �ʴ� ��� ���ÿ����� �ö󰡰� �ȴ�
	// �����Ҵ� ���� ��� �������� �ö󰡴� ���̰� ����. c#�̳� java�� ������ �÷��Ͱ� �˾Ƽ� ������ ��������, ���⼭�� �׷��� ����.
	cout << "CTest7 ���� ��ü ����" << endl;
	CTest7 *pData = new CTest7(10); 

	cout << "CTest7 ���� ��ü �Ҹ�" << endl;
	delete pData;

	// �迭�� ������ ��ü�� �ݵ�� �迭�� �����Ѵ�. �ȱ׷��� ù��° ����ϳ��� �Ҹ��ϰ� �������� �޸𸮿� ���´�.
	cout << "CTest7 ���� ��ü �迭 ����" << endl;
	//CTest7 *pDataArr = new CTest7(10)[3]; �迭�� �����Ҷ��� �Ű������� �ִ� �����ڸ� ȣ���� �� ����.. ������ ���� �߻�.. why;;;
	CTest7 *pDataArr = new CTest7[3];

	cout << "CTest7 ���� ��ü �迭 �Ҹ�" << endl;
	delete [] pDataArr;



	cout << "_tmain end" << endl;
	return 0;
}

