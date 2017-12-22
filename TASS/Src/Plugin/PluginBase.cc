#include "PluginsBase.h"



PluginInfo* PluginsActionBase::getPlugInfo(std::string name)
{
	if (0 == base.size())
	{
		return NULL;
	}
	
	for (int i = 0; i < base.size(); ++i)
	{
		std::string str(base[i]->getName());
		if (str == name)
		{
			return base[i];
		}
	}

	return NULL;
}

PluginsActionBase::PluginsActionBase() 
{

}
PluginsActionBase::~PluginsActionBase() 
{

}

std::vector<std::string> PluginsActionBase::getPluginsNames()
{
	std::vector<std::string> names = { 0 };

	for (int i = 0; i < base.size(); ++i)
	{

		names.push_back(std::string(base[i]->getName(), strlen(base[i]->getName()) + 1));
	}

	return names;

}

PluginPair PluginsActionBase::getPluginObject(std::string name)
{
	PluginInfo* tmp = getPlugInfo(name);
	PluginPair pluginPair;

	memset(&pluginPair, 0, sizeof(PluginPair));

	if (NULL == tmp)
	{
		return pluginPair;
	}
	pluginPair.flagInstance = true;
	pluginPair.name = std::string(tmp->getName(), strlen(tmp->getName()) + 1);
	pluginPair.obj = dynamic_cast<IPluginAction*>(tmp->loadPlugin());

	return pluginPair;

}
void PluginsActionBase::freePluginObject(PluginPair pluginPair)
{
	PluginInfo* tmp = getPlugInfo(pluginPair.name);

	tmp->unloadPlugin(dynamic_cast<IPlugin*>(pluginPair.obj));
}

std::string PluginsActionBase::getName(std::string name)
{
	PluginInfo* tmp = getPlugInfo(name);
	std::string str = { 0 };

	if (NULL == tmp)
	{
		return str;
	}

	return std::string(tmp->getName(), strlen(tmp->getName()) + 1);
}
std::string PluginsActionBase::getVersion(std::string name)
{
	PluginInfo* tmp = getPlugInfo(name);
	std::string str = { 0 };

	if (NULL == tmp)
	{
		return str;
	}

	return std::string(tmp->getVersion(), strlen(tmp->getVersion()) + 1);
}
std::string PluginsActionBase::getPathToHelpFile(std::string name)
{
	PluginInfo* tmp = getPlugInfo(name);
	std::string str = { 0 };

	if (NULL == tmp)
	{
		return str;
	}

	return std::string(tmp->getPathToHelpFile(), strlen(tmp->getPathToHelpFile()) + 1);
}

bool PluginsActionBase::add(PluginInfo* plg)
{
	if (NULL == plg)
	{
		return false;
	}
	base.push_back(plg);
	return true;
}
PluginInfo* PluginsActionBase::remove(std::string name)
{
	for (int i = 0; i < base.size(); ++i)
	{
		if (0 == strcmp(name.c_str(), base[i]->getName()))
		{
			PluginInfo* tmp = base[i];
			base.erase(base.begin() + i);
			return tmp;
		}
	}
	return NULL;
}