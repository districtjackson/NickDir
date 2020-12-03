// NickDir.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

bool fileExists(const std::string& filename)
{
    WIN32_FIND_DATAA fd = { 0 };
    HANDLE hFound = FindFirstFileA(filename.c_str(), &fd);
    bool retval = hFound != INVALID_HANDLE_VALUE;
    FindClose(hFound);

    return retval;
}

//Creates document to store aliases permanently
int permanent(wchar_t name[33], wchar_t command[132]) {
    
    wchar_t szBuf[MAX_PATH] = { 0 };

    GetEnvironmentVariable(L"HOMEPATH", szBuf, MAX_PATH);
    
    wcscat_s(szBuf, L"\\alias.cmd");

    wcout << szBuf;

    std::wstring ws(szBuf);

    std:string strBuf(ws.begin(), ws.end());

    bool exists = fileExists(strBuf);
    
    //Opens document
    std::wofstream outfile(szBuf, std::ios_base::app);

    //Performs first setup if document does not exist
    if (!exists) {  
        cout << "First setup";
        outfile << L"@echo off" << std::endl;
    }

    wchar_t prefix[162] = L"DOSKEY ";

    //Builds command string
    wcscat_s(prefix, name);

    wcscat_s(prefix, L"=");

    wcscat_s(prefix, command);

    outfile << prefix << std::endl;

    outfile.close();

    return NULL;
}

int main()
{
    wchar_t name[33];
    wchar_t tempLocation[129];

    cout << "Welcome to NickDir! This a tool for easily creating shortcuts to navigate between Windows directories.\n\n";

    cout << "Enter the name for the shortcut (max 32 characters): ";
    wcin >> name;
    cout << "Enter the full path for the shortcut (max 128 characters): ";
    wcin >> tempLocation;

    wchar_t location[132] = L"cd ";
    
    wcscat_s(location, tempLocation);
    
    permanent(name, location);
    
    LPWSTR wideName = name; //Convert directly from a wchar_t to a LPWSTR (which I now know stands for Long Pointer to Wide String)
    
    LPWSTR wideLocation = location;

    wchar_t executable[8] = L"cmd.exe";

    LPWSTR wideExecutable = executable;

    AddConsoleAlias(wideName, wideLocation, wideExecutable);

    cout << "\nShortcut successfully added. Type the name you entered and you will now automatically navigate to that directory.\n";

    
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
