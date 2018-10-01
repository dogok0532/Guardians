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
using ImageTest._02.Parser._01.Texture;

namespace ImageTest
{
    public partial class ImageTestClient : Form
    {

        public ImageTestClient()
        {
            InitializeComponent();
            parser = new CImageParser();
            ImageBox.Image = null;
        

            TextureName.Items.AddRange(parser.GetTextureList());
            
        }

        private void DrawButton_Click(object sender, EventArgs e)
        {
            parser.AddFrame();
            ResetImage();
            
        }

        private void ImageBox_Paint(object sender, PaintEventArgs e)
        {
            Rectangle rcSize = new Rectangle(0, 0, 100, 100);
            if (ImageBox.Image != null)
            {
                rcSize = parser.GetFrameSize();
                ImageBox.Width = ImageBox.Image.Width;
                ImageBox.Height = ImageBox.Image.Height;
            }
           

            if (ImageBox.Image != null)
            {
                e.Graphics.Clear(ImageBox.BackColor);
            

                e.Graphics.DrawImage(ImageBox.Image,
                    rcSize,
                    parser.GetFrameRect(),
                    GraphicsUnit.Pixel);
            }
        }

        private void TextureName_SelectedIndexChanged(object sender, EventArgs e)
        {
            SpriteName.Items.Clear();

           
            SpriteName.Items.AddRange(parser.GetSpriteList(TextureName.Text));
           
               
            
        }

        private void SpriteName_SelectedIndexChanged(object sender, EventArgs e)
        {
            ResetImage();
        }
        
        public void ResetImage()
        {
            parser.SetImage(TextureName.Text, SpriteName.Text);
            ImageBox.Image = parser.GetImage();
        }

        private void Reset_Click(object sender, EventArgs e)
        {
            if(parser != null)
            {
                parser = null;
                parser = new CImageParser();

                TextureName.Items.Clear();
                TextureName.SelectedItem = null;
                SpriteName.Items.Clear();
                SpriteName.SelectedItem = null;
                TextureName.Items.AddRange(parser.GetTextureList());
            }
        }
    }
}
