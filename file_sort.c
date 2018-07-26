/* file_sort.c*/
/* It removes the repeated lines  */
/* (c) Amit Poudel 2018 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{ int N=0, i;
  FILE *inptr; 
  FILE *outptr;
  char first[100] = {'f'}, last[100]={'l'};
  char ch[10000]={'\0'}, out[1000]={'\0'}, sort[1000]={'\0'};
    
  
  printf("# file_sort \n");
  printf("Usage: file_sort 1 in.dat \n");
  printf("       f for keeping first occurrence\n");
  printf("       l for keeping last occurrence\n");
  printf("Example: file_sort f in.dat \n");
  if((argc>=2) && (strcmp(argv[1],first)!=0 && strcmp(argv[1],last)!=0))
  {
    printf("Error: give option f for keeping the datas that appear first\n"); 
    printf("       OR          l for keeping the datas that appear last \n");
    return 0;
  }
  
  /* open file in */
  for ( i = 2; i<argc; i++ )
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

   //Finding the total number of lines in the file
    while(fgets (ch, 1000, inptr)!=NULL)
    { 
      N += 1;
    }
    printf("Total number of lines read from the inputfile: %d\n", N);
    
    /* Dynamic memory allocation for n*m matrix */
    double *M;
    int j, k=0, l=0, m=0, n, u;
    double col1, col2 ;
    char c0[1000], c1[1000];
    M = calloc((N+1)*2, sizeof(*M));
   
    // Bringing cursor back to first line
    rewind(inptr);
   
// Keeps the line that comes first
    if(strcmp(argv[1],first)==0)
    { printf("--Keeping the data points occuring first--\n");
      fgets (ch, 1000, inptr);
      sscanf(ch, "%s %s", c0, c1);
      fprintf(outptr, " %s  %s\n", c0,c1);
      rewind(inptr);
      n = 0;
      while(fgets (ch, 1000, inptr)!=NULL)
      { 
        sscanf(ch, "%s %s", c0, c1);
        col1 = atof(c0);
        col2 = atof(c1);
        M[2*n] = col1;
        M[1+2*n]= col2;
        for(u=0; u<n; u++)
        { 
          if(M[2*u] == col1)
          { k +=1;
            break;
          }
          if(u==n-1)
           fprintf(outptr, " %s  %s\n", c0,c1);
         }     
        n += 1;      
       }
     }

// Keeps the line that occus last
    if(strcmp(argv[1],last)==0)
    { printf("--Keeping the data points occuring last--\n");
      rewind(inptr);
      n = 0;
      while(fgets (ch, 1000, inptr)!=NULL)
      { 
        sscanf(ch, "%s %s", c0, c1);
        col1 = atof(c0);
        col2 = atof(c1);
        M[2*n] = col1;
        M[1+2*n]= col2;
        n += 1;
      } 
       
      for(u=0; u<N; u++)
      { for(j=u+1; j<N; j++)
        {  if(M[2*u] == M[2*j])
           { M[2*u] = M[2*j];
             M[1+2*u] = M[1+2*j];
             k +=1;
             break;
           }
        }
       }
       for(l=0; l<N-k; l++)
       { fprintf(outptr, " %1.15g  %1.15g \n", M[2*l], M[1+2*l]);
       }
          
        
          
    }
    printf("Total number of common data points: %d\n", k);
    printf("Total number of lines in the outputfile: %d\n", N-k);

    fclose(inptr);
    fclose(outptr);
    free(M);
  }
return 0;
}














