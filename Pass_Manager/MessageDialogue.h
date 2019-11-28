#pragma once
#include "LoginPage.h"

namespace PassManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MessageDialogue
	/// </summary>
	public ref class MessageDialogue : public System::Windows::Forms::Form
	{
		public:
			MessageDialogue(String^ msg)
			{
				InitializeComponent();
				this->MessageDialogue_Message_Lbl->Text = msg;
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MessageDialogue()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^ MessageDialogue_Message_Lbl;
		private: System::Windows::Forms::Button^ MessageDialogue_Ok_Btn;

		private: const int CS_DropShadow = 0x20000;
		protected: virtual property System::Windows::Forms::CreateParams^ CreateParams {
			System::Windows::Forms::CreateParams^ get() override
			{
				System::Windows::Forms::CreateParams^ cp = Form::CreateParams;
				cp->ClassStyle |= CS_DropShadow;
				return cp;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MessageDialogue::typeid));
			this->MessageDialogue_Message_Lbl = (gcnew System::Windows::Forms::Label());
			this->MessageDialogue_Ok_Btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// MessageDialogue_Message_Lbl
			// 
			this->MessageDialogue_Message_Lbl->AutoSize = true;
			this->MessageDialogue_Message_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MessageDialogue_Message_Lbl->Location = System::Drawing::Point(40, 15);
			this->MessageDialogue_Message_Lbl->Name = L"MessageDialogue_Message_Lbl";
			this->MessageDialogue_Message_Lbl->Size = System::Drawing::Size(64, 25);
			this->MessageDialogue_Message_Lbl->TabIndex = 0;
			this->MessageDialogue_Message_Lbl->Text = L"label1";
			// 
			// MessageDialogue_Ok_Btn
			// 
			this->MessageDialogue_Ok_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->MessageDialogue_Ok_Btn->FlatAppearance->BorderSize = 0;
			this->MessageDialogue_Ok_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MessageDialogue_Ok_Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MessageDialogue_Ok_Btn->Location = System::Drawing::Point(220, 55);
			this->MessageDialogue_Ok_Btn->Name = L"MessageDialogue_Ok_Btn";
			this->MessageDialogue_Ok_Btn->Size = System::Drawing::Size(100, 32);
			this->MessageDialogue_Ok_Btn->TabIndex = 0;
			this->MessageDialogue_Ok_Btn->Text = L"Ok";
			this->MessageDialogue_Ok_Btn->UseVisualStyleBackColor = false;
			this->MessageDialogue_Ok_Btn->Click += gcnew System::EventHandler(this, &MessageDialogue::MessageDialogue_Ok_Btn_Click);
			// 
			// MessageDialogue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->ClientSize = System::Drawing::Size(540, 100);
			this->Controls->Add(this->MessageDialogue_Ok_Btn);
			this->Controls->Add(this->MessageDialogue_Message_Lbl);
			this->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MessageDialogue";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"MessageDialogue";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void MessageDialogue_Ok_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
		}
	};
}
