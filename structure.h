#include <vector>
#include <iostream>

#include "square.h"

using namespace std;

class structure{
    private:
    	vector <square> grid_in;
    	vector <point> point_in;
    	int scale,count;
    	
	public:
        structure();
        void cal_scale(int,int);
        void cal_points(void);
        void cal_squares(void);
        void write_points(void);
        void write_squares(void);
        void write_neiberhood(void);

	};
