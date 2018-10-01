using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ImageTest._02.Parser._01.Texture
{
    class CTexture
    {
        string Name;





        string ImageRoute;
       


        Dictionary<string, CSprite> mapTexture = new Dictionary<string, CSprite>();

       

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

        public CSprite GetSprite(string sprite)
        {
            CSprite value;
           mapTexture.TryGetValue(sprite,out value);
            return value;
        }
        
        public string[] GetSpriteNameList()
        {
            return mapTexture.Keys.ToArray();
        }
    }
}
