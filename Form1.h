/*#include "Bankers_Algorithm.h"
namespace OS_Project
{
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1()
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::IContainer^ components;

        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->text_nprocess = (gcnew System::Windows::Forms::TextBox());
            this->text_nresource = (gcnew System::Windows::Forms::TextBox());
            this->button_check = (gcnew System::Windows::Forms::Button());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->text_allocation = (gcnew System::Windows::Forms::TextBox());
            this->rich_allocation = (gcnew System::Windows::Forms::RichTextBox());
            this->button_allocation = (gcnew System::Windows::Forms::Button());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->text_max = (gcnew System::Windows::Forms::TextBox());
            this->rich_max = (gcnew System::Windows::Forms::RichTextBox());
            this->button_max = (gcnew System::Windows::Forms::Button());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->text_available = (gcnew System::Windows::Forms::TextBox());
            this->rich_output = (gcnew System::Windows::Forms::RichTextBox());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->button_safe = (gcnew System::Windows::Forms::Button());
            this->button_clear = (gcnew System::Windows::Forms::Button());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->rich_need = (gcnew System::Windows::Forms::RichTextBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->text_Prequest = (gcnew System::Windows::Forms::TextBox());
            this->text_Rrequest = (gcnew System::Windows::Forms::TextBox());
            this->radioButton_safe = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton_request = (gcnew System::Windows::Forms::RadioButton());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(308, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(123, 17);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Bankers Algorithm";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(31, 54);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(104, 17);
            this->label2->TabIndex = 1;
            this->label2->Text = L"num processes";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(33, 82);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(102, 17);
            this->label3->TabIndex = 2;
            this->label3->Text = L"num resources";
            // 
            // text_nprocess
            // 
            this->text_nprocess->Location = System::Drawing::Point(180, 49);
            this->text_nprocess->Name = L"text_nprocess";
            this->text_nprocess->Size = System::Drawing::Size(87, 22);
            this->text_nprocess->TabIndex = 3;
            this->text_nprocess->TextChanged += gcnew System::EventHandler(this, &Form1::text_nprocess_TextChanged);
            // 
            // text_nresource
            // 
            this->text_nresource->Location = System::Drawing::Point(180, 82);
            this->text_nresource->Name = L"text_nresource";
            this->text_nresource->Size = System::Drawing::Size(87, 22);
            this->text_nresource->TabIndex = 4;
            // 
            // button_check
            // 
            this->button_check->Location = System::Drawing::Point(402, 47);
            this->button_check->Name = L"button_check";
            this->button_check->Size = System::Drawing::Size(115, 26);
            this->button_check->TabIndex = 5;
            this->button_check->Text = L"Enter";
            this->button_check->UseVisualStyleBackColor = true;
            this->button_check->Click += gcnew System::EventHandler(this, &Form1::button_check_Click);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(50, 141);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(110, 17);
            this->label4->TabIndex = 6;
            this->label4->Text = L"Allocation matrix";
            // 
            // text_allocation
            // 
            this->text_allocation->Enabled = false;
            this->text_allocation->Location = System::Drawing::Point(52, 181);
            this->text_allocation->Name = L"text_allocation";
            this->text_allocation->Size = System::Drawing::Size(100, 22);
            this->text_allocation->TabIndex = 7;
            // 
            // rich_allocation
            // 
            this->rich_allocation->Location = System::Drawing::Point(180, 146);
            this->rich_allocation->Name = L"rich_allocation";
            this->rich_allocation->ReadOnly = true;
            this->rich_allocation->Size = System::Drawing::Size(200, 129);
            this->rich_allocation->TabIndex = 8;
            this->rich_allocation->Text = L"";
            // 
            // button_allocation
            // 
            this->button_allocation->Enabled = false;
            this->button_allocation->Location = System::Drawing::Point(53, 224);
            this->button_allocation->Name = L"button_allocation";
            this->button_allocation->Size = System::Drawing::Size(101, 23);
            this->button_allocation->TabIndex = 9;
            this->button_allocation->Text = L"Add row";
            this->button_allocation->UseVisualStyleBackColor = true;
            this->button_allocation->Click += gcnew System::EventHandler(this, &Form1::button_allocation_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(436, 141);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(74, 17);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Max matrix";
            // 
            // text_max
            // 
            this->text_max->Enabled = false;
            this->text_max->Location = System::Drawing::Point(428, 183);
            this->text_max->Name = L"text_max";
            this->text_max->Size = System::Drawing::Size(91, 22);
            this->text_max->TabIndex = 11;
            // 
            // rich_max
            // 
            this->rich_max->Location = System::Drawing::Point(555, 146);
            this->rich_max->Name = L"rich_max";
            this->rich_max->ReadOnly = true;
            this->rich_max->Size = System::Drawing::Size(209, 129);
            this->rich_max->TabIndex = 12;
            this->rich_max->Text = L"";
            this->rich_max->TextChanged += gcnew System::EventHandler(this, &Form1::rich_max_TextChanged);
            // 
            // button_max
            // 
            this->button_max->Enabled = false;
            this->button_max->Location = System::Drawing::Point(428, 222);
            this->button_max->Name = L"button_max";
            this->button_max->Size = System::Drawing::Size(91, 25);
            this->button_max->TabIndex = 13;
            this->button_max->Text = L"Add row";
            this->button_max->UseVisualStyleBackColor = true;
            this->button_max->Click += gcnew System::EventHandler(this, &Form1::button_max_Click);
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(50, 314);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(65, 17);
            this->label6->TabIndex = 14;
            this->label6->Text = L"Available";
            // 
            // text_available
            // 
            this->text_available->Enabled = false;
            this->text_available->Location = System::Drawing::Point(53, 348);
            this->text_available->Name = L"text_available";
            this->text_available->Size = System::Drawing::Size(100, 22);
            this->text_available->TabIndex = 15;
            // 
            // rich_output
            // 
            this->rich_output->Location = System::Drawing::Point(51, 430);
            this->rich_output->Name = L"rich_output";
            this->rich_output->ReadOnly = true;
            this->rich_output->Size = System::Drawing::Size(696, 96);
            this->rich_output->TabIndex = 16;
            this->rich_output->Text = L"";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(333, 400);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(51, 17);
            this->label7->TabIndex = 17;
            this->label7->Text = L"Output";
            // 
            // button_safe
            // 
            this->button_safe->Enabled = false;
            this->button_safe->Location = System::Drawing::Point(563, 372);
            this->button_safe->Name = L"button_safe";
            this->button_safe->Size = System::Drawing::Size(183, 39);
            this->button_safe->TabIndex = 18;
            this->button_safe->Text = L"Check safety";
            this->button_safe->UseVisualStyleBackColor = true;
            this->button_safe->Click += gcnew System::EventHandler(this, &Form1::button_safe_Click);
            // 
            // button_clear
            // 
            this->button_clear->Enabled = false;
            this->button_clear->Location = System::Drawing::Point(53, 384);
            this->button_clear->Name = L"button_clear";
            this->button_clear->Size = System::Drawing::Size(109, 28);
            this->button_clear->TabIndex = 19;
            this->button_clear->Text = L"Clear";
            this->button_clear->UseVisualStyleBackColor = true;
            this->button_clear->Click += gcnew System::EventHandler(this, &Form1::button_clear_Click);
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Location = System::Drawing::Point(450, 280);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(42, 17);
            this->label10->TabIndex = 24;
            this->label10->Text = L"Need";
            // 
            // rich_need
            // 
            this->rich_need->Location = System::Drawing::Point(553, 285);
            this->rich_need->Name = L"rich_need";
            this->rich_need->ReadOnly = true;
            this->rich_need->Size = System::Drawing::Size(211, 81);
            this->rich_need->TabIndex = 25;
            this->rich_need->Text = L"";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(282, 49);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(17, 17);
            this->label8->TabIndex = 26;
            this->label8->Text = L"P";
            this->label8->Visible = false;
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->Location = System::Drawing::Point(281, 86);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(18, 17);
            this->label9->TabIndex = 27;
            this->label9->Text = L"R";
            this->label9->Visible = false;
            // 
            // text_Prequest
            // 
            this->text_Prequest->Location = System::Drawing::Point(309, 46);
            this->text_Prequest->Name = L"text_Prequest";
            this->text_Prequest->Size = System::Drawing::Size(54, 22);
            this->text_Prequest->TabIndex = 28;
            this->text_Prequest->Visible = false;
            // 
            // text_Rrequest
            // 
            this->text_Rrequest->Location = System::Drawing::Point(309, 83);
            this->text_Rrequest->Name = L"text_Rrequest";
            this->text_Rrequest->Size = System::Drawing::Size(54, 22);
            this->text_Rrequest->TabIndex = 29;
            this->text_Rrequest->Visible = false;
            // 
            // radioButton_safe
            // 
            this->radioButton_safe->AutoSize = true;
            this->radioButton_safe->Location = System::Drawing::Point(610, 34);
            this->radioButton_safe->Name = L"radioButton_safe";
            this->radioButton_safe->Size = System::Drawing::Size(112, 21);
            this->radioButton_safe->TabIndex = 30;
            this->radioButton_safe->TabStop = true;
            this->radioButton_safe->Text = L"Safety Check";
            this->radioButton_safe->UseVisualStyleBackColor = true;
            this->radioButton_safe->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_safe_CheckedChanged);
            // 
            // radioButton_request
            // 
            this->radioButton_request->AutoSize = true;
            this->radioButton_request->Location = System::Drawing::Point(599, 82);
            this->radioButton_request->Name = L"radioButton_request";
            this->radioButton_request->Size = System::Drawing::Size(123, 21);
            this->radioButton_request->TabIndex = 31;
            this->radioButton_request->TabStop = true;
            this->radioButton_request->Text = L"Request check";
            this->radioButton_request->UseVisualStyleBackColor = true;
            this->radioButton_request->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_request_CheckedChanged);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 563);
            this->Controls->Add(this->radioButton_request);
            this->Controls->Add(this->radioButton_safe);
            this->Controls->Add(this->text_Rrequest);
            this->Controls->Add(this->text_Prequest);
            this->Controls->Add(this->label9);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->rich_need);
            this->Controls->Add(this->label10);
            this->Controls->Add(this->button_clear);
            this->Controls->Add(this->button_safe);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->rich_output);
            this->Controls->Add(this->text_available);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->button_max);
            this->Controls->Add(this->rich_max);
            this->Controls->Add(this->text_max);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->button_allocation);
            this->Controls->Add(this->rich_allocation);
            this->Controls->Add(this->text_allocation);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->button_check);
            this->Controls->Add(this->text_nresource);
            this->Controls->Add(this->text_nprocess);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma region Windows Form Designer generated code
        // Form designer generated code
#pragma endregion
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ text_nprocess;
    private: System::Windows::Forms::TextBox^ text_nresource;
    private: System::Windows::Forms::Button^ button_check;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::TextBox^ text_allocation;
    private: System::Windows::Forms::RichTextBox^ rich_allocation;
    private: System::Windows::Forms::Button^ button_allocation;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::TextBox^ text_max;
    private: System::Windows::Forms::RichTextBox^ rich_max;
    private: System::Windows::Forms::Button^ button_max;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::TextBox^ text_available;
    private: System::Windows::Forms::RichTextBox^ rich_output;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Button^ button_safe;
    private: System::Windows::Forms::Button^ button_clear;
    private: System::Windows::Forms::Label^ label10;
    private: System::Windows::Forms::RichTextBox^ rich_need;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::TextBox^ text_Prequest;
    private: System::Windows::Forms::TextBox^ text_Rrequest;
    private: System::Windows::Forms::RadioButton^ radioButton_safe;
    private: System::Windows::Forms::RadioButton^ radioButton_request;
    private: System::Void button_check_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void rich_max_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void text_nprocess_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}*/
