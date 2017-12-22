#ifndef _TASK_H
#define _TASK_H_

#include <vector>
#include <fstream>
#include "IPluginAction.h"
#include "PluginsBase.h"

class Task
{
	std::string name;
	std::vector<PluginPair> actions;
public:
	Task(std::string nm);
	~Task();
	bool saveParamsToConfig(std::string path);
	bool addAction(PluginPair plluginPair);
	bool deleteAction();
	bool run();
	std::string getName();
};

#endif /*  */