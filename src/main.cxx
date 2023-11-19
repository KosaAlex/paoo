#include <iostream>
#include "CppFileManager.h"
#include "JavaFileManager.h"

using namespace codefilemanager;



int main(){
    // FileManager f1("f1","Ana are mere");
    // FileManager f2("f2","Ana are pere");
    // std::cout<<"Doua fisiere initiale"<<'\n';
    // f1.showContent();
    // f2.showContent();

    /*In cazul in care nu suprascriem copy constructorul avem eroarea : main(79166,0x7ff8594d6640) malloc: Double free of object 0x7f8f10705ec0
main(79166,0x7ff8594d6640) malloc: *** set a breakpoint in malloc_error_break to debug
Abort trap: 6*/ 
//call to implicitly-deleted copy constructor of 'FileManager'
    // std::cout<<"Fisierul 3 este creat drept copie dupa f1\n";
    // FileManager f3 = f1;
    // std::cout<<"In f3 se afla\n";
    // f3.showContent();
    // std::cout<<"Modificam f1 si observam ca nu se transmite schimbarea\n";
    // f1.setContent("Ana are prune");
    // std::cout<<"In f1 se afla\n";
    // f1.showContent();
    // std::cout<<"In f3 se afla\n";
    // f3.showContent();
    // std::cout<<"In fisierul f4 se muta fisierul f2\n";
    // FileManager f4 = std::move(f2);
    // std::cout<<"In f4 se afla\n";
    // f4.showContent();
    //Daca incercam sa afisam continutul lui f2 avem segmentation fault
    //f2.showContent();
    //f2 este inca valid
    // f2.setContent("Ana are merer");

    // f1.setName("f1");
    // f2.setName("f2");
    // f3.setName("f3");
    // f4.setName("f4");


    FileManager txtFile;
    JavaFileManager javaFile("f1","Hello!");
    CppFileManager cppFile("f2","Hi!");

    javaFile.showContent();
    cppFile.showContent();

    JavaFileManager javaFile2;

    javaFile2 = javaFile;
    CppFileManager cppFile2 = cppFile;

    javaFile2.showContent();
    cppFile2.showContent();

    JavaFileManager javaFile3;
    javaFile3 = std::move(javaFile);
    CppFileManager cppFile3 = std::move(cppFile);

    javaFile3.showContent();
    cppFile3.showContent();

    txtFile = cppFile3;


    

}