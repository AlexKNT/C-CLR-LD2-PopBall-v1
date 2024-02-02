#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;
int main()
{
	Application::EnableVisualStyles();
	CCLRLD2PopBallv1::MainForm form;
	ball = new Ball(form.frame->Width, form.frame->Height);
	Application::Run(% form);
	delete ball;
}