#pragma once
#include <sstream>
#include <string>
#include <iostream>
#include "TablesForm.h"
#include "DetailsForms.h"
#include "GrecsForm.h"
#include "tinyxml.h"
#include "EfficiencyLibProducts.h"
#include <boost/foreach.hpp>
//#include "CurveData.hpp"


namespace EfficiencyPricerLibApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			 tableauNPV	= new vector<tuple<string, string, double, double, double> >;
			 tableauGrecs = new vector<tuple<string, string, double, double, double, double> >;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox2;
	protected:
	private: System::Windows::Forms::TextBox^  DeltaTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  NPVDetailButton;
	private: System::Windows::Forms::Button^  RiskFactorButton;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  NPVTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  VegaTextBox;
	private: System::Windows::Forms::ToolStripMenuItem^  marketDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tableDeMappingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  MenuMapping;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::TextBox^  LoadTextBox;
	private: System::Windows::Forms::Button^  Loadbutton;
	private: System::Windows::Forms::Button^  Pricebutton;
	private: System::Windows::Forms::Label^  label1;

	private:
		vector<tuple<string, string, double, double, double> >* tableauNPV;
		vector<tuple<string, string, double, double, double, double> >* tableauGrecs;
		EfficiencyLibProducts* EffLibProducts;
		TablesForm ^ formTable;

	private: System::Windows::Forms::TextBox^  GammaTextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  DateTextBox;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  Closebutton;
	private: System::Windows::Forms::Panel^  closePanel;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::TextBox^  npvDeviseTextBox;
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
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->npvDeviseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GammaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DeltaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->NPVDetailButton = (gcnew System::Windows::Forms::Button());
			this->RiskFactorButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NPVTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->VegaTextBox = (gcnew System::Windows::Forms::TextBox());
			this->marketDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableDeMappingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuMapping = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->LoadTextBox = (gcnew System::Windows::Forms::TextBox());
			this->Loadbutton = (gcnew System::Windows::Forms::Button());
			this->Pricebutton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->DateTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->Closebutton = (gcnew System::Windows::Forms::Button());
			this->closePanel = (gcnew System::Windows::Forms::Panel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->closePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->BackColor = System::Drawing::Color::SteelBlue;
			this->groupBox2->Controls->Add(this->npvDeviseTextBox);
			this->groupBox2->Controls->Add(this->GammaTextBox);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->DeltaTextBox);
			this->groupBox2->Controls->Add(this->groupBox1);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->NPVTextBox);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->VegaTextBox);
			this->groupBox2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->groupBox2->Location = System::Drawing::Point(3, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(651, 184);
			this->groupBox2->TabIndex = 57;
			this->groupBox2->TabStop = false;
			// 
			// npvDeviseTextBox
			// 
			this->npvDeviseTextBox->Enabled = false;
			this->npvDeviseTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->npvDeviseTextBox->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->npvDeviseTextBox->Location = System::Drawing::Point(213, 16);
			this->npvDeviseTextBox->Name = L"npvDeviseTextBox";
			this->npvDeviseTextBox->Size = System::Drawing::Size(51, 26);
			this->npvDeviseTextBox->TabIndex = 53;
			// 
			// GammaTextBox
			// 
			this->GammaTextBox->Enabled = false;
			this->GammaTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GammaTextBox->Location = System::Drawing::Point(86, 99);
			this->GammaTextBox->Name = L"GammaTextBox";
			this->GammaTextBox->Size = System::Drawing::Size(121, 26);
			this->GammaTextBox->TabIndex = 52;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(6, 101);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(62, 18);
			this->label6->TabIndex = 51;
			this->label6->Text = L"Gamma :";
			// 
			// DeltaTextBox
			// 
			this->DeltaTextBox->Enabled = false;
			this->DeltaTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeltaTextBox->Location = System::Drawing::Point(86, 58);
			this->DeltaTextBox->Name = L"DeltaTextBox";
			this->DeltaTextBox->Size = System::Drawing::Size(121, 26);
			this->DeltaTextBox->TabIndex = 42;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->NPVDetailButton);
			this->groupBox1->Controls->Add(this->RiskFactorButton);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox1->Location = System::Drawing::Point(454, 81);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(191, 97);
			this->groupBox1->TabIndex = 50;
			this->groupBox1->TabStop = false;
			// 
			// NPVDetailButton
			// 
			this->NPVDetailButton->BackColor = System::Drawing::Color::WhiteSmoke;
			this->NPVDetailButton->Cursor = System::Windows::Forms::Cursors::Default;
			this->NPVDetailButton->Enabled = false;
			this->NPVDetailButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->NPVDetailButton->Location = System::Drawing::Point(6, 14);
			this->NPVDetailButton->Name = L"NPVDetailButton";
			this->NPVDetailButton->Size = System::Drawing::Size(174, 37);
			this->NPVDetailButton->TabIndex = 40;
			this->NPVDetailButton->Text = L"Details des NPV";
			this->NPVDetailButton->UseVisualStyleBackColor = true;
			this->NPVDetailButton->Click += gcnew System::EventHandler(this, &MyForm::NPVDetailButton_Click);
			// 
			// RiskFactorButton
			// 
			this->RiskFactorButton->BackColor = System::Drawing::Color::WhiteSmoke;
			this->RiskFactorButton->Enabled = false;
			this->RiskFactorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RiskFactorButton->Location = System::Drawing::Point(6, 57);
			this->RiskFactorButton->Name = L"RiskFactorButton";
			this->RiskFactorButton->Size = System::Drawing::Size(174, 34);
			this->RiskFactorButton->TabIndex = 43;
			this->RiskFactorButton->Text = L"Facteurs de risque";
			this->RiskFactorButton->UseVisualStyleBackColor = true;
			this->RiskFactorButton->Click += gcnew System::EventHandler(this, &MyForm::RiskFactorButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(6, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 18);
			this->label2->TabIndex = 37;
			this->label2->Text = L"NPV :";
			// 
			// NPVTextBox
			// 
			this->NPVTextBox->Enabled = false;
			this->NPVTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NPVTextBox->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->NPVTextBox->Location = System::Drawing::Point(86, 16);
			this->NPVTextBox->Name = L"NPVTextBox";
			this->NPVTextBox->Size = System::Drawing::Size(121, 26);
			this->NPVTextBox->TabIndex = 38;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(6, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 18);
			this->label3->TabIndex = 41;
			this->label3->Text = L"Delta :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(6, 151);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 18);
			this->label4->TabIndex = 44;
			this->label4->Text = L"Vega :";
			// 
			// VegaTextBox
			// 
			this->VegaTextBox->Enabled = false;
			this->VegaTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VegaTextBox->Location = System::Drawing::Point(86, 146);
			this->VegaTextBox->Name = L"VegaTextBox";
			this->VegaTextBox->Size = System::Drawing::Size(121, 26);
			this->VegaTextBox->TabIndex = 45;
			// 
			// marketDataToolStripMenuItem
			// 
			this->marketDataToolStripMenuItem->Name = L"marketDataToolStripMenuItem";
			this->marketDataToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->marketDataToolStripMenuItem->Text = L"Market data";
			this->marketDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::marketDataToolStripMenuItem_Click);
			// 
			// tableDeMappingToolStripMenuItem
			// 
			this->tableDeMappingToolStripMenuItem->Name = L"tableDeMappingToolStripMenuItem";
			this->tableDeMappingToolStripMenuItem->Size = System::Drawing::Size(169, 22);
			this->tableDeMappingToolStripMenuItem->Text = L"Table de mapping";
			this->tableDeMappingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tableDeMappingToolStripMenuItem_Click);
			// 
			// MenuMapping
			// 
			this->MenuMapping->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->MenuMapping->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tableDeMappingToolStripMenuItem,
					this->marketDataToolStripMenuItem
			});
			this->MenuMapping->Name = L"MenuMapping";
			this->MenuMapping->Size = System::Drawing::Size(67, 20);
			this->MenuMapping->Text = L"Mapping";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->MenuMapping });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(657, 24);
			this->menuStrip1->TabIndex = 56;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// LoadTextBox
			// 
			this->LoadTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->LoadTextBox->Enabled = false;
			this->LoadTextBox->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->LoadTextBox->Location = System::Drawing::Point(69, 14);
			this->LoadTextBox->Name = L"LoadTextBox";
			this->LoadTextBox->Size = System::Drawing::Size(428, 20);
			this->LoadTextBox->TabIndex = 54;
			this->LoadTextBox->Text = L"Charger un produit";
			this->LoadTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::LoadTextBox_TextChanged);
			// 
			// Loadbutton
			// 
			this->Loadbutton->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Loadbutton->Location = System::Drawing::Point(496, 13);
			this->Loadbutton->Name = L"Loadbutton";
			this->Loadbutton->Size = System::Drawing::Size(59, 22);
			this->Loadbutton->TabIndex = 53;
			this->Loadbutton->Text = L"Charger";
			this->Loadbutton->UseVisualStyleBackColor = true;
			this->Loadbutton->Click += gcnew System::EventHandler(this, &MyForm::Loadbutton_Click);
			// 
			// Pricebutton
			// 
			this->Pricebutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Pricebutton->AutoEllipsis = true;
			this->Pricebutton->BackColor = System::Drawing::Color::Green;
			this->Pricebutton->Enabled = false;
			this->Pricebutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pricebutton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Pricebutton->Location = System::Drawing::Point(274, 132);
			this->Pricebutton->MaximumSize = System::Drawing::Size(119, 42);
			this->Pricebutton->MinimumSize = System::Drawing::Size(119, 42);
			this->Pricebutton->Name = L"Pricebutton";
			this->Pricebutton->Size = System::Drawing::Size(119, 42);
			this->Pricebutton->TabIndex = 52;
			this->Pricebutton->Text = L"Price";
			this->Pricebutton->UseVisualStyleBackColor = false;
			this->Pricebutton->Click += gcnew System::EventHandler(this, &MyForm::Pricebutton_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(-2, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 55;
			this->label1->Text = L"Chemin :";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 56);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 58;
			this->label5->Text = L"Date :";
			// 
			// DateTextBox
			// 
			this->DateTextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->DateTextBox->Location = System::Drawing::Point(69, 53);
			this->DateTextBox->Name = L"DateTextBox";
			this->DateTextBox->Size = System::Drawing::Size(123, 20);
			this->DateTextBox->TabIndex = 59;
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->BackColor = System::Drawing::Color::SteelBlue;
			this->groupBox3->Controls->Add(this->Loadbutton);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->DateTextBox);
			this->groupBox3->Controls->Add(this->LoadTextBox);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox3->Location = System::Drawing::Point(3, 3);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(649, 100);
			this->groupBox3->TabIndex = 60;
			this->groupBox3->TabStop = false;
			// 
			// Closebutton
			// 
			this->Closebutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Closebutton->Location = System::Drawing::Point(551, 6);
			this->Closebutton->Name = L"Closebutton";
			this->Closebutton->Size = System::Drawing::Size(103, 35);
			this->Closebutton->TabIndex = 61;
			this->Closebutton->Text = L"Fermer";
			this->Closebutton->UseVisualStyleBackColor = true;
			this->Closebutton->Click += gcnew System::EventHandler(this, &MyForm::Closebutton_Click);
			// 
			// closePanel
			// 
			this->closePanel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->closePanel->Controls->Add(this->Closebutton);
			this->closePanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->closePanel->Location = System::Drawing::Point(0, 462);
			this->closePanel->Name = L"closePanel";
			this->closePanel->Size = System::Drawing::Size(657, 44);
			this->closePanel->TabIndex = 62;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->groupBox3);
			this->splitContainer1->Panel1->Controls->Add(this->Pricebutton);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->groupBox2);
			this->splitContainer1->Size = System::Drawing::Size(657, 438);
			this->splitContainer1->SplitterDistance = 198;
			this->splitContainer1->TabIndex = 63;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(657, 506);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->closePanel);
			this->Controls->Add(this->menuStrip1);
			this->MinimumSize = System::Drawing::Size(673, 545);
			this->Name = L"MyForm";
			this->Text = L" ";
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->closePanel->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	/*private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		int notional;
		notional = System::Convert::ToDouble(textBox3->Text);

		double strike;
		strike = System::Convert::ToDouble(textBox1->Text);

		double vol;
		vol = System::Convert::ToDouble(textBox2->Text);

		CapFloor::Type InstrumentType;
		EfficiencyPricerLibProducts::EfficiencyCapFloor  CapFloorProduct;
		//InstrumentType = CapFloorProduct.stringToType(comboBoxType->SelectedItem->ToString());
		boost::shared_ptr<CapFloor> InstrumentEfficiency = CapFloorProduct.TestCapFloor(InstrumentType ,notional, strike, vol);

		 this->textBox4->Text= InstrumentEfficiency->NPV().ToString();
	}
	*/

		
	private: System::Void Loadbutton_Click(System::Object^  sender, System::EventArgs^  e) {

		// Effacer les résultats du pricing précédent
		LoadTextBox->Text = "";
		NPVTextBox->Text = "";
		DeltaTextBox->Text = "";
		GammaTextBox->Text = "";
		VegaTextBox->Text = "";


		// ouverture de la fenêtre pour choisir le fichier
		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->ShowDialog();
		String ^ FilePath = openFileDialog1->FileName;
		LoadTextBox->Text = FilePath;

		// si un chemin est indiqué
		if (LoadTextBox->Text != "") {
			char* pathC = (char*)Marshal::StringToHGlobalAnsi(LoadTextBox->Text).ToPointer();
			string ret(pathC); // convert char* to string
			string extension = pathC;
			extension.erase(0, extension.length() - 3);

			try {
				if (boost::iequals(extension, "xml")) {
					TiXmlDocument doc(pathC);

					if (!doc.LoadFile()) {
						char* err = "Erreur du chargement du fichier XML";
						throw err;
					}
					else // si le fichier est chargé
					{
						// création de la fenêtre de la table de mapping
						DateTextBox->Enabled = true;
						DeltaTextBox->Enabled = true;
						NPVTextBox->Enabled = true;
						GammaTextBox->Enabled = true;
						VegaTextBox->Enabled = true;
						Pricebutton->Enabled = true;
						NPVDetailButton->Enabled = true;
						RiskFactorButton->Enabled = true;
						TiXmlHandle hdl(&doc);
						try {
							/*Construction of all products*/
							EffLibProducts = new EfficiencyLibProducts(hdl);
							EffLibProducts->setModelsProductsTypes();

							EffLibProducts->makeProducts();
						}
						catch (string e) {

							MessageBox::Show(gcnew String(e.c_str()), "Erreur",
								MessageBoxButtons::OK, MessageBoxIcon::Error); //kb
						}
					}
				}
				else {
					char* err = "Erreur du chargement du fichier XML";
					throw err;
				}
			}

			catch (char* const& err) {
				MessageBox::Show(gcnew String(err), "Erreur du chargement",
					MessageBoxButtons::OK, MessageBoxIcon::Error);

				NPVTextBox->Enabled = false;
				Pricebutton->Enabled = false;
				NPVDetailButton->Enabled = false;
				RiskFactorButton->Enabled = false;
				DateTextBox->Enabled = false;
				GammaTextBox->Enabled = false;
				VegaTextBox->Enabled = false;
			}
		}
	}

	
