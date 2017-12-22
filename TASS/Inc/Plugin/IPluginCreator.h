#ifndef _I_PLUGIN_CREATOR_
#define _I_PLUGIN_CREATOR_

#include <string>
#include "IPlugin.h"

enum EPluginType
{
	EPluginAction,
	EPluginParser,
	EEnd
};

class IPluginCreator
{
public:
	IPluginCreator() {};
	virtual ~IPluginCreator() {};
	virtual IPlugin* createPlugin() = 0;
	virtual void freePlugin(IPlugin* plugin) = 0;
};

#endif /* _I_PLUGIN_CREATOR_ */