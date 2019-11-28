#pragma once
#include "MessageDialogue.h"
#include "ModifyEntryPage.h"
#include "DeleteConfirmation.h"

namespace PassManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainPage
	/// </summary>
	public ref class MainPage : public System::Windows::Forms::Form
	{
		public:
			MainPage(void)
			{
				InitializeComponent();
				this->MainPage_Search_Txt->AutoSize = false;
				// load all entries into list box
				array<String^>^ n = Globals::data->getEntryNames();
				int siz = n->Length;
				for (int i = 0; i < siz; i++) {
					this->MainPage_ListBox->Items->Add(n[i]);
				}
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MainPage()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::TextBox^ MainPage_Search_Txt;
		private: System::Windows::Forms::Button^ MainPage_NewEntry_Btn;
		private: System::Windows::Forms::ListBox^ MainPage_ListBox;
		private: System::Windows::Forms::Button^ MainPage_DeleteEntry_Btn;
		private: System::Windows::Forms::Button^ MainPage_EditEntry_Btn;
		private: System::Windows::Forms::Button^ MainPage_Close_Btn;
		private: System::Windows::Forms::Button^ MainPage_Minimize_Btn;
		private: System::Windows::Forms::Label^ MainPage_UserName_Lbl;
		private: System::Windows::Forms::Label^ MainPage_Password_Lbl;
		private: System::Windows::Forms::Label^ MainPage_Notes_Lbl;
		private: System::Windows::Forms::Label^ MainPage_UserName_Value_Txt;
		private: System::Windows::Forms::Label^ MainPage_Password_Value_Txt;

		private: System::Windows::Forms::ToolTip^ ToolTip_ClickToCopy;
		private: System::Windows::Forms::ToolTip^ ToolTip_Buttons;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
		private: System::ComponentModel::IContainer^ components;

		// used to drag window around
		private: bool dragging;
		private: Point offset;
	private: System::Windows::Forms::TextBox^ MainPage_Notes_Txt;


		private: const int CS_DropShadow = 0x20000;

		protected: virtual property System::Windows::Forms::CreateParams^ CreateParams {
			System::Windows::Forms::CreateParams^ get() override
			{
				System::Windows::Forms::CreateParams^ cp = Form::CreateParams;
				cp->ClassStyle |= CS_DropShadow;
				return cp;
			}
		}
	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainPage::typeid));
			this->MainPage_Search_Txt = (gcnew System::Windows::Forms::TextBox());
			this->MainPage_NewEntry_Btn = (gcnew System::Windows::Forms::Button());
			this->MainPage_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->MainPage_DeleteEntry_Btn = (gcnew System::Windows::Forms::Button());
			this->MainPage_EditEntry_Btn = (gcnew System::Windows::Forms::Button());
			this->MainPage_Close_Btn = (gcnew System::Windows::Forms::Button());
			this->MainPage_Minimize_Btn = (gcnew System::Windows::Forms::Button());
			this->MainPage_UserName_Lbl = (gcnew System::Windows::Forms::Label());
			this->MainPage_Password_Lbl = (gcnew System::Windows::Forms::Label());
			this->MainPage_Notes_Lbl = (gcnew System::Windows::Forms::Label());
			this->MainPage_UserName_Value_Txt = (gcnew System::Windows::Forms::Label());
			this->MainPage_Password_Value_Txt = (gcnew System::Windows::Forms::Label());
			this->ToolTip_ClickToCopy = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->ToolTip_Buttons = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->MainPage_Notes_Txt = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// MainPage_Search_Txt
			// 
			this->MainPage_Search_Txt->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->MainPage_Search_Txt->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::FileSystem;
			this->MainPage_Search_Txt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->MainPage_Search_Txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->MainPage_Search_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MainPage_Search_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_Search_Txt->Location = System::Drawing::Point(319, 48);
			this->MainPage_Search_Txt->Name = L"MainPage_Search_Txt";
			this->MainPage_Search_Txt->Size = System::Drawing::Size(327, 23);
			this->MainPage_Search_Txt->TabIndex = 0;
			this->MainPage_Search_Txt->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainPage::MainPage_Search_Txt_KeyUp);
			// 
			// MainPage_NewEntry_Btn
			// 
			this->MainPage_NewEntry_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->MainPage_NewEntry_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MainPage_NewEntry_Btn.BackgroundImage")));
			this->MainPage_NewEntry_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->MainPage_NewEntry_Btn->FlatAppearance->BorderSize = 0;
			this->MainPage_NewEntry_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MainPage_NewEntry_Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MainPage_NewEntry_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_NewEntry_Btn->Location = System::Drawing::Point(40, 48);
			this->MainPage_NewEntry_Btn->Name = L"MainPage_NewEntry_Btn";
			this->MainPage_NewEntry_Btn->Size = System::Drawing::Size(36, 37);
			this->MainPage_NewEntry_Btn->TabIndex = 9;
			this->MainPage_NewEntry_Btn->TabStop = false;
			this->ToolTip_Buttons->SetToolTip(this->MainPage_NewEntry_Btn, L"Create new entry");
			this->MainPage_NewEntry_Btn->UseVisualStyleBackColor = false;
			this->MainPage_NewEntry_Btn->Click += gcnew System::EventHandler(this, &MainPage::MainPage_NewEntry_Btn_Click);
			// 
			// MainPage_ListBox
			// 
			this->MainPage_ListBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->MainPage_ListBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->MainPage_ListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainPage_ListBox->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_ListBox->FormattingEnabled = true;
			this->MainPage_ListBox->ItemHeight = 29;
			this->MainPage_ListBox->Location = System::Drawing::Point(40, 107);
			this->MainPage_ListBox->Name = L"MainPage_ListBox";
			this->MainPage_ListBox->Size = System::Drawing::Size(654, 580);
			this->MainPage_ListBox->TabIndex = 9;
			this->MainPage_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainPage::MainPage_ListBox_SelectedIndexChanged);
			this->MainPage_ListBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainPage::MainPage_ListBox_KeyDown);
			// 
			// MainPage_DeleteEntry_Btn
			// 
			this->MainPage_DeleteEntry_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->MainPage_DeleteEntry_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MainPage_DeleteEntry_Btn.BackgroundImage")));
			this->MainPage_DeleteEntry_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->MainPage_DeleteEntry_Btn->FlatAppearance->BorderSize = 0;
			this->MainPage_DeleteEntry_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MainPage_DeleteEntry_Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MainPage_DeleteEntry_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_DeleteEntry_Btn->Location = System::Drawing::Point(100, 48);
			this->MainPage_DeleteEntry_Btn->Name = L"MainPage_DeleteEntry_Btn";
			this->MainPage_DeleteEntry_Btn->Size = System::Drawing::Size(36, 37);
			this->MainPage_DeleteEntry_Btn->TabIndex = 9;
			this->MainPage_DeleteEntry_Btn->TabStop = false;
			this->ToolTip_Buttons->SetToolTip(this->MainPage_DeleteEntry_Btn, L"Delete selected entry");
			this->MainPage_DeleteEntry_Btn->UseVisualStyleBackColor = false;
			this->MainPage_DeleteEntry_Btn->Click += gcnew System::EventHandler(this, &MainPage::MainPage_DeleteEntry_Btn_Click);
			// 
			// MainPage_EditEntry_Btn
			// 
			this->MainPage_EditEntry_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->MainPage_EditEntry_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MainPage_EditEntry_Btn.BackgroundImage")));
			this->MainPage_EditEntry_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->MainPage_EditEntry_Btn->FlatAppearance->BorderSize = 0;
			this->MainPage_EditEntry_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MainPage_EditEntry_Btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MainPage_EditEntry_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_EditEntry_Btn->Location = System::Drawing::Point(160, 48);
			this->MainPage_EditEntry_Btn->Name = L"MainPage_EditEntry_Btn";
			this->MainPage_EditEntry_Btn->Size = System::Drawing::Size(36, 37);
			this->MainPage_EditEntry_Btn->TabIndex = 9;
			this->MainPage_EditEntry_Btn->TabStop = false;
			this->ToolTip_Buttons->SetToolTip(this->MainPage_EditEntry_Btn, L"Edit selected entry");
			this->MainPage_EditEntry_Btn->UseVisualStyleBackColor = false;
			this->MainPage_EditEntry_Btn->Click += gcnew System::EventHandler(this, &MainPage::MainPage_EditEntry_Btn_Click);
			// 
			// MainPage_Close_Btn
			// 
			this->MainPage_Close_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->MainPage_Close_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MainPage_Close_Btn.BackgroundImage")));
			this->MainPage_Close_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->MainPage_Close_Btn->FlatAppearance->BorderSize = 0;
			this->MainPage_Close_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MainPage_Close_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_Close_Btn->Location = System::Drawing::Point(707, 1);
			this->MainPage_Close_Btn->Name = L"MainPage_Close_Btn";
			this->MainPage_Close_Btn->Size = System::Drawing::Size(32, 32);
			this->MainPage_Close_Btn->TabIndex = 3;
			this->MainPage_Close_Btn->UseVisualStyleBackColor = false;
			this->MainPage_Close_Btn->Click += gcnew System::EventHandler(this, &MainPage::MainPage_Close_Btn_Click);
			// 
			// MainPage_Minimize_Btn
			// 
			this->MainPage_Minimize_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->MainPage_Minimize_Btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MainPage_Minimize_Btn.BackgroundImage")));
			this->MainPage_Minimize_Btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->MainPage_Minimize_Btn->FlatAppearance->BorderSize = 0;
			this->MainPage_Minimize_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MainPage_Minimize_Btn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_Minimize_Btn->Location = System::Drawing::Point(675, 1);
			this->MainPage_Minimize_Btn->Name = L"MainPage_Minimize_Btn";
			this->MainPage_Minimize_Btn->Size = System::Drawing::Size(32, 32);
			this->MainPage_Minimize_Btn->TabIndex = 2;
			this->MainPage_Minimize_Btn->UseVisualStyleBackColor = false;
			this->MainPage_Minimize_Btn->Click += gcnew System::EventHandler(this, &MainPage::MainPage_Minimize_Btn_Click);
			// 
			// MainPage_UserName_Lbl
			// 
			this->MainPage_UserName_Lbl->AutoSize = true;
			this->MainPage_UserName_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MainPage_UserName_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_UserName_Lbl->Location = System::Drawing::Point(96, 723);
			this->MainPage_UserName_Lbl->Name = L"MainPage_UserName_Lbl";
			this->MainPage_UserName_Lbl->Size = System::Drawing::Size(116, 25);
			this->MainPage_UserName_Lbl->TabIndex = 9;
			this->MainPage_UserName_Lbl->Text = L"User Name:";
			// 
			// MainPage_Password_Lbl
			// 
			this->MainPage_Password_Lbl->AutoSize = true;
			this->MainPage_Password_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MainPage_Password_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_Password_Lbl->Location = System::Drawing::Point(108, 764);
			this->MainPage_Password_Lbl->Name = L"MainPage_Password_Lbl";
			this->MainPage_Password_Lbl->Size = System::Drawing::Size(104, 25);
			this->MainPage_Password_Lbl->TabIndex = 9;
			this->MainPage_Password_Lbl->Text = L"Password:";
			// 
			// MainPage_Notes_Lbl
			// 
			this->MainPage_Notes_Lbl->AutoSize = true;
			this->MainPage_Notes_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainPage_Notes_Lbl->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_Notes_Lbl->Location = System::Drawing::Point(143, 804);
			this->MainPage_Notes_Lbl->Name = L"MainPage_Notes_Lbl";
			this->MainPage_Notes_Lbl->Size = System::Drawing::Size(69, 25);
			this->MainPage_Notes_Lbl->TabIndex = 9;
			this->MainPage_Notes_Lbl->Text = L"Notes:";
			// 
			// MainPage_UserName_Value_Txt
			// 
			this->MainPage_UserName_Value_Txt->AutoSize = true;
			this->MainPage_UserName_Value_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MainPage_UserName_Value_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_UserName_Value_Txt->Location = System::Drawing::Point(220, 721);
			this->MainPage_UserName_Value_Txt->MaximumSize = System::Drawing::Size(400, 32);
			this->MainPage_UserName_Value_Txt->MinimumSize = System::Drawing::Size(400, 32);
			this->MainPage_UserName_Value_Txt->Name = L"MainPage_UserName_Value_Txt";
			this->MainPage_UserName_Value_Txt->Size = System::Drawing::Size(400, 32);
			this->MainPage_UserName_Value_Txt->TabIndex = 9;
			this->ToolTip_ClickToCopy->SetToolTip(this->MainPage_UserName_Value_Txt, L"Click to copy text");
			this->MainPage_UserName_Value_Txt->Click += gcnew System::EventHandler(this, &MainPage::MainPage_UserName_Value_Txt_Click);
			// 
			// MainPage_Password_Value_Txt
			// 
			this->MainPage_Password_Value_Txt->AutoSize = true;
			this->MainPage_Password_Value_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MainPage_Password_Value_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_Password_Value_Txt->Location = System::Drawing::Point(220, 761);
			this->MainPage_Password_Value_Txt->MaximumSize = System::Drawing::Size(400, 32);
			this->MainPage_Password_Value_Txt->MinimumSize = System::Drawing::Size(400, 32);
			this->MainPage_Password_Value_Txt->Name = L"MainPage_Password_Value_Txt";
			this->MainPage_Password_Value_Txt->Size = System::Drawing::Size(400, 32);
			this->MainPage_Password_Value_Txt->TabIndex = 9;
			this->ToolTip_ClickToCopy->SetToolTip(this->MainPage_Password_Value_Txt, L"Click to copy text");
			this->MainPage_Password_Value_Txt->Click += gcnew System::EventHandler(this, &MainPage::MainPage_Password_Value_Txt_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->label1->Location = System::Drawing::Point(70, 695);
			this->label1->MaximumSize = System::Drawing::Size(600, 2);
			this->label1->MinimumSize = System::Drawing::Size(600, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(600, 2);
			this->label1->TabIndex = 10;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label2->Location = System::Drawing::Point(233, 54);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 25);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Search:";
			// 
			// MainPage_Notes_Txt
			// 
			this->MainPage_Notes_Txt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->MainPage_Notes_Txt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->MainPage_Notes_Txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainPage_Notes_Txt->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->MainPage_Notes_Txt->Location = System::Drawing::Point(223, 803);
			this->MainPage_Notes_Txt->Multiline = true;
			this->MainPage_Notes_Txt->Name = L"MainPage_Notes_Txt";
			this->MainPage_Notes_Txt->Size = System::Drawing::Size(400, 100);
			this->MainPage_Notes_Txt->TabIndex = 12;
			// 
			// MainPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(740, 930);
			this->Controls->Add(this->MainPage_Notes_Txt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MainPage_Password_Value_Txt);
			this->Controls->Add(this->MainPage_UserName_Value_Txt);
			this->Controls->Add(this->MainPage_Notes_Lbl);
			this->Controls->Add(this->MainPage_Password_Lbl);
			this->Controls->Add(this->MainPage_UserName_Lbl);
			this->Controls->Add(this->MainPage_Minimize_Btn);
			this->Controls->Add(this->MainPage_Close_Btn);
			this->Controls->Add(this->MainPage_EditEntry_Btn);
			this->Controls->Add(this->MainPage_DeleteEntry_Btn);
			this->Controls->Add(this->MainPage_ListBox);
			this->Controls->Add(this->MainPage_NewEntry_Btn);
			this->Controls->Add(this->MainPage_Search_Txt);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainPage";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainPage::MainPage_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainPage::MainPage_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainPage::MainPage_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	#pragma endregion
		private: System::Void MainPage_Load(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			//used to make sure the for doesnt drag when opened
			this->dragging = false;

		}
		private: System::Void MainPage_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		}

		private: System::Void MainPage_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (this->dragging) {
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
			}
		}
		private: System::Void MainPage_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			this->dragging = false;
		}

		// closes the form
		private: System::Void MainPage_Close_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			//this->Close();
			Application::Exit();
		}
		// minimizes the form
		private: System::Void MainPage_Minimize_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			this->WindowState = FormWindowState::Minimized;
		}
		// create a new entry
		private: System::Void MainPage_NewEntry_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			ModifyEntryPage^ mep = gcnew ModifyEntryPage();
			mep->ShowDialog(this);
			if (mep->checkNewAdded) {
				this->MainPage_ListBox->Items->Add(mep->nameGet);
			}
		}
		// delete selected entry
		private: System::Void MainPage_DeleteEntry_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			int idx = this->MainPage_ListBox->SelectedIndex;
			if (idx != -1) {
				DeleteConfirmation^ dc = gcnew DeleteConfirmation();
				dc->ShowDialog(this);
				if (dc->delConf) {
					String^ name = this->MainPage_ListBox->SelectedItem->ToString();
					this->MainPage_ListBox->Items->RemoveAt(idx);
					Globals::data->deleteEntry(name);
					writeAllDataToFile();
				}
			}
			else {
				MessageDialogue^ md = gcnew MessageDialogue("No entry is selected!");
				md->ShowDialog();
			}
		}
		// edit selecte entry
		private: System::Void MainPage_EditEntry_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			Object^ selObj = this->MainPage_ListBox->SelectedItem;
			if (selObj != nullptr) {
				Entry^ temp = Globals::data->getEntry(selObj->ToString());
				ModifyEntryPage^ mep = gcnew ModifyEntryPage(decryptString(temp->getName()), decryptString(temp->getUserName()),
																decryptString(temp->getPassword()), decryptString(temp->getNotes()));
				this->MainPage_ListBox->SelectedItem = nullptr;
				this->MainPage_Password_Value_Txt->Text = "";
				this->MainPage_UserName_Value_Txt->Text = "";
				this->MainPage_Notes_Txt->Text = "";
				mep->ShowDialog(this);
				writeAllDataToFile();
			}
			else {
				MessageDialogue^ md = gcnew MessageDialogue("No entry is selected!");
				md->ShowDialog();
			}
		}
		// update info based on element selected in list box
		private: System::Void MainPage_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			Object^ selObj = this->MainPage_ListBox->SelectedItem;
			if (selObj == nullptr) {
				return;
			}
			String^ name = selObj->ToString();
			Entry^ selected = Globals::data->getEntry(name);
			if (selected != nullptr) {
				this->MainPage_UserName_Value_Txt->Text = decryptString(selected->getUserName());
				this->MainPage_Password_Value_Txt->Text = decryptString(selected->getPassword());
				this->MainPage_Notes_Txt->Text = decryptString(selected->getNotes());
			}
			else {
				MessageDialogue^ md = gcnew MessageDialogue("The selected entry is curropted!");
				md->ShowDialog();
				return;
			}
		}
		// update search results
		private: System::Void MainPage_Search_Txt_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			String^ search = this->MainPage_Search_Txt->Text->ToLower();
			array<String^>^ nameList = Globals::data->getEntryNames();
			int siz = nameList->Length;
			this->MainPage_ListBox->Items->Clear();
			if (search == "") {
				for (int i = 0; i < siz; i++) {
					this->MainPage_ListBox->Items->Add(nameList[i]);
				}
			}
			else {
				for (int i = 0; i < siz; i++) {
					String^ temp = nameList[i];
					String^ tempL = temp->ToLower();
					if (tempL->Contains(search)) {
						this->MainPage_ListBox->Items->Add(temp);
					}
				}
			}
		}
		// copy password to clipboard
		private: System::Void MainPage_Password_Value_Txt_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ temp = this->MainPage_Password_Value_Txt->Text;
			if (temp != "") {
				Clipboard::SetText(temp);
			}
		}
		// copy username to clipboard
		private: System::Void MainPage_UserName_Value_Txt_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ temp = this->MainPage_UserName_Value_Txt->Text;
			if (temp != "") {
				Clipboard::SetText(temp);
			}
		}
		private: System::Void MainPage_ListBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Delete) {
				MainPage_DeleteEntry_Btn_Click(nullptr, nullptr);
			}
		}
	};
}
