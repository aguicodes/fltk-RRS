#include "FL/Fl.H" 
// Include each “widget” you use
#include "FL/Fl_Window.H"
#include "FL/Fl_Box.H"

int main() {

        // Create a window // Create a window
        Creating a Callback
        Fl_Window *win = new Fl_Window{640,120,"Callback Demo"};
        // Sign up for callback // Sign up for callback
        win->callback(CloseCB);

        // Create our custom box and draw the turtel's path
        Fl_Box *box = new Fl_Box{0,0,640,120, "Now with annoying prompts!"};
        box->box(FL_UP_BOX); box->box(FL_UP_BOX);
        box->labelfont(FL_BOLD+FL_ITALIC); 
        box->labelsize(36); 
        box->labeltype(FL_SHADOW_LABEL);
        // Enable resizing
        win->resizable(*box);
        // Wrap it up and let FLTK do its thing
        win->end(); 
        win->show();
        return(Fl::run());
}
