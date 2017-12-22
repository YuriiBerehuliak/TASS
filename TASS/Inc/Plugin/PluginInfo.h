#ifndef _PLUGIN_INFO_
#define _PLUGIN_INFO_

#include "IPluginCreator.h"

#ifdef _WIN32
#include <Windows.h>
#define PLUGIN_INSTANCE HINSTANCE
#else
#define PLUGIN_INSTANCE void*
#endif

typedef IPlugin* (__cdecl *fpLoadPlugin)();

typedef void(__cdecl *fpUnloadPlugin)(IPlugin*);

typedef const char* (__cdecl *fpGetName)();

typedef const char* (__cdecl *fpGetVersion)();

typedef EPluginType (__cdecl *fpGetType)();

typedef const char* (__cdecl *fpGetPathToHelpFile)();

class PluginInfo
{
	PLUGIN_INSTANCE pluginInstance_;
	fpLoadPlugin loadPlugin_;
	fpUnloadPlugin unloadPlugin_;
	fpGetName getName_;
	fpGetVersion getVersion_;
	fpGetType getType_;
	fpGetPathToHelpFile getPathToHelpFile_;
public:
	PluginInfo(PLUGIN_INSTANCE pluginInstance,
		fpLoadPlugin loadPlugin,
		fpUnloadPlugin unloadPlugin,
		fpGetName getName,
		fpGetVersion getVersion,
		fpGetType getType,
		fpGetPathToHelpFile getPathToHelpFile);
	~PluginInfo();

	PLUGIN_INSTANCE getInstance();
	IPlugin* loadPlugin();
	void unloadPlugin(IPlugin* plugin);
	const char* getName();
	const char* getVersion();
	EPluginType getType();
	const char* getPathToHelpFile();

};

#endif /* _PLUGIN_INFO_ */
																																										\
