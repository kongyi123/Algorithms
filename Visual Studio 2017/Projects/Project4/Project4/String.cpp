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

// ������ ����� �ִ� �κ�
// String Ÿ������ ������ �ϰ� char ������ Ÿ���� StringŸ������ �������ֱ� ����
// ���ο� String ��ü�� ������༭ �װ��� ��������.
String String::operator+(const String& ref)
{
	char *tStr = new char[len + ref.len - 1];

	strcpy(tStr, str);
	strcat(tStr, ref.str);
	String temp(tStr);
	delete[]tStr;
	return temp;

	/* '+','='�� �����ε� �� ���¿��� */
	// *this = *this + ref; 
	// return *this; 
	// �� �ڵ嵵 �������� ������? 
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

/* ���� �Լ� �����ε� */
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
