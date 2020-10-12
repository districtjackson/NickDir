// NickDir.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <stringapiset.h>

using namespace std;

LPWSTR convertString(string str) {

    wchar_t wtext[20];
    size_t strlength = str.length();
    size_t outSize;

    mbstowcs_s(&outSize, wtext, str.c_str(), strlength);
    LPWSTR finalstr = wtext;

    return finalstr;
}

int main()
{

    string name;
    string location;
    string executable = "cmd.exe";

    cout << "Enter the name for the alias: ";
    cin >> name;
    cout << "Enter the path for the alias: ";
    cin >> location;

    LPWSTR Lname = convertString(name);

    LPWSTR Llocation = convertString(location);

    LPWSTR Lexecutable = convertString(executable);

    AddConsoleAlias(TEXT(name), TEXT(location), TEXT(executable));
 
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
