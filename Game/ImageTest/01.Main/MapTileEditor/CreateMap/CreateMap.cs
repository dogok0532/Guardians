using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageTest._01.Main.MapTileEditor
{
    public partial class CreateMap : Form
    {
        public CreateMap()
        {
            InitializeComponent();
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            ((MapTileEditor)Owner).CreateMap(xNum.Value,yNum.Value);
            


            this.Close();
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void CreateMap_FormClosing(object sender, FormClosingEventArgs e)
        {
            
            Owner.Enabled = true;
            
        }
    }
}
