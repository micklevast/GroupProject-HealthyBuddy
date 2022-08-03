#include <iostream>
#include <vector>
#include <ios>
#include <limits>
#include <windows.h>
#include <map>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cstdio>
#include <regex>
using namespace std;

// admin code
void settings()
{
theme:
    system("cls");
    cout << "\t--------------------------------------------------------------\n";
    cout << "\t\t |------------Select  Theme------------|" << endl
         << "\t\t |------------1.Dark  Theme------------|" << endl
         << "\t\t |------------2.Light Theme------------|" << endl
         << "\t\t |------------3.Eye <->Care------------|" << endl;
    cout << "\t--------------------------------------------------------------\n";
    cout << "Please enter your choice:";
    int a;
    cin >> a;
    if (a == 1)
    {
        system("color 07");
    }
    else if (a == 2)
    {
        system("color 70");
    }
    else if (a == 3)
    {
        system("color 86");
    }
    else
    {
        cout << "please select right option...\n";
        goto theme;
    }
}

class Admin
{
    string name, dob, user, pass;

    map<string, string> mp;
    int age;

public:
    string hosname, hosaddres;
    long long int phno1, phno2;
    int year;
    void doctorforgotpassword()
    {
        system("cls");
        cout << "Enter ID of Doctor :-";
        string delid, st6;
        cin.ignore();
        getline(cin, delid);
        st6 = "ID=";
        delid = st6 + delid;
        ifstream in("Doctorslogin.txt");
        ofstream on, move;
        string st4;
        while (getline(in, st4))
        {

            if (st4 == delid)
            {

                for (int i = 0; i < 3; i++)
                {
                    cout << st4 << endl;
                    getline(in, st4);
                }
                break;
            }
        }
        system("pause");
    }

    void viewdoctor()
    {
        system("cls");
        string st;
        ifstream in("Doctorlist.dat");
        while (in.eof() == 0)
        {
            getline(in, st);
            cout << st << endl;
        }
        system("pause");
    }
    //To delete Doctors
    void deletedoctor()
    {
        system("cls");
        cout << "Enter ID of Doctor you want to delete:-";
        string delid, st6;
        cin.ignore();
        getline(cin, delid);
        st6 = "ID=";
        delid = st6 + delid;
        ifstream in("Doctorlist.dat");
        ofstream on, move;
        string st4;
        move.open("Bin.txt", fstream::app);
        on.open("Newfile.dat", fstream::app);
        while (getline(in, st4))
        {

            if (st4 == delid)
            {

                for (int i = 0; i < 7; i++)
                {
                    move << st4 << endl;
                    getline(in, st4);
                }
            }
            if (st4 != delid)
            {
                on << st4 << endl;
            }
        }
        in.close();
        move.close();
        on.close();
        remove("Doctorlist.dat");
        rename("Newfile.dat", "Doctorlist.dat");
        ifstream i4("Doctorslogin.txt");
        ofstream o4, o5;
        o4.open("sample.dat", fstream::app);
        o5.open("loginbin.dat", fstream::app);
        while (getline(i4, st4))
        {

            if (st4 == delid)
            {

                for (int i = 0; i < 3; i++)
                {
                    o5 << st4 << endl;
                    getline(i4, st4);
                }
            }
            if (st4 != st6)
            {
                o4 << st4 << endl;
            }
        }
        i4.close();
        o4.close();
        o5.close();
        remove("Doctorslogin.txt");
        rename("sample.dat", "Doctorslogin.txt");
    }

    //To register
    void signup()
    {
        system("cls");
        cout << "\t\t----------------------Welcome------------------------\n";
        ofstream out("sample60b.txt", fstream::app);
        cout << "\nPlease Enter your name:-";
        cin.ignore();
        getline(cin, name);
        // cout<<name;
        out << "Name=" << name << endl;
        // cin.ignore(numeric_limits<streamsize>::max());
        cout << "Date of Birth:-";
        cin >> dob;
        out << "Date of Birth:-" << dob << endl;
        cout << "Age:-";
        cin >> age;
        out << "Age:-" << age << endl;
        cout << "Name of your hospital:-";
        cin.ignore();
        getline(cin, hosname);
        // cout<<hosname;
        out << "Name of your hospital:-" << hosname << endl;
        cout << "\t Enter your hospital details" << endl
             << "Contact no. 1:-";
        cin >> phno1;
        out << "Contact no. 1:-" << phno1 << endl;
        cout << "Contact no. 2:-";
        cin >> phno2;
        out << "Contact no. 2:-" << phno2 << endl;
        cout << "Year Established:-";
        cin >> year;
        out << "Year Established:-" << year << endl;
        cout << "Hospital address:-";
        cin.ignore();
        getline(cin, hosaddres);
        out << "Hospital address:-" << hosaddres << endl;
        for (int i = 0; i < 50; i++)
        {
            out << "-";
        }
        out << endl
            << endl;
        //cout << "enter captcha" << endl;
        ofstream o1("Login.txt", fstream::app);
        string user, pass;
        map<string, string> mp;
    reattempt:
        cout << "Please Enter your username:-";
        cin >> user;
        cout << "Please Enter your password:-";
        cin >> pass;
        mp[user] = pass;
        cout << "Please Enter your username:-";
        cin >> user;
        cout << "Please Enter your password:-";
        cin >> pass;
        if ((mp.find(user) == mp.end()) || (mp[user] != pass))
        {
            cout << "LOGIN FAILED" << endl;
            goto reattempt;
        }
        else
        {
            cout << "Welcome Admin" << endl;
            o1 << name << endl;
            o1 << "Username=" << user << endl;
            o1 << "Password=" << pass << endl;
            for (int i = 0; i < 50; i++)
            {
                o1 << "-";
            }
            o1 << endl
               << endl;
        }
    }
    void staffforgotpassword()
    {
        system("cls");
        cout << "Enter ID of Staff member:-";
        string delid, st6;
        cin.ignore();
        getline(cin, delid);
        st6 = "ID=";
        delid = st6 + delid;
        ifstream in("Staffslogin.txt");
        ofstream on, move;
        string st4;
        while (getline(in, st4))
        {

            if (st4 == delid)
            {

                for (int i = 0; i < 3; i++)
                {
                    cout << st4 << endl;
                    getline(in, st4);
                }
                break;
            }
        }
        system("pause");
    }

