
using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;


namespace ImageTest._01.Main.MapTileEditor
{
    public partial class MapTileEditor : Form
    {
       
        private StageMap map;
        Graphics g;
        

        public MapTileEditor()
        {
            InitializeComponent();
            g = mapPictureBox.CreateGraphics();


            tileListBox.DisplayMember = "fileName";
            
           
        }
       
        private void MapTileEditor_FormClosing(object sender, FormClosingEventArgs e)
        {
            Owner.Show();
        }

        

        public void CreateMap(decimal X, decimal Y)
        {
            int x=Convert.ToInt32(X);
            int y=Convert.ToInt32(Y);

            string[] tileRoute = new String[tileListBox.Items.Count];
            for (int i = 0;i< tileListBox.Items.Count; i++)
            {
                tileRoute[i] = (string)tileListBox.Items[i];
            }
            map = new StageMap(x, y, tileRoute);
        }


        private void tileSplitContainer_Resize(object sender, EventArgs e)
        {



        }


        public void CreateMap(int x,int y)
        {
            

            
        }



        private void mapPictureBox_Paint(object sender, PaintEventArgs e)
        {
            BufferedGraphicsContext currentContext;
            BufferedGraphics myBuffer;
            currentContext = BufferedGraphicsManager.Current;
            myBuffer = currentContext.Allocate(e.Graphics, e.ClipRectangle);

            myBuffer.Graphics.Clear(Form.DefaultBackColor);

            if (map != null)
            {
                myBuffer.Graphics.Clear(Color.White);
                mapPictureBox.Width = map.GetWidth();
                mapPictureBox.Height = map.GetHeight();
               map.Draw(myBuffer.Graphics);
            }

            myBuffer.Render();
            myBuffer.Render(e.Graphics);
            myBuffer.Dispose();
            
        }

        private void tileListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            Bitmap bit = new Bitmap(((TileInfo)tileListBox.SelectedItem).tileImage);
            tilePictureBox.Image = bit;
            tilePictureBox.Height = bit.Height;
            tilePictureBox.Width = bit.Width;
        }

        private void tileSeperateBlockPicture_Paint(object sender, PaintEventArgs e)
        {
            Pen redPen = new Pen(Color.Red,2);
            Pen blackPen = new Pen(Color.Black, 1);
            Pen pen;

            int width = tileSeperateBlockPicture.Width-1;
            int height = tileSeperateBlockPicture.Height-1;

            if (checkBox_LeftUp.Checked)
                pen = redPen;
            else
                pen = blackPen;
            e.Graphics.DrawLine(pen,width/2,0,0,height/2);

            if (checkBox_LeftDown.Checked)
                pen = redPen;
            else
                pen = blackPen;
            e.Graphics.DrawLine(pen,0,height/2,width/2,height );


            if (checkBox_RightDown.Checked)
                pen = redPen;
            else
                pen = blackPen;

            e.Graphics.DrawLine(pen,width/2,height,width,height/2);

            if (checkBox_RightUp.Checked)
                pen = redPen;
            else
                pen = blackPen;
            e.Graphics.DrawLine(pen,width,height/2,width/2,0);

        }

        private void checkBox_LeftTop_CheckedChanged(object sender, EventArgs e)
        {
            tileSeperateBlockPicture.Refresh();
        }

        private void checkBox_RightTop_CheckedChanged(object sender, EventArgs e)
        {
            tileSeperateBlockPicture.Refresh();
        }

        private void checkBox_LeftDown_CheckedChanged(object sender, EventArgs e)
        {
            tileSeperateBlockPicture.Refresh();
        }

        private void checkBox_RightDown_CheckedChanged(object sender, EventArgs e)
        {
            tileSeperateBlockPicture.Refresh();
        }

       
    }
}
