//
//  Operations.cpp
//  Dagger
//
//  Created by User on 5/14/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "Operations.h"

std::string MULTIPLE(PrintJob *job)
{
    int n = job->getNum();
    if(n % 3)
        return "ERROR";
    job->setNum(n/3);
    
    return "RESIDUE";
}

std::string ABUNDANT(PrintJob *job)
{
    int n = job->getNum();
    int arr[21] = {12, 18, 20, 24, 30, 36, 40, 42, 48, 54, 56, 60, 66, 70, 72, 78, 80, 84, 88, 90, 96};
    bool isAbundant = false;
    for(int i = 0; i < 22; ++i)
        if( arr[i] == n )
        {
            isAbundant = true;
            break;
        }
    if( isAbundant ){
        job->setNum(n*4);
        return "PRONIC";
    }else{
        job->setNum(n*7);
        return "EVEN";
    }
}

std::string CATALAN(PrintJob *job)
{
    int n = job->getNum();
    if( n != 1 && n != 2 && n != 5 && n != 14 && n != 42 )
        return "ERROR";
    job->setNum(n+4);
    return "ABUNDANT";
}

std::string CUBIC(PrintJob *job)
{
    int n = job->getNum();
    if( n == 1 || n == 8 || n == 27 || n == 64 ){
        job->setNum(n*2);
        return "DOUBLE";
    }else{
        job->setNum(n & 13);
        return "EVEN";
    }
}

std::string DOUBLE(PrintJob *job)
{
    int n = job->getNum();
    if( n > 2*job->getInitial() )
    {
        job->setNum(n-3);
        return "PRINTER";
    }else{
        job->setNum(n-1);
        return "FACTORS";
    }
}

std::string ELECTRON(PrintJob *job)
{
    int n = job->getNum();
    if( n == 2 || n == 8 || n == 18 || n == 32 || n == 50 || n == 72 || n == 98 ){
        job->setNum(n%11);
        return "DOUBLE";
    }else{
        job->setNum(n-2);
        return "PRINTER";
    }
}

std::string EVEN(PrintJob *job)
{
    int n = job->getNum();
    if( n%2 )
    {
        job->setNum(n%9 + 2);
        return "PRINTER";
    }else{
        job->setNum(n-3);
        return "FACTORS";
    }
}

std::string FACTORS(PrintJob *job)
{
    int n = job->getNum();
    
    if( n == 0 || n == 1 ) /* Neither composite nor prime */
    {
        return "REPDIGIT";
    }
    int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
        37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 
        79, 83, 89, 97};
    
    bool isPrime = false;
    for( int i = 0; i < 25; ++i )
        if( n == primes[i] )
        {
            isPrime = true;
            break;
        }
    
    if( isPrime ){ 
        job->setNum(n+1);
        return "CUBIC";
    }else{ 
        job->setNum((n+9) & 10);
        return "PRINTER";
    }
}

std::string HAPPY(PrintJob *job)
{
    int n = job->getNum();
    int happy[19] = {1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 
                  49, 68, 70, 79, 82, 86, 91, 94, 97};
    
    bool isHappy = false;
    for( int i = 0; i < 19; ++i )
    {
        if( happy[i] == n )
        {
            isHappy = true;
            break;
        }
    }
    
    if( isHappy )
    {
        job->setNum(n+3);
        return "SQUARE";
    }else{
        job->setNum(n/2);
        return "PRINTER";
    }
}

std::string PRONIC(PrintJob *job)
{
    int n = job->getNum();
    int pronic[9] = { 2, 6, 12, 20, 30, 42, 56, 72, 90 };
    bool isPronic = false;
    for( int i = 0; i < 9; ++i )
    {
        if( pronic[i] == n )
        {
            isPronic = true;
            break;
        }
    }
    
    if( isPronic )
    {
        job->setNum(n+18);
        return "SQUARE";
    }else{
        return "ERROR";
    }
}

std::string RESIDUE(PrintJob *job)
{
    int n = job->getNum();
    int x = n % 3;
    if( x == 0 )
    {
        job->setNum(n/3 + 4);
        return "PRINTER";
    }else if( x == 1 ){
        if(n == 1){
            job->setNum(1);
        }else if(n == 2){
            job->setNum(2);
        }else if(n == 3){
            job->setNum(6);
        }else if(n == 4){
            job->setNum(24);
        }else{
            job->setNum(-1);
            return "ERROR";
        }
        return "HAPPY";
    }else{
        return "3MULTIPLE";
    }
}

std::string REPDIGIT(PrintJob *job)
{
    int n = job->getNum();
    if( 11*n == job->getRepe() || n == job->getRepe() )
    {
        job->setNum(4*n);
        return "DOUBLE";
    }else{
        return "PRINTER";
    }
}

std::string SQUARE(PrintJob *job)
{
    int n = job->getNum();
    int squares[9] = {1, 4, 9, 16, 25, 36, 49, 64, 81 };
    bool isSquare = false;
    int i = 0;
    for( i = 0; i < 9; ++i )
        if( n == squares[i] )
        {
            isSquare = true;
            break;
        }
    if( isSquare )
    {
        job->setNum(i + 1); /* Sqrt[n] == i + 1 */
        return "TRIANGULAR";
    }else{
        return "ERROR";
    }
}

std::string TRIANGULAR(PrintJob *job)
{
    int n = job->getNum();
    int triangulars[13] = {1, 3, 6, 10, 15, 21, 28, 
                        36, 45, 55, 66, 78, 91};
    bool isTriangular = false;
    for( int i = 0; i < 13; ++i )
        if( triangulars[i] == n )
        {
            isTriangular = true;
            break;
        }
    
    if( isTriangular )
    {
        job->setNum(n+8);
        return "ELECTRON";
    }else{
        job->setNum(n+9);
        return "PRINTER";
    }
}