    // Login of Admin
    void signin()
    {
    back:
        system("cls");
        string input_password, id1, st1, st2, st3;

        cin.ignore();
        cout << "Enter your Username:-";
        getline(cin, id1);
        cout << "Enter your Password:-";
        getline(cin, input_password);
        st1 = "Username=";
        st2 = "Password=";
        st1 = st1 + id1;
        //  st1="username=karan"
        st2 = st2 + input_password;
        ifstream in("Login.txt");
        while (in.eof() == 0)
        {
            getline(in, st3);
            if (st3 == st1)
            {

                getline(in, st3);
                if (st3 == st2)
                {
                    cout << "You Have Successfully Login" << endl;
                    system("pause");
                    break;
                }
            }
            if (in.eof() == 1)
            {
                cout << "No Such Username or Password Found" << endl;
                system("pause");
                goto back;
            }
        }
    }
    //Adding new Doctors By Admin
    void adddoctor()
    {
        system("cls");
        string qualification, special, gender;
        string doctor;
        string id;
        int age;
        cout << "Please add no. of Doctor you want to add:-";
        int m;
        cin >> m;
        ofstream o3("Doctorlist.dat", fstream::app);
        for (int i = 0; i < m; i++)
        {
            cout << "----------------------------------------\n";
            cout << "Enter Doctor's ID:-";
            cin.ignore();
            getline(cin, id);
            o3 << "ID=" << id << endl;
            cout << "Enter Doctors name:-";
            getline(cin, doctor);
            o3 << "Name=" << doctor << endl;
            cout << "Enter Doctor's Gender:-";
            getline(cin, gender);
            o3 << "Gender=" << gender << endl;
            cout << "Enter Doctor's age:-";
            cin >> age;
            o3 << "Age=" << age << endl;
            cout << "Enter Doctor's Qualification:-";
            cin.ignore();
            getline(cin, qualification);
            o3 << "Qualification=" << qualification << endl;
            cout << "Enter Doctor's Specailisation:-";
            getline(cin, special);
            o3 << "Speciality=" << special << endl;
            for (int i = 0; i < 50; i++)
            {
                o3 << "-";
            }
            o3 << endl
               << endl;

            string user, pass, st1, st2, st3;
            map<string, string> mp;
        tryagain:
            cout << "Please Enter Doctor's username:-";
            cin >> user;
            st1 = "Username=";
            st2 = "Password=";
            st1 = st1 + user;
            ofstream o4;
            o4.open("Doctorslogin.txt", fstream::app);
            ifstream i4;
            i4.open("Doctorslogin.txt");
            while (i4.eof() == 0)
            {
                getline(i4, st3);
                if (st3 == st1)
                {
                    cout << "Username is already taken" << endl;
                    goto tryagain;
                }
            }
            o4 << "ID=" << id << endl;
            o4 << st1 << endl;
            cout << "Please Enter Doctor's password:-";
            cin >> pass;
            st2 = st2 + pass;
            o4 << st2 << endl;
            mp[user] = pass;
        }
    }
    void addStaff()
    {
        system("cls");
        string qualification, gender;
        string Staff, id;
        int age;
        cout << "Please add no. of Staff you want to add:-";
        int m;
        cin >> m;
        ofstream o3("Stafflist.dat", fstream::app);
        for (int i = 0; i < m; i++)
        {
            cout << "------------------------------------------\n";
            cout << "Enter Id  of Staff:-";
            cin.ignore();
            getline(cin, id);
            o3 << "ID=" << id << endl;
            cout << "Enter Staff member's name:-";
            getline(cin, Staff);
            o3 << "Name=" << Staff << endl;
            cout << "Enter Staff member's Qualification:-";
            getline(cin, qualification);
            o3 << "Qualification=" << qualification << endl;
            cout << "Enter Staff member's  Gender:-";
            getline(cin, gender);
            o3 << "Gender=" << gender << endl;
            cout << "Enter Staff member's age:-";
            cin >> age;
            o3 << "Age=" << age << endl;
            for (int i = 0; i < 50; i++)
            {
                o3 << "-";
            }
            o3 << endl
               << endl;

            string user, pass, st1, st2, st3;
            map<string, string> mp;
        tryagain:
            cout << "Please Enter Staff's username:-";
            cin >> user;
            st1 = "Username=";
            st2 = "Password=";
            st1 = st1 + user;
            ofstream o4;
            o4.open("Staffslogin.txt", fstream::app);
            ifstream i4;
            i4.open("Staffslogin.txt");
            while (i4.eof() == 0)
            {
                getline(i4, st3);
                if (st1 == st3)
                {
                    cout << "Username is already taken" << endl;
                    goto tryagain;
                }
            }
            o4<<"ID="<<id<<endl;
            o4 << st1 << endl;
            cout << "Please Enter Staff's password:-";
            cin >> pass;
            st2 = st2 + pass;
            o4 << st2 << endl;
            mp[user] = pass;
        }
    }
    void viewStaff()
    {
        system("cls");
        string st;
        ifstream in("Stafflist.dat");
        while (in.eof() == 0)
        {
            getline(in, st);
            cout << st << endl;
        }
        system("pause");
    }
    void deleteStaff()
    {
        system("cls");
        cout << "Enter ID of Staff member you want to delete:-";
        string delid, st6;
        cin.ignore();
        getline(cin, delid);
        st6 = "ID=";
        delid = st6 + delid;
        ifstream in("Stafflist.dat");
        ofstream on, move;
        string st4;
        move.open("Bin.txt", fstream::app);
        on.open("Newfile.dat", fstream::app);
        while (getline(in, st4))
        {

            if (st4 == delid)
            {

                for (int i = 0; i < 5; i++)
                {
                    move << st4 << endl;
                    getline(in, st4);
                }
            }
            if (st4 != delid)
            {
                on << st4 << endl;
            }
        }
        in.close();
        move.close();
        on.close();
        remove("Stafflist.dat");
        rename("Newfile.dat", "Stafflist.dat");
        ifstream i4("Staffslogin.txt");
        ofstream o4, o5;
        o4.open("sample.dat", fstream::app);
        o5.open("loginbin.dat", fstream::app);
        while (getline(i4, st4))
        {

            if (st4 == delid)
            {

                for (int i = 0; i < 3; i++)
                {
                    o5 << st4 << endl;
                    getline(i4, st4);
                }
            }
            if (st4 != delid)
            {
                o4 << st4 << endl;
            }
        }
        i4.close();
        o4.close();
        o5.close();
        remove("Staffslogin.txt");
        rename("sample.dat", "Staffslogin.txt");
        cout << "Deleted successfully...";
        system("pause");
    }
};

