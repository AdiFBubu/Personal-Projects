using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Profesorul_Pac_Man
{
    public partial class Form2 : Form
    {

        bool goup, godown, goleft, goright, isGameOver;

        int score, playerSpeed, redGhostSpeed, yellowGhostSpeed, pinkGhostX, pinkGhostY;

        private void button1_Click(object sender, EventArgs e)
        {

        }

        // dupa finalizarea jocului, acesta va reîncepe mereu, dacă dorește 	
        // utilizatorul

        public Form2()
        {
            InitializeComponent();

            resetGame();
        }


        private void pacman_Click(object sender, EventArgs e)
        {

        }

        // trimiterea programului informația că utilizatorul folosește cel puțin
        // una din tastele sus-jos-stânga-dreapta

        private void keyisdown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Up)
            {
                goup = true;
            }

            if (e.KeyCode == Keys.Down)
            {
                godown = true;
            }

            if (e.KeyCode == Keys.Left)
            {
                goleft = true;
            }

            if (e.KeyCode == Keys.Right)
            {
                goright = true;
            }
        }

        // trimiterea programului informația că utilizatorul nu mai folosește
        // nicio tastă care să-l deplaseze pe PAC-MAN

        private void keyisup(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Up)
            {
                goup = false;
            }

            if (e.KeyCode == Keys.Down)
            {
                godown = false;
            }

            if (e.KeyCode == Keys.Left)
            {
                goleft = false;
            }

            if (e.KeyCode == Keys.Right)
            {
                goright = false;
            }

            // când utilizatorul a încheiat jocul și apasă ENTER, 		
            // jocul e resetat
            if (e.KeyCode == Keys.Enter && isGameOver == true)
            {
                resetGame();
            }
        }

        // ce se întâmplă cu fiecare obiect atunci când jocul e pornit

        private void mainGameTimer(object sender, EventArgs e)
        {

            txtScore.Text = "Score: " + score;

            // se stabilește ce se întâmplă cu PAC-MAN atunci când utilizatorul
            // vrea să-l deplaseze folosind săgețile corespunzătoare

            // la fiecare schimbare de sens, se va modifica și imaginea
            // lui PAC-MAN, astfel încât să existe concordanță între
            // sensul de mers și orientarea feței lui PAC-MAN

            if (goleft == true)
            {
                pacman.Left -= playerSpeed;
                pacman.Image = Properties.Resources.left;
            }

            if (goright == true)
            {
                pacman.Left += playerSpeed;
                pacman.Image = Properties.Resources.right;
            }

            if (godown == true)
            {
                pacman.Top += playerSpeed;
                pacman.Image = Properties.Resources.down;
            }

            if (goup == true)
            {
                pacman.Top -= playerSpeed;
                pacman.Image = Properties.Resources.Up;
            }

            // când PAC-MAN depășește o margine, el va ajunge în partea opusă a 		// ecranului (dreapta-stânga și sus-jos)

            if (pacman.Left < -10)
            {
                pacman.Left = 680;
            }

            if (pacman.Left > 680)
            {
                pacman.Left = -10;
            }

            if (pacman.Top < -10)
            {
                pacman.Top = 550;
            }

            if (pacman.Top > 550)
            {
                pacman.Top = 0;
            }


            // ce se întamplă cu fiecare obiect:
            // ---- bănuțul colectat devine invizibil si se incrementează scorul
            // utilizatorului

            // ---- atingerea unui perete sau a unei fantome
            // duce la pierderea jocului

            foreach (Control x in this.Controls)
            {
                if (x is PictureBox)
                {
                    if ((string)x.Tag == "coin" && x.Visible == true)
                    {
                        if (pacman.Bounds.IntersectsWith(x.Bounds))
                        {
                            score += 1;
                            x.Visible = false;
                        }
                    }

                    if ((string)x.Tag == "wall")
                    {
                        if (pacman.Bounds.IntersectsWith(x.Bounds))
                        {
                            gameOver("Ai pierdut!");
                        }

                        // când fantoma roz atinge un zid, i se modifică
                        // sensul de mișcare pe axa Ox

                        if (pinkGhost.Bounds.IntersectsWith(x.Bounds))
                        {
                            pinkGhostX = -pinkGhostX;
                        }
                    }

                    if ((string)x.Tag == "ghost")
                    {
                        if (pacman.Bounds.IntersectsWith(x.Bounds))
                        {
                            gameOver("Ai pierdut!");
                        }
                    }
                }
            }
            // mișcarea fantomelor

            // fantoma roșie și cea galbenă se deplasează de la stânga la 			// dreapta (pe axa Ox), între ziduri

            redGhost.Left += redGhostSpeed;

            if (redGhost.Bounds.IntersectsWith(pictureBox1.Bounds) || redGhost.Bounds.IntersectsWith(pictureBox2.Bounds))
            {
                redGhostSpeed = -redGhostSpeed; // atingerea unui zid = 								   // schimbarea sensului de mișcare
                                                // pe axa Ox
            }

            yellowGhost.Left -= yellowGhostSpeed;

            if (yellowGhost.Bounds.IntersectsWith(pictureBox3.Bounds) || yellowGhost.Bounds.IntersectsWith(pictureBox4.Bounds))
            {
                yellowGhostSpeed = -yellowGhostSpeed;
            }

            pinkGhost.Left -= pinkGhostX;
            pinkGhost.Top -= pinkGhostY;

            // fantoma roz se deplasează în zig-zag (compunerea forțelor 			reprezentate pe Ox și Oy)

            // daca atinge marginea ecranului, i se modifică sensul de mișcare
            // pe axa Oy

            if (pinkGhost.Top < 0 || pinkGhost.Top > 520)
            {
                pinkGhostY = -pinkGhostY;
            }

            if (pinkGhost.Left < 0 || pinkGhost.Left > 620)
            {
                pinkGhostX = -pinkGhostX;
            }


            if (score == 34)
            {
                gameOver("Ai Castigat!"); // încheierea jocului din ipostaza de
                                          // câștigător
            }



        }

        // la fiecare nou început de joc, se resetează scorul, respectiv vitezele 	// și coordonatele lui PAC-MAN și ale fantomelor

        private void resetGame()
        {

            txtScore.Text = "Score: 0";
            score = 0;

            redGhostSpeed = 5;
            yellowGhostSpeed = 5;
            playerSpeed = 8;

            pinkGhostX = 5;
            pinkGhostY = 5;

            isGameOver = false;

            pacman.Left = 24;
            pacman.Top = 41;

            yellowGhost.Left = 476;
            yellowGhost.Top = 449;

            redGhost.Left = 191;
            redGhost.Top = 55;

            pinkGhost.Left = 566;
            pinkGhost.Top = 238;

            // în plus, fiecare bănuț redevine vizibil

            foreach (Control x in this.Controls)
            {
                if (x is PictureBox)
                {
                    x.Visible = true;
                }
            }

            gameTimer.Start(); // jocul pornește

        }


        private void gameOver(string message) // mesajul afișat la sfârșitul 							 // fiecărui joc
        {
            isGameOver = true;
            gameTimer.Stop(); // jocul se oprește
            txtScore.Text = "Score: " + score + Environment.NewLine + message;
        }
    }
}
