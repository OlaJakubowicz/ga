#include <vector>
#include <iostream>

class point{
	  private:
	  		 int x,y,state;
	  public:
			  point();

			  void set_xy(int,int);
			  void set_state(int);
			  void set(int,int,int);
			  void mod_xy();
			  int ret_x();
			  int ret_y();
			  int ret_state();
			  void write();
	  };
