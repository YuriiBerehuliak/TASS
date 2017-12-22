#include "IPluginMacro.h"

#include "PluginWindowsBatchCommand.h"
#include "PluginCreatorWindowsBatchCommand.h"

static PluginCreatorWindowsBatchCommand WindowsBatchCommandCreator;

DEFINE_PLUGIN(WindowsBatchCommandCreator, "WindowsBatchCommand", "0.1V", EPluginAction, "D:\qwe");
