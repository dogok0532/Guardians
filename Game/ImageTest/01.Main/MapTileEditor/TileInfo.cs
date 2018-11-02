using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml;
using System.Drawing;
using System.Windows.Forms;

namespace ImageTest._01.Main.MapTileEditor
{
    public enum eTileType
    {
        NONE,
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
       


        public TileInfo(string filePath)   //타일 추가를 통해 새로운 타일 생성
        {
            if (Path.IsPathRooted(filePath))
            {
                tileImage = new Bitmap(filePath);
                filePath = GetRelativePath(filePath);
            }
            else
            {
                string fullPath = Path.GetFullPath(filePath);
                tileImage = new Bitmap(fullPath);

            }
            this.filePath = filePath;
        }



        public int tileCode;
        public string filePath { get; }
        public string fileName { get { return Path.GetFileName(filePath); } }
        public Bitmap tileImage { get; }


        public eTileType tileType { get; set; }

        public int floor;
        public eWay way;


        public bool[] BlockedWay = new bool[(int)eWay.WAY_MAX];

        private string GetRelativePath(string des)
        {
            Uri Client = new Uri(Application.ExecutablePath);
            Uri Absolute = new Uri(des);
            Uri relative = Client.MakeRelativeUri(Absolute);

            return relative.OriginalString;

        }

    }
}