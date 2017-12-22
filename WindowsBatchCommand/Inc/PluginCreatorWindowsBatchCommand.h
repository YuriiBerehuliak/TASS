#ifndef _PLUGIN_CREATOR_WINDOWS_BATCH_COMMAND_
#define _PLUGIN_CREATOR_WINDOWS_BATCH_COMMAND_

#include "IPluginCreator.h"
#include "IPluginCreatorAction.h"

#include "PluginWindowsBatchCommand.h"

class PluginCreatorWindowsBatchCommand : public IPluginCreator
{

public:
	PluginCreatorWindowsBatchCommand();
	~PluginCreatorWindowsBatchCommand();
	virtual IPlugin* createPlugin();
	virtual void freePlugin(IPlugin* plugin);
};

#endif /* _PLUGIN_CREATOR_WINDOWS_BATCH_COMMAND_ */
