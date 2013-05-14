//
//  main.cpp
//  Dagger
//
//  Created by User on 5/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Operations.h"
#include "Dag.h"

int main (int argc, const char * argv[])
{
    Node *multipleNode      = new Node("3MULTIPLE", MULTIPLE);
    Node *abundantNode      = new Node("ABUNDANT", ABUNDANT);
    Node *catalanNode       = new Node("CATALAN", CATALAN);
    Node *cubicNode         = new Node("CUBIC", CUBIC);
    Node *doubleNode        = new Node("DOUBLE", DOUBLE);
    Node *electronNode      = new Node("ELECTRON", ELECTRON);
    Node *evenNode          = new Node("EVEN", EVEN);
    Node *factorsNode       = new Node("FACTORS", FACTORS);
    Node *happyNode         = new Node("HAPPY", HAPPY);
    Node *pronicNode        = new Node("PRONIC", PRONIC);
    Node *residueNode       = new Node("RESIDUE", RESIDUE);
    Node *repdigitNode      = new Node("REPDIGIT", REPDIGIT);
    Node *squareNode        = new Node("SQUARE", SQUARE);
    Node *triangularNode    = new Node("TRIANGULAR", TRIANGULAR);
    
    Node **nodes = (Node **)malloc(14*sizeof(Node*));
    nodes[0]  = multipleNode;
    nodes[1]  = abundantNode;
    nodes[2]  = catalanNode;
    nodes[3]  = cubicNode;
    nodes[4]  = doubleNode;
    nodes[5]  = electronNode;
    nodes[6]  = evenNode;
    nodes[7]  = factorsNode;
    nodes[8]  = happyNode;
    nodes[9]  = pronicNode;
    nodes[10] = residueNode;
    nodes[11] = repdigitNode;
    nodes[12] = squareNode;
    nodes[13] = triangularNode;
    
    Report ***finalReports = (Report ***)malloc(99*sizeof(Report **));
    for( int repe = 1; repe <= 99; ++repe )
    {
        Report ***reports = (Report ***)malloc(14*sizeof(Report **));
        int **successes = (int **)malloc(14*sizeof(int *));
        bool shouldKill = false;
        int killedIndex = 13;
        for( int k = 0; k < 14; ++k )
        {
            reports[k] = (Report **)malloc(99*sizeof(Report *));
            bool hasPrinted = false;
            bool hasLooped = false;
            successes[k] = (int *)malloc(2*sizeof(int));
            successes[k][0] = 0;
            successes[k][1] = 0;
            for( int i = 1; i <= 99; ++i )
            {
                Report *report = new Report();
                PrintJob *job = new PrintJob(i, repe);
                nodes[k]->pass(job, report);
                reports[k][i-1] = report;
                if( !hasPrinted && report->getType() == kPrinted )
                {
                    hasPrinted = true;
                    successes[k][0] = i;
                }
                if( !hasLooped && report->getType() == kLoop )
                {
                    hasLooped = true;
                    successes[k][1] = i;
                }
                if( hasLooped && hasPrinted )
                   break;
                delete job;
                
            }
            if( successes[k][0] + successes[k][1] == 0 )
            {
                shouldKill = true;
                killedIndex = k;
                break;
            }
        }
        if( !shouldKill )
        {
            int uniquePrint = 0;
            int uniqueLoop = 0;
            int both = 0;
            for( int i = 0; i < 14; ++i )
            {
                if( successes[i][0] && successes[i][1] )
                    ++both;
                else if( successes[i][0] )
                    ++uniquePrint;
                else
                    ++uniqueLoop;
            }
            if( uniqueLoop <= 2 && uniquePrint <= 12 )
            {
                int newLoops  = 2-uniqueLoop;
                int newPrints = 12-uniquePrint;
                finalReports[repe-1] = (Report **)malloc(14*sizeof(Report*));
                for( int i = 0; i < 14; ++i )
                {
                    if( successes[i][0] && successes[i][1] )
                    {
                        if( newLoops )
                        {
                            finalReports[repe-1][i] = new Report(*reports[i][successes[i][1]]);
                            --newLoops;
                        }else{
                            finalReports[repe-1][i] = new Report(*reports[i][successes[i][0]]);
                            --newPrints;
                        }
                    }else if( successes[i][0] )
                        finalReports[repe-1][i] = new Report(*reports[i][successes[i][0]]);
                    else
                        finalReports[repe-1][i] = new Report(*reports[i][successes[i][1]]);
                }
            }
        }   
        for( int i = 0; i <= killedIndex; ++i )
        {
            for( int k = 0; k < 99; ++k )
                delete reports[i][k];
            delete reports[i];
            delete successes[i];
        }
        delete successes;
        std::cout << "Done with repe: " << repe << std::endl;
    }
    
    int totalReports = 0;
    for( int i = 0; i < 99; ++i )
        if( finalReports[i] != NULL )
            ++totalReports;
    
    std::cout << "Completed with " << totalReports << " good reports" << std::endl;
    
    for( int i = 0; i < 14; ++i )
        delete nodes[i];
    
    return 0;
}
