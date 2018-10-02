using ImageEditor._02.Parser;

namespace ImageEditor
{
    partial class ImageEditor
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        private CImageParser parser;
        

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
            this.DrawButton = new System.Windows.Forms.Button();
            this.ImageBox = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.ImageBox)).BeginInit();
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
            // DrawButton
            // 
            this.DrawButton.Location = new System.Drawing.Point(554, 328);
            this.DrawButton.Name = "DrawButton";
            this.DrawButton.Size = new System.Drawing.Size(99, 51);
            this.DrawButton.TabIndex = 7;
            this.DrawButton.Text = "Draw";
            this.DrawButton.UseVisualStyleBackColor = true;
            this.DrawButton.Click += new System.EventHandler(this.DrawButton_Click);
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
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(554, 244);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(99, 56);
            this.button1.TabIndex = 8;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Reset_Click);
            // 
            // ImageEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.DrawButton);
            this.Controls.Add(this.ImageBox);
            this.Controls.Add(this.SpriteName);
            this.Controls.Add(this.TextureName);
            this.Name = "ImageEditor";
            this.Text = "ImageEditor";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.ImageEditor_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.ImageBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.ComboBox TextureName;
        private System.Windows.Forms.ComboBox SpriteName;
        private System.Windows.Forms.Button DrawButton;
        private System.Windows.Forms.PictureBox ImageBox;
        private System.Windows.Forms.Button button1;
    }
}

