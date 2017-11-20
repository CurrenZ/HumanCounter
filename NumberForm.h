#pragma once
#include "humancounting.h"

namespace HumanCounter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for NumberForm
	/// </summary>
	public ref class NumberForm : public System::Windows::Forms::Form
	{
	public:
		NumberForm(void)
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
		~NumberForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NumberForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(38, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"00";
			// 
			// NumberForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(184, 161);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"NumberForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Number";
			this->Load += gcnew System::EventHandler(this, &NumberForm::NumberForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void NumberForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Thread^ trd_update_iNum = gcnew Thread(gcnew ThreadStart(this, &NumberForm::update_iNum));
		trd_update_iNum->Start();
		label1->Text = System::Convert::ToString(iNum);

	}

			 void update_iNum() {
				 this->Invoke(gcnew MethodInvoker(this, &NumberForm::thread_update_iNum));
			 }

			 void thread_update_iNum() {
				 num_human();
			 }

	};
}
