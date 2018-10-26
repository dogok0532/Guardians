using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace ImageTest._01.Main.MapTileEditor
{
    class Tile
    {
        Bitmap TileBitMap;
        int indexX;
        int indexY;

        public Tile(string file)
        {
        }

        public void SetTileImage(ref Bitmap bit)
        {
            TileBitMap = bit;
        }

        public void Draw(ref Graphics g)
        {
            g.DrawImage(TileBitMap, -indexX / 2 * StageMap.TileWidth, indexY / 2 * StageMap.TileHeight);
        }
    }
}
