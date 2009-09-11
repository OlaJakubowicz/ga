#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "structure.h"


//--------------------------------------------------------------------------------------------  konstruktor
structure::structure(){

}
//--------------------------------------------------------------------------------------------  cal_scale
void structure::cal_scale(int size, int pro_size){
	double rest=size % pro_size;
	count=size / pro_size;

	if(rest > pro_size/2){
        count++;
        scale=size/count;
	}
	else{
         scale=size/count;
	}
	
	
	cout <<"scale "<< scale << endl ;
	cout <<"temp "<< count << endl ;
}
//--------------------------------------------------------------------------------------------  cal_points
void structure::cal_points(){
    point *temp=new point();

	for(int x=0;x<count+1;x++){
        for(int y=0;y<count+1;y++){
			if(x==0 || x==count || y==0 ||y==count)
			    temp->set_state(1);
			else
			    temp->set_state(0);
			
			temp->set_xy(x*scale,y*scale);
            point_in.push_back(*temp);
		}
	}
}
//--------------------------------------------------------------------------------------------  cal_square
void structure::cal_squares(){
    square *temp =new square();
    
    int wsk=1;
    for(int x=0;x<count;x++){
        for(int y=0;y<count;y++){
            temp->set_square(point_in.at(wsk),point_in.at(wsk+1),point_in.at(wsk+count),point_in.at(wsk+count+1));
/*
             	point_in.at(wsk).write();
			    point_in.at(wsk+1).write();
			    point_in.at(wsk+count).write();
				point_in.at(wsk+count+1).write();

				std::cout<<" " << wsk  <<std::endl;
				std::cout<<"  "<<std::endl;
	*/
	        temp->write_square();
            grid_in.push_back(temp);
            wsk++;
		}
	}
/*
	wsk=1;
	int a,b,c,d;
	for(int i=1;i<grid_in.size();i++){
		if(i<count)
			a=0;
		else
			a=i-count;


		if(i>grid_in.size()-count)
			d=0;
		else
			d=i+count;

	}
*/
}
//--------------------------------------------------------------------------------------------  write_points
void structure::write_points(){

	for(int x=1;x<point_in.size();x++){
      point_in.at(x).write();
	}
}

//--------------------------------------------------------------------------------------------  write_squares
void structure::write_squares(){

	for(int x=1;x<grid_in.size();x++){
      grid_in.at(x)->write_square();
	}
}