void admin()
{
logout:
    system("CLS");
    cout << "\t***------------------------------------------------------------***\n";
    cout << "\t\t   |**-------------1.SIGN UP------------**|" << endl;
    cout << "\t\t   |**-------------2.SIGN IN------------**|" << endl;
    cout << "\t\t   |**-------------3.Setting------------**|" << endl;
    cout << "\t\t   |**-------------4.Logout ------------**|" << endl;
    cout << "\t***------------------------------------------------------------***\n";
    int n;
    cout << "\t  Please Enter Your Choice:";
    cin >> n;

    if (n == 1)
    {
        system("CLS");
        cout << "\t\t\t       ________________________________\n";
        cout << "\t\t\t      |    REGISTER YOUR SELF          |" << endl;
        cout << "\t\t\t      |________________________________|\n";
        cout << " _______---------------'Please enter your details correctly and then register'---------------_______\n\n";
        system("pause");
        Admin jay;
        jay.signup();
    }
    else if (n == 2)
    {
        system("CLS");
        cout << "\t\t------------ Hey Admin Welcome Back Please Sign In ------------" << endl;
        Admin jay;
        jay.signin();
    }
    if (n == 3)
    {
        settings();
        goto logout;
    }
    if (n == 4)
        return;
    //// else
    //  {
    //    cout << "Wrong Input!" << endl;
    //    system("pause");
    //    goto logout;
    //   }
mainmenu:
    system("CLS");
    cout << "\n\t   -------------------------------------------------------";
    cout << "\n\t\t|-------------1.Edit Doctors   --------------|"
         << "\n\t\t|-------------2.Edit Staff     --------------|"
         << "\n\t\t|-------------3.Forgot Password--------------|"
         << "\n\t\t|-------------4.Settings       --------------|"
         << "\n\t\t|-------------5.Log Out        --------------|" << endl;
    cout << "\t   -------------------------------------------------------\n";
    int c;
    cout << "Please Enter Correct Choice: ";
    cin >> c;

    if (c == 1)
    {
    begin:
        system("CLS");
        cout << "\n\t  -----------------------------------------------------------\n";
        cout << "\t\t|--------*Please select sutable option---------|" << endl
             << "\t\t|--------1.View Doctor list           ---------|" << endl
             << "\t\t|--------2.Remove  Doctor From System ---------|" << endl
             << "\t\t|--------3.Add a new Doctor           ---------|" << endl
             << "\t\t|--------4.Settings                   ---------|" << endl
             << "\t\t|--------5.Return to Previous Menu    ---------|" << endl;
        cout << "\t  -----------------------------------------------------------\n";
        cout << "Please Enter Correct Choice: ";
        int d;
        cin >> d;
        if (d == 1)
        {
            Admin jay;
            jay.viewdoctor();
            goto begin;
        }
        else if (d == 2)
        {
            Admin jay;
            jay.deletedoctor();
            goto begin;
        }
        else if (d == 3)
        {
            Admin jay;
            jay.adddoctor();
            goto begin;
        }
        else if (d == 4)
        {
            settings();
            goto begin;
        }
        else if (d == 5)
        {
            goto mainmenu;
        }
        else
        {
            cout << "Wrong input" << endl;
            system("pause");
            goto begin;
        }
    }
    if (c == 2)
    {
        {
        begin2:
            system("CLS");
            cout << "\n\t   ----------------------------------------------------------\n";
            cout << "\t\t|----------Please select sutable option----------|" << endl
                 << "\t\t|----------1.View staff list           ----------|" << endl
                 << "\t\t|----------2.Remove  staff From System ----------|" << endl
                 << "\t\t|----------3.Add a new staff           ----------|" << endl
                 << "\t\t|----------4.Settings                  ----------|" << endl
                 << "\t\t|----------5.Return to Previous Menu   ----------|" << endl;
            cout << "\t   ----------------------------------------------------------\n";
            cout << "PLease Enter correct choice:";
            int g;
            cin >> g;
            if (g == 1)
            {
                Admin jay;
                jay.viewStaff();
                goto begin2;
            }
            else if (g == 2)
            {
                Admin jay;
                jay.deleteStaff();
                goto begin2;
            }
            else if (g == 3)
            {
                Admin jay;
                jay.addStaff();
                goto begin2;
            }
            else if (g == 4)
            {
                settings();
                goto begin2;
            }
            else if (g == 5)
            {
                goto mainmenu;
            }
            else
            {
                cout << "Wrong input" << endl;
                system("pause");
                goto begin2;
            }
        }
    }
    if (c == 3)
    {
        cout << "\t_____________________________________________\n";
        cout << "\t\t |---1.Doctor's Login Detail---|\n"
             << "\t\t |---2.Staff Login Detail   ---|" << endl;
        cout << "\t_____________________________________________\n";
        int k;
        cin >> k;
        if (k == 1)
        {
            Admin jay;
            jay.doctorforgotpassword();
        }
        if (k == 2)
        {
            Admin jay;
            jay.staffforgotpassword();
        }
        goto mainmenu;
    }
    if (c == 4)
    {
        settings();
        goto mainmenu;
    }
    if (c == 5)
    {
    }
    else
    {
        {
            cout << "Wrong input" << endl;
            system("pause");
            goto begin;
        }
    }
}
//merging1
void self_health_checker();
typedef struct patient
{
    string idd, passwords;
    int age;
    float weight;
    float height;
    float body_temperature;
    float BP_DBP; //Diastolic Blood Pressure(bottom number)
    float BP_SBP; //Systolic Blood Pressure(Top number)
    float oxygen_level;
    string bmi_report, oxygen_report, BP_report, fever_report;
    void input_patients_data();
    void vital_report();
} patients;

