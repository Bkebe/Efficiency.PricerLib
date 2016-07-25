#pragma once
#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <iostream>
//#include <boost/foreach.hpp>
//#include "GrecsForm.h"
//#include "tinyxml.h"
//#include "EfficiencyLibProducts.h"

namespace EfficiencyPricerLibApplication {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for TestForm
	/// </summary>
	public ref class DetailsForms : public System::Windows::Forms::Form
	{
	public:
		DetailsForms(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
		_tableauNPV = new vector<tuple<string, string, double, double, double> >;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DetailsForms()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
		vector<tuple<string, string, double, double, double> >* _tableauNPV;
	public:




	private: System::Windows::Forms::Button^  CloseButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::Panel^  cloePanel;
	private: System::Windows::Forms::Panel^  gridPanel;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->cloePanel = (gcnew System::Windows::Forms::Panel());
			this->gridPanel = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->cloePanel->SuspendLayout();
			this->gridPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->BackgroundColor = System::Drawing::Color::GhostWhite;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(555, 207);
			this->dataGridView1->TabIndex = 1;
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Trade ID";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column2->HeaderText = L"Trade type";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column3->HeaderText = L"NPV";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column4->HeaderText = L"NPV fixed leg";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column5->HeaderText = L"NPV floating leg";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// CloseButton
			// 
			this->CloseButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CloseButton->Location = System::Drawing::Point(457, 6);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(101, 32);
			this->CloseButton->TabIndex = 2;
			this->CloseButton->Text = L"Fermer";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &DetailsForms::CloseButton_Click);
			// 
			// cloePanel
			// 
			this->cloePanel->Controls->Add(this->CloseButton);
			this->cloePanel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->cloePanel->Location = System::Drawing::Point(0, 213);
			this->cloePanel->Name = L"cloePanel";
			this->cloePanel->Size = System::Drawing::Size(561, 55);
			this->cloePanel->TabIndex = 3;
			// 
			// gridPanel
			// 
			this->gridPanel->Controls->Add(this->dataGridView1);
			this->gridPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gridPanel->Location = System::Drawing::Point(0, 0);
			this->gridPanel->Name = L"gridPanel";
			this->gridPanel->Size = System::Drawing::Size(561, 213);
			this->gridPanel->TabIndex = 4;
			// 
			// DetailsForms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(561, 268);
			this->Controls->Add(this->gridPanel);
			this->Controls->Add(this->cloePanel);
			this->MinimumSize = System::Drawing::Size(577, 283);
			this->Name = L"DetailsForms";
			this->Text = L"Details des NPV";
			this->Load += gcnew System::EventHandler(this, &DetailsForms::DetailsForms_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->cloePanel->ResumeLayout(false);
			this->gridPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
			public: property vector<tuple<string, string, double, double, double> >* tableauNPV{
				vector<tuple<string, string, double, double, double> >* get() {
					return _tableauNPV;
				}
				void set(vector<tuple<string, string, double, double, double> >* tabNPV) {
					_tableauNPV = NULL;

					bool isNotNull = tabNPV == NULL ? false : true;

					if (isNotNull){
						_tableauNPV = tabNPV;
					}

					dataGridView1->Enabled = isNotNull;
					//CloseButton->Enabled = isNotNull;
				
				}
			}


	private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void DetailsForms_Load(System::Object^  sender, System::EventArgs^  e) {
	if (_tableauNPV != NULL && _tableauNPV->size() >0) {
		ShowDataGridNPV();
			}
}

			private:
				System::Void ShowDataGridNPV()
				{
					dataGridView1->Rows->Add(_tableauNPV->size());
					// Afficher les éléments du tableau des résultats dans le dataGrid.
					for (std::size_t indice = 0; indice < _tableauNPV->size(); indice++)
					{
						dataGridView1->Rows[indice]->Cells[0]->Value
							= gcnew String(std::get<0>(_tableauNPV[0][indice]).c_str());
						dataGridView1->Rows[indice]->Cells[1]->Value
							= gcnew String(std::get<1>(_tableauNPV[0][indice]).c_str());
						dataGridView1->Rows[indice]->Cells[2]->Value
							= std::get<2>(_tableauNPV[0][indice]).ToString();
						dataGridView1->Rows[indice]->Cells[3]->Value
							= std::get<3>(_tableauNPV[0][indice]).ToString();
						dataGridView1->Rows[indice]->Cells[4]->Value
							= std::get<4>(_tableauNPV[0][indice]).ToString();
					}
				}

};
}
