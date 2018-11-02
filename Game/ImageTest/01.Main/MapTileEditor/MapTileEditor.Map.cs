using System;
using System.Windows.Forms;


namespace ImageTest._01.Main.MapTileEditor
{
    class Dummy2 { };

    partial class MapTileEditor : Form
    {

     

        private void mapPictureBox_MouseDown(object sender, MouseEventArgs e)
        {
           
            SetTileOnMap(e);


        }

        private void mapPictureBox_MouseUp(object sender, MouseEventArgs e)
        {
        }

       

        private void SetTileOnMap(MouseEventArgs e)
        {
            if (map != null)
            {
                map.ChangeTileInfo(e,tileListBox.SelectedIndex);
                mapPictureBox.Refresh();
            }
        }




    }
}
