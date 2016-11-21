
#include "FL/Fl.H"
#include "FL/Fl_Box.H"
#include "FL/Fl_Window.H"
#include "FL/Fl_Widget.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Check_Button.H"
#include "FL/Fl_Input.H"
#include "FL/Fl_Output.H"
#include "FL/Fl_Float_Input.H"
#include "FL/Fl_Int_Input.H"
#include "FL/Fl_Menu_Bar.H"
#include "FL/Fl_Return_Button.H"
#include "FL/Fl_Multiline_Input.H"
#include "FL/Fl_Multiline_Output.H"
#include "FL/Fl_Text_Display.H"
#include "FL/Fl_Text_Buffer.H"

#include<iostream>
#include<fstream>
#include <assert.h>
#include<cstdlib>
#include<string>
#include<vector>
#include <sstream>


using namespace std;


class Head *robot_head_dlg;
class Arm *robot_arm_dlg;
class Torso *robot_torso_dlg;
class Locomotor *robot_loco_dlg;
class Battery *robot_batt_dlg;
class salesAssociate *robot_sales_dlg;
class Customer *robot_cust_dlg;
class Models *robot_models_dlg;

struct arm;
struct head;
struct torso;
struct loco;
struct battery;
struct salesassociate;
struct customer;
struct models;

vector<arm> armParts;
vector<head> headParts;
vector<torso> torsoParts;
vector<loco> locoParts;
vector<battery> batteryParts;
vector<salesassociate> employees;
vector<customer> clients;
vector<models> rModels;


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
void cancel_robot_salesCB(Fl_Widget* w, void* p);
void create_robot_salesCB(Fl_Widget* w, void* p);
void cancel_robot_custCB(Fl_Widget* w, void* p);
void create_robot_custCB(Fl_Widget* w, void* p);
void cancel_robot_modelsCB(Fl_Widget* w, void* p);
void create_robot_modelsCB(Fl_Widget* w, void* p);

void view_parts();
void store_parts();

void view_models();
void store_models();

void view_custs();
void store_custs();

void view_employees();
void store_employees();

void view_orders();
void store_orders();


void ButtonSecCB(Fl_Widget* w, void* p);
void ButtonCB(Fl_Widget* w, void* p);

struct arm{
    string name;
    string part;
    string power;
    string weight;
    string cost;
    string description;
};
struct head{
    string name;
    string part;
    string weight;
    string cost;
    string description;
};
struct loco{
    string name;
    string part;
    string power;
    string speed;
    string weight;
    string cost;
    string description;
};
struct torso{
    string name;
    string part;
    string bAmount;
    string weight;
    string cost;
    string description;
};
struct battery{
    string name;
    string part;
    string energy;
    string weight;
    string cost;
    string description;
};

struct salesassociate{
    string name;
    string ID;
    string phone;
    string email;
    
};

struct customer{
    string name;
    string phone;
    string email;
};
struct models{
    
    string name;
    string arm;
    string armP;
    string armPow;
    string armW;
    string armC;
    string armD;
    
    string head;
    string headP;
    string headW;
    string headC;
    string headD;
    
    string loco;
    string locoP;
    string locoPow;
    string locoS;
    string locoW;
    string locoC;
    string locoD;
    
    string torso;
    string torsoP;
    string torsoB;
    string torsoW;
    string torsoC;
    string torsoD;
    
    string batt;
    string battP;
    string battE;
    string battW;
    string battC;
    string battD;
    
    string price;

};



class salesAssociate{
    
