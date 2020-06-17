namespace MathModeling
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea5 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend5 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series5 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title5 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.AnimationTimer = new System.Windows.Forms.Timer(this.components);
            this.Animation_pictureBox = new System.Windows.Forms.PictureBox();
            this.Time_Chart = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.CreatePoints_button = new System.Windows.Forms.Button();
            this.Algorithm_groupBox = new System.Windows.Forms.GroupBox();
            this.Trivial_radioButton = new System.Windows.Forms.RadioButton();
            this.dominance_radioButton = new System.Windows.Forms.RadioButton();
            this.kD_Tree_radioButton = new System.Windows.Forms.RadioButton();
            this.Pretreatment_button = new System.Windows.Forms.Button();
            this.CountingPoints_button = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.PretreatmentTime_label = new System.Windows.Forms.Label();
            this.PretreatmentTime_textBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.Animation_pictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Time_Chart)).BeginInit();
            this.Algorithm_groupBox.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Animation_pictureBox
            // 
            this.Animation_pictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.Animation_pictureBox.Location = new System.Drawing.Point(12, 142);
            this.Animation_pictureBox.Name = "Animation_pictureBox";
            this.Animation_pictureBox.Size = new System.Drawing.Size(553, 389);
            this.Animation_pictureBox.TabIndex = 1;
            this.Animation_pictureBox.TabStop = false;
            // 
            // Time_Chart
            // 
            this.Time_Chart.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.Time_Chart.BorderlineColor = System.Drawing.Color.Black;
            this.Time_Chart.BorderlineDashStyle = System.Windows.Forms.DataVisualization.Charting.ChartDashStyle.Solid;
            chartArea5.Name = "ChartArea1";
            this.Time_Chart.ChartAreas.Add(chartArea5);
            legend5.Name = "Legend1";
            this.Time_Chart.Legends.Add(legend5);
            this.Time_Chart.Location = new System.Drawing.Point(571, 171);
            this.Time_Chart.Name = "Time_Chart";
            series5.ChartArea = "ChartArea1";
            series5.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series5.Legend = "Legend1";
            series5.Name = "Время поиска";
            this.Time_Chart.Series.Add(series5);
            this.Time_Chart.Size = new System.Drawing.Size(402, 360);
            this.Time_Chart.TabIndex = 2;
            this.Time_Chart.Text = "Зависимость времени поиска от количества точек";
            title5.Name = "Title1";
            title5.Text = "Зависимость времени поиска от количества точек";
            this.Time_Chart.Titles.Add(title5);
            this.Time_Chart.Click += new System.EventHandler(this.TimeChart_Click);
            // 
            // CreatePoints_button
            // 
            this.CreatePoints_button.Location = new System.Drawing.Point(3, 3);
            this.CreatePoints_button.Name = "CreatePoints_button";
            this.CreatePoints_button.Size = new System.Drawing.Size(125, 23);
            this.CreatePoints_button.TabIndex = 0;
            this.CreatePoints_button.Text = "Создать точки";
            this.CreatePoints_button.UseVisualStyleBackColor = true;
            // 
            // Algorithm_groupBox
            // 
            this.Algorithm_groupBox.Controls.Add(this.kD_Tree_radioButton);
            this.Algorithm_groupBox.Controls.Add(this.dominance_radioButton);
            this.Algorithm_groupBox.Controls.Add(this.Trivial_radioButton);
            this.Algorithm_groupBox.Location = new System.Drawing.Point(3, 32);
            this.Algorithm_groupBox.Name = "Algorithm_groupBox";
            this.Algorithm_groupBox.Size = new System.Drawing.Size(125, 89);
            this.Algorithm_groupBox.TabIndex = 2;
            this.Algorithm_groupBox.TabStop = false;
            this.Algorithm_groupBox.Text = "Алгоритм поиска";
            // 
            // Trivial_radioButton
            // 
            this.Trivial_radioButton.AutoSize = true;
            this.Trivial_radioButton.Checked = true;
            this.Trivial_radioButton.Location = new System.Drawing.Point(6, 19);
            this.Trivial_radioButton.Name = "Trivial_radioButton";
            this.Trivial_radioButton.Size = new System.Drawing.Size(94, 17);
            this.Trivial_radioButton.TabIndex = 1;
            this.Trivial_radioButton.TabStop = true;
            this.Trivial_radioButton.Text = "Тривиальный";
            this.Trivial_radioButton.UseVisualStyleBackColor = true;
            // 
            // dominance_radioButton
            // 
            this.dominance_radioButton.AutoSize = true;
            this.dominance_radioButton.Location = new System.Drawing.Point(6, 42);
            this.dominance_radioButton.Name = "dominance_radioButton";
            this.dominance_radioButton.Size = new System.Drawing.Size(108, 17);
            this.dominance_radioButton.TabIndex = 3;
            this.dominance_radioButton.TabStop = true;
            this.dominance_radioButton.Text = "Доминирование";
            this.dominance_radioButton.UseVisualStyleBackColor = true;
            // 
            // kD_Tree_radioButton
            // 
            this.kD_Tree_radioButton.AutoSize = true;
            this.kD_Tree_radioButton.Location = new System.Drawing.Point(6, 66);
            this.kD_Tree_radioButton.Name = "kD_Tree_radioButton";
            this.kD_Tree_radioButton.Size = new System.Drawing.Size(84, 17);
            this.kD_Tree_radioButton.TabIndex = 4;
            this.kD_Tree_radioButton.TabStop = true;
            this.kD_Tree_radioButton.Text = "k-D Дерево";
            this.kD_Tree_radioButton.UseVisualStyleBackColor = true;
            // 
            // Pretreatment_button
            // 
            this.Pretreatment_button.Location = new System.Drawing.Point(134, 3);
            this.Pretreatment_button.Name = "Pretreatment_button";
            this.Pretreatment_button.Size = new System.Drawing.Size(126, 59);
            this.Pretreatment_button.TabIndex = 3;
            this.Pretreatment_button.Text = "Предобработка";
            this.Pretreatment_button.UseVisualStyleBackColor = true;
            this.Pretreatment_button.Click += new System.EventHandler(this.button2_Click);
            // 
            // CountingPoints_button
            // 
            this.CountingPoints_button.Location = new System.Drawing.Point(134, 62);
            this.CountingPoints_button.Name = "CountingPoints_button";
            this.CountingPoints_button.Size = new System.Drawing.Size(126, 59);
            this.CountingPoints_button.TabIndex = 4;
            this.CountingPoints_button.Text = "Подсчет количества точек";
            this.CountingPoints_button.UseVisualStyleBackColor = true;
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.CountingPoints_button);
            this.panel1.Controls.Add(this.Pretreatment_button);
            this.panel1.Controls.Add(this.Algorithm_groupBox);
            this.panel1.Controls.Add(this.CreatePoints_button);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(961, 124);
            this.panel1.TabIndex = 0;
            // 
            // PretreatmentTime_label
            // 
            this.PretreatmentTime_label.AutoSize = true;
            this.PretreatmentTime_label.Location = new System.Drawing.Point(572, 142);
            this.PretreatmentTime_label.Name = "PretreatmentTime_label";
            this.PretreatmentTime_label.Size = new System.Drawing.Size(198, 13);
            this.PretreatmentTime_label.TabIndex = 3;
            this.PretreatmentTime_label.Text = "Время затраченое на предобработку:";
            // 
            // PretreatmentTime_textBox
            // 
            this.PretreatmentTime_textBox.Location = new System.Drawing.Point(777, 142);
            this.PretreatmentTime_textBox.Name = "PretreatmentTime_textBox";
            this.PretreatmentTime_textBox.Size = new System.Drawing.Size(196, 20);
            this.PretreatmentTime_textBox.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.ClientSize = new System.Drawing.Size(985, 543);
            this.Controls.Add(this.PretreatmentTime_textBox);
            this.Controls.Add(this.PretreatmentTime_label);
            this.Controls.Add(this.Time_Chart);
            this.Controls.Add(this.Animation_pictureBox);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Математическое моделирование";
            ((System.ComponentModel.ISupportInitialize)(this.Animation_pictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Time_Chart)).EndInit();
            this.Algorithm_groupBox.ResumeLayout(false);
            this.Algorithm_groupBox.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer AnimationTimer;
        private System.Windows.Forms.PictureBox Animation_pictureBox;
        private System.Windows.Forms.DataVisualization.Charting.Chart Time_Chart;
        private System.Windows.Forms.Button CreatePoints_button;
        private System.Windows.Forms.GroupBox Algorithm_groupBox;
        private System.Windows.Forms.RadioButton kD_Tree_radioButton;
        private System.Windows.Forms.RadioButton dominance_radioButton;
        private System.Windows.Forms.RadioButton Trivial_radioButton;
        private System.Windows.Forms.Button Pretreatment_button;
        private System.Windows.Forms.Button CountingPoints_button;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label PretreatmentTime_label;
        private System.Windows.Forms.TextBox PretreatmentTime_textBox;
    }
}

