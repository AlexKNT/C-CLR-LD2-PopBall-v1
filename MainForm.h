#pragma once
#include "Ball.h"
#include <cstdlib>
#include <stdio.h>

namespace CCLRLD2PopBallv1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ frame;
	protected:

	protected:

	protected:

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
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(12, 12);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(601, 398);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->DoubleClick += gcnew System::EventHandler(this, &MainForm::frame_DoubleClick);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDown);
			this->frame->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseMove);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 422);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Balls V1: Single Ball";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        Graphics^ grp = e->Graphics;
        grp->FillRectangle(% SolidBrush(Color::White), 0, 0, frame->Width, frame->Height);
        ball->draw(grp);
		frame->Invalidate();
	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        ball->setPos(e->X, e->Y);
		frame->Invalidate();
	}
	private: System::Void frame_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
            ball->setPos(e->X, e->Y);
            frame->Invalidate();
        }
	}
	private: System::Void frame_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		int red = rand() % 256;
		int green = rand() % 254;
		int blue = rand() % 253;
		// Convert the RGB values to a single hex integer with the format 0x80RRGGBB and pass the value to SetColor
		ball->setColor(0x80000000 + red * 0x10000 + green * 0x100 + blue);
	}
	};
}
