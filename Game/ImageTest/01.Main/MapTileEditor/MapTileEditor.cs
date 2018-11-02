
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
                tileRoute[i] = ((TileInfo)(tileListBox.Items[i])).filePath;
            }
            map = new StageMap(x, y);
            
            

            mapPictureBox.Refresh();
        }


        private void tileSplitContainer_Resize(object sender, EventArgs e)
        {
            tileSplitContainer.Panel1.Width = tileSplitContainer.Width;


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
               map.Draw(myBuffer.Graphics,tileListBox);
            }

            myBuffer.Render();
            myBuffer.Render(e.Graphics);
            myBuffer.Dispose();
            
        }

        private void tileListBox_SelectedIndexChanged(object sender, EventArgs e)
        {

            blockedRadioButton.Checked = false;
            stairRadioButton.Checked = false;
            floorRadioButton.Checked = false;

            if (tileListBox.SelectedItem != null)
            {
                Bitmap bit = new Bitmap(((TileInfo)tileListBox.SelectedItem).tileImage);
                tilePictureBox.Image = bit;
                tilePictureBox.Height = bit.Height;
                tilePictureBox.Width = bit.Width;



                if (((TileInfo)tileListBox.SelectedItem).tileType == eTileType.BLOCKED)
                {
                    blockedRadioButton.Checked = true;

                }
                if (((TileInfo)tileListBox.SelectedItem).tileType == eTileType.STAIR)
                {
                    stairRadioButton.Checked = true;
                }
                if (((TileInfo)tileListBox.SelectedItem).tileType == eTileType.FLOOR)
                {
                    floorRadioButton.Checked = true;
                }
            }
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

        private void blockedRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (blockedRadioButton.Checked)
            {
                ((TileInfo)(tileListBox.SelectedItem)).tileType = eTileType.BLOCKED;
            }
        }

        private void floorRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (floorRadioButton.Checked)
            {
                ((TileInfo)(tileListBox.SelectedItem)).tileType = eTileType.FLOOR;
            }
        }

        private void stairRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (stairRadioButton.Checked)
            {
                
                ((TileInfo)(tileListBox.SelectedItem)).tileType = eTileType.STAIR;
            }
        }

        private void floorComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            ((TileInfo)(tileListBox.SelectedItem)).floor = Int32.Parse((string) floorComboBox.SelectedItem);

        }

        private void stairComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if( (string)stairComboBox.SelectedItem == "↖")
            {
                ((TileInfo)(tileListBox.SelectedItem)).way = eWay.LEFT_UP;
            }

            if ((string)stairComboBox.SelectedItem == "↙")
            {
                ((TileInfo)(tileListBox.SelectedItem)).way = eWay.LEFT_DOWN;
            }

            if ((string)stairComboBox.SelectedItem == "↘")
            {
                ((TileInfo)(tileListBox.SelectedItem)).way = eWay.RIGHT_DOWN;
            }

            if ((string)stairComboBox.SelectedItem == "↗")
            {
                ((TileInfo)(tileListBox.SelectedItem)).way = eWay.RIGHT_UP;
            }
        }

        private void removeTIleButton_Click(object sender, EventArgs e)
        {
            if (tileListBox.SelectedItem != null)
            { tileListBox.Items.RemoveAt(tileListBox.SelectedIndex);

                ResetTile(tileListBox.SelectedIndex);
            }
         
        }

        void ResetTile(int removedTile)
        {
            map.ResetTile(removedTile);
        }
    }
}
