// Chapter3. 클래스
// 객체지향 프로그래밍 - 반드시 다수의 (여러분의 클래스를 가져다 사용하는) '사용자'를 배려하자.

#include "stdafx.h"
#include <iostream>
using namespace std;

// 제작자 코드
class CTest {
public :
	// 생성자 - 정의 안하면 자동생성
	CTest() {
		m_nData = 10; // 1. 생성자에서 멤버 데이터 초기화
	}
	// 멤버 데이터 선언
	int m_nData;
	// 멤버 함수 선언
	void PrintData(void);
};

// 클래스의 함수 정의는 외부에 별도로 정의한다. why?
void CTest::PrintData(void) {
	cout << m_nData << endl;
}

class CTest2 {
public:
	// 생성자
	CTest2() : m_nData1(20), m_nData2(30) // 2. 생성자 초기화 목록을 이용해 멤버 데이터 초기화
	{}
	// 멤버 데이터 선언
	int m_nData1;
	int m_nData2;
};

class CTest3 {
public:
	// 생성자
	CTest3() {}
	// c++11부터 선언과 동시에 멤버 변수 초기화 가능해짐
	int m_nData1 = 40;
	int m_nData2 = 50;
};

// 접근지시자
// public 외부 접근 허용
// protected 외부 접근 차단. 상속관계의 파생클래스에서만 접근 가능
// private default값. 외부 & 파생 클래스까지 모두 차단.
class CTest4 {
	// 기본 접근 지시자는 private 
	int m_nData;
public:
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

// 생성자와 소멸자
class CTest5 {
public:
	CTest5(){
		// 생성자
		cout << "CTest5 생성자 호출" << endl;
	}
	~CTest5() {
		// 소멸자(여기서는 _tmain() 함수 실행 끝날때 => CTest5 객체가 소멸될때 호출된다.)
		cout << "CTest5 소멸자 호출" << endl;
	}
};

// 전역 변수로 선언한 클래스의 생성자는 main() 함수보다 먼저 호출됨!
class CTest6 {
public:
	CTest6() {
		// 생성자
		cout << "CTest6 생성자 호출" << endl;
	}
	~CTest6() {
		// 소멸자
		cout << "CTest6 소멸자 호출" << endl;
	}
};
CTest6 t6; // 전역변수로 선언

// 생성자 오버로딩. 이 경우 디폴트 생성자 자동 생성 안됨.
class CTest7 {
	int m_nData;
public:
	CTest7() {
		// 기본 생성자 - 배열 동적 생성을 위해 만들어줬습니다.
		cout << "CTest7 기본 생성자 호출" << endl;
	}
	CTest7(int nParam) {
		// 생성자
		cout << "CTest7 생성자 호출" << endl;
		m_nData = nParam;
	}
	~CTest7() {
		// 소멸자
		cout << "CTest7 소멸자 호출" << endl;
	}
};



// 사용자 코드
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

	cout << "CTest5 선언 start" << endl;
	CTest5 t5;
	cout << "CTest5 선언 end" << endl;

	//CTest7 t7; // 디폴트 생성자가 없어서 컴파일 오류 발생
	CTest7 t7(3);

	
	// 동적 객체의 생성과 소멸
	// new와 delete로 객체가 생성 및 소멸하는 시점을 코드에서 명확히 알 수 있다.
	// 동적할당 받지 않는 경우 스택영역에 올라가게 된다
	// 동적할당 받은 경우 힙영역에 올라가는 차이가 있음. c#이나 java는 가비지 컬렉터가 알아서 해제를 해주지만, 여기서는 그렇지 않음.
	cout << "CTest7 동적 객체 생성" << endl;
	CTest7 *pData = new CTest7(10); 

	cout << "CTest7 동적 객체 소멸" << endl;
	delete pData;

	// 배열로 생성한 객체는 반드시 배열로 삭제한다. 안그러면 첫번째 요소하나만 소멸하고 나머지는 메모리에 남는다.
	cout << "CTest7 동적 객체 배열 생성" << endl;
	//CTest7 *pDataArr = new CTest7(10)[3]; 배열로 생성할때는 매개변수가 있는 생성자를 호출할 수 없음.. 컴파일 오류 발생.. why;;;
	CTest7 *pDataArr = new CTest7[3];

	cout << "CTest7 동적 객체 배열 소멸" << endl;
	delete [] pDataArr;



	cout << "_tmain end" << endl;
	return 0;
}

