
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Widget.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Check_Button.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Float_Input.H"
#include "FL/Fl_Int_Input.H"
#include "FL/Fl_Menu_Bar.H"
#include "FL/Fl_Return_Button.H"
#include "FL/Fl_Multiline_Input.H"

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>


using namespace std;

class Head *robot_head_dlg;
class Arm *robot_arm_dlg;
class Torso *robot_torso_dlg;
class Locomotor *robot_loco_dlg;
class Battery *robot_batt_dlg;

void CreatePartCB(Fl_Widget* w, void* p);
void cancel_robot_headCB(Fl_Widget* w, void* p);
void create_robot_headCB(Fl_Widget* w, void* p);
void cancel_robot_armCB(Fl_Widget* w, void* p);
void create_robot_armCB(Fl_Widget* w, void* p);
void cancel_robot_torsoCB(Fl_Widget* w, void* p);
void create_robot_torsoCB(Fl_Widget* w, void* p);
void cancel_robot_locoCB(Fl_Widget* w, void* p);
void create_robot_locoCB(Fl_Widget* w, void* p);
void cancel_robot_battCB(Fl_Widget* w, void* p);
void create_robot_battCB(Fl_Widget* w, void* p);
void ButtonSecCB(Fl_Widget* w, void* p);
void ButtonCB(Fl_Widget* w, void* p);

class Head{
    public:

        Head(){
            
            dialog = new Fl_Window (340, 270, "Head part");
            
            rp_name = new Fl_Input (120, 10, 210, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
            
            rp_part_number = new Fl_Input (120, 40, 210, 25, "Part Number: ");
            rp_part_number->align (FL_ALIGN_LEFT);
            
            
            rp_weight = new Fl_Input (120, 70, 210, 25, "Weight: ");
            rp_weight->align (FL_ALIGN_LEFT);
    
            
            rp_cost = new Fl_Float_Input (120, 100, 210, 25, "Cost: ");
            rp_cost->align (FL_ALIGN_LEFT);
            
            rp_description = new Fl_Multiline_Input (120, 160, 210, 75, "Description: ");
            rp_description->align (FL_ALIGN_LEFT);
            
            rp_create = new Fl_Return_Button (145, 240, 120, 25, "Create");
            rp_create->callback (create_robot_headCB, 0);
            
            rp_cancel = new Fl_Button (270, 240, 60, 25, "Cancel");
            rp_cancel->callback (cancel_robot_headCB, 0);
            
            dialog->end();
            dialog->set_non_modal();
        }

    
        void show () {dialog->show();}
        void hide () {dialog->hide();}
        string name() {return rp_name->value();}
        string part_number() {return rp_part_number->value();}
        string weight() {return rp_weight->value();}
        string cost() {return rp_cost->value();}
        string description() {return rp_description->value();}
   
    private:
    
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_weight;
        Fl_Float_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
    
    
};

class Arm{
    
    public:
    
        Arm(){
            
            dialog = new Fl_Window (480, 320, "Arm part");
            
            rp_name = new Fl_Input (160, 10, 310, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
            
            rp_part_number = new Fl_Input (160, 40, 310, 25, "Part Number: ");
            rp_part_number->align (FL_ALIGN_LEFT);
            
            rp_power = new Fl_Input (160, 70, 310, 25, "Power (in Watts): ");
            rp_power->align (FL_ALIGN_LEFT);
            
            
            rp_weight = new Fl_Input (160, 100, 310, 25, "Weight: ");
            rp_weight->align (FL_ALIGN_LEFT);
            
            
            rp_cost = new Fl_Float_Input (160, 130, 310, 25, "Cost: ");
            rp_cost->align (FL_ALIGN_LEFT);
            
            rp_description = new Fl_Multiline_Input (160, 190, 310, 75, "Description: ");
            rp_description->align (FL_ALIGN_LEFT);
            
            rp_create = new Fl_Return_Button (265, 280, 120, 25, "Create");
            rp_create->callback (create_robot_armCB, 0);
            
            rp_cancel = new Fl_Button (400, 280, 60, 25, "Cancel");
            rp_cancel->callback (cancel_robot_armCB, 0);
            
            dialog->end();
            dialog->set_non_modal();
        
        }
    
        void show () {dialog->show();}
        void hide () {dialog->hide();}
        string name() {return rp_name->value();}
        string part_number() {return rp_part_number->value();}
        string weight() {return rp_weight->value();}
        string cost() {return rp_cost->value();}
        string description() {return rp_description->value();}
        string power() {return rp_power->value();}
    
    
    private:
    
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_weight;
        Fl_Float_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Input *rp_power;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
    
    
};

class Torso{
    
