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
        Csh_text txt = new Csh_text("Head");
        String s = " ";
        public Form1()
        {
            InitializeComponent();
            label1.Text = txt.getHead();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            txt.setHead(textBox1.Text);
            label1.Text = txt.getHead();
            button2.Text = "Add the section";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label2.Text = "";
            if (button2.Text != "Add the section")
                throw new Exception();
            txt.CreateSection(textBox2.Text);
            s += txt.Print_t();
            label2.Text = s;
        }
    }
}
