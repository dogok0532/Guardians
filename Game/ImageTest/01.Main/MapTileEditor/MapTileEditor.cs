
using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;



namespace ImageTest._01.Main.MapTileEditor
{




    public partial class MapTileEditor : Form
    {
        TileSelector tileSelector = new TileSelector();


        public MapTileEditor()
        {
            InitializeComponent();





        }
       
        private void MapTileEditor_FormClosing(object sender, FormClosingEventArgs e)
        {
            Owner.Show();
        }

        

        internal void CreateMap(decimal X, decimal Y)
        {
            int x=Convert.ToInt32(X);
            int y=Convert.ToInt32(Y);
        }

        private void tilePictureBox_Paint(object sender, PaintEventArgs e)
        {
            if (tilePictureBox.Image == null)
                return;
            int X = tilePictureBox.Image.Width / Constant.Pixel;
            int Y = tilePictureBox.Image.Height / Constant.Pixel;


            Point[] point = new Point[2];



            Pen pen = new Pen(Color.Black, 1);

            for (int i = 0; i < X; i++)
            {
                for (int j = 0; j < Y; j++)
                {
                    point[0].X = 0;
                    point[0].Y = j * 16;
                    point[1].X = tilePanel.Width;
                    point[1].Y = j * 16;

                    e.Graphics.DrawLine(pen, point[0], point[1]);
                }
                point[0].X = i * 16;
                point[0].Y = 0;
                point[1].X = i * 16;
                point[1].Y = tilePanel.Height;

                e.Graphics.DrawLine(pen, point[0], point[1]);
            }

            tileSelector.DrawSelected(e.Graphics);
        }


        private void tilePictureBox_MouseClick(object sender, MouseEventArgs e)
        {



            tilePictureBox.Refresh();

        }

        private void tileSplitContainer_Resize(object sender, EventArgs e)
        {



        }

        private void tileSplitContainer_SplitterMoved(object sender, SplitterEventArgs e)
        {


            tilePanel.Width = e.X;
            tileListBox.Width = e.X;


        }

        private void tileListBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tileListBox.SelectedItem != null)
            {
                Bitmap bit = new Bitmap( (string)tileListBox.SelectedItem);

                tilePictureBox.Image = bit;


                
            }


        }

        private void tilePictureBox_MouseDown(object sender, MouseEventArgs e)
        {
            if (tileSelector.bDragging == false)
            {
                tileSelector.SelectBegin(e.Location);
                tileSelector.bDragging = true;

            }


            tilePictureBox.Refresh();
        }

        private void tilePictureBox_MouseUp(object sender, MouseEventArgs e)
        {
            if (tileSelector.bDragging == true)
            {
                tileSelector.SelectEnd(e.Location);
                tileSelector.bDragging = false;
            }

            tilePictureBox.Refresh();
        }

        private void tilePictureBox_MouseMove(object sender, MouseEventArgs e)
        {
            if (tileSelector.bDragging == true)
                tilePictureBox.Refresh();

           
        }

        private void 새지도ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new CreateMap().Show(this);
            this.Enabled = false;
        }

        public void CreateMap(int x,int y)
        {

        }

        public string GetRelativePath(string src, string des)
        {
            string str_1;
            string str_2;
            string str = null;
            string[] a1 = new string[100];
            string[] a2 = new string[100];
            int cnt = 0;
            int i = 0;
            bool check = true;
      
            str_1 = src;
            str_2 = des;

            a1 = str_1.Split('\\');
            a2 = str_2.Split('\\');
            while (true)
            {
                try
                {
                    if (a1[i] == null)
                    {
                        break;
                    }
                }
                catch (Exception e)
                {
                    break;
                }
                
                if ( a1[i].Equals(a2[i]))
                {
                    i++;
                    continue;
                }
                else
                {
                    if (check) { cnt = i; check = false; }
                    break;
                }
            }
            i = 0;
            while (true){
                try { if (a2[i] == null) break; }
                catch(Exception e)
                {
                    i--;
                    break;
                }
                    i++;
            }
            for (int k = 1; k < cnt-1; k++)
            {
                a2[k] = "..";
            }
            for (int k = 1; k < cnt-1; k++)
            {
               
                   str += a2[k] + "/";
               
            }
            for (int k = cnt; k <= i; k++)
            {
               
                str += a2[k] ;

                if(k != i)
                    str +="\\";
            }

            return str;
        }

        private void 타일열기ToolStripMenuItem_Click(object sender, EventArgs e)
        {


        }
        private void 타일목록저장ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TilesaveFileDialog = new SaveFileDialog();
            TilesaveFileDialog.AddExtension = true;
            TilesaveFileDialog.DefaultExt = "txt";

            TilesaveFileDialog.ShowDialog();


            for (int i = 0; i < tileListBox.Items.Count; i++)
            {

            }



        }

        private void 타일추가ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TileopenFileDialog = new OpenFileDialog();
            TileopenFileDialog.Multiselect = true;
            TileopenFileDialog.ShowDialog();
            string[] fileNames = TileopenFileDialog.FileNames;

            foreach (string fileName in fileNames)
            {
                string relativePath
                 = GetRelativePath(System.Windows.Forms.Application.StartupPath, fileName);
                tileListBox.Items.Add(relativePath);
            }


            //tileListBox.
        }

        private void TileopenFileDialog_FileOk(object sender, CancelEventArgs e)
        {

        }

    }
}
