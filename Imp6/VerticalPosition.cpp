#include "../include/VerticalPosition.h"

using namespace std;

VerticalPosition::VerticalPosition()
{
    //ctor
}

void VerticalPosition::createSomething( vector<ProteinSequence> p )
{
    outFile = new FileCreator();
    string file = "ShowSequences.txt";
    outFile->createFile(file);
    ofstream& oFile = outFile->getFile();

    oFile.write( file.c_str(), file.size() );

    for( size_t i = 0; i < p.size(); i++ )
    {
        string s = p[i].getSeq();
        oFile.write(s.c_str(), s.size());
    }




    oFile.close();

}
VerticalPosition::~VerticalPosition()
{
    delete outFile;
    //dtor
}
