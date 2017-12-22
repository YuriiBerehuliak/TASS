#include "IPluginAction.h"

std::istream &operator>>(std::istream &input, const IPluginAction* plugin)
{
	IPluginAction* pl = const_cast<IPluginAction*>(plugin);
	pl->inputParmsFromConsole(input);
	return input;
}
std::ostream &operator<<(std::ostream &output, const IPluginAction* plugin)
{
	IPluginAction* pl = const_cast<IPluginAction*>(plugin);
	pl->outputParamsoConsole(output);
	return output;
}