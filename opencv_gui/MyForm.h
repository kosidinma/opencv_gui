#pragma once

namespace opencv_gui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/** Function Headers */
	int button_test(void);
	void Erosion(int, void*);
	void Dilation(int, void*);


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
	private: System::Windows::Forms::Button^  cvtest;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cvtest = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cvtest
			// 
			this->cvtest->Location = System::Drawing::Point(27, 240);
			this->cvtest->Name = L"cvtest";
			this->cvtest->Size = System::Drawing::Size(107, 34);
			this->cvtest->TabIndex = 0;
			this->cvtest->Text = L"Test";
			this->cvtest->UseVisualStyleBackColor = true;
			this->cvtest->Click += gcnew System::EventHandler(this, &MyForm::cvtest_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(508, 347);
			this->Controls->Add(this->cvtest);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void cvtest_Click(System::Object^  sender, System::EventArgs^  e) {
		button_test();
	}
	};
}


