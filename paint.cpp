#include "paint.h"


//--------------------------------------------------------------------------------------------------------------------------
void Wyswietl(const int filtr_w, const int filtr_h, const int filtr[],char *napis){

printf("%s",napis);
//SDL_SaveBMP (Splot (filtr_w, filtr_h, filtr), BMPTMP);
display_bmp (BMPTMP);

}

//--------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------

SDL_Surface *display_bmp(char *file_name){
 SDL_Surface *image=SDL_LoadBMP(file_name);

  if (!image )
     fprintf(stderr, "Couldn't load %s: %s\n", file_name, SDL_GetError());
  if(SDL_BlitSurface(image, NULL, screen, NULL) < 0)
     fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());

  SDL_UpdateRect(screen, 0, 0, image->w, image->h);
  //    SDL_FreeSurface(image);


  return image;
  }


bool Init (const char *header){
   if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return false;
    	}

    screen = SDL_SetVideoMode( XSIZE, YSIZE,BITS_PER_PIXEL, SDL_DOUBLEBUF | SDL_HWSURFACE ); // *changed*
    if ( !screen ) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return false;
		}



	return true;
	}


structure* Loop (void){


	structure *ekr=new structure();
//	genetic *pom;

 	img = display_bmp(BMP2);
 	SDL_Event event;      // Unia zawieraj¹ca struktury zdarzeñ
  	bool running = true;  // zmienna decyzyjna
  	bool drawing = false; // zmienna decyzyjna

  	while(running){
    	SDL_WaitEvent(&event); // czekamy na zdarzenie
    	if(SDL_MUSTLOCK(screen)) if(SDL_LockSurface(screen) < 0) exit(-1);

		switch(event.type){

			case SDL_KEYDOWN:
				 if(event.key.keysym.sym == SDLK_1) {
				 	 img = display_bmp(BMP2);
//	 	 	 	 	 gfxLine(screen, 20, 0, 20,100, 0x0000ff);
	 	 	 	 	 break;
	 	 	 	 	 }
	 	 	 	 if(event.key.keysym.sym == SDLK_2) {
	 	 	 	 	 SDL_SaveBMP (screen, BMPTMP);
				 	 break;
	 	 	 	 	 }

			case SDL_QUIT:
				 running = false;
				 break;

			case SDL_MOUSEBUTTONDOWN:
				if(event.button.button == SDL_BUTTON_LEFT){
//                	if( gfxGetPixel(screen,  event.button.x,  event.button.y)!= 0x0000ff &&
//						gfxGetPixel(screen,  event.button.x,  event.button.y)!= 0x000000)



				//		ekr = doit();
//						cout << ekr->size_tr() <<"     -->"<<endl;
//						ekr = gfxFloodFill(screen, event.button.x,event.button.y, 0x0000ff);
// 						ekr->set_state(0);
//						ekr->change_state(10);

///						cout << ekr->size_tr() <<"     -->"<<endl;

 					 //	gfxPartFill(screen,*ekr);

//						pom=new genetic(*ekr,100,10,ekr->size_t());
					//	redraw(ekr);


//						gfxPointFill(screen,*ekr);

						drawing = true;
 					}

                             /*
							    else if(event.button.button == SDL_BUTTON_RIGHT)
                                {
                                  SDL_FillRect(screen, NULL, 0);
                                  drawing = false;
                                }
                                break;
      case SDL_MOUSEBUTTONUP:   drawing = false;
                                break;
      case SDL_MOUSEMOTION:     if(drawing) gfxLineTo(screen, event.motion.x, event.motion.y, 0xffffff);
                                break;
							*/
 		}
    	if(SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
    	SDL_UpdateRect(screen, 0, 0, 0, 0);
		}

	return ekr;

	}

//--------------------------------------------------------------------------------------------  paint_rectangle
void paint_rectangle(SDL_Surface *screen,structure *data){
 
	int size = data->get_square_size();
	vector <int> points ;
	points.reserve (100);
	
	for(int i=0;i<size;i++){
       	points=data->get_square(i);
      	gfxRectangle(screen, points.at(0), points.at(1),points.at(2), points.at(3),points.at(4),
					points.at(5), points.at(6), points.at(7), 0xffffff);
					
//		SDL_Delay(200);
//		SDL_UpdateRect(screen, 0, 0, 0, 0);
  
	}
}
