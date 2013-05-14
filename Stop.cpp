//
//  Stop.cpp
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "Stop.h"

Stop::Stop(std::string n, int p)
{
    name = n;
    num  = p;
}

std::string Stop::getName()
{
    return this->name;
}

int Stop::getNumber()
{
    return this->num;
}