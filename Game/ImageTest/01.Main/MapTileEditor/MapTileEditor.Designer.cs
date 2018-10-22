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
            this.MenuStrip = new System.Windows.Forms.MenuStrip();
            this.파일ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.타일열기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.타일목록저장ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.타일추가ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.타일설정ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.지도ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.열기ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.저장ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.새지도ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.TileopenFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.TilesaveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.tileSplitContainer = new System.Windows.Forms.SplitContainer();
            this.tileListSplitContainer = new System.Windows.Forms.SplitContainer();
            this.tileListBox = new System.Windows.Forms.ListBox();
            this.optionSplitContainer = new System.Windows.Forms.SplitContainer();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown3 = new System.Windows.Forms.NumericUpDown();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.MenuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tileSplitContainer)).BeginInit();
            this.tileSplitContainer.Panel1.SuspendLayout();
            this.tileSplitContainer.Panel2.SuspendLayout();
            this.tileSplitContainer.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tileListSplitContainer)).BeginInit();
            this.tileListSplitContainer.Panel1.SuspendLayout();
            this.tileListSplitContainer.Panel2.SuspendLayout();
            this.tileListSplitContainer.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.optionSplitContainer)).BeginInit();
            this.optionSplitContainer.Panel1.SuspendLayout();
            this.optionSplitContainer.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.SuspendLayout();
            // 
            // MenuStrip
            // 
            this.MenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.파일ToolStripMenuItem,
            this.지도ToolStripMenuItem});
            this.MenuStrip.Location = new System.Drawing.Point(0, 0);
            this.MenuStrip.Name = "MenuStrip";
            this.MenuStrip.Size = new System.Drawing.Size(1308, 24);
            this.MenuStrip.TabIndex = 0;
            this.MenuStrip.Text = "menuStrip1";
            // 
            // 파일ToolStripMenuItem
            // 
            this.파일ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.타일열기ToolStripMenuItem,
            this.타일목록저장ToolStripMenuItem,
            this.타일추가ToolStripMenuItem,
            this.타일설정ToolStripMenuItem});
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
            // 타일설정ToolStripMenuItem
            // 
            this.타일설정ToolStripMenuItem.Name = "타일설정ToolStripMenuItem";
            this.타일설정ToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.타일설정ToolStripMenuItem.Text = "타일설정";
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
            this.tileSplitContainer.Panel1.Controls.Add(this.tileListSplitContainer);
            // 
            // tileSplitContainer.Panel2
            // 
            this.tileSplitContainer.Panel2.Controls.Add(this.optionSplitContainer);
            this.tileSplitContainer.Size = new System.Drawing.Size(1308, 569);
            this.tileSplitContainer.SplitterDistance = 214;
            this.tileSplitContainer.TabIndex = 1;
            // 
            // tileListSplitContainer
            // 
            this.tileListSplitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tileListSplitContainer.Location = new System.Drawing.Point(0, 0);
            this.tileListSplitContainer.Name = "tileListSplitContainer";
            this.tileListSplitContainer.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // tileListSplitContainer.Panel1
            // 
            this.tileListSplitContainer.Panel1.Controls.Add(this.tileListBox);
            // 
            // tileListSplitContainer.Panel2
            // 
            this.tileListSplitContainer.Panel2.Controls.Add(this.numericUpDown3);
            this.tileListSplitContainer.Panel2.Controls.Add(this.numericUpDown2);
            this.tileListSplitContainer.Panel2.Controls.Add(this.numericUpDown1);
            this.tileListSplitContainer.Panel2.Controls.Add(this.comboBox1);
            this.tileListSplitContainer.Panel2.Controls.Add(this.radioButton3);
            this.tileListSplitContainer.Panel2.Controls.Add(this.radioButton2);
            this.tileListSplitContainer.Panel2.Controls.Add(this.radioButton1);
            this.tileListSplitContainer.Panel2.Controls.Add(this.pictureBox1);
            this.tileListSplitContainer.Size = new System.Drawing.Size(214, 569);
            this.tileListSplitContainer.SplitterDistance = 163;
            this.tileListSplitContainer.TabIndex = 0;
            // 
            // tileListBox
            // 
            this.tileListBox.FormattingEnabled = true;
            this.tileListBox.ItemHeight = 12;
            this.tileListBox.Location = new System.Drawing.Point(0, 0);
            this.tileListBox.Name = "tileListBox";
            this.tileListBox.ScrollAlwaysVisible = true;
            this.tileListBox.Size = new System.Drawing.Size(214, 160);
            this.tileListBox.TabIndex = 0;
            // 
            // optionSplitContainer
            // 
            this.optionSplitContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.optionSplitContainer.Location = new System.Drawing.Point(0, 0);
            this.optionSplitContainer.Name = "optionSplitContainer";
            // 
            // optionSplitContainer.Panel1
            // 
            this.optionSplitContainer.Panel1.AutoScroll = true;
            this.optionSplitContainer.Panel1.Controls.Add(this.pictureBox2);
            this.optionSplitContainer.Size = new System.Drawing.Size(1090, 569);
            this.optionSplitContainer.SplitterDistance = 720;
            this.optionSplitContainer.TabIndex = 0;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 18);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(168, 92);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(19, 130);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(92, 16);
            this.radioButton1.TabIndex = 1;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "radioButton1";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(19, 152);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(92, 16);
            this.radioButton2.TabIndex = 2;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "radioButton2";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(19, 174);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(92, 16);
            this.radioButton3.TabIndex = 3;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "radioButton3";
            this.radioButton3.UseVisualStyleBackColor = true;
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(117, 170);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(52, 20);
            this.comboBox1.TabIndex = 4;
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(56, 228);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(75, 21);
            this.numericUpDown1.TabIndex = 5;
            // 
            // numericUpDown2
            // 
            this.numericUpDown2.Location = new System.Drawing.Point(56, 255);
            this.numericUpDown2.Name = "numericUpDown2";
            this.numericUpDown2.Size = new System.Drawing.Size(75, 21);
            this.numericUpDown2.TabIndex = 6;
            // 
            // numericUpDown3
            // 
            this.numericUpDown3.Location = new System.Drawing.Point(56, 282);
            this.numericUpDown3.Name = "numericUpDown3";
            this.numericUpDown3.Size = new System.Drawing.Size(75, 21);
            this.numericUpDown3.TabIndex = 7;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Location = new System.Drawing.Point(21, 22);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(661, 485);
            this.pictureBox2.TabIndex = 0;
            this.pictureBox2.TabStop = false;
            this.pictureBox2.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox2_Paint);
            // 
            // MapTileEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(1308, 593);
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
            this.tileListSplitContainer.Panel1.ResumeLayout(false);
            this.tileListSplitContainer.Panel2.ResumeLayout(false);
            this.tileListSplitContainer.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.tileListSplitContainer)).EndInit();
            this.tileListSplitContainer.ResumeLayout(false);
            this.optionSplitContainer.Panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.optionSplitContainer)).EndInit();
            this.optionSplitContainer.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
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
        private System.Windows.Forms.ToolStripMenuItem 타일추가ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 새지도ToolStripMenuItem;
        private System.Windows.Forms.SplitContainer tileSplitContainer;
        private System.Windows.Forms.SplitContainer tileListSplitContainer;
        private System.Windows.Forms.ListBox tileListBox;
        private System.Windows.Forms.SplitContainer optionSplitContainer;
        private System.Windows.Forms.ToolStripMenuItem 타일설정ToolStripMenuItem;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.NumericUpDown numericUpDown3;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.PictureBox pictureBox2;
    }
}