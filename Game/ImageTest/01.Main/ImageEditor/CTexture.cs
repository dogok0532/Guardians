using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace ImageEditor._02.Parser._01.Texture
{
    class CTexture
    {
        string Name;
        string ImageRoute;


        Dictionary<string, CSprite> mapTexture = new Dictionary<string, CSprite>();

        public bool isSprite(string strSprite)
        {
            if (strSprite == null)
                return false;

            CSprite sprite =new CSprite();
            return mapTexture.TryGetValue(strSprite,out sprite);

           
        }

        public void SetName(string name)
        {
            Name = name;
        }
        public void SetRoute(string imageRoute)
        {
            ImageRoute = imageRoute;
        }
        public string GetRoute()
        {
            return ImageRoute;
        }

        public void AddSprite(string name,CSprite sprite)
        {
            mapTexture.Add(name, sprite);
        }

               
        public string[] GetSpriteNameList()
        {
            return mapTexture.Keys.ToArray();
        }


        public Rectangle GetSpriteRect(string sprite)
        {
            CSprite value;
            mapTexture.TryGetValue(sprite, out value);
            return value.GetSpriteRect();
        }

        public bool TryGetRect(string sprite, int frame, out Rectangle rc)
        {
            CSprite value;
            rc = new Rectangle();
            if (sprite == null)
            {
                
                return false;
            }
            if (mapTexture.TryGetValue(sprite, out value))
            {
                rc = value.GetFrameRect(frame);

                return true;
            }

            return false;



        }

        public int GetFrameCount(string sprite)
        {
            CSprite value;

            if (sprite == null)
                return 0;
            if (mapTexture.TryGetValue(sprite, out value))
            {
                return value.GetFrameCount();
            }
            return 0;
        }

    }
}
