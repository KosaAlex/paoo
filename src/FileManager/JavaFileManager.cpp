#include <cstring>
#include "JavaFileManager.h"
#include <string>

namespace codefilemanager{
    JavaFileManager::JavaFileManager(const char* name, const char* str)
        :FileManager((std::string(name) + ".java").c_str(), str) {}
    void JavaFileManager::setName(const char* str){
            FileManager::setName((std::string(str) + ".cpp").c_str());
        }
}