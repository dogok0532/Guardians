using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.IO;
using System.Collections.Generic;

namespace ImageTest._01.Main.MapTileEditor
{
    //[System.ComponentModel.DesignerCategory("Code")]   
    class Dummy { }  //designer 제거용

    

    partial class MapTileEditor
    {
       
        private void 타일목록열기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TileopenFileDialog = new OpenFileDialog();
            TilesaveFileDialog.AddExtension = true;
            TileopenFileDialog.DefaultExt = "xml";
            TileopenFileDialog.ShowDialog();

            XmlDocument xmlDoc = new XmlDocument();
            xmlDoc.Load(TileopenFileDialog.FileName);

            XmlNode xmlRoot = xmlDoc.FirstChild;
            XmlNode xmlTile = xmlRoot.FirstChild;


            

        }

        private void 타일목록저장ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TilesaveFileDialog = new SaveFileDialog();
            TilesaveFileDialog.AddExtension = true;
            TilesaveFileDialog.DefaultExt = "xml";
            TilesaveFileDialog.ShowDialog();

            XmlDocument xmlDoc = new XmlDocument();

            XmlNode xmlRoot = xmlDoc.CreateElement("TileList");
            xmlDoc.AppendChild(xmlRoot);
            for (int i = 0; i < tileListBox.Items.Count; i++)
            {
                XmlNode tile = xmlDoc.CreateElement("Tile");

               
                XmlNode tileName = xmlDoc.CreateElement("Name");
                tileName.InnerText = Path.GetFileName(((TileInfo)(tileListBox.Items[i])).fileName);


                
                XmlNode tileRoute = xmlDoc.CreateElement("Route");
                tileRoute.InnerText =((TileInfo)(tileListBox.Items[i])).filePath;
                
                XmlNode tileStatus = xmlDoc.CreateElement("Status");
                {
                    XmlNode tileType = xmlDoc.CreateElement("TileType");
                   

                    if (((TileInfo)(tileListBox.Items[i])).tileType == eTileType.BLOCKED)
                    {
                        tileType.InnerText = "Blocked";
                        tileStatus.AppendChild(tileType);

                    }
                    if (((TileInfo)(tileListBox.Items[i])).tileType == eTileType.FLOOR)
                    {
                        tileType.InnerText = "Floor";
                        tileStatus.AppendChild(tileType);

                        XmlNode tileFloor = xmlDoc.CreateElement("Floor");
                        tileFloor.InnerText = ((TileInfo)(tileListBox.Items[i])).floor.ToString();
                        tileType.AppendChild(tileFloor);
                    }
                    if (((TileInfo)(tileListBox.Items[i])).tileType == eTileType.STAIR)
                    {
                        tileType.InnerText = "Stair";
                        tileStatus.AppendChild(tileType);

                        XmlNode tileStair = xmlDoc.CreateElement("Stair");
                        tileStair.InnerText = (string)stairComboBox.SelectedItem;
                        tileType.AppendChild(tileStair);
                    }
                    
                    


                }

                tile.AppendChild(tileName);
                tile.AppendChild(tileRoute);
                tile.AppendChild(tileStatus);
                //tile.AppendChild(tileStatus);
                xmlRoot.AppendChild(tile);
            }

            
            xmlDoc.Save(TilesaveFileDialog.FileName);
        }

        private void 타일추가ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            TileopenFileDialog = new OpenFileDialog();
            TileopenFileDialog.Multiselect = true;
            TileopenFileDialog.ShowDialog();
            string[] fileNames = TileopenFileDialog.FileNames;

            foreach (string file in fileNames)
            {
                TileInfo tile = new TileInfo(file);
                tileListBox.Items.Add(tile);
               
            }
        }

        private void 새지도ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new CreateMap().Show(this);
            this.Enabled = false;
        }

        private void TileopenFileDialog_FileOk(object sender, System.ComponentModel.CancelEventArgs e)
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

                if (a1[i].Equals(a2[i]))
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
            while (true)
            {
                try { if (a2[i] == null) break; }
                catch (Exception e)
                {
                    i--;
                    break;
                }
                i++;
            }
            for (int k = 1; k < cnt - 1; k++)
            {
                a2[k] = "..";
            }
            for (int k = 1; k < cnt - 1; k++)
            {

                str += a2[k] + "/";

            }
            for (int k = cnt; k <= i; k++)
            {

                str += a2[k];

                if (k != i)
                    str += "\\";
            }

            return str;
        }

    }
}
