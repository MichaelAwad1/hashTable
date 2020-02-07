#include <stdio.h>
#include <stdlib.h>
#include "Hashtable.h"

imageData *imagesLinearTable[noOfImages];
imageDataSeparate *imagesSeparateTable[noOfImages];
int collisionCounter = 0;
int separatecollisionCounter = 0;


void initializeMap()
{
    int i;
    for(i=0;i<noOfImages;i++){
        imagesLinearTable[i] = NULL;
        imagesSeparateTable[i] =NULL;
    }
}


int hashKey(Image image)
{
    int sum=0,i=0,j=0;
    for(i=0;i<28;i++) //Row
        for(j=0;j<28;j++)  //Column
            sum+=image.imgArr[(i*28)+j]*(i+1);
    return sum;
}

int hashCode(int sum)
{
    return sum%noOfImages;
}

void putLinear(int key,Image currentImage)
{
    int index = hashCode(key);
    imageData* image = (imageData*)malloc(sizeof(imageData));
    image->data = currentImage;
    image->key = key;
    if(imagesLinearTable[index]==NULL){
        imagesLinearTable[index] = image;
        //printf("%d No collision at %d\tCounter = %d\n",key,collisionCounter);
    }
    else//Collision
    {
          //printf("Collision occurred at %d\t  Linear Counter = %d\n",index,collisionCounter);
        while(imagesLinearTable[index]!=NULL)
            index = (index+1)%1000;
        imagesLinearTable[index] = image;
        collisionCounter++;
    }
}

int getLinear(Image image)
{
    int index = hashCode(hashKey(image));
    int count = 0;
    if(imagesLinearTable[index]==NULL) return -1;
    while(count!=1000)
    {
        if(imagesLinearTable[index] == NULL) return -1;
        if(areImagesEqual(&(imagesLinearTable[index]->data) , &image))
            return imagesLinearTable[index]->data.imgArr[idIndex];
        count++;
        index=(index+1)%1000;
    }
    return -1;
}

int removeLinear(Image image)
{
    if(getLinear(image) == -1) return -1;
    int index = hashCode(hashKey(image));
    int count = 0;
    if(imagesLinearTable[index]==NULL) return -1;
    while(count!=1000)
    {
        if(areImagesEqual(&(imagesLinearTable[index]->data) , &image))
        {
            int imageiD = imagesLinearTable[index]->data.imgArr[idIndex];
            imagesLinearTable[index] = NULL;
            return imageiD;
        }
        count++;
        index = (index+1)%1000;
    }
    return -1;
}

void putSeparate(int key, Image currentImage)
{
    imageDataSeparate *image = (imageDataSeparate*)malloc(sizeof(imageDataSeparate));
    image->data = currentImage;
    image->key = key;
    image->next = NULL;
    int index = hashCode(key);
    if(imagesSeparateTable[index]==NULL || imagesSeparateTable[index]->data.imgArr[idIndex]==-1)
        imagesSeparateTable[index] = image;
    else //collision
    {
        imageDataSeparate *node = imagesSeparateTable[index];
        //printf("Collision occurred at %d\t  Separate Counter = %d\n",index,separatecollisionCounter);
        while(node->next!= NULL /*&&*/ /*node->data.imgArr[idIndex] != -1*/)
            node=node->next;
        if(!node->next)
            node->next = image;
        /*else
            node = image;*/
        separatecollisionCounter++;
    }
}

int getSeparate(Image image)
{
    int index = hashCode(hashKey(image));
    imageDataSeparate *node = imagesSeparateTable[index];
    if(node==NULL) return -1;
    else
    {
        while(node->next!= NULL)
        {
            if(areImagesEqual(&(node->data) , &image))
                return node->data.imgArr[idIndex];
            node = node->next;
        }
        if(areImagesEqual(&image,&(node->data)))
            return node->data.imgArr[idIndex];
    }
    return -1;
}

int removeSeparate(Image image)
{
    if(getSeparate(image) == -1)
        return -1;   //Image not found.
    int index = hashCode(hashKey(image));
    imageDataSeparate *node = imagesSeparateTable[index];
     while(node!=NULL && !areImagesEqual(&(node->data) , &image))
        node = node->next;
    if(node == NULL) return -1;
    int imageId = node->data.imgArr[idIndex];
    node->data.imgArr[idIndex] = -1;
    return imageId;
}


int areImagesEqual(Image *image1 , Image *image2)
{
    int i;
    for(i=0;i<784;i++)
        if(image1->imgArr[i] != image2->imgArr[i])
            return 0;
    return 1;
}






