#include <iostream>

#include "paint.h"


using namespace std;

SDL_Surface *screen;		// ekran do wyswietlenia grafiki
SDL_Surface *img;		    // aktualnie widoczny obrazek


int main(int argc, char *args[]){

    freopen( "CON", "w", stdout );
	freopen( "CON", "w", stderr );

	if (!Init ("mesh")){
       	exit (EXIT_FAILURE);
	   	}
	structure *ekr=new structure();
		
	ekr->cal_scale(XSIZE,50);
	ekr->cal_points();
//	ekr->write_points();
	ekr->cal_squares();

//	
//	ekr->write_neiberhood();
    img = display_bmp(BMP2);
	ekr->crumble_squares(img);

//	ekr->write_squares();
	 
//	paint_rectangle(screen,ekr);
	ekr->cal_triangle();
	paint_triangle(screen,ekr);

 	SDL_UpdateRect(screen, 0, 0, 0, 0);
	SDL_Delay(8000);
 	SDL_Quit ();

	cout << "Tekst  ";
//	system("pause");
	
//	delete ekr;
  	return 0;
}
