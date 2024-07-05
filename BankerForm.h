#include "Bankers_Algorithm.h"
#include <vector>
#pragma once

namespace OSProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BankerForm
	/// </summary>
	public ref class BankerForm : public System::Windows::Forms::Form
	{
	public:
		BankerForm(void)
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
		~BankerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ text_nprocess;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ text_nresource;
	private: System::Windows::Forms::Button^ button_check;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ text_allocation;
	private: System::Windows::Forms::Button^ button_allocation;
	private: System::Windows::Forms::RichTextBox^ rich_allocation;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ text_max;
	private: System::Windows::Forms::Button^ button_max;
	private: System::Windows::Forms::RichTextBox^ rich_max;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ text_available;
	private: System::Windows::Forms::RadioButton^ radioButton_safe;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::RichTextBox^ rich_need;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button_clear;
	private: System::Windows::Forms::Button^ button1;
	public:
		cli::array<int>^ seq;
		int row_alloc;
		int row_max;
		   int processes;
		   int resources;
		   int i = 0;
		   String^ input;
		   cli::array<cli::array<int>^>^ allocations;
		   cli::array<cli::array<int>^>^ maximums;
		   cli::array<cli::array<int>^>^ need;
		   cli::array<int>^ avail;
		   bool input_locked = false;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	public:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label8;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->text_nprocess = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->text_nresource = (gcnew System::Windows::Forms::TextBox());
			this->button_check = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->text_allocation = (gcnew System::Windows::Forms::TextBox());
			this->button_allocation = (gcnew System::Windows::Forms::Button());
			this->rich_allocation = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->text_max = (gcnew System::Windows::Forms::TextBox());
			this->button_max = (gcnew System::Windows::Forms::Button());
			this->rich_max = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->text_available = (gcnew System::Windows::Forms::TextBox());
			this->radioButton_safe = (gcnew System::Windows::Forms::RadioButton());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->rich_need = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button_clear = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(224, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"num processes";
			// 
			// text_nprocess
			// 
			this->text_nprocess->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->text_nprocess->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_nprocess->Location = System::Drawing::Point(356, 26);
			this->text_nprocess->Name = L"text_nprocess";
			this->text_nprocess->Size = System::Drawing::Size(87, 23);
			this->text_nprocess->TabIndex = 4;
			this->text_nprocess->TextChanged += gcnew System::EventHandler(this, &BankerForm::text_nprocess_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(516, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"num resources";
			// 
			// text_nresource
			// 
			this->text_nresource->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->text_nresource->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_nresource->Location = System::Drawing::Point(649, 29);
			this->text_nresource->Name = L"text_nresource";
			this->text_nresource->Size = System::Drawing::Size(87, 23);
			this->text_nresource->TabIndex = 6;
			this->text_nresource->TextChanged += gcnew System::EventHandler(this, &BankerForm::text_nresource_TextChanged);
			// 
			// button_check
			// 
			this->button_check->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_check->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_check->Location = System::Drawing::Point(392, 78);
			this->button_check->Name = L"button_check";
			this->button_check->Size = System::Drawing::Size(115, 26);
			this->button_check->TabIndex = 7;
			this->button_check->Text = L"Enter";
			this->button_check->UseVisualStyleBackColor = false;
			this->button_check->Click += gcnew System::EventHandler(this, &BankerForm::button_check_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(31, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(134, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Allocation matrix";
			// 
			// text_allocation
			// 
			this->text_allocation->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->text_allocation->Enabled = false;
			this->text_allocation->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_allocation->Location = System::Drawing::Point(30, 215);
			this->text_allocation->Name = L"text_allocation";
			this->text_allocation->Size = System::Drawing::Size(100, 23);
			this->text_allocation->TabIndex = 9;
			this->text_allocation->TextChanged += gcnew System::EventHandler(this, &BankerForm::text_allocation_TextChanged);
			// 
			// button_allocation
			// 
			this->button_allocation->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_allocation->Enabled = false;
			this->button_allocation->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_allocation->Location = System::Drawing::Point(32, 253);
			this->button_allocation->Name = L"button_allocation";
			this->button_allocation->Size = System::Drawing::Size(101, 23);
			this->button_allocation->TabIndex = 10;
			this->button_allocation->Text = L"Add row";
			this->button_allocation->UseVisualStyleBackColor = false;
			this->button_allocation->Click += gcnew System::EventHandler(this, &BankerForm::button_allocation_Click);
			// 
			// rich_allocation
			// 
			this->rich_allocation->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->rich_allocation->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rich_allocation->Location = System::Drawing::Point(175, 168);
			this->rich_allocation->Name = L"rich_allocation";
			this->rich_allocation->ReadOnly = true;
			this->rich_allocation->Size = System::Drawing::Size(200, 129);
			this->rich_allocation->TabIndex = 11;
			this->rich_allocation->Text = L"";
			this->rich_allocation->TextChanged += gcnew System::EventHandler(this, &BankerForm::rich_allocation_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(418, 171);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Max matrix";
			// 
			// text_max
			// 
			this->text_max->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->text_max->Enabled = false;
			this->text_max->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_max->Location = System::Drawing::Point(416, 215);
			this->text_max->Name = L"text_max";
			this->text_max->Size = System::Drawing::Size(91, 23);
			this->text_max->TabIndex = 13;
			// 
			// button_max
			// 
			this->button_max->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_max->Enabled = false;
			this->button_max->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_max->Location = System::Drawing::Point(416, 253);
			this->button_max->Name = L"button_max";
			this->button_max->Size = System::Drawing::Size(91, 25);
			this->button_max->TabIndex = 14;
			this->button_max->Text = L"Add row";
			this->button_max->UseVisualStyleBackColor = false;
			this->button_max->Click += gcnew System::EventHandler(this, &BankerForm::button_max_Click_1);
			// 
			// rich_max
			// 
			this->rich_max->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->rich_max->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rich_max->Location = System::Drawing::Point(542, 168);
			this->rich_max->Name = L"rich_max";
			this->rich_max->ReadOnly = true;
			this->rich_max->Size = System::Drawing::Size(209, 129);
			this->rich_max->TabIndex = 15;
			this->rich_max->Text = L"";
			this->rich_max->TextChanged += gcnew System::EventHandler(this, &BankerForm::rich_max_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(837, 168);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(126, 20);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Available Matrix";
			// 
			// text_available
			// 
			this->text_available->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->text_available->Enabled = false;
			this->text_available->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_available->Location = System::Drawing::Point(840, 215);
			this->text_available->Name = L"text_available";
			this->text_available->Size = System::Drawing::Size(100, 23);
			this->text_available->TabIndex = 17;
			this->text_available->TextChanged += gcnew System::EventHandler(this, &BankerForm::text_available_TextChanged_1);
			// 
			// radioButton_safe
			// 
			this->radioButton_safe->AutoSize = true;
			this->radioButton_safe->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->radioButton_safe->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton_safe->Location = System::Drawing::Point(713, 359);
			this->radioButton_safe->Name = L"radioButton_safe";
			this->radioButton_safe->Size = System::Drawing::Size(136, 24);
			this->radioButton_safe->TabIndex = 31;
			this->radioButton_safe->TabStop = true;
			this->radioButton_safe->Text = L"safe sequence";
			this->radioButton_safe->UseVisualStyleBackColor = false;
			this->radioButton_safe->CheckedChanged += gcnew System::EventHandler(this, &BankerForm::radioButton_safe_CheckedChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label10->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(31, 325);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 20);
			this->label10->TabIndex = 33;
			this->label10->Text = L"Need Matrix";
			// 
			// rich_need
			// 
			this->rich_need->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->rich_need->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rich_need->Location = System::Drawing::Point(34, 359);
			this->rich_need->Name = L"rich_need";
			this->rich_need->ReadOnly = true;
			this->rich_need->Size = System::Drawing::Size(330, 137);
			this->rich_need->TabIndex = 34;
			this->rich_need->Text = L"";
			this->rich_need->TextChanged += gcnew System::EventHandler(this, &BankerForm::rich_need_TextChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(469, 359);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(184, 137);
			this->richTextBox1->TabIndex = 35;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &BankerForm::richTextBox1_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label7->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(466, 325);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 20);
			this->label7->TabIndex = 36;
			this->label7->Text = L"Output";
			// 
			// button_clear
			// 
			this->button_clear->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_clear->Enabled = false;
			this->button_clear->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_clear->Location = System::Drawing::Point(867, 507);
			this->button_clear->Name = L"button_clear";
			this->button_clear->Size = System::Drawing::Size(109, 28);
			this->button_clear->TabIndex = 37;
			this->button_clear->Text = L"Clear";
			this->button_clear->UseVisualStyleBackColor = false;
			this->button_clear->Click += gcnew System::EventHandler(this, &BankerForm::button_clear_Click_1);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(713, 507);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 28);
			this->button1->TabIndex = 38;
			this->button1->Text = L"Check";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &BankerForm::button1_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(886, 358);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(87, 24);
			this->radioButton1->TabIndex = 39;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"request";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &BankerForm::radioButton1_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(889, 410);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(87, 23);
			this->textBox1->TabIndex = 40;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &BankerForm::textBox1_TextChanged);
			this->textBox1->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(889, 452);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(87, 23);
			this->textBox2->TabIndex = 41;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &BankerForm::textBox2_TextChanged);
			this->textBox2->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(739, 410);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 20);
			this->label1->TabIndex = 42;
			this->label1->Text = L"request process:";
			this->label1->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Montserrat SemiBold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(724, 452);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(144, 20);
			this->label8->TabIndex = 43;
			this->label8->Text = L"request resources:";
			this->label8->Visible = false;
			// 
			// BankerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->ClientSize = System::Drawing::Size(1002, 561);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button_clear);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->rich_need);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->radioButton_safe);
			this->Controls->Add(this->text_available);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->rich_max);
			this->Controls->Add(this->button_max);
			this->Controls->Add(this->text_max);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->rich_allocation);
			this->Controls->Add(this->button_allocation);
			this->Controls->Add(this->text_allocation);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button_check);
			this->Controls->Add(this->text_nresource);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->text_nprocess);
			this->Controls->Add(this->label2);
			this->Name = L"BankerForm";
			this->Text = L"BankerForm";
			this->Load += gcnew System::EventHandler(this, &BankerForm::BankerForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		protected:

	private: System::Void button_check_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Int32::TryParse(text_nprocess->Text, processes) && Int32::TryParse(text_nresource->Text, resources)) {
			allocations = gcnew cli::array<cli::array<int>^>(processes);
			maximums = gcnew cli::array<cli::array<int>^>(processes);
			avail = gcnew cli::array<int>(resources);
			for (int k = 0; k < processes; ++k) {
				allocations[k] = gcnew cli::array<int>(resources);
				maximums[k] = gcnew cli::array<int>(resources);
			}
			text_allocation->Enabled = true;
			button_allocation->Enabled = true;
			rich_allocation->Enabled = true;
			text_max->Enabled = true;
			button_max->Enabled = true;
			rich_max->Enabled = true;
			text_available->Enabled = true;
			radioButton_safe->Enabled = true;
			button1->Enabled = true;
			text_nprocess->Enabled = false;
			text_nresource->Enabled = false;
			button_clear->Enabled = true;
		}
	}

	private: System::Void button_allocation_Click(System::Object^ sender, System::EventArgs^ e) {
		if (row_alloc < processes) {
			cli::array<String^>^ parts = text_allocation->Text->Split(' ');
			if (parts->Length != resources) {
				// handle error
				return;
			}
			for (int k = 0; k < resources; ++k) {
				int value = Convert::ToInt32(parts[k]);
				if (value < 0) {
					MessageBox::Show("Please do not enter negative values!");
					text_max->Clear();
					return;
				}
				allocations[row_alloc][k] = value;
			}
			++row_alloc;
			if (row_alloc == processes) {
				text_allocation->Enabled = false;
				button_allocation->Enabled = false;
				rich_allocation->Enabled = false;
			}
			// display allocations matrix in rich_allocation
			rich_allocation->Text = "";
			for (int i = 0; i < row_alloc; ++i) {
				rich_allocation->Text += "P" + i + " -> ";
				for (int j = 0; j < resources; ++j) {
					rich_allocation->Text += allocations[i][j] + " ";
				}
				rich_allocation->Text += "\n";
			}
			text_allocation->Clear();
			button_clear->Enabled = true;
		}
	}

	private: System::Void button_max_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (row_max < processes) {
			cli::array<String^>^ parts = text_max->Text->Split(' ');
			if (parts->Length != resources) {
				// handle error
				return;
			}
			for (int k = 0; k < resources; ++k) {
				int value = Convert::ToInt32(parts[k]);
				if (value < 0) {
					MessageBox::Show("Please do not enter negative values!");
					text_max->Clear();
					return;
				}
				maximums[row_max][k] = value;
			}
			++row_max;
			if (row_max == processes) {
				text_max->Enabled = false;
				button_max->Enabled = false;
				rich_max->Enabled = false;

			}
			// display maximum matrix in rich_max
			rich_max->Text = "";
			for (int i = 0; i < row_max; ++i) {
				rich_max->Text += "P" + i + " -> ";
				for (int j = 0; j < resources; ++j) {
					rich_max->Text += maximums[i][j] + " ";
				}
				rich_max->Text += "\n";
			}
			text_max->Clear();
			button_clear->Enabled = true;
		}
	}


	private: System::Void button_clear_Click_1(System::Object^ sender, System::EventArgs^ e) {
		text_nprocess->Clear();
		text_nresource->Clear();
		text_allocation->Clear();
		text_allocation->Enabled = false;
		button_allocation->Enabled = false;
		rich_allocation->Clear();
		rich_allocation->Enabled = false;
		text_max->Clear();
		text_max->Enabled = false;
		button_max->Enabled = false;
		rich_max->Clear();
		rich_max->Enabled = false;
		text_available->Clear();
		text_available->Enabled = false;
		rich_need->Clear();
		richTextBox1->Clear();
		radioButton_safe->Enabled = false;
		button1->Enabled = false;
		processes = 0;
		resources = 0;
		row_alloc = 0;
		row_max = 0;
	}
	private: System::Void text_allocation_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void text_nprocess_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void text_nresource_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void rich_allocation_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Calculate need matrix
		need = gcnew cli::array<cli::array<int>^>(processes);
		for (int i = 0; i < processes; ++i) {
			need[i] = gcnew cli::array<int>(resources);
			for (int j = 0; j < resources; ++j) {
				need[i][j] = maximums[i][j] - allocations[i][j];
			}
		}

		// Display need matrix in rich_need
		rich_need->Text = "";
		for (int i = 0; i < processes; ++i) {
			rich_need->Text += "P" + i + " -> ";
			for (int j = 0; j < resources; ++j) {
				rich_need->Text += need[i][j] + " ";
			}
			rich_need->Text += "\n";
		}

		// Enable check button to find safe sequence
		button1->Enabled = true;
	}

	private: System::Void text_available_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void radioButton_safe_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton_safe->Checked) {
			cli::array<String^>^ values = text_available->Text->Split(' ');
			for (int j = 0; j < resources; j++) {
				int value = Convert::ToInt32(values[j]);
				if (value < 0) {
					MessageBox::Show("Please do not enter negative values!");
					radioButton_safe->Checked = false;
					return;
				}
			}
			// Calculate safe sequence
			seq = gcnew cli::array<int>(processes);
			int finished = processes;
			cli::array<int>^ work = gcnew cli::array<int>(resources);
			cli::array<bool>^ finish = gcnew cli::array<bool>(processes);

			// Initialize work array with available resources
			for (int i = 0; i < resources; ++i) {
				work[i] = avail[i];
			}

			// Initialize finish array to false
			for (int i = 0; i < processes; ++i) {
				finish[i] = false;
			}

			// Find safe sequence
			while (finished != 0) {
				int counter = finished;
				for (int i = 0; i < processes; ++i) {
					if (!finish[i]) {
						bool canAllocate = true;
						for (int j = 0; j < resources; ++j) {
							if (need[i][j] > work[j]) {
								canAllocate = false;
								break;
							}
						}
						if (canAllocate) {
							// Process i can be completed
							finish[i] = true;
							seq[processes - finished] = i; // Add process to the safe sequence
							for (int j = 0; j < resources; ++j) {
								work[j] += allocations[i][j]; // Release allocated resources
							}
							--finished;
						}
					}
				}

				// If no process can be completed, break the loop
				if (counter == finished) {
					break;
				}
			}

			// If finished is zero, all processes can complete, return true
			if (finished == 0) {
				// Display safe sequence in richTextBox1
				richTextBox1->Text = "Safe sequence: ";
				for (int i = 0; i < processes; ++i) {
					richTextBox1->Text += "P" + seq[i] + " ";
				}
			}
			else {
				// Handle unsafe state
				richTextBox1->Text = "Unsafe state!";
			}
		}
		button_clear->Enabled = true;
	}


private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void rich_need_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void BankerForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void rich_max_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	bool isChecked = radioButton1->Checked;
	label1->Visible = isChecked;
	label8->Visible = isChecked;
	textBox1->Visible = isChecked;
	textBox2->Visible = isChecked;
	/*int pid = Convert::ToInt32(textBox1->Text);
	cli::array<String^>^ values = textBox2->Text->Split(' ');
	for (int j = 0; j < resources; j++) {
		int value = Convert::ToInt32(values[j]);
		if (value < 0) {
			MessageBox::Show("Please do not enter negative values!");
			radioButton_safe->Checked = false;
			return;
		}
	}*/
}
};
}