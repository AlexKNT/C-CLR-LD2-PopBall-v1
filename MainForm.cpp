#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include "MainForm.h"
#include "Manager.h"
using namespace System;
using namespace System::Windows::Forms;
int main()
{
	Application::EnableVisualStyles();
	CCLRLD2PopBallv1::MainForm form;
	manager = new Manager();
	Application::Run(% form);
	delete manager;
}