    public:
    
        Torso(){
        
            dialog = new Fl_Window (480, 320, "Torso part");
        
            rp_name = new Fl_Input (160, 10, 310, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
        
            rp_part_number = new Fl_Input (160, 40, 310, 25, "Part Number: ");
            rp_part_number->align (FL_ALIGN_LEFT);
        
            rp_amount = new Fl_Int_Input (160, 70, 310, 25, "Battery Amount: ");
            rp_amount->align (FL_ALIGN_LEFT);
        
        
            rp_weight = new Fl_Input (160, 100, 310, 25, "Weight: ");
            rp_weight->align (FL_ALIGN_LEFT);
        
        
            rp_cost = new Fl_Float_Input (160, 130, 310, 25, "Cost: ");
            rp_cost->align (FL_ALIGN_LEFT);
        
            rp_description = new Fl_Multiline_Input (160, 190, 310, 75, "Description: ");
            rp_description->align (FL_ALIGN_LEFT);
        
            rp_create = new Fl_Return_Button (265, 280, 120, 25, "Create");
            rp_create->callback (create_robot_torsoCB, 0);
        
            rp_cancel = new Fl_Button (400, 280, 60, 25, "Cancel");
            rp_cancel->callback (cancel_robot_torsoCB, 0);
        
            dialog->end();
            dialog->set_non_modal();
            
        }
    
        void show () {dialog->show();}
        void hide () {dialog->hide();}
        string name() {return rp_name->value();}
        string part_number() {return rp_part_number->value();}
        string weight() {return rp_weight->value();}
        string cost() {return rp_cost->value();}
        string description() {return rp_description->value();}
        string amount() {return rp_amount->value();}
    
    
    private:
    
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_weight;
        Fl_Float_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Int_Input  *rp_amount;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
    
};

class Locomotor{
    
    public:
    
        Locomotor(){
        
            dialog = new Fl_Window (480, 340, "Locomotor part");
        
            rp_name = new Fl_Input (160, 10, 310, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
        
            rp_part_number = new Fl_Input (160, 40, 310, 25, "Part Number: ");
            rp_part_number->align (FL_ALIGN_LEFT);
            
            rp_power = new Fl_Input (160, 70, 310, 25, "Power (in Watts): ");
            rp_power->align (FL_ALIGN_LEFT);
        
            rp_speed = new Fl_Input (160, 100, 310, 25, "Max Speed (in MPH): ");
            rp_speed->align (FL_ALIGN_LEFT);
        
        
            rp_weight = new Fl_Input (160, 130, 310, 25, "Weight: ");
            rp_weight->align (FL_ALIGN_LEFT);
        
        
            rp_cost = new Fl_Float_Input (160, 160, 310, 25, "Cost: ");
            rp_cost->align (FL_ALIGN_LEFT);
        
            rp_description = new Fl_Multiline_Input (160, 220, 310, 75, "Description: ");
            rp_description->align (FL_ALIGN_LEFT);
        
            rp_create = new Fl_Return_Button (265, 305, 120, 25, "Create");
            rp_create->callback (create_robot_locoCB, 0);
        
            rp_cancel = new Fl_Button (400, 305, 60, 25, "Cancel");
            rp_cancel->callback (cancel_robot_locoCB, 0);
        
            dialog->end();
            dialog->set_non_modal();
        
        }
    
        void show () {dialog->show();}
        void hide () {dialog->hide();}
        string name() {return rp_name->value();}
        string part_number() {return rp_part_number->value();}
        string weight() {return rp_weight->value();}
        string cost() {return rp_cost->value();}
        string description() {return rp_description->value();}
        string speed() {return rp_speed->value();}
        string power() {return rp_power->value();}
    
    
    private:
    
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_weight;
        Fl_Float_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Input *rp_speed;
        Fl_Input *rp_power;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
    
};

class Battery{
    
    public:
    
