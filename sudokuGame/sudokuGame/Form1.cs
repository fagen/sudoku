using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;
using System.IO;
//using System.Text;

namespace sudokuGame
{
    public partial class sudoku宇宙超级无敌变态的数独游戏 : Form
    {
        public static ArrayList tbList = new ArrayList();
        public static int flag = 0;
        public sudoku宇宙超级无敌变态的数独游戏()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("sudoku.exe", "-c 1000").WaitForExit();
            System.Diagnostics.Process.Start("sudoku.exe", "-p 1000");
            tbList.Add(tb11);
            tbList.Add(tb12);
            tbList.Add(tb13);
            tbList.Add(tb14);
            tbList.Add(tb15);
            tbList.Add(tb16);
            tbList.Add(tb17);
            tbList.Add(tb18);
            tbList.Add(tb19);
            tbList.Add(tb21);
            tbList.Add(tb22);
            tbList.Add(tb23);
            tbList.Add(tb24);
            tbList.Add(tb25);
            tbList.Add(tb26);
            tbList.Add(tb27);
            tbList.Add(tb28);
            tbList.Add(tb29);
            tbList.Add(tb31);
            tbList.Add(tb32);
            tbList.Add(tb33);
            tbList.Add(tb34);
            tbList.Add(tb35);
            tbList.Add(tb36);
            tbList.Add(tb37);
            tbList.Add(tb38);
            tbList.Add(tb39);
            tbList.Add(tb41);
            tbList.Add(tb42);
            tbList.Add(tb43);
            tbList.Add(tb44);
            tbList.Add(tb45);
            tbList.Add(tb46);
            tbList.Add(tb47);
            tbList.Add(tb48);
            tbList.Add(tb49);
            tbList.Add(tb51);
            tbList.Add(tb52);
            tbList.Add(tb53);
            tbList.Add(tb54);
            tbList.Add(tb55);
            tbList.Add(tb56);
            tbList.Add(tb57);
            tbList.Add(tb58);
            tbList.Add(tb59);
            tbList.Add(tb61);
            tbList.Add(tb62);
            tbList.Add(tb63);
            tbList.Add(tb64);
            tbList.Add(tb65);
            tbList.Add(tb66);
            tbList.Add(tb67);
            tbList.Add(tb68);
            tbList.Add(tb69);
            tbList.Add(tb71);
            tbList.Add(tb72);
            tbList.Add(tb73);
            tbList.Add(tb74);
            tbList.Add(tb75);
            tbList.Add(tb76);
            tbList.Add(tb77);
            tbList.Add(tb78);
            tbList.Add(tb79);
            tbList.Add(tb81);
            tbList.Add(tb82);
            tbList.Add(tb83);
            tbList.Add(tb84);
            tbList.Add(tb85);
            tbList.Add(tb86);
            tbList.Add(tb87);
            tbList.Add(tb88);
            tbList.Add(tb89);
            tbList.Add(tb91);
            tbList.Add(tb92);
            tbList.Add(tb93);
            tbList.Add(tb94);
            tbList.Add(tb95);
            tbList.Add(tb96);
            tbList.Add(tb97);
            tbList.Add(tb98);
            tbList.Add(tb99);
        }

        

        private void tb11_TextChanged(object sender, EventArgs e)
        {

        }

        static void FillGrid()
        {
            //flag++;
            StreamReader sr1 = new StreamReader(@"ques.txt");
            for(int k=0;k<10*flag;k++)
            {
                string linemore = sr1.ReadLine();
            }
            for (int i = 0; i < 9; i++)
            {
                string line = sr1.ReadLine();
                for(int j=0;j<9;j++)
                {
                    TextBox tb = tbList[i * 9 + j] as TextBox;
                    if(line[2*j] == '0')
                    {
                        tb.Text = "";
                        tb.ReadOnly = false;
                        tb.ForeColor = Color.Brown;
                        //tb.BackColor = Color.Thistle;
                        //tb.BackColor = Color.Coral;
                    }
                    else
                    {
                        tb.Text = line[2*j].ToString();
                        tb.ReadOnly = true;
                        tb.ForeColor = Color.Black;
                        tb.ForeColor = Color.Green;
                    }
                   
                }
            }
            flag++;
        }

        static void UnfinishedWarning()
        {
            MessageBox.Show("崽子，题都没写完","提示");
        }
        static void WrongAnswerWarning()
        {
            MessageBox.Show("写错啦,大兄弟！","提示");
        }
        static void PassReminding()
        {
            MessageBox.Show("写对了哦！", "通过提示");
        }

        static void OnSumitClicked()
        {
            string[] finished;
            finished = new string[10];
            for(int i=0;i<9;i++)
            {
                finished[i] = "";
                for(int j=0;j<9;j++)
                {
                    TextBox tb = tbList[i * 9 + j] as TextBox;
                    if (tb.Text == "")
                    { UnfinishedWarning(); return; }
                    finished[i] += tb.Text;
                }
            }

            int[] row={ 0, 3, 6, 27, 30, 33, 54, 57, 60};
            int[] plus = { 0, 1, 2, 9, 10, 11, 18, 19, 20 };
            for(int i=0;i<9;i++)//check the answer
            {
                int[] crow = new int[10];
                int[] ccol = new int[10];
                int[] cgrid = new int[10];
                for(int j=0;j<9;j++)//计数置零
                {
                    crow[j] = 0;
                    ccol[j] = 0;
                    cgrid[j] = 0;
                }
                for(int j=0;j<9;j++)//检测存在数字出现次数
                {
                    crow[finished[i][j] - '0']++;
                    ccol[finished[j][i] - '0']++;

                    int pos = row[i] + plus[j];
                    int c = pos / 9;
                    int d = pos % 9;
                    cgrid[finished[c][d]-'0']++;

                }
                for(int j=0;j<9;j++)
                {
                    if (crow[j] == 0 || crow[j] > 1) { WrongAnswerWarning(); return; }
                    if (ccol[j] == 0 || ccol[j] > 1) { WrongAnswerWarning(); return; }
                    if (cgrid[j] == 0 || cgrid[j] > 1) { WrongAnswerWarning(); return; }
             
                }
                
            }
            PassReminding();

        }
       // public void FillGrid()
        private void button1_Click(object sender, EventArgs e)
        {

            FillGrid();          
        }

        private void button3_Click(object sender, EventArgs e)
        {
            OnSumitClicked();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            FillGrid();
        }
        static void TrickWindow()
        {
            MessageBox.Show("没有！\n想得美！", "没想到吧，hiahiahiahia");
        }
        private void button1_Click_1(object sender, EventArgs e)
        {
            TrickWindow();
        }
    }
}
