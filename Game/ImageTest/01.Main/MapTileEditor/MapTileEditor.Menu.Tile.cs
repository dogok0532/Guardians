using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.IO;



namespace ImageTest._01.Main.MapTileEditor
{
    //[System.ComponentModel.DesignerCategory("Code")]   
    class Dummy { }  //designer 제거용

    

    partial class MapTileEditor
    {
       
        private void 타일목록열기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialog = new OpenFileDialog();
            saveFileDialog.AddExtension = true;
            openFileDialog.DefaultExt = "xml";
            openFileDialog.ShowDialog();

            XmlDocument xmlDoc = new XmlDocument();
            xmlDoc.Load(openFileDialog.FileName);
            OpenTileXml(xmlDoc);
            

        }

        private void 타일목록저장ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog = new SaveFileDialog();
            saveFileDialog.AddExtension = true;
            saveFileDialog.DefaultExt = "xml";
            saveFileDialog.ShowDialog();


            XmlDocument xmlDocument = CreateTileXml();
            if (saveFileDialog.FileName != "")
                 xmlDocument.Save(saveFileDialog.FileName);
        }

        private void 타일추가ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialog = new OpenFileDialog();
            openFileDialog.Multiselect = true;
            openFileDialog.ShowDialog();
            string[] fileNames = openFileDialog.FileNames;

            foreach (string file in fileNames)
            {
             
                TileInfo tile = new TileInfo(file);
                tile.tileCode = tileListBox.Items.Count;
                tileListBox.Items.Add(tile);
               
            }
        }

        private void 새지도ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new CreateMap().Show(this);
            this.Enabled = false;
        }

        public void OpenTileXml(XmlDocument xmlDoc)
        {
            tileListBox.Items.Clear();

            XmlNode xmlRoot = xmlDoc.FirstChild;
            XmlNodeList xmlTileList = xmlRoot.SelectSingleNode("TileList").SelectNodes("Tile");
            foreach (XmlNode xmlTile in xmlTileList)
            {
                XmlNode xmlName = xmlTile.SelectSingleNode("Name");
                XmlNode xmlRoute = xmlTile.SelectSingleNode("Route");
                XmlNode xmlStatus = xmlTile.SelectSingleNode("Status");


                TileInfo newTile = new TileInfo(xmlRoute.InnerText);
                if (xmlStatus.InnerText == "Blocked")
                {
                    newTile.tileType = eTileType.BLOCKED;
                }
                if (xmlStatus.InnerText == "Floor")
                {
                    newTile.tileType = eTileType.FLOOR;

                    XmlNode xmlFloor = xmlStatus.SelectSingleNode("Floor");

                    Int32.TryParse(xmlFloor.InnerText, out newTile.floor);

                }
                if (xmlStatus.InnerText == "Stair")
                {
                    newTile.tileType = eTileType.STAIR;
                    XmlNode xmlStair = xmlStatus.SelectSingleNode("Stair");

                    if (xmlStair.InnerText == "↖" || xmlStair.InnerText == "LEFT_UP")
                    {
                        newTile.way = eWay.LEFT_UP;
                    }
                    if (xmlStair.InnerText == "↙" || xmlStair.InnerText == "LEFT_DOWN")
                    {
                        newTile.way = eWay.LEFT_DOWN;
                    }
                    if (xmlStair.InnerText == "↘" || xmlStair.InnerText == "RIGHT_DOWN")
                    {
                        newTile.way = eWay.RIGHT_DOWN;
                    }
                    if (xmlStair.InnerText == "↗" || xmlStair.InnerText == "RIGHT_UP")
                    {
                        newTile.way = eWay.RIGHT_UP;
                    }
                }

                tileListBox.Items.Add(newTile);



            }

           
        }

        public XmlDocument CreateTileXml()
        {
            XmlDocument xmlDoc = new XmlDocument();
            XmlNode xmlRoot = xmlDoc.CreateElement("Root");
            XmlNode xmlTileList = xmlDoc.CreateElement("TileList");
            xmlDoc.AppendChild(xmlRoot);
            xmlRoot.AppendChild(xmlTileList);
            for (int i = 0; i < tileListBox.Items.Count; i++)
            {
                XmlNode tile = xmlDoc.CreateElement("Tile");
                XmlNode tileName = xmlDoc.CreateElement("Name");
                tileName.InnerText = ((TileInfo)(tileListBox.Items[i])).fileName;
                XmlNode tileRoute = xmlDoc.CreateElement("Route");
                tileRoute.InnerText = ((TileInfo)(tileListBox.Items[i])).filePath;
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

                xmlTileList.AppendChild(tile);
            }

            return xmlDoc;
        }
      
    
        
    }
}
