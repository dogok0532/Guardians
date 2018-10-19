using ImageEditor._01.Main;
using ImageEditor._02.Parser;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;


static class Constant
{
    public const int Pixel = 16;
}

namespace ImageEditor
{
    static class Program
    {
        

        /// <summary>
        /// 해당 응용 프로그램의 주 진입점입니다.
        /// </summary>
        [STAThread]
        static void Main()
        {
          

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new GameEditor());

           
          
        }
    }
}
