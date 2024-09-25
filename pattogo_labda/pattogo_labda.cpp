// Fordítás: g++ pattogo_labda.cpp -o pattogo
// Futtatás: ./pattogo

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;

//globális változók
int szelesseg = 30;
int magassag = 50;
int xpoz = szelesseg / 2;
int ypoz = magassag / 2;

void keret()
{
    for (int x = 0; x <= szelesseg; x++)
    {
        for (int y = 0; y <= magassag; y++)
        {
            if (x == 0 || x == szelesseg || y == 0 || y == magassag)
            {
                cout << "#";
            }
            else if (xpoz == x && ypoz == y)
            {
                cout << "X";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void iranyvaltoztatas(int& randomX, int& randomY)
{
    if (xpoz == 1 || xpoz == szelesseg -1)
        {
            randomX *= -1;
        }
        if (ypoz == 1 || ypoz == magassag -1)
        {
            randomY *= -1;
        }
}

int main()
{
    srand(time(0));
    int randomX = rand() % 3-1;
    int randomY = rand() % 3-1;
    
    if (randomX == 0)
    {
        randomX += 1;
    }
    if (randomY == 0)
    {
        randomY += 1;
    }
    
    while(true)
    {
        system("clear");
        
        keret();
        
        this_thread::sleep_for(chrono::milliseconds(100)); //késleltetés
        
        xpoz += randomX;
        ypoz += randomY;
        
        iranyvaltoztatas(randomX, randomY);
    }
    
    return 0;
}