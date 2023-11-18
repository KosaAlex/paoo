#include <cstring>
#include "CppFileManager.h"
#include <string> 

namespace codefilemanager{
    CppFileManager::CppFileManager(const char* name, const char* str) 
        : FileManager((std::string(name) + ".cpp").c_str(), str) {}
    void CppFileManager::setName(const char* str){
            FileManager::setName((std::string(str) + ".cpp").c_str());
        }
}