#pragma once
#include "FileManager.h"


namespace codefilemanager{
    class CppFileManager : public FileManager{
        public:
            CppFileManager() = default;
            CppFileManager(const char* name, const char* str);
            void setName(const char *str) override;

    };
}