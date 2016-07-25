#pragma once

#include <sstream>
#include <string>
#include <iostream>
#include "Catalogue.h"
#include "Mapping.h"
namespace EfficiencyPricerLibApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TablesForm
	/// </summary>
	public ref class TablesForm : public System::Windows::Forms::Form
	{
	public:
		TablesForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			catalogue = new Catalogue();
			catalogueIsChanged = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TablesForm()
		{
			if (components)
			{
				delete components;
			}
		}

		Catalogue* catalogue;
		Mapping* mapping;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  Creatbutton;
	public: System::Windows::Forms::ComboBox^  ProductTypecomboBox;
	private: System::Windows::Forms::Button^  SaveMappingbutton;
	public:
	private:
	protected:



	public:
		bool catalogueIsChanged;
	public:
	private:

	public:

	private: System::Windows::Forms::Button^  Cancelbutton;

	private: System::Windows::Forms::DataGridView^  dataG;



	private: System::Windows::Forms::Label^  label2;



	private: System::Windows::Forms::Button^  SaveCataloguebutton;


	private: System::Windows::Forms::TabPage^  tabPage1;
	public: System::Windows::Forms::DataGridView^  dataGridView1;
	private:

	public:
	private: System::Windows::Forms::TabControl^  tabControl1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;



	private: System::Windows::Forms::Button^  Closebutton;
	private: System::Windows::Forms::Button^  CancelTypeProdButton;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Panel^  panel3;



	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ProductColumn;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  TypeColumn;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  ActivateColumn;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  ModelColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  ObjectQuantLibColumn;







	private: System::Windows::Forms::TextBox^  ProductTypeTextBox;

			
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->dataG = (gcnew System::Windows::Forms::DataGridView());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ObjectQuantLibColumn = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->ProductTypecomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ProductTypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveMappingbutton = (gcnew System::Windows::Forms::Button());
			this->Creatbutton = (gcnew System::Windows::Forms::Button());
			this->SaveCataloguebutton = (gcnew System::Windows::Forms::Button());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ProductColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TypeColumn = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->ActivateColumn = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->ModelColumn = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->CancelTypeProdButton = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->Closebutton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataG))->BeginInit();
			this->panel2->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::GhostWhite;
			this->tabPage2->Controls->Add(this->splitContainer1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(615, 441);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Table de mapping";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->panel3);
			this->splitContainer1->Panel1->Controls->Add(this->panel2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->Cancelbutton);
			this->splitContainer1->Panel2->Controls->Add(this->SaveMappingbutton);
			this->splitContainer1->Panel2->Controls->Add(this->Creatbutton);
			this->splitContainer1->Size = System::Drawing::Size(609, 435);
			this->splitContainer1->SplitterDistance = 351;
			this->splitContainer1->TabIndex = 29;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->dataG);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 44);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(609, 307);
			this->panel3->TabIndex = 30;
			// 
			// dataG
			// 
			this->dataG->AllowUserToDeleteRows = false;
			this->dataG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataG->BackgroundColor = System::Drawing::Color::White;
			this->dataG->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataG->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataG->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column4, this->Column5,
					this->ObjectQuantLibColumn
			});
			this->dataG->GridColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataG->Location = System::Drawing::Point(5, 6);
			this->dataG->Name = L"dataG";
			this->dataG->Size = System::Drawing::Size(599, 298);
			this->dataG->TabIndex = 22;
			// 
			// Column4
			// 
			this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column4->HeaderText = L"Composante MUST";
			this->Column4->Name = L"Column4";
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column5
			// 
			this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column5->HeaderText = L"Type Must";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// ObjectQuantLibColumn
			// 
			this->ObjectQuantLibColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ObjectQuantLibColumn->HeaderText = L"Objet QuantLib";
			this->ObjectQuantLibColumn->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"FixedLegQuantLib", L"FloatingLegQuantLib",
					L"OptionQuantLib", L"IndexQuantLib", L"NominalQuantLib", L"startDateQuantLib", L"endDateQuantLib", L"startDateOption", L"endDateOption",
					L"FixedRateQuantLib", L"StrikeQuantLib", L"maturityOptionQuantLib", L"CapOrFloor"
			});
			this->ObjectQuantLibColumn->Name = L"ObjectQuantLibColumn";
			this->ObjectQuantLibColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->ProductTypecomboBox);
			this->panel2->Controls->Add(this->ProductTypeTextBox);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(609, 44);
			this->panel2->TabIndex = 29;
			// 
			// ProductTypecomboBox
			// 
			this->ProductTypecomboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->ProductTypecomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ProductTypecomboBox->FormattingEnabled = true;
			this->ProductTypecomboBox->Location = System::Drawing::Point(414, 5);
			this->ProductTypecomboBox->Name = L"ProductTypecomboBox";
			this->ProductTypecomboBox->Size = System::Drawing::Size(164, 21);
			this->ProductTypecomboBox->TabIndex = 20;
			this->ProductTypecomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &TablesForm::ProductTypecomboBox_SelectedIndexChanged);
			// 
			// ProductTypeTextBox
			// 
			this->ProductTypeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->ProductTypeTextBox->Location = System::Drawing::Point(414, 5);
			this->ProductTypeTextBox->Name = L"ProductTypeTextBox";
			this->ProductTypeTextBox->Size = System::Drawing::Size(164, 20);
			this->ProductTypeTextBox->TabIndex = 28;
			this->ProductTypeTextBox->Visible = false;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(303, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Type du produit";
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->Cancelbutton->Location = System::Drawing::Point(491, 2);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(115, 34);
			this->Cancelbutton->TabIndex = 25;
			this->Cancelbutton->Text = L"Annuler";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &TablesForm::Cancelbutton_Click);
			// 
			// SaveMappingbutton
			// 
			this->SaveMappingbutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SaveMappingbutton->Location = System::Drawing::Point(262, 3);
			this->SaveMappingbutton->Name = L"SaveMappingbutton";
			this->SaveMappingbutton->Size = System::Drawing::Size(122, 34);
			this->SaveMappingbutton->TabIndex = 24;
			this->SaveMappingbutton->Text = L"Enregistrer";
			this->SaveMappingbutton->UseVisualStyleBackColor = true;
			this->SaveMappingbutton->Click += gcnew System::EventHandler(this, &TablesForm::SaveMappingbutton_Click);
			// 
			// Creatbutton
			// 
			this->Creatbutton->Location = System::Drawing::Point(5, 3);
			this->Creatbutton->Name = L"Creatbutton";
			this->Creatbutton->Size = System::Drawing::Size(106, 34);
			this->Creatbutton->TabIndex = 26;
			this->Creatbutton->Text = L"Créer";
			this->Creatbutton->UseVisualStyleBackColor = true;
			this->Creatbutton->Click += gcnew System::EventHandler(this, &TablesForm::Creatbutton_Click);
			// 
			// SaveCataloguebutton
			// 
			this->SaveCataloguebutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->SaveCataloguebutton->Location = System::Drawing::Point(3, 5);
			this->SaveCataloguebutton->Name = L"SaveCataloguebutton";
			this->SaveCataloguebutton->Size = System::Drawing::Size(117, 37);
			this->SaveCataloguebutton->TabIndex = 1;
			this->SaveCataloguebutton->Text = L"Enregistrer";
			this->SaveCataloguebutton->UseVisualStyleBackColor = true;
			this->SaveCataloguebutton->Click += gcnew System::EventHandler(this, &TablesForm::SaveCataloguebutton_Click);
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::GhostWhite;
			this->tabPage1->Controls->Add(this->panel4);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(615, 441);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Types de produits";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->splitContainer2);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(3, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(609, 435);
			this->panel4->TabIndex = 4;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer2->Location = System::Drawing::Point(3, 18);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->dataGridView1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->CancelTypeProdButton);
			this->splitContainer2->Panel2->Controls->Add(this->SaveCataloguebutton);
			this->splitContainer2->Size = System::Drawing::Size(603, 377);
			this->splitContainer2->SplitterDistance = 328;
			this->splitContainer2->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->ProductColumn,
					this->TypeColumn, this->ActivateColumn, this->ModelColumn
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(603, 328);
			this->dataGridView1->TabIndex = 0;
			// 
			// ProductColumn
			// 
			this->ProductColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ProductColumn->HeaderText = L"Produit";
			this->ProductColumn->Name = L"ProductColumn";
			// 
			// TypeColumn
			// 
			this->TypeColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->TypeColumn->HeaderText = L"Type";
			this->TypeColumn->Name = L"TypeColumn";
			this->TypeColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->TypeColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// ActivateColumn
			// 
			this->ActivateColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ActivateColumn->HeaderText = L"Activé";
			this->ActivateColumn->Name = L"ActivateColumn";
			this->ActivateColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->ActivateColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// ModelColumn
			// 
			this->ModelColumn->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->ModelColumn->HeaderText = L"Modèle";
			this->ModelColumn->Name = L"ModelColumn";
			this->ModelColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->ModelColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// CancelTypeProdButton
			// 
			this->CancelTypeProdButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CancelTypeProdButton->Location = System::Drawing::Point(483, 4);
			this->CancelTypeProdButton->Name = L"CancelTypeProdButton";
			this->CancelTypeProdButton->Size = System::Drawing::Size(117, 37);
			this->CancelTypeProdButton->TabIndex = 2;
			this->CancelTypeProdButton->Text = L"Annuler";
			this->CancelTypeProdButton->UseVisualStyleBackColor = true;
			this->CancelTypeProdButton->Click += gcnew System::EventHandler(this, &TablesForm::CancelTypeProdButton_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(623, 467);
			this->tabControl1->TabIndex = 29;
			// 
			// Closebutton
			// 
			this->Closebutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Closebutton->Location = System::Drawing::Point(498, 4);
			this->Closebutton->Name = L"Closebutton";
			this->Closebutton->Size = System::Drawing::Size(115, 37);
			this->Closebutton->TabIndex = 30;
			this->Closebutton->Text = L"Fermer";
			this->Closebutton->UseVisualStyleBackColor = true;
			this->Closebutton->Click += gcnew System::EventHandler(this, &TablesForm::Closebutton_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->Closebutton);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 422);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(623, 45);
			this->panel1->TabIndex = 31;
			// 
			// TablesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(623, 467);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tabControl1);
			this->MinimumSize = System::Drawing::Size(639, 506);
			this->Name = L"TablesForm";
			this->Text = L"Table de mapping";
			this->Load += gcnew System::EventHandler(this, &TablesForm::TablesForm_Load);
			this->tabPage2->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataG))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		/*
		Fichier de la Form(fenêtre) de la table de mapping
		Cette form est appelèe via le menu de la première interface
		*/
