#include <iostream>
#include <stdlib.h>
#include <thread>
#include <windows.h>
#include <TlHelp32.h>
// #include <stdexcept>
// #include <stdio.h>
// #include <fstream>

using namespace std;

HANDLE GetProcessHandle(const char *process_name, DWORD dwAccess)
{
  HANDLE hProcessSnap;
  HANDLE hProcess;
  PROCESSENTRY32 pe32;
  hProcessSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);

  if(hProcessSnap==INVALID_HANDLE_VALUE)
  {
    cerr <<"Failed to create process snapshot!";
    return INVALID_HANDLE_VALUE;
  }

  pe32.dwSize=sizeof(PROCESSENTRY32);

  if(!Process32First(hProcessSnap,&pe32))
  {
      cerr <<"Process32First() failed\n";
      return INVALID_HANDLE_VALUE;
  }

  do
  {
      if(strcmp(pe32.szExeFile,process_name)==0)
        return OpenProcess(dwAccess,0,pe32.th32ProcessID);
  }
  while(Process32Next(hProcessSnap,&pe32));
}

void exec(const char* cmd) {
    char buffer[128];
    FILE* pipe = _popen(cmd, "r");
    if (!pipe) throw runtime_error("popen() failed!");
	// ofstream ofstream_;
	// ofstream_.open("out.txt");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
					// ofstream_<<buffer;
					cout<<buffer;
        }
    } catch (...) {
        _pclose(pipe);
        throw;
    }
    _pclose(pipe);
	// ofstream_.close();
}

void foo (){
	// system("start java -jar morfologik-tools-2.1.0.jar dict_apply -d polish.dict > out.txt");
	//@up ścieżka, przy założeniu, że morfologik jest w tym samym katalogu co plik odpalający
	exec("start java -jar morfologik-tools-2.1.0.jar dict_apply -d polish.dict > out.txt");
}

void foo2(){
	int i = 1;
	Sleep(500);
	while(i){
		HANDLE hProcess=GetProcessHandle("java.exe",PROCESS_QUERY_INFORMATION);
		if(hProcess==0 || hProcess==INVALID_HANDLE_VALUE)
			i = 0;
		else;
			cout <<"Java run\n";
	}
	cout<<"DONE";
}

int main(void){
	int a;
	system("chcp 1250");
	thread first(foo);
	thread second(foo2);
	first.join();
	second.join();
	cout<<"done2";
	cin>>a;
	return 0;
}