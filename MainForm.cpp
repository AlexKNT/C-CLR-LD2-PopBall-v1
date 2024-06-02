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

void CCLRLD2PopBallv1::MainForm::startGame()
{
	// Create and place initial game objects
	manager->add(new House(frame->Width, frame->Height, 200, 200));
}

void CCLRLD2PopBallv1::MainForm::endGame(int reason) {
	//
}