#pragma endregion
	
private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	////////
	ObjectQuantLibColumn->ReadOnly = true;
	ProductTypecomboBox->Visible = true;
	ProductTypeTextBox->Visible = false;

	/////
	if (ProductTypecomboBox->SelectedIndex != -1)

	{
		char* typeProd_string = (char*)Marshal::StringToHGlobalAnsi(ProductTypecomboBox->SelectedItem->ToString()).ToPointer();
		EfficiencyProduct::EfficiencyTypeProduct typePrduct = EfficiencyProduct::stringToTypeProduct(typeProd_string);

		string path = "";

		for (size_t indice = 0; indice < catalogue->VecCatalogue.size(); indice++)
		{
			if (catalogue->VecCatalogue[indice][0] != "" && catalogue->VecCatalogue[indice][1] != "")
			{
				if (ProductTypecomboBox->SelectedItem->ToString() == gcnew String(catalogue->VecCatalogue[indice][1].c_str())){ // si c'est le même type de produit
					path = catalogue->VecCatalogue[indice][4];

					break;
				}
			}
		}
		if (path != ""){
			try
			{
				mapping = new Mapping(path, typePrduct);
				affiche_dataMapping();
			}
			catch (char* const& err)
			{
				MessageBox::Show(gcnew String(err), "Erreur du chargement",
					MessageBoxButtons::OK, MessageBoxIcon::Error);

			}
		}


	}
	else
	{
		dataG->Rows->Clear();
	}
}
		 //bouton enregistrer les modifications de la table de mapping
