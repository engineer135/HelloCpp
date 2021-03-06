// HelloCpp.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

void Testfunc(int &nParam) {
	nParam = 3000;
}

int _tmain(int argc, _TCHAR* argv[]) {
	std::cout << "Hello, World!" << std::endl;

	// std::cout std::cin
	std::string strData = "TestString";
	std::cout << strData << std::endl;

	std::string strName;
	std::cout << "이름을 입력하세요~" << std::endl;
	std::cin >> strName;

	std::cout << "너의 이름은 " << strName << "이구나." << std::endl;

	// 자료형 auto
	// 초깃값 형식에 맞춰 선언하는 인스턴스의 형식이 '자동'으로 결정됨
	int a(10);
	int b(a);
	auto c(b);

	std::cout << a + b + c << std::endl;

	// new와 delete연산자
	// 객체를 동적할당하고 해제하는 '연산자'
	// malloc()과 달리 메모리 크기를 정하지 않는다. 그리고 생성자 함수를 호출한다.
	
	// 인스턴스만 동적으로 생성하는 경우
	int *pData = new int;

	// 초깃값 기술하는 경우
	int *pNewData = new int(10);

	*pData = 5;
	std::cout << *pData << std::endl;
	std::cout << *pNewData << std::endl;

	// 반드시 해제해줘야 함. 객체의 소멸자를 호출한다.
	delete pData;
	delete pNewData;


	// 배열 형태의 동적할당
	int *arr = new int[5];

	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 10;
	}
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << std::endl;
	}

	// 해제할때도 배열 형태로
	delete[] arr;


	// 참조자 형식(&)
	// 포인터와 비슷. 
	// 선언과 동시에 반드시 초기화해야함.
	// 상수에는 참조를 선언할 수 없다!
	//char &pnData = "Hi"; 불가능. 근데 이건 의아한게 C에서는 되는데 왜 교재에는 안된다고 써있을까? char *pStr = "Hi"; 이런거..
	//int *pnData = &3; 불가능.
	//int &pnData = 3; 불가능.
	//int &pnData; 불가능

	int nData = 10;
	int &ref = nData;
	ref = 20;
	std::cout << nData << std::endl;

	// 아래는 포인터. 거의 비슷함. 모양이 조금 다른거 빼고..
	int *pnData = &nData;
	*pnData = 50;
	std::cout << nData << std::endl;

	// 참조에 의한 호출. 덩치 큰 자료는 값이 아니라 주소를 전달하는 것이 효율적!
	Testfunc(nData); // 매개변수가 참조자인 경우 호출자 코드만 봐서는 매개변수가 참조 형식이라는 사실을 전혀 알 수 없음.
	// 매개변수가 참조자가 아닌 그냥 자료를 받는다면, 결과값을 return해서 nData에 다시 저장하지 않는 이상 nData 값이 변하지 않는다. 스택에 쌓였다가 함수 종료시 사라지니까.
	cout << "TestFunc 호출 후 nData=" << nData << endl;

	// r-value 참조
	// 이건 뭐지? 임시 결과를 저장하는 참조자..
	// 3+4+5 에서 3+4가 임시 결과. 이어지는 연산에 활용된 직후 소멸되는 r-value
	// 이게 언제 쓰이는건지는 나중에 배운다.
	int &&rData = 3+4;
	cout << "rValue 참조 nData=" << rData << endl;

	// 범위기반 for문
	// for(auto &n : aList) 이런식으로 사용할 수 있는 루프문.

	return 0;
}
