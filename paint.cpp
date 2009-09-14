#include "paint.h"


//--------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------
Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
  int bpp = surface->format->BytesPerPixel;
  Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

  switch(bpp) {
  case 1:
    return *p;

  case 2:
    return *(Uint16 *)p;

  case 3:
       // obsÅ‚ugujemy wpisywanie barw w standardach RGB i BGR
    if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
      return p[0] << 16 | p[1] << 8 | p[2];
    else
      return p[0] | p[1] << 8 | p[2] << 16;

  case 4:
    return *(Uint32 *)p;

  default:
    return 0;
  }
}
//-------------------------------------------------------------------------------
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  int bpp = surface->format->BytesPerPixel;
  Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

  switch(bpp) {
  case 1:
    *p = pixel;
    break;

  case 2:
    *(Uint16 *)p = pixel;
    break;

  case 3:
    if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
      p[0] = (pixel >> 16) & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = pixel & 0xff;
    } else {
      p[0] = pixel & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = (pixel >> 16) & 0xff;
    }
    break;

  case 4:
    *(Uint32 *)p = pixel;
    break;
  }
}

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

/*
void redraw(structure* ekr){
	int x1,x2,x3,y1,y2,y3;
//						triangle temp;
/*
						for(int i=0;i<ekr->size_tr();i++){

							temp=*ekr->ret_tr(i);

							x1=ekr->ret_p_x(temp.ret_ver(1));
							x2=ekr->ret_p_x(temp.ret_ver(2));
							x3=ekr->ret_p_x(temp.ret_ver(3));

							y1=ekr->ret_p_y(temp.ret_ver(1));
							y2=ekr->ret_p_y(temp.ret_ver(2));
							y3=ekr->ret_p_y(temp.ret_ver(3));

							gfxTriangle(screen, x1, x2,x3, y1,y2,y3);

							}

//gfxTriangle(SDL_Surface * screen,  Sint32 x1, Sint32 x2,Sint32 x3,Sint32  y1,Sint32 y2,Sint32 y3, Uint32 color){

}*/

//--------------------------------------------------------------------------------------------  paint_rectangle
void paint_rectangle(SDL_Surface *screen,structure *data){
 
	int size = data->get_square_size();
	cout << size << "  ";

	
	vector <int> tab_point ;
	tab_point.reserve (100);
	//tab_point.clear();
	data->get_square(20);

//		cout << points.size() << "  ";

/*
		for(int j=0;j<points.size();j++){
			cout << points.at(j) << "  ";
		}
			cout << endl;
*/

/*

	for(int i=0;i<size;i++){
       points=temp->get_square(i);
 //       cout << points.at(0)<< "  " << points.at(1)<< "  " <<points.at(2)<< "  " << points.at(3) << "  " << endl;
//        gfxLine(screen, points.at(0), points.at(1),points.at(2), points.at(3), 0xffffff);

/*      gfxRectangle(screen, points.at(0), points.at(1),points.at(2), points.at(3),points.at(4),
					points.at(5), points.at(6), points.at(7), 0xffffff);

		for(int j=0;j<points.size();j++){
			cout << points.at(j) << "  ";
		}
			cout << endl;

	}
*/
//gfxPlot(screen);
}
