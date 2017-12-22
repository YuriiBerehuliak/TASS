#ifndef _PLUGIN_WINDOWS_BATCH_COMMAND_
#define _PLUGIN_WINDOWS_BATCH_COMMAND_

#include "IPlugin.h"
#include "IPluginAction.h"

#include <iostream>
#include <string>

class PluginWindowsBatchCommand : public IPluginAction
{
	std::string command;

public:
	PluginWindowsBatchCommand();
	virtual ~PluginWindowsBatchCommand();
	virtual bool execute();
	virtual bool setParmeters(std::string parameters);
	virtual std::string getParmeters();

};

#endif /* _PLUGIN_WINDOWS_BATCH_COMMAND_ */