// NickDir.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    wchar_t name[32];
    wchar_t tempLocation[128];

    cout << "Enter the name for the alias: ";
    wcin >> name;
    cout << "Enter the path for the alias: ";
    wcin >> tempLocation;

    wchar_t location[131] = L"cd ";

    wcscat_s(location, tempLocation);

    LPWSTR wideName = name; //Trying to convert directly from a widestring to a LPWSTR (which I now know stands for Long Pointer to Wide String)

    LPWSTR wideLocation = location;

    wchar_t executable[8] = L"cmd.exe";

    LPWSTR wideExecutable = executable;

    AddConsoleAlias(wideName, wideLocation, wideExecutable);
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
