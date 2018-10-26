using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;
using System.Drawing;


namespace ImageTest._01.Main.MapTileEditor
{
    public enum eTileType
    {
        BLOCKED,
        FLOOR,
        STAIR
    }
    public enum eWay
    {
        LEFT_UP = 0,
        LEFT_DOWN,
        RIGHT_DOWN,
        RIGHT_UP,
        WAY_MAX
    }

    public class TileInfo
    {
        public TileInfo(XmlNode xmlTile)   //타일목록 열기를 통해 타일정보 생성
        {
            XmlNode xmlName = xmlTile.SelectSingleNode("Name");
            XmlNode xmlRoute = xmlTile.SelectSingleNode("Route");
            //XmlNode xmlStatus = xmlTile.SelectSingleNode("Status");

            string tileName = xmlName.InnerText;
            string tileRoute = xmlRoute.InnerText;
            //string tileStatus = xmlStatus.InnerText;

        }

        public TileInfo(string filePath)   //타일 추가를 통해 새로운 타일 생성
        {
            this.filePath = filePath;
            tileImage = new Bitmap(filePath);
        }




        public string filePath { get; }
        public string fileName { get { return Path.GetFileName(filePath); } }
        public Bitmap tileImage { get; }


        public eTileType tileType { get; set; }

        public int floor;
        public eWay way;


        public bool[] BlockedWay = new bool[(int)eWay.WAY_MAX];
       
       

    }
}