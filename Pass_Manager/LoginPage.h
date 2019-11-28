#pragma once
#include "MainPage.h"
#include "SharedData.h"
#include "MessageDialogue.h"

namespace PassManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LogIn
	/// </summary>
	public ref class LoginPage : public System::Windows::Forms::Form
	{
		public:
			LoginPage(void)
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
			~LoginPage()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Label^ LoginPage_Key_Lbl;
		private: System::Windows::Forms::TextBox^ LogInPage_Key_Txt;
		private: System::Windows::Forms::Button^ LogIn_Enter_Btn;
		private: System::Windows::Forms::Button^ LoginPage_Minimize_Btn;
		private: System::Windows::Forms::Button^ LoginPage_Close_Btn;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginPage::typeid));
			this->LoginPage_Key_Lbl = (gcnew System::Windows::Forms::Label());
			this->LogInPage_Key_Txt = (gcnew System::Windows::Forms::TextBox());
			this->LogIn_Enter_Btn = (gcnew System::Windows::Forms::Button());
			this->LoginPage_Minimize_Btn = (gcnew System::Windows::Forms::Button());
			this->LoginPage_Close_Btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LoginPage_Key_Lbl
			// 
			this->LoginPage_Key_Lbl->AutoSize = true;
			this->LoginPage_Key_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginPage_Key_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->LoginPage_Key_Lbl->Location = System::Drawing::Point(80, 60);
			this->LoginPage_Key_Lbl->Name = L"LoginPage_Key_Lbl";
			this->LoginPage_Key_Lbl->Size = System::Drawing::Size(60, 29);
			this->LoginPage_Key_Lbl->TabIndex = 0;
			this->LoginPage_Key_Lbl->Text = L"Key:";
			// 
			// LogInPage_Key_Txt
			// 
			this->LogInPage_Key_Txt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->LogInPage_Key_Txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->LogInPage_Key_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LogInPage_Key_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->LogInPage_Key_Txt->Location = System::Drawing::Point(148, 56);
			this->LogInPage_Key_Txt->Name = L"LogInPage_Key_Txt";
			this->LogInPage_Key_Txt->PasswordChar = '*';
			this->LogInPage_Key_Txt->Size = System::Drawing::Size(400, 37);
			this->LogInPage_Key_Txt->TabIndex = 1;
			this->LogInPage_Key_Txt->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &LoginPage::LogInPage_Key_Txt_KeyDown);
			// 
			// LogIn_Enter_Btn
			// 
			this->LogIn_Enter_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->LogIn_Enter_Btn->FlatAppearance->BorderSize = 0;
			this->LogIn_Enter_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LogIn_Enter_Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LogIn_Enter_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->LogIn_Enter_Btn->Location = System::Drawing::Point(560, 56);
			this->LogIn_Enter_Btn->Name = L"LogIn_Enter_Btn";
			this->LogIn_Enter_Btn->Size = System::Drawing::Size(100, 37);
			this->LogIn_Enter_Btn->TabIndex = 2;
			this->LogIn_Enter_Btn->Text = L"Enter";
			this->LogIn_Enter_Btn->UseVisualStyleBackColor = false;
			this->LogIn_Enter_Btn->Click += gcnew System::EventHandler(this, &LoginPage::LogIn_Enter_Btn_Click);
			// 
			// LoginPage_Minimize_Btn
			// 
			this->LoginPage_Minimize_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->LoginPage_Minimize_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoginPage_Minimize_Btn.BackgroundImage")));
			this->LoginPage_Minimize_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LoginPage_Minimize_Btn->FlatAppearance->BorderSize = 0;
			this->LoginPage_Minimize_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoginPage_Minimize_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->LoginPage_Minimize_Btn->Location = System::Drawing::Point(675, 1);
			this->LoginPage_Minimize_Btn->Name = L"LoginPage_Minimize_Btn";
			this->LoginPage_Minimize_Btn->Size = System::Drawing::Size(32, 32);
			this->LoginPage_Minimize_Btn->TabIndex = 4;
			this->LoginPage_Minimize_Btn->UseVisualStyleBackColor = false;
			this->LoginPage_Minimize_Btn->Click += gcnew System::EventHandler(this, &LoginPage::LoginPage_Minimize_Btn_Click);
			// 
			// LoginPage_Close_Btn
			// 
			this->LoginPage_Close_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->LoginPage_Close_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoginPage_Close_Btn.BackgroundImage")));
			this->LoginPage_Close_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LoginPage_Close_Btn->FlatAppearance->BorderSize = 0;
			this->LoginPage_Close_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoginPage_Close_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->LoginPage_Close_Btn->Location = System::Drawing::Point(707, 1);
			this->LoginPage_Close_Btn->Name = L"LoginPage_Close_Btn";
			this->LoginPage_Close_Btn->Size = System::Drawing::Size(32, 32);
			this->LoginPage_Close_Btn->TabIndex = 5;
			this->LoginPage_Close_Btn->UseVisualStyleBackColor = false;
			this->LoginPage_Close_Btn->Click += gcnew System::EventHandler(this, &LoginPage::LoginPage_Close_Btn_Click);
			// 
			// LoginPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(740, 150);
			this->Controls->Add(this->LoginPage_Close_Btn);
			this->Controls->Add(this->LoginPage_Minimize_Btn);
			this->Controls->Add(this->LogIn_Enter_Btn);
			this->Controls->Add(this->LogInPage_Key_Txt);
			this->Controls->Add(this->LoginPage_Key_Lbl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"LoginPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LogIn";
			this->Load += gcnew System::EventHandler(this, &LoginPage::LoginPage_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &LoginPage::LoginPage_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &LoginPage::LoginPage_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &LoginPage::LoginPage_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void LoginPage_Load(System::Object^ sender, System::EventArgs^ e) {
			this->dragging = false;
			if (!DataFileExists()) {
				PassManager::MessageDialogue^ md = gcnew PassManager::MessageDialogue("Enter a key you want to encrypt your data with!");
				md->ShowDialog();
			}
		}
		private: System::Void LoginPage_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		}
		private: System::Void LoginPage_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (this->dragging) {
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
			}
		}
		private: System::Void LoginPage_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->dragging = false;
		}
		
		// display the main page when enter is pressed
		private: System::Void LogIn_Enter_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			int len = this->LogInPage_Key_Txt->Text->Length;
			if (!len) {
				return;
			}
			if (!DataFileExists() && (len < 8 || len > 32)) {
				MessageDialogue^ md = gcnew MessageDialogue("Please enter a key of length 8 - 32 characters.");
				md->ShowDialog();
			}
			else {
				String^ k = this->LogInPage_Key_Txt->Text;
				if (len < 32) {
					// pad the key
					int i = 0;
					while (len < 32) {
						k += k[i++];
						len++;
					}
				}
				Globals::key = System::Text::Encoding::ASCII->GetBytes(k);
				if (!OpenDataFile()) {
					MessageDialogue^ md = gcnew MessageDialogue("Key entered is invalid!");
					md->ShowDialog();
					return;// return because key entered is invalid
				}
				
				this->Hide();
				// add code to check key is valid
				MainPage^ mp = gcnew MainPage();
				mp->ShowDialog();
			}
		}
		// close the window
		private: System::Void LoginPage_Close_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
		// minimize the window
		private: System::Void LoginPage_Minimize_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->WindowState = FormWindowState::Minimized;
		}
		// if enter is pressed in textbox
		private: System::Void LogInPage_Key_Txt_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter) {
				LogIn_Enter_Btn_Click(nullptr, nullptr);
			}
		}
	};
}
