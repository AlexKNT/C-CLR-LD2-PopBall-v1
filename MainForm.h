#pragma once
#include "Ball.h"
#include <cstdlib>
#include <stdio.h>
#include "Rectangle.h"
#include "Triangle.h"
#include "Star.h"
#include "Manager.h"


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
	private: System::Windows::Forms::Timer^ moveTimer;
	private: System::Windows::Forms::Timer^ drawTimer;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ starBtn;

	private: System::Windows::Forms::RadioButton^ triangleBtn;

	private: System::Windows::Forms::RadioButton^ rectangleBtn;
	private: System::Windows::Forms::RadioButton^ ballBtn;
	public:
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->frame = (gcnew System::Windows::Forms::PictureBox());
			this->moveTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->drawTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->starBtn = (gcnew System::Windows::Forms::RadioButton());
			this->triangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->rectangleBtn = (gcnew System::Windows::Forms::RadioButton());
			this->ballBtn = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// frame
			// 
			this->frame->Location = System::Drawing::Point(12, 12);
			this->frame->Name = L"frame";
			this->frame->Size = System::Drawing::Size(600, 400);
			this->frame->TabIndex = 0;
			this->frame->TabStop = false;
			this->frame->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::frame_Paint);
			this->frame->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::frame_MouseDown);
			// 
			// moveTimer
			// 
			this->moveTimer->Enabled = true;
			this->moveTimer->Interval = 10;
			this->moveTimer->Tick += gcnew System::EventHandler(this, &MainForm::moveTimer_Tick);
			// 
			// drawTimer
			// 
			this->drawTimer->Enabled = true;
			this->drawTimer->Interval = 10;
			this->drawTimer->Tick += gcnew System::EventHandler(this, &MainForm::drawTimer_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->starBtn);
			this->groupBox1->Controls->Add(this->triangleBtn);
			this->groupBox1->Controls->Add(this->rectangleBtn);
			this->groupBox1->Controls->Add(this->ballBtn);
			this->groupBox1->Location = System::Drawing::Point(631, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(100, 143);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Shape";
			// 
			// starBtn
			// 
			this->starBtn->AutoSize = true;
			this->starBtn->Location = System::Drawing::Point(17, 107);
			this->starBtn->Name = L"starBtn";
			this->starBtn->Size = System::Drawing::Size(42, 17);
			this->starBtn->TabIndex = 3;
			this->starBtn->TabStop = true;
			this->starBtn->Text = L"star";
			this->starBtn->UseVisualStyleBackColor = true;
			// 
			// triangleBtn
			// 
			this->triangleBtn->AutoSize = true;
			this->triangleBtn->Location = System::Drawing::Point(17, 84);
			this->triangleBtn->Name = L"triangleBtn";
			this->triangleBtn->Size = System::Drawing::Size(63, 17);
			this->triangleBtn->TabIndex = 2;
			this->triangleBtn->TabStop = true;
			this->triangleBtn->Text = L"Triangle";
			this->triangleBtn->UseVisualStyleBackColor = true;
			// 
			// rectangleBtn
			// 
			this->rectangleBtn->AutoSize = true;
			this->rectangleBtn->Location = System::Drawing::Point(17, 61);
			this->rectangleBtn->Name = L"rectangleBtn";
			this->rectangleBtn->Size = System::Drawing::Size(74, 17);
			this->rectangleBtn->TabIndex = 1;
			this->rectangleBtn->TabStop = true;
			this->rectangleBtn->Text = L"Rectangle";
			this->rectangleBtn->UseVisualStyleBackColor = true;
			// 
			// ballBtn
			// 
			this->ballBtn->AutoSize = true;
			this->ballBtn->Location = System::Drawing::Point(17, 38);
			this->ballBtn->Name = L"ballBtn";
			this->ballBtn->Size = System::Drawing::Size(42, 17);
			this->ballBtn->TabIndex = 0;
			this->ballBtn->TabStop = true;
			this->ballBtn->Text = L"Ball";
			this->ballBtn->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(746, 422);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->frame);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pop Balls V4";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->frame))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frame_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        Graphics^ grp = e->Graphics;
		grp->FillRectangle(% SolidBrush(Color::White), 0, 0, frame->Width, frame->Height);
		manager->drawFrame(grp);
	}
	private: System::Void frame_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (ballBtn->Checked) {
			manager->add(new Ball(frame->Width, frame->Height, e->X, e->Y));
		} else if (rectangleBtn->Checked) {
            manager->add(new Rectangle_(frame->Width, frame->Height, e->X, e->Y));
        } else if (triangleBtn->Checked) {
            manager->add(new Triangle(frame->Width, frame->Height, e->X, e->Y));
        } else if (starBtn->Checked) {
            manager->add(new Star(frame->Width, frame->Height, e->X, e->Y));
        }
		frame->Invalidate();
	}
	private: System::Void moveTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		manager->move();
	}
	private: System::Void drawTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		frame->Invalidate();
	}
};
}