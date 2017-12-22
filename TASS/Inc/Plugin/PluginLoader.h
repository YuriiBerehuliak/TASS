#ifndef _LIBRARY_LOADER_
#define _LIBRARY_LOADER_

#include "PluginInfo.h"

#include "string"

class PluginLoader
{
public:
	static PluginInfo* loadPlugin( const char * path);
	static void unloadPlugin(PluginInfo* plInfo);
};

#endif /* _LIBRARY_LOADER_ */

