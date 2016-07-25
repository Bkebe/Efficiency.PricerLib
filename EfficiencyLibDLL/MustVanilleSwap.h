#pragma once
#include "EfficiencyLibProduct.h"
//#include"MustProduct.h"
using namespace QuantLib;
#include "CurveData.h"

#include "DllHeader.h"




class EFFICIEBCYLIBDLL_API MustVanilleSwap : public EfficiencyLibProduct
{
public:
	MustVanilleSwap(Date valuationDate, EfficiencyProduct::EfficiencyTypeProduct typeProd, string paths, EfficiencyProduct::EfficiencyModelProduct modelProd, TiXmlDocument hdldoc, string trId);
	/*double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName) override;
	boost::shared_ptr< PricingEngine >  SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure) override;
*/
	virtual ~MustVanilleSwap(){};
	void setComponentsQuantLib(Handle<QuantLib::YieldTermStructure> forwardingTermStructure);
	void makeSwap(Handle<QuantLib::YieldTermStructure> forwardingTermStructure);
	virtual Real price();
	boost::shared_ptr<Swap>  swap;
#pragma region"Swap Vanille Parametres"
private:
	RelinkableHandle<YieldTermStructure> forwardingTermStructure;
	boost::shared_ptr<IborIndex> myIndex;
	Leg fixedLeg;
	Leg floatingLeg;
	EfficiencyProduct::EfficiencyModelProduct modelProduct;
#pragma endregion 

};
