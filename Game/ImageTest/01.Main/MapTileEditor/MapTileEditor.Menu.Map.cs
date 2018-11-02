using System;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace ImageTest._01.Main.MapTileEditor
{
  


    class Dummy4 { }


    partial class MapTileEditor
    {
        private void 열기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
			
        }

        private void 저장ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog = new SaveFileDialog();
            saveFileDialog.AddExtension = true;
            saveFileDialog.DefaultExt = "mapdat";
            saveFileDialog.ShowDialog();


            XmlDocument xmlDoc = CreateTileXml();
           
			

            
            XmlNode xmlMapData = xmlDoc.CreateElement("MapData");
            xmlDoc.FirstChild.AppendChild(xmlMapData);

            XmlNode xmlXSize = xmlDoc.CreateElement("XSize");
            xmlXSize.InnerText = map.XSize.ToString();

            XmlNode xmlYSize = xmlDoc.CreateElement("YSize");
            xmlYSize.InnerText = map.YSize.ToString();

            XmlNode xmlData = xmlDoc.CreateElement("Data");
            xmlData.InnerText = map.GetData();


			
            xmlMapData.AppendChild(xmlXSize);
            xmlMapData.AppendChild(xmlYSize);
            xmlMapData.AppendChild(xmlData);

            

			xmlDoc.Save(saveFileDialog.FileName);
        }
    }
       
}
