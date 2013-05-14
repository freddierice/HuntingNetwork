//
//  PrintJob.cpp
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "PrintJob.h"

PrintJob::PrintJob( int n, int r )
{
    num = n;
    initial = n;
    repe = r;
}

int PrintJob::getNum()
{
    return num;
}

int PrintJob::getInitial()
{
    return initial;
}

int PrintJob::getRepe()
{
    return repe;
}

void PrintJob::setNum(int n)
{
    num = n;
}

