
#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int main(int argc, char* argv[])
{
	BYTE* Martredes = NULL;
	BYTE* Sulfoneringernes = NULL;
	HMODULE hntdll = NULL;
	FARPROC ntprotect = NULL;
	long int fsize = 0;

	if (argc == 1)
	{
		printf("No argument supplied. Exiting");
		return 0;
	}

	char* file_name = argv[1];
	int i = 0;

	FILE* fp = fopen(file_name, "rb");
	if (fp == NULL) {
		printf("File Not Found!\n");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	fsize = ftell(fp);

	Sulfoneringernes = (BYTE*)VirtualAlloc(NULL, fsize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	//Martredes = VirtualAlloc(NULL, 73605120, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	//Sulfoneringernes = (BYTE*)malloc(651);
	//Martredes = (BYTE*)malloc(73605120);

	if (Sulfoneringernes == NULL) // || Martredes == NULL) 
	{
		printf("Memory not allocated.\n");
		fclose(fp);
		exit(0);
	}

	for (i = 0; i < fsize; ++i) {
		Sulfoneringernes[i] = (BYTE)NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fread(Sulfoneringernes, 1, fsize, fp);
	fclose(fp);
	((void(*)())Sulfoneringernes)();
	/*
	hntdll = GetModuleHandleA("ntdll.dll");
	if (hntdll == NULL)
	{
		hntdll = LoadLibraryA("ntdll.dll");
	}

	ntprotect = GetProcAddress(hntdll, "NtProtectVirtualMemory");
	CallWindowProcA((WNDPROC)Sulfoneringernes, (HWND)Martredes, (UINT)ntprotect, (WPARAM)0x0, (LPARAM)0x0);
	if (Sulfoneringernes)
		free(Sulfoneringernes);
	if (Martredes)
		free(Martredes);
	*/
	return 0;
}