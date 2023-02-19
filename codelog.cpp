#include "codelog.h"
#include "global_functions.h"
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;
void codelog ::intro()
{

    //                                  COORD is a inbuilt structure located in windows.h
    // The object c from COORD is used as C.X nad C.Y which are respectively the row and the column from where the message is to be printed
    //                                  Normally, there are 20 rows and 80 columns in a console window
    /*COORD c;
    c.X = 20;
    c.Y = 10;
    Updated to new method

    As the name suggests. It puts the consolecursor position to the output handle of COORD c
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); */

    /***********************************Background and Foreground*********************************/
    /*
        Background and Foreground Colors can be changed simply by:
        system ("COLOR attr");
        Example: system ("COLOR 1F");
        Here, 1st Hex in COLOR '1' gives background color
        And, 2nd Hex 'F' gives foreground color
        16 different colors are available
        Include stdlib.h for system() function
        Use system("COLOR FFF"); for details on availabe colors
        Use system("PAUSE"); to ask the user before proceeding i.e. Press any key to Continue
        Use system("CLS"); to clear screen
        Use cout << char(x); to print symbols where x is any number from 0 to 255;

    */

    /*  system("COLOR FFF"); */

    system("CLS");

    system("COLOR 3F");
    // This class is used to get height and width of the console window
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    int height = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

    // Used to vertically center align the box

    for (int i = 0; i < (height - 8) / 2; i++)
    {
        cout << endl;
    }

    // Used to make box

    // First row
    for (int i = 0; i < (width - 80) / 2; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < 80; i++)
    {
        cout << "=";
    }
    cout << endl;

    // Second Row
    cout << endl;
    for (int i = 0; i < (((width - 8) / 2)); i++)
    {
        cout << " ";
    }
    cout << "CODELOG:" << endl;

    // Third Row

    for (int i = 0; i < (width - 76) / 2; i++)
    {
        cout << " ";
    }
    cout << "A mini project implementing a Social Media using the concepts of DSA and C++" << endl <<endl;

    for (int i = 0; i < (width - 80) / 2; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < 80; i++)
    {
        cout << "=";
    }
    cout << endl<<endl;

    /************************For press any key message*************************************/
    for (int i = 0; i < (width - 16) / 2; i++)
    {
        cout << " ";
    }
    cout << "Press any key...";
    getch();

    system("CLS");

    /*****************************For new Screen*******************************************/

    system("COLOR 02");
    HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);

    // This loop is for vertical center alignment of the content
    for (int i = 0; i < (height - 15) / 2; i++)
    {
        cout << endl;
    }

    // For center alignment of the horizontal lines
    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    SetConsoleTextAttribute (h, 15);
    // Two new lines for the line 'Project By'
    cout << endl <<endl;

    for (int i = 0; i < (width - 13) / 2; i++)
    {
        cout << " ";
    }
    cout << "PROJECT BY: " << endl <<endl;
    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    SetConsoleTextAttribute(h, 15);

    // Name And Roll Number
    cout << endl <<endl;
    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Name";
    cout << setw(1) << left << " ";
    cout << setw(20) << right << "Roll Number" << endl <<endl;

    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    SetConsoleTextAttribute (h, 15);
    cout << endl
         << endl;

    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Tangsang Chongbang" << setw(1) << left << " " << setw(20) << right << "PUL077BEI047" << endl;
    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Susan Thapa" << setw(1) << left << " " << setw(20) << right << "PUL077BEI046" << endl;
    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Sangam Rai" << setw(1) << left << " " << setw(20) << right << "PUL077BEI040" << endl;
    for (int i = 0; i < (width - 41) / 2; i++)
    {
        cout << " ";
    }
    cout << setw(20) << left << "Manish Shah" << setw(1) << left << " " << setw(20) << right << "PUL077BEI050" << endl <<endl;

    for (int i = 0; i < (width - 60) / 2; i++)
    {
        cout << " ";
    }
    SetConsoleTextAttribute (h, 2);
    for (int i = 0; i < 60; i++)
    {
        cout << char (196);
    }
    SetConsoleTextAttribute (h, 15);
    cout << endl <<endl;
    for (int i = 0; i < (width - 16) / 2; i++)
    {
        cout << " ";
    }
    cout << "Press any key...";
    getch();
    system("CLS");
}

