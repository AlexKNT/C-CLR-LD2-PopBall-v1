#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include "MainForm.h"
#include "Manager.h"
#include <cstdlib>
#include <ctime>
using namespace System;
using namespace System::Windows::Forms;
int main()
{
	Application::EnableVisualStyles();
	CCLRLD2PopBallv1::MainForm form;
	srand(static_cast<unsigned int>(time(nullptr)));
	manager = new Manager();
	Application::Run(% form);
	delete manager;
}