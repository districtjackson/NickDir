// NickDir.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <stringapiset.h>

using namespace std;

//2 methods, replace all the backslashes with spaces, and then rereplace them after, or break the string apart, run it one at a time, and then stitch them all back together after.

int numberofWords(string str) {
    int wordcount = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) == '\\') {
            ++wordcount;
        }
    }

    return wordcount;
}

string replaceWackWack(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) == '\\') {
            str[i] = ' ';
        }
    }
}

LPWSTR replaceSpace(LPWSTR str, int length) {
    for (int i = 0; i < length; i++) {
        if(str.Find[])
    }
}

LPWSTR convertLongString(string str) {
    str = replaceWackWack(str);

    wchar_t wtext[20];
    size_t strlength = str.length();
    size_t outSize;
    size_t wordSize = strlength;

    mbstowcs_s(&outSize, wtext, str.c_str(), strlength);
    LPWSTR finalstr = wtext;

    return finalstr;
}

LPWSTR convertString(string str) {

    int wordcount = numberofWords(str);

    wchar_t wtext[20];
    size_t strlength = str.length();
    size_t outSize;
    size_t wordSize = strlength;

    mbstowcs_s(&outSize, wtext, str.c_str(), strlength);
    LPWSTR finalstr = wtext;

    return finalstr;
}

inline std::wstring convert(const std::string& as)
{
    wchar_t* buf = new wchar_t[as.size() * 2 + 2];
    swprintf(buf, L"%S", as.c_str());
    std::wstring rval = buf;
    delete[] buf;
    return rval;
}

int main()
{

    string name;
    string location;

    cout << "Enter the name for the alias: ";
    cin >> name;
    cout << "Enter the path for the alias: ";
    cin >> location;

    wchar_t testchar = 'r';

    LPCWSTR myStr = L"Hello World"; //Testing out cases for Long Pointer types to understand their logic.

    LPWSTR testpointer = testchar*;

    LPWSTR wideName = convert(name); //Trying to convert directly from a widestring to a LPWSTR (which I now know stands for Long Pointer to Wide String)

    wstring wideLocation = convert(location);

    wstring wideExecutable = L"cmd.exe";

    AddConsoleAlias(wideName*, wideLocation*, wideExecutable*);
 
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
