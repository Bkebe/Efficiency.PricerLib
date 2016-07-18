
#include "Mapping.h"


Mapping::Mapping(){}
Mapping::~Mapping(){
	//delete map;
}

Mapping::Mapping(string path, EfficiencyProduct::EfficiencyTypeProduct typePrduct) // constructeur
{
	
	//map = new std::vector<std::tuple<std::string, std::string, std::string>>();

	// doc_param : XML de param�trage 
	TiXmlDocument* doc_param;

	this->typeProd = EfficiencyProduct::typeProductToString(typePrduct);

	string dir = "..//product file//";
	dir += path ;

	//path += ".xml";
	doc_param = new TiXmlDocument(dir.c_str());


	if (doc_param->LoadFile())
	{
		TiXmlHandle XMLparam(doc_param); // ouverture du fichier XML de param�trage

		TiXmlElement* param;
		TiXmlElement* param_child;
		string ComponentNameMust;
		string ComponentNameQuantLib;
		string ComponentTypeMust;
		//====================================================
		//             recherche par boucle
		//=====================================================

		// param point� sur les enfants de la balise "mapping"
		param = XMLparam.FirstChild("BODY").Child("product", 0).Child("mapping", 0).FirstChildElement().ToElement();
		while (param) // boucle sur les elements du XML param�tr�
		{
			ComponentTypeMust = param->Attribute("type");
			param_child = param->FirstChild()->ToElement();
			while (param_child) // boucle sur les children de param
			{
				ComponentNameQuantLib = param_child->Attribute("name");
				ComponentNameMust = param_child->GetText();

				map.push_back(std::make_tuple(ComponentNameMust, ComponentTypeMust, ComponentNameQuantLib));

				param_child = param_child->NextSiblingElement();
			}

			param = param->NextSiblingElement(); // iteration sur param : les elements
			// du XML de
			// param�trage
		}
	} // fin de if (doc_param.LoadFile())
	else
	{
		char* err = "Erreur du chargement du fichier XML de mapping";
		throw err;
	}
}



// ========================================================
// =================M�thodes===============================
// ========================================================

//Input : le nom de la composante sur QuantLib
//Output : le nom de la composante sur le MustML

std::string Mapping::search_mapping(std::string valSearch)
{
	for (std::size_t i = 0; i < this->map.size(); i++)
	{
		if (std::get<2>(this->map[i]) == valSearch)
			return std::get<0>(this->map[i]);  //retourne le nom de la composante sur le MustML
	}//fin de la boucle de recherche
	return "";
}


//Input : nom de la variable QuantLib  , et nom de la variable Must qu'on veut modifier
//le fichier XML de param�trage
void Mapping::updateXML(char* valQuantLib, char* newVal)
{
	TiXmlDocument* doc;


	this->typeProd = typeProd;

	string path = "..//product file//";
	path += typeProd;
	path += ".xml";
	doc = new TiXmlDocument(path.c_str());


	TiXmlHandle hdl(doc);
	if (doc->LoadFile())
	{
		bool trouve = false;
		TiXmlElement *elem = hdl.FirstChild("BODY").FirstChild("product").FirstChild("mapping").FirstChild("comp").ToElement();

		while (elem && !trouve)
		{
			//rehcherche du nom de la variable QuantLib
			if (string(elem->FirstChild("property")->ToElement()->Attribute("name")) == valQuantLib)
			{
				trouve = true;
				break;
			}
			elem = elem->NextSiblingElement(); // iteration, passage a l'element suivant
		}

		if (trouve)
		{

			elem->FirstChild("property")->ToElement()->Clear();
			elem->FirstChild("property")->ToElement()->LinkEndChild(new TiXmlText(newVal)); // modifier la variable Must


			string path = "..//product file//";
			path += typeProd;
			path += ".xml";
			doc->SaveFile(path.c_str());  // enregistrement de la modification

		}

	}
	else
	{
		char* err = "Erreur du chargement du fichier Catalogue.xml";
		throw err;
	}

}


////Afficher la table de mapping du produit choisi dans le combobox dans la dataGrid
//void Mapping::affiche_data(System::Windows::Forms::ComboBox^  comboBox1, System::Windows::Forms::DataGridView^  dataG)
//{
//	String^ typeProd_string = gcnew String(this->typeProd.c_str());
//
//	if (comboBox1->SelectedItem->ToString() == typeProd_string)
//		//if (comboBox1->SelectedItem->ToString() == mapping->typeProd)
//	{
//		//mapping : objet de la classe mapping
//
//		dataG->Rows->Clear();
//		dataG->Rows->Add(this->map.size()); // la taille de la dataGridView  = taille de la matrice map //pour faire le test
//
//		//===============================================================
//		//				AFFICHAGE DANS LA TABLE DataGridView
//		//===============================================================
//
//		for (std::size_t i = 0; i < this->map.size(); i++)
//		{
//			dataG->Rows[i]->Cells[0]->Value = gcnew String(std::get<0>(this->map[i]).c_str());
//			dataG->Rows[i]->Cells[1]->Value = gcnew String(std::get<1>(this->map[i]).c_str());
//			dataG->Rows[i]->Cells[2]->Value = gcnew String(std::get<2>(this->map[i]).c_str());
//
//		}//fin de la boucle d'affichage
//		//==================  fin de l'affichage ==================
//
//	}
//
//	else
//	{
//		dataG->Rows->Clear();
//	}
//
//}
//
//
////remplir une matrice par les �l�ments de la nouvelle table de mapping
//vector < vector < string>> Mapping::tableVector(System::Windows::Forms::DataGridView^  dataG)
//{
//	vector<string> ligne;
//	vector<vector<string>> table;
//	char* colonne0;
//	char* colonne2;
//	for (int indice = 0; indice < dataG->Rows->Count - 1; indice++)
//	{
//		ligne.clear();
//
//		// 1ere colonne de la dataGrid
//		colonne0 = (char*)Marshal::StringToHGlobalAnsi(dataG->Rows[indice]->Cells[0]->Value->ToString()).ToPointer();
//		string c0(colonne0);
//
//		// 3eme colonne de la dataGrid
//		colonne2 = (char*)Marshal::StringToHGlobalAnsi(dataG->Rows[indice]->Cells[2]->Value->ToString()).ToPointer();
//		string c2(colonne2);
//
//		string c1;
//
//		// 2eme colonne de la dataGrid
//		// affectation de chaque objet QuantLib � un type Must
//		if (c2 == "FixedLegQuantLib" || c2 == "FloatingLegQuantLib")
//		{
//			c1 = "COMPONENT_CASHFLOW";
//		}
//
//		if (c2 == "IndexQuantLib")
//		{
//			c1 = "COMPONENT_INDEX";
//		}
//
//
//		if (c2 == "NominalQuantLib")
//		{
//			c1 = "COMPONENT_PRINCIPAL";
//		}
//
//		if (c2 == "startDateQuantLib" || c2 == "endDateQuantLib")
//		{
//			c1 = "FULLDATE";
//		}
//
//		if (c2 == "FixedRateQuantLib")
//		{
//			c1 = "RATE";
//		}
//
//
//		// affectation des donn�es au vecteur ligne
//		ligne.push_back(c0);
//		ligne.push_back(c1);
//		ligne.push_back(c2);
//
//		//ajout du vecteur ligne au vecteur table
//		table.push_back(ligne);
//
//	}
//	return table;
//}


//creat_Table : pour cr�er une nouvelle table de mapping
//enregistrer les donn�es dans un nouveau xml
void Mapping::creat_Table(string nameProd, vector<vector<string>> vecTable)
{
	//cr�ation du fichier
	TiXmlDocument doc;
	//l'en-t�te du fichier
	TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "utf-8", "");
	doc.LinkEndChild(decl);

	//la 1ere balise BODY
	TiXmlElement * root = new TiXmlElement("BODY");
	doc.LinkEndChild(root);

	//balise produit
	TiXmlElement* element2 = new TiXmlElement("product");
	element2->SetAttribute("name", nameProd.c_str());
	root->LinkEndChild(element2);

	//balise mapping
	TiXmlElement* element3 = new TiXmlElement("mapping");
	root->FirstChildElement()->LinkEndChild(element3);


	//boucle sur les �l�ments de vecTable
	//pour cr�er des balises avec le m�me param�trage
	for (size_t indice = 0; indice < vecTable.size(); indice++)
	{
		TiXmlElement* comp = new TiXmlElement("comp");
		comp->SetAttribute("type", vecTable[indice][1].c_str());
		root->FirstChildElement()->FirstChildElement()->LinkEndChild(comp);

		TiXmlElement* property = new TiXmlElement("preperty");
		property->SetAttribute("name", vecTable[indice][2].c_str());
		root->FirstChildElement()->FirstChildElement()->LastChild()->LinkEndChild(property);

		TiXmlText* texti = new TiXmlText(vecTable[indice][0].c_str());
		property->LinkEndChild(texti);
	}

	// sauvegarde du fichier dans le dossier : "product file"

	nameProd = "..//product file//" + nameProd + ".xml";
	doc.SaveFile(nameProd.c_str()); // ajouter extension

}



// updateCatalogue : pour ajouter le type et et le chemin du xml

void Mapping::updateCatalogue(char* typeProd)
{
	TiXmlDocument doc("..//product file//Catalogue.xml");
	TiXmlHandle hdl(&doc);
	if (doc.LoadFile())
	{
		TiXmlElement *elem = hdl.FirstChild("BODY").FirstChild("typeList").ToElement();
		if (elem)
		{
			//balise produit
			TiXmlElement* element2 = new TiXmlElement("prod");

			element2->SetAttribute("type", typeProd);
			elem->LinkEndChild(element2);
			string path = string(typeProd) + ".xml";
			TiXmlText* texti = new TiXmlText(path.c_str());
			element2->LinkEndChild(texti);
			doc.SaveFile("..//product file//Catalogue.xml");  // enregistrement de la modification
		}
	}
	else
	{
		char* err = "Erreur du chargement du fichier Catalogue.xml";
		throw err;
	}
}


