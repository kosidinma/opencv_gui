#pragma once

#include "opencv2/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/opencv.hpp"


namespace opencv_gui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	bool stop_record = false;


	/** Function Headers */
	int button_test(System::Windows::Forms::PictureBox^, System::Windows::Forms::Control^, System::Windows::Forms::TrackBar^, System::Windows::Forms::TrackBar^);
	bool face_det(void);
	void positive_prep(System::Windows::Forms::TextBox^ , System::Windows::Forms::TextBox^ , System::Windows::Forms::TextBox^ , System::Windows::Forms::TextBox^, System::Windows::Forms::Label^ );
	void negative_prep(System::Windows::Forms::TextBox^ , System::Windows::Forms::TextBox^ , System::Windows::Forms::TextBox^, System::Windows::Forms::Label^ );
	float millsecondsPerStep = 2000;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^  cvtest;
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  stop;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::PictureBox^  pictureBox2;
	public: System::Windows::Forms::TrackBar^  brightness;
	public:



	private: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::TrackBar^  contrast;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label12;

	public:

	private: System::ComponentModel::IContainer^  components;
	public:

	public:
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->cvtest = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->stop = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->brightness = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->contrast = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightness))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrast))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// cvtest
			// 
			this->cvtest->Location = System::Drawing::Point(26, 376);
			this->cvtest->Name = L"cvtest";
			this->cvtest->Size = System::Drawing::Size(104, 34);
			this->cvtest->TabIndex = 0;
			this->cvtest->Text = L"Start Detecting";
			this->cvtest->UseVisualStyleBackColor = true;
			this->cvtest->Click += gcnew System::EventHandler(this, &MyForm::cvtest_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(26, 26);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(190, 313);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// stop
			// 
			this->stop->Location = System::Drawing::Point(26, 501);
			this->stop->Name = L"stop";
			this->stop->Size = System::Drawing::Size(104, 34);
			this->stop->TabIndex = 2;
			this->stop->Text = L"Stop";
			this->stop->UseVisualStyleBackColor = true;
			this->stop->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(23, 423);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 15);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Face Detected\?";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Red;
			this->pictureBox2->Location = System::Drawing::Point(26, 441);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(104, 43);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// brightness
			// 
			this->brightness->Location = System::Drawing::Point(42, 140);
			this->brightness->Maximum = 100;
			this->brightness->Name = L"brightness";
			this->brightness->Size = System::Drawing::Size(104, 45);
			this->brightness->TabIndex = 6;
			this->brightness->Value = 50;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(53, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Brightness";
			// 
			// contrast
			// 
			this->contrast->LargeChange = 1;
			this->contrast->Location = System::Drawing::Point(44, 64);
			this->contrast->Maximum = 3;
			this->contrast->Minimum = 1;
			this->contrast->Name = L"contrast";
			this->contrast->Size = System::Drawing::Size(104, 45);
			this->contrast->TabIndex = 5;
			this->contrast->Value = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(65, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Contrast";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->contrast);
			this->panel1->Controls->Add(this->brightness);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(185, 376);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(198, 196);
			this->panel1->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(24, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 24);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Video Controls";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(575, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"+ve Training Data";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(238, 67);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(295, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Constraints [no of items  rectx1 y1 x2 y2 ) e.g. 1 11 5 650 400";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(759, 26);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"-ve Training Data";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(578, 59);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 13;
			this->textBox1->Text = L"1 2 2 199 199";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(238, 102);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(148, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Training Data Folder Directory";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(563, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"+ve Choose Folder";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(752, 97);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(122, 23);
			this->button2->TabIndex = 17;
			this->button2->Text = L"-ve Choose Folder";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(563, 126);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(127, 20);
			this->textBox3->TabIndex = 19;
			this->textBox3->Text = L"C:/";
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(752, 127);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(122, 20);
			this->textBox4->TabIndex = 20;
			this->textBox4->Text = L"C:/";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(272, 26);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(172, 18);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Prepare Training Data";
			this->label9->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(238, 206);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(89, 13);
			this->label10->TabIndex = 22;
			this->label10->Text = L"Output File Name";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(578, 203);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 23;
			this->textBox5->Text = L"positivedata";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(762, 203);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 24;
			this->textBox6->Text = L"negativedata";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(238, 164);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(116, 13);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Output Folder Directory";
			// 
			// textBox7
			// 
			this->textBox7->Enabled = false;
			this->textBox7->Location = System::Drawing::Point(563, 164);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(311, 20);
			this->textBox7->TabIndex = 26;
			this->textBox7->Text = L"C:/";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(563, 239);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(127, 23);
			this->button3->TabIndex = 27;
			this->button3->Text = L"Prepare +ve Data";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(752, 239);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(122, 23);
			this->button4->TabIndex = 28;
			this->button4->Text = L"Prepare -ve Data";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(437, 162);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(120, 23);
			this->button5->TabIndex = 29;
			this->button5->Text = L"Choose Output Folder";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(272, 265);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 13);
			this->label12->TabIndex = 30;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(938, 630);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->stop);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->cvtest);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->brightness))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->contrast))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void cvtest_Click(System::Object^  sender, System::EventArgs^  e) {
		if (cvtest->Text == "Detecting..") {
			cvtest->Text = "Start Detecting";
		}
		else {
			cvtest->Enabled = false;
			cvtest->Text = "Detecting..";
		}
		stop_record = false;
		timer1->Interval = millsecondsPerStep;
		timer1->Enabled = true;
		if (!stop_record) {
		button_test(pictureBox1, cvtest, brightness, contrast);
	}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		pictureBox2->BackColor = System::Drawing::Color::Green;
		stop_record = true;
		//timer1->Enabled = false;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (face_det()) {
		pictureBox2->BackColor = System::Drawing::Color::Green;
	}
		else
		{
			pictureBox2->BackColor = System::Drawing::Color::Red;
		}
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	//+ve input folder
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		textBox3->Text = folderBrowserDialog1->SelectedPath;
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//-ve input folder
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		textBox4->Text = folderBrowserDialog1->SelectedPath;
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//prepare +ve data
	positive_prep(textBox1, textBox3, textBox7, textBox5, label12);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	//prepare -ve data
	negative_prep(textBox4, textBox7, textBox6, label12);
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	if (folderBrowserDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		textBox7->Text = folderBrowserDialog1->SelectedPath;
	}
}
};
}

