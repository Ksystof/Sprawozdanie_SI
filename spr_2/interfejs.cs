using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace interfejs_spr
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            label_txt_spr.Text = "";

            checkBox1.Enabled = false; // Ustawienie CheckBox jako nieaktywny przy ładowaniu formularzu
            checkBox2.Enabled = false;
            checkBox3.Enabled = false;
        }

        private void richTextBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Sprawdza, czy wprowadzony znak jest literą, liczbą lub znakiem
            if (!char.IsLetter(e.KeyChar) && !char.IsDigit(e.KeyChar) && !char.IsPunctuation(e.KeyChar))
            {
                // Jeśli nie jest, anuluje do wprowadzania znaku:
                e.Handled = true;
            }

            // Sprawdza, czy kontrolka 'RichTextBox' - już zawiera znaki:
            if (richTextBox1.Text.Length >= 1 && richTextBox1.SelectionLength == 0)
            {
                // Jeśli tak, anuluj wprowadzenie dodatkowych znaków
                e.Handled = true;

                string tekst = richTextBox1.Text.Trim(); // Pobranie tekstu z RichTextBox i usuwa początkowych i końcowych białych znaków

                TreeNode rootNode = treeView1.Nodes["a1"]; // Pobranie węzła "a1" z drzewa

                if (rootNode != null)
                {
                    TreeNode childNode = rootNode.Nodes["a1_text"]; // Pobiera węzł "a1_text" jako dziecka węzła "a1"

                    if (childNode == null)
                    {
                        childNode = new TreeNode("a1_text");
                        rootNode.Nodes.Add(childNode);
                    }

                    childNode.Text = tekst; // Zapisanie tekstu z RichTextBox w węźle "a1_text"
                    treeView1.SelectedNode = childNode; // Ustawienie węzła "a1_text" jako zaznaczonego
                }
            }
        }

        private void richTextBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Sprawdza, czy wprowadzony znak jest literą, liczbą lub znakiem
            if (!char.IsLetter(e.KeyChar) && !char.IsDigit(e.KeyChar) && !char.IsPunctuation(e.KeyChar))
            {
                // Jeśli nie jest, anuluje do wprowadzania znaku:
                e.Handled = true;
            }

            // Sprawdza, czy kontrolka 'RichTextBox' - już zawiera znaki:
            if (richTextBox2.Text.Length >= 1 && richTextBox2.SelectionLength == 0)
            {
                // Jeśli tak, anuluj wprowadzenie dodatkowych znaków
                e.Handled = true;

                string tekst = richTextBox2.Text.Trim(); // Pobranie tekstu z RichTextBox i usuwa początkowych i końcowych białych znaków

                TreeNode rootNode = treeView1.Nodes["a2"]; // Pobranie węzła "a2" z drzewa

                if (rootNode != null)
                {
                    TreeNode childNode = rootNode.Nodes["a2_text"]; // Pobiera węzł "a2_text" jako dziecka węzła "a2"

                    if (childNode == null)
                    {
                        childNode = new TreeNode("a2_text");
                        rootNode.Nodes.Add(childNode);
                    }

                    childNode.Text = tekst; // Zapisanie tekstu z RichTextBox w węźle "a2_text"
                    treeView1.SelectedNode = childNode; // Ustawienie węzła "a2_text" jako zaznaczonego
                }
            }
        }

        private void richTextBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            // Sprawdza, czy wprowadzony znak jest literą, liczbą lub znakiem
            if (!char.IsLetter(e.KeyChar) && !char.IsDigit(e.KeyChar) && !char.IsPunctuation(e.KeyChar))
            {
                // Jeśli nie jest, anuluje do wprowadzania znaku:
                e.Handled = true;
            }

            // Sprawdza, czy kontrolka 'RichTextBox' - już zawiera znaki:
            if (richTextBox3.Text.Length >= 1 && richTextBox3.SelectionLength == 0)
            {
                // Jeśli tak, anuluj wprowadzenie dodatkowych znaków
                e.Handled = true;

                string tekst = richTextBox3.Text.Trim(); // Pobranie tekstu z RichTextBox i usuwa początkowych i końcowych białych znaków

                TreeNode rootNode = treeView1.Nodes["a3"]; // Pobranie węzła "a3" z drzewa

                if (rootNode != null)
                {
                    TreeNode childNode = rootNode.Nodes["a3_text"]; // Pobiera węzł "a3_text" jako dziecka węzła "a3"

                    if (childNode == null)
                    {
                        childNode = new TreeNode("a3_text");
                        rootNode.Nodes.Add(childNode);
                    }

                    childNode.Text = tekst; // Zapisanie tekstu z RichTextBox w węźle "a3_text"
                    treeView1.SelectedNode = childNode; // Ustawienie węzła "a3_text" jako zaznaczonego
                }
            }
        }

        private void delete_a1_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            checkBox1.Checked = false;
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            if (richTextBox1.Text.Length > 0)
            {
                spr_dane.Enabled = richTextBox1.Text.Length > 0;
                

                //-------
                delete_a1.Enabled = true; // Włącz przycisk "Usuń"
                delete_all_dane.Enabled = true; // Dla ogólnego
            }
            else
            {
                delete_a1.Enabled = false; // Wyłącz przycisk "Usuń"
                delete_all_dane.Enabled = false; // Dla ogólnego
            }
        }

        private void delete_a2_Click(object sender, EventArgs e)
        {
            richTextBox2.Clear();
            checkBox2.Checked = false;
        }

        private void richTextBox2_TextChanged(object sender, EventArgs e)
        {
            if (richTextBox2.Text.Length > 0)
            {
                spr_dane.Enabled = richTextBox2.Text.Length > 0;
                

                //-----------
                delete_a2.Enabled = true; // Włącz przycisk "Usuń"
                delete_all_dane.Enabled = true; // Dla ogólnego
            }
            else
            {
                delete_a2.Enabled = false; // Wyłącz przycisk "Usuń"
                delete_all_dane.Enabled = false; // Dla ogólnego
            }
        }

        private void delete_a3_Click(object sender, EventArgs e)
        {
            richTextBox3.Clear();
            checkBox3.Checked = false;
        }

        private void richTextBox3_TextChanged(object sender, EventArgs e)
        {
            if (richTextBox3.Text.Length > 0)
            {
                spr_dane.Enabled = richTextBox3.Text.Length > 0;
                

                //-----------
                delete_a3.Enabled = true; // Włącz przycisk "Usuń"
                delete_all_dane.Enabled = true; // Dla ogólnego
            }
            else
            {
                delete_a3.Enabled = false; // Wyłącz przycisk "Usuń"
                delete_all_dane.Enabled = false; // Dla ogólnego
            }
        }

        private void delete_all_dane_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            richTextBox2.Clear();
            richTextBox3.Clear();

            checkBox1.Checked = false;
            checkBox2.Checked = false;
            checkBox3.Checked = false;
        }

        private void spr_dane_Click(object sender, EventArgs e)
        {
            bool q = richTextBox3.Text.Length > 0;
            bool r = richTextBox3.Text.Length > 0;
            bool t = richTextBox3.Text.Length > 0;

            if (q && r  && t)
            {
                bool hasNoNumbers = !richTextBox1.Text.Any(char.IsDigit);
                bool hasOnlyLetters = richTextBox2.Text.All(char.IsLetter);
                bool hasNoSpecialChars = !richTextBox3.Text.Any(c => char.IsPunctuation(c) || char.IsSymbol(c));

                checkBox1.Checked = hasNoNumbers;
                checkBox2.Checked = hasOnlyLetters;
                checkBox3.Checked = hasNoSpecialChars;

                bool r1 = checkBox1.Checked;
                bool r2 = checkBox2.Checked;
                bool r3 = checkBox3.Checked;

                if (r1 && r2 && r3)
                {
                    label_txt_spr.Text = "Są danymi!";
                }else label_txt_spr.Text = "Nie są danymi!";
            } else spr_dane.Enabled = false;
        }
    }
}
