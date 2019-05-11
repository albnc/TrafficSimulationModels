// corsimTS0.cpp : main project file.

#include "stdafx.h"
#include "MyForm.h"


using namespace System;
using namespace corsimTS0;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    // Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew MyForm());
    return 0;
}
