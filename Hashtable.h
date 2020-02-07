#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#define sizeOfImage 785
#define noOfImages 1000
#define idIndex 784



typedef struct Image{
    int imgArr [sizeOfImage];
}Image;

typedef struct imageData{
    Image data;
    int key;
    Image *next;
}imageData;

typedef struct imageDataSeparate{
    Image data;
    int key;
    struct imageDataSeparate *next;
}imageDataSeparate;

Image *givenImages;



void initializeMap();
int hashKey(Image image);
int hashCode(int sum);
void putLinear(int key,Image currentImage);
int removeLinear(Image image);
int getLinear(Image image);
void putSeparate(int key, Image currentImage);
int removeSeparate(Image image);
int getSeparate(Image image);
int areImagesEqual(Image *image1 , Image *image2);
#endif // HASHTABLE_H_INCLUDED
