#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "Mainmenu.h"
#include "Utility.h"


void arrowHere(int realposition, int arrowposition)
{
    if ( realposition == arrowposition)
    {
        color(15);
    }
    else
    {
        color(8);
    }
}


void mainmenu()
{
    system("ClS");
    int position=1;
    char Keypressed=0;
    setcoordinates(0,0);
    color(10);
    printf("Use arrows");
    while(Keypressed!=(char)13)
    {
        setcoordinates(0,1);
        arrowHere(1,position);
        printf("1.Linear Probing");
        setcoordinates(0,2);
        arrowHere(2,position);
        printf("2.Separate Chaining");
        setcoordinates(0,3);
        arrowHere(3,position);
        printf("3.Exit");
        Keypressed=_getch();
        if(Keypressed==(char)224)
        {
            Keypressed = _getch();
            if(Keypressed == (char)80 && position != 3)
                position++;
            else if(Keypressed == (char)72 && position != 1)
                position--;
            else
                position = position;
        }
    }
    if(position==1)
        linearprobingMenu();
    else if(position==2)
        separateChainingMenu();
    else if(position==3)
        exit(0);
}




void linearprobingMenu()
{
    system("CLS");
    int position =1;
    char Keypressed=0;
    setcoordinates(0,0);
    color(10);
    printf("Use arrows");
    while(Keypressed!=(char)13)
    {
        setcoordinates(0,1);
        arrowHere(1,position);
        printf("1.Search for Images");
        setcoordinates(0,2);
        arrowHere(2,position);
        printf("2.Remove Images");
        setcoordinates(0,3);
        arrowHere(3,position);
        printf("3.Back");
        Keypressed = _getch();
        if(Keypressed==(char)224)
        {
            Keypressed = _getch();
            if(Keypressed == (char)80 && position != 3)
                position++;
            else if(Keypressed == (char)72 && position != 1)
                position--;
            else
                position = position;
        }
    }
    if(Keypressed==(char)13 && position == 3)
        mainmenu();
    if(position==1)
        searchLinear(givenImages);
    else if(position==2)
        deleteLinear(givenImages);

}



void separateChainingMenu()
{
    system("CLS");
    int position =1;
    char Keypressed=0;
    setcoordinates(0,0);
    color(10);
    printf("Use arrows");
    while(Keypressed!=(char)13)
    {
        setcoordinates(0,1);
        arrowHere(1,position);
        printf("1.Search for Images");
        setcoordinates(0,2);
        arrowHere(2,position);
        printf("2.Remove Images");
        setcoordinates(0,3);
        arrowHere(3,position);
        printf("3.Back");
        Keypressed = _getch();
        if(Keypressed==(char)224)
        {
            Keypressed = _getch();
            if(Keypressed == (char)80 && position != 3)
                position++;
            else if(Keypressed == (char)72 && position != 1)
                position--;
            else
                position = position;
        }
    }
    if(Keypressed==(char)13 && position == 3)
        mainmenu();
    if(position==1)
        searchSeparate(givenImages);
    else if(position==2)
        deleteSeparate(givenImages);
}


void searchLinear(Image *image)
{
    color(13);
    system("CLS");
    int i;
    int id = 0;
    for(i=0;i<5;i++)
    {
        id = getLinear(image[i]);
        if(id == -1)
            printf("Image not found \n");
        else
        printf("Image found, ID = %d\n",id);
    }
    char Keypressed;
    color(14);
    printf("\nPress any key to go back to main menu.");
    Keypressed=_getch();
    if(Keypressed)
        mainmenu();
}


void deleteLinear(Image *image)
{
    color(13);
    system("CLS");
    int i;
    int id = 0;
    for(i=0;i<5;i++)
    {
        id = removeLinear(image[i]);
        if(id == -1)
            printf("Image not found \n");
        else
        printf("Image removed, ID = %d\n",id);
    }
    char Keypressed;
    color(14);
    printf("\nPress any key to go back to main menu.");
    Keypressed=_getch();
    if(Keypressed)
        mainmenu();
}

void searchSeparate(Image *image)
{
    color(13);
    system("CLS");
    int i;
    int id = 0;
    for(i=0;i<5;i++)
    {
        id = getSeparate(image[i]);
        if(id == -1)
            printf("Image not found \n");
        else
        printf("Image found, ID = %d\n",id);
    }
    char Keypressed;
    color(14);
    printf("\nPress any key to go back to main menu.");
    Keypressed=_getch();
    if(Keypressed)
        mainmenu();
}


void deleteSeparate(Image *image)
{
    color(13);
    system("CLS");
    int i;
    int id = 0;
    for(i=0;i<5;i++)
    {
        id = removeSeparate(image[i]);
        if(id == -1)
            printf("Image not found \n");
        else
        printf("Image removed , ID = %d\n",id);
    }
    char Keypressed;
    color(14);
    printf("\nPress any key to go back to main menu.");
    Keypressed=_getch();
    if(Keypressed)
        mainmenu();
}
