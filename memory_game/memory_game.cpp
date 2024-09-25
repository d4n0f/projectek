// Fordítás: g++ memory_game.cpp -o memory_game
// Futtatás: ./memory_game

#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>

using namespace std;

int main()
{
    int x;
    int y;
    int z;
    int zs;
    int a;
    
    int* xp = &x;
    int* yp = &y;
    int* zp = &z;
    int* zsp = &zs;
    int* ap = &a;
    
    // VÁLTOZÓK AZ ADATBEKÉRÉSHEZ
    int szam1;
    int szam2;
    
    
    // SEGÉDVÁLTOZÓK
    int* seged1;
    int* seged2;
    int j1;
    int j2;
    int n = 5;
    int probalkozas = 10;
    string segitseg;
    
    // EREDETI TÖMB LÉTREHOZÁSA ÉS FELTÖLTÉSE
    int* tomb[] = {&x,&y,&z,&zs,&a, xp, yp, zp, zsp, ap};
    //ÚJ TÖMB LÉTREHOZÁSA A KEVERT SORRENDNEK
    int* newtomb[10];
    
    // CONSOLE-RA KIÍRÁST SEGÍTŐ TÖMB
    string szamok[10] = {"[1] ", "[2] ", "[3] ", "[4] ", "[5] ", "[6] ", "[7] ", "[8] ", "[9] ", "[10]"};
    
    
    
    
    //  VÉLETLENSZERŰ SORREND LÉTREHOZÁSA
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle (begin(tomb), end(tomb), std::default_random_engine(seed));
    
    // ÚJ TÖMB FELTÖLTÉSE AZ ÚJ SORRENDDEL
    for (int i = 0; i < 10; i++)
    {
        newtomb[i] = tomb[i];
    }
    
    // JÁTÉKBEMUTATÓ
    cout << "\nMEMÓRIA JÁTÉK\n" << endl;
    cout << "A játék lényege: \n" << "1-10-ig választhatsz ki számokat, amelyek egy-egy memóriacímet rejtenek. Mindegyiknek van egy párja. A cél, hogy megtaláld az összes párt!" << endl;
    cout << "Jó játékot kívánok!\n";
    
    cout << szamok[0] << szamok[1] << szamok[2] << szamok[3] << szamok[4] << "\n" << szamok[5] << szamok[6] << szamok[7] << szamok[8] << szamok[9] << endl;
    cout << "Válasszon ki egy számot és keresse meg a párját!" << endl;
    
    

    
    while (n != 0)
    {

        cout << "\nElső szám: ";
        cin >> szam1;
        cin.ignore();
        
        // ELSŐ SZÁM KIVÁLASZTÁSI MENETE
        switch(szam1)
        {
            case 1:
                cout << newtomb[0] << endl;
                seged1 = newtomb[0];
                j1 = 0;
                break;
            case 2:
                cout << newtomb[1] << endl;
                seged1 = newtomb[1];
                j1 = 1;
                break;
            case 3:
                cout << newtomb[2] << endl;
                seged1 = newtomb[2];
                j1 = 2;
                break;
            case 4:
                cout << newtomb[3] << endl;
                seged1 = newtomb[3];
                j1 = 3;
                break;
            case 5:
                cout << newtomb[4] << endl;
                seged1 = newtomb[4];
                j1 = 4;
                break;
            case 6:
                cout << newtomb[5] << endl;
                seged1 = newtomb[5];
                j1 = 5;
                break;
            case 7:
                cout << newtomb[6] << endl;
                seged1 = newtomb[6];
                j1 = 6;
                break;
            case 8:
                cout << newtomb[7] << endl;
                seged1 = newtomb[7];
                j1 = 7;
                break;
            case 9:
                cout << newtomb[8] << endl;
                seged1 = newtomb[8];
                j1 = 8;
                break;
            case 10:
                cout << newtomb[9] << endl;
                seged1 = newtomb[9];
                j1 = 9;
                break;
        }
        
        // MÁSODIK SZÁM KIVÁLASZTÁSI MENETE
        cout << "Második szám: ";
        cin >> szam2;
        cin.ignore();
        
        switch(szam2)
        {
            case 1:
                cout << newtomb[0] << endl;
                seged2 = newtomb[0];
                j2 = 0;
                break;
            case 2:
                cout << newtomb[1] << endl;
                seged2 = newtomb[1];
                j2 = 1;
                break;
            case 3:
                cout << newtomb[2] << endl;
                seged2 = newtomb[2];
                j2 = 2;
                break;
            case 4:
                cout << newtomb[3] << endl;
                seged2 = newtomb[3];
                j2 = 3;
                break;
            case 5:
                cout << newtomb[4] << endl;
                seged2 = newtomb[4];
                j2 = 4;
                break;
            case 6:
                cout << newtomb[5] << endl;
                seged2 = newtomb[5];
                j2 = 5;
                break;
            case 7:
                cout << newtomb[6] << endl;
                seged2 = newtomb[6];
                j2 = 6;
                break;
            case 8:
                cout << newtomb[7] << endl;
                seged2 = newtomb[7];
                j2 = 7;
                break;
            case 9:
                cout << newtomb[8] << endl;
                seged2 = newtomb[8];
                j2 = 8;
                break;
            case 10:
                cout << newtomb[9] << endl;
                seged2 = newtomb[9];
                j2 = 9;
                break;
        }
        
        // FELTÉTEL ARRA, HOGY A FELHASZNÁLÓ NEM KÉRHETI BE 2x UGYAN AZT A SZÁMOT
        if (j1 != j2)
        {
            // FELTÉTEL HA A FELHASZNÁLÓ ELTALÁL / NEM TALÁL EL EGY PÁRT
            if (seged1 == seged2)
            {
                cout << "\nGratulálok! Sikeresen megtaláltál egy párt!\n" << endl;
                n = n - 1;
                
                string szokoz1 = "    ";
                string szokoz2 = "    ";
                
                swap(szamok[j1], szokoz1); // ELSŐ SZÁM ELTÜNTETÉSE
                swap(szamok[j2], szokoz2); // MÁSODIK SZÁM ELTÜNTETÉSE
                
                cout << szamok[0] << szamok[1] << szamok[2] << szamok[3] << szamok[4] << "\n" << szamok[5] << szamok[6] << szamok[7] << szamok[8] << szamok[9] << endl;
            }
            else
            {
                cout << "\nNem talált! Próbáld újra!" << endl;
                probalkozas = probalkozas - 1;
            }
        }
        else
        {
            cout << "Nem választhatod kétszer ugyan azt a számot egy próbálkozásnál!" << endl;
        }
        
        // SEGÍTSÉG AJÁNLÁSA
        if (probalkozas == 0)
        {
            cout << "Szeretnél segítséget kérni? [I/N]" << endl;
            cin >> segitseg;
            cin.ignore();
            
            if (segitseg == "I" or segitseg == "i") // IGEN LEHETŐSÉGNÉL A PROGRAM KIÍRJA HOGY 1-10-ig MELYIK HELYEN MELYIK MEMÓRIACÍM ÁLL
            {
                cout << endl;
                for (int i = 0; i < 10; i++)
                {
                    cout << i+1 << ". " << newtomb[i] << endl;
                }
                cout << "\n" << szamok[0] << szamok[1] << szamok[2] << szamok[3] << szamok[4] << "\n" << szamok[5] << szamok[6] << szamok[7] << szamok[8] << szamok[9] << endl;
                probalkozas = -1;
            }
            else // HA A NEM LEHETŐSÉGET VÁLASZTOTTA ÚJRAINDUL A 10-es PRÓBÁLKOZÁSI LEHETŐSÉG
            {
                probalkozas = 10;
                cout << probalkozas << "probalkozas" << endl;
            }
        }
        
        // JÁTÉK VÉGE KIÍRÁS
        if (n == 0)
        {
            cout << "A játék véget ért! Megtaláltad az összes párt! Gratulálok!" << endl;
        }
    }
    
    return 0;
}