        Battery(){
        
            dialog = new Fl_Window (480, 320, "Arm part");
        
            rp_name = new Fl_Input (160, 10, 310, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
        
            rp_part_number = new Fl_Input (160, 40, 310, 25, "Part Number: ");
            rp_part_number->align (FL_ALIGN_LEFT);
        
            rp_energy = new Fl_Input (160, 70, 310, 25, "Energy (KW/HRS): ");
            rp_energy->align (FL_ALIGN_LEFT);
    
        
            rp_weight = new Fl_Input (160, 100, 310, 25, "Weight: ");
            rp_weight->align (FL_ALIGN_LEFT);
        
        
            rp_cost = new Fl_Float_Input (160, 130, 310, 25, "Cost: ");
            rp_cost->align (FL_ALIGN_LEFT);
        
            rp_description = new Fl_Multiline_Input (160, 190, 310, 75, "Description: ");
            rp_description->align (FL_ALIGN_LEFT);
        
            rp_create = new Fl_Return_Button (265, 280, 120, 25, "Create");
            rp_create->callback (create_robot_armCB, 0);
        
            rp_cancel = new Fl_Button (400, 280, 60, 25, "Cancel");
            rp_cancel->callback (cancel_robot_armCB, 0);
        
            dialog->end();
            dialog->set_non_modal();
        
        }
    
        void show () {dialog->show();}
        void hide () {dialog->hide();}
        string name() {return rp_name->value();}
        string part_number() {return rp_part_number->value();}
        string weight() {return rp_weight->value();}
        string cost() {return rp_cost->value();}
        string description() {return rp_description->value();}
        string energy() {return rp_energy->value();}
    
    
    private:
    
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_part_number;
        Fl_Input *rp_weight;
        Fl_Float_Input *rp_cost;
        Fl_Input *rp_description;
        Fl_Input *rp_energy;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
    
    
};

class Parts{
    
    public:
    
        Parts(){
            
            Fl_Window *win = new Fl_Window(400, 330, "Robbie Robot Shop");
            
            Fl_Box *box = new Fl_Box (20,20,340,50, "Let's create some parts!");
            
            box->box(FL_EMBOSSED_BOX);
            box->labelfont(FL_BOLD+FL_ITALIC);
            box->labelsize(26);
            
            char* option_one = (char*) "Arm";
            char* option_two = (char*) "Head";
            char* option_three = (char*) "Torso";
            char* option_four = (char*) "Locomotor";
            char* option_five = (char*) "Battery";

            
            Fl_Check_Button* button_one = new Fl_Check_Button (40,80,140,50, option_one);
            button_one->when(FL_WHEN_RELEASE);
            button_one->callback(CreatePartCB, option_one);
            
            Fl_Check_Button* button_two = new Fl_Check_Button (40,120,140,50, option_two);
            button_two->when(FL_WHEN_RELEASE);
            button_two->callback(CreatePartCB, option_two);
            
            Fl_Check_Button* button_three = new Fl_Check_Button (40,160,140,50, option_three);
            button_three->when(FL_WHEN_RELEASE);
            button_three->callback(CreatePartCB, option_three);
            
            Fl_Check_Button* button_four = new Fl_Check_Button (40,200,140,50, option_four);
            button_four->when(FL_WHEN_RELEASE);
            button_four->callback(CreatePartCB, option_four);
            
            Fl_Check_Button* button_five = new Fl_Check_Button (40,240,140,50, option_five);
            button_five->when(FL_WHEN_RELEASE);
            button_five->callback(CreatePartCB, option_five);
            
            win->end();
            win->show();
            
        }
};


class Models{
    
public:
    
