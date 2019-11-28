#pragma once

namespace PassManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DeleteConfirmation
	/// </summary>
	public ref class DeleteConfirmation : public System::Windows::Forms::Form
	{
		public:
			DeleteConfirmation(void)
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
			~DeleteConfirmation()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::Button^ DeleteConfirmation_Yes_Btn;
		protected:
		private: System::Windows::Forms::Button^ DeleteConfirmation_No_Btn;
		private: System::Windows::Forms::Label^ DeleteConfirmation_Lbl;

		// used to confirm if user wants to delete the entry
		private: Boolean del = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteConfirmation::typeid));
			this->DeleteConfirmation_Yes_Btn = (gcnew System::Windows::Forms::Button());
			this->DeleteConfirmation_No_Btn = (gcnew System::Windows::Forms::Button());
			this->DeleteConfirmation_Lbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// DeleteConfirmation_Yes_Btn
			// 
			this->DeleteConfirmation_Yes_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->DeleteConfirmation_Yes_Btn->FlatAppearance->BorderSize = 0;
			this->DeleteConfirmation_Yes_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DeleteConfirmation_Yes_Btn->Location = System::Drawing::Point(120, 56);
			this->DeleteConfirmation_Yes_Btn->Name = L"DeleteConfirmation_Yes_Btn";
			this->DeleteConfirmation_Yes_Btn->Size = System::Drawing::Size(100, 32);
			this->DeleteConfirmation_Yes_Btn->TabIndex = 0;
			this->DeleteConfirmation_Yes_Btn->Text = L"YES";
			this->DeleteConfirmation_Yes_Btn->UseVisualStyleBackColor = false;
			this->DeleteConfirmation_Yes_Btn->Click += gcnew System::EventHandler(this, &DeleteConfirmation::DeleteConfirmation_Yes_Btn_Click);
			// 
			// DeleteConfirmation_No_Btn
			// 
			this->DeleteConfirmation_No_Btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->DeleteConfirmation_No_Btn->FlatAppearance->BorderSize = 0;
			this->DeleteConfirmation_No_Btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DeleteConfirmation_No_Btn->Location = System::Drawing::Point(320, 56);
			this->DeleteConfirmation_No_Btn->Name = L"DeleteConfirmation_No_Btn";
			this->DeleteConfirmation_No_Btn->Size = System::Drawing::Size(100, 32);
			this->DeleteConfirmation_No_Btn->TabIndex = 1;
			this->DeleteConfirmation_No_Btn->Text = L"NO";
			this->DeleteConfirmation_No_Btn->UseVisualStyleBackColor = false;
			this->DeleteConfirmation_No_Btn->Click += gcnew System::EventHandler(this, &DeleteConfirmation::DeleteConfirmation_No_Btn_Click);
			// 
			// DeleteConfirmation_Lbl
			// 
			this->DeleteConfirmation_Lbl->AutoSize = true;
			this->DeleteConfirmation_Lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DeleteConfirmation_Lbl->Location = System::Drawing::Point(90, 15);
			this->DeleteConfirmation_Lbl->Name = L"DeleteConfirmation_Lbl";
			this->DeleteConfirmation_Lbl->Size = System::Drawing::Size(379, 25);
			this->DeleteConfirmation_Lbl->TabIndex = 4;
			this->DeleteConfirmation_Lbl->Text = L"Are you sure you want to delete this entry\?";
			// 
			// DeleteConfirmation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->ClientSize = System::Drawing::Size(540, 100);
			this->Controls->Add(this->DeleteConfirmation_Lbl);
			this->Controls->Add(this->DeleteConfirmation_No_Btn);
			this->Controls->Add(this->DeleteConfirmation_Yes_Btn);
			this->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"DeleteConfirmation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"DeleteConfirmation";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		public: property System::Boolean delConf {
			Boolean get() {
				return del;
			}
		}

		private: System::Void DeleteConfirmation_Yes_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			del = true;
			this->Close();
		}	
		
		private: System::Void DeleteConfirmation_No_Btn_Click(System::Object^ sender, System::EventArgs^ e) {
			del = false;
			this->Close();
		}
	};
}
