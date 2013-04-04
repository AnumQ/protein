#include "../include/FileRead.h"
const char LF = 0x0a;  //linefeed
const char CR = 0x0d;  //carriage return

using namespace std;

FileReader::FileReader()
{
    delim = '\n';
}

bool FileReader::openFile( string file )
{
    string i = file;
    readFile.open(i.c_str());
    if (!readFile.is_open() )
	{
		cerr << "Error opening file: " << i << endl;
		return false;
	}
	else
	{
	    if( verbose )
        cout << "Opened file: " << i << endl;
		return true;
	}
}

ifstream& FileReader::getFile()
{
    return readFile;
}

void FileReader::closeFile()
{
    if( verbose )
    cout << "Closing file .. " << endl;
    readFile.close();
}

void FileReader::clearFile()
{
	ifstream& File = readFile;
	if ( verbose )
	{
		cout << "Clearing file .. " << filename << endl;
	}
	File.clear();
	File.seekg( 0, ios::beg );

}

FileReader::~FileReader()
{
    //dtor
}
