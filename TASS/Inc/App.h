#ifndef _APP_H_
#define _APP_H_

#include <string>
#include <vector>
#include "PluginsBase.h"
#include "Task.h"
#include "FileSystem.h"
#include "PluginInfo.h"
class App
{
	std::string currentDirectoryPath;
	std::vector<Task> tasks;
	PluginsActionBase actionsBase;
public:
	App();
	~App();
	bool loadTask(std::string path);
	bool createTask(std::string name);
	bool deleteTask(std::string name);
	bool runTask(std::string name);
	bool addActionToTask(std::string nameTask, std::string actionName, std::string actionParams);
	bool deletActionFromTask(std::string nameTask, std::string actionName);
	bool changedParametersActionInTask(std::string nameTask, std::string actionName, std::string newActionParams);
	bool loadPlugin(std::string name);
	bool unloadPlugin(std::string name);
	bool getAllPluginsName();
	
};

#endif /* _APP_H_ */