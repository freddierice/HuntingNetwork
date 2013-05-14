//
//  Operations.h
//  Dagger
//
//  Created by User on 5/14/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Dagger_Operations_h
#define Dagger_Operations_h
#include <string>
#include "PrintJob.h"

typedef std::string (*pNextNode)(PrintJob *);

std::string MULTIPLE(PrintJob *job);
std::string ABUNDANT(PrintJob *job);
std::string CATALAN(PrintJob *job);
std::string CUBIC(PrintJob *job);
std::string DOUBLE(PrintJob *job);
std::string ELECTRON(PrintJob *job);
std::string EVEN(PrintJob *job);
std::string FACTORS(PrintJob *job);
std::string HAPPY(PrintJob *job);
std::string PRONIC(PrintJob *job);
std::string RESIDUE(PrintJob *job);
std::string REPDIGIT(PrintJob *job);
std::string SQUARE(PrintJob *job);
std::string TRIANGULAR(PrintJob *job);


#endif
