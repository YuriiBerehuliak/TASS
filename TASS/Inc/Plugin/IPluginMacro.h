#ifndef _I_PLUGIN_MACRO_
#define _I_PLUGIN_MACRO_

#ifdef _WIN32
#define PLUGIN_CALLING_CONVENTION __cdecl
#define PLUGIN_EXPORT __declspec(dllexport)
#else
#define PLUGIN_CALLING_CONVENTION 
#define PLUGIN_EXPORT 
#endif 

#define DEFINE_PLUGIN(creator, pluginName, pluginVersion, pluginType, pathToHelpFile)					\
extern "C" PLUGIN_EXPORT IPlugin* PLUGIN_CALLING_CONVENTION loadPlugin()						\
    {																							\
      return creator.createPlugin();															\
    }																							\
extern "C" PLUGIN_EXPORT void PLUGIN_CALLING_CONVENTION unloadPlugin(IPlugin* plugin)			\
	{																							\
		creator.freePlugin(plugin);																\
	}																							\
																								\
extern "C" PLUGIN_EXPORT const char* PLUGIN_CALLING_CONVENTION getName()						\
    {																							\
      return pluginName;																		\
    }																							\
																								\
extern "C" PLUGIN_EXPORT const char* PLUGIN_CALLING_CONVENTION getVersion()						\
    {																							\
      return pluginVersion;																		\
    }																							\
																								\
extern "C" PLUGIN_EXPORT EPluginType PLUGIN_CALLING_CONVENTION getType()						\
	{																							\
		return 	pluginType;																		\
	}																							\
extern "C" PLUGIN_EXPORT const char* PLUGIN_CALLING_CONVENTION getPathToHelpFile()					\
	{																							\
		return 	pathToHelpFile;																		\
	}			
#endif /* _I_PLUGIN_MACRO_ */
