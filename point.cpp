#include "point.h"

point::point(){
    state=0;
  	};
//--------------------------------------------------------------------------------------------  set
void point::set(int a,int b,int c){
	x=a;
	y=b;
	state=c;
}
//--------------------------------------------------------------------------------------------  set_xy
void point::set_xy(int a ,int b){
	 x=a;
	 y=b;
	 };
//--------------------------------------------------------------------------------------------  set_state
void point::set_state(int a){
	 state=a;
	 };
//--------------------------------------------------------------------------------------------  write
void point::write(){
	 std::cout<<"x: " << x <<" y: " << y << " s: "<< state << std::endl;
	 };
//--------------------------------------------------------------------------------------------  get_x
int point::get_x(){
	  return x;
	  };
//--------------------------------------------------------------------------------------------  get_y
int point::get_y(){
	  return y;
	  };
