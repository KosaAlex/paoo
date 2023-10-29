#include <iostream>
#include <cstring>

using namespace std;

class FileManager {
    private:
        char* filename;
        char* content;

    public:
        void showContent(){
            cout<<"Nume: "<<filename<<", Continut: "<<content<<"\n\n";
        }
        FileManager(const char* name, const char* str){
            filename = new char[strlen(name) + 1];
            strcpy(this->filename,name);
            content = new char[strlen(str) + 1];
            strcpy(this->content,str);
            cout<<"S-a creat fisierul "<<name<<'\n';
        }
        ~FileManager(){
            cout<<"Se sterge obiectul "<<filename<<'\n';
            delete[] filename;
            delete[] content;

        }
        //suprascriem copy constructorul si realizeaza shallow copy
        FileManager(const FileManager& other){
            //trebuie creata o zona noua de memorie in heap pentru a copia
            filename = new char[strlen(other.filename) + 1];
            strcpy(this->filename,other.filename);
            content = new char[strlen(other.content) + 1];
            strcpy(this->content,other.content);
            cout<<"S-a apelat copy constructorul\n";
        }
        FileManager(FileManager&& other){
            filename = other.filename;
            content = other.content;
            other.filename = nullptr;
            other.content = nullptr; 
            cout<<"S-a apelat move constructorul\n";
        }
       
        void setContent(char* str){
            content = new char[strlen(str) + 1];
            strcpy(this->content,str);
        }
};

int main(){
    FileManager f1("f1","Ana are mere");
    FileManager f2("f2","Ana are pere");
    cout<<"Doua fisiere initiale"<<'\n';
    f1.showContent();
    f2.showContent();

    /*In cazul in care nu suprascriem copy constructorul avem eroarea : main(79166,0x7ff8594d6640) malloc: Double free of object 0x7f8f10705ec0
main(79166,0x7ff8594d6640) malloc: *** set a breakpoint in malloc_error_break to debug
Abort trap: 6*/ 
    cout<<"Fisierul 3 este creat drept copie dupa f1\n";
    FileManager f3 = f1;
    cout<<"In f3 se afla\n";
    f3.showContent();
    cout<<"Modificam f1 si observam ca nu se transmite schimbarea\n";
    f1.setContent("Ana are prune");
    cout<<"In f1 se afla\n";
    f1.showContent();
    cout<<"In f3 se afla\n";
    f3.showContent();
    cout<<"In fisierul f4 se muta fisierul f2\n";
    FileManager f4 = move(f2);
    cout<<"In f4 se afla\n";
    f4.showContent();
    //Daca incercam sa afisam continutul lui f2 avem segmentation fault
    //f2.showContent();
    // Il putem folosi in continuare
    f2 = f3;
    f2.showContent();

    

}