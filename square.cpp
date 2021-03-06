#include "square.h"


//--------------------------------------------------------------------------------------------  konstruktor
square::square(){
    points = new point[4];
    neiberhood = new int[4];
    depth=0;
}
//--------------------------------------------------------------------------------------------  set_square
void square::set_square(point up,point lp,point dp,point rp){
    points[0]=up;
    points[1]=lp;
    points[2]=dp;
	points[3]=rp;
}
//--------------------------------------------------------------------------------------------  set_neiberhood
void square::set_neiberhood(int un,int ln,int dn,int rn){
    neiberhood[0]=un;
    neiberhood[1]=ln;
    neiberhood[2]=dn;
	neiberhood[3]=rn;
}
//--------------------------------------------------------------------------------------------  write_square
void square::write_square(){
 	points[0].write();
    points[1].write();
    points[2].write();
	points[3].write();
	
	std::cout<<"  "<<std::endl;
}
//--------------------------------------------------------------------------------------------  write_neiberhood
void square::write_neiberhood(){

    std::cout<<" 1: " << neiberhood[0] <<" 2: " << neiberhood[1] << " 3: "<< neiberhood[2] << " 4: "<< neiberhood[3] << std::endl;
	std::cout<<"  "<<std::endl;
}
//--------------------------------------------------------------------------------------------  get_points
vector <int> square::get_points(void){
    vector <int> temp;
    temp.reserve(8);
    
    for(int i=0;i<4;i++){
    	temp.push_back(points[i].get_x());
    	temp.push_back(points[i].get_y());
	}
	return temp;
}
//--------------------------------------------------------------------------------------------  get_neiberhood
vector <int> square::get_neiberhood(void){
 	vector <int> temp;
    temp.reserve(4);

    for(int i=0;i<4;i++){
    	temp.push_back(neiberhood[i]);
	}
	return temp;
}
//--------------------------------------------------------------------------------------------  get_depth
int square::get_depth(){
	return depth;
}
//--------------------------------------------------------------------------------------------  set_depth
void square::set_depth(int a){
    depth=depth+a;
}
//--------------------------------------------------------------------------------------------  get_point
vector <point > square::get_point(void){
    vector <point > temp;
    temp.reserve(4);

    for(int i=0;i<4;i++){
    	temp.push_back(points[i]);
	}
	return temp;
}
