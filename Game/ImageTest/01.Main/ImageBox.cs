using ImageTest._02.Parser;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageTest
{
    public partial class ImageTestClient : Form
    {
        public ImageTestClient()
        {
            InitializeComponent();
            parser = new CImageParser();
        }

        private void DrawButton_Click(object sender, EventArgs e)
        {
            ImageBox.SizeMode = PictureBoxSizeMode.Normal;

           

           
            
           ImageBox.Image = parser.GetImage();
            Rectangle rc = parser.GetFrameRect();
            
           

        }
    }
}