    Models(){
        
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
};


int main(){
    
    Fl_Window *win = new Fl_Window(500, 240, "Robbie Robot Shop");
    
    Fl_Box *box = new Fl_Box (80,30,300,50, "Welcome to RRS Shop!");
    
    box->box(FL_ROUND_UP_BOX);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labelsize(24);
    box->labeltype(FL_SHADOW_LABEL);
    
    char* option_one = (char*) "Product Manager";
    char* option_two = (char*) "Customer";
    
    Fl_Button* button_one = new Fl_Button (80,120,140,50, option_one);
    button_one->when(FL_WHEN_RELEASE);
    button_one->callback(ButtonCB, option_one);
    
    
    Fl_Button* button_two = new Fl_Button (240,120,140,50, option_two);
    button_two->when(FL_WHEN_RELEASE);
    button_two->callback(ButtonCB, option_two);
    
    
    win->end();
    win->show();
    
    return Fl::run();
}
void CreatePartCB(Fl_Widget* w, void* p){
    Fl_Button *b = (Fl_Button*)w;
    
    if (!strcmp((char*)p, "Arm")){
        robot_arm_dlg = new Arm;
        robot_arm_dlg->show();
    }
    else if (!strcmp((char*)p, "Head")){
        robot_head_dlg = new Head;
        robot_head_dlg->show();
    }
    else if (!strcmp((char*)p, "Locomotor")){
        robot_loco_dlg = new Locomotor;
        robot_loco_dlg->show();
    }
    else if (!strcmp((char*)p, "Torso")){
        robot_torso_dlg = new Torso;
        robot_torso_dlg->show();
    }
    else{
        robot_batt_dlg = new Battery;
        robot_batt_dlg->show();
    }
}
void create_robot_headCB(Fl_Widget* w, void* p){
    
    
    //cout << " ### Creating robot part" << endl;
    
    
    cout << "Name      :" << robot_head_dlg->name() << endl;
    cout << "Part #    :" << robot_head_dlg->part_number() << endl;
    cout << "Weight    :" << robot_head_dlg->weight() << endl;
    cout << "Cost      :" << robot_head_dlg->cost() << endl;
    cout << "Descrip   :" << robot_head_dlg->description() << endl;
    robot_head_dlg->hide();
    
}
void create_robot_armCB(Fl_Widget* w, void* p){
    
    
    cout << " ### Creating robot part" << endl;
    cout << "Name      :" << robot_arm_dlg->name() << endl;
    cout << "Part #    :" << robot_arm_dlg->part_number() << endl;
    cout << "Power     :" << robot_arm_dlg->power() << endl;
    cout << "Weight    :" << robot_arm_dlg->weight() << endl;
    cout << "Cost      :" << robot_arm_dlg->cost() << endl;
    cout << "Descrip   :" << robot_arm_dlg->description() << endl;
    robot_arm_dlg->hide();
    
}
void create_robot_torsoCB(Fl_Widget* w, void* p){
    
    
    cout << " ### Creating robot part" << endl;
    cout << "Name      :" << robot_torso_dlg->name() << endl;
    cout << "Part #    :" << robot_torso_dlg->part_number() << endl;
    cout << "Battery#  :" << robot_torso_dlg->amount() << endl;
    cout << "Weight    :" << robot_torso_dlg->weight() << endl;
    cout << "Cost      :" << robot_torso_dlg->cost() << endl;
    cout << "Descrip   :" << robot_torso_dlg->description() << endl;
    robot_torso_dlg->hide();
    
}
void create_robot_locoCB(Fl_Widget* w, void* p){
    
    
    cout << " ### Creating robot part" << endl;
    cout << "Name      :" << robot_loco_dlg->name() << endl;
    cout << "Part #    :" << robot_loco_dlg->part_number() << endl;
    cout << "Weight    :" << robot_loco_dlg->weight() << endl;
    cout << "Cost      :" << robot_loco_dlg->cost() << endl;
    cout << "Descrip   :" << robot_loco_dlg->description() << endl;
    robot_loco_dlg->hide();
    
}
void create_robot_battCB(Fl_Widget* w, void* p){
    
    
    cout << " ### Creating robot part" << endl;
    cout << "Name      :" << robot_batt_dlg->name() << endl;
    cout << "Part #    :" << robot_batt_dlg->part_number() << endl;
    cout << "Energy    :" << robot_batt_dlg->energy() << endl;
    cout << "Weight    :" << robot_batt_dlg->weight() << endl;
    cout << "Cost      :" << robot_batt_dlg->cost() << endl;
    cout << "Descrip   :" << robot_batt_dlg->description() << endl;
    robot_batt_dlg->hide();
    
}
void cancel_robot_headCB(Fl_Widget* w, void* p){
    robot_head_dlg->hide();
}
void cancel_robot_armCB(Fl_Widget* w, void* p){
    robot_arm_dlg->hide();
}
void cancel_robot_torsoCB(Fl_Widget* w, void* p){
    robot_torso_dlg->hide();
}
void cancel_robot_locoCB(Fl_Widget* w, void* p){
    robot_loco_dlg->hide();
}
void cancel_robot_battCB(Fl_Widget* w, void* p){
    robot_batt_dlg->hide();
}
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
        