void patients::vital_report()
{
    float bmi = ((weight) / (height * height)) * 10000.0;
    cout << "---------------------------REPORT----------------------------\n";
    if (bmi < 18.5)
    {
        bmi_report = "Your BMI-Report       :Under-Weight";
        cout << bmi_report << endl;
    }
    else if (bmi > 18.5 && bmi < 24.9)
    {
        bmi_report = "Your BMI-Report       :Normal-Weight";
        cout << bmi_report << endl;
    }
    else if (bmi > 25.0 && bmi < 29.9)
    {
        bmi_report = "Your BMI-Report       :Overwight(Pre-Obesity)!";
        cout << bmi_report << endl;
    }
    else
    {
        bmi_report = "Your BMI_Report       :Crosses-Obesity_Class";
        cout << bmi_report << endl;
    }

    /*oxygen report*/
    if (oxygen_level > 94.0)
    {
        oxygen_report = "Oxygen-level          :Maintain Healthy-level";
        cout << oxygen_report << endl;
    }
    else
    {
        oxygen_report = "Oxygen-level          :Below-per Healthy-level";
        cout << oxygen_report << endl;
    }

    /*BP report*/
    if (BP_SBP < 90.0 && BP_DBP < 60.0)
    {
        BP_report = "BP-level              :LOW-Blood pressure";
        cout << BP_report << endl;
    }
    else if ((BP_SBP > 90.0 && BP_SBP < 120.0) && (BP_DBP > 60.0 && BP_DBP < 80.0))
    {
        BP_report = "BP-level              :NORMAL-Blood pressure";
        cout << BP_report << endl;
    }
    else if ((BP_SBP > 120.0 && BP_SBP < 140.0) && (BP_DBP > 80.0 && BP_DBP < 90.0))
    {
        BP_report = "BP-level              :PRE-High-Blood pressure";
        cout << BP_report << endl;
    }
    else
    {
        BP_report = "BP-level              :HIGH-Blood pressure";
        cout << BP_report << endl;
    }

    /*Fever report*/
    if (body_temperature < 97.0)
    {
        fever_report = "Fever                 :-ve (you have suffer COLD)";
        cout << fever_report << endl;
    }
    else if (body_temperature >= 97.0 && body_temperature < 99.0)
    {
        fever_report = "Fever                 :-ve (Normal)";
        cout << fever_report << endl;
    }
    else if (body_temperature > 99.0 && body_temperature < 100.4)
    {
        fever_report = "Fever                 :Acute-fever";
        cout << fever_report << endl;
    }
    else
    {
        fever_report = "Fever                 :+ve";
        cout << fever_report << endl;
    }
}

