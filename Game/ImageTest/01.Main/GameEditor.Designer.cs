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
            this.StageDesignerButton = new System.Windows.Forms.Button();
            this.ImageEditorButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // StageDesignerButton
            // 
            this.StageDesignerButton.Location = new System.Drawing.Point(194, 213);
            this.StageDesignerButton.Name = "StageDesignerButton";
            this.StageDesignerButton.Size = new System.Drawing.Size(130, 63);
            this.StageDesignerButton.TabIndex = 0;
            this.StageDesignerButton.Text = "StageDesigner";
            this.StageDesignerButton.UseVisualStyleBackColor = true;
            this.StageDesignerButton.Click += new System.EventHandler(this.StageDesigner_Click);
            // 
            // ImageEditorButton
            // 
            this.ImageEditorButton.Location = new System.Drawing.Point(409, 213);
            this.ImageEditorButton.Name = "ImageEditorButton";
            this.ImageEditorButton.Size = new System.Drawing.Size(133, 63);
            this.ImageEditorButton.TabIndex = 1;
            this.ImageEditorButton.Text = "ImageEditor";
            this.ImageEditorButton.UseVisualStyleBackColor = true;
            this.ImageEditorButton.Click += new System.EventHandler(this.ImageEditor_Click);
            // 
            // GameEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(794, 470);
            this.Controls.Add(this.ImageEditorButton);
            this.Controls.Add(this.StageDesignerButton);
            this.Name = "GameEditor";
            this.Text = "GameEditor";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button StageDesignerButton;
        private System.Windows.Forms.Button ImageEditorButton;
    }
}