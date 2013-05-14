//
//  PrintJob.h
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Dagger_PrintJob_h
#define Dagger_PrintJob_h

class PrintJob {
public:
    PrintJob(int n, int r);
    int getNum();
    int getInitial();
    int getRepe();
    void setNum( int n );
private:
    int num;
    int initial;
    int repe;
};

#endif
