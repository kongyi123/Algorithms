#include <iostream> 
#include <cstring> 

using namespace std;

class String
{
private:
	char *str;
	int len;

public:
	String();
	String(const char* pStr);
	String(const String& ref);
	~String();

	String& operator=(const String& ref);
	String operator+(const String& ref);
	String& operator+=(String& ref);
	bool operator==(const String& ref);

	friend ostream& operator<<(ostream& os, const String& ref);
	friend istream& operator>>(istream& is, String& ref);
};

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char* pStr)
{
	len = strlen(pStr) + 1;
	str = new char[len];
	strcpy(str, pStr);
}

String::String(const String& ref)
{
	len = ref.len;
	str = new char[len];
	strcpy(str, ref.str);
}

String::~String()
{
	if (str != NULL)
		delete[]str;
}

String& String::operator=(const String& ref)
{
	if (str != NULL)
		delete[]str;

	len = ref.len;
	str = new char[len];
	strcpy(str, ref.str);

	return *this;
}

// 참고할 기법이 있는 부분
// String 타입으로 리턴을 하고 char 포인터 타입을 String타입으로 변경해주기 위해
// 새로운 String 객체를 만들어줘서 그것을 리턴해줌.
String String::operator+(const String& ref)
{
	char *tStr = new char[len + ref.len - 1];

	strcpy(tStr, str);
	strcat(tStr, ref.str);
	String temp(tStr);
	delete[]tStr;
	return temp;

	/* '+','='가 오버로딩 된 상태에서 */
	// *this = *this + ref; 
	// return *this; 
	// 위 코드도 가능하지 않을까? 
}

String& String::operator+=(String& ref)
{
	char *tStr = new char[len + ref.len - 1];
	strcpy(tStr, str);
	strcat(tStr, ref.str);

	if (str != NULL)
		delete[]str;

	str = tStr;
	return *this;
}

bool String::operator==(const String& ref)
{
	return (strcmp(str, ref.str)) ? false : true;
}

/* 전역 함수 오버로딩 */
ostream& operator<<(ostream& os, const String& ref)
{
	os << ref.str;
	return os;
}

istream& operator>>(istream& is, String& ref)
{
	char temp[256];
	is >> temp;
	ref = String(temp);
	return is;
}
