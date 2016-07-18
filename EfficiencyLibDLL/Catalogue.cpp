#include "Catalogue.h"

Catalogue::Catalogue() // constructeur
{
	// doc_param : XML de param�trage 
	TiXmlDocument doc_param("..//product file//Catalogue.xml");

	if (doc_param.LoadFile())
	{
		TiXmlHandle XMLparam(&doc_param); // ouverture du fichier XML de param�trage

		//====================================================
		//             recherche par boucle
		//=====================================================
		string nameProd;
		string typeProd;
		string pathXML;
		string activated;
		string modele;

		TiXmlElement* param = XMLparam.FirstChild("BODY").FirstChild("productList").Child("prod", 0).ToElement();


		/*	VecCatalogue = new vector<vector<string>>();
			VecCatalogueType = new vector<vector<string>>();
			VecCatalogueModel = new vector<string>();*/
		while (param) // boucle sur les elements du XML param�tr�
		{

			vector < string > prod;
			nameProd = param->Attribute("name");
			typeProd = param->Attribute("type");
			activated = param->Attribute("activate");
			modele = param->Attribute("modele");
			pathXML = param->GetText();
			prod.push_back(string(nameProd));
			prod.push_back(string(typeProd));
			prod.push_back(string(activated));
			prod.push_back(string(modele));
			prod.push_back(string(pathXML));

			VecCatalogue.push_back(prod);

			param = param->NextSiblingElement(); // iteration sur param : les elements
		}

		//================== Boucle sur les types de produits===================
		param = XMLparam.FirstChild("BODY").FirstChild("typeList").Child("prod", 0).ToElement();

		while (param) // boucle sur les elements du XML param�tr�
		{

			vector < string > prod;
			typeProd = param->Attribute("type");
			pathXML = param->GetText();
			prod.push_back(string(typeProd));
			prod.push_back(string(pathXML));

			VecCatalogueType.push_back(prod);

			param = param->NextSiblingElement(); // iteration sur param : les elements
		}


		//================== Boucle sur les mod�les ===================
		param = XMLparam.FirstChild("BODY").FirstChild("modelList").Child("model", 0).ToElement();
		string model;
		while (param) // boucle sur les elements du XML param�tr�
		{

			model = param->Attribute("name");


			VecCatalogueModel.push_back(model);

			param = param->NextSiblingElement(); // iteration sur param : les elements
		}


	} // fin de if (doc_param.LoadFile())
	else {
		char* err = "Erreur du chargement du fichier Catalogue.xml";
		throw err;
	}
}

//=================================================================
//===============   M�thodes   =====================================
//=================================================================

//SuppDoublons : pour supprimer les doublons dans un vecteur de string
vector<string> Catalogue::SuppDoublons(vector<string> vec)
{
	std::vector<std::string> result;
	bool inserer;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		inserer = true;
		for (unsigned int j = i + 1; j < vec.size(); j++)
		{
			if (vec[i] == vec[j])
				inserer = false;
		}
		if (inserer)
			result.push_back(vec[i]);
	}
	return result;
}



// *******************
// update catalogue par les noms de produits, les types et les chemins des XML

void Catalogue::updateCatalogue(char* typeProd, char* nameProd, char* activated, char* modele)
{
	TiXmlDocument doc("..//product file//Catalogue.xml");
	TiXmlHandle hdl(&doc);
	if (doc.LoadFile())
	{
		TiXmlElement *elem = hdl.FirstChild("BODY").FirstChild("productList").ToElement();
		if (elem)
		{
			//balise produit
			TiXmlElement* element2 = new TiXmlElement("prod");
			element2->SetAttribute("name", nameProd);
			element2->SetAttribute("type", typeProd);
			element2->SetAttribute("activate", activated);
			element2->SetAttribute("modele", modele);
			elem->LinkEndChild(element2);

			string path = "EFFICIENCY_" + string(typeProd) + ".xml";

			TiXmlText* texti = new TiXmlText(path.c_str());
			element2->LinkEndChild(texti);

			//ajout du produit au vecteur du catalogue
			vector<string> produit;
			produit.push_back(string(nameProd));
			produit.push_back(string(typeProd));
			produit.push_back(string(activated));
			produit.push_back(string(modele));
			produit.push_back(path);
			this->VecCatalogue.push_back(produit);

			doc.SaveFile("..//product file//Catalogue.xml");  // enregistrement de la modification
		}
	}
	else {
		char* err = "Erreur du chargement du fichier Catalogue.xml";
		throw err;
	}
}

//*******************

bool Catalogue::isInCatalogue(string typeProd, string nameProd)
{
	//verifier si le nom et le type du meme produit existent dans le vecteur du catalogue
	for (size_t i = 0; i < this->VecCatalogue.size(); i++)
	{
		
		if (this->VecCatalogue[i][0] == nameProd && this->VecCatalogue[i][1] == typeProd)
			return true;
	}
	return false;
}


//*******************

bool Catalogue::doublonsActifs(string nameProd, string activated, int indice)
{
	//verifier si le nom et le type du meme produit existent dans le vecteur du catalogue
	for (size_t i = 0; i < indice; i++)
	{
		if (this->VecCatalogue[i][0] == nameProd && this->VecCatalogue[i][2] == "True" && activated == "True")
			return true;
	}
	return false;
}

//**********************************
void Catalogue::deleteCatalogue()
{
	TiXmlDocument doc("../product file//Catalogue.xml");

	if (doc.LoadFile())
	{
		bool trouve = false;
		TiXmlHandle hdl(&doc);
		TiXmlElement *elem = hdl.FirstChild("BODY").FirstChild("productList").FirstChildElement().ToElement();
		TiXmlElement *elem2 = elem;

		while (elem2)
		{

			TiXmlElement *f = hdl.FirstChild("BODY").FirstChild("productList").ToElement();
			elem = elem2;
			elem2 = elem->NextSiblingElement();
			f->RemoveChild(elem);


		}
		doc.SaveFile("..//product file//Catalogue.xml");

		this->VecCatalogue.clear();
	}
	else {
		char* err = "Erreur du chargement du fichier Catalogue.xml";
		throw err;
	}
}

//**********************************
string Catalogue::SearchType(string nameProd)
{
	for (size_t i = 0; i < this->VecCatalogue.size(); i++)
	{
		if (this->VecCatalogue[i][0] == nameProd && this->VecCatalogue[i][2] == "True")
			return this->VecCatalogue[i][1];
	}
	return "";

}

//**********************************
string Catalogue::SearchModel(string nameProd)
{
	for (size_t i = 0; i < this->VecCatalogue.size(); i++)
	{
		if (this->VecCatalogue[i][0] == nameProd && this->VecCatalogue[i][2] == "True")
			return this->VecCatalogue[i][3];
	}
	return "";

}