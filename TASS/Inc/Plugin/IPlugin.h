#ifndef _I_PLUGIN_
#define _I_PLUGIN_

#include <string>

class IPlugin
{
public:
	IPlugin() {};
	virtual ~IPlugin() {};

	virtual bool setParmeters(std::string parameters) = 0;
	virtual std::string getParmeters() = 0;

};

#endif /* _I_PLUGIN_ */
