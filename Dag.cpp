//
//  Dag.cpp
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "Dag.h"

Dag::Dag()
{
    
}

Node* Dag::nodeByName(std::string name)
{
    for( int i = 0; i < nodes.size(); ++i )
        if( nodes.at(i)->getName() == name )
            return nodes.at(i);
    return NULL;
}

Dag& Dag::getInstance()
{ 
    static Dag instance = Dag();
    return instance;
}

void Dag::addNode(Node *n)
{
    Dag::getInstance().nodes.push_back(n);
}