private: System::Void NPVDetailButton_Click(System::Object^  sender, System::EventArgs^  e) {
	DetailsForms ^ detailsForm = gcnew DetailsForms();
	detailsForm->tableauNPV = tableauNPV;
	// afficher l'écran "Détails"
	detailsForm->Show();
}
private: System::Void Pricebutton_Click(System::Object^  sender, System::EventArgs^  e) {
		//Effaçage des résultats : tableaux des npv et des grecs
		tableauNPV->clear();
		tableauGrecs->clear();

		/*pricer tous les trade qui sont dans "EffLibProducts" */
		if (EffLibProducts->AllProducts[0] != NULL) {
			double npv;
			double npvSomme = 0;
			string type;
			string id;

			for (std::size_t numProd = 0; numProd < EffLibProducts->AllProducts.size(); numProd++)
			{
				npv = (EffLibProducts->AllProducts[numProd])->price();
				DeuxChiff(&npv);

				type = EffLibProducts->portefeuille.AllTrades->operator[](numProd)->typeProduct;

				id = EffLibProducts->portefeuille.AllTrades->operator[](numProd)->tradeID;

				tableauNPV->push_back(std::make_tuple(id, type, npv, 0, 0));
				tableauGrecs->push_back(std::make_tuple(id, type, 0, 0, 0, 0));
				npvSomme += npv;
			}
			NPVTextBox->Text = npvSomme.ToString();
		}
}
private: System::Void RiskFactorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	GrecsForm ^ grecsFrom = gcnew GrecsForm();
	grecsFrom->tableauGrecs = tableauGrecs;
	grecsFrom->Show();
}
private: System::Void tableDeMappingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//// affichade l'écran de la table de mapping
	formTable = gcnew TablesForm();
	formTable->Show();
}
private: System::Void marketDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

}

void DeuxChiff(double *my_double) /* test attend l'adresse d'un entier... */
{
	if (*my_double >= 0)
		*my_double = (floor(*my_double * 100)) / 100;
	else
		*my_double = (floor(*my_double * 100 + 1)) / 100;
	return;
}
private: System::Void Closebutton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

private: System::Void LoadTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
