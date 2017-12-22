#include "Listener.h"

Listener::Listener(std::string path)
{
	fout.open(path.c_str());
}
Listener::~Listener()
{
	fout.close();
}
bool Listener::out(std::string str)
{
	fout << str;
}