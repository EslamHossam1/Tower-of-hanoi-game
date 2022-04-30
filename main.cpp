#include <iostream>
#include <unistd.h>
#include "header.h"
using namespace std;

void move(int ,int);
void show();
void autos(int, int, int, int);     //auto solution function
bool graphic;       //for the graphical solution
int time_d;       //time for the delay

tower x[3];

int main()
{
        clock_t start, End;
       start=clock();

    char fill[] = " 123456789";
    int z;
    int howmany;
    char response;
    int from;
    int to;
    int j = 1;
    int counter = 0;

    cout << "Choose the difficulty of the game: From level 1 to level 5... " ;
    cin >> z;
    howmany = z + 2;

    if(howmany > 7)
    {
        howmany = 7;
    }else if(howmany < 1)
    {
        howmany = 3;
    }


    for(int i = howmany; i > 0; i--)        //time complexity of pushing
    {
        x[0].push(fill[i]);
    }



    show();         //time complexity Function show

    while(j)
    {
        if (counter > 5)        //for struggle this will show the solution and end the game
        {
            cout << "Give up?! You can enter 0 & 0 to show the solution!" << endl << endl;
        }
        cout << "Which tower from? ";
        cin >> from;
        cout << "Which tower to? ";
        cin >> to;
        if(from == 0 && to == 0)
        {
            cout << "You gave up!! do you want the solution graphically? (Y/N) ";
            cin >> response;
            cout << endl;

            graphic = (response == 'Y' || response == 'y');

            if (graphic == 1)       //determining how fast the graphical solution will be
            {
                int fast;
                cout << "How fast do you want the graphical solution? " << endl;
                cout << "(1) Fast" << endl << "(2) medium" << endl << "(3) slow" << endl;
                cin >> fast;
                switch (fast)
                {
                case 1:
                    time_d = 1000000;           //second
                    break;
                case 2:
                    time_d = 1500000;
                    break;
                case 3:
                    time_d = 2000000;
                    break;
                default:
                    time_d = 1500000;
                }
            }

            for(int i = 0; i < 3; i++)          //resets the game to start from the beginning
                {
                    x[i].reset();
                }

            for(int j = howmany; j > 0; j--)
                {
                    x[0].push(fill[j]);
                }

            cout << "Initial state " << endl;
            show();
            usleep(time_d);       //delay for some seconds

            autos(howmany, 1, 3, 2);


            usleep(time_d);       //delay for some seconds
            cout << endl;
            cout << "Final state " << endl;
            show();
            break;
        }
        counter++;
        move(from,to);
        if(x[2].top == howmany)
        {
            cout << "Congratulations, you win!! after " << counter << " moves ";
            j = 0;
        }
    }

    system("pause");
 End=clock();
   double time_taken = (double(End-start))/(CLOCKS_PER_SEC); // calculate the elapsed time
   cout << "The program took "<< time_taken <<" seconds to execute"<<endl;
    return EXIT_SUCCESS;
}

void move(int from, int to)         //time complexity of this function
{
    if(x[to - 1].peak() < x[from - 1].peak() && x[to - 1].peak() != NULL)
    {
        cout << "You can't put a bigger number on a smaller number!!" << endl;
        return;
    }
    x[to - 1].push(x[from - 1].pop());
    show();
}

void autos(int count, int from, int to, int temp)       //time complexity of this function
{
    if (count == 0)
    {
        return;
    }
    autos(count - 1, from, temp, to);
    cout << "Move from " << from << " to " << to << endl;
    x[to - 1].push(x[from - 1].pop());
    if(graphic)
    {
        show();
        usleep(time_d);       //delay for some seconds
    }
    autos(count - 1, temp, to, from);
}


void show()
{
    for(int i = 0; i < 3; i++)
    {
        x[i].display(i);
    }
    cout << "---------------------------------------" << endl;
    cout << endl << endl;
}
