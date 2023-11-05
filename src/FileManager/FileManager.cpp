#include "FileManager.h"
#include <iostream>
#include <cstring>

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
void FileManager::setName(char* str){
            this->filename = new char[strlen(str) + 1];
            strcpy(this->filename,str);
        }