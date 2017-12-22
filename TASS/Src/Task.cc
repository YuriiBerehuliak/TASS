#include "Task.h"


Task::Task(std::string nm):name(nm)
{

}

Task::~Task()
{

}
bool Task::addAction(PluginPair plluginPair)
{
	if (NULL == plluginPair.obj)
	{
		return false;
	}

	actions.push_back(plluginPair);

	return true;
}
bool Task::deleteAction()
{
	return true;
}
bool Task::run()
{
	bool result = true;

	for (int i = 0; i < actions.size(); ++i)
	{
		result = actions[i].obj->execute();

		if (false == result)
		{
			return false;
		}
	}
	return true;
}

bool Task::saveParamsToConfig(std::string path)
{
	std::ofstream file;
	file.open(path + "\\tasks\\" + name + ".task", std::ios::out);

	file << name << "\n";
	for (int i = 0; i < actions.size(); ++i)
	{
		file << actions[i].name << "\n";
		file << actions[i].obj->getParmeters() << "\n";
	}

	file.close();

	return true;
}

std::string Task::getName()
{
	return name;
}