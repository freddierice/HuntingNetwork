//
//  Report.h
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Dagger_Report_h
#define Dagger_Report_h

#include "iostream"
#include "fstream"
#include "vector"
#include "Stop.h"

enum ReportType {
    kError = 0, kLoop, kPrinted, kNumTypes
};

class Report {
public:
    Report();
    void pushStop( std::string ident, int num );
    Stop* firstStop();
    Stop* lastStop();
    bool isFirst();
    void setType(ReportType t);
    void print(int i);
    ReportType getType();
private:
    std::vector<Stop *> stops;
    ReportType type;
};

#endif
