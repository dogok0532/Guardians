using ImageEditor._02.Parser;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ImageEditor._02.Parser._01.Texture;

namespace ImageEditor
{
    public partial class ImageEditor : Form
    {
        private Dictionary<string, CTexture> mapTexture;
        private CImageParser parser;


        public ImageEditor()
        {
            InitializeComponent();
            parser = new CImageParser();
            mapTexture = parser.GetParsedData();

            ImageBox.Image = null;

            TextureName.Items.AddRange(mapTexture.Keys.ToArray());

            FrameBar.Minimum = 0;
            FrameBar.Maximum = 0;

        }



        

        private void TextureName_SelectedIndexChanged(object sender, EventArgs e)
        {
            SpriteName.Items.Clear();
            SpriteName.Items.Add("-");
            SpriteName.Items.AddRange(
                mapTexture[(string)TextureName.SelectedItem].GetSpriteNameList()
                );
            ResetTexture();
            
        }

        private void SpriteName_SelectedIndexChanged(object sender, EventArgs e)
        {
            
           
        }
        
        public void ResetTexture()
        {
            Bitmap bit=new Bitmap(mapTexture[(string)TextureName.SelectedItem].GetRoute());
            ImageBox.Image = bit;
            ImageBox.Width = ImageBox.Image.Width;
            ImageBox.Width = ImageBox.Image.Height;

           
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
                TextureName.Items.AddRange(mapTexture.Keys.ToArray());
            }
        }

        private void ImageEditor_FormClosing(object sender, FormClosingEventArgs e)
        {
            Owner.Show();
        }

        private void FrameBar_Scroll(object sender, EventArgs e)
        {
            ResetTexture();
        }

        private void ResetButton_Click(object sender, EventArgs e)
        {

        }

 
    }
}
