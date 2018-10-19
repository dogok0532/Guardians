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


       
        bool isPlayingFrame = false;

        public ImageEditor()
        {
            InitializeComponent();
            parser = new CImageParser();
            mapTexture = parser.ParseTexture();

            ImageBox.Image = null;

            TextureName.Items.AddRange(mapTexture.Keys.ToArray());

            FrameBar.Minimum = 0;
            FrameBar.Maximum = 0;

            backFrameCounter.WorkerReportsProgress = true;
            backFrameCounter.WorkerSupportsCancellation = true;

            backFrameCounter.DoWork +=
                new DoWorkEventHandler(backFrameCounter_DoWork);
            backFrameCounter.RunWorkerCompleted +=
                new RunWorkerCompletedEventHandler(
            backFrameCounter_RunWorkerCompleted);
            backFrameCounter.ProgressChanged +=
                new ProgressChangedEventHandler(
            backFrameCounter_ProgressChanged);
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

        
            ResetTexture();

        }
        
        public void ResetTexture()
        {
            Bitmap bit=new Bitmap(mapTexture[(string)TextureName.SelectedItem].GetRoute());
            ImageBox.Image = bit;
            ImageBox.Width = ImageBox.Image.Width;
            ImageBox.Width = ImageBox.Image.Height;

            FrameBar.Maximum = mapTexture[(string)TextureName.SelectedItem].GetFrameCount((string)SpriteName.SelectedItem)-1;
            if (FrameBar.Maximum < 0)
                FrameBar.Maximum = 0;

            if (FrameBar.Minimum < 0)
                FrameBar.Minimum = 0;

        }

        private void ImageBox_Paint(object sender, PaintEventArgs e)
        {
            if(ImageBox.Image != null)
                ImageBox.Size = ImageBox.Image.Size;

            Rectangle rcImageBox=new Rectangle(ImageBox.Location,ImageBox.Size);
            if (TextureName.SelectedItem != null && mapTexture[(string)TextureName.SelectedItem] != null)
            {
                

                if (mapTexture[(string)TextureName.SelectedItem].isSprite((string)SpriteName.SelectedItem))
                {
                    Rectangle rcSource;
                    if (!FrameBar.Enabled)
                    {
                        rcSource = mapTexture[(string)TextureName.SelectedItem].GetSpriteRect((string)SpriteName.SelectedItem);
                       
                    }
                    else
                    {
                        mapTexture[(string)TextureName.SelectedItem].TryGetRect((string)SpriteName.SelectedItem, FrameBar.Value, out rcSource);
                        
                    }

                    rcImageBox.Size = rcSource.Size;
                    ImageBox.Size = rcImageBox.Size;
                    e.Graphics.DrawImage(ImageBox.Image, ImageBox.DisplayRectangle, rcSource, GraphicsUnit.Pixel);
                }
              
            }

        }



        private void ImageEditor_FormClosing(object sender, FormClosingEventArgs e)
        {
            Owner.Show();
        }

   
           

        private void ResetButton_Click(object sender, EventArgs e)
        {
            if (parser != null)
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

        private void radButtonSpriteView_CheckedChanged(object sender, EventArgs e)
        {
            FrameBar.Enabled = false;
            isPlayingFrame = false;
            if (backFrameCounter.IsBusy)
                backFrameCounter.CancelAsync();
            PlayButton_Click(null, null);

            ResetTexture();
        }

        private void radButtonFrameView_CheckedChanged(object sender, EventArgs e)
        {
            FrameBar.Enabled = true;
            ResetTexture();
        }

        private void PlayButton_Click(object sender, EventArgs e)
        {
           if( isPlayingFrame )
            {
                isPlayingFrame = false;
                PlayButton.Text = "Play";
                if (backFrameCounter.IsBusy)
                    backFrameCounter.CancelAsync();
            }
           else
            {
                isPlayingFrame = true;
                PlayButton.Text = "Stop";

               if(!backFrameCounter.IsBusy)
                   backFrameCounter.RunWorkerAsync(FrameBar.Value);
            }

        }

        private void backFrameCounter_DoWork(object sender, DoWorkEventArgs e)
        {
            BackgroundWorker worker = sender as BackgroundWorker;
            int i = 0;

           while(true)
            {
                i++;

                if (i > FrameBar.Maximum)
                    i = 0;


               if(worker.CancellationPending ==true)
                {
                    e.Cancel = true;
                    break;
                }
                else
                {
                   

                    System.Threading.Thread.Sleep(100);

                   
                    worker.ReportProgress(0,i);


                }

            }

            
        }

        private void backFrameCounter_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            if( (int)e.UserState >= FrameBar.Maximum)
            {
                FrameBar.Value = FrameBar.Maximum;
                return;
            }
        
               

            FrameBar.Value = (int)e.UserState;

           
        }

        private void backFrameCounter_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            
        }

        private void FrameBar_Changed(object sender, EventArgs e)
        {
            ResetTexture();

        }
    }
}
