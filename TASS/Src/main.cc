#include <iostream>
#include <Windows.h>

#include "shell.h"

App app;
Shell shell(&app);

int main()
{
	
	shell.run();

	return 0;
}
