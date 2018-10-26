
using System.Collections.Generic;
using System.Drawing;


namespace ImageTest._01.Main.MapTileEditor
{
    public class StageMap
    {
        private int XSize;
        private int YSize;
        private Tile[,] vTile;

        public static int TileWidth=32;
        public static int TileHeight=16;


        public int GetWidth()
        {
            return XSize * TileWidth;
        }
        public int GetHeight()
        {
            return YSize * TileHeight;
        }

        Dictionary<string, Bitmap> tileBitList= new Dictionary<string, Bitmap>();

        public StageMap(int xSize, int ySize,string[] tileRoute)
        {
            vTile = new Tile[xSize, ySize];
            XSize = xSize;
            YSize = ySize;

          
          
            foreach(string str in tileRoute)
            {
                
                Bitmap bit = new Bitmap(str);
                tileBitList.Add(str,bit);

            }
        }

        public void SetTile(int x,int y ,string tileRoute)
        {
            Bitmap resultBit;
            if(tileBitList.TryGetValue(tileRoute, out resultBit))
             vTile[x,y].SetTileImage(ref resultBit);
        }

        public void DrawLine(ref Graphics g)
        {
            Pen pen = new Pen(Color.Black);

            for(int i=0;i<XSize+1;i++)
            {

                g.DrawLine(pen, GetWidth() / 2 - i * TileWidth / 2,
                            i * TileHeight / 2,
                            GetWidth() - i * TileWidth / 2,
                            GetHeight() / 2 + i * TileHeight / 2);

                g.DrawLine(pen, GetWidth() / 2 + i * TileWidth / 2,
                           i * TileHeight / 2,
                           i * TileWidth / 2,
                           GetHeight() / 2 + i * TileHeight / 2);

            }
        }

        public void Draw(Graphics g)
        {
            DrawLine(ref g);
            foreach (Tile tile in vTile)
            {
                if(tile != null)           
                tile.Draw(ref g);
            }
        }
    }


}
