﻿

using System.Drawing;

namespace ImageTest._02.Parser._01.Texture
{
   


    internal class CSprite
    {
        private spriteInfo m_SpriteInfo;

        public CSprite(spriteInfo SpriteInfo)
        {
            m_SpriteInfo = SpriteInfo;
        }

        public Rectangle GetFrameRect(int Frame)
        {
            Frame %= m_SpriteInfo.iFrameCount;

            int StartX = m_SpriteInfo.iXBegin
                + (m_SpriteInfo.iXSize + m_SpriteInfo.iIsLine) * (Frame % m_SpriteInfo.iXFrame);

            int StartY = m_SpriteInfo.iYBegin
                + (m_SpriteInfo.iYSize + m_SpriteInfo.iIsLine) * (Frame / m_SpriteInfo.iXFrame);

            int EndX = StartX + m_SpriteInfo.iXSize;

            int EndY = StartY + m_SpriteInfo.iYSize;

            Rectangle rc=new Rectangle(StartX,StartY,m_SpriteInfo.iXSize-1,m_SpriteInfo.iYSize-1);    //프레임, 좌표값에 따라 출력할 범위 설정


           

            return rc;
        }

        public Rectangle GetFrameSize()
        {
            return new Rectangle(0, 0, m_SpriteInfo.iXSize, m_SpriteInfo.iYSize);
        }


    }


}