        Fl_Window *win = new Fl_Window(640, 480, "Robbie Robot Shop");
        
        Fl_Box *box = new Fl_Box (80,40,440,60, "Hello Product Manager!");
        
        box->box(FL_PLASTIC_UP_BOX);
        box->labelfont(FL_BOLD+FL_ITALIC);
        box->labelsize(36);
        box->labeltype(FL_SHADOW_LABEL);
        
        Fl_Box *b = new Fl_Box (240,140,180,40, "Create");
        
        b->box(FL_EMBOSSED_BOX);
        b->labelfont(FL_ITALIC);
        b->labelsize(28);
        
        Fl_Box *bb = new Fl_Box (260,300,140,40, "View");
        
        bb->box(FL_EMBOSSED_BOX);
        bb->labelfont(FL_ITALIC);
        bb->labelsize(28);

        
        char* option_one = (char*) "Customers";
        char* option_two = (char*) "Create Sales Associate";
        char* option_three = (char*) "Create Robot Parts";
        char* option_four = (char*) "Create Robot Models";
        char* option_five = (char*) "Orders";
        char* option_six = (char*) "Associates";
        
        Fl_Button* button_one = new Fl_Button (440,370,140,50, option_one);
        button_one->when(FL_WHEN_RELEASE);
        button_one->callback(ButtonSecCB, option_one);
        
        Fl_Button* button_two = new Fl_Button (420,210,160,50, option_two);
        button_two->when(FL_WHEN_RELEASE);
        button_two->callback(ButtonSecCB, option_two);
        
        Fl_Button* button_three = new Fl_Button (40,210,140,50, option_three);
        button_three->when(FL_WHEN_RELEASE);
        button_three->callback(ButtonSecCB, option_three);
        
        Fl_Button* button_four = new Fl_Button (220,210,150,50, option_four);
        button_four->when(FL_WHEN_RELEASE);
        button_four->callback(ButtonSecCB, option_four);
        
        Fl_Button* button_five = new Fl_Button (40,370,140,50, option_five);
        button_one->when(FL_WHEN_RELEASE);
        button_one->callback(ButtonSecCB, option_five);
        
        Fl_Button* button_six = new Fl_Button (220,370,140,50, option_six);
        button_one->when(FL_WHEN_RELEASE);
        button_one->callback(ButtonSecCB, option_six);
        
        win->end();
        win->show();
        
        
    }
    
    else{
        
        Fl_Window *win = new Fl_Window(480, 380, "Robbie Robot Shop");
        
        Fl_Box *box = new Fl_Box (50,40,380,50, "Welcome Customer!");
        
        box->box(FL_PLASTIC_UP_BOX);
        box->labelfont(FL_BOLD+FL_ITALIC);
        box->labelsize(36);
        box->labeltype(FL_SHADOW_LABEL);
        
        char* option_five = (char*) "View Robot Models";
        char* option_six = (char*) "View your Orders";
        char* option_seven = (char*) "View Robot Parts";
        char* option_eight = (char*) "Create an Order";
        
        Fl_Button* button_five = new Fl_Button (70,240,140,50, option_five);
        button_five->when(FL_WHEN_RELEASE);
        button_five->callback(ButtonSecCB, option_five);
        
        Fl_Button* button_six = new Fl_Button (270,240,140,50, option_six);
        button_six->when(FL_WHEN_RELEASE);
        button_six->callback(ButtonSecCB, option_six);
        
        Fl_Button* button_seven = new Fl_Button (70,140,140,50, option_seven);
        button_seven->when(FL_WHEN_RELEASE);
        button_seven->callback(ButtonSecCB, option_seven);
        
        Fl_Button* button_eight = new Fl_Button (270,140,140,50, option_eight);
        button_eight->when(FL_WHEN_RELEASE);
        button_eight->callback(ButtonSecCB, option_eight);
        
        win->end();
        win->show();
        
        
    }
}