private: System::Void SaveMappingbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	// si l'utilisateur veut afficher la table de mapping
	if (ProductTypecomboBox->Visible == true)

	{
		saveMappingModifiedProduct();

	}
	// si on veut créer un nouveau produit
	if (ProductTypeTextBox->Visible == true)
	{
		saveMappingNewProduct();
	}

}
private: System::Void saveMappingModifiedProduct(){
	
		//si un des éléments de la comboBox est selectionné
		if (ProductTypecomboBox->SelectedIndex != -1)
		{
			char* typeProd_string = (char*)Marshal::StringToHGlobalAnsi(ProductTypecomboBox->SelectedItem->ToString()).ToPointer();

			EfficiencyProduct::EfficiencyTypeProduct typePrduct = EfficiencyProduct::stringToTypeProduct(typeProd_string);

			string path = "";
			for (size_t indice = 0; indice < catalogue->VecCatalogue.size(); indice++)
			{
				if (catalogue->VecCatalogue[indice][0] != "" && catalogue->VecCatalogue[indice][1] != "")
				{
					if (ProductTypecomboBox->SelectedItem->ToString() == gcnew String(catalogue->VecCatalogue[indice][1].c_str())){ // si c'est le même type de produit
						path = catalogue->VecCatalogue[indice][4];
						break;
					}
				}
			}
			if (path != ""){
				try
				{
					mapping = new Mapping(path, typePrduct);
					System::String ^ cell1;
					System::String ^ cell2;

					char* newCell1;
					char* newCell2;

					// mettre à jour le XML de paramètrage par les éléments de la datagrid
					for (int row = 0; row < dataG->RowCount - 1; row++)
					{

						cell1 = dataG->Rows[row]->Cells[0]->Value->ToString();
						cell2 = dataG->Rows[row]->Cells[2]->Value->ToString();
						newCell1 = (char*)Marshal::StringToHGlobalAnsi(cell1).ToPointer();
						newCell2 = (char*)Marshal::StringToHGlobalAnsi(cell2).ToPointer();
						if (strcmp(newCell1, "") != 0 && strcmp(newCell2, "") != 0)
						{
							mapping->updateXML(newCell2, newCell1);
						}
					}
				}
				catch (char* const& err)
				{
					MessageBox::Show(gcnew String(err), "Erreur du chargement",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

				}
			}
			
		}
		else // si la comboBox est vide
		{
			MessageBox::Show(
				"Veuillez choisir le type de votre produit",
				"Type du produit invalide", MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
		}
	}

private: System::Void saveMappingNewProduct(){
		// si l'utilisateur saisit un type de produit
		if (ProductTypeTextBox->Text != "")
		{
			char* prodName;
			bool isFull; // isFull = true : si la cellule est pleine
			Mapping* newMapping = new Mapping(); //constructeur sans argument
			vector<vector<string>> vectorMapping;// vecteur qui contient les elements de la dataGrid
			if (ProductTypeTextBox->Text != "" && dataG->Rows->Count>2)
			{

				//tester si le 1er élément de la datagrid existe
				if (dataG->Rows[0]->Cells[0]->Value != nullptr)  isFull = true;
				else isFull = false;

				//parcourir la dataGrid
				// tester si tous les elements de la datagrid ne sont pas vides 
				//si seulement un est vide alors isFull = false
				for (int indice = 0; indice < dataG->Rows->Count - 1; indice++)
				{
					if (dataG->Rows[indice]->Cells[0]->Value == nullptr || dataG->Rows[indice]->Cells[2]->Value == nullptr)
					{

						isFull = isFull && false;
					}
				}
				//si aucun element n'est vide
				if (isFull)
				{
					prodName = (char*)Marshal::StringToHGlobalAnsi(ProductTypeTextBox->Text).ToPointer();
					string prodNameS(prodName);

					// création de la table
					vectorMapping = CreatTableVector();
					newMapping->creat_Table(prodNameS, vectorMapping);

					//update du catalogue

					newMapping->updateCatalogue(prodName);
					// vérifier si le fichier xml de paramètrage est crée
					string pathFile = "..//product file//" + prodNameS + ".xml";
					TiXmlDocument doc_param(pathFile.c_str());

					if (doc_param.LoadFile())
					{
						//affichade d'un message : fichier enregistré
						MessageBox::Show(
							"Fichier XML de paramètrage de la nouvelle table de mapping est enregistré avec succès !",
							"Fichier enregistré", MessageBoxButtons::OK,
							MessageBoxIcon::None);

						TypeColumn->Items->AddRange(gcnew String(prodName));
						ProductTypecomboBox->Items->Add(gcnew String(prodName));
					}

				}

			}
		}

		else // si le textBox est vide
			MessageBox::Show(
			"Veuillez saisir le nom de votre produit",
			"Nom du produit invalide", MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
	}

 vector < vector < string>> CreatTableVector()
		 {
			 vector<string> ligne;
			 vector<vector<string>> table;
			 char* colonne0;
			 char* colonne2;
			 for (int indice = 0; indice < dataG->Rows->Count - 1; indice++)
			 {
				 ligne.clear();

				 // 1ere colonne de la dataGrid
				 colonne0 = (char*)Marshal::StringToHGlobalAnsi(dataG->Rows[indice]->Cells[0]->Value->ToString()).ToPointer();
				 string c0(colonne0);

				 // 3eme colonne de la dataGrid
				 colonne2 = (char*)Marshal::StringToHGlobalAnsi(dataG->Rows[indice]->Cells[2]->Value->ToString()).ToPointer();
				 string c2(colonne2);

				 string c1;

				 // 2eme colonne de la dataGrid
				 // affectation de chaque objet QuantLib à un type Must
				 if (c2 == "FixedLegQuantLib" || c2 == "FloatingLegQuantLib")
				 {
					 c1 = "COMPONENT_CASHFLOW";
				 }

				 if (c2 == "IndexQuantLib")
				 {
					 c1 = "COMPONENT_INDEX";
				 }


				 if (c2 == "NominalQuantLib")
				 {
					 c1 = "COMPONENT_PRINCIPAL";
				 }

				 if (c2 == "startDateQuantLib" || c2 == "endDateQuantLib")
				 {
					 c1 = "FULLDATE";
				 }

				 if (c2 == "FixedRateQuantLib")
				 {
					 c1 = "RATE";
				 }


				 // affectation des données au vecteur ligne
				 ligne.push_back(c0);
				 ligne.push_back(c1);
				 ligne.push_back(c2);

				 //ajout du vecteur ligne au vecteur table
				 table.push_back(ligne);

			 }
			 return table;
		 }

private: System::Void Creatbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	ObjectQuantLibColumn->ReadOnly = false;
	dataG->Rows->Clear();
	ProductTypecomboBox->Visible = false;
	ProductTypeTextBox->Visible = true;
	ProductTypeTextBox->Clear();
}

private: System::Void ProductTypecomboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (ProductTypecomboBox->SelectedIndex != -1)
	{



		char* typeProd_string = (char*)Marshal::StringToHGlobalAnsi(ProductTypecomboBox->SelectedItem->ToString()).ToPointer();
		EfficiencyProduct::EfficiencyTypeProduct typePrduct = EfficiencyProduct::stringToTypeProduct(typeProd_string);
		string path = "";

		for (size_t indice = 0; indice < catalogue->VecCatalogue.size(); indice++)
		{
			if (catalogue->VecCatalogue[indice][0] != "" && catalogue->VecCatalogue[indice][1] != "")
			{
				if (ProductTypecomboBox->SelectedItem->ToString() == gcnew String(catalogue->VecCatalogue[indice][1].c_str())){ // si c'est le même type de produit
					 path = catalogue->VecCatalogue[indice][4];

					break;
				}
			}
		}
		if (path != ""){
			try
			{
				mapping = new Mapping(path, typePrduct);
				affiche_dataMapping();
			}
			catch (char* const& err)
			{
				MessageBox::Show(gcnew String(err), "Erreur du chargement",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	}
}
void affiche_dataMapping(){

			 
			 String^ typeProd_string = gcnew String(mapping->typeProd.c_str());
			 
			 if (ProductTypecomboBox->SelectedItem->ToString() == typeProd_string)
			 	{
			 		//mapping : objet de la classe mapping
			 
			 		dataG->Rows->Clear();
					std::size_t taille = mapping->map.size();
					dataG->Rows->Add(taille); // la taille de la dataGridView  = taille de la matrice map //pour faire le test
			 
			 		//===============================================================
			 		//				AFFICHAGE DANS LA TABLE DataGridView
			 		//===============================================================
			 
					for (std::size_t i = 0; i <taille; i++)
			 		{
						dataG->Rows[i]->Cells[0]->Value = gcnew String(std::get<0>(mapping->map[i]).c_str());
						dataG->Rows[i]->Cells[1]->Value = gcnew String(std::get<1>(mapping->map[i]).c_str());
						dataG->Rows[i]->Cells[2]->Value = gcnew String(std::get<2>(mapping->map[i]).c_str());
					
						//ObjectQuantLibColumn
			 		}//fin de la boucle d'affichage
			 		//==================  fin de l'affichage ==================
			 
			 	}
			 
			 	else
			 	{
			 		dataG->Rows->Clear();
			 	}
			 
			 
		 }

//void fillTableMappingVector(){
//	vector<string> ligne;
//		vector<vector<string>> table;
//		char* colonne0;
//		char* colonne2;
//		for (int indice = 0; indice < dataG->Rows->Count - 1; indice++)
//		{
//			ligne.clear();
//	
//			// 1ere colonne de la dataGrid
//			colonne0 = (char*)Marshal::StringToHGlobalAnsi(dataG->Rows[indice]->Cells[0]->Value->ToString()).ToPointer();
//			string c0(colonne0);
//	
//			// 3eme colonne de la dataGrid
//			colonne2 = (char*)Marshal::StringToHGlobalAnsi(dataG->Rows[indice]->Cells[2]->Value->ToString()).ToPointer();
//			string c2(colonne2);
//	
//			string c1;
//	
//			// 2eme colonne de la dataGrid
//			// affectation de chaque objet QuantLib à un type Must
//			if (c2 == "FixedLegQuantLib" || c2 == "FloatingLegQuantLib")
//			{
//				c1 = "COMPONENT_CASHFLOW";
//			}
//	
//			if (c2 == "IndexQuantLib")
//			{
//				c1 = "COMPONENT_INDEX";
//			}
//	
//	
//			if (c2 == "NominalQuantLib")
//			{
//				c1 = "COMPONENT_PRINCIPAL";
//			}
//	
//			if (c2 == "startDateQuantLib" || c2 == "endDateQuantLib")
//			{
//				c1 = "FULLDATE";
//			}
//	
//			if (c2 == "FixedRateQuantLib")
//			{
//				c1 = "RATE";
//			}
//	
//	
//			// affectation des données au vecteur ligne
//			ligne.push_back(c0);
//			ligne.push_back(c1);
//			ligne.push_back(c2);
//	
//			//ajout du vecteur ligne au vecteur table
//			table.push_back(ligne);
//	
//		}
//		//return table;
//
//}
		 // chargement de la form

private: System::Void fillDataGridViewCatalogue(){
	try {
		for (size_t indice = 0; indice < catalogue->VecCatalogue.size(); indice++) {
			if (catalogue->VecCatalogue[indice][0] != "" && catalogue->VecCatalogue[indice][1] != "") {
				//remplir les colonnes de la dataGrid avec les elements du vecteur VecCatalogue de l'objet catalogue
				dataGridView1->Rows[indice]->Cells[0]->Value = gcnew String(catalogue->VecCatalogue[indice][0].c_str());
				dataGridView1->Rows[indice]->Cells[1]->Value = gcnew String(catalogue->VecCatalogue[indice][1].c_str());
				dataGridView1->Rows[indice]->Cells[2]->Value = gcnew String(catalogue->VecCatalogue[indice][2].c_str());
				dataGridView1->Rows[indice]->Cells[3]->Value = gcnew String(catalogue->VecCatalogue[indice][3].c_str());
			}
		}
	}
	catch (char* const& err) {
		MessageBox::Show(gcnew String(err), "Erreur du chargement",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}
private: System::Void TablesForm_Load(System::Object^  sender, System::EventArgs^  e) {
	//objet de la classe Catalogue
	if (catalogue->VecCatalogue.size() != 0)
	{
		//initier la taille de la datagridView
		dataGridView1->Rows->Add(catalogue->VecCatalogue.size());

		vector<string> elementsComboBox;
		//boucle sur les elements du vecteur qui contient les noms et les types de produits 
		// et les chemins  des XML de paramètrage

		for (size_t indice = 0; indice < catalogue->VecCatalogueModel.size(); indice++)
		{
			//remplir la comboBox de la colonnes 4 par les modeles
			ModelColumn->Items->AddRange(gcnew String(catalogue->VecCatalogueModel[indice].c_str()));

		}
		for (size_t indice = 0; indice < catalogue->VecCatalogueType.size(); indice++)
		{
			//remplir un autre vecteur avce les types de produits
			elementsComboBox.push_back(catalogue->VecCatalogueType[indice][0]);
		}

		//supprimer les doublons dans le vecteur elementsComboBox
		elementsComboBox = catalogue->SuppDoublons(elementsComboBox);

		for (size_t indice = 0; indice < elementsComboBox.size(); indice++)
		{
			//remplir les comboBox de la datagrid et la comboBox de la table de mapping
			ProductTypecomboBox->Items->Add(gcnew String(elementsComboBox[indice].c_str()));
			TypeColumn->Items->AddRange(gcnew String(elementsComboBox[indice].c_str()));

		}

		fillDataGridViewCatalogue();

	}

}
private: System::Void SaveCataloguebutton_Click(System::Object^  sender, System::EventArgs^  e) {
		//Catalogue* catalogue = new Catalogue();
	try {
		catalogue->deleteCatalogue();

		for (int indice = 0; indice < dataGridView1->Rows->Count - 1; indice++)
		{
		if (dataGridView1->Rows[indice]->Cells[0]->Value != nullptr
		&& dataGridView1->Rows[indice]->Cells[1]->Value != nullptr
		&& dataGridView1->Rows[indice]->Cells[3]->Value != nullptr)
		{
		char* name = (char*)Marshal::StringToHGlobalAnsi(dataGridView1->Rows[indice]->Cells[0]->Value->ToString()).ToPointer();
		char* type = (char*)Marshal::StringToHGlobalAnsi(dataGridView1->Rows[indice]->Cells[1]->Value->ToString()).ToPointer();
		char* activate;
		if (dataGridView1->Rows[indice]->Cells[2]->Value == nullptr)
		activate = "False";
		else
		activate = (char*)Marshal::StringToHGlobalAnsi(dataGridView1->Rows[indice]->Cells[2]->Value->ToString()).ToPointer();

		char* modele = (char*)Marshal::StringToHGlobalAnsi(dataGridView1->Rows[indice]->Cells[3]->Value->ToString()).ToPointer();

		if (!catalogue->isInCatalogue(string(type), string(name)))
		{
		if (!catalogue->doublonsActifs(string(name), string(activate), indice))
		{
		catalogue->updateCatalogue(type, name, activate, modele);
		catalogueIsChanged = true;
		}
		else
		{
		MessageBox::Show(
		"Un produit du même nom est déjà activé",
		"Produit existant", MessageBoxButtons::OK,
		MessageBoxIcon::Warning);

		dataGridView1->Rows[indice]->Cells[2]->Value = "False";
		}

		}
		else
		{
		MessageBox::Show(
		"Un produit du même type est enregistré sous le même nom",
		"Produit existant", MessageBoxButtons::OK,
		MessageBoxIcon::Warning);

		dataGridView1->Rows[indice]->Cells[0]->Value = nullptr;
		}
		}
		else
		{
		MessageBox::Show(
		"Veuillez entrer tous les champs !",
		"Données manquantes", MessageBoxButtons::OK,
		MessageBoxIcon::Warning);

		}
		}
	}
	catch (char* const& err) {
		MessageBox::Show(gcnew String(err), "Erreur du chargement",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	}
private: System::Void  Closebutton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

private: System::Void dataG_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ anError)
	{
		anError->ThrowException = false;


	}


private: System::Void CancelTypeProdButton_Click(System::Object^  sender, System::EventArgs^  e) {
	/* à compléter*/
	catalogueIsChanged = false;
}
};
}