void patients::input_patients_data()
{
    cout << "_____--For safety && social-Distancing Purpose Please Measure Your Vital Information With the Help of Our Kits Provide To You--_____\n";
    cout << "Enter your Age:";
    cin >> age;
    cout << "Measure Your Height(cm):";
    cin >> height;
    cout << "Measure your Weight(kg):";
    cin >> weight;
    cout << "Measure your Body-Temperature(deg.Far):";
    cin >> body_temperature;
    cout << "Measure your BP(SBP & DBP both):";
    cin >> BP_SBP >> BP_DBP;
    cout << "Measure Your oxygen-level(0-100%):";
    cin >> oxygen_level;
}
void free_sign_in();
void free_sign_up()
{
    string sss(100, '*');
    cout << sss << endl;
    cout << "\n\t\t\t\t -----------" << endl;
    printf("\t\t\t\t | Sign Up |\n");
    cout << "\t\t\t\t -----------" << endl;
    string id, password;
    cout << "Without using space in word!\nmake your id:";
    cin.ignore();
    getline(cin, id);
    cout << "make your password: ";

    getline(cin, password);
    fstream fout;
    fout.open("login_data.txt", ios::app | ios::out);
    if (!fout)
        cout << "your file doesn't open!\n";
    else
    {
        fout << "id:" << id << "  "
             << "password:" << password << endl;
        fout.close();
        cout << "loading";
        for (int i = 0; i < 50; i++)
        {
            Sleep(100);
            cout << ".";
        }
        cout << "\n*************congrate! you have successfully made your account*************\n";
    }
}
void free_sign_in()
{
    system("CLS");
    cout << "\n\t\t\t\t -----------" << endl;
    printf("\t\t\t\t | Sign in |");
    cout << "\n\t\t\t\t -----------" << endl;
    string sss(26, '*');
    cout << sss << "____LOGIN____" << sss << endl;
    int flag = 0;
    string input_id, idd, input_password, pass;
    cout << "enter your id:";
    cin.ignore();
    getline(cin, input_id);
    idd = "id:" + input_id;
    cout << "enter your corresponding password:";
    getline(cin, input_password);
    pass = "password:" + input_password;
    fstream fin;
    fin.open("login_data.txt", ios::in);
    if (!fin)
        cout << "sorry! your file doesn't exit\n ";
    else
    {
        fin.seekg(0, ios::beg);
        char id1[30];
        char pass1[30];
        while (fin)
        {
            fin >> id1 >> pass1;
            if (idd == id1 && pass == pass1)
            {
                cout << "\t\t\tloading ";
                for (int i = 0; i < 5; i++)
                {
                    Sleep(1000);
                    cout << ".";
                }
                cout << "\n************------------you have successfully login------------************\n";
                Sleep(1111);
                Sleep(1000);
                /*-----------option for User/patients------------*/
                cout << "\t__________WELCOME TO OURS FREE SERVICES!__________\n";

                cout << "User can ...\n\n<1>Check_Self:Vital-reports\n<2>Check_Self:Corona-status\n";
                Sleep(2000);
                patients p1;
                p1.idd = input_id;
                p1.passwords = input_password;
                cout << "\t\t---------------------<1>Check_Self:Vital-reports---------------------\n";
                p1.input_patients_data();
                p1.vital_report();
                /*storing vital-report in Vital-Report.txt file*/
                fstream fout;
                fout.open("Vital-Report.txt", ios::out | ios::app);
                fout << "---------------------------------------------------------------------------------------\n";
                fout << "id:" << p1.idd << endl;
                fout << "Password              :" << p1.passwords << endl;

                fout << p1.bmi_report << endl;
                fout << p1.BP_report << endl;
                fout << p1.oxygen_report << endl;
                fout << p1.fever_report << endl;
                // fout<<"end:detail\n";
                Sleep(2000);
                system("pause");
                cout << "\t\t----------------<2>Check_Self:Corona-status----------------\n";
                cout << "  checking your Corona_status...\n";
                self_health_checker();
                fout << "end:detail\n";
                fout.close();

                flag++;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "please entered right id and password!\n";
            int choice2;
            cout << "press 1 for sign up\n";
            cout << "press 2 for sign in\n";
            cin >> choice2;
            if (choice2 == 1)
                free_sign_up();
            else
                free_sign_in();
        }
    }
    fin.close();
}

void show_menubar()
{
    cout << "\t--------------------------------------------------------------\n";
    cout << "\t\t|-------------press 1 for sign up-------------|\n";
    cout << "\t\t|-------------press 2 for sign in-------------|\n";
    cout << "\t\t|-------------press 3 for to exit-------------|\n";
    cout << "\t--------------------------------------------------------------\n";
}

/*main section */
void self_test_portal()
{
    int i, chance = 0, more_option = 0;
label1:
    system("cls");
    show_menubar();
    cout << "enter your choice:";

    cin >> i;
    switch (i)
    {
    case 1:
    {
        free_sign_up();
        cout << "==>for more option--------enter any positive number otherwise enter any negative number--------==>\n";
        cin >> more_option;
        if (more_option > 0)
        {
            goto label1;
        }
        more_option = 0;
        break;
    }
    case 2:
    {
        free_sign_in();
        cout << "==>\t\t\tfor more option...\n"
             << "\t________enter any positive number otherwise enter any negative number________\n";
        cin >> more_option;
        if (more_option > 0)
        {
            goto label1;
        }
        more_option = 0;
        break;
    }
    case 3:
    {
        break;
    }
    default:
    {
        if (chance < 3)
        {
            cout << "you have entered wrong choice! please make it correct...\n";
            chance++;
            cin.ignore();
            goto label1;
        }
        else
        {
            cout << "please log in after some time later";
        }
        break;
    }
    }
}

/*---------------------------------------------------------self-health-checker----------------------------------------------------------*/
void self_health_checker()
{
    float risk_status = 0.00;

    int num_of_sympton, num_of_pre_exiting_disease;
    char vaccine_status, travel_status;
    cout << "\t________Welcome to self_health checker a better precaution to prevent CORONA!________\n";
    cout << "CORONA SYMPTOM ==>\n";
    cout << "\t\t<i>Fever\n \t\t<ii>Dry Cough \n \t\t<iii>Tiredness\n \t\t<iv>Shortness of Breath\n \t\t<v>Loss of Taste and Smell\n \t\t<vi>Bodyache\n \t\t<vii>Pink Eyes\n \t\t<viii>Gastro-intestine Symptom\n \t\t<ix>Nose and Throat infection\n\t\t<x>None\n";
    cout << "\nQ.1) How many Corona Symptom do you have of above mention ? : ";
    cin >> num_of_sympton;
    if (num_of_sympton > 0)
    {
        risk_status = risk_status + 3.66 * num_of_sympton;
    }

    cout << "PRE-EXITING DISEASE==>\n";
    cout << "\t\t\t<i>Diabetes\n\t\t\t<ii>Hypertension\n\t\t\t<iii>Lung Disease\n\t\t\t<iv>Heart Disease\n\t\t\t<v>Kidney Disease\n\t\t\t<vi>Asthma\n\t\t\t<vii>none\n";
    cout << "\nQ.2)how many Pre-exiting Disease-Condition do you have facing?\n";
    cin >> num_of_pre_exiting_disease;
    if (num_of_pre_exiting_disease > 0)
    {
        risk_status = risk_status + 5.5 * num_of_pre_exiting_disease;
    }

    cout << "\nQ.3)Do you have taken Vaccine?\n______\t (i) For yes enter Y/y  &  For No enter N/n:-______:->";
    cin >> vaccine_status;
    if (vaccine_status == 'y' || vaccine_status == 'Y')
    {
        int vac, dose_num;
        cout << "-------------Available Vaccine in India:-------------\n";
        cout << "\t\t <1>Covishield\n\t\t<2>Covaxin\n\t\t<3>Sputnik-V\n\t\t<4>Moderna's\n";
        cout << "\n(I)Which number of vaccine do you have taken of above mention? :";
        cin >> vac;
        if (vac == 1)
        {
            risk_status = risk_status - 14.0;
        }
        if (vac == 2)
        {
            risk_status = risk_status - 15.6;
        }
        if (vac == 3)
        {
            risk_status = risk_status - 15.72;
        }
        cout << "\n(II)How Many Dose do you have taken? :";
        cin >> dose_num;
        if (dose_num == 1)
        {
            risk_status = risk_status;
        }
        if (dose_num == 2)
        {
            risk_status = risk_status - (4.00);
        }
    }
    else
    {
        risk_status = risk_status + (20.00);
    }

    cout << "\nQ.4)Do you have travel outside in last past 14 days?\n_____(i) For yes enter Y/y &&  For No enter N/n_____ :";
    cin >> travel_status;
    if (travel_status == 'Y' || travel_status == 'y')
    {
        risk_status = risk_status + (14.00);
    }
    else
    {
        risk_status = risk_status;
    }

    cout << "-----------showing your CORONA-risk status =" << risk_status << "%-----------\n";

    string corona_status;
    if (risk_status < 0.0)
    {
        corona_status = "CORONA-REPORTs        :CONGRATS! You are extremely Safe from Corona\n";
        cout << corona_status;
    }
    else if (risk_status >= 0 && risk_status < 33.00)
    {
        corona_status = "CORONA-REPORTs        :Great! You are Safe from Corona\n";
        cout << corona_status;
    }
    else if (risk_status >= 33.00 && risk_status < 66.00)
    {
        corona_status = "CORONA-REPORTs        :Disappointed! You have Moderate CORONA-risk of infection\n";
        cout << corona_status;
    }
    else
    {
        corona_status = "CORONA-REPORTs        :Heartbroken! You are in Higher CORONA-risk of infection\n";
        cout << corona_status;
    }
    cout << "------------------------------------------------------------------------------\n";
    fstream fout;
    fout.open("Vital-Report.txt", ios::out | ios::app);
    fout << "_________________CORONA-STATUS__________________\n";
    fout << corona_status;
    fout << "_________________-------------__________________\n";
    fout.close();
}

//doctor
void view_vital_report_by_patients_id();
class doctor
{
protected:
    string id;

public:
    void getid();
    void doc_login();
    void doc_main_menu();
    void get_vitals();
    void display_vitals();
    void write_prescription();
    void display_prescription();
    void write_med_report();
    void display_med_report();
} doc;

void doctor::doc_login()
{
back:
    system("cls");
    string input_password, id1, st1, st2, st3;

    cin.ignore();
    cout << "Enter your Username:-";
    getline(cin, id1);
    cout << "Enter your Password:-";
    getline(cin, input_password);
    st1 = "Username=";
    st2 = "Password=";
    st1 = st1 + id1;
    st2 = st2 + input_password;
    ifstream in("Doctorslogin.txt");
    while (in.eof() == 0)
    {
        getline(in, st3);
        if (st3 == st1)
        {

            getline(in, st3);
            if (st3 == st2)
            {
                system("cls");
                cout << "You Have Successfully Login" << endl;
                getchar();
                goto home;
            }
        }
        if (in.eof() == 1)
        {
            cout << "No Such Username or Password Found" << endl;
            goto back;
        }
    }
home:
    doc.doc_main_menu();
}

void doctor::doc_main_menu()
{
    int ch1;

doc_home:
    system("cls");
    doc.getid();
    getchar();
    do
    {
        system("cls");
        cout << "\t       ______________DOCTOR MAIN-MENU______________" << endl;
        cout << "\t   --------------------------------------------------------" << endl;
        cout << "\t\t1. |------Write vitals report    ------|" << endl;
        cout << "\t\t2. |------View vitals            ------|" << endl;
        cout << "\t\t3. |------Write prescription     ------|" << endl;
        cout << "\t\t4. |------View prescription      ------|" << endl;
        cout << "\t\t5. |------Write medical report   ------|" << endl;
        cout << "\t\t6. |------View medical report    ------|" << endl;
        cout << "\t\t7. |------View self vital report ------|" << endl;
        cout << "\t\t8. |------Back                   ------|" << endl;
        cout << "\t\t9. |------Setting                ------|" << endl;
        cout << "\t\t10.|------Logout                 ------|" << endl;
        cout << "\t   --------------------------------------------------------" << endl;
        cout << " \tEnter your choice:";
        cin >> ch1;

        switch (ch1)
        {
        case 1:
            doc.get_vitals();
            break;

        case 2:
            doc.display_vitals();
            break;

        case 3:
            doc.write_prescription();
            break;

        case 4:
            doc.display_prescription();
            break;

        case 5:
            doc.write_med_report();
            break;

        case 6:
            doc.display_med_report();
            break;

        case 7:
            view_vital_report_by_patients_id();
            break;

        case 8:
            goto doc_home;
            break;

        case 9:
            settings();
            break;

        case 10:
            break;

        default:
            cout << "Wrong choice!!";
            getchar();
            goto doc_home;
        }
    } while (ch1 != 10);
}

void doctor ::getid()
{
    cout << "Enter patient id : ";
    cin >> id;
}

void doctor ::get_vitals()
{
    int bp1, bp2, gul_lvl;
    float temp, o2_lvl;
    string vit = "vitals_of_";
    system("cls");
    cout << "\t\t\t\tEnter Vitals" << endl;
    cout << "Enter Blood Pressure : ";
    cin >> bp1 >> bp2;

    cout << "Enter Glucose level : ";
    cin >> gul_lvl;

    cout << "Enter Temperature : ";
    cin >> temp;

    cout << "Enter Oxygen level :";
    cin >> o2_lvl;

    vit = vit + id + ".txt";

    ofstream o;
    o.open(vit);

    o << "Patient Id : " << id << endl;
    o << "Blood Pressure : " << bp1 << "/" << bp2 << endl;
    o << "Temperature : " << temp << endl;
    o << "Glucose Level : " << gul_lvl << endl;
    o << "Oxygen Level : " << o2_lvl << endl;

    o.close();
}

void doctor ::display_vitals()
{
    string vit = "vitals_of_", s;
    vit = vit + id + ".txt";

    ifstream i;
    i.open(vit);
    system("cls");
    cout << "\t\t\t\tVITAL REPORT OF PATIENT " << id << endl;
    while (i.eof() == 0)
    {
        getline(i, s);
        cout << s << endl;
    }
    cin.ignore();
    getchar();
}

void doctor ::write_prescription()
{
    string s1, l;
    int n;
    s1 = "prescription_of_" + id + ".txt";
    system("cls");
    cout << "Enter the no of lines";
    cin >> n;
    system("cls");
    cout << "\t\t\tWrite Prescription\n";
    ofstream pre(s1);

    for (int i = 0; i <= n; i++)
    {
        getline(cin, l);
        pre << l << endl;
    }
    pre.close();
}

void doctor ::display_prescription()
{
    string s1, l;
    s1 = "prescription_of_" + id + ".txt";
    ifstream pre1(s1);
    system("cls");
    cout << "\t\t\t-------------:PRESCRIPTION OF PATIENT-------------: " << id << endl;
    while (getline(pre1, l))
    {
        cout << l << endl;
    }
    pre1.close();
    cin.ignore();
    getchar();
}

void doctor ::write_med_report()
{
    string repo_file = "Medreport_of_", s1;
    repo_file = repo_file + id + ".txt";
    ofstream o;

    o.open(repo_file, ios::app);
    system("cls");
    cout << "Enter report:" << endl;
    cin.ignore();
    getline(cin, s1);
    o << s1 << endl;

    o.close();
}

void doctor ::display_med_report()
{
    string repo_file = "Medreport_of_", s1;

    repo_file = repo_file + id + ".txt";
    ifstream i;
    i.open(repo_file);
    system("cls");
    cout << "\t\t--------MEDICAL REPORT OF PATIENT--------: " << id << endl;
    while (i.eof() == 0)
    {
        getline(i, s1);
        cout << s1 << endl;
    }

    cin.ignore();
    getchar();
}

//staff_profile
void sign_in();
void sign_up();
void view_vital_report();
void doctor_list();

class staff : virtual public doctor
{
public:
    void staff_login();
    void create_patient_account();
    void view_all_patient_record();
    void view_all_patient_vital_report();
    void update_patient_record();
    void read_patient_medical_report();
    void view_doctor_list();
    void working();
    void staff_service_menu();
};
void staff::view_doctor_list()
{
    doctor_list();
    system("pause");
}

void staff ::staff_login()
{
back:
    system("cls");
    string input_password, id1, st1, st2, st3;

    cin.ignore();
    cout << "Enter your Username:-";
    getline(cin, id1);
    cout << "Enter your Password:-";
    getline(cin, input_password);
    st1 = "Username=";
    st2 = "Password=";
    st1 = st1 + id1;
    st2 = st2 + input_password;
    ifstream in("Staffslogin.txt");
    while (in.eof() == 0)
    {
        getline(in, st3);
        if (st3 == st1)
        {

            getline(in, st3);
            if (st3 == st2)
            {
                cout << "loading";
                for (int i = 0; i < 5; i++)
                {
                    cout << ".";
                    Sleep(100);
                }
                cout << "\nYou Have Successfully Login" << endl;
                system("pause");
                goto home;
            }
        }
        if (in.eof() == 1)
        {
            cout << "No Such Username or Password Found" << endl;
            goto back;
        }
    }
home:
    working();
}

void staff::staff_service_menu()
{
    cout << "\t\t\t\t\t________________________________________________________\n";
    cout << "\t\t\t\t\t|------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|----------------------______________------------------|\n";
    cout << "\t\t\t\t\t|---------------------|Menu for Staff|-----------------|\n";
    cout << "\t\t\t\t\t|---------------------|______________|-----------------|\n";
    cout << "\t\t\t\t\t|------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|______________________________________________________|\n";

    cout << "\t\t\t\t\t\t\t[1]  Menu bar\n"
         << "\t\t\t\t\t\t\t[2] Create patient account\n"
         << "\t\t\t\t\t\t\t[3] View patient record\n"
         << "\t\t\t\t\t\t\t[4] View vital  report\n"
         << "\t\t\t\t\t\t\t[5] Write vital report\n"
         << "\t\t\t\t\t\t\t[6] View prescription\n"
         << "\t\t\t\t\t\t\t[7] Write prescription\n"
         << "\t\t\t\t\t\t\t[8] View medical report\n"
         << "\t\t\t\t\t\t\t[9] View all patient self vital report\n"
         << "\t\t\t\t\t\t\t[10] View specific patient self vital report\n"
         << "\t\t\t\t\t\t\t[11] View doctor list\n"
         << "\t\t\t\t\t\t\t[12] Settings\n"
         << "\t\t\t\t\t\t\t[0] press 0 for exit\n";
}

void staff::working()
{
    int choice;
    static int limit;
    do
    {
        system("CLS");
        staff_service_menu();
        cout << "enter your choice for working:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            staff_service_menu();
            break;

        case 2:
            create_patient_account();
            break;

        case 3:
            view_all_patient_record();
            break;

        case 4:
            getid();
            display_vitals();
            break;

        case 5:
            getid();
            get_vitals();
            break;

        case 6:
            getid();
            display_prescription();
            break;

        case 7:
            getid();
            write_prescription();
            break;

        case 8:
            getid();
            display_med_report();
            break;
        case 9:
            view_all_patient_vital_report();
            break;

        case 10:
            view_vital_report_by_patients_id();
            break;

        case 11:
            view_doctor_list();
            break;

        case 12:
            settings();
            break;

        default:

            if (choice != 0)
            {
                if (limit < 3)
                {
                    cout << "you have entered wrong option, please make it right!\n ";
                    limit++;
                    working();
                }
                else
                {
                    cout << "Your Try limit is exceed, Please try after some time later!\n";
                }
            }
        }
    } while (choice != 0);
}
void staff::create_patient_account()
{

    int op;

    do
    {
        cout << "\t\t\t\t**********************___________Menu To Make Account___________***********************\n";
        cout << "\t\t\t\t\t\t\t\t[1] Sign Up\n"
             << "\t\t\t\t\t\t\t\t[2] Log in\n"
             << "\t\t\t\t\t\t\t\t[0] press 0 to exit\n";
        cout << "enter your option:";
        cin >> op;
        switch (op)
        {

        case 1:
        {
            sign_up();
            break;
        }
        case 2:
        {
            sign_in();
            break;
        }

        default:
        {
            if (op != 0)
                cout << "Please enter Right Choice!\n";
            break;
        }
        }
    } while (op != 0);
}

