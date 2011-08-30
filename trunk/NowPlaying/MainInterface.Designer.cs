namespace JoelLow.NowPlaying
{
	partial class MainInterface
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

		#region Component Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify 
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.Panel = new System.Windows.Forms.Panel();
			this.txtUserInfo = new System.Windows.Forms.TextBox();
			this.BottomToolStripPanel = new System.Windows.Forms.ToolStripPanel();
			this.TopToolStripPanel = new System.Windows.Forms.ToolStripPanel();
			this.RightToolStripPanel = new System.Windows.Forms.ToolStripPanel();
			this.LeftToolStripPanel = new System.Windows.Forms.ToolStripPanel();
			this.ContentPanel = new System.Windows.Forms.ToolStripContentPanel();
			this.mainPanel = new System.Windows.Forms.Panel();
			this.RefreshTimer = new System.Windows.Forms.Timer(this.components);
			this.Panel.SuspendLayout();
			this.mainPanel.SuspendLayout();
			this.SuspendLayout();
			// 
			// Panel
			// 
			this.Panel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
						| System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.Panel.Controls.Add(this.txtUserInfo);
			this.Panel.Location = new System.Drawing.Point(3, 3);
			this.Panel.Name = "Panel";
			this.Panel.Size = new System.Drawing.Size(774, 364);
			this.Panel.TabIndex = 0;
			// 
			// txtUserInfo
			// 
			this.txtUserInfo.Dock = System.Windows.Forms.DockStyle.Bottom;
			this.txtUserInfo.Location = new System.Drawing.Point(0, 271);
			this.txtUserInfo.Multiline = true;
			this.txtUserInfo.Name = "txtUserInfo";
			this.txtUserInfo.Size = new System.Drawing.Size(774, 93);
			this.txtUserInfo.TabIndex = 0;
			// 
			// BottomToolStripPanel
			// 
			this.BottomToolStripPanel.Location = new System.Drawing.Point(0, 0);
			this.BottomToolStripPanel.Name = "BottomToolStripPanel";
			this.BottomToolStripPanel.Orientation = System.Windows.Forms.Orientation.Horizontal;
			this.BottomToolStripPanel.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
			this.BottomToolStripPanel.Size = new System.Drawing.Size(0, 0);
			// 
			// TopToolStripPanel
			// 
			this.TopToolStripPanel.Location = new System.Drawing.Point(0, 0);
			this.TopToolStripPanel.Name = "TopToolStripPanel";
			this.TopToolStripPanel.Orientation = System.Windows.Forms.Orientation.Horizontal;
			this.TopToolStripPanel.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
			this.TopToolStripPanel.Size = new System.Drawing.Size(0, 0);
			// 
			// RightToolStripPanel
			// 
			this.RightToolStripPanel.Location = new System.Drawing.Point(0, 0);
			this.RightToolStripPanel.Name = "RightToolStripPanel";
			this.RightToolStripPanel.Orientation = System.Windows.Forms.Orientation.Horizontal;
			this.RightToolStripPanel.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
			this.RightToolStripPanel.Size = new System.Drawing.Size(0, 0);
			// 
			// LeftToolStripPanel
			// 
			this.LeftToolStripPanel.Location = new System.Drawing.Point(0, 0);
			this.LeftToolStripPanel.Name = "LeftToolStripPanel";
			this.LeftToolStripPanel.Orientation = System.Windows.Forms.Orientation.Horizontal;
			this.LeftToolStripPanel.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
			this.LeftToolStripPanel.Size = new System.Drawing.Size(0, 0);
			// 
			// ContentPanel
			// 
			this.ContentPanel.AutoScroll = true;
			this.ContentPanel.Size = new System.Drawing.Size(640, 273);
			// 
			// mainPanel
			// 
			this.mainPanel.Controls.Add(this.Panel);
			this.mainPanel.Dock = System.Windows.Forms.DockStyle.Fill;
			this.mainPanel.Location = new System.Drawing.Point(0, 0);
			this.mainPanel.Name = "mainPanel";
			this.mainPanel.Size = new System.Drawing.Size(780, 370);
			this.mainPanel.TabIndex = 0;
			this.mainPanel.Paint += new System.Windows.Forms.PaintEventHandler(this.mainPanel_Paint);
			// 
			// RefreshTimer
			// 
			this.RefreshTimer.Enabled = true;
			this.RefreshTimer.Interval = 5000;
			this.RefreshTimer.Tick += new System.EventHandler(this.RefreshTimer_Tick);
			// 
			// MainInterface
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.Controls.Add(this.mainPanel);
			this.DoubleBuffered = true;
			this.Name = "MainInterface";
			this.Size = new System.Drawing.Size(780, 370);
			this.Panel.ResumeLayout(false);
			this.Panel.PerformLayout();
			this.mainPanel.ResumeLayout(false);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel Panel;
		private System.Windows.Forms.TextBox txtUserInfo;
		private System.Windows.Forms.ToolStripPanel BottomToolStripPanel;
		private System.Windows.Forms.ToolStripPanel TopToolStripPanel;
		private System.Windows.Forms.ToolStripPanel RightToolStripPanel;
		private System.Windows.Forms.ToolStripPanel LeftToolStripPanel;
		private System.Windows.Forms.ToolStripContentPanel ContentPanel;
		private System.Windows.Forms.Panel mainPanel;
		private System.Windows.Forms.Timer RefreshTimer;

	}
}
