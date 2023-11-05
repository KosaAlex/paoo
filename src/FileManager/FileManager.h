#pragma once


class FileManager {
    private:
        char* filename;
        char* content;

    public:
        void showContent();
        FileManager(const char* name, const char* str);
        ~FileManager();
        
        FileManager(const FileManager& other);
        FileManager(FileManager&& other);
       
        void setContent(char* str);
        void setName(char *str);
};
