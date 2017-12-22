#include "PluginWindowsBatchCommand.h"

PluginWindowsBatchCommand::PluginWindowsBatchCommand() :IPluginAction()
{

}
PluginWindowsBatchCommand:: ~PluginWindowsBatchCommand()
{

};
bool PluginWindowsBatchCommand::execute()
{
	system(command.c_str());
	return true;
};

bool PluginWindowsBatchCommand::setParmeters(std::string parameters)
{
	command = parameters;
	return true;
}
std::string PluginWindowsBatchCommand::getParmeters()
{
	return command;
}
