#pragma pack(1)
unsigned char mask[]={0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define PIXEL(r, c) (r[c/8] & mask[c%8])

#include <bits/stdc++.h>
using namespace std;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned DWORD;
typedef int INT;

typedef struct tagBITMAPFILEHEADER {
  /* bmfh */
  WORD bfType;
  DWORD bfSize;
  WORD bfReserved1;
  WORD bfReserved2;
  DWORD bfOffBits;

  void toStr() {
    printf("Size of bitmap file: %d\n", bfSize);
    printf("Bitmap data offset: %d\n\n", bfOffBits);
  }
}
BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
  /* bmih */
  DWORD biSize;
  INT biWidth;
  INT biHeight;
  WORD biPlanes;
  WORD biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  INT biXPelsPerMeter;
  INT biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;

  void toStr() {
    printf("Size of BITMAPFILEHEADER: %d\n", biSize);
    printf("Bitmap width: %d\n", biWidth);
    printf("Bitmap height: %d\n", biHeight);
    printf("#planes: %d\n", biPlanes);
    printf("#bits/pixel: %d\n", biBitCount);
    printf("compression: %d\n", biCompression);
    printf("Image size: %d\n", biSizeImage);
    printf("x resolution: %d\n", biXPelsPerMeter);
    printf("y resolution: %d\n", biYPelsPerMeter);
    printf("#colors: %d\n", biClrUsed);
    printf("#important colors: %d\n\n", biClrImportant);
  }
}
BITMAPINFOHEADER;

typedef struct tagRGBQUAD {
  /* rgbq */
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
}
RGBQUAD;


int main(int argc, char ** argv) {
  char * name = argv[1];
  FILE * file = fopen(name, "rb");

  BITMAPFILEHEADER f;
  if(fread(& f, sizeof(f), 1, file) == 0 || f.bfType != 0x4D42) {
    printf("%s is not a bitmap file!\n",name);
    return 0;
  }

  printf("Bitmap file header of %s:\n", name);
  f.toStr();

  BITMAPINFOHEADER i;
  if(fread(&i, sizeof(i), 1, file) ==0) {
    printf("%s is not a bitmap file!\n",name);
    return 0;
  }
  printf("Bitmap information of %s:\n", name);
  i.toStr();

  if (i.biBitCount <= 8) {
    printf("Color Table of %s:\n", name);
   
    int color;
    for(int j = 0;j<pow(2,i.biBitCount);j++) {
    	fread(&color,4,1,file);
      printf("Color %d: 0x%08x\n", j, color);
    }
    printf("\n");
  }
  
  if(i.biBitCount>1) 
    return 0;
    
  printf("Image of %s:\n\n", name);
  
  char byteBuf;
  string result;
  int rowSize = floor(((i.biBitCount * i.biWidth) + 31) / 32) * 4;
  
  for(int r = 0;r<i.biHeight;r++) {
  	string line;
    for(int k = 0;k<i.biWidth/8;k++) {
  	  fread(&byteBuf,1,1,file);
  	  for(int j = 0;j<8;j++) {
  	    line += (((byteBuf << j) & 0x80) ? '.' : '*');
  	  }
    }
    result = line + "\n" + result;
    line = "";
    fread(&byteBuf,1,rowSize - i.biWidth/8,file);
  }
  cout << result;
}