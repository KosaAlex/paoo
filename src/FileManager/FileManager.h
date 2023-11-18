#pragma once


class FileManager {
    private:
        char* filename;
        char* content;

    public:
        void showContent();
        FileManager();
        FileManager(const char* name, const char* str);
        ~FileManager();
        
        FileManager(const FileManager& other);
        FileManager(FileManager&& other);

        FileManager& operator=(const FileManager& other);
        FileManager& operator=(FileManager&& other);
       
        void setContent(char* str);
        virtual void setName(const char *str);
};
