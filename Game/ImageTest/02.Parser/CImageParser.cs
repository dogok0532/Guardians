
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Xml;


using ImageTest._02.Parser._01.Texture;

struct spriteInfo
{
    public int iXBegin;    //Sprite의 텍스쳐내 시발점X
    public int iYBegin;    //Sprite의 텍스쳐내 시발점Y
    public int iIsLine; //0이면 라인없음, 1이상이면 라인의 사이즈
    public int iFrameCount; // 총 프레임 개수
    public int iXFrame;    //수평 프레임 개수
    public int iYFrame;    //수직 프레임 개수
    public int iXSize;     // SpriteFrame의 X크기
    public int iYSize;     // SpriteFrame의 Y크기
};



namespace ImageTest._02.Parser
{


    class CImageParser
    {
       XmlDocument xml;
       Dictionary<string, CTexture> mapTexture= new Dictionary<string, CTexture>();

        public CImageParser()
            {
            xml = new XmlDocument();
            xml.Load("../../../Script/TextureList.xml");



            XmlNodeList TextureList = xml.SelectNodes("/TextureList/Texture");

           

            foreach(XmlNode TextureNode in TextureList)   //Texture 수만큼 루프
            {
                string strName = TextureNode["Name"].InnerText;

                XmlNode BackGround = TextureNode["BackgroundRGB"];

                if ( BackGround != null  && BackGround.HasChildNodes)
                {
                    int R = Int32.Parse(TextureNode["BackgroundRGB"].SelectSingleNode("R").InnerText);
                    int G = Int32.Parse(TextureNode["BackgroundRGB"].SelectSingleNode("G").InnerText);
                    int B = Int32.Parse(TextureNode["BackgroundRGB"].SelectSingleNode("B").InnerText);
                }
                
                string strPath = TextureNode["Path"].InnerText;

                CTexture Texture = new CTexture();
                Texture.SetName(strName);
                Texture.SetRoute(strPath);

                XmlNodeList SpriteList = TextureNode.SelectNodes("Sprite");


               
                foreach(XmlNode SpriteNode in SpriteList)   //Sprite 수만큼 루프
                {
                    if (SpriteNode.HasChildNodes)
                    {
                        string SpriteName = SpriteNode["Name"].InnerText;
                        spriteInfo SpriteInfo;

                  
                         SpriteInfo.iXBegin= Int32.Parse(SpriteNode["iXBegin"].InnerText);
                        SpriteInfo.iYBegin= Int32.Parse(SpriteNode["iYBegin"].InnerText);
                        SpriteInfo.iIsLine = Int32.Parse(SpriteNode["iIsLine"].InnerText);
                        SpriteInfo.iFrameCount = Int32.Parse(SpriteNode["iFrameCount"].InnerText);
                        SpriteInfo.iXFrame = Int32.Parse(SpriteNode["iXFrame"].InnerText);
                        SpriteInfo.iYFrame = Int32.Parse(SpriteNode["iYFrame"].InnerText);
                        SpriteInfo.iXSize = Int32.Parse(SpriteNode["iXSize"].InnerText);
                        SpriteInfo.iYSize = Int32.Parse(SpriteNode["iYSize"].InnerText);

                        SpriteList = new CSprite(SpriteInfo);

                       






                        Texture.AddSprite()

                    }
                }


                mapTexture.Add(strName, Texture);
            }

            }
        

    }
}
