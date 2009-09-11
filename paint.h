#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>


#include "structure.h"

using namespace std;
#define XSIZE 540
#define YSIZE 540

#define BITS_PER_PIXEL 32
#define BYTES_PER_PIXEL 4

#define BMP2 "2.bmp"
#define BMPTMP "wynikowy.bmp"

//#define MAX(a, b) (a > b ? a : b)
//#define MIN(a, b) (a < b ? a : b)
//#define CUT(rgb, down, up) MIN(MAX(rgb, down), up)

//-------------------------------------------------------------------

extern SDL_Surface *screen;	// ekran do wyswietlenia grafiki
extern SDL_Surface *img;		// aktualnie widoczny obrazek

void Wyswietl(const int filtr_w, const int filtr_h, const int filtr[],char *napis);
SDL_Surface *display_bmp(char *file_name);
bool Init (const char *header);
Uint32 getpixel(SDL_Surface *surface, int x, int y);
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
structure* Loop (void);
//void redraw(structure*);