void codelog :: homescreen()
{
    system ("COLOR 02");
    //To get height and width of the current console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h;
    h = GetStdHandle (STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = (int)(csbi.srWindow.Right-csbi.srWindow.Left+1);
    int height = (int)(csbi.srWindow.Bottom-csbi.srWindow.Top+1);

    int ch; // Stores user's choice

    do {
        system("cls");
        SetConsoleTextAttribute (h, 2);
        //For vertical center alignment
        for (int i = 0; i < (height - 15) / 2; i++)
        {
            cout << endl;
        }

        //first row

        for (int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < 60; i++)
        {
            cout << char(196);
        }
        cout << endl;
        ifstream codelog_title ("titles/codelog_title.txt");
        string title;
        if (codelog_title.is_open())
        {
            while (!codelog_title.eof())
            {
                SetConsoleTextAttribute (h, 5);
                getline (codelog_title, title);
                for(int i = 0; i < (width - 42) / 2; i++)
                {
                    cout << " ";
                }
                cout << title << endl;
                SetConsoleTextAttribute (h, 2);
            }
        }
        codelog_title.close();
        for (int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < 60; i++)
        {
            cout << char (196);
        }

        //second row
        /*
        for (int i = 0; i < (width - 8) / 2; i ++)
        {
            cout << " ";
        }
        cout << "CODELOG:" << endl;

        //third row

        for (int i = 0; i < (width - 46) / 2; i++)
        {
            cout << " ";
        }

        cout << "Connect and Work with your Fellow Programmers." << endl << endl;

        //fourth row

        for (int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }

        for (int i = 0; i < 60; i++)
        {
            cout << "=";
        }
        */
        cout << endl << endl;

        //User options
        
        for(int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }
        cout << "(1) Create an Account" << endl;
        
        for(int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }
        cout << "(2) Login" <<endl;
        
        for(int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }
        cout << "(3) Forgot Password?"<<endl;
        
        for (int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }
        cout << "(4) Exit" << endl << endl;
        
        for(int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }

        for (int i = 0; i < 60; i++)
        {
            cout << char (196);
        }
        cout << endl << endl;

        for (int i = 0; i < (width - 60) / 2; i++)
        {
            cout << " ";
        }
        cout << "Enter your choice: ";
        cin >> ch;
            while(!cin.good())
            {
                for (int i = 0; i < (width - 60) / 2; i++)
                {
                    cout << " ";
                }
                SetConsoleTextAttribute (h, 4);
                cout << "ERR:"; 
                SetConsoleTextAttribute (h, 2);
                cout << " Enter integer only: ";
                cin.clear();
                cin.ignore();
                cin >> ch;
                cout << endl;
            }
            switch (ch)
            {
                case 1: write_details(); 
                system ("cls");
                system ("COLOR 0F");
                break;
                case 2:
                cin.ignore(); 
                login(); 
                break;
                case 3: forgot_password();
                break;
                case 4:
                cout << endl;
                for (int i = 0; i < (width - 60) / 2; i++)
                {
                    cout << " ";
                }
                SetConsoleTextAttribute (h, 4); 
                cout << "Exiting...";
                SetConsoleTextAttribute (h, 2);
                break;
                default: 
                for (int i = 0; i < (width - 60) / 2; i++)
                {
                    cout << " ";
                }
                SetConsoleTextAttribute (h, 4);
                cout << "Invalid Choice, Input again...";
                SetConsoleTextAttribute (h, 2);
                getch();
            } 
    } while (ch != 4);
}
