#include "stdafx.h"
#include <iostream>

using namespace std;
//using namespace TEST;

// 매개변수 default 값을 정해줄 수 있다.
int TestFunc(int nParam = 10) {
	cout << "TestFunc in GLOBAL" << endl;
	return nParam;
}

// 함수 템플릿 사용
template <typename T>
T TemplateFunc(T a) {
	cout << "매개변수 a : " << a << endl;
	return a;
}

// 네임스페이스
// 공동 작업시 변수나 함수 이름이 겹치지 않게 네임스페이스를 활용하자
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
	
	// 1. default 매개변수 디폴트 값은 반드시 오른쪽 매개변수부터 기술
	// 2. 매개변수 여러개일때 디폴트값 쓰려면 '모든' 매개변수에 다 써야한다.
	// 3. 매개변수에 실인수를 기술하면 왼쪽부터 적용되고, 짝 없으면 디폴트 값 적용.
	// 어려워보이지만 당연한 얘기다. 넘어가자.

	// 함수 다중 정의
	// 메서드 오버로딩
	// 같은 함수 이름, 다른 매개변수 개수 or 형식 으로 다중 정의가 가능함.
	// Add(int a, int b); Add(double a, double b); 호출시 컴파일러가 자료형 보고 알아서 호출한다.
	
	// 불가능한 경우는 아래 두개
	// 1. 반환 형식만 다른 경우 int Add(int a, int b); double Add(int a, int b);
	// 2. 호출 규칙만 다른 경우 int __cdecl Add(int a, int b); int __stdcall Add(int a, int b);

	// 함수 다중 정의의 문제 - 코드 중복, 불필요한 코드 생김
	// 그러므로
	// 함수 템플릿을 사용하자
	cout << "int\t" << TemplateFunc(3) << endl;
	cout << "double\t" << TemplateFunc(3.5) << endl;
	cout << "char\t" << TemplateFunc('A') << endl;
	cout << "char*\t" << TemplateFunc("TestString") << endl; // 상수는 참조자가 안된다더니 이건 또 되네... 포인터 변수라서?

																 
	// 인라인 함수
	// C와 동일한 기능이다.
	// __inline 이 아닌 inline int AddNew(...) 이런식으로 함수 반환 형식 앞에 inline을 추가해주면 된다.

	// 네임스페이스
	TestFunc(); //TEST에 using 선언하면, 글로벌 TestFunc 함수를 호출하는건지 TEST함수의 TestFunc함수를 호출하는건지 모호하기 때문에 컴파일 오류가 발생
	::TestFunc(); // 명시적 전역
	TEST::TestFunc();
	cout << "TEST 안에 있는 g_nData값은? " << TEST::g_nData << endl; //2000

	// using 선언 - 자주 사용하는 네임스페이스가 있다면 using 선언으로 생략하는게 편하다.
	// using namespace TEST;
	// 선언하면
	// 그냥 TestFunc(); 로 TEST 네임스페이스 안의 TestFunc 함수를 호출할 수 있다.

	// 중첩 네임스페이스도 가능하다
	cout << "TEST 안에 INNER 안에 있는 g_nData값은? " << TEST::INNER::g_nData << endl; //4000

	
	// 식별자 검색 순서
	// 전역 함수인 경우
	// 1 현재 블록 범위
	// 2 현재 블록 범위를 포함하고 있는 상위 블록 범위
	// 3 가장 최근에 선언된 전역 변수나 함수
	// 4 using 선언된 네임스페이스 혹은 전역 네임스페이스. 동일한 식별자가 존재하면 컴파일 오류

	// 클래스 메서드인 경우
	// 1 현재 블록 범위
	// 2 현재 블록 범위를 포함하고 있는 상위 블록 범위
	// 3 클래스 멤버
	// 4 부모 클래스 멤버
	// 5 가장 최근에 선언된 전역 변수나 함수

	// 이건 뭐 개발하면서 자연스럽게 익히자.
}