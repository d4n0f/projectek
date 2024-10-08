using System.Diagnostics;

namespace CalculatorByBalint
{
public partial class Szamologep : Form
    {
        Muveletek muveletek = new Muveletek(); // a Muveletek osztály példányosítása

        //változók deklarálása
        string hasznaltOperator = ""; 
        double szam1, szam2, eredmeny;

        public Szamologep()
        {
            InitializeComponent();
            kijelzo.Text = "0"; //a kijelzõre 0-t ír alapból

            //a kicsiKijelzo egy segédkijelzõ a jobb átláthatóságért
        }

        private void gomb_Click(object sender, EventArgs e) //képernyõre írja a megfelelõ számot
        {
            if (kijelzo.Text.Equals("0")) //megnézi, hogy nullával akarunk e kezdeni
            {
                kijelzo.Clear(); //ha igen, akkor nem hagyja hogy 1-nél több nulla kerüljön oda
            }

            Button gomb = (Button)sender; 
            kijelzo.Text += gomb.Text; // egyéb esetben pedig kiírja a számokat
        }

        private void gombPlusz_Click(object sender, EventArgs e) //'+' operátor tárolása, kíírása a képernyõre
        {
            operatorKezeles("+");
        }

        private void gombMinusz_Click(object sender, EventArgs e) //'-' operátor tárolása, kíírása a képernyõre
        {
            operatorKezeles("-");
        }

        private void gombSzorzas_Click(object sender, EventArgs e) //'*' operátor tárolása, kíírása a képernyõre
        {
            operatorKezeles("*");
        }

        private void gombOsztas_Click(object sender, EventArgs e) //'/' operátor tárolása, kíírása a képernyõre
        {
            operatorKezeles("/");
        }

        private void gombEgyenlo_Click(object sender, EventArgs e)
        {
            try
            {
                szam2 = Convert.ToDouble(kijelzo.Text); //második szám eltárolása
                if (hasznaltOperator.Equals("/") && szam2 == 0) // nullával való osztás elleni feltétel
                {
                    MessageBox.Show("Nullával nem lehet osztani!");
                    Debug.WriteLine("Nullával való osztás történt."); // logolja a hibát
                    updateKijelzo();
                }
                //Kilencvenkilenc billió kilencszázkilencvenkilenc milliárd kilencszázkilencvenkilenc millió kilencszázkilencvenkilencezer kilencszázkilencvenkilenc
                if (Convert.ToDouble(kijelzo.Text) > 99999999999999 || Convert.ToDouble(kijelzo.Text) < -99999999999999) // megakadályozza, hogy a számok nagyobbak legyenek mint a kijelzõ
                {
                    MessageBox.Show("Elérted a számok limitjét!");
                    Debug.WriteLine("Számok limitje elérve."); // logolja a hibát
                    updateKijelzo();
                    return;
                }
            }
            catch (FormatException ex)
            {
                Debug.WriteLine($"Formátum hiba történt: {ex.Message}"); // logolja a hibát
            }
            catch (OverflowException ex)
            {
                Debug.WriteLine($"Túlcsordulás történt: {ex.Message}"); // logolja a hibát
            }

            switch (hasznaltOperator) // meghívja a megfelelõ mûveletet
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
            kijelzo.Text = Convert.ToString(Math.Round(eredmeny, 2)); // kíírja a kijelzõre az eredményt
            kicsiKijelzo.Text += szam2 + "=";
        }

        private void gombVissza_Click(object sender, EventArgs e) // törli a legutóbbi lépést
        {
            if (kijelzo.Text.Length > 1)
            {
                kijelzo.Text = kijelzo.Text.Remove(kijelzo.Text.Length - 1);
            }
            else
            {
                kijelzo.Text = "0"; // ha már nincs mit törölni, visszaállítja 0-ra a kijelzõt
            }
        }

        private void gombTorles_Click(object sender, EventArgs e) // kijelzõ nullázása
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
                Debug.WriteLine($"Formátum hiba történt: {ex.Message}");
            }
            catch (OverflowException ex)
            {
                Debug.WriteLine($"Túlcsordulás történt: {ex.Message}");
            }

            kicsiKijelzo.Clear();
            kicsiKijelzo.Text += kijelzo.Text + megadottOperator;
            kijelzo.Clear();
        }
        private void updateKijelzo() // kijelzõ nullázásához eljárás
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
