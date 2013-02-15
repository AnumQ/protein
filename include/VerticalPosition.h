#ifndef VERTICALPOSITION_H
#define VERTICALPOSITION_H
#include "stdafx.h"
#include "../include/FileCreator.h"
#include "../include/ProteinSequence.h"

using namespace std;

class VerticalPosition
{
    public:
        VerticalPosition();
        void createSomething(vector<ProteinSequence>);
        virtual ~VerticalPosition();
    protected:
    private:
    FileCreator* outFile;
};

#endif // VERTICALPOSITION_H
