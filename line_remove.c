/* line_remove.c*/
/* It removes the lines having particular values */
/* (c) Amit Poudel 2018 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{ int N, i;
  FILE *inptr; 
  FILE *outptr;
  double col1, col2 ;
  char ch[10000], c0[1000], c1[1000];
  char out[1000] , sort[1000];
  
  
  printf("# line_remove \n");
  printf("Usage: line_remove in.dat line_with_value_to_remove \n");
  printf("Example: line_remove in.dat 1.33 \n");
  
  
  /* open file in */
  for ( i = 1; i < (argc-1); i++ )
  {
    printf("# input file: %s",argv[i]);
    inptr=fopen(argv[i],"r");
    if(inptr==NULL)
    {
      printf(" not found.\n");
      return 0;
    }  
    printf("\n");

  /* open file out */
    strcpy(out, "sorted_");
    strcat(out, argv[i]);
    printf("# output file: %s",out);
    outptr=fopen(out,"w");
    printf("\n");


    while(fgets (ch, 1000, inptr)!=NULL)
    { 
      sscanf(ch, "%s %s", c0, c1);

      if (strcmp(c1,argv[(argc-1)])!=0)
      {
        fprintf(outptr, " %s   %s\n", c0, c1);   
      }
      N += 1;
      }
      fclose(inptr);   
      fclose(outptr);
  }
return 0;
}














