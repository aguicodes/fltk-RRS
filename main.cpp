#include "main.h"
#include "view.h"
#include "Models.h"
#include "Parts.h"
    

int main(){
    
    Fl_Window *win = new Fl_Window(740, 580, "Robbie Robot Shop");
    
    Fl_Box *box = new Fl_Box (120,60,480,100, "Welcome to RRS Shop!");
    
    box->box(FL_ROUND_UP_BOX);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);
    
    char* option_one = "Product Manager";
    char* option_two = "Customer";
    
    Fl_Button* button_one = new Fl_Button (180,340,140,50, option_one);
    button_one->when(FL_WHEN_RELEASE);
    button_one->callback(ButtonCB, option_one);
    
    
    Fl_Button* button_two = new Fl_Button (380,340,140,50, option_two);
    button_two->when(FL_WHEN_RELEASE);
    button_two->callback(ButtonCB, option_two);
    
    
    win->end();
    win->show();
    
    return Fl::run();
}

