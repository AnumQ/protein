#ifndef FILEREADER_H
#define FILEREADER_H
#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;

class FileReader
{
    public:
        FileReader();
        bool openFile(string);
        void closeFile();
        void clearFile();
        ifstream& getFile();


        virtual ~FileReader();
    protected:
    private:
    char delim;
    string filename;
    ifstream readFile;
};

#endif // FILEREADER_H
