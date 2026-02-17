#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void studentMenu();
void adminMenu();
string getTime();

// ---------------- MAIN ----------------
int main() {

    int choice;

    while(true){
        cout<<"\n===== SMART CAMPUS FOOD ORDERING SYSTEM =====\n";
        cout<<"1. Student Login\n";
        cout<<"2. Admin Login\n";
        cout<<"3. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice) {

            case 1:
                studentMenu();
                break;

            case 2:
                adminMenu();
                break;

            case 3:
                cout<<"Thank You!\n";
                return 0;

            default:
                cout<<"Invalid Choice\n";
        }
    }
}

// ---------------- GET TIME ----------------
string getTime() {

    time_t now = time(0);
    string dt = ctime(&now);
    return dt;
}

// ---------------- STUDENT MENU ----------------
void studentMenu() {

    string user, pass;

    cout<<"\nStudent Login\n";
    cout<<"Enter Username: ";
    cin>>user;

    cout<<"Enter Password: ";
    cin>>pass;

    if(pass!="1234") {
        cout<<"Wrong Password\n";
        return;
    }

    int choice, qty;
    float total = 0;

    int burger=0, pizza=0, sandwich=0, coldDrink=0;

    while(true) {

        cout<<"\n---- Food Menu ----\n";
        cout<<"1. Burger - Rs 50\n";
        cout<<"2. Pizza - Rs 120\n";
        cout<<"3. Sandwich - Rs 40\n";
        cout<<"4. Cold Drink - Rs 30\n";
        cout<<"5. Generate Bill\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==5)
            break;

        cout<<"Enter Quantity: ";
        cin>>qty;

        switch(choice) {

            case 1:
                burger+=qty;
                total+=50*qty;
                break;

            case 2:
                pizza+=qty;
                total+=120*qty;
                break;

            case 3:
                sandwich+=qty;
                total+=40*qty;
                break;

            case 4:
                coldDrink+=qty;
                total+=30*qty;
                break;

            default:
                cout<<"Invalid Choice\n";
        }
    }

    // Bill Print
    cout<<"\n========= BILL =========\n";

    if(burger>0)
        cout<<"Burger x "<<burger<<" = "<<burger*50<<endl;

    if(pizza>0)
        cout<<"Pizza x "<<pizza<<" = "<<pizza*120<<endl;

    if(sandwich>0)
        cout<<"Sandwich x "<<sandwich<<" = "<<sandwich*40<<endl;

    if(coldDrink>0)
        cout<<"Cold Drink x "<<coldDrink<<" = "<<coldDrink*30<<endl;

    cout<<"------------------------\n";
    cout<<"Total Bill = Rs "<<total<<endl;
    cout<<"Order Placed Successfully!\n";

    // Save Order
    static int orderNo = 1;

    ofstream file("orders.txt", ios::app);
    file<<"\nOrder No: "<<orderNo++;
    file<<"\nStudent: "<<user;
    file<<"\nTime: "<<getTime();

    if(burger>0)
        file<<"Burger x "<<burger<<endl;

    if(pizza>0)
        file<<"Pizza x "<<pizza<<endl;

    if(sandwich>0)
        file<<"Sandwich x "<<sandwich<<endl;

    if(coldDrink>0)
        file<<"Cold Drink x "<<coldDrink<<endl;

    file<<"Total = "<<total<<endl;
    file<<"--------------------------\n";

    file.close();
}

// ---------------- ADMIN MENU ----------------
void adminMenu() {

    string pass;
    cout<<"\nAdmin Password: ";
    cin>>pass;

    if(pass!="admin") {
        cout<<"Wrong Password\n";
        return;
    }

    ifstream file("orders.txt");
    string line;

    cout<<"\n------ ORDER HISTORY ------\n";

    while(getline(file,line)) {
        cout<<line<<endl;
    }

    file.close();
}