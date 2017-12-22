#include "PluginCreatorWindowsBatchCommand.h"

PluginCreatorWindowsBatchCommand::PluginCreatorWindowsBatchCommand()
{

}
PluginCreatorWindowsBatchCommand::~PluginCreatorWindowsBatchCommand()
{

}
IPlugin* PluginCreatorWindowsBatchCommand::createPlugin()
{
	return new PluginWindowsBatchCommand;
}
void PluginCreatorWindowsBatchCommand::freePlugin(IPlugin* plugin)
{
	delete plugin;
}
