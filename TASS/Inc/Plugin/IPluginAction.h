#ifndef _I_PLUGIN_ACTION_
#define _I_PLUGIN_ACTION_

#include "IPlugin.h"
#include <istream>
#include <ostream>

class IPluginAction : public IPlugin
{
public:
	IPluginAction(){}
	virtual ~IPluginAction() {};
	virtual bool execute() = 0;	
	virtual bool setParmeters(std::string parameters) = 0;
	virtual std::string getParmeters() = 0;
};



#endif /* _I_PLUGIN_ACTION_ */
