#include <vector>
#include <iostream>

#include "SDL_gfx.h"

#include "square.h"


#define CONST 32768


using namespace std;

class structure{
    private:
    	vector <square> grid_in;
    	vector <point> point_in;
    	vector <triangle> triangle_in;
    	int scale,count,depth;
    	
	public:
        structure();
        void cal_scale(int,int);
        void cal_points(void);
        void cal_squares(void);
        void write_points(void);
        void write_squares(void);
        void write_neiberhood(void);
        void crumble_squares(SDL_Surface *);
        void cal_triangle(void);

        vector <int> get_square(int);
        vector <int> get_triangle(int);
        int get_square_size();
        int get_point_size();
        int get_triangle_size();

	};
