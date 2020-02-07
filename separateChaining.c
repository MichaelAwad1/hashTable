#include <stdio.h>
#include <stdlib.h>
#include "linearProbing.h"
#include "separateChaining.h"


imageDataSeparate *imagesSeparateTable[noOfImages];
int separatecollisionCounter = 0;




void initializeLinearTable()
{
    int i;
    for(i=0;i<noOfImages;i++){
        imageslinearTable[i] = NULL;
    }
}

void putSeparate(int key, Image currentImage)
{
    imageDataSeparate *image = (imageDataSeparate*)malloc(sizeof(imageDataSeparate));
    image->data = currentImage;
    image->key = key;
    image->next = NULL;
    if(imagesSeparateTable[key]==NULL)
        imagesSeparateTable[key] = image;
    else //collision
    {
        printf("Collision occurred at %d\t  Separate Counter = %d\n",key,separatecollisionCounter);
        while(imagesSeparateTable[key]!= NULL)
            imagesSeparateTable[key]=imagesSeparateTable[key]->next;
        imagesSeparateTable[key] = image;
        separatecollisionCounter++;
    }
}

int getSeparate(Image image)
{
    int key = hashKey(hashCode(image));
    if(imagesSeparateTable[key]==NULL) return -1;
    while(imagesSeparateTable[key]!= NULL)
    {
        if(imagesSeparateTable[key]->data.imgArr[idIndex] == image.imgArr[idIndex])
            return image.imgArr[idIndex];
        imagesSeparateTable[key] = imagesSeparateTable[key]->next;
    }
    return image.imgArr[idIndex];
}

int removeSeparate(Image image)
{
    int key = hashKey(hashCode(image));
    while(imagesSeparateTable[key]!=NULL)
    {
        if(imagesSeparateTable[key]->data.imgArr[idIndex] == image.imgArr[idIndex])
        {
            imagesSeparateTable[key] = NULL;
            return key;
        }
        imagesSeparateTable[key]=imagesSeparateTable[key]->next;
    }
    return key;
}
