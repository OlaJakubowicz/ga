#include "structure.h"

//--------------------------------------------------------------------------------------------  konstruktor
structure::structure(){
	depth=1;

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
	cout <<"count "<< count << endl ;
}
//--------------------------------------------------------------------------------------------  cal_points
void structure::cal_points(){
    point *temp=new point();

	for(int y=0;y<count+1;y++){
        for(int x=0;x<count+1;x++){
			if(x==0 || x==count || y==0 ||y==count)
			    temp->set_state(1);
			else
			    temp->set_state(0);
			
			temp->set_xy(x*scale,y*scale);
            point_in.push_back(*temp);
		}
	}
	cout <<"size "<< point_in.size() << endl ;
}
//--------------------------------------------------------------------------------------------  cal_square
void structure::cal_squares(){
    square *temp;
    
    int aa=count+1,wsk=1;
    bool first=true;
    while(wsk < (point_in.size()-count-2)){
	    temp =new square();
	    temp->set_square(point_in.at(wsk-1),point_in.at(wsk),point_in.at(wsk+count+1),point_in.at(wsk+count));
	    grid_in.push_back(*temp);
        delete temp;

  		wsk++;
    	if( wsk % aa == 0) wsk++;
	}

	int a,b,c,d;
	for(int i=1;i<grid_in.size()+1;i++){
		if(i-1<count)
			a=CONST;
		else
			a=i-count-1;

		if(i%(count)==0 && i!=0)
			b=CONST;
		else
			b=i;

		if(i>grid_in.size()-count)
			c=CONST;
		else
			c=i+count-1;

		if(i%(count)==1 || i==1)
			d=CONST;
		else
			d=i-2;

        grid_in.at(i-1).set_neiberhood(a,b,c,d);
	}
    delete temp;

}
//--------------------------------------------------------------------------------------------  write_points
void structure::write_points(){

	for(int x=0;x<point_in.size();x++){
      point_in.at(x).write();
	}
}

//--------------------------------------------------------------------------------------------  write_squares
void structure::write_squares(){

	for(int x=0;x<grid_in.size();x++){
      grid_in.at(x).write_square();
	}
}
//--------------------------------------------------------------------------------------------  write_neiberhood
void structure::write_neiberhood(){

	for(int x=0;x<grid_in.size();x++){
	  std::cout<<x;
      grid_in.at(x).write_neiberhood();
	}
}
//--------------------------------------------------------------------------------------------  get_square
vector <int> structure::get_square(int x){
    vector <int> tab(grid_in.at(x).get_points());
	return tab;
}
//--------------------------------------------------------------------------------------------  get_square_size
int structure::get_square_size(){
	return grid_in.size();
}
//--------------------------------------------------------------------------------------------  crumble_squares
void structure::crumble_squares(SDL_Surface *s){

 	Uint32 a,b,c,d;
 	square *temp_sq;
 	point *temp;

	for(int i=0;i<grid_in.size();i++){
		if( grid_in.at(i).get_depth()<depth){
             vector <int> tab(grid_in.at(i).get_points());
   			 a= getpixel(s, tab.at(0),tab.at(1));
   			 b= getpixel(s, tab.at(2),tab.at(3));
   			 c= getpixel(s, tab.at(4),tab.at(5));
   			 d= getpixel(s, tab.at(6),tab.at(7));
   			 
   			if(a==b && b==c && c==d){ }
			//	 std::cout<<i <<std::endl;	}
   			else{
//                std::cout<<(int)a <<"  "<<(int) b <<"  "<<(int) c <<"  "<<(int) d <<std::endl;
                
                int size =point_in.size();
	            vector <point> old_point=grid_in.at(i).get_point();
	            vector <int> old_neiberhood=grid_in.at(i).get_neiberhood();
	           
                temp=new point();
                temp->set_state(0);
                temp->set_xy(tab.at(0)+(tab.at(2)-tab.at(0))/2,tab.at(1));
                point_in.push_back(*temp);
                delete temp;
                

                temp=new point();
                temp->set_state(0);
				temp->set_xy(tab.at(0),tab.at(1)+(tab.at(5)-tab.at(1))/2);
                point_in.push_back(*temp);
                delete temp;

                temp=new point();
                temp->set_state(0);
				temp->set_xy(tab.at(0)+(tab.at(2)-tab.at(0))/2,tab.at(1)+(tab.at(5)-tab.at(1))/2);
                point_in.push_back(*temp);
                delete temp;
                
                temp=new point();
                temp->set_state(0);
				temp->set_xy(tab.at(2),tab.at(1)+(tab.at(5)-tab.at(1))/2);
                point_in.push_back(*temp);
                delete temp;
                
                temp=new point();
                temp->set_state(0);
				temp->set_xy(tab.at(0)+(tab.at(2)-tab.at(0))/2,tab.at(5));
                point_in.push_back(*temp);
                delete temp;

               grid_in.at(i).set_square(old_point.at(0),point_in.at(size),point_in.at(size+2),point_in.at(size+1));
               grid_in.at(i).set_neiberhood(old_neiberhood.at(0),size,size+1,old_neiberhood.at(3));
               grid_in.at(i).set_depth(1);

               temp_sq =new square();
			   temp_sq->set_square(point_in.at(size),old_point.at(1),point_in.at(size+3),point_in.at(size+2));
			   temp_sq->set_neiberhood(old_neiberhood.at(0),old_neiberhood.at(1),size+2,i);
			   temp_sq->set_depth(1);
			   grid_in.push_back(*temp_sq);
		    	delete temp_sq;
    
               temp_sq =new square();
			   temp_sq->set_square(point_in.at(size+1),point_in.at(size+2),point_in.at(size+4),old_point.at(3));
			   temp_sq->set_neiberhood(i,size+2,old_neiberhood.at(2),old_neiberhood.at(3));
			   temp_sq->set_depth(1);
			   grid_in.push_back(*temp_sq);
			   
//				grid_in.at(i).write_square();
//			   temp_sq->write_square();
		    	delete temp_sq;

               temp_sq =new square();
			   temp_sq->set_square(point_in.at(size+2),point_in.at(size+3),old_point.at(2),point_in.at(size+4));
			   temp_sq->set_neiberhood(size,old_neiberhood.at(1),old_neiberhood.at(2),size+1);
			   temp_sq->set_depth(1);
			   grid_in.push_back(*temp_sq);
		    	delete temp_sq;
		  
		    	
			}
		}
	}
	
}
