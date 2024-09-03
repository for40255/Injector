#include "inject.h"

#include <iostream>
#include "util.h"

int Inject(HANDLE hProcess, const std::string& dllPath, InjectionType type)
{
	int success = 1;
	switch (type)
	{
	case InjectionType::LoadLibraryDLL:
		if (!LoadLibraryDLL(hProcess, dllPath)) {
			std::cerr << "Failed to inject DLL using LoadLibrary." << std::endl;
			success = 0;
		}
		break;
	case InjectionType::ManualMap:
		if (!ManualMapDLL(hProcess, dllPath)) {
			success = 0;
			std::cerr << "Failed to inject DLL using ManualMap." << std::endl;
		}
		break;
	default:
		if (!LoadLibraryDLL(hProcess, dllPath)) {
			success = 0;
			std::cerr << "Failed to inject DLL using LoadLibrary." << std::endl;
		}
		break;
	}
	return success;
}