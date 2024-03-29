// dllmain.cpp : Defines the entry point for the DLL application.
#include "mal_dll.h"

DWORD WINAPI BoxThread(LPVOID lpParam)
{
	showMessage();
	return 0;
}

extern "C" __declspec(dllexport)
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
		case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, BoxThread, NULL, NULL, NULL);
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// Exporting function usable with SetWindowsHookEx
extern "C" __declspec(dllexport) int NextHook(int code, WPARAM wParam, LPARAM lParam) {
	return CallNextHookEx(NULL, code, wParam, lParam);
}

/** 
TO RUN:
	\Windows\System32\regsvr32.exe mal_dll.dll
**/