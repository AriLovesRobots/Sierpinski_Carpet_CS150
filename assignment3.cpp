
#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <string>
#include <sstream>
//sierpinski carpet
//calculates for given depth I guess?
//stops calculation when recursion depth becomes zero!
//one recursion call calculates one square!




using namespace std;


struct Carpet_window:Simple_window{
           

       Carpet_window(Point pp, int ww, int hh, const string& carpet_title)
             :Simple_window(Point(300,400), 200, 300, "Sierpinski carpet"),
             depth_in(Point(20,0), 20, 10, "Depth input"),
             rect(Point(500,50),900, 900),
             dots("."),
             end_label(Point(500, 960), text_string.str()),
             depth_box_button(Point(40,0), 20, 10, "New depth",cb_update) //watch out for this, no callback!                         

             {
                text_string<<"Recursive Sierpinski carpet points: "<<dots.number_of_points();
                end_label.set_font_size(10);
                attach(depth_in);
                attach(rect);
                attach(dots); 
                attach(end_label);
                attach(depth_box_button);
             }
             
             


    void add_carpets(int left, int top, int size, int depth);
    
    void update_depth();
    
    static void cb_update(Address, Address pw); 

    Marks dots;


    private:
       In_box depth_in;

       Button depth_box_button; 
        
       Rectangle rect;
       

       stringstream text_string;
       
       Text end_label;
          




};



//remember: left = x, top = y point coords of the top left part of square that is being calculated
//also remember that each recursion responds to different coordinates!
void Carpet_window::add_carpets(int left, int top, int size, int depth){
        
     if( depth == 0) return;  //ending point for recursive function    
     else{  
       
        Point center(left + size/2,top + size/2 ); 
        dots.add(center);     
        
         
        for(int i = 0; i<3; i++){
              for(int j = 0; j<3; j++){
                  
                 if (i == 1 && j == 1)continue;    //middle square position
                 else{
                int new_size = size/3;                   
                int new_left = left + j*new_size;                      
                int new_top =  top + i*new_size;
                

                Carpet_window::add_carpets(new_left, new_top, new_size, depth-1);
                
                Point center(new_left + new_size/2,new_top + new_size/2 ); 
                dots.add(center);

                
                }
            }  
        }


     }
    
}



void Carpet_window::update_depth(){
      
    int new_depth = depth_in.get_int(); 
    
    Marks dots(".");

    add_carpets(500, 50, 900, new_depth);
    
    redraw();
} 


void Carpet_window::cb_update(Address, Address pw){
  
      reference_to<Carpet_window>(pw).update_depth();
}


int main(){
try{

    Carpet_window win(Point(300, 400),200, 300, "Sierpinski carpet" );

    //defining our starting point with this Rectangle object, just for reference! 

    //int depth;
    //cout<<"Enter depth of Sierpinski carpet\n";
    //cin>>depth;
    //if (!cin) error("Failed to take depth!");
        
    //win.add_carpets(500, 50, 900, depth);
    
    
    


    win.wait_for_button();  
  }catch(exception& e){
     
    return 1;
      
  }
  catch(...){

    return 2;
  }

}


