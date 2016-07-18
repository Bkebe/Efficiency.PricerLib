#include "EfficiencyLibProducts.h"
void  EfficiencyLibProducts::setModelsProductsTypes(){
	for (std::size_t iTrade = 0; iTrade < portefeuille.AllTrades->size(); iTrade++)
	{
		if (catalogue->SearchType(portefeuille.AllTrades->operator[](iTrade)->nameProduct) != ""
			&& catalogue->SearchModel(portefeuille.AllTrades->operator[](iTrade)->nameProduct) != "") // càd si le produit existe dans le catalogue des produits
		{
			portefeuille.AllTrades->operator[](iTrade)->modele = catalogue->SearchModel(portefeuille.AllTrades->operator[](iTrade)->nameProduct);
			portefeuille.AllTrades->operator[](iTrade)->typeProduct = catalogue->SearchType(portefeuille.AllTrades->operator[](iTrade)->nameProduct);
		}
		else
		{
			//si le produit n'existe pas dans le catalogue
			string monMessage = "Le trade '" + portefeuille.AllTrades->operator[](iTrade)->nameProduct + "' de ID : " + portefeuille.AllTrades->operator[](iTrade)->tradeID + " n'existe pas dans le catalogue !";
			throw monMessage;
		}
	}

}
void EfficiencyLibProducts::setMarketData(boost::shared_ptr<QuantLib::YieldTermStructure> yieldTermStructure){
	EfficiencyLibProducts::forwardingTermStructure.linkTo(yieldTermStructure);
}
/* Construction de tous les produits "Must Trade" qui sont dans le portefeuille*/
void  EfficiencyLibProducts::makeProducts(){
	EfficiencyProduct::EfficiencyTypeProduct typeProduct;
	EfficiencyProduct::EfficiencyModelProduct modelProduct;
	
	for (std::size_t iTrade = 0; iTrade < portefeuille.AllTrades->size(); iTrade++)
	{
		if (portefeuille.AllTrades->operator[](iTrade)->typeProduct != "") // càd si le produit existe dans le catalogue des produits
		{
			typeProduct = EfficiencyProduct::stringToTypeProduct(portefeuille.AllTrades->operator[](iTrade)->typeProduct);
			modelProduct = EfficiencyProduct::stringToModelProduct(portefeuille.AllTrades->operator[](iTrade)->modele);

			string path = "";
			for (size_t indice = 0; indice < catalogue->VecCatalogue.size(); indice++)
			{
				if (catalogue->VecCatalogue[indice][0] != "" && catalogue->VecCatalogue[indice][1] != "")
				{
					if ( portefeuille.AllTrades->operator[](iTrade)->typeProduct == catalogue->VecCatalogue[indice][1]){ // si c'est le même type de produit
						path = catalogue->VecCatalogue[indice][4];
						break;
					}
				}
			}
			switch (typeProduct) {
			case EfficiencyProduct::EfficiencyTypeProduct::SWAP:
			{

				CurveData cData;
				// Fill out with some sample market data
				cData.sampleMktData(cData);

				// Build a curve linked to this market data
				boost::shared_ptr<YieldTermStructure> ocurve = (cData.buildCurve(cData));

				// Link the curve to the term structure
				this->forwardingTermStructure.linkTo(ocurve);
				Date today(6, October, 2014);
				// today = calendar.adjust(today);
				Settings::instance().evaluationDate() = today;


				MustVanilleSwap* swap = new MustVanilleSwap(typeProduct, path, modelProduct, Xmlhdldoc, portefeuille.AllTrades->operator[](iTrade)->tradeID);
				swap->makeSwap(forwardingTermStructure);
				AllProducts.push_back(swap);
			}
			break;
			case EfficiencyProduct::EfficiencyTypeProduct::CAPFLOOR:
			{

				
				MustCapFloor* capfloor = new MustCapFloor(typeProduct, path, modelProduct,Xmlhdldoc, portefeuille.AllTrades->operator[](iTrade)->tradeID);

				capfloor->makeCapFloor(forwardingTermStructure);
				AllProducts.push_back(capfloor);
			}
			break;
			case EfficiencyProduct::EfficiencyTypeProduct::SWAPTION:
			{
				MustSwaption* swaption = new MustSwaption(typeProduct, path, modelProduct, Xmlhdldoc, portefeuille.AllTrades->operator[](iTrade)->tradeID);
				swaption->makeSwaption(forwardingTermStructure);
				AllProducts.push_back(swaption);
			}
			break;
			default:
				//just to do something
			{
				MustVanilleSwap* swapTest = new MustVanilleSwap(typeProduct,path, modelProduct, Xmlhdldoc, portefeuille.AllTrades->operator[](iTrade)->tradeID);
				swapTest->makeSwap(forwardingTermStructure);
				AllProducts.push_back(swapTest);
			}
			break;
			}
		}
	}

}