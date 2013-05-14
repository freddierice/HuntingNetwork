//
//  Node.h
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Dagger_Node_h
#define Dagger_Node_h
#include <iostream>
#include "Operations.h"
#include "PrintJob.h"
#include "Report.h"

enum NodeType {
    kComputer = 0, kPrinter, kNodeTypes
};

class Node {
public:
    Node(std::string name, pNextNode next);
    bool pass(PrintJob *job, Report *report);
    NodeType getType();
    std::string getName();
private:
    std::string ident;
    NodeType type;
    pNextNode nextNode;
};

#endif
