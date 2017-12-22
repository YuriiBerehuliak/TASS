#include "PluginInfo.h"


PluginInfo::PluginInfo(PLUGIN_INSTANCE pluginInstance,
	fpLoadPlugin loadPlugin,
	fpUnloadPlugin unloadPlugin,
	fpGetName getName,
	fpGetVersion getVersion,
	fpGetType getType,
	fpGetPathToHelpFile getPathToHelpFile)
{
	pluginInstance_ = pluginInstance;
	loadPlugin_ = loadPlugin;
	unloadPlugin_ = unloadPlugin;
	getName_ = getName;
	getVersion_ = getVersion;
	getType_ = getType;
	getPathToHelpFile_ = getPathToHelpFile;
}
PluginInfo::~PluginInfo()
{

}

PLUGIN_INSTANCE PluginInfo::getInstance()
{
	return pluginInstance_;
}

IPlugin* PluginInfo::loadPlugin()
{

	return this->loadPlugin_();

}
void PluginInfo::unloadPlugin(IPlugin* plugin) 
{
	this->unloadPlugin_(plugin);
}
const char* PluginInfo::getName()
{
	return this->getName_();
}
const char* PluginInfo::getVersion()
{
	return this->getVersion_();
}
EPluginType PluginInfo::getType()
{
	return this->getType_();
}
const char* PluginInfo::getPathToHelpFile()
{
	return this->getPathToHelpFile_();
}