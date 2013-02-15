#ifndef FILECREATOR_H
#define FILECREATOR_H
#include "stdafx.h"

using namespace std;

class FileCreator
{
    public:
        FileCreator();
        void createFile( string );
        void closeFile();
        ofstream& getFile();
        virtual ~FileCreator();
    protected:
    private:
        string filename;
        ofstream OutPutFile;
};

#endif // FILECREATOR_H
