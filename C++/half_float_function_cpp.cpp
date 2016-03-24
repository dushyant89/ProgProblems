#include "iostream"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define INT16_TYPE int16_t
#define UINT16_TYPE uint16_t
#define INT32_TYPE int32_t
#define UINT32_TYPE uint32_t
typedef unsigned char BYTE;
using namespace std;
typedef uint16_t HALF;
float HALFToFloat(HALF y);
uint32_t halfToFloatI(HALF y);

int main(int argc, char* argv[])
{

    string filename;
    string outputFilename;
    int endian;
    long Npixels;
    long Nlines;
    long fileSize;
    float *master;
    BYTE *memory;


    cout <<" ----------------------------------------------------------" <<endl;
    cout <<" Half precision float to float conversion (big-endian gamma)" <<endl;
    cout <<"----------------------------------------------------------" <<endl;
    cout <<" CSRE MRSL LAB                                            " <<endl;
    cout <<" ---------------------------------------------------------" <<endl;
    cout <<endl <<endl;

      /*cout <<"Input File Name : "<<endl;
      cin >>filename;

      cout <<"Output File Name: "<<endl;
      cin >>outputFilename;

      cout <<"Big-endian(enter 1) or Litte-endian (enter 2)"<<endl;
      cin >>endian;
*/
      cout <<"Number of Pixel per line "<<endl;
      cin >>Npixels;


      /*filename = argv[1];
      outputFilename = argv[2];
      endian = atoi(argv[3]);
      Npixels = atoi(argv[4]);


    FILE *inputFilep;
    inputFilep = fopen(filename.c_str(),"rb+");
    fseek(inputFilep,0L,SEEK_END);
    fileSize = ftell(inputFilep);
    fseek(inputFilep,0L,SEEK_SET);

    FILE *outFilep;
    outFilep = fopen(outputFilename.c_str(), "wb+");
    cout<< "\nFileSize : " <<fileSize<<" Bytes" <<endl;
    memory = new BYTE [fileSize];
    Nlines = fileSize/(Npixels*4);

    master = new float [Nlines*Npixels*2];
    if(memory == NULL) {cout << "\n ERROR:\n Memory Allocation Failed"<<endl;}
    else { cout <<"\n Memory Allocated Successfully"<<endl;}
    fread(memory,sizeof(BYTE),fileSize,inputFilep);
*/
    printf("Percent Completed : ###");
     
	 HALF yy=1536;
	 
	 unsigned int ct=0;
	  int i;
   float fd;
    for (i=0; i<1; i=i++);
    {

            
			fd=HALFToFloat(yy);
			printf("%f",fd);
    }
   //fwrite(master, sizeof(float),Nlines*Npixels*2,outFilep);
 }

typedef uint16_t HALF;
uint32_t halfToFloatI(HALF y);

float HALFToFloat(HALF y)
{
    union { float f; uint32_t i; } v;
    cout <<halfToFloatI(y)<<endl;
	v.i = halfToFloatI(y);
    return v.f;
}

uint32_t halfToFloatI(HALF y)
{
    int s = (y >> 15) & 0x00000001;cout<<"s="<<s<<endl;                            // sign
    int e = (y >> 10) & 0x0000001f;cout<<"e="<<e<<endl;                            // exponent
    int f =  y        & 0x000003ff;cout<<"f="<<f<<endl;                            // fraction

    // need to handle 7c00 INF and fc00 -INF?
    if (e == 0) {
        // need to handle +-0 case f==0 or f=0x8000?
        if (f == 0)                                            // Plus or minus zero
            return s << 31;
        else {                                                 // Denormalized number -- renormalize it
            while (!(f & 0x00000400)) {
                f <<= 1;
                e -=  1;
            }
            e += 1;
            f &= ~0x00000400;
        }
    } else if (e == 31) 
	{
        if (f == 0)                                             // Inf
            return (s << 31) | 0x7f800000;
        else                                                    // NaN
            return (s << 31) | 0x7f800000 | (f << 13);
    }

    e = e + (127 - 15);
    //f = f << 13;

    return ((s<<31) | (e << 23) | f);
}
