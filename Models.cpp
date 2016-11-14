
#include "Models.h"
#include "main.h"
#include "view.h"

Models::Models(){
    
    Fl_Window *win = new Fl_Window(740, 580, "Robbie Robot Shop");
    
    Fl_Box *box = new Fl_Box (120,60,480,100, "Let's create some models!");
    
    box->box(FL_ROUND_UP_BOX);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);
    
    /*char* option_one = "Arm";
     char* option_two = "head";
     char* option_three = "Torso";
     char* option_four = "locomotor";
     char* option_five = "locomotor";
     
     Fl_Button* button_one = new Fl_Button (180,400,140,50, option_one);
     button_one->when(FL_WHEN_RELEASE);
     button_one->callback(ButtonCB, option_one);
     
     Fl_Button* button_two = new Fl_Button (380,400,140,50, option_two);
     button_two->when(FL_WHEN_RELEASE);
     button_two->callback(ButtonCB, option_two);
     
     Fl_Button* button_three = new Fl_Button (180,240,140,50, option_three);
     button_three->when(FL_WHEN_RELEASE);
     button_three->callback(ButtonCB, option_three);
     
     Fl_Button* button_four = new Fl_Button (380,240,140,50, option_four);
     button_four->when(FL_WHEN_RELEASE);
     button_four->callback(ButtonCB, option_four);*/
    
    win->end();
    win->show();
    
}
