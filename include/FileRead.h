#ifndef FILEREAD_H
#define FILEREAD_H
#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

class FileRead
{
    public:
        FileRead();
        bool openFile(string);
        void closeFile();
        void clearFile();
        ifstream& getFile();


        virtual ~FileRead();
    protected:
    private:
    char delim;
    string filename;
    ifstream readFile;
};

#endif // FILEREAD_H
