using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace ImageTest._01.Main.MapTileEditor
{
    class Tile
    {
       
        int indexX;
        int indexY;

        private TileInfo tileInfo;
        public int tileCode=-1;

        public Tile(int indexX, int indexY)
        {
            this.indexX = indexX;
            this.indexY = indexY;
            
        }


        public void Draw(ref Graphics g , StageMap stageMap)
        {
            if (tileInfo != null)
            {




                int yAdjust =
                   stageMap.TileHeight - tileInfo.tileImage.Height - stageMap.TileHeight / 2;





                g.DrawImage(tileInfo.tileImage,
             stageMap.TileWidth * (indexX + indexY) / 2,
             stageMap.TileHeight * (-indexX + indexY) / 2 + stageMap.GetHeight() / 2 + yAdjust);









            }
        }




        public void ChangeTileInfo(TileInfo tileInfo, int tileCode)
        {
            this.tileInfo = tileInfo;
        }
    }
}
