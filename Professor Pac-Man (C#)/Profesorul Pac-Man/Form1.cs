using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TaskbarClock;

namespace Profesorul_Pac_Man
{
    public partial class Form1 : Form
    {

        // variabilele pentru quiz

        int correctAnswer;
        int questionNumber = 1;
        int score;
        int percentage;
        int totalQuestions;


        public Form1()
        {
            InitializeComponent();

            askQuestion(questionNumber);

            totalQuestions = 20;
        }



        // ce se întâmplă atunci când se alege o variantă de răspuns
        private void checkAnswerEvent(object sender, EventArgs e)
        {
            var senderObject = (Button)sender;

            int buttonTag = Convert.ToInt32(senderObject.Tag);

            if (buttonTag == correctAnswer) // daca varianta de răspuns aleasă e
                                            // cea corectă, crește scorul
            {
                score++;
            }

            // dacă am ajuns la finalul testului, afisăm mesajul cu statistica
            // evaluării

            if (questionNumber == totalQuestions)
            {
                percentage = (int)Math.Round((double)(score * 100) / totalQuestions);

                MessageBox.Show(
                    "Testul s-a încheiat!" + Environment.NewLine +
                    "Ai raspuns la " + score + " întrebari corecte." + Environment.NewLine +
                    "Procentul total este " + percentage + "%" + Environment.NewLine +
                    "Apasă OK pentru a relua testul.", "Statistica evaluării"


                    );
                // după apăsarea butonului OK, testul reîncepe		

                score = 0;
                questionNumber = 0;
            }

            questionNumber++;
            askQuestion(questionNumber);


        }


        // toate cele 20 de grile, cu raspunsurile propuse si varianta corectă
        // afișarea intrebarii curente se realizează cu ajutorul instrucțiunii switch, care primește numărul grilei la care a ajuns utilizatorul

        private void askQuestion(int qnum)
        {
            switch (qnum)
            {
                case 1:
                    pictureBox1.Image = Properties.Resources.Question_1;

                    lblQuestion.Text = "    Ce se va afișa pe ecran în urma execuției următorului program?";

                    button1.Text = "42,64";
                    button2.Text = "64,42";
                    button3.Text = "64,64";
                    button4.Text = "eroare de compilare, pentru că lipsește void la declararea funcției main";

                    correctAnswer = 1;

                    break;

                case 2:
                    pictureBox1.Image = Properties.Resources.Question_2;

                    lblQuestion.Text = "    Ce se va afișa pe ecran în urma execuției următorului program?";

                    button1.Text = "300 800 310 600 900";
                    button2.Text = "300 900 320 600 1000";
                    button3.Text = "300 800 310 600 1000";
                    button4.Text = "niciuna din variante nu este corectă";

                    correctAnswer = 3;

                    break;

                case 3:
                    pictureBox1.Image = Properties.Resources.Question_3;

                    lblQuestion.Text = "    Ce se va afișa pe ecran în urma execuției următorului program?";

                    button1.Text = "edccbf";
                    button2.Text = "edcbaf";
                    button3.Text = "bcdefg";
                    button4.Text = "niciuna din variante nu este corectă";

                    correctAnswer = 1;

                    break;

                case 4:
                    pictureBox1.Image = Properties.Resources.Question_4;

                    lblQuestion.Text = "    Ce se va afișa pe ecran în urma execuției următorului program?";

                    button1.Text = "15";
                    button2.Text = "nimic (programul nu se compilează)";
                    button3.Text = "0";
                    button4.Text = "36";

                    correctAnswer = 2;

                    break;
                case 5:
                    pictureBox1.Image = Properties.Resources.Question_5;

                    lblQuestion.Text = "    Se consideră secvența următoare, în care valorile lui n și x se presupun cunoscute, v este un vector cu elementele (v[0],v[1],...,v[n-1]).\r\n\t     Precizați care dintre urmatoarele afirmații sunt adevărate:";

                    button1.Text = "Pentru n = 5, x = 3 ¸si v= (5,6,2,7,1), se afișează ultimele patru elemente nemodificate ale vectorului: 6 2 7 1.";
                    button2.Text = "Pentru n = 5, x = 1 și v = (2,1,3,1,4), se afișează: 2 3 1 4;";
                    button3.Text = "Secvența conține erori de sintaxă";
                    button4.Text = "Algoritmul șterge din vector elementul cu valoarea x, prin mutarea cu o poziție mai la stânga a elementelor aflate dupa el.";

                    correctAnswer = 4;

                    break;

                case 6:
                    pictureBox1.Image = Properties.Resources.Question_6;

                    lblQuestion.Text = "    Ce valori se vor găsi în fișierul numere.txt după execuția următorului program?";

                    button1.Text = "11 17 5 23 11";
                    button2.Text = "20 4 10 14 34";
                    button3.Text = "11\r\n17\r\n5";
                    button4.Text = "11\r\n17\r\n5\r\n23\r\n11";

                    correctAnswer = 3;

                    break;

                case 7:
                    pictureBox1.Image = Properties.Resources.Question_7;

                    lblQuestion.Text = "    O procedură ce parcurge următorul arbore în inordine va afișa:";

                    button1.Text = "3, 5, 6, 7, 10, 12, 13, 15, 16, 18, 20, 23";
                    button2.Text = "3, 6, 5, 7, 10, 12, 13, 15, 16, 18, 20, 23";
                    button3.Text = "3, 5, 6, 7, 10, 12, 13, 16, 15, 18, 20, 23";
                    button4.Text = "3, 7, 6, 10, 13, 12, 5, 18, 23, 20, 16, 15";

                    correctAnswer = 1;

                    break;

                case 8:
                    pictureBox1.Image = Properties.Resources.Question_8;

                    lblQuestion.Text = "    Ce metodă de sortare este descrisă în pseudocodul următor?";

                    button1.Text = "HeapSort";
                    button2.Text = "MergeSort";
                    button3.Text = "BubbleSort";
                    button4.Text = "SwapSort";

                    correctAnswer = 3;

                    break;

                case 9:
                    pictureBox1.Image = Properties.Resources.Question_9;

                    lblQuestion.Text = "    Ce se va afișa pe ecran în urma execuției următorului program:";

                    button1.Text = "Eroare de compilare";
                    button2.Text = "2 1 1 1";
                    button3.Text = "2 5 2 0";
                    button4.Text = "2 5 2 1";

                    correctAnswer = 4;

                    break;

                case 10:
                    pictureBox1.Image = Properties.Resources.Question_10;

                    lblQuestion.Text = "    Ce puteți afirma despre următorul program Java?";

                    button1.Text = "Programul nu este corect, deoarece asignarea lui x, conform obiectului b, este ilegală in Java;";
                    button2.Text = "Afișează:\r\na.x=2 a.x=200;";
                    button3.Text = "Afișează:\r\na.x=0 a.x=100;";
                    button4.Text = "Afișează:\r\na.x=1 a.x=100;";

                    correctAnswer = 2;

                    break;
                case 11:
                    pictureBox1.Image = Properties.Resources.Question_11;

                    lblQuestion.Text = "    Ce puteti spune despre următorul program Java?";

                    button1.Text = "Programul este corect și va afișa la execuție a=4, b=3;";
                    button2.Text = "Va apărea eroare la compilare, deoarece clasa C2 nu poate fi definită în metoda f() din clasa C1;";
                    button3.Text = "Va apărea eroare la compilare, deoarece în metoda g() nu putem accesa variabila locala a din metoda f();";
                    button4.Text = "Va apărea eroare la compilare, deoarece nu se creeaza în clasa Test un obiect de tip C1.C2";

                    correctAnswer = 3;

                    break;

                case 12:
                    pictureBox1.Image = Properties.Resources.Question_12;

                    lblQuestion.Text = "    Care este ordinea de parcurgere a nodurilor grafului din figura 1, dacă se folosește metoda de vizitare în lățime (BFS) pornind din nodul 5?";

                    button1.Text = "5, 2, 1, 3, 4, 7, 6, 8";
                    button2.Text = "5, 2, 7, 1, 6, 3, 4, 8";
                    button3.Text = "5, 2, 1, 3, 5, 7, 6, 8";
                    button4.Text = "5, 7, 2, 6, 1, 8, 4, 3";

                    correctAnswer = 2;

                    break;

                case 13:
                    pictureBox1.Image = Properties.Resources.Question_13;

                    lblQuestion.Text = "    Având graful ponderat din figura 4, să se determine un arbore de acoperire de cost minim. Vom considera nodul A ca nod de plecare. Care este ordinea de parcurgere a nodurilor?";

                    button1.Text = "A, B, D, E, C;";
                    button2.Text = "A, C, B, D, E;";
                    button3.Text = "A, B, D, C, E;";
                    button4.Text = "A, B, E, B, D;";

                    correctAnswer = 1;

                    break;

                case 14:
                    pictureBox1.Image = Properties.Resources.Question_14;

                    lblQuestion.Text = "    Care din urmatoarele interpretări fac adevărată formula F, ilustrată în graficul din Figura 5?\r\n";

                    button1.Text = "x1 = true, x2 = true, x3 = true";
                    button2.Text = "x1 = false, x2 = true, x3 = false";
                    button3.Text = "x1 = true, x2 = false, x3 = true";
                    button4.Text = "niciuna din variante nu este corectă";

                    correctAnswer = 2;

                    break;

                case 15:
                    pictureBox1.Image = Properties.Resources.Question_15;

                    lblQuestion.Text = "    Să se indice ordinul de creștere al funcției f(n) cu următoarea relație de recurență:";

                    button1.Text = "f(n) ∈ O(n!)";
                    button2.Text = "f(n) ∈ O(n^2)";
                    button3.Text = "f(n) ∈ O(n^2)";
                    button4.Text = "f(n) ∈ O(n * n!)";

                    correctAnswer = 1;

                    break;
                case 16:
                    pictureBox1.Image = Properties.Resources.Question_16;

                    lblQuestion.Text = "    Ce se va afișa pe ecran în urma execuției următorului program?";

                    button1.Text = "6";
                    button2.Text = "3";
                    button3.Text = "nimic (programul nu se compilează)";
                    button4.Text = "1";

                    correctAnswer = 4;

                    break;

                case 17:
                    pictureBox1.Image = Properties.Resources.Question_17;

                    lblQuestion.Text = "    Considerăm următorul program:\r\n      Dacă în urma execuției liniilor 4 și 5 se afisează 2 respectiv 0xF004, ce se va afișa în urma execuției liniei 6?";

                    button1.Text = "0xF010";
                    button2.Text = "0xF006";
                    button3.Text = "0xF00A";
                    button4.Text = "0xF003";

                    correctAnswer = 3;

                    break;

                case 18:
                    pictureBox1.Image = Properties.Resources.Question_18;

                    lblQuestion.Text = "    Se dă următorul algoritm:\r\n      Care vor fi valorile vectorului a dupa terminarea pasului i = 5, a = (8, 6, 4, 2, 3, 5, 7)?";

                    button1.Text = "(2, 3, 4, 5, 8, 7, 6)";
                    button2.Text = "(8, 7, 6, 5, 4, 2, 3)";
                    button3.Text = "(2, 3, 4, 5, 6, 8, 7)";
                    button4.Text = "(8, 3, 4, 5, 6, 7, 8)";

                    correctAnswer = 3;

                    break;

                case 19:
                    pictureBox1.Image = Properties.Resources.Question_19;

                    lblQuestion.Text = "    Ce va afișa următorul program?";

                    button1.Text = "Franklin";
                    button2.Text = "FDR";
                    button3.Text = "Franklin D. Roosevelt";
                    button4.Text = "Roosevelt";

                    correctAnswer = 2;
                    break;
                case 20:
                    pictureBox1.Image = Properties.Resources.Question_20;

                    lblQuestion.Text = "    Analizând algoritmul de mai jos, precizați ce timp de execuție are.";

                    button1.Text = "O(logN)";
                    button2.Text = "O(2^N)";
                    button3.Text = "O(NlogN)";
                    button4.Text = "O(N)";

                    correctAnswer = 4;

                    break;


            }
        }


        private void button5_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();  // buton care accesează jocul PAC-MAN
            f2.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit(); // odată închisă această fereastră, se închide
                                // toată aplicația
        }
    }
}
