#include "FileSystem.h"


#ifdef _WIN32

#include <Windows.h>

#include <direct.h>

std::string FileSystem::getCurrentDir()
{
	char result[MAX_PATH];
	GetModuleFileName(NULL, result, MAX_PATH);
	unsigned int len = strlen(result);

	for (int i = len; i >= 0; --i)
	{
		if (result[i] == '\\')
		{
			result[i] = '\0';
			break;
		}
	}

	return std::string(result);
}
bool FileSystem::createDir(std::string path, std::string nameDir)
{
	std::string tmp = path + "\\" + nameDir;


	if (!CreateDirectory(tmp.c_str(), NULL))
	{
		return false;
	}

	return true;
}
bool FileSystem::deleteDir(std::string path, std::string nameDir)
{
	std::string tmp = path +  "\\" + nameDir;


	if (!RemoveDirectory(tmp.c_str()))
	{
		return false;
	}

	return true;
}

bool FileSystem::createFile(std::string path, std::string nameFile)
{
	return true;

}
bool FileSystem::deleteFile(std::string path, std::string nameFile)
{
	return true;
}

#else

#endif