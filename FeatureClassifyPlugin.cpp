#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FeatureClassifyPlugin.h"

void FeatureClassifyPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void FeatureClassifyPlugin::run() {
   
}

void FeatureClassifyPlugin::output(std::string file) { 
	   std::string command = "export OLDPATH=${PATH}; ";
   command += "export PATH=${CONDA_HOME}/bin/:${PATH}; ";
   command += "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2021.4; ";

   //std::string command = "eval \"$(conda shell.bash hook)\"; ";
   //command += "conda activate qiime2-2020.11; ";
   command += "qiime feature-classifier classify-sklearn --i-classifier "+std::string(PluginManager::prefix())+"/"+parameters["classifier"]+" --i-reads "+std::string(PluginManager::prefix())+"/"+parameters["reads"]+" --o-classification "+file+"; ";
 //std::cout << command << std::endl;
   command += "conda deactivate; ";
   command += "conda deactivate; ";
   command += "export PATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<FeatureClassifyPlugin> FeatureClassifyPluginProxy = PluginProxy<FeatureClassifyPlugin>("FeatureClassify", PluginManager::getInstance());
