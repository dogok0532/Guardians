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
            // 
            // FrameBar
            // 
            this.FrameBar.AutoSize = false;
            this.FrameBar.Location = new System.Drawing.Point(339, 12);
            this.FrameBar.Name = "FrameBar";
            this.FrameBar.Size = new System.Drawing.Size(296, 40);
            this.FrameBar.TabIndex = 9;
            this.FrameBar.Value = 2;
            this.FrameBar.Scroll += new System.EventHandler(this.FrameBar_Scroll);
            // 
            // ImageEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
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

        }

        #endregion
        private System.Windows.Forms.ComboBox TextureName;
        private System.Windows.Forms.ComboBox SpriteName;
        private System.Windows.Forms.Button ResetButton;
        private System.Windows.Forms.PictureBox ImageBox;
        private System.Windows.Forms.TrackBar FrameBar;
    }
}

