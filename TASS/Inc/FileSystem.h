#ifndef _FILE_SYSTEM_
#define _FILE_SYSTEM_

#include <string>

class FileSystem
{
public:
	static std::string getCurrentDir();
	static bool createDir(std::string path, std::string nameDir);
	static bool deleteDir(std::string path, std::string nameDir);
	static bool createFile(std::string path, std::string nameFile);
	static bool deleteFile(std::string path, std::string nameFile);
};

#endif /*_FILE_SYSTEM_ */