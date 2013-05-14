//
//  Stop.h
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Dagger_Stop_h
#define Dagger_Stop_h
#include "string"

class Stop {
public:
    Stop(std::string n, int p);
    std::string getName();
    int getNumber();
private:
    std::string name;
    int num;
};

#endif