    public:
        salesAssociate(){
            
            dialog = new Fl_Window (480, 340, "Sales Associate");
            
            rp_name = new Fl_Input (160, 10, 310, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
            
            rp_ID = new Fl_Input (160, 40, 310, 25, "Employee ID: ");
            rp_ID->align (FL_ALIGN_LEFT);
            
            rp_telePhone = new Fl_Input (160, 70, 310, 25, "Employee Telephone: ");
            rp_telePhone->align (FL_ALIGN_LEFT);
            
            rp_email = new Fl_Input (160, 100, 310, 25, "Employee email: ");
            rp_email->align (FL_ALIGN_LEFT);
            
            rp_create = new Fl_Return_Button (265, 305, 120, 25, "Create");
            rp_create->callback (create_robot_salesCB, 0);
            
            rp_cancel = new Fl_Button (400, 305, 60, 25, "Cancel");
            rp_cancel->callback (cancel_robot_salesCB, 0);
            
            dialog->end();
            dialog->set_non_modal();
            
        }
    
        void show () {dialog->show();}
        void hide () {dialog->hide();}
        string name() {return rp_name->value();}
        string ID() {return rp_ID->value();}
        string telePhone() {return rp_telePhone->value();}
        string email() {return rp_email->value();}
    
    private:
    
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_ID;
        Fl_Input *rp_telePhone;
        Fl_Input *rp_email;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;

};


class Customer{
    
public:
    Customer(){
        
        dialog = new Fl_Window (480, 340, "Customer information");
        
        rp_name = new Fl_Input (160, 10, 310, 25, "Name: ");
        rp_name->align (FL_ALIGN_LEFT);
        
        rp_telePhone = new Fl_Input (160, 70, 310, 25, "Telephone: ");
        rp_telePhone->align (FL_ALIGN_LEFT);
        
        rp_email = new Fl_Input (160, 100, 310, 25, "Email: ");
        rp_email->align (FL_ALIGN_LEFT);
        
        rp_mod = new Fl_Input (160, 130, 310, 25, "Robot Model # : ");
        rp_mod->align (FL_ALIGN_LEFT);
        
        rp_quan = new Fl_Input (160, 160, 310, 25, "Quantity: ");
        rp_quan->align (FL_ALIGN_LEFT);
        
        rp_create = new Fl_Return_Button (265, 305, 120, 25, "Buy");
        rp_create->callback (create_robot_custCB, 0);
        
        rp_cancel = new Fl_Button (400, 305, 60, 25, "Cancel");
        rp_cancel->callback (cancel_robot_custCB, 0);
        
        dialog->end();
        dialog->set_non_modal();
        
    }
    
    void show () {dialog->show();}
    void hide () {dialog->hide();}
    string name() {return rp_name->value();}
    string mod() {return rp_mod->value();}
    string quan() {return rp_quan->value();}
    string telePhone() {return rp_telePhone->value();}
    string email() {return rp_email->value();}
    
private:
    
    Fl_Window *dialog;
    Fl_Input *rp_name;
    Fl_Input *rp_telePhone;
    Fl_Input *rp_email;
    Fl_Input *rp_mod;
    Fl_Input *rp_quan;
    Fl_Return_Button *rp_create;
    Fl_Button *rp_cancel;
    
};


class Head{
    public:

