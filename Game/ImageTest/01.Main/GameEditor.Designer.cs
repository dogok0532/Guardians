namespace ImageEditor._01.Main
{
    partial class GameEditor
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
            this.ImageEditorButton = new System.Windows.Forms.Button();
            this.MapTileEditor = new System.Windows.Forms.Button();
            this.SoundEditorButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ImageEditorButton
            // 
            this.ImageEditorButton.Location = new System.Drawing.Point(344, 211);
            this.ImageEditorButton.Name = "ImageEditorButton";
            this.ImageEditorButton.Size = new System.Drawing.Size(133, 63);
            this.ImageEditorButton.TabIndex = 1;
            this.ImageEditorButton.Text = "ImageEditor";
            this.ImageEditorButton.UseVisualStyleBackColor = true;
            this.ImageEditorButton.Click += new System.EventHandler(this.ImageEditor_Click);
            // 
            // MapTileEditor
            // 
            this.MapTileEditor.Location = new System.Drawing.Point(158, 211);
            this.MapTileEditor.Name = "MapTileEditor";
            this.MapTileEditor.Size = new System.Drawing.Size(133, 63);
            this.MapTileEditor.TabIndex = 2;
            this.MapTileEditor.Text = "MapTileEditor";
            this.MapTileEditor.UseVisualStyleBackColor = true;
            this.MapTileEditor.Click += new System.EventHandler(this.MapTileEditor_Click);
            // 
            // SoundEditorButton
            // 
            this.SoundEditorButton.Location = new System.Drawing.Point(531, 211);
            this.SoundEditorButton.Name = "SoundEditorButton";
            this.SoundEditorButton.Size = new System.Drawing.Size(133, 63);
            this.SoundEditorButton.TabIndex = 3;
            this.SoundEditorButton.Text = "SoundEditor";
            this.SoundEditorButton.UseVisualStyleBackColor = true;
            // 
            // GameEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(794, 470);
            this.Controls.Add(this.SoundEditorButton);
            this.Controls.Add(this.MapTileEditor);
            this.Controls.Add(this.ImageEditorButton);
            this.Name = "GameEditor";
            this.Text = "GameEditor";
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button ImageEditorButton;
        private System.Windows.Forms.Button MapTileEditor;
        private System.Windows.Forms.Button SoundEditorButton;
    }
}