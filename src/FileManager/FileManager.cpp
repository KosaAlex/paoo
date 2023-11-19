#include "FileManager.h"
#include <iostream>
#include <cstring>

FileManager::FileManager(){
    filename = new char[strlen("unk") + 1];
    strcpy(this->filename,"unk");
    content = new char[strlen("unk") + 1];
    strcpy(this->content,"unk");
    std::cout<<"S-a creat fisierul "<<this->filename<<'\n';
}

FileManager::FileManager(const char* name, const char* str){
            filename = new char[strlen(name) + 1];
            strcpy(this->filename,name);
            content = new char[strlen(str) + 1];
            strcpy(this->content,str);
            std::cout<<"S-a creat fisierul "<<name<<'\n';
        }
void FileManager::showContent(){
            std::cout<<"Nume: "<<filename<<", Continut: "<<content<<"\n\n";
        }
FileManager::~FileManager(){
            if(filename != nullptr)
                std::cout<<"Se sterge obiectul "<<filename<<'\n';
            
            delete[] filename;
            delete[] content;
            //std::cout<<"Aici!\n";

        }
//suprascriem copy constructorul
FileManager::FileManager(const FileManager& other){
            //trebuie creata o zona noua de memorie in heap pentru a copia
            filename = new char[strlen(other.filename) + 1];
            strcpy(this->filename,other.filename);
            content = new char[strlen(other.content) + 1];
            strcpy(this->content,other.content);
            std::cout<<"S-a apelat copy constructorul\n";
        }
FileManager::FileManager(FileManager&& other){

            filename = other.filename;
            content = other.content;
            other.filename = nullptr;
            other.content = nullptr; 
            std::cout<<"S-a apelat move constructorul\n";
        }
void FileManager::setContent(char* str){
            this->content = new char[strlen(str) + 1];
            strcpy(this->content,str);
        }
void FileManager::setName(const char* str){
            this->filename = new char[strlen(str) + 1];
            strcpy(this->filename,str);
        }


FileManager& FileManager::operator=(const FileManager& other){
    if( this != &other){
            filename = new char[strlen(other.filename) + 1];
            strcpy(this->filename,other.filename);
            content = new char[strlen(other.content) + 1];
            strcpy(this->content,other.content);
    }
        std::cout<<"S-a apelat asignment operator\n";
            return *this;
    
}

FileManager& FileManager::operator=(FileManager&& other){

        if(this != &other){


            filename = other.filename;
            content = other.content;
            other.filename = nullptr;
            other.content = nullptr; 
        }
        std::cout<<"S-a apelat Move operator\n";
        return *this;
}