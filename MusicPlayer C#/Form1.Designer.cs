namespace BetterMusicPlayer
{
    partial class Form1
    {

        private System.ComponentModel.IContainer components = null;


        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code


        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            btn_previous = new Button();
            btn_next = new Button();
            btn_play = new Button();
            btn_pause = new Button();
            btn_open = new Button();
            p_bar = new ProgressBar();
            track_list = new ListBox();
            pic_art = new PictureBox();
            player = new AxWMPLib.AxWindowsMediaPlayer();
            track_volume = new TrackBar();
            label1 = new Label();
            lbl_volume = new Label();
            lbl_track_start = new Label();
            lbl_track_end = new Label();
            panel1 = new Panel();
            timer1 = new System.Windows.Forms.Timer(components);
            ((System.ComponentModel.ISupportInitialize)pic_art).BeginInit();
            ((System.ComponentModel.ISupportInitialize)player).BeginInit();
            ((System.ComponentModel.ISupportInitialize)track_volume).BeginInit();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // btn_previous
            // 
            btn_previous.BackColor = Color.Black;
            btn_previous.FlatStyle = FlatStyle.Flat;
            btn_previous.ForeColor = Color.FromArgb(255, 128, 0);
            btn_previous.Location = new Point(125, 539);
            btn_previous.Name = "btn_previous";
            btn_previous.Size = new Size(118, 39);
            btn_previous.TabIndex = 0;
            btn_previous.Text = "Previous";
            btn_previous.UseVisualStyleBackColor = false;
            btn_previous.Click += btn_previous_Click;
            btn_previous.MouseEnter += btn_previous_MouseEnter;
            // 
            // btn_next
            // 
            btn_next.BackColor = Color.Black;
            btn_next.FlatStyle = FlatStyle.Flat;
            btn_next.ForeColor = Color.FromArgb(255, 128, 0);
            btn_next.Location = new Point(249, 539);
            btn_next.Name = "btn_next";
            btn_next.Size = new Size(118, 39);
            btn_next.TabIndex = 1;
            btn_next.Text = "Next";
            btn_next.UseVisualStyleBackColor = false;
            btn_next.Click += btn_next_Click;
            btn_next.MouseEnter += btn_next_MouseEnter;
            // 
            // btn_play
            // 
            btn_play.BackColor = Color.Black;
            btn_play.FlatStyle = FlatStyle.Flat;
            btn_play.ForeColor = Color.FromArgb(255, 128, 0);
            btn_play.Location = new Point(373, 539);
            btn_play.Name = "btn_play";
            btn_play.Size = new Size(118, 39);
            btn_play.TabIndex = 2;
            btn_play.Text = "Play";
            btn_play.UseVisualStyleBackColor = false;
            btn_play.Click += btn_play_Click;
            btn_play.MouseEnter += btn_play_MouseEnter;
            // 
            // btn_pause
            // 
            btn_pause.BackColor = Color.Black;
            btn_pause.FlatStyle = FlatStyle.Flat;
            btn_pause.ForeColor = Color.FromArgb(255, 128, 0);
            btn_pause.Location = new Point(497, 539);
            btn_pause.Name = "btn_pause";
            btn_pause.Size = new Size(118, 39);
            btn_pause.TabIndex = 3;
            btn_pause.Text = "Pause";
            btn_pause.UseVisualStyleBackColor = false;
            btn_pause.Click += btn_pause_Click;
            btn_pause.MouseEnter += btn_pause_MouseEnter;
            // 
            // btn_open
            // 
            btn_open.BackColor = Color.Black;
            btn_open.FlatStyle = FlatStyle.Flat;
            btn_open.ForeColor = Color.FromArgb(255, 128, 0);
            btn_open.Location = new Point(621, 539);
            btn_open.Name = "btn_open";
            btn_open.Size = new Size(247, 39);
            btn_open.TabIndex = 4;
            btn_open.Text = "Open";
            btn_open.UseVisualStyleBackColor = false;
            btn_open.Click += btn_open_Click;
            btn_open.MouseEnter += btn_open_MouseEnter;
            // 
            // p_bar
            // 
            p_bar.Location = new Point(125, 496);
            p_bar.Name = "p_bar";
            p_bar.Size = new Size(743, 28);
            p_bar.TabIndex = 5;
            p_bar.MouseDown += p_bar_MouseDown;
            // 
            // track_list
            // 
            track_list.BackColor = Color.Black;
            track_list.BorderStyle = BorderStyle.None;
            track_list.ForeColor = Color.FromArgb(255, 128, 0);
            track_list.FormattingEnabled = true;
            track_list.ItemHeight = 25;
            track_list.Location = new Point(294, 174);
            track_list.Name = "track_list";
            track_list.Size = new Size(574, 250);
            track_list.TabIndex = 6;
            track_list.SelectedIndexChanged += track_list_SelectedIndexChanged;
            // 
            // pic_art
            // 
            pic_art.BackColor = Color.FromArgb(0, 192, 192);
            pic_art.Image = (Image)resources.GetObject("pic_art.Image");
            pic_art.Location = new Point(22, 13);
            pic_art.Name = "pic_art";
            pic_art.Size = new Size(270, 250);
            pic_art.SizeMode = PictureBoxSizeMode.StretchImage;
            pic_art.TabIndex = 7;
            pic_art.TabStop = false;
            // 
            // player
            // 
            player.Dock = DockStyle.Top;
            player.Enabled = true;
            player.Location = new Point(0, 0);
            player.Name = "player";
            player.OcxState = (AxHost.State)resources.GetObject("player.OcxState");
            player.Size = new Size(1074, 70);
            player.TabIndex = 8;
            // 
            // track_volume
            // 
            track_volume.BackColor = Color.FromArgb(255, 128, 0);
            track_volume.Location = new Point(896, 195);
            track_volume.Maximum = 100;
            track_volume.Name = "track_volume";
            track_volume.Orientation = Orientation.Vertical;
            track_volume.Size = new Size(69, 204);
            track_volume.TabIndex = 9;
            track_volume.TickStyle = TickStyle.TopLeft;
            track_volume.Scroll += track_volume_Scroll;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.FromArgb(255, 128, 0);
            label1.Font = new Font("High Tower Text", 12F, FontStyle.Italic, GraphicsUnit.Point);
            label1.ForeColor = Color.Black;
            label1.Location = new Point(893, 241);
            label1.Name = "label1";
            label1.Size = new Size(83, 28);
            label1.TabIndex = 10;
            label1.Text = "Volume";
            label1.Click += label1_Click;
            // 
            // lbl_volume
            // 
            lbl_volume.AutoSize = true;
            lbl_volume.BackColor = Color.FromArgb(255, 128, 0);
            lbl_volume.Font = new Font("High Tower Text", 14F, FontStyle.Italic, GraphicsUnit.Point);
            lbl_volume.ForeColor = Color.Black;
            lbl_volume.Location = new Point(893, 0);
            lbl_volume.Name = "lbl_volume";
            lbl_volume.Size = new Size(76, 31);
            lbl_volume.TabIndex = 11;
            lbl_volume.Text = "100 %";
            // 
            // lbl_track_start
            // 
            lbl_track_start.AutoSize = true;
            lbl_track_start.Font = new Font("Dungeon", 24F, FontStyle.Bold, GraphicsUnit.Point);
            lbl_track_start.ForeColor = Color.FromArgb(128, 255, 128);
            lbl_track_start.Location = new Point(18, 93);
            lbl_track_start.Name = "lbl_track_start";
            lbl_track_start.Size = new Size(184, 55);
            lbl_track_start.TabIndex = 12;
            lbl_track_start.Text = "00:00";
            // 
            // lbl_track_end
            // 
            lbl_track_end.AutoSize = true;
            lbl_track_end.Font = new Font("Dungeon", 24F, FontStyle.Bold, GraphicsUnit.Point);
            lbl_track_end.ForeColor = Color.FromArgb(128, 255, 128);
            lbl_track_end.Location = new Point(813, 93);
            lbl_track_end.Name = "lbl_track_end";
            lbl_track_end.Size = new Size(184, 55);
            lbl_track_end.TabIndex = 13;
            lbl_track_end.Text = "00:00";
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(255, 128, 0);
            panel1.Controls.Add(label1);
            panel1.Controls.Add(pic_art);
            panel1.Controls.Add(lbl_volume);
            panel1.Location = new Point(-4, 161);
            panel1.Name = "panel1";
            panel1.Size = new Size(1021, 289);
            panel1.TabIndex = 14;
            // 
            // timer1
            // 
            timer1.Enabled = true;
            timer1.Tick += timer1_Tick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.Black;
            ClientSize = new Size(1074, 610);
            Controls.Add(lbl_track_end);
            Controls.Add(lbl_track_start);
            Controls.Add(track_volume);
            Controls.Add(player);
            Controls.Add(track_list);
            Controls.Add(p_bar);
            Controls.Add(btn_open);
            Controls.Add(btn_pause);
            Controls.Add(btn_play);
            Controls.Add(btn_next);
            Controls.Add(btn_previous);
            Controls.Add(panel1);
            Name = "Form1";
            Text = "MusicPlayer";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)pic_art).EndInit();
            ((System.ComponentModel.ISupportInitialize)player).EndInit();
            ((System.ComponentModel.ISupportInitialize)track_volume).EndInit();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button btn_previous;
        private Button btn_next;
        private Button btn_play;
        private Button btn_pause;
        private Button btn_open;
        private ProgressBar p_bar;
        private ListBox track_list;
        private PictureBox pic_art;
        private AxWMPLib.AxWindowsMediaPlayer player;
        private TrackBar track_volume;
        private Label label1;
        private Label lbl_volume;
        private Label lbl_track_start;
        private Label lbl_track_end;
        private Panel panel1;
        private System.Windows.Forms.Timer timer1;
    }
}
