#include "view.h"
#include "main.h"
#include "Parts.h"
#include "Models.h"

void ButtonSecCB(Fl_Widget* w, void* p){
    
    Fl_Button *b = (Fl_Button*)w;
    
    if (!strcmp((char*)p, "Create Robot Parts")){
        
        Parts parts;
    }
    
    if (!strcmp((char*)p, "Create Robot Models")){
        
        Models models;
    }
    
}

void ButtonCB(Fl_Widget* w, void* p){
    
    Fl_Button *b = (Fl_Button*)w;
    
    if (!strcmp((char*)p, "Product Manager")){
        
        Fl_Window *win = new Fl_Window(740, 580, "Robbie Robot Shop");
        
        Fl_Box *box = new Fl_Box (120,60,480,100, "Hello Product Manager!");
        
        box->box(FL_ROUND_UP_BOX);
        box->labelfont(FL_BOLD+FL_ITALIC);
        box->labelsize(36);
        box->labeltype(FL_SHADOW_LABEL);
        
        char* option_one = "Create Robot Models";
        char* option_two = "View Robot Models";
        char* option_three = "Create Robot Parts";
        char* option_four = "View Robot Parts";
        
        Fl_Button* button_one = new Fl_Button (180,400,140,50, option_one);
        button_one->when(FL_WHEN_RELEASE);
        button_one->callback(ButtonSecCB, option_one);
        
        Fl_Button* button_two = new Fl_Button (380,400,140,50, option_two);
        button_two->when(FL_WHEN_RELEASE);
        button_two->callback(ButtonSecCB, option_two);
        
        Fl_Button* button_three = new Fl_Button (180,240,140,50, option_three);
        button_three->when(FL_WHEN_RELEASE);
        button_three->callback(ButtonSecCB, option_three);
        
        Fl_Button* button_four = new Fl_Button (380,240,140,50, option_four);
        button_four->when(FL_WHEN_RELEASE);
        button_four->callback(ButtonSecCB, option_four);
        
        win->end();
        win->show();
        
        
    }
    
    else{
        
        Fl_Window *win = new Fl_Window(740, 580, "Robbie Robot Shop");
        
        Fl_Box *box = new Fl_Box (120,60,480,100, "Welcome Customer!");
        
        box->box(FL_ROUND_UP_BOX);
        box->labelfont(FL_BOLD+FL_ITALIC);
        box->labelsize(36);
        box->labeltype(FL_SHADOW_LABEL);
        
        char* option_five = "View Robot Models";
        char* option_six = "View your Orders";
        char* option_seven = "View Robot Parts";
        char* option_eight = "Create an Order";
        
        Fl_Button* button_five = new Fl_Button (180,400,140,50, option_five);
        button_five->when(FL_WHEN_RELEASE);
        button_five->callback(ButtonSecCB, option_five);
        
        Fl_Button* button_six = new Fl_Button (380,400,140,50, option_six);
        button_six->when(FL_WHEN_RELEASE);
        button_six->callback(ButtonSecCB, option_six);
        
        Fl_Button* button_seven = new Fl_Button (180,240,140,50, option_seven);
        button_seven->when(FL_WHEN_RELEASE);
        button_seven->callback(ButtonSecCB, option_seven);
        
        Fl_Button* button_eight = new Fl_Button (380,240,140,50, option_eight);
        button_eight->when(FL_WHEN_RELEASE);
        button_eight->callback(ButtonSecCB, option_eight);
        
        win->end();
        win->show();
        
        
    }
}

