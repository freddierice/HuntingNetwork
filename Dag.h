//
//  Dag.h
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//


#ifndef Dagger_Dag_h
#define Dagger_Dag_h

#include <vector>
#include "Node.h"

class Dag {
public:
    static Dag &getInstance();
    Node* nodeByName(std::string name);
    static void addNode(Node *);
private:
    Dag();
    std::vector<Node*> nodes;
};

#endif
