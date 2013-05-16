//
//  Report.cpp
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "Report.h"

Report::Report()
{
    type = kNumTypes;
}

void Report::pushStop( std::string ident, int num )
{
    stops.push_back(new Stop(ident,num));
}

Stop* Report::firstStop()
{
    return stops.at(0);
}

Stop* Report::lastStop()
{
    return stops.at(stops.size()-1);
}

bool Report::isFirst()
{
    return stops.size() == 0;
}

void Report::setType(ReportType t)
{
    type = t;
}

ReportType Report::getType()
{
    return type;
}

void Report::print(int i)
{
    std::ofstream file ("report.csv",std::ofstream::binary | std::ofstream::app);
    for (int i = 0; i < stops.size(); ++i) 
        file << stops.at(i)->getName() << "," << stops.at(i)->getNumber() << std::endl;
    if( i == 13 )
        file << "BREAK,BREAK\n";
    file.close();
}

