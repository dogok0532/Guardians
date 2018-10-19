using ImageEditor._02.Parser;


namespace ImageEditor
{
    partial class ImageEditor
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

       
        

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.TextureName = new System.Windows.Forms.ComboBox();
            this.SpriteName = new System.Windows.Forms.ComboBox();
            this.ResetButton = new System.Windows.Forms.Button();
            this.ImageBox = new System.Windows.Forms.PictureBox();
            this.FrameBar = new System.Windows.Forms.TrackBar();
            this.radButtonSpriteView = new System.Windows.Forms.RadioButton();
            this.radButtonFrameView = new System.Windows.Forms.RadioButton();
            this.PlayButton = new System.Windows.Forms.Button();
            this.backFrameCounter = new System.ComponentModel.BackgroundWorker();
            ((System.ComponentModel.ISupportInitialize)(this.ImageBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.FrameBar)).BeginInit();
            this.SuspendLayout();
            // 
            // TextureName
            // 
            this.TextureName.FormattingEnabled = true;
            this.TextureName.Location = new System.Drawing.Point(12, 12);
            this.TextureName.Name = "TextureName";
            this.TextureName.Size = new System.Drawing.Size(115, 20);
            this.TextureName.TabIndex = 1;
            this.TextureName.SelectedIndexChanged += new System.EventHandler(this.TextureName_SelectedIndexChanged);
            // 
            // SpriteName
            // 
            this.SpriteName.FormattingEnabled = true;
            this.SpriteName.Location = new System.Drawing.Point(133, 12);
            this.SpriteName.Name = "SpriteName";
            this.SpriteName.Size = new System.Drawing.Size(115, 20);
            this.SpriteName.TabIndex = 2;
            this.SpriteName.SelectedIndexChanged += new System.EventHandler(this.SpriteName_SelectedIndexChanged);
            // 
            // ResetButton
            // 
            this.ResetButton.Location = new System.Drawing.Point(554, 328);
            this.ResetButton.Name = "ResetButton";
            this.ResetButton.Size = new System.Drawing.Size(99, 51);
            this.ResetButton.TabIndex = 7;
            this.ResetButton.Text = "Reset";
            this.ResetButton.UseVisualStyleBackColor = true;
            this.ResetButton.Click += new System.EventHandler(this.ResetButton_Click);
            // 
            // ImageBox
            // 
            this.ImageBox.Location = new System.Drawing.Point(88, 89);
            this.ImageBox.Name = "ImageBox";
            this.ImageBox.Size = new System.Drawing.Size(317, 290);
            this.ImageBox.TabIndex = 5;
            this.ImageBox.TabStop = false;
            this.ImageBox.Paint += new System.Windows.Forms.PaintEventHandler(this.ImageBox_Paint);
            // 
            // FrameBar
            // 
            this.FrameBar.AutoSize = false;
            this.FrameBar.Location = new System.Drawing.Point(339, 12);
            this.FrameBar.Name = "FrameBar";
            this.FrameBar.Size = new System.Drawing.Size(296, 40);
            this.FrameBar.TabIndex = 9;
            this.FrameBar.Value = 2;
            this.FrameBar.ValueChanged += new System.EventHandler(this.FrameBar_Changed);
            // 
            // radButtonSpriteView
            // 
            this.radButtonSpriteView.AutoSize = true;
            this.radButtonSpriteView.Location = new System.Drawing.Point(377, 58);
            this.radButtonSpriteView.Name = "radButtonSpriteView";
            this.radButtonSpriteView.Size = new System.Drawing.Size(83, 16);
            this.radButtonSpriteView.TabIndex = 10;
            this.radButtonSpriteView.Text = "SpriteView";
            this.radButtonSpriteView.UseVisualStyleBackColor = true;
            this.radButtonSpriteView.CheckedChanged += new System.EventHandler(this.radButtonSpriteView_CheckedChanged);
            // 
            // radButtonFrameView
            // 
            this.radButtonFrameView.AutoSize = true;
            this.radButtonFrameView.Checked = true;
            this.radButtonFrameView.Location = new System.Drawing.Point(508, 58);
            this.radButtonFrameView.Name = "radButtonFrameView";
            this.radButtonFrameView.Size = new System.Drawing.Size(87, 16);
            this.radButtonFrameView.TabIndex = 11;
            this.radButtonFrameView.TabStop = true;
            this.radButtonFrameView.Text = "FrameView";
            this.radButtonFrameView.UseVisualStyleBackColor = true;
            this.radButtonFrameView.CheckedChanged += new System.EventHandler(this.radButtonFrameView_CheckedChanged);
            // 
            // PlayButton
            // 
            this.PlayButton.Location = new System.Drawing.Point(660, 12);
            this.PlayButton.Name = "PlayButton";
            this.PlayButton.Size = new System.Drawing.Size(99, 51);
            this.PlayButton.TabIndex = 12;
            this.PlayButton.Text = "Play";
            this.PlayButton.UseVisualStyleBackColor = true;
            this.PlayButton.Click += new System.EventHandler(this.PlayButton_Click);
            // 
            // backFrameCounter
            // 
            this.backFrameCounter.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backFrameCounter_DoWork);
            this.backFrameCounter.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.backFrameCounter_ProgressChanged);
            this.backFrameCounter.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.backFrameCounter_RunWorkerCompleted);
            // 
            // ImageEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.PlayButton);
            this.Controls.Add(this.radButtonFrameView);
            this.Controls.Add(this.radButtonSpriteView);
            this.Controls.Add(this.FrameBar);
            this.Controls.Add(this.ResetButton);
            this.Controls.Add(this.ImageBox);
            this.Controls.Add(this.SpriteName);
            this.Controls.Add(this.TextureName);
            this.Name = "ImageEditor";
            this.Text = "ImageEditor";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.ImageEditor_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.ImageBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.FrameBar)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ComboBox TextureName;
        private System.Windows.Forms.ComboBox SpriteName;
        private System.Windows.Forms.Button ResetButton;
        private System.Windows.Forms.PictureBox ImageBox;
        private System.Windows.Forms.TrackBar FrameBar;
        private System.Windows.Forms.RadioButton radButtonSpriteView;
        private System.Windows.Forms.RadioButton radButtonFrameView;
        private System.Windows.Forms.Button PlayButton;
        private System.ComponentModel.BackgroundWorker backFrameCounter;
    }
}

