#ifndef _PLUGINS_BASE_
#define _PLUGINS_BASE_

#include "PluginInfo.h"
#include "IPluginAction.h"
#include <vector>
#include <string>
#include "PluginLoader.h"

struct PluginPair
{
	std::string name;
	IPluginAction* obj;
	bool flagInstance;
};


class PluginsActionBase
{

	PluginLoader loader;
	std::vector<PluginInfo*> base;

	PluginInfo* getPlugInfo(std::string name);
public:
	PluginsActionBase();
	~PluginsActionBase();
	bool add(PluginInfo* plg);

	PluginInfo* remove(std::string name);

	std::vector<std::string> getPluginsNames();	
	PluginPair getPluginObject(std::string name);
	void freePluginObject(PluginPair pluginPair);
	std::string getName(std::string name);
	std::string getVersion(std::string name);
	std::string getPathToHelpFile(std::string name);	
};

#endif /* _PLUGINS_BASE_ */
