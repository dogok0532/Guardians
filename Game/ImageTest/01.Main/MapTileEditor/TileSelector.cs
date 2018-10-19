using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace ImageTest._01.Main.MapTileEditor
{
    class TileSelector
    {
        private int tileX;
        private int tileY;

        private int beginX;
        private int beginY;
        private int endX;
        private int endY;
        public bool bDragging { get; set; }

        public TileSelector()
        {
            bDragging = false;
        }
        

        public void SelectBegin(Point mouse)
        {
            
             beginX = mouse.X / Constant.Pixel;
             beginY = mouse.Y / Constant.Pixel;


            endX = mouse.X / Constant.Pixel+1;
            endY = mouse.Y / Constant.Pixel+1;


        }

        public void SelectEnd(Point mouse)
        {

            endX = mouse.X / Constant.Pixel+1;
            endY = mouse.Y / Constant.Pixel+1;

           
            if(beginX > endX)
            {
                int temp = endX;
                endX = beginX;
                beginX = temp;
            }
            if (beginY > endY)
            {
                int temp = endY;
                endY = beginY;
                beginY = endY;
            }
        }
            public void DrawSelected(Graphics g)
        {
            Pen pen = new Pen(Color.Red, 2);

            beginX *= Constant.Pixel;
            beginY *= Constant.Pixel;
            endX *= Constant.Pixel;
            endY *= Constant.Pixel;

            g.DrawLine(pen, beginX, beginY, beginX, endY);
            g.DrawLine(pen, beginX, endY, endX, endY);
            g.DrawLine(pen, endX, endY, endX, beginY);
            g.DrawLine(pen, endX, beginY, beginX, beginY);

            beginX /= Constant.Pixel;
            beginY /= Constant.Pixel;
            endX /= Constant.Pixel;
            endY /= Constant.Pixel;
        }



       
    }
}
