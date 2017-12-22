#include "shell.h"

static const std::string createTaskCmd = "create task";
static const std::string loadTaskCmd = "load task";
static const std::string deleteTaskCmd = "delete task";
static const std::string runTaskCmd = "run task";
static const std::string addActionToTaskCmd = "add action to task";
static const std::string deletActionFromTaskCmd = "delete action from task";
static const std::string changedParametersActionInTaskCmd = "changed parameters action in task";
static const std::string helpCmd = "help";
static const std::string exitCmd = "exit";

static const std::string loadPluginCmd = "load plugin";
static const std::string unloadPluginCmd = "unload plugin";


Shell::Shell(App* application) : isRun(true), app(application)
{

}
Shell::~Shell()
{

}
int Shell::run()
{

	std::string input;

	

	while (isRun)
	{
		bool result = true;
		std::cout << "Enter command -> ";
		std::getline(std::cin, input);

		if (createTaskCmd == input)
		{
			std::string name;
			std::cout << "-> Set Name -> ";
			std::getline(std::cin, name);
			result = app->createTask(name);

			if (true != result)
			{
				std::cout << "-> Task create error" <<std::endl;
			}
			std::cout << "-> Created task \"" << name << "\"" << std::endl;

			continue;
		}

		if (addActionToTaskCmd == input)
		{
			std::string nameTask;
			std::string actionName;
			std::string actionParams;
			std::cout << "-> Set Task Name -> ";
			std::getline(std::cin, nameTask);
			std::cout << "-> Set Action Name -> ";
			std::getline(std::cin, actionName);
			std::cout << "-> Set Action Parameters -> ";
			std::getline(std::cin, actionParams);

			if (true == app->addActionToTask(nameTask,actionName, actionParams))
			{
				std::cout << "-> Action \""<< actionName <<"\" added to task \"" 
					<< nameTask << "\"with parameters \"" <<actionParams <<"\""<<std::endl;
				continue;
			}
			std::cout << "-> Actions added to task error" << std::endl;
			continue;

			continue;
		}

		if (runTaskCmd == input)
		{
			std::string name;
			std::cout << "-> Set Name -> ";
			std::getline(std::cin, name);

			if (true == app->runTask(name))
			{
				std::cout << "-> Task runs  \"" << name << "\"" << std::endl;
				continue;
			}
			std::cout << "-> Task runs error" << std::endl;
		}

		if (loadPluginCmd == input)
		{
			bool result = true;

			std::string name;
			std::cout << "-> Set Name -> ";
			std::getline(std::cin, name);

			if (true == app->loadPlugin(name))
			{
				std::cout << "-> Plugin loaded \"" << name << "\"" << std::endl;
				continue;
			}
			std::cout << "-> Load plugin error" << std::endl;

			continue;
		}

		if (unloadPluginCmd == input)
		{
			bool result = true;

			std::string name;
			std::cout << "-> Set Name -> ";
			std::getline(std::cin, name);			

			if (true == app->unloadPlugin(name))
			{
				std::cout << "-> Plugin unloaded \"" << name << "\"" << std::endl;
				continue;
			}
			std::cout << "-> Unload plugin error" << std::endl;
			continue;
		}




		if (exitCmd == input)
		{
			isRun = false;
			continue;
		}

		std::cout << "Undefined commnd \"" << input << "\"" << std::endl;
	}
	return 0;
}