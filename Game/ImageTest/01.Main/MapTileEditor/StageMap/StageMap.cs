
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Xml;
using System.IO;
using System;

namespace ImageTest._01.Main.MapTileEditor
{
    public class StageMap
    {
        public int XSize { get; }
        public int YSize { get; }
        private int[,] vTileCode;

        public int TileWidth=64;
        public int TileHeight=32;


        public int GetWidth()
        {
            return (XSize+YSize)/2 * TileWidth;
        }
        public int GetHeight()
        {
            return (XSize + YSize) / 2 * TileHeight;
        }

    

        public StageMap(int xSize, int ySize)
        {
            vTileCode = new int[xSize, ySize];
            for (int i = 0; i < xSize;i++)
            {
                for (int j = 0; j < ySize; j++)
                    vTileCode[i,j] = -1;
            }
            XSize = xSize;
            YSize = ySize;

          
        
        }

     

        

        public void ChangeTileInfo(MouseEventArgs e,int tileCode)
        {
            int xCoord = e.X;
            int yCoord = e.Y - GetHeight() / 2;

            

            float newCoordX = xCoord/(float)TileWidth - yCoord/ (float)TileHeight;
            float newCoordY = xCoord/ (float)TileWidth + yCoord/ (float)TileHeight;

            int indexX = (int)newCoordX;
            int indexY = (int)newCoordY;
            
            
        if (indexX < 0 || indexY >= XSize ||
            indexY < 0 || indexY >= YSize)
            return;



            vTileCode[indexX, indexY] = tileCode;


        }

        public void DrawLine(ref Graphics g)
        {
            Pen pen = new Pen(Color.Black);

            for (int i = 0; i < XSize + 1; i++)
            {



                g.DrawLine(pen, XSize* TileWidth/2 - i * TileWidth / 2,
                            i * TileHeight / 2,
                           GetWidth() - i * TileWidth / 2,
                            GetHeight() -TileHeight/2*XSize + i * TileHeight / 2);

                

            }
            for (int i = 0; i < YSize + 1; i++)
            {
                g.DrawLine(pen, XSize * TileWidth / 2 + i * TileWidth / 2,
                        i * TileHeight / 2,
                       i * TileWidth / 2,
                       TileHeight * XSize/2 + i * TileHeight / 2);
            }
        }

        public void Draw(Graphics g,ListBox tileListBox)
        {
            DrawLine(ref g);


            

            for (int i=XSize-1; i >=0;i--)
            {
                for (int j = 0; j < YSize; j++)
                {
                    if (vTileCode[i,j] != -1)
                    {
                        int yAdjust =
                            TileHeight - ((TileInfo)tileListBox.Items[vTileCode[i, j]]).tileImage.Height - TileHeight / 2;

                        g.DrawImage( ((TileInfo)tileListBox.Items[vTileCode[i, j]]).tileImage,
                             TileWidth * (i + j) / 2,
                            TileHeight * (-i + j) / 2 + GetHeight() / 2 + yAdjust);
                    }
                }
            }
        }


        public string GetData()
        {
            string MapTileInfo="";
            for(int i=0;i<XSize;i++)
            {
                for(int j=0;j<YSize;j++)
                {
                    MapTileInfo += vTileCode[i, j];
                }
            }



            return MapTileInfo;
        }

        internal void ResetTile(int removedTile)
        {
            throw new NotImplementedException();
        }
    }


}
