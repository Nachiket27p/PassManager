#pragma once
#include "SharedData.h"
#include "MainPage.h"
#include "InvalidInputAlert.h"

namespace PassManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ModifyEntryPage
	/// </summary>
	public ref class ModifyEntryPage : public System::Windows::Forms::Form
	{
		public:
			ModifyEntryPage()
			{
				InitializeComponent();
			}
			ModifyEntryPage(String^ name, String^ userName, String^ password, String^ notes)
			{
				InitializeComponent();

				this->ModifyEntryPage_Name_Txt->ReadOnly = true;
				this->ModifyEntryPage_Name_Txt->Text = name;
				this->ModifyEntryPage_UserName_Txt->Text = userName;
				this->ModifyEntryPage_Password_Txt->Text = password;
				this->ModifyEntryPage_Notes_Txt->Text = notes;
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~ModifyEntryPage()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^ ModifyEntryPage_Close_Btn;
		private: System::Windows::Forms::Label^ ModifyEntryPage_Name_Lbl;
		private: System::Windows::Forms::Label^ ModifyEntryPage_UserName_Lbl;
		private: System::Windows::Forms::Label^ ModifyEntryPage_Password_Lbl;
		private: System::Windows::Forms::Label^ ModifyEntryPage_Notes_Lbl;
		private: System::Windows::Forms::TextBox^ ModifyEntryPage_Name_Txt;
		private: System::Windows::Forms::TextBox^ ModifyEntryPage_UserName_Txt;
		private: System::Windows::Forms::TextBox^ ModifyEntryPage_Password_Txt;
		private: System::Windows::Forms::TextBox^ ModifyEntryPage_Notes_Txt;
		private: System::Windows::Forms::Button^ ModifyEntryPage_Save_Btn;
		private: System::Windows::Forms::Button^ ModifyEntryPage_Minimize_Btn;

	
		// used to drag window around
		private: bool dragging;
		private: Point offset;
		// used to indicate to MainPage that a new entry was added
		private: bool newAdded = false;
	
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModifyEntryPage::typeid));
			this->ModifyEntryPage_Close_Btn = (gcnew System::Windows::Forms::Button());
			this->ModifyEntryPage_Name_Lbl = (gcnew System::Windows::Forms::Label());
			this->ModifyEntryPage_UserName_Lbl = (gcnew System::Windows::Forms::Label());
			this->ModifyEntryPage_Password_Lbl = (gcnew System::Windows::Forms::Label());
			this->ModifyEntryPage_Notes_Lbl = (gcnew System::Windows::Forms::Label());
			this->ModifyEntryPage_Name_Txt = (gcnew System::Windows::Forms::TextBox());
			this->ModifyEntryPage_UserName_Txt = (gcnew System::Windows::Forms::TextBox());
			this->ModifyEntryPage_Password_Txt = (gcnew System::Windows::Forms::TextBox());
			this->ModifyEntryPage_Notes_Txt = (gcnew System::Windows::Forms::TextBox());
			this->ModifyEntryPage_Save_Btn = (gcnew System::Windows::Forms::Button());
			this->ModifyEntryPage_Minimize_Btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ModifyEntryPage_Close_Btn
			// 
			this->ModifyEntryPage_Close_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ModifyEntryPage_Close_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ModifyEntryPage_Close_Btn.BackgroundImage")));
			this->ModifyEntryPage_Close_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ModifyEntryPage_Close_Btn->FlatAppearance->BorderSize = 0;
			this->ModifyEntryPage_Close_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ModifyEntryPage_Close_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Close_Btn->Location = System::Drawing::Point(687, 1);
			this->ModifyEntryPage_Close_Btn->Name = L"ModifyEntryPage_Close_Btn";
			this->ModifyEntryPage_Close_Btn->Size = System::Drawing::Size(32, 32);
			this->ModifyEntryPage_Close_Btn->TabIndex = 9;
			this->ModifyEntryPage_Close_Btn->UseVisualStyleBackColor = false;
			this->ModifyEntryPage_Close_Btn->Click += gcnew System::EventHandler(this, &ModifyEntryPage::ModifyEntryPage_Close_Btn_Click);
			// 
			// ModifyEntryPage_Name_Lbl
			// 
			this->ModifyEntryPage_Name_Lbl->AutoSize = true;
			this->ModifyEntryPage_Name_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_Name_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Name_Lbl->Location = System::Drawing::Point(82, 48);
			this->ModifyEntryPage_Name_Lbl->Name = L"ModifyEntryPage_Name_Lbl";
			this->ModifyEntryPage_Name_Lbl->Size = System::Drawing::Size(70, 25);
			this->ModifyEntryPage_Name_Lbl->TabIndex = 6;
			this->ModifyEntryPage_Name_Lbl->Text = L"Name:";
			// 
			// ModifyEntryPage_UserName_Lbl
			// 
			this->ModifyEntryPage_UserName_Lbl->AutoSize = true;
			this->ModifyEntryPage_UserName_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_UserName_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_UserName_Lbl->Location = System::Drawing::Point(36, 89);
			this->ModifyEntryPage_UserName_Lbl->Name = L"ModifyEntryPage_UserName_Lbl";
			this->ModifyEntryPage_UserName_Lbl->Size = System::Drawing::Size(116, 25);
			this->ModifyEntryPage_UserName_Lbl->TabIndex = 7;
			this->ModifyEntryPage_UserName_Lbl->Text = L"User Name:";
			// 
			// ModifyEntryPage_Password_Lbl
			// 
			this->ModifyEntryPage_Password_Lbl->AutoSize = true;
			this->ModifyEntryPage_Password_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_Password_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Password_Lbl->Location = System::Drawing::Point(48, 130);
			this->ModifyEntryPage_Password_Lbl->Name = L"ModifyEntryPage_Password_Lbl";
			this->ModifyEntryPage_Password_Lbl->Size = System::Drawing::Size(104, 25);
			this->ModifyEntryPage_Password_Lbl->TabIndex = 8;
			this->ModifyEntryPage_Password_Lbl->Text = L"Password:";
			// 
			// ModifyEntryPage_Notes_Lbl
			// 
			this->ModifyEntryPage_Notes_Lbl->AutoSize = true;
			this->ModifyEntryPage_Notes_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_Notes_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Notes_Lbl->Location = System::Drawing::Point(82, 170);
			this->ModifyEntryPage_Notes_Lbl->Name = L"ModifyEntryPage_Notes_Lbl";
			this->ModifyEntryPage_Notes_Lbl->Size = System::Drawing::Size(69, 25);
			this->ModifyEntryPage_Notes_Lbl->TabIndex = 9;
			this->ModifyEntryPage_Notes_Lbl->Text = L"Notes:";
			// 
			// ModifyEntryPage_Name_Txt
			// 
			this->ModifyEntryPage_Name_Txt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ModifyEntryPage_Name_Txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ModifyEntryPage_Name_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_Name_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Name_Txt->Location = System::Drawing::Point(158, 45);
			this->ModifyEntryPage_Name_Txt->Multiline = true;
			this->ModifyEntryPage_Name_Txt->Name = L"ModifyEntryPage_Name_Txt";
			this->ModifyEntryPage_Name_Txt->Size = System::Drawing::Size(400, 35);
			this->ModifyEntryPage_Name_Txt->TabIndex = 0;
			this->ModifyEntryPage_Name_Txt->WordWrap = false;
			this->ModifyEntryPage_Name_Txt->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ModifyEntryPage::ModifyEntryPage_Name_Txt_KeyDown);
			// 
			// ModifyEntryPage_UserName_Txt
			// 
			this->ModifyEntryPage_UserName_Txt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ModifyEntryPage_UserName_Txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ModifyEntryPage_UserName_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_UserName_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_UserName_Txt->Location = System::Drawing::Point(158, 86);
			this->ModifyEntryPage_UserName_Txt->Multiline = true;
			this->ModifyEntryPage_UserName_Txt->Name = L"ModifyEntryPage_UserName_Txt";
			this->ModifyEntryPage_UserName_Txt->Size = System::Drawing::Size(400, 35);
			this->ModifyEntryPage_UserName_Txt->TabIndex = 1;
			this->ModifyEntryPage_UserName_Txt->WordWrap = false;
			this->ModifyEntryPage_UserName_Txt->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ModifyEntryPage::ModifyEntryPage_UserName_Txt_KeyDown);
			// 
			// ModifyEntryPage_Password_Txt
			// 
			this->ModifyEntryPage_Password_Txt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ModifyEntryPage_Password_Txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ModifyEntryPage_Password_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_Password_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Password_Txt->Location = System::Drawing::Point(158, 127);
			this->ModifyEntryPage_Password_Txt->Multiline = true;
			this->ModifyEntryPage_Password_Txt->Name = L"ModifyEntryPage_Password_Txt";
			this->ModifyEntryPage_Password_Txt->Size = System::Drawing::Size(400, 35);
			this->ModifyEntryPage_Password_Txt->TabIndex = 2;
			this->ModifyEntryPage_Password_Txt->WordWrap = false;
			this->ModifyEntryPage_Password_Txt->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ModifyEntryPage::ModifyEntryPage_Password_Txt_KeyDown);
			// 
			// ModifyEntryPage_Notes_Txt
			// 
			this->ModifyEntryPage_Notes_Txt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ModifyEntryPage_Notes_Txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ModifyEntryPage_Notes_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_Notes_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Notes_Txt->Location = System::Drawing::Point(158, 169);
			this->ModifyEntryPage_Notes_Txt->Multiline = true;
			this->ModifyEntryPage_Notes_Txt->Name = L"ModifyEntryPage_Notes_Txt";
			this->ModifyEntryPage_Notes_Txt->Size = System::Drawing::Size(400, 100);
			this->ModifyEntryPage_Notes_Txt->TabIndex = 3;
			// 
			// ModifyEntryPage_Save_Btn
			// 
			this->ModifyEntryPage_Save_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ModifyEntryPage_Save_Btn->FlatAppearance->BorderSize = 0;
			this->ModifyEntryPage_Save_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ModifyEntryPage_Save_Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyEntryPage_Save_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Save_Btn->Location = System::Drawing::Point(587, 228);
			this->ModifyEntryPage_Save_Btn->Name = L"ModifyEntryPage_Save_Btn";
			this->ModifyEntryPage_Save_Btn->Size = System::Drawing::Size(100, 40);
			this->ModifyEntryPage_Save_Btn->TabIndex = 4;
			this->ModifyEntryPage_Save_Btn->Text = L"Save";
			this->ModifyEntryPage_Save_Btn->UseVisualStyleBackColor = false;
			this->ModifyEntryPage_Save_Btn->Click += gcnew System::EventHandler(this, &ModifyEntryPage::ModifyEntryPage_Save_Btn_Click);
			// 
			// ModifyEntryPage_Minimize_Btn
			// 
			this->ModifyEntryPage_Minimize_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->ModifyEntryPage_Minimize_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ModifyEntryPage_Minimize_Btn.BackgroundImage")));
			this->ModifyEntryPage_Minimize_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ModifyEntryPage_Minimize_Btn->FlatAppearance->BorderSize = 0;
			this->ModifyEntryPage_Minimize_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ModifyEntryPage_Minimize_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ModifyEntryPage_Minimize_Btn->Location = System::Drawing::Point(655, 1);
			this->ModifyEntryPage_Minimize_Btn->Name = L"ModifyEntryPage_Minimize_Btn";
			this->ModifyEntryPage_Minimize_Btn->Size = System::Drawing::Size(32, 32);
			this->ModifyEntryPage_Minimize_Btn->TabIndex = 9;
			this->ModifyEntryPage_Minimize_Btn->UseVisualStyleBackColor = false;
			this->ModifyEntryPage_Minimize_Btn->Click += gcnew System::EventHandler(this, &ModifyEntryPage::ModifyEntryPage_Minimize_Btn_Click);
			// 
			// ModifyEntryPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->ClientSize = System::Drawing::Size(720, 300);
			this->Controls->Add(this->ModifyEntryPage_Save_Btn);
			this->Controls->Add(this->ModifyEntryPage_Notes_Txt);
			this->Controls->Add(this->ModifyEntryPage_Password_Txt);
			this->Controls->Add(this->ModifyEntryPage_UserName_Txt);
			this->Controls->Add(this->ModifyEntryPage_Name_Txt);
			this->Controls->Add(this->ModifyEntryPage_Notes_Lbl);
			this->Controls->Add(this->ModifyEntryPage_Password_Lbl);
			this->Controls->Add(this->ModifyEntryPage_UserName_Lbl);
			this->Controls->Add(this->ModifyEntryPage_Name_Lbl);
			this->Controls->Add(this->ModifyEntryPage_Minimize_Btn);
			this->Controls->Add(this->ModifyEntryPage_Close_Btn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ModifyEntryPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"ModifyEntryPage";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &ModifyEntryPage::ModifyEntryPage_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ModifyEntryPage::ModifyEntryPage_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ModifyEntryPage::ModifyEntryPage_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ModifyEntryPage::ModifyEntryPage_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

		public: property System::String^ nameGet {
			String^ get() {
				return this->ModifyEntryPage_Name_Txt->Text;
			}
		}
		public: property bool checkNewAdded {
			bool get() {
				return this->newAdded;
			}
		}

		private: System::Void ModifyEntryPage_Load(System::Object^ sender, System::EventArgs^ e) {
			this->dragging = false;
		}
		private: System::Void ModifyEntryPage_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		}
		private: System::Void ModifyEntryPage_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (this->dragging) {
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
			}
		}
		private: System::Void ModifyEntryPage_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->dragging = false;
		}
			   // close button
		private: System::Void ModifyEntryPage_Close_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
		}
			   // minimize button
		private: System::Void ModifyEntryPage_Minimize_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->WindowState = FormWindowState::Minimized;
		}
			   // save the entry
		private: System::Void ModifyEntryPage_Save_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			bool success;
			String^ name = this->ModifyEntryPage_Name_Txt->Text;
			// check if the user entered values for the fields name, userName, and password
			if (!name->Length) {
				InvalidInputAlert^ iia = gcnew InvalidInputAlert("Name field cannot be empty!");
				iia->ShowDialog(this);
				return;
			}
			String^ userName = this->ModifyEntryPage_UserName_Txt->Text;
			if (!userName->Length) {
				InvalidInputAlert^ iia = gcnew InvalidInputAlert("UserName filed cannot be empty!");
				iia->ShowDialog(this);
				return;
			}
			String^ password = this->ModifyEntryPage_Password_Txt->Text;
			if (!password->Length) {
				InvalidInputAlert^ iia = gcnew InvalidInputAlert("Password field cannot be empty!");
				iia->ShowDialog(this);
				return;
			}
			String^ notes = this->ModifyEntryPage_Notes_Txt->Text;
			// if the name text box is set to read only than modify entry
			if (this->ModifyEntryPage_Name_Txt->ReadOnly) {
				success = Globals::data->modifyEntry(name, encryptString(name), encryptString(userName), encryptString(password), encryptString(notes));
				if (!success) {
					InvalidInputAlert^ iia = gcnew InvalidInputAlert("No Entry with this name exists");
					iia->ShowDialog(this);
					return;
				}
			}
			else {
				success = Globals::data->addEntry(name, encryptString(name), encryptString(userName), encryptString(password), encryptString(notes));
				if (!success) {
					InvalidInputAlert^ iia = gcnew InvalidInputAlert("An entry with the same name already exists");
					iia->ShowDialog(this);
					return;
				}
			}
			// new entry was added update value so main page can get add the list box
			writeEntryToFile(name);
			// set boolan flag to indicate an entry was added
			this->newAdded = true;
			this->Close();
		}
		private: System::Void ModifyEntryPage_Name_Txt_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter) {
				ModifyEntryPage_Save_Btn_Click(nullptr, nullptr);
			}
		}
		private: System::Void ModifyEntryPage_UserName_Txt_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter) {
				ModifyEntryPage_Save_Btn_Click(nullptr, nullptr);
			}
		}
		private: System::Void ModifyEntryPage_Password_Txt_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter) {
				ModifyEntryPage_Save_Btn_Click(nullptr, nullptr);
			}
		}	
	};
}
