#pragma once


#include <Windows.h>
#include <string>
#include "load-library.h"
#include "manual-map.h"

enum class InjectionType
{
	LoadLibraryDLL,
	ManualMap
};

int Inject(HANDLE hProcess, const std::string& dllPath, InjectionType type = InjectionType::LoadLibraryDLL);