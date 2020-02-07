#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "Utility.h"
#include "Mainmenu.h"


FILE *myFile=NULL;
int readFile(const char * filepath , Image* image);
void putImages(Image *images);
int readGivenFile(const char* filepath,Image *images);

int main()
{
    initializeMap();
    Image *images = (Image*)malloc(noOfImages*sizeof(Image));
    putImages(images);
    /*printf("Enter the file path: ");
    char file[100];
    gets(file);
    givenImages = (Image*)malloc(5*sizeof(Image));
    if(!readGivenFile(file,givenImages)) exit(-5);
    mainmenu();*/

    return 0;
}


int readFile(const char * filepath , Image* image)
{
    myFile = NULL;
    myFile = fopen(filepath,"r");
    if(myFile == NULL) return 0;
    int i=0;
    int k=0;
    while(!feof(myFile))
    {
        fscanf(myFile,"%d",&image[k].imgArr[i++]);
        if(i == sizeOfImage)
        {
            i = 0;
            k++;
        }
    }
    fclose(myFile);
    return 1;
}

void putImages(Image *images)
{
    if(!readFile("MNIST-data(datastructures_assignment3)_whitespace.txt",images))exit(-111);
    int i;
    for(i=0;i<noOfImages;i++){
        int key = hashKey(images[i]);
        putLinear(key,images[i]);
        putSeparate(key,images[i]);
    }
}


int readGivenFile(const char* filepath,Image *images)
{
    FILE *givenFILE = NULL;
    givenFILE = fopen(filepath,"r");
    if(givenFILE == NULL) exit(1);
    int i = 0 , j = 0;
    while(!feof(givenFILE))
    {
        fscanf(givenFILE,"%d",&images[j].imgArr[i++]);
        if(i==sizeOfImage - 1)
        {
            i = 0;
            j++;
        }
    }
    fclose(givenFILE);
    /*for(i=0;i<5;i++)
    for(j=0;j<784;j++){
        printf("%d ",images[i].imgArr[j++]);
        if(j==783)
            printf("\n\n\n");
    }*/
    return 1;
}

