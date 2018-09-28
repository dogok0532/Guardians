using ImageTest._02.Parser;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

struct RECT
{
    public long left;
    public long top;
    public long right;
    public long bottom;
}

namespace ImageTest
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
            Application.Run(new ImageTestClient());

            
          
        }
    }
}
