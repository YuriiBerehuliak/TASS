#ifndef _SHELL_H_
#define _SHELL_H_

#include <string>
#include <iostream>
#include "App.h"
 
class Shell
{
	volatile bool isRun;
	App* app;
public:
	Shell(App* application);
	~Shell();
	int run();
};

#endif /* _SHELL_H_ */