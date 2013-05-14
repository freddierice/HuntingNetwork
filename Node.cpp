//
//  Node.cpp
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "Dag.h"
#include "Node.h"

Node::Node(std::string name, pNextNode next)
{
    ident    = name;
    nextNode = next;
    type = kComputer;
}

bool Node::pass(PrintJob *job, Report *report)
{
    //std::cout << this->getName() << ": " << job->getNum() << std::endl;
    
    /* Infinite Loop Case */
    if( !report->isFirst() )
    {
        if( report->firstStop()->getName() == this->ident && report->firstStop()->getNumber() == job->getNum() ){
            report->setType(kLoop);
            return true;
        }
    }
    
    /* Found Printer Case */
    if (type == kPrinter)
    {
        report->setType(kPrinted);
        report->pushStop(this->getName(), job->getNum());
        return true;
    }
    
    /* Number Out of Bounds Case */
    if( job->getNum() > 99 || job->getNum() < 1 )
    {
        report->setType(kError);
        return false;
    }
    
    report->pushStop(this->getName(), job->getNum());
    Node *n = Dag::getInstance().nodeByName((*nextNode)(job));
    
    if( n == NULL )
    {
        report->setType(kError);
        return false;
    }
    
    return n->pass(job, report);
}

std::string Node::getName()
{
    return ident;
}

void Node::setType(NodeType t)
{
    type = t;
}

NodeType Node::getType()
{
    return type;
}