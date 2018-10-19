namespace ImageTest._01.Main.MapTileEditor
{
    partial class MapTileEditor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MapTileEditor));
            this.MenuStrip = new System.Windows.Forms.MenuStrip();
            this.파일ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.타일열기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.타일목록저장ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.타일추가ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.지도ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.열기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.저장ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.새지도ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.TileopenFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.TilesaveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.tileSplitContainer = new System.Windows.Forms.SplitContainer();
            this.tilePanel = new System.Windows.Forms.Panel();
            this.tilePictureBox = new System.Windows.Forms.PictureBox();
            this.tileListBox = new System.Windows.Forms.ListBox();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.MapPannel = new System.Windows.Forms.Panel();
            this.MenuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tileSplitContainer)).BeginInit();
            this.tileSplitContainer.Panel1.SuspendLayout();
            this.tileSplitContainer.Panel2.SuspendLayout();
            this.tileSplitContainer.SuspendLayout();
            this.tilePanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tilePictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // MenuStrip
            // 
            this.MenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.파일ToolStripMenuItem,
            this.지도ToolStripMenuItem});
            this.MenuStrip.Location = new System.Drawing.Point(0, 0);
            this.MenuStrip.Name = "MenuStrip";
            this.MenuStrip.Size = new System.Drawing.Size(1260, 24);
            this.MenuStrip.TabIndex = 0;
            this.MenuStrip.Text = "menuStrip1";
            // 
            // 파일ToolStripMenuItem
            // 
            this.파일ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.타일열기ToolStripMenuItem,
            this.타일목록저장ToolStripMenuItem,
            this.타일추가ToolStripMenuItem});
            this.파일ToolStripMenuItem.Name = "파일ToolStripMenuItem";
            this.파일ToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.파일ToolStripMenuItem.Text = "타일";
            // 
            // 타일열기ToolStripMenuItem
            // 
            this.타일열기ToolStripMenuItem.Name = "타일열기ToolStripMenuItem";
            this.타일열기ToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.타일열기ToolStripMenuItem.Text = "타일목록 열기";
            this.타일열기ToolStripMenuItem.Click += new System.EventHandler(this.타일열기ToolStripMenuItem_Click);
            // 
            // 타일목록저장ToolStripMenuItem
            // 
            this.타일목록저장ToolStripMenuItem.Name = "타일목록저장ToolStripMenuItem";
            this.타일목록저장ToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.타일목록저장ToolStripMenuItem.Text = "타일목록 저장";
            this.타일목록저장ToolStripMenuItem.Click += new System.EventHandler(this.타일목록저장ToolStripMenuItem_Click);
            // 
            // 타일추가ToolStripMenuItem
            // 
            this.타일추가ToolStripMenuItem.Name = "타일추가ToolStripMenuItem";
            this.타일추가ToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.타일추가ToolStripMenuItem.Text = "타일추가";
            this.타일추가ToolStripMenuItem.Click += new System.EventHandler(this.타일추가ToolStripMenuItem_Click);
            // 
            // 지도ToolStripMenuItem
            // 
            this.지도ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.열기ToolStripMenuItem,
            this.저장ToolStripMenuItem,
            this.새지도ToolStripMenuItem});
            this.지도ToolStripMenuItem.Name = "지도ToolStripMenuItem";
            this.지도ToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.지도ToolStripMenuItem.Text = "지도";
            // 
            // 열기ToolStripMenuItem
            // 
            this.열기ToolStripMenuItem.Name = "열기ToolStripMenuItem";
            this.열기ToolStripMenuItem.Size = new System.Drawing.Size(114, 22);
            this.열기ToolStripMenuItem.Text = "열기";
            // 
            // 저장ToolStripMenuItem
            // 
            this.저장ToolStripMenuItem.Name = "저장ToolStripMenuItem";
            this.저장ToolStripMenuItem.Size = new System.Drawing.Size(114, 22);
            this.저장ToolStripMenuItem.Text = "저장";
            // 
            // 새지도ToolStripMenuItem
            // 
            this.새지도ToolStripMenuItem.Name = "새지도ToolStripMenuItem";
            this.새지도ToolStripMenuItem.Size = new System.Drawing.Size(114, 22);
            this.새지도ToolStripMenuItem.Text = "새 지도";
            this.새지도ToolStripMenuItem.Click += new System.EventHandler(this.새지도ToolStripMenuItem_Click);
            // 
            // TileopenFileDialog
            // 
            this.TileopenFileDialog.FileName = "openFileDialog1";
            this.TileopenFileDialog.FileOk += new System.ComponentModel.CancelEventHandler(this.TileopenFileDialog_FileOk);
            // 
            // tileSplitContainer
            // 
            this.tileSplitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tileSplitContainer.Location = new System.Drawing.Point(0, 24);
            this.tileSplitContainer.Name = "tileSplitContainer";
            // 
            // tileSplitContainer.Panel1
            // 
            this.tileSplitContainer.Panel1.Controls.Add(this.tilePanel);
            this.tileSplitContainer.Panel1.Controls.Add(this.tileListBox);
            // 
            // tileSplitContainer.Panel2
            // 
            this.tileSplitContainer.Panel2.AutoScroll = true;
            this.tileSplitContainer.Panel2.Controls.Add(this.splitContainer1);
            this.tileSplitContainer.Size = new System.Drawing.Size(1260, 619);
            this.tileSplitContainer.SplitterDistance = 298;
            this.tileSplitContainer.TabIndex = 1;
            this.tileSplitContainer.SplitterMoved += new System.Windows.Forms.SplitterEventHandler(this.tileSplitContainer_SplitterMoved);
            this.tileSplitContainer.Resize += new System.EventHandler(this.tileSplitContainer_Resize);
            // 
            // tilePanel
            // 
            this.tilePanel.AutoScroll = true;
            this.tilePanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.tilePanel.Controls.Add(this.tilePictureBox);
            this.tilePanel.Location = new System.Drawing.Point(3, 137);
            this.tilePanel.Name = "tilePanel";
            this.tilePanel.Size = new System.Drawing.Size(292, 479);
            this.tilePanel.TabIndex = 0;
            // 
            // tilePictureBox
            // 
            this.tilePictureBox.InitialImage = ((System.Drawing.Image)(resources.GetObject("tilePictureBox.InitialImage")));
            this.tilePictureBox.Location = new System.Drawing.Point(-3, 0);
            this.tilePictureBox.Name = "tilePictureBox";
            this.tilePictureBox.Size = new System.Drawing.Size(252, 435);
            this.tilePictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.tilePictureBox.TabIndex = 0;
            this.tilePictureBox.TabStop = false;
            this.tilePictureBox.Paint += new System.Windows.Forms.PaintEventHandler(this.tilePictureBox_Paint);
            this.tilePictureBox.MouseClick += new System.Windows.Forms.MouseEventHandler(this.tilePictureBox_MouseClick);
            this.tilePictureBox.MouseDown += new System.Windows.Forms.MouseEventHandler(this.tilePictureBox_MouseDown);
            this.tilePictureBox.MouseMove += new System.Windows.Forms.MouseEventHandler(this.tilePictureBox_MouseMove);
            this.tilePictureBox.MouseUp += new System.Windows.Forms.MouseEventHandler(this.tilePictureBox_MouseUp);
            // 
            // tileListBox
            // 
            this.tileListBox.FormattingEnabled = true;
            this.tileListBox.HorizontalScrollbar = true;
            this.tileListBox.ItemHeight = 12;
            this.tileListBox.Location = new System.Drawing.Point(3, 0);
            this.tileListBox.Name = "tileListBox";
            this.tileListBox.ScrollAlwaysVisible = true;
            this.tileListBox.Size = new System.Drawing.Size(292, 136);
            this.tileListBox.TabIndex = 1;
            this.tileListBox.SelectedIndexChanged += new System.EventHandler(this.tileListBox_SelectedIndexChanged);
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.MapPannel);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Font = new System.Drawing.Font("굴림", 8F);
            this.splitContainer1.Size = new System.Drawing.Size(958, 619);
            this.splitContainer1.SplitterDistance = 698;
            this.splitContainer1.TabIndex = 0;
            // 
            // MapPannel
            // 
            this.MapPannel.Location = new System.Drawing.Point(3, 3);
            this.MapPannel.Name = "MapPannel";
            this.MapPannel.Size = new System.Drawing.Size(692, 613);
            this.MapPannel.TabIndex = 0;
            // 
            // MapTileEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(1260, 643);
            this.Controls.Add(this.tileSplitContainer);
            this.Controls.Add(this.MenuStrip);
            this.MainMenuStrip = this.MenuStrip;
            this.Name = "MapTileEditor";
            this.Text = "MapTileEditor";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MapTileEditor_FormClosing);

            this.MenuStrip.ResumeLayout(false);
            this.MenuStrip.PerformLayout();
            this.tileSplitContainer.Panel1.ResumeLayout(false);
            this.tileSplitContainer.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.tileSplitContainer)).EndInit();
            this.tileSplitContainer.ResumeLayout(false);
            this.tilePanel.ResumeLayout(false);
            this.tilePanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tilePictureBox)).EndInit();
            this.splitContainer1.Panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
      
        private System.Windows.Forms.MenuStrip MenuStrip;
        private System.Windows.Forms.ToolStripMenuItem 파일ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 타일열기ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 타일목록저장ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 지도ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 열기ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 저장ToolStripMenuItem;
        private System.Windows.Forms.OpenFileDialog TileopenFileDialog;
        private System.Windows.Forms.SaveFileDialog TilesaveFileDialog;
        private System.Windows.Forms.SplitContainer tileSplitContainer;
        private System.Windows.Forms.ToolStripMenuItem 타일추가ToolStripMenuItem;
        private System.Windows.Forms.ListBox tileListBox;
        private System.Windows.Forms.Panel tilePanel;
        private System.Windows.Forms.PictureBox tilePictureBox;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.ToolStripMenuItem 새지도ToolStripMenuItem;
        private System.Windows.Forms.Panel MapPannel;
    }
}