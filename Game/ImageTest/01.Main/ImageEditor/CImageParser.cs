
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Xml;
using System.Drawing;

using ImageEditor._02.Parser._01.Texture;

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



namespace ImageEditor._02.Parser
{
    class CImageParser
    {
        XmlDocument xml;

        public CImageParser()
        {


        }
        public Dictionary<string, CTexture> ParseTexture()  //텍스처 파싱후 Map으로 반환
        {
            xml = new XmlDocument();
            xml.Load("../../../Script/TextureList.xml");
            Dictionary<string, CTexture> mapTexture = new Dictionary<string, CTexture>();
            XmlNodeList TextureList = xml.SelectNodes("/TextureList/Texture");
            foreach (XmlNode TextureNode in TextureList)   //Texture 수만큼 루프
            {
                string strName = TextureNode["Name"].InnerText;
                XmlNode BackGround = TextureNode["BackgroundRGB"];
                if (BackGround != null && BackGround.HasChildNodes)
                {
                    int R = Int32.Parse(TextureNode["BackgroundRGB"].SelectSingleNode("R").InnerText);
                    int G = Int32.Parse(TextureNode["BackgroundRGB"].SelectSingleNode("G").InnerText);
                    int B = Int32.Parse(TextureNode["BackgroundRGB"].SelectSingleNode("B").InnerText);
                }
                string strPath = TextureNode["Path"].InnerText;
                CTexture Texture = new CTexture();
                Texture.SetName(strName);
                Texture.SetRoute("../../" + strPath);
                XmlNodeList SpriteList = TextureNode.SelectNodes("Sprite");
                foreach (XmlNode SpriteNode in SpriteList)   //Sprite 수만큼 루프
                {
                    if (SpriteNode.HasChildNodes)
                    {
                        string SpriteName = SpriteNode["Name"].InnerText;
                        spriteInfo SpriteInfo;
                        SpriteInfo.iXBegin = Int32.Parse(SpriteNode["XBegin"].InnerText);
                        SpriteInfo.iYBegin = Int32.Parse(SpriteNode["YBegin"].InnerText);
                        SpriteInfo.iIsLine = Int32.Parse(SpriteNode["isLine"].InnerText);
                        SpriteInfo.iFrameCount = Int32.Parse(SpriteNode["FrameCount"].InnerText);
                        SpriteInfo.iXFrame = Int32.Parse(SpriteNode["XFrame"].InnerText);
                        SpriteInfo.iYFrame = Int32.Parse(SpriteNode["YFrame"].InnerText);
                        SpriteInfo.iXSize = Int32.Parse(SpriteNode["XSize"].InnerText);
                        SpriteInfo.iYSize = Int32.Parse(SpriteNode["YSize"].InnerText);
                        CSprite Sprite = new CSprite(SpriteInfo);
                        Texture.AddSprite(SpriteName, Sprite);
                    }
                }
                mapTexture.Add(strName, Texture);
            }
            return mapTexture;
        }

        public void MakeXml()
        {
        }
    

    }
}
