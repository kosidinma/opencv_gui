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
			this->pictureBox1->Size = System::Drawing::Size(331, 313);
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
			this->contrast->Size = System::Drawing::Size(104, 44);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(730, 630);
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
};
}

