#ifndef FEATURECLASSIFYPLUGIN_H
#define FEATURECLASSIFYPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class FeatureClassifyPlugin : public Plugin
{
public: 
 std::string toString() {return "FeatureClassify";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
