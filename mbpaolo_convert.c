/* This is Dr. Paolo Pasquali's Program for converting HP/SUN to DIGITAL or
   Vice versa */
#include  <stdio.h>

main(int argc, char **argv)
{

int        na, nr;
int        a;
int        size;


char      *buffer, *pos, *end, app;

FILE      *inf, *outf;


fprintf(stderr, "%s: convert a binary file from HP/SUN to DIGITAL format and vice versa\n",argv[0]);


if( argc < 4 ) {
 fprintf(stderr,"\nusage: %s <bytes*sample> <samples*record> <records> [<infile> [<outfile>]]\n",argv[0]);
 fprintf(stderr,"bytes*sample           2: short int, 4: float or (long) int, 8: double\n");
 fprintf(stderr,"samples*record         of bytes*sample lenght\n");
 fprintf(stderr,"records                of samples*record elements\n");
 fprintf(stderr,"infile                 if not provided, stdin is used\n");
 fprintf(stderr,"outfile                if not provided, stdout is used\n");
 exit(-1);
  }

if( argc > 4 ) {
   inf = fopen(argv[4],"r"); 
   if (inf == NULL){
      fprintf(stderr, "Cannot open input file: %s\n",argv[4]);
      exit(-1);
     }
   } else inf = stdin;

if( argc > 5 ) {
   outf = fopen(argv[5],"w"); 
   if (outf == NULL){
      fprintf(stderr, "Cannot open output file: %s\n",argv[5]);
      exit(-1);
     }
   } else outf = stdout;


sscanf(argv[1],"%d",&size);
sscanf(argv[2],"%d",&nr);
sscanf(argv[3],"%d",&na);


buffer= (char *) malloc(nr*size*sizeof(char));
if( buffer==NULL ) {
   fprintf(stderr, "Cannot allocate %d bytes of memory for I/O buffer\n", nr*size*sizeof(char));
   exit(-1);
   }


end = &buffer[nr*size];

for (a=0; a<na; a++) {

   if( fread((char *) buffer, sizeof(char), nr*size, inf) != nr*size) {
         fprintf( stderr, "Impossible to read record number %d\n", a);
         exit(-1);
      }

   switch( size ) {
        case 2:
           for( pos=buffer; pos<end; pos+=2) {
                 app = pos[1];
                 pos[1] = pos[0];
                 pos[0] = app;
                 }
           break;
        case 4:
           for( pos=buffer; pos<end; pos+=4) {
                 app = pos[3];
                 pos[3] = pos[0];
                 pos[0] = app;
                 app = pos[2];
                 pos[2] = pos[1];
                 pos[1] = app;
                 }
           break;
        case 8:
           for( pos=buffer; pos<end; pos+=8) {
                 app = pos[7];
                 pos[7] = pos[0];
                 pos[0] = app;
                 app = pos[6];
                 pos[6] = pos[1];
                 pos[1] = app;
                 app = pos[5];
                 pos[5] = pos[2];
                 pos[2] = app;
                 app = pos[4];
                 pos[4] = pos[3];
                 pos[3] = app;
                 }
           break;
        default:
           fprintf( stderr, "Error: invalid number of bytes*sample\n");
           exit(-1);
           break;
       }

   if( fwrite((char *) buffer, sizeof(char), nr*size, outf) != nr*size) {
         fprintf( stderr, "Impossible to write record number %d\n", a);
         exit(-1);
      }

   }

fprintf( stderr, "%s: conversion done\n",argv[0]);



free(buffer);

if( argc > 5 ) fclose(outf);
if( argc > 4 ) fclose(inf);

}