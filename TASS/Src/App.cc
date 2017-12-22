#include "App.h"

App::App()
{

	currentDirectoryPath = FileSystem::getCurrentDir();

}
App::~App()
{

}
bool App::createTask(std::string name)
{
	bool result = true;

	for (int i = 0; i < tasks.size(); ++i)
	{
		if (tasks[i].getName() == name)
		{
			return false;
		}
	}

	//result = FileSystem::createDir(currentDirectoryPath, name);

	if (true != result)
	{
		return false;
	}

	Task task(name);

	tasks.push_back(task);
	tasks.back().saveParamsToConfig(currentDirectoryPath);

	return true;
}
bool App::deleteTask(std::string name)
{
	return true;
}
bool App::runTask(std::string name)
{
	int i;
	bool result;
	for (i = 0; i < tasks.size(); ++i)
	{
		if (tasks[i].getName() == name)
		{
			break;
		}
	}

	if (i == tasks.size())
	{
		return false;
	}

	return tasks[i].run();
}
bool App::addActionToTask(std::string nameTask, std::string actionName, std::string actionParams)
{
	int pos;
	for (pos = 0; pos < tasks.size(); ++pos)
	{
		if (tasks[pos].getName() == nameTask)
		{
			break;
		}
	}
	if (pos == tasks.size())
	{
		return false;
	}

	PluginPair pair = actionsBase.getPluginObject(actionName);
	if (false == pair.flagInstance)
	{
		return false;
	}

	if (false == pair.obj->setParmeters(actionParams))
	{
		return false;
	}

	tasks[pos].addAction(pair);
	tasks[pos].saveParamsToConfig(currentDirectoryPath);

	return true;

}
bool App::deletActionFromTask(std::string nameTask, std::string actionName)
{
	return true;
}
bool App::changedParametersActionInTask(std::string nameTask, std::string actionName, std::string newActionParams)
{

	return true;
}

bool App::loadPlugin(std::string name)
{
	PluginLoader loader;

	std::string tmp = currentDirectoryPath + "\\" + "plugins" + "\\" + name;

	PluginInfo* plg = loader.loadPlugin(tmp.c_str());

	if (NULL == plg)
	{
		return false;
	}

	actionsBase.add(plg);

	return true;
}
bool App::unloadPlugin(std::string name)
{
	PluginLoader loader;

	PluginInfo* plg = actionsBase.remove(name);

	if (NULL == plg)
	{
		return false;
	}

	loader.unloadPlugin(plg);

	return true;
}

bool App::loadTask(std::string path)
{
	std::ifstream file;
	file.open(path, std::ios::out);
	std::string name;

	if (!std::getline(file, name))
	{
		Task task(name);

		std::string actionParams;
		std::string actionName;
		while (true)
		{
			if (!std::getline(file, actionName) || !std::getline(file, actionParams))
			{
				return false;
			}

			PluginPair pair = actionsBase.getPluginObject(actionName);
			if (false == pair.flagInstance)
			{
				return false;
			}

			if (false == pair.obj->setParmeters(actionParams))
			{
				return false;
			}

			task.addAction(pair);
		}
		tasks.push_back(task);
	}

	file.close();

	return true;
}





