
using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;


namespace ImageTest._01.Main.MapTileEditor
{
    public partial class MapTileEditor : Form
    {
        TileSelector tileSelector = new TileSelector();
        private StageMap map;
        Graphics g;
        

        public MapTileEditor()
        {
            InitializeComponent();
            g = pictureBox2.CreateGraphics();
           
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

        private void pictureBox2_Paint(object sender, PaintEventArgs e)
        {
           

            if (map != null)
            {
                pictureBox2.Width = map.GetWidth();
                pictureBox2.Height = map.GetHeight();
               map.Draw(ref g);
            }
        }
    }
}
