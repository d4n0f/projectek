// Fordítás: g++ xor_project.cpp -o xor
// Futtatás: ./xor

#include <iostream> //console-ra írás
#include <cstring> //const char* segéd
#include <bitset> //bináris számmá alakítás
#include <fstream> //fájlba írás
#include <vector> //végtelen tömb
#include <sstream> //a helyes kulcs megtalálásában és dekódolásban segít
#include <algorithm>

using namespace std;

//a már beolvasott szöveget átalakítja 8 bites bináris számsorozatokká
void binaris_atalakitas(const char* szoveg, bitset<8> eredeti[], size_t meret)
{
    for(int i = 0; i < meret; i++) 
    {
        eredeti[i] = bitset<8>(szoveg[i]);
    }
}

//a bináris számsorozaton XOR titkosítást hajt végre a "kulcs" segítségével
void titkositas(bitset<8> titkositott[], bitset<8> eredeti[], bitset<8> kulcs, size_t meret)
{
    vector<string> titkos;
    string seged;
    ofstream file1("titkositott_szamokban.txt");
    for (int i = 0; i < meret; i++)
    {
        titkositott[i] = eredeti[i] ^ kulcs;
        
        char simaChar = static_cast<char>(titkositott[i].to_ulong());
        seged.push_back(simaChar);
        
        file1 << titkositott[i] << " ";
    }
    file1.close();
    
    ofstream file2("titkositott.txt");
    file2 << seged;
    file2.close();
    
    cout << "A titkosított szöveg: " << seged << endl;
}

//random kulcs generáló
int randomKulcs() 
{
    srand(time(nullptr));

    int randomBinaris = 0;
    for (int i = 0; i < 8; i++)
    {
        randomBinaris = (randomBinaris << 1) | rand() % 2;
    }
    return randomBinaris;
}

//segít megkeresni melyik kulccsal titkosítottunk, illetve hogy melyik a helyes szöveg
vector<string> dekodolas(const bitset<8> titkositott[], int tomb_meret, int kulcs, string& felhasznaltKulcs) 
{
    vector<string> eredmeny;
    string simaszoveg;
    
    simaszoveg.clear();
    for (int i = 0; i < tomb_meret; i++)
    {
        char simaChar = static_cast<char>(titkositott[i].to_ulong() ^ kulcs); // XOR művelet a kulccsal
        simaszoveg.push_back(simaChar);
    }
    eredmeny.push_back(simaszoveg);
    felhasznaltKulcs = to_string(kulcs);
    
    return eredmeny;
}

int main()
{   
    //fájl beolvasása és eltárolása
    const char* szoveg;
    
    string simastr;
    string sor;
    
    ifstream file("titkositando.txt");
    while (getline(file, sor))
    {
        simastr += sor + "\n";
    }
    file.close();
    
    szoveg = simastr.c_str();
    
    size_t meret = strlen(szoveg);

    //bitset tömbök létrehozása
    bitset<8> eredeti[meret];
    bitset<8> kulcs = randomKulcs();
    bitset<8> titkositott[meret];
    bitset<8> visszafejtett[meret];
    
    //a karakterek átalakítása 8 bites bináris számokká, és a tömb feltöltése ezekkel a számokkal
    binaris_atalakitas(szoveg,eredeti,meret);
    
    //a bináris karakterek XOR alapú titkosítása a "kulcs" segítségével, új tömb feltöltése a titkosított számokkal
    titkositas(titkositott,eredeti,kulcs,meret);
    
    //titkosított tömb mérete
    int titkos_meret = sizeof(titkositott)/sizeof(titkositott[0]);
    
    //visszafejtési folyamat
    bitset<8> jo_kulcs;
    string felhasznaltKulcs;
    vector<string> dekodoltSzoveg;
    
    for (int key = 0; key <= 255; ++key) 
    {
        dekodoltSzoveg = dekodolas(titkositott, titkos_meret, key, felhasznaltKulcs);
        for (int i = 0; i < titkos_meret; i++)
        {
            istringstream iss(dekodoltSzoveg[i]);
            string szavak;
            while (iss >> szavak)
            {
                if (szavak == "be" or szavak == "and" or szavak == "to" or szavak == "is")
                {
                    cout << "\nA dekódolt szöveg: " << dekodoltSzoveg[i] << endl;
                    jo_kulcs = bitset<8>(key);
                    cout << "A kulcs amivel a szöveg titkosítva volt: " << jo_kulcs << endl;
                    break;
                }
            }
            break;
        }
    }
    
    //a visszafejtett szöveg beleírása fájlba
    ofstream file3("visszafejtett.txt"); // fájl megnyitása
    for (int i = 0; i < meret; ++i)
    {
        visszafejtett[i] = titkositott[i] ^ jo_kulcs; // XOR dekódolás
            
        unsigned long szam = visszafejtett[i].to_ulong(); // a dekódolt számsorozat szöveggé alakítása
        char betuk = static_cast<char>(szam);
            
        file3 << betuk;
    }
    file3.close(); // fájl bezárása
    
    return 0;
}

/*
    további feladatok:
    
        - tisztábbá/szebbé tenni a kódot
        - megoldani a nyelvválasztást
*/