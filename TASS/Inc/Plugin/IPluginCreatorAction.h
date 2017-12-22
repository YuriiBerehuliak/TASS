#ifndef _I_PLUGIN_CREATOR_ACTION_
#define _I_PLUGIN_CREATOR_ACTION_

#include "IPluginCreator.h"

class IPluginCreatorAction : public IPluginCreator
{
public:
	IPluginCreatorAction() {};
	virtual ~IPluginCreatorAction() {};

	virtual IPlugin* createPlugin() = 0;
	virtual void freePlugin(IPlugin* plugin) = 0;

};

#endif /* _I_PLUGIN_CREATOR_ACTION_ */
