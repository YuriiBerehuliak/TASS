#include "PluginLoader.h"

#ifdef _WIN32
#include "Windows.h"
PluginInfo* PluginLoader::loadPlugin(const char * path)
{
	HINSTANCE dll_handle = ::LoadLibrary(TEXT("WindowsBatchPlugin.dll"));
	if (!dll_handle) {
		return NULL;
	}

	fpLoadPlugin loadPlugin = reinterpret_cast<fpLoadPlugin>(
		GetProcAddress(dll_handle, "loadPlugin"));
	if (!loadPlugin) {
		FreeLibrary(dll_handle);
		return NULL;
	}

	fpUnloadPlugin unloadPlugin = reinterpret_cast<fpUnloadPlugin>(
		GetProcAddress(dll_handle, "unloadPlugin"));
	if (!unloadPlugin) {
		FreeLibrary(dll_handle);
		return NULL;
	}

	fpGetName getName = reinterpret_cast<fpGetName>(
		GetProcAddress(dll_handle, "getName"));
	if (!getName) {
		FreeLibrary(dll_handle);
		return NULL;
	}

	fpGetName getVersion = reinterpret_cast<fpGetVersion>(
		GetProcAddress(dll_handle, "getVersion"));
	if (!getVersion) {
		FreeLibrary(dll_handle);
		return NULL;
	}

	fpGetType getType = reinterpret_cast<fpGetType>(
		GetProcAddress(dll_handle, "getType"));
	if (!getType) {
		FreeLibrary(dll_handle);
		return NULL;
	}

	fpGetPathToHelpFile getPathToHelpFile = reinterpret_cast<fpGetPathToHelpFile>(
		GetProcAddress(dll_handle, "getType"));
	if (!getPathToHelpFile) {
		FreeLibrary(dll_handle);
		return NULL;
	}

	return new PluginInfo(dll_handle, loadPlugin, unloadPlugin, 
		getName, getVersion, getType, getPathToHelpFile);
}
void PluginLoader::unloadPlugin(PluginInfo* plInfo)
{
	FreeLibrary(plInfo->getInstance());
	delete plInfo;
}
#else

bool PluginLoader::loadPlugin(PluginInfo* plInfo, const char * path)
{

}

bool PluginLoader::unloadPlugin(PluginInfo* plInfo, const char * path)
{

}

#endif