#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


/*
 *   Program name: dynCGOL.c
 *   Author: Rehan Nagoor Mohideen
 *   Student ID: 1100592
 *   Function: program of Conways game of life with a fixed array size of 20X40.
 *   Compilation: make dynCGOL
 */

int main ( int argc, char *argv[] ) {
  int maxRows;
  int maxColumns;
  FILE *f1;
  int i=0, x=0, y=0, j=0, c=0, tick=0, totalTicks=50;
  char start[10];
  char cont[10];
  char string [100];


/*checks if there are a right amount of arguments*/
  if (argc!=5) {
    printf("Usage: ./dynCGOL (filename) (ticks) (no. of rows) (no. of columns)\n");
    exit(0);
  }

  totalTicks = atoi(argv[2]);
  maxRows = atoi(argv[3]);
  maxColumns = atoi(argv[4]);

  if (totalTicks < 1 || maxRows < 1 || maxColumns < 1) {
    printf("Please enter ticks, no. of Rows and no. of Columns greater than 0\n" );
    exit(0);
  }


  int currentGrid[maxRows][maxColumns], futureGrid[maxRows][maxColumns];

/*checks if the file is the right grid size*/
  if ((f1 = fopen(argv[1], "r")) != NULL) {
    while ( fgets(string, 100, f1) != NULL ) {
      if (strlen(string) != maxColumns*2) {
        printf("Input file not in valid grid size.\n" );
        exit(0);
      }
      c++;
    }
  }
  if (c != maxRows) {
    printf("Input file not in valid grid size.\n" );
    exit(0);
  }
  fclose(f1);


/*reads and stores data from file to the array*/
  if ( (f1 = fopen(argv[1], "r")) != NULL ) {

    for (x = 0; x < maxRows; x++) {
      for (y = 0; y < maxColumns; y++) {
        fscanf(f1 , "%d", &currentGrid[x][y]);
        if (currentGrid[x][y] != 1 && currentGrid[x][y] != 0) {
          printf("Input file not in valid grid size of 20X40.\n" );
        }
      }
    }


  }else {
    printf ( "Cannot open %s\n", argv[1] );
    return ( -2 );
  }
  fclose(f1);

  memcpy(futureGrid, currentGrid, sizeof(currentGrid));

/*prints initial grid data.*/
  system("clear");
  printf(" ");
  for (i = 0; i < maxColumns; i++) {
    printf("-");
  }
  printf("\n");
  for (x = 0; x < maxRows; x++) {
    printf("|");
    for (y = 0; y < maxColumns; y++) {
      if (currentGrid[x][y] == 1) {
        printf("X");
      }else {
        printf(" ");
      }
    }
    printf("|\n");
  }
  printf(" ");
  for (i = 0; i < maxColumns; i++) {
    printf("-");
  }
  printf("%d\n", tick);


  do {
    printf("Start? (y or n):");
    scanf("%s", start);
    if (strcmp(start, "Y")!=0 && strcmp(start, "y")!=0 && strcmp(start, "N")!=0 && strcmp(start, "n")!=0) {
      printf("Only single characters n or n are acceptable.\n");
    }
  } while(strcmp(start, "Y")!=0 && strcmp(start, "y")!=0 && strcmp(start, "N")!=0 && strcmp(start, "n")!=0);


  if (strcmp(start, "Y")==0 || strcmp(start, "y")==0) {
    do {
      for (j = 0; j < totalTicks; j++) {
        memcpy(currentGrid, futureGrid, sizeof(futureGrid));


/*Calulates future grid for all array locations except for the borders*/
        for (x = 1; x < maxRows-1; x++) {
          for (y = 1; y < maxColumns-1; y++) {
            if (currentGrid[x][y] == 1) {
              if ((currentGrid[x-1][y-1] + currentGrid[x-1][y] + currentGrid[x-1][y+1] + currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x+1][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) != 2  && (currentGrid[x-1][y-1] + currentGrid[x-1][y] + currentGrid[x-1][y+1] + currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x+1][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) != 3) {
                futureGrid[x][y] = 0;
              }
            }else{
              if ((currentGrid[x-1][y-1] + currentGrid[x-1][y] + currentGrid[x-1][y+1] + currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x+1][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) == 3) {
                futureGrid[x][y] = 1;
              }
            }
          }
        }

/*Calculates futre grid for the left border data*/
        y=0;
        for (x = 1; x < maxRows-1; x++) {
          if (currentGrid[x][y] == 1) {
            if ((currentGrid[x-1][y] + currentGrid[x-1][y+1] + currentGrid[x][y+1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) != 2 && (currentGrid[x-1][y] + currentGrid[x-1][y+1] + currentGrid[x][y+1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) != 3) {
              futureGrid[x][y] = 0;
            }
          }else{
            if ((currentGrid[x-1][y] + currentGrid[x-1][y+1] + currentGrid[x][y+1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) == 3) {
              futureGrid[x][y] = 1;
            }
          }
        }

/*Calculates futre grid for the right border data*/
        y=maxColumns-1;
        for (x = 1; x < maxRows-1; x++) {
          if (currentGrid[x][y] == 1) {
            if ((currentGrid[x-1][y] + currentGrid[x-1][y-1] + currentGrid[x][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y-1]) != 2 && (currentGrid[x-1][y] + currentGrid[x-1][y-1] + currentGrid[x][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y-1]) != 3) {
              futureGrid[x][y] = 0;
            }
          }else{
            if ((currentGrid[x-1][y] + currentGrid[x-1][y-1] + currentGrid[x][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y-1]) == 3) {
              futureGrid[x][y] = 1;
            }
          }
        }

/*Calculates futre grid for the top border data*/
        x=0;
        for (y = 1; y < maxColumns-1; y++) {
          if (currentGrid[x][y] == 1) {
            if ((currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x+1][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) != 2 && (currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x+1][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) != 3) {
              futureGrid[x][y] = 0;
            }
          }else{
            if ((currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x+1][y-1] + currentGrid[x+1][y] + currentGrid[x+1][y+1]) == 3) {
              futureGrid[x][y] = 1;
            }
          }
        }

/*Calculates futre grid for the top border data*/
        x=maxRows-1;
        for (y = 1; y < maxColumns-1; y++) {
          if (currentGrid[x][y] == 1) {
            if ((currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x-1][y-1] + currentGrid[x-1][y] + currentGrid[x-1][y+1]) != 2 && (currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x-1][y-1] + currentGrid[x-1][y] + currentGrid[x-1][y+1]) != 3) {
              futureGrid[x][y] = 0;
            }
          }else{
            if ((currentGrid[x][y-1] + currentGrid[x][y+1] + currentGrid[x-1][y-1] + currentGrid[x-1][y] + currentGrid[x-1][y+1]) == 3) {
              futureGrid[x][y] = 1;
            }
          }
        }

/*Calculates futre grid for the top left corner data*/
        x=0;
        y=0;
        if (currentGrid[x][y] == 1) {
          if ((currentGrid[x][y+1] + currentGrid[x+1][y+1] + currentGrid[x+1][y]) != 2 && (currentGrid[x][y+1] + currentGrid[x+1][y+1] + currentGrid[x+1][y]) != 3) {
            futureGrid[x][y] = 0;
          }
        }else{
          if ((currentGrid[x][y+1] + currentGrid[x+1][y+1] + currentGrid[x+1][y]) == 3) {
            futureGrid[x][y] = 1;
          }
        }

/*Calculates futre grid for the bottom left corner data*/
        x=0;
        y=maxColumns-1;
        if (currentGrid[x][y] == 1) {
          if ((currentGrid[x][y-1] + currentGrid[x+1][y-1] + currentGrid[x+1][y]) != 2 && (currentGrid[x][y-1] + currentGrid[x+1][y-1] + currentGrid[x+1][y]) != 3) {
            futureGrid[x][y] = 0;
          }
        }else{
          if ((currentGrid[x][y-1] + currentGrid[x+1][y-1] + currentGrid[x+1][y]) == 3) {
            futureGrid[x][y] = 1;
          }
        }

/*Calculates futre grid for the bottom right corner data*/
        x=maxRows-1;
        y=maxColumns-1;
        if (currentGrid[x][y] == 1) {
          if ((currentGrid[x][y-1] + currentGrid[x-1][y-1] + currentGrid[x-1][y]) != 2 && (currentGrid[x][y-1] + currentGrid[x-1][y-1] + currentGrid[x-1][y]) != 3) {
            futureGrid[x][y] = 0;
          }
        }else{
          if ((currentGrid[x][y-1] + currentGrid[x-1][y-1] + currentGrid[x-1][y]) == 3) {
            futureGrid[x][y] = 1;
          }
        }

/*Calculates futre grid for the top right corner data*/
        x=maxRows-1;
        y=0;
        if (currentGrid[x][y] == 1) {
          if ((currentGrid[x][y+1] + currentGrid[x-1][y+1] + currentGrid[x-1][y]) != 2 && (currentGrid[x][y+1] + currentGrid[x-1][y+1] + currentGrid[x-1][y]) != 3) {
            futureGrid[x][y] = 0;
          }
        }else{
          if ((currentGrid[x][y+1] + currentGrid[x-1][y+1] + currentGrid[x-1][y]) == 3) {
            futureGrid[x][y] = 1;
          }
        }


/*Exits if the grid does not change between grids.*/
        if (memcmp(currentGrid, futureGrid, sizeof(futureGrid)) == 0) {
          exit(0);
        }

/*prints out the grid for each tick.*/
        tick++;
        system("clear");
        printf(" ");
        for (i = 0; i < maxColumns; i++) {
          printf("-");
        }
        printf("\n");
        for (x = 0; x < maxRows; x++) {
          printf("|");
          for (y = 0; y < maxColumns; y++) {
            if (futureGrid[x][y] == 1) {
              printf("X");
            }else {
              printf(" ");
            }
          }
          printf("|\n");
        }
        printf(" ");
        for (i = 0; i < maxColumns; i++) {
          printf("-");
        }
        printf("%d\n", tick);
        system("sleep 0.25");
      }

/*checks if u want to continue once the number of ticks are complete.*/
      do {
        printf("cont? (y or n):");
        scanf("%s", cont);
        if (strcmp(cont, "Y")!=0 && strcmp(cont, "y")!=0 && strcmp(cont, "N")!=0 && strcmp(cont, "n")!=0) {
          printf("Only single characters y or n are acceptable.\n");
        }
      } while(strcmp(cont, "Y")!=0 && strcmp(cont, "y")!=0 && strcmp(cont, "N")!=0 && strcmp(cont, "n")!=0);

    } while((strcmp(cont, "Y") ==0 || strcmp(cont, "y") == 0));

  }else {
    exit(0);
  }

return 0;
}
