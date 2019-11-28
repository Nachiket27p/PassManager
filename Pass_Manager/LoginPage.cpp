#pragma once
#include "LoginPage.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	PassManager::LoginPage lip;
	Application::Run(% lip);
}



