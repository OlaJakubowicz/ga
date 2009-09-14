#include <vector>
#include <iostream>

#include "point.h"

using namespace std;

class square{
    private:
    	point *points;              // UP,LEFT,DOWN,RIGHT
    	int *neiberhood;            // UP,LEFT,DOWN,RIGHT
    	
	public:
        square();
	    void set_square(point,point,point,point );
	    void set_neiberhood(int,int,int,int);
	    void write_square(void);
	    void write_neiberhood(void);

		vector <int> get_points(void);
	    

};
