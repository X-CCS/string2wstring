#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
#include<memory.h>
#include<fstream>
#include<cstdlib>
#include<map>
#include<iterator>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

std::string ws2s(const std::wstring& ws)
{
    std::string curLocale = setlocale(LC_ALL, NULL);        // curLocale = "C";
    setlocale(LC_ALL, "chs");
    const wchar_t* _Source = ws.c_str();
    size_t _Dsize = 2 * ws.size() + 1;
    char *_Dest = new char[_Dsize];
    memset(_Dest,0,_Dsize);
    wcstombs(_Dest,_Source,_Dsize);
    std::string result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, curLocale.c_str());
    return result;
}

std::wstring s2ws(const std::string& s)
{
    setlocale(LC_ALL, "chs"); 
    const char* _Source = s.c_str();
    size_t _Dsize = s.size() + 1;
    wchar_t *_Dest = new wchar_t[_Dsize];
    wmemset(_Dest, 0, _Dsize);
    mbstowcs(_Dest,_Source,_Dsize);
    std::wstring result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, "C");
    return result;
}
int main(){
	//test
    wstring str = L"1234567->语言分析891011"; 
    std::wcout.imbue(std::locale("chs"));//lang
    wcout << str << endl;
	wstring a(L"语言统计分析");
	string b = "语言统计分析";
	wstring b1 = s2ws(b);
	string b3 = ws2s(b1);
	cout << b3 << endl;
	return 0;
}