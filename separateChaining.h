#ifndef SEPARATECHAINING_H_INCLUDED
#define SEPARATECHAINING_H_INCLUDED
#include "linearProbing.h"


typedef struct imageDataSeparate{
    Image data;
    int key;
    struct imageDataSeparate *next;
}imageDataSeparate;



#endif // SEPARATECHAINING_H_INCLUDED
