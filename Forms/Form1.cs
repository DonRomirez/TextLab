using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MyDLL;

namespace Forms
{
    public partial class Form1 : Form
    {
        Csh_text txt = new Csh_text(" ");
        public Form1()
        {
            InitializeComponent();
            label1.Text = txt.getHead();
            label2.Text = " ";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            txt.setHead(textBox1.Text);
            label1.Text = txt.getHead();
            button2.Text = "Add the section";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            button3.Text = "Add the text of section";
            String s = " ";
            label2.Text="";
            if (button2.Text != "Add the section")
                throw new Exception();
            txt.CreateSection(textBox2.Text);
            s += txt.String_t();
            label2.Text = s;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            String s = " ";
            label2.Text = "";
            if (button3.Text != "Add the text of section")
                throw new Exception();
            txt.CreateSubSection(textBox2.Text);
            s = txt.String_t();
            label2.Text = s;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            String s = " ";
            label2.Text = "";
            txt.Delete_Section();
            s = txt.String_t();
            label2.Text = s;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            String s = " ";
            label2.Text = "";
            txt.Previous();
            s = txt.String_t();
            label2.Text = s;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            String s = " ";
            label2.Text = "";
            txt.Next();
            s = txt.String_t();
            label2.Text = s;
        }

        private void label2_Click(object sender, EventArgs e)
        {
            return;
        }
    }
}
