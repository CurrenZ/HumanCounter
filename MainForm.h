#pragma once
#include "humancounting.h"
#include <string> 

namespace HumanCounter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form{
		public:
			MainForm(void)
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
			~MainForm()
			{
				if (components)
				{
					delete components;
				}
			}

		private: System::Windows::Forms::Label^  label1;

		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Button^  button3;

		private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
		private: System::Windows::Forms::Button^  button4;
		private: System::Windows::Forms::TextBox^  textBox1;
		private: System::Windows::Forms::Label^  label2;
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
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				this->button4 = (gcnew System::Windows::Forms::Button());
				this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->SuspendLayout();
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(21, 20);
				this->label1->Name = L"lb_choose_file";
				this->label1->Size = System::Drawing::Size(68, 13);
				this->label1->TabIndex = 0;
				this->label1->Text = L"Choose a file";
				// 
				// button1
				// 
				this->button1->Enabled = false;
				this->button1->Location = System::Drawing::Point(24, 79);
				this->button1->Name = L"bt_start";
				this->button1->Size = System::Drawing::Size(75, 23);
				this->button1->TabIndex = 2;
				this->button1->Text = L"Start";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &MainForm::bt_start_Click);
				// 
				// button2
				// 
				this->button2->Enabled = false;
				this->button2->Location = System::Drawing::Point(105, 79);
				this->button2->Name = L"bt_pause";
				this->button2->Size = System::Drawing::Size(75, 23);
				this->button2->TabIndex = 3;
				this->button2->Text = L"Pause";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &MainForm::bt_pause_Click);
				// 
				// button3
				// 
				this->button3->Enabled = false;
				this->button3->Location = System::Drawing::Point(186, 79);
				this->button3->Name = L"bt_stop";
				this->button3->Size = System::Drawing::Size(75, 23);
				this->button3->TabIndex = 4;
				this->button3->Text = L"Stop";
				this->button3->UseVisualStyleBackColor = true;
				this->button3->Click += gcnew System::EventHandler(this, &MainForm::bt_stop_Click);
				// 
				// openFileDialog1
				// 
				this->openFileDialog1->FileName = L"openFileDialog1";
				// 
				// button4
				// 
				this->button4->Location = System::Drawing::Point(210, 33);
				this->button4->Name = L"bt_browse";
				this->button4->Size = System::Drawing::Size(51, 23);
				this->button4->TabIndex = 6;
				this->button4->Text = L"...";
				this->button4->UseVisualStyleBackColor = true;
				this->button4->Click += gcnew System::EventHandler(this, &MainForm::bt_browse_Click);
				// 
				// textBox1
				// 
				this->textBox1->Location = System::Drawing::Point(24, 36);
				this->textBox1->Name = L"textBox1";
				this->textBox1->Size = System::Drawing::Size(180, 20);
				this->textBox1->TabIndex = 7;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Adobe Heiti Std R", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->label2->ForeColor = System::Drawing::Color::RoyalBlue;
				this->label2->Location = System::Drawing::Point(16, 158);
				this->label2->Name = L"lb_num_human";
				this->label2->Size = System::Drawing::Size(124, 46);
				this->label2->TabIndex = 8;
				this->label2->Text = L"";
				// 
				// MainForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(284, 261);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->textBox1);
				this->Controls->Add(this->button4);
				this->Controls->Add(this->button3);
				this->Controls->Add(this->button2);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->label1);
				this->Name = L"MainForm";
				this->Text = L"Human Counter";
				this->ResumeLayout(false);
				this->PerformLayout();

			}
		#pragma endregion
		private: System::Void bt_start_Click(System::Object^  sender, System::EventArgs^  e) {
			Thread^ trd_update_iNum = gcnew Thread(gcnew ThreadStart(this, &MainForm::update_iNum));
			trd_update_iNum->Start();
			label2->Text = System::Convert::ToString(iNum);
		}
		private: System::Void bt_pause_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void bt_stop_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void bt_browse_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->ShowDialog();
			textBox1->Text = openFileDialog1->FileName;
			if (textBox1->Text != "") {
				button1->Enabled = true;
				button2->Enabled = true;
				button3->Enabled = true;
			}
			else {
				button1->Enabled = false;
				button2->Enabled = false;
				button3->Enabled = false;
			}
		}

		void update_iNum() {
			this->Invoke(gcnew MethodInvoker(this, &MainForm::thread_update_iNum));
		}

		void thread_update_iNum() {
			num_human();
		}
	};

	
}