void staff::view_all_patient_record()
{
    int change_line = 0;
    string patient;
    fstream fin;
    fin.open("patient_data.txt", ios::in);
    if (!fin.is_open())
        cout << "RECORDs NOT FOUND\n";
    else
    {
        cout << "****************--------------PATIENTs RECORDs--------------******************\n";
        while (fin >> patient)
        {
            change_line++;
            Sleep(100);
            cout << patient << "        ";
            if (change_line % 2 == 0)
                cout << endl;
        }
        system("pause");
    }
    cout << "---------------------------------------OVER------------------------------------------\n";
}
void staff_portal()
{
    staff s;
    // s.staff_service_menu();
    s.staff_login();
}

/*-----------------------------------sign_up nad login--------------------------------------*/
void sign_in();
void sign_up()
{
    string sss(70, '*');
    cout << sss << endl;
    cout << "\n\t\t\t\t -----------" << endl;
    printf("\t\t\t\t | Sign Up |\n");
    cout << "\t\t\t\t -----------" << endl;
    string id, password;
    cout << "make your id:";
    cin.ignore();
    getline(cin, id);
    cout << "make your password: ";

    getline(cin, password);
    fstream fout;
    fout.open("patient_data.txt", ios::app | ios::out);
    if (!fout)
        cout << "your file doesn't open!\n";
    else
    {
        fout << "id:" << id << "  "
             << "password:" << password << endl;
        fout.close();
        cout << "\t\t\tloading";
        for (int i = 0; i < 10; i++)
        {
            Sleep(100);
            cout << ".";
        }
        cout << "\ncongrate! you have successfully made your account\n";
        Sleep(1000);
    }
}
void sign_in()
{
    system("CLS");
    cout << "\n\t\t\t   -----------" << endl;
    printf("\t\t\t   | Sign in |");
    cout << "\n\t\t\t   -----------" << endl;
    string sss(26, '*');
    cout << sss << "____LOGIN____" << sss << endl;
    int flag = 0;
    string input_id, idd, input_password, pass;
    cout << "enter your id:";
    cin.ignore();
    getline(cin, input_id);
    idd = "id:" + input_id;
    cout << "enter your corresponding password:";

    getline(cin, input_password);
    pass = "password:" + input_password;
    fstream fin;
    fin.open("patient_data.txt", ios::in);
    if (!fin)
        cout << "sorry! your file doesn't exit\n ";
    else
    {
        // fin.seekg(0, ios::beg);
        char id1[30];
        char pass1[30];
        while (fin)
        {
            fin >> id1 >> pass1;
            if (idd == id1 && pass == pass1)
            {
                cout << "\t\t________________________________\n";
                cout << "\t\t\t   loading ";
                for (int i = 0; i < 5; i++)
                {
                    Sleep(1000);
                    cout << ".";
                }
                cout << "\n\t\t-------------------------------\n";
                cout << "\n\t__________you have successfully login__________\n";
                system("pause");

                flag++;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "please entered right id and password!\n";
            int choice2;
            cout << "press 1 for sign up\n";
            cout << "press 2 for sign in\n";
            cin >> choice2;
            if (choice2 == 1)
                sign_up();
            else
                sign_in();
        }
    }
    fin.close();
}

/*--------------------------------------------view ALL_patient vital reports--------------------------------------------*/
void staff::view_all_patient_vital_report()
{
    view_vital_report();
    system("pause");
}
string mark_line(100, '-');
void view_vital_report()
{
    string line;
    fstream fin;
    fin.open("Vital-Report.txt", ios::in);
    if (!fin)
        cout << "sorry! your file doesn't exits!\n";
    else
    {
        cout << "*************************ALL PATIENT VITAL REPORTS*********************\n";
        while (fin)
        {
            getline(fin, line);
            Sleep(100);
            cout << line << endl;
        }
    }
    cout << mark_line << endl;
}
/*----------------------------------view specific_patient vital reports_via_ID--------------------------------------*/
void view_vital_report_by_patients_id()
{
    int success = 0;
    string line, id, ID;
    string end_detail = "end:detail";
    fstream fin;
    fin.open("Vital-Report.txt", ios::in);
    if (!fin)
        cout << "sorry! your file doesn't exits!\n";
    else
    {
        cout << "enter patient id:";
        cin >> id;
        cout << "****************************PATIENT-ID: " << id << " :VITAL-REPORTs**********************************\n";
        ID = "id:" + id;
        while (fin)
        {
            getline(fin, line);
            if (line == ID)
            {
                cout << "patient found...\n";
                cout << line << endl;
                while (end_detail != line)
                {
                    Sleep(100);
                    getline(fin, line);
                    cout << line << endl;
                }
                success++;
                break;
            }
            if (success)
                break;
        }
        if (success == 0)
            cout << "user not found\n";
    }
    system("pause");
    cout << mark_line << endl;
}

/*-------------------------------view_all_Available-doctor_list----------------------------------n*/
void doctor_list()
{
    string line;
    fstream fin;
    fin.open("doctor_profile.txt", ios::in);
    if (!fin)
        cout << "sorry! your file doesn't exits!\n";
    else
    {
        cout << "**********************************HOSPITAL ALL DOCTOR LIST************************************\n";
        while (fin)
        {
            Sleep(50);
            getline(fin, line);
            Sleep(100);
            cout << line << endl;
        }
    }
    cout << mark_line << endl;
}

class patient1 : virtual public doctor, virtual public staff
{
public:
    void patient_login();
    void patient_menu();
} pat;

void patient1 ::patient_login()
{
    system("CLS");
    cout << "\t\t----------------------------------\n";
    cout << "\t\t   |-----1.Exist Patients-----|\n";
    cout << "\t\t   |-----2.New  Patients -----|\n";
    cout << "\t\t   |-----3.Logout        -----|\n";
    cout << "\t\t----------------------------------\n";
    int vikalp;
pat:
    cout << "enter you choice:";
    cin >> vikalp;
    switch (vikalp)
    {
    case 1:
    {
        sign_in();
        patient_menu();
        break;
    }
    case 2:
    {
        sign_up();
        sign_in();
        patient_menu();
        break;
    }
    case 3:
    {
        break;
    }
    default:
    {
        cout << "please enter correct option!\n";
        goto pat;
        break;
    }
    }
}
void make_free_vital_reports()
{
    string input_id, idd, input_password, pass;
    cout << "enter your id:";
    cin.ignore();
    getline(cin, input_id);
    idd = "id:" + input_id;
    cout << "enter your corresponding password:";
    getline(cin, input_password);
    pass = "password:" + input_password;
    patients p1;
    p1.idd = input_id;
    p1.passwords = input_password;
    cout << "\t\t---------------<1>Check_Self:Vital-reports---------------\n";
    p1.input_patients_data();
    p1.vital_report();
    /*storing vital-report in Vital-Report.txt file*/
    fstream fout;
    fout.open("Vital-Report.txt", ios::out | ios::app);
    fout << "---------------------------------------------------------------------------------------\n";
    fout << "id:" << p1.idd << endl;
    fout << "Password              :" << p1.passwords << endl;
    fout << p1.bmi_report << endl;
    fout << p1.BP_report << endl;
    fout << p1.oxygen_report << endl;
    fout << p1.fever_report << endl;
    // fout<<"end:detail\n";
    Sleep(2000);
    system("pause");
    cout << "\t\t----------------<2>Check_Self:Corona-status----------------\n";
    cout << "  checking your Corona_status...\n";
    self_health_checker();
    fout << "end:detail\n";
    fout.close();
    system("pause");
    system("CLS");
}

void corona_precaution()
{
    system("CLS");
    string line;
    fstream fin;
    fin.open("corona_precaution.txt", ios::in);
    while (fin)
    {
        getline(fin, line);
        cout << line << endl;
        Sleep(30);
    }
    system("pause");
}
void patient1 ::patient_menu()
{
    int c;
    do
    {
    home:
        system("cls");

        cout << "\t----------------------------MAIN-MENU-------------------------------" << endl;
        cout << "\t\t|----------1. Make free vital report        ---------|" << endl;
        cout << "\t\t|----------2. View Vital Report-Made by self---------|" << endl
             << "\t\t|----------3. View Prescription     -----------------|" << endl
             << "\t\t|----------4. View Medical Report   -----------------|" << endl
             << "\t\t|----------5. View Vital Report-made by staff--------|" << endl
             << "\t\t|----------6. View Doctor's List    -----------------|" << endl
             << "\t\t|----------7. Corona-Precaution     -----------------|" << endl
             << "\t\t|----------8. Settings              -----------------|" << endl
             << "\t\t|----------9. Logout                -----------------|" << endl;
        cout << "\t---------------------------------------------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            make_free_vital_reports();
            break;
        case 2:
            view_vital_report_by_patients_id();

            break;

        case 3:
            getid();
            display_prescription();
            break;

        case 4:
            getid();
            display_med_report();
            break;

        case 5:
            getid();
            display_vitals();
            break;

        case 6:
            view_doctor_list();
            break;

        case 7:
            corona_precaution();
            break;

        case 8:
            settings();
            break;

        case 9:
            break;

        default:
            cout << "\t\tPlease enter correct choice!!!" << endl;
            system("pause");
            goto home;
        }
    } while (c != 9);
}

