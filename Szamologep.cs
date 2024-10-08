using System.Diagnostics;

namespace CalculatorByBalint
{
public partial class Szamologep : Form
    {
        Muveletek muveletek = new Muveletek(); // a Muveletek oszt�ly p�ld�nyos�t�sa

        //v�ltoz�k deklar�l�sa
        string hasznaltOperator = ""; 
        double szam1, szam2, eredmeny;

        public Szamologep()
        {
            InitializeComponent();
            kijelzo.Text = "0"; //a kijelz�re 0-t �r alapb�l

            //a kicsiKijelzo egy seg�dkijelz� a jobb �tl�that�s�g�rt
        }

        private void gomb_Click(object sender, EventArgs e) //k�perny�re �rja a megfelel� sz�mot
        {
            if (kijelzo.Text.Equals("0")) //megn�zi, hogy null�val akarunk e kezdeni
            {
                kijelzo.Clear(); //ha igen, akkor nem hagyja hogy 1-n�l t�bb nulla ker�lj�n oda
            }

            Button gomb = (Button)sender; 
            kijelzo.Text += gomb.Text; // egy�b esetben pedig ki�rja a sz�mokat
        }

        private void gombPlusz_Click(object sender, EventArgs e) //'+' oper�tor t�rol�sa, k��r�sa a k�perny�re
        {
            operatorKezeles("+");
        }

        private void gombMinusz_Click(object sender, EventArgs e) //'-' oper�tor t�rol�sa, k��r�sa a k�perny�re
        {
            operatorKezeles("-");
        }

        private void gombSzorzas_Click(object sender, EventArgs e) //'*' oper�tor t�rol�sa, k��r�sa a k�perny�re
        {
            operatorKezeles("*");
        }

        private void gombOsztas_Click(object sender, EventArgs e) //'/' oper�tor t�rol�sa, k��r�sa a k�perny�re
        {
            operatorKezeles("/");
        }

        private void gombEgyenlo_Click(object sender, EventArgs e)
        {
            try
            {
                szam2 = Convert.ToDouble(kijelzo.Text); //m�sodik sz�m elt�rol�sa
                if (hasznaltOperator.Equals("/") && szam2 == 0) // null�val val� oszt�s elleni felt�tel
                {
                    MessageBox.Show("Null�val nem lehet osztani!");
                    Debug.WriteLine("Null�val val� oszt�s t�rt�nt."); // logolja a hib�t
                    updateKijelzo();
                }
                //Kilencvenkilenc billi� kilencsz�zkilencvenkilenc milli�rd kilencsz�zkilencvenkilenc milli� kilencsz�zkilencvenkilencezer kilencsz�zkilencvenkilenc
                if (Convert.ToDouble(kijelzo.Text) > 99999999999999 || Convert.ToDouble(kijelzo.Text) < -99999999999999) // megakad�lyozza, hogy a sz�mok nagyobbak legyenek mint a kijelz�
                {
                    MessageBox.Show("El�rted a sz�mok limitj�t!");
                    Debug.WriteLine("Sz�mok limitje el�rve."); // logolja a hib�t
                    updateKijelzo();
                    return;
                }
            }
            catch (FormatException ex)
            {
                Debug.WriteLine($"Form�tum hiba t�rt�nt: {ex.Message}"); // logolja a hib�t
            }
            catch (OverflowException ex)
            {
                Debug.WriteLine($"T�lcsordul�s t�rt�nt: {ex.Message}"); // logolja a hib�t
            }

            switch (hasznaltOperator) // megh�vja a megfelel� m�veletet
            {
                case "+":
                    eredmeny = muveletek.osszeadas(szam1, szam2);
                    break;
                case "-":
                    eredmeny = muveletek.kivonas(szam1, szam2);
                    break;
                case "*":
                    eredmeny = muveletek.szorzas(szam1, szam2);
                    break;
                case "/":
                    eredmeny = muveletek.osztas(szam1, szam2);
                    break;
            }
            kijelzo.Text = Convert.ToString(Math.Round(eredmeny, 2)); // k��rja a kijelz�re az eredm�nyt
            kicsiKijelzo.Text += szam2 + "=";
        }

        private void gombVissza_Click(object sender, EventArgs e) // t�rli a legut�bbi l�p�st
        {
            if (kijelzo.Text.Length > 1)
            {
                kijelzo.Text = kijelzo.Text.Remove(kijelzo.Text.Length - 1);
            }
            else
            {
                kijelzo.Text = "0"; // ha m�r nincs mit t�r�lni, vissza�ll�tja 0-ra a kijelz�t
            }
        }

        private void gombTorles_Click(object sender, EventArgs e) // kijelz� null�z�sa
        {
            updateKijelzo();
        }

        private void operatorKezeles(string megadottOperator)
        {
            hasznaltOperator = megadottOperator;

            try
            {
                szam1 = Convert.ToDouble(kijelzo.Text);
            }
            catch (FormatException ex)
            {
                Debug.WriteLine($"Form�tum hiba t�rt�nt: {ex.Message}");
            }
            catch (OverflowException ex)
            {
                Debug.WriteLine($"T�lcsordul�s t�rt�nt: {ex.Message}");
            }

            kicsiKijelzo.Clear();
            kicsiKijelzo.Text += kijelzo.Text + megadottOperator;
            kijelzo.Clear();
        }
        private void updateKijelzo() // kijelz� null�z�s�hoz elj�r�s
        {
            kijelzo.Clear();
            kicsiKijelzo.Clear();
            kijelzo.Text = "0";
            eredmeny = 0;
            szam1 = 0;
            szam2 = 0;
            hasznaltOperator = "";
        }
    }
}