        Head(){
            
            dialog = new Fl_Window (340, 270, "Head part");
            
            rp_name = new Fl_Input (120, 10, 210, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
            
            rp_part_number = new Fl_Input (120, 40, 210, 25, "Part Number: ");
            rp_part_number->align (FL_ALIGN_LEFT);
            
            
            rp_weight = new Fl_Input (120, 70, 210, 25, "Weight(lbs): ");
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
            
            
            rp_weight = new Fl_Input (160, 100, 310, 25, "Weight(lbs): ");
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
        
        
            rp_weight = new Fl_Input (160, 100, 310, 25, "Weight(lbs): ");
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
        
        
            rp_weight = new Fl_Input (160, 130, 310, 25, "Weight(lbs): ");
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
        
            dialog = new Fl_Window (480, 320, "Battery part");
        
            rp_name = new Fl_Input (160, 10, 310, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
        
            rp_part_number = new Fl_Input (160, 40, 310, 25, "Part Number: ");
            rp_part_number->align (FL_ALIGN_LEFT);
        
            rp_energy = new Fl_Input (160, 70, 310, 25, "Energy (KW/HRS): ");
            rp_energy->align (FL_ALIGN_LEFT);
    
        
            rp_weight = new Fl_Input (160, 100, 310, 25, "Weight(lbs): ");
            rp_weight->align (FL_ALIGN_LEFT);
        
        
            rp_cost = new Fl_Float_Input (160, 130, 310, 25, "Cost: ");
            rp_cost->align (FL_ALIGN_LEFT);
        
            rp_description = new Fl_Multiline_Input (160, 190, 310, 75, "Description: ");
            rp_description->align (FL_ALIGN_LEFT);
        
            rp_create = new Fl_Return_Button (265, 280, 120, 25, "Create");
            rp_create->callback (create_robot_battCB, 0);
        
            rp_cancel = new Fl_Button (400, 280, 60, 25, "Cancel");
            rp_cancel->callback (cancel_robot_battCB, 0);
        
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
        
            dialog = new Fl_Window (480, 340, "Create a Model");
        
            rp_name = new Fl_Input (160, 10, 310, 25, "Name: ");
            rp_name->align (FL_ALIGN_LEFT);
        
            rp_arm = new Fl_Input (160, 40, 310, 25, "Arm #: ");
            rp_arm->align (FL_ALIGN_LEFT);
        
            rp_head = new Fl_Input (160, 70, 310, 25, "Head #: ");
            rp_head->align (FL_ALIGN_LEFT);
        
            rp_loco = new Fl_Input (160, 100, 310, 25, "Locomotor #: ");
            rp_loco->align (FL_ALIGN_LEFT);
        
        
            rp_torso = new Fl_Input (160, 130, 310, 25, "Torso #: ");
            rp_torso->align (FL_ALIGN_LEFT);
            
            rp_battery = new Fl_Input (160, 160, 310, 25, "Battery #: ");
            rp_battery->align (FL_ALIGN_LEFT);
        
            rp_ID = new Fl_Multiline_Input (160, 220, 310, 75, "Give it a Part #: ");
            rp_ID->align (FL_ALIGN_LEFT);
        
            rp_create = new Fl_Return_Button (265, 305, 120, 25, "Create");
            rp_create->callback (create_robot_modelsCB, 0);
        
            rp_cancel = new Fl_Button (400, 305, 60, 25, "Cancel");
            rp_cancel->callback (cancel_robot_modelsCB, 0);
        
            dialog->end();
            dialog->set_non_modal();
        
        }
    
        void show () {dialog->show();}
        void hide () {dialog->hide();}
        string name() {return rp_name->value();}
        string arm() {return rp_arm->value();}
        string head() {return rp_head->value();}
        string loco() {return rp_loco->value();}
        string torso() {return rp_torso->value();}
        string battery() {return rp_battery->value();}
        string ID() {return rp_ID->value();}


    
    
    private:
    
        Fl_Window *dialog;
        Fl_Input *rp_name;
        Fl_Input *rp_arm;
        Fl_Input *rp_head;
        Fl_Input *rp_loco;
        Fl_Input *rp_torso;
        Fl_Input *rp_battery;
        Fl_Input *rp_ID;
        Fl_Return_Button *rp_create;
        Fl_Button *rp_cancel;
    
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
    else if(!strcmp((char*)p, "Battery")){
        robot_batt_dlg = new Battery;
        robot_batt_dlg->show();
    }
    /*else if (!strcmp((char*)p, "Sales associate")){
        robot_sales_dlg = new salesAssociate;
        robot_sales_dlg->show();
    }*/
}
void create_robot_headCB(Fl_Widget* w, void* p){
    
    
    fstream file ("head.csv", ios::in | ios::out | ios::app);
    
    if(!file.is_open()){
        cout << "error, cannot open "<< file << endl;
    }
    
    else{
        file << "Name: " << robot_head_dlg->name() << ",";
        file << robot_head_dlg->part_number() << ",";
        file << "Weight: " << robot_head_dlg->weight() << ",";
        file << robot_head_dlg->cost() << ",";
        file << "Description: " << robot_head_dlg->description() << ","<< endl;
    }
    file.close();
    
    robot_head_dlg->hide();
    
}
void create_robot_armCB(Fl_Widget* w, void* p){
    
    fstream file ("arm.csv", ios::in | ios::out | ios::app);
    
    if(!file.is_open()){
        cout << "error, cannot open "<< file << endl;
    }
    
    else{
        file << "Name: " << robot_arm_dlg->name() << ",";
        file << robot_arm_dlg->part_number() << ",";
        file << "Power: " << robot_arm_dlg->power() << ",";
        file << "Weight: " << robot_arm_dlg->weight() << ",";
        file << robot_arm_dlg->cost() << ",";
        file << "Description: " << robot_arm_dlg->description() <<",";
    }
    file.close();
    robot_arm_dlg->hide();
    
}
void create_robot_torsoCB(Fl_Widget* w, void* p){
    
    fstream file ("torso.csv", ios::in | ios::out | ios::app);
    
    if(!file.is_open()){
        cout << "error, cannot open "<< file << endl;
    }
    
    else{
        file << "Name: " << robot_torso_dlg->name() << ",";
        file << robot_torso_dlg->part_number() << ",";
        file << "Battery#: " << robot_torso_dlg->amount() << ",";
        file << "Weight: " << robot_torso_dlg->weight() << ",";
        file << robot_torso_dlg->cost() << ",";
        file << "Description: " << robot_torso_dlg->description() << ",";
    }
    file.close();
    robot_torso_dlg->hide();
    
}
void create_robot_locoCB(Fl_Widget* w, void* p){
    
    fstream file ("loco.csv", ios::in | ios::out | ios::app);
    
    if(!file.is_open()){
        cout << "error, cannot open "<< file << endl;
    }
    
    else{
        file << "Name: " << robot_loco_dlg->name() << ",";
        file << robot_loco_dlg->part_number() << ",";
        file << "Power: " << robot_loco_dlg->power() << ",";
        file << "Max Speed: " << robot_loco_dlg->speed() << ",";
        file << "Weight: " << robot_loco_dlg->weight() << ",";
        file << robot_loco_dlg->cost() << ",";
        file << "Description: " << robot_loco_dlg->description() << ",";
    }
    file.close();
    robot_loco_dlg->hide();
    
}
void create_robot_battCB(Fl_Widget* w, void* p){
    
    fstream file ("battery.csv", ios::in | ios::out | ios::app);
    
    if(!file.is_open()){
        cout << "error, cannot open "<< file << endl;
    }
    
    else{
        file << "Name: " << robot_batt_dlg->name() << ",";
        file << robot_batt_dlg->part_number() << ",";
        file << "Energy: " << robot_batt_dlg->energy() << ",";
        file << "Weight: " << robot_batt_dlg->weight() << ",";
        file << robot_batt_dlg->cost() << ",";
        file << "Description: " << robot_batt_dlg->description() << ",";
    }
    file.close();
    robot_batt_dlg->hide();
    
}
void create_robot_salesCB(Fl_Widget* w, void* p){
    
    fstream file ("salesAsoc.csv", ios::in | ios::out | ios::app);
    
    if(!file.is_open()){
        cout << "error, cannot open "<< file << endl;
    }
    
    else{
        file << "Name: " << robot_sales_dlg->name() << ",";
        file << "Employee ID: " << robot_sales_dlg->ID() << ",";
        file << "Telephone #: " << robot_sales_dlg->telePhone() << ",";
        file << "Email: " << robot_sales_dlg->email() << ",";
     
    }
    file.close();
    robot_sales_dlg->hide();
}
void create_robot_custCB(Fl_Widget* w, void* p){

    fstream file ("customers.csv", ios::in | ios::out | ios::app);
    
    if(!file.is_open()){
        cout << "error, cannot open "<< file << endl;
    }
    
    else{
        file << "Name: " << robot_cust_dlg->name() << ",";
        file << "Telephone #: " << robot_cust_dlg->telePhone() << ",";
        file << "Email: " << robot_cust_dlg->email() << ",";
        
    }
    file.close();

    
    
    
    fstream filee ("orders.csv", ios::in | ios::out | ios::app);
    
    if(!filee.is_open()){
        cout << "error, cannot open "<< file << endl;
    }
    
    else{
        filee << "Name: " << robot_cust_dlg->name() << ",";
        filee << "Telephone #: " << robot_cust_dlg->telePhone() << ",";
        filee << "Email: " << robot_cust_dlg->email() << ",";
        filee << "Robot Model #: " << robot_cust_dlg->mod() << ",";
        filee << "Quantity: " << robot_cust_dlg->quan() << ",";
        
    }
    filee.close();
    robot_cust_dlg->hide();
}
void create_robot_modelsCB(Fl_Widget* w, void* p){
    
    double price = 0;
    
    fstream file ("models.csv", ios::in | ios::out | ios::app);
    
    if(!file.is_open()){
        cout << "error, cannot open "<< file << endl;
    }

    
    store_parts();
    
    file << "Name: "<<robot_models_dlg->name()<< ",";
    
    int i = 0;
    
    
    for(i = 0; i < armParts.size(); i++){
        
        cout << armParts[i].part << endl;
        
        if ((armParts[i].part) == (robot_models_dlg->arm())){
            
            file << armParts[i].name << ",";
            file << "Part #: " << armParts[i].part << ",";
            file << armParts[i].power << ",";
            file << armParts[i].weight << ",";
            file << "Cost: " <<armParts[i].cost << ",";
            price += atof((armParts[i].cost).c_str());
            file << armParts[i].description << ",";
            
        }
    }
    armParts.clear();
    
   //file << "###HEADDDDDD#####\n\n";

    for(i = 0; i < headParts.size(); i++){
        
        cout << headParts[i].part << endl;
        
        if ((headParts[i].part) == (robot_models_dlg->head())){
            
            file << headParts[i].name << ",";
            file << "Part #: " << headParts[i].part << ",";
            file << headParts[i].weight << ",";
            file << "Cost: " <<headParts[i].cost << ",";
            price += atof((headParts[i].cost).c_str());
            file << headParts[i].description << ",";
            
        }
    }
    headParts.clear();
    
    //file << "###TORSO#####\n\n";

    for(i = 0; i < torsoParts.size(); i++){
        
        cout << torsoParts[i].part << endl;
        
        if ((torsoParts[i].part) == (robot_models_dlg->torso())){
            
            file << torsoParts[i].name << ",";
            file << "Part #: " << torsoParts[i].part << ",";
            file << torsoParts[i].bAmount << ",";
            file << torsoParts[i].weight << ",";
            file << "Cost: " <<torsoParts[i].cost << ",";
            price += atof((torsoParts[i].cost).c_str());
            file << torsoParts[i].description << ",";
            
        }
    }
    torsoParts.clear();
 
    //file << "###LOCO#####\n\n";

    for(i = 0; i < locoParts.size(); i++){
        
        cout << locoParts[i].part << endl;
        
        if ((locoParts[i].part) == (robot_models_dlg->loco())){
            
            file << locoParts[i].name << ",";
            file << "Part #: " << locoParts[i].part << ",";
            file << locoParts[i].power << ",";
            file << locoParts[i].speed << ",";
            file << locoParts[i].weight << ",";
            file << "Cost: " <<locoParts[i].cost << ",";
            price += atof((locoParts[i].cost).c_str());
            file << locoParts[i].description << ",";
            
        }
    }
    locoParts.clear();
    //file << "###BATTERY#####\n\n";

    
    for(i = 0; i < batteryParts.size(); i++){
        
        cout << batteryParts[i].part << endl;
        
        if ((batteryParts[i].part) == (robot_models_dlg->battery())){
            
            file << batteryParts[i].name << ",";
            file << "Part #: "<< batteryParts[i].part << ",";
            file << batteryParts[i].energy << ",";
            file << batteryParts[i].weight << ",";
            file << "Cost: " << batteryParts[i].cost << ",";
            price += atof((batteryParts[i].cost).c_str());
            file << batteryParts[i].description << ",";
            
        }
    }
    
    batteryParts.clear();
    file << "Part # : "<<robot_models_dlg->ID()<< ",";
    
    file << price << ",";
    file.close();
    
    robot_models_dlg->hide();
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
void cancel_robot_salesCB(Fl_Widget* w, void* p){
    robot_sales_dlg->hide();
}
void cancel_robot_custCB(Fl_Widget* w, void* p){
    robot_cust_dlg->hide();
}
void cancel_robot_modelsCB(Fl_Widget* w, void* p){
    robot_models_dlg->hide();
}
void ButtonSecCB(Fl_Widget* w, void* p){
    
    Fl_Button *b = (Fl_Button*)w;
    
    if (!strcmp((char*)p, "Create Robot Parts")){
        
        Parts parts;
    }
    
    if (!strcmp((char*)p, "Create Robot Models")){
        
        robot_models_dlg = new Models;
        robot_models_dlg->show();
        store_parts();
        view_parts();
    }
    if (!strcmp((char*)p, "Create Sales Associate")){
        
        robot_sales_dlg = new salesAssociate;
        robot_sales_dlg->show();
    }
    if (!strcmp((char*)p, "Create an Order")){
        
        robot_cust_dlg = new Customer;
        robot_cust_dlg->show();
    }


    if (!strcmp((char*)p, "View Robot Parts")){

        store_parts();
        view_parts();
    }
    if (!strcmp((char*)p, "View Robot Models")){
        
        store_models();
        view_models();
    }
    if (!strcmp((char*)p, "Customers")){
        
        store_custs();
        view_custs();
    }
    if (!strcmp((char*)p, "Associates")){
        
        store_employees();
        view_employees();
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
        button_five->when(FL_WHEN_RELEASE);
        button_five->callback(ButtonSecCB, option_five);
        
        Fl_Button* button_six = new Fl_Button (220,370,140,50, option_six);
        button_six->when(FL_WHEN_RELEASE);
        button_six->callback(ButtonSecCB, option_six);
        
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
        char* option_six = (char*) "View your Order";
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

void view_parts(){
    
    Fl_Window *d = new Fl_Window(540, 300, "Robot Parts");
    
    Fl_Multiline_Output* output = new Fl_Multiline_Output(100, 10, 400, 200, "Parts list:");
    
    d->end();
    d->set_non_modal();
    d->show();

    
    ostringstream oss;
    
    oss << "#######ARM PARTS##############" << "\n";
    for(size_t i = 0; i < (armParts.size()-2); i++) {
        oss << armParts[i].name << "\n";
        oss << armParts[i].part << "\n";
        oss << armParts[i].power << "\n";
        oss << armParts[i].weight << "\n";
        oss << armParts[i].cost << "\n";
        oss << armParts[i].description << "\n";
        oss << "\n";
    }
    oss << "##############################" << "\n";
    
    oss << "\n#######HEAD PARTS###########" << "\n";
    for(size_t i = 0; i < (headParts.size()-2); i++) {
        oss << headParts[i].name << "\n";
        oss << headParts[i].part << "\n";
        oss << headParts[i].weight << "\n";
        oss << headParts[i].cost << "\n";
        oss << headParts[i].description << "\n";
        oss << "\n";
    }
    oss << "##############################" << "\n";
    
    oss << "\n#######TORSO PARTS##############" << "\n";
    for(size_t i = 0; i < (torsoParts.size()-2); i++) {
        oss << torsoParts[i].name << "\n";
        oss << torsoParts[i].part << "\n";
        oss << torsoParts[i].bAmount << "\n";
        oss << torsoParts[i].weight << "\n";
        oss << torsoParts[i].cost << "\n";
        oss << torsoParts[i].description << "\n";
        oss << "\n";
    }
    oss << "##############################" << "\n";
    
    oss << "\n####LOCOMOTOR PARTS#####"<< "\n";
    for(size_t i = 0; i < (locoParts.size()-2); i++) {
        oss << locoParts[i].name << "\n";
        oss << locoParts[i].part << "\n";
        oss << locoParts[i].power << "\n";
        oss << locoParts[i].speed << "\n";
        oss << locoParts[i].weight << "\n";
        oss << locoParts[i].cost << "\n";
        oss << locoParts[i].description << "\n";
        oss << "\n";
    }
    oss << "############################" << "\n";
    
    oss << "\n#######BATTERY PARTS########" << "\n";
    for(size_t i = 0; i < (batteryParts.size()-2); i++) {
        oss << batteryParts[i].name << "\n";
        oss << batteryParts[i].part << "\n";
        oss << batteryParts[i].energy << "\n";
        oss << batteryParts[i].weight << "\n";
        oss << batteryParts[i].cost << "\n";
        oss << batteryParts[i].description << "\n";
        oss << "\n";
    }
    oss << "##############################" << "\n";
    output->value(oss.str().c_str());
    
    armParts.clear();
    headParts.clear();
    torsoParts.clear();
    locoParts.clear();
    batteryParts.clear();
}

void store_parts(){
    
    armParts.push_back(arm());
    ifstream file;
    int index = 0;
    
    file.open("arm.csv",ios::in);
    assert(!file.fail( ));
  //  cout << "the count before: " << armParts.size() << endl;
    while (!file.eof( )){
        getline(file, armParts[index].name, ',');
        getline(file, armParts[index].part, ',');
        getline(file, armParts[index].power, ',');
        getline(file, armParts[index].weight, ',');
        getline(file, armParts[index].cost, ',');
        getline(file, armParts[index].description, ',');
        index++;
        armParts.push_back(arm());
    }
    
    file.close();
    //assert(!file.fail( ));
    
    
    //cout << "arm - the count : and index: " << armParts.size() << index << endl;
    
   // for(index = 0 ; index < (armParts.size() - 2); index++)
    //{
    //    cout << armParts[index].name << " ### " << armParts[index].description << endl;
  //  }
    
    index = 0;
    headParts.push_back(head());
    //cout << "the count before: " << headParts.size() << endl;
    
    file.open("head.csv",ios::in);
    assert(!file.fail( ));
    
    while (!file.eof( )){
        getline(file, headParts[index].name, ',');
        getline(file, headParts[index].part, ',');
        getline(file, headParts[index].weight, ',');
        getline(file, headParts[index].cost, ',');
        getline(file, headParts[index].description, ',');
        index++;
        headParts.push_back(head());
    }
    
    file.close();
    
    
    //cout << "head-the count : and index: " << headParts.size() << index << endl;
    
    //for(index = 0 ; index < (armParts.size() - 1); index++)
    //{
       // cout << headParts[index].name << " ### " << headParts[index].description << endl;
   // }
    
    index = 0;
    torsoParts.push_back(torso());
    //cout << "the count before: " << torsoParts.size() << endl;
    
    file.open("torso.csv",ios::in);
    assert(!file.fail( ));
    
    while (!file.eof( )){
        getline(file, torsoParts[index].name, ',');
        getline(file, torsoParts[index].part, ',');
        getline(file, torsoParts[index].bAmount, ',');
        getline(file, torsoParts[index].weight, ',');
        getline(file, torsoParts[index].cost, ',');
        getline(file, torsoParts[index].description, ',');
        index++;
        torsoParts.push_back(torso());
    }
    
    file.close();
    
    
    //cout << "torso-the count : and index: " << torsoParts.size() << index << endl;
    
    //for(index = 0 ; index < (torsoParts.size() - 1); index++)
    //{
       // cout << torsoParts[index].name << " ### " << torsoParts[index].description << endl;
   // }
    
    
    index = 0;
    locoParts.push_back(loco());
   // cout << "the count before: " << locoParts.size() << endl;
    
    file.open("loco.csv",ios::in);
    assert(!file.fail( ));
    
    while (!file.eof( )){
        getline(file, locoParts[index].name, ',');
        getline(file, locoParts[index].part, ',');
        getline(file, locoParts[index].power, ',');
        getline(file, locoParts[index].speed, ',');
        getline(file, locoParts[index].weight, ',');
        getline(file, locoParts[index].cost, ',');
        getline(file, locoParts[index].description, ',');
        index++;
        locoParts.push_back(loco());
    }
    
    file.close();
    
    
   // cout << "loco-the count : and index: " << locoParts.size() << index << endl;
    
   // for(index = 0 ; index < (locoParts.size() - 1); index++)
   // {
    //    cout << locoParts[index].name << " ### " << locoParts[index].description << endl;
  //  }
    
    index = 0;
    batteryParts.push_back(battery());
    //cout << "the count before: " << batteryParts.size() << endl;
    
    file.open("battery.csv",ios::in);
    assert(!file.fail( ));
    
    while (!file.eof( )){
        getline(file, batteryParts[index].name, ',');
        getline(file, batteryParts[index].part, ',');
        getline(file, batteryParts[index].energy, ',');
        getline(file, batteryParts[index].weight, ',');
        getline(file, batteryParts[index].cost, ',');
        getline(file, batteryParts[index].description, ',');
        index++;
        batteryParts.push_back(battery());
    }
    
    file.close();
    
    
    //cout << "batt-the count : and index: " << batteryParts.size() << index << endl;
    
    //for(index = 0 ; index < (batteryParts.size() - 1); index++)
   // {
   //     cout << batteryParts[index].name << " ### " << batteryParts[index].description << endl;
   // }
    
}


void view_custs(){
    
    Fl_Window *d = new Fl_Window(540, 300, "Our Beautiful Customers!");
    
    Fl_Multiline_Output* output = new Fl_Multiline_Output(100, 10, 400, 200, "Customer list:");
    
    d->end();
    d->set_non_modal();
    d->show();
    
    
    ostringstream oss;

    
    oss << "\n#######CUSTOMERS########\n" << "\n";
    for(size_t i = 0; i < (clients.size()-2); i++) {
        oss << clients[i].name << "\n";
        oss << clients[i].phone << "\n";
        oss << clients[i].email << "\n";
        oss << "\n";
    }
    oss << "##############################" << "\n";
    output->value(oss.str().c_str());
    
    clients.clear();
    
    
    
}
void store_custs(){
    
    clients.push_back(customer());
    ifstream file;
    int index = 0;
    
    file.open("customers.csv",ios::in);
    assert(!file.fail( ));
    cout << "the count before: " << clients.size() << endl;
    while (!file.eof( )){
        getline(file, clients[index].name, ',');
        getline(file, clients[index].phone, ',');
        getline(file, clients[index].email, ',');
        index++;
        clients.push_back(customer());
    }
    
    file.close();
}

void view_employees(){
    
    Fl_Window *d = new Fl_Window(540, 300, "Our Beautiful Employees");
    
    Fl_Multiline_Output* output = new Fl_Multiline_Output(100, 10, 400, 200, "Employee list:");
    
    d->end();
    d->set_non_modal();
    d->show();
    
    
    ostringstream osss;

    
    osss << "\n#######Sales Associates########" << "\n\n";
    for(size_t i = 0; i < (employees.size()-2); i++) {
        osss << employees[i].name << "\n";
        osss << employees[i].ID << "\n";
        osss << employees[i].phone << "\n";
        osss << employees[i].email << "\n";
        osss << "\n";
    }
    osss << "##############################" << "\n";
    output->value(osss.str().c_str());
    employees.clear();
}
void store_employees(){
    
    employees.push_back(salesassociate());
    ifstream file;
    int index = 0;
    
    file.open("salesAsoc.csv",ios::in);
    assert(!file.fail( ));
    cout << "the count before: " << employees.size() << endl;
    while (!file.eof( )){
        getline(file, employees[index].name, ',');
        getline(file, employees[index].ID, ',');
        getline(file, employees[index].phone, ',');
        getline(file, employees[index].email, ',');
        index++;
        employees.push_back(salesassociate());
    }
    
    file.close();
    
}
void view_models(){
    
    Fl_Window *d = new Fl_Window(540, 300, "Our Robot Models");
    
    Fl_Multiline_Output* output = new Fl_Multiline_Output(100, 10, 400, 200, "Employee list:");
    
    d->end();
    d->set_non_modal();
    d->show();
    
    
    ostringstream osss;
    
    
    osss << "\n#######Robot Models########" << "\n\n";
    for(size_t i = 0; i < (rModels.size()-2); i++) {
        osss << rModels[i].name << "\n";
        osss << "******Arm Part (2)********\n";
        osss << rModels[i].arm << "\n";
        osss << rModels[i].armP << "\n";
        osss << rModels[i].armPow << "\n";
        osss << rModels[i].armW << "\n";
        osss << rModels[i].armC << "\n";
        osss << rModels[i].armD << "\n";
        osss << "\n";
        osss << "*************************\n";
        osss << "******Head Part************\n";
        osss << rModels[i].head << "\n";
        osss << rModels[i].headP << "\n";
        osss << rModels[i].headW << "\n";
        osss << rModels[i].headC << "\n";
        osss << rModels[i].headD << "\n";
        osss << "\n";
        osss << "*************************\n";
        osss << "******Locomotor Part****\n";
        osss << rModels[i].loco << "\n";
        osss << rModels[i].locoP << "\n";
        osss << rModels[i].locoPow << "\n";
        osss << rModels[i].locoS << "\n";
        osss << rModels[i].locoW << "\n";
        osss << rModels[i].locoC << "\n";
        osss << rModels[i].locoD << "\n";
        osss << "\n";
        osss << "************************\n";
        osss << "******Torso Part********\n";
        osss << rModels[i].torso << "\n";
        osss << rModels[i].torsoP << "\n";
        osss << rModels[i].torsoB << "\n";
        osss << rModels[i].torsoW << "\n";
        osss << rModels[i].torsoC << "\n";
        osss << rModels[i].torsoD << "\n";
        osss << "\n";
        osss << "**************************\n";
        osss << "******Battery Part********\n";
        osss << rModels[i].batt << "\n";
        osss << rModels[i].battP << "\n";
        osss << rModels[i].battE << "\n";
        osss << rModels[i].battW << "\n";
        osss << rModels[i].battC << "\n";
        osss << rModels[i].battD << "\n";
        osss << "\n";
        osss << "*************************\n";
        
        osss << "PRICE: " << rModels[i].price << "\n";
    }

    osss << "##############################" << "\n";
    output->value(osss.str().c_str());
    rModels.clear();
    
    
    
}
void store_models(){
    
    rModels.push_back(models());
    ifstream file;
    int index = 0;
    
    file.open("models.csv",ios::in);
    assert(!file.fail( ));
    cout << "the count before: " << rModels.size() << endl;
    while (!file.eof( )){
        
        getline(file, rModels[index].name, ',');
        getline(file, rModels[index].arm, ',');
        getline(file, rModels[index].armP, ',');
        getline(file, rModels[index].armPow, ',');
        getline(file, rModels[index].armW, ',');
        getline(file, rModels[index].armC, ',');
        getline(file, rModels[index].armD, ',');
        
        getline(file, rModels[index].head, ',');
        getline(file, rModels[index].headP, ',');
        getline(file, rModels[index].headW, ',');
        getline(file, rModels[index].headC, ',');
        getline(file, rModels[index].headD, ',');
        
        getline(file, rModels[index].torso, ',');
        getline(file, rModels[index].torsoP, ',');
        getline(file, rModels[index].torsoB, ',');
        getline(file, rModels[index].torsoW, ',');
        getline(file, rModels[index].torsoC, ',');
        getline(file, rModels[index].torsoD, ',');

        getline(file, rModels[index].loco, ',');
        getline(file, rModels[index].locoP, ',');
        getline(file, rModels[index].locoPow, ',');
        getline(file, rModels[index].locoS, ',');
        getline(file, rModels[index].locoW, ',');
        getline(file, rModels[index].locoC, ',');
        getline(file, rModels[index].locoD, ',');
        
        getline(file, rModels[index].batt, ',');
        getline(file, rModels[index].battP, ',');
        getline(file, rModels[index].battE, ',');
        getline(file, rModels[index].battW, ',');
        getline(file, rModels[index].battC, ',');
        getline(file, rModels[index].battD, ',');
        
        getline(file, rModels[index].price, ',');

        index++;
        rModels.push_back(models());
    }
    
    file.close();
 
}


















