﻿namespace AssetManager
{
	partial class Manager
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Manager));
			this.ButtonPack = new System.Windows.Forms.Button();
			this.treeViewAssets = new System.Windows.Forms.TreeView();
			this.labelWorkspace = new System.Windows.Forms.Label();
			this.labelMetadata = new System.Windows.Forms.Label();
			this.buttonWorkspaceOpen = new System.Windows.Forms.Button();
			this.buttonAssetOpen = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.Output = new System.Windows.Forms.RichTextBox();
			this.ButtonSettings = new System.Windows.Forms.Button();
			this.ButtonUpdate = new System.Windows.Forms.Button();
			this.panel1 = new System.Windows.Forms.Panel();
			this.SuspendLayout();
			// 
			// ButtonPack
			// 
			this.ButtonPack.Location = new System.Drawing.Point(808, 13);
			this.ButtonPack.Name = "ButtonPack";
			this.ButtonPack.Size = new System.Drawing.Size(111, 24);
			this.ButtonPack.TabIndex = 1;
			this.ButtonPack.Text = "Pack";
			this.ButtonPack.UseVisualStyleBackColor = true;
			this.ButtonPack.Click += new System.EventHandler(this.ButtonPack_Click);
			// 
			// treeViewAssets
			// 
			this.treeViewAssets.BackColor = System.Drawing.SystemColors.Window;
			this.treeViewAssets.Location = new System.Drawing.Point(14, 39);
			this.treeViewAssets.Margin = new System.Windows.Forms.Padding(5, 3, 5, 3);
			this.treeViewAssets.Name = "treeViewAssets";
			this.treeViewAssets.Size = new System.Drawing.Size(237, 589);
			this.treeViewAssets.TabIndex = 7;
			// 
			// labelWorkspace
			// 
			this.labelWorkspace.AutoSize = true;
			this.labelWorkspace.Location = new System.Drawing.Point(11, 21);
			this.labelWorkspace.Name = "labelWorkspace";
			this.labelWorkspace.Size = new System.Drawing.Size(65, 15);
			this.labelWorkspace.TabIndex = 12;
			this.labelWorkspace.Text = "Workspace";
			// 
			// labelMetadata
			// 
			this.labelMetadata.AutoSize = true;
			this.labelMetadata.Location = new System.Drawing.Point(256, 21);
			this.labelMetadata.Name = "labelMetadata";
			this.labelMetadata.Size = new System.Drawing.Size(57, 15);
			this.labelMetadata.TabIndex = 13;
			this.labelMetadata.Text = "Metadata";
			// 
			// buttonWorkspaceOpen
			// 
			this.buttonWorkspaceOpen.Location = new System.Drawing.Point(140, 13);
			this.buttonWorkspaceOpen.Name = "buttonWorkspaceOpen";
			this.buttonWorkspaceOpen.Size = new System.Drawing.Size(111, 24);
			this.buttonWorkspaceOpen.TabIndex = 14;
			this.buttonWorkspaceOpen.Text = "Explore";
			this.buttonWorkspaceOpen.UseVisualStyleBackColor = true;
			this.buttonWorkspaceOpen.Click += new System.EventHandler(this.buttonWorkspaceOpen_Click);
			// 
			// buttonAssetOpen
			// 
			this.buttonAssetOpen.Enabled = false;
			this.buttonAssetOpen.Location = new System.Drawing.Point(363, 13);
			this.buttonAssetOpen.Name = "buttonAssetOpen";
			this.buttonAssetOpen.Size = new System.Drawing.Size(111, 24);
			this.buttonAssetOpen.TabIndex = 15;
			this.buttonAssetOpen.Text = "Reset";
			this.buttonAssetOpen.UseVisualStyleBackColor = true;
			this.buttonAssetOpen.Click += new System.EventHandler(this.buttonAssetOpen_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.Location = new System.Drawing.Point(482, 21);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(45, 15);
			this.label1.TabIndex = 16;
			this.label1.Text = "Output";
			// 
			// Output
			// 
			this.Output.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(48)))), ((int)(((byte)(48)))), ((int)(((byte)(48)))));
			this.Output.BorderStyle = System.Windows.Forms.BorderStyle.None;
			this.Output.Font = new System.Drawing.Font("Consolas", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.Output.ForeColor = System.Drawing.Color.LightGray;
			this.Output.Location = new System.Drawing.Point(485, 39);
			this.Output.Margin = new System.Windows.Forms.Padding(5, 3, 5, 3);
			this.Output.Name = "Output";
			this.Output.ReadOnly = true;
			this.Output.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.Vertical;
			this.Output.Size = new System.Drawing.Size(435, 589);
			this.Output.TabIndex = 19;
			this.Output.Text = "";
			// 
			// ButtonSettings
			// 
			this.ButtonSettings.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("ButtonSettings.BackgroundImage")));
			this.ButtonSettings.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
			this.ButtonSettings.Location = new System.Drawing.Point(110, 13);
			this.ButtonSettings.Name = "ButtonSettings";
			this.ButtonSettings.Size = new System.Drawing.Size(24, 24);
			this.ButtonSettings.TabIndex = 23;
			this.ButtonSettings.UseVisualStyleBackColor = true;
			this.ButtonSettings.Click += new System.EventHandler(this.buttonSettings_Click);
			// 
			// ButtonUpdate
			// 
			this.ButtonUpdate.Location = new System.Drawing.Point(691, 13);
			this.ButtonUpdate.Name = "ButtonUpdate";
			this.ButtonUpdate.Size = new System.Drawing.Size(111, 24);
			this.ButtonUpdate.TabIndex = 24;
			this.ButtonUpdate.Text = "Update";
			this.ButtonUpdate.UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this.panel1.Location = new System.Drawing.Point(259, 39);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(218, 588);
			this.panel1.TabIndex = 25;
			// 
			// Manager
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(934, 641);
			this.Controls.Add(this.treeViewAssets);
			this.Controls.Add(this.panel1);
			this.Controls.Add(this.ButtonUpdate);
			this.Controls.Add(this.ButtonSettings);
			this.Controls.Add(this.Output);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.ButtonPack);
			this.Controls.Add(this.buttonAssetOpen);
			this.Controls.Add(this.buttonWorkspaceOpen);
			this.Controls.Add(this.labelMetadata);
			this.Controls.Add(this.labelWorkspace);
			this.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.MaximizeBox = false;
			this.Name = "Manager";
			this.Text = "Jewel3D - Asset Manager";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion
		private System.Windows.Forms.Button ButtonPack;
		private System.Windows.Forms.TreeView treeViewAssets;
		private System.Windows.Forms.Label labelWorkspace;
		private System.Windows.Forms.Label labelMetadata;
		private System.Windows.Forms.Button buttonWorkspaceOpen;
		private System.Windows.Forms.Button buttonAssetOpen;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.RichTextBox Output;
		private System.Windows.Forms.Button ButtonSettings;
		private System.Windows.Forms.Button ButtonUpdate;
        private System.Windows.Forms.Panel panel1;
    }
}

