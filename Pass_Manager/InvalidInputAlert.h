#pragma once

namespace PassManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NewEntryPage
	/// </summary>
	public ref class InvalidInputAlert : public System::Windows::Forms::Form
	{
		public:
			InvalidInputAlert(String^ s)
			{
				InitializeComponent();
				this->InvalidInputAlert_Message_Lbl->Text = s;
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~InvalidInputAlert()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^ ConfirmationPage_Close_Btn;
		private: System::Windows::Forms::Button^ InvalidInputAlert_Ok_Btn;
		private: System::Windows::Forms::Label^ InvalidInputAlert_Message_Lbl;

		// used to drag window around
		private: bool dragging;
		private: Point offset;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InvalidInputAlert::typeid));
			this->ConfirmationPage_Close_Btn = (gcnew System::Windows::Forms::Button());
			this->InvalidInputAlert_Ok_Btn = (gcnew System::Windows::Forms::Button());
			this->InvalidInputAlert_Message_Lbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ConfirmationPage_Close_Btn
			// 
			this->ConfirmationPage_Close_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ConfirmationPage_Close_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ConfirmationPage_Close_Btn.BackgroundImage")));
			this->ConfirmationPage_Close_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ConfirmationPage_Close_Btn->FlatAppearance->BorderSize = 0;
			this->ConfirmationPage_Close_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ConfirmationPage_Close_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ConfirmationPage_Close_Btn->Location = System::Drawing::Point(710, 0);
			this->ConfirmationPage_Close_Btn->Name = L"ConfirmationPage_Close_Btn";
			this->ConfirmationPage_Close_Btn->Size = System::Drawing::Size(30, 30);
			this->ConfirmationPage_Close_Btn->TabIndex = 3;
			this->ConfirmationPage_Close_Btn->UseVisualStyleBackColor = false;
			// 
			// InvalidInputAlert_Ok_Btn
			// 
			this->InvalidInputAlert_Ok_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->InvalidInputAlert_Ok_Btn->FlatAppearance->BorderSize = 0;
			this->InvalidInputAlert_Ok_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->InvalidInputAlert_Ok_Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->InvalidInputAlert_Ok_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->InvalidInputAlert_Ok_Btn->Location = System::Drawing::Point(220, 55);
			this->InvalidInputAlert_Ok_Btn->Name = L"InvalidInputAlert_Ok_Btn";
			this->InvalidInputAlert_Ok_Btn->Size = System::Drawing::Size(100, 32);
			this->InvalidInputAlert_Ok_Btn->TabIndex = 0;
			this->InvalidInputAlert_Ok_Btn->Text = L"Ok";
			this->InvalidInputAlert_Ok_Btn->UseVisualStyleBackColor = false;
			this->InvalidInputAlert_Ok_Btn->Click += gcnew System::EventHandler(this, &InvalidInputAlert::InvalidInputAlert_Ok_Btn_Click);
			// 
			// InvalidInputAlert_Message_Lbl
			// 
			this->InvalidInputAlert_Message_Lbl->AutoSize = true;
			this->InvalidInputAlert_Message_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->InvalidInputAlert_Message_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->InvalidInputAlert_Message_Lbl->Location = System::Drawing::Point(40, 15);
			this->InvalidInputAlert_Message_Lbl->Name = L"InvalidInputAlert_Message_Lbl";
			this->InvalidInputAlert_Message_Lbl->Size = System::Drawing::Size(64, 25);
			this->InvalidInputAlert_Message_Lbl->TabIndex = 4;
			this->InvalidInputAlert_Message_Lbl->Text = L"label1";
			// 
			// InvalidInputAlert
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->ClientSize = System::Drawing::Size(540, 100);
			this->Controls->Add(this->InvalidInputAlert_Message_Lbl);
			this->Controls->Add(this->InvalidInputAlert_Ok_Btn);
			this->Controls->Add(this->ConfirmationPage_Close_Btn);
			this->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"InvalidInputAlert";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"NewEntryPage";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &InvalidInputAlert::ConfirmationPage_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &InvalidInputAlert::ConfirmationPage_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &InvalidInputAlert::ConfirmationPage_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &InvalidInputAlert::ConfirmationPage_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void ConfirmationPage_Load(System::Object^ sender, System::EventArgs^ e) {
			this->dragging = false;
		}
		private: System::Void ConfirmationPage_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		}
		private: System::Void ConfirmationPage_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (this->dragging) {
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
			}
		}
		private: System::Void ConfirmationPage_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->dragging = false;
		}
		private: System::Void InvalidInputAlert_Ok_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
};
}
