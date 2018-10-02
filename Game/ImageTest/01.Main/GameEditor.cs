using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ImageEditor;

namespace ImageEditor._01.Main
{
   

    public partial class GameEditor : Form
    {
        

        public GameEditor()
        {
            
            InitializeComponent();

        }

        private void StageDesigner_Click(object sender, EventArgs e)
        {
            
        }

        private void ImageEditor_Click(object sender, EventArgs e)
        {

            
            new ImageEditor().Show(this);

            this.Hide();
        }

        
        
    }
}
