#pragma once
#include "FileManager.h"


namespace codefilemanager{
    class JavaFileManager : public FileManager{
        public:
            JavaFileManager() = default;
            JavaFileManager(const char* name, const char* str);
            void setName(const char *str) override;

    };
}