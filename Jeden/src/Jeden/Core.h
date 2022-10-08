#pragma once

#ifdef JD_PLATFORM_WINDOWS
	#ifdef JD_BUILD_DLL
		#define JEDEN_API __declspec(dllexport)
	#else
		#define JEDEN_API __declspec(dllimport)
	#endif
#else
	#error Jeden only supports Windows!
#endif