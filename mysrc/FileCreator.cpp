#include "../include/FileCreator.h"

using namespace std;

FileCreator::FileCreator()
{
    //ctor
}

void FileCreator::createFile( string file )
{
    filename = file;
    OutPutFile.open(filename.c_str());

    if ( OutPutFile.is_open() )
    {
        if ( verbose )
        {
            cout << "Created file '" << filename << "'" << endl;
        }

    }
    else
    {
        cout << "Unable to create '" << filename << "'" << endl;
    }
}

void FileCreator::closeFile()
{
    OutPutFile.close();

    if ( verbose )
    {
        cout << "Closing file " << filename << endl;
    }
}

ofstream& FileCreator::getFile()
{
    return OutPutFile;
}

FileCreator::~FileCreator()
{

}