//Patient portal code
void patient_portal()
{
    pat.patient_login();
}

int main()
{
    int ch;
    do
    {
        system("cls");
        cout << "    ------------------------------------------------------------------------\n";
        cout << "\t|-------------------------WELCOME------------------------------|\n";
        cout << "\t|----------------------------To--------------------------------|\n";
        cout << "\t|_______________________HealthyBuddy___________________________|\n";
        cout << "\t      |--------1. Admin                          --------|" << endl;
        cout << "\t      |--------2. Doctor                         --------|" << endl;
        cout << "\t      |--------3. Staff                          --------|" << endl;
        cout << "\t      |--------4. Patient                        --------|" << endl;
        cout << "\t      |--------5. Free Regular Checkup & Covid-19--------|" << endl;
        cout << "\t      |--------6. Corona-Precaution              --------|" << endl;
        cout << "\t      |--------7. Setting                        --------|" << endl;
        cout << "\t      |--------8. Exit                           --------|" << endl;
        cout << "\t--------------------------------------------------------------\n";
        cout << "\t\tEnter your Choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            admin();
            break;

        case 2:
            doc.doc_login();
            break;

        case 3:
            staff_portal();
            break;

        case 4:
            patient_portal();
            break;

        case 5:
            self_test_portal();
            break;

        case 6:
            corona_precaution();
            break;

        case 7:
            settings();
            break;

        case 8:
            break;

        default:
            cout << "\t\tPlease enter correct choice." << endl;
            system("pause");
        }

    } while (ch != 8);
    system("cls");
    cout << "\t----------------------------------------------------\n";
    cout << "\t\tThank you for using our services ....\n";
    cout << "\t----------------------------------------------------\n";
    return 0;
}
