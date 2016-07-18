#pragma once
#include"EfficiencyLibProduct.h"
#include "CurveData.h"
#include "CapFloorVolatility.h"
using namespace QuantLib;
#include "DllHeader.h"





class EFFICIEBCYLIBDLL_API MustCapFloor : public EfficiencyLibProduct
{
public:
	MustCapFloor(EfficiencyProduct::EfficiencyTypeProduct typeProd, string paths, EfficiencyProduct::EfficiencyModelProduct modelProd, TiXmlHandle hdldoc, string trId);
	void setComponentsQuantLib();
	void makeCapFloor(Handle<QuantLib::YieldTermStructure> forwardingTermStructure);
	virtual ~MustCapFloor(){}
	/*MustCapFloor(ComponentPrincipalMust principal, ComponentCashFlowMust floatingLeg, ComponentIndexMust index, DateMust startDate, DateMust endDate, RateMust fixe_dRate);
	double Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName) override;
	boost::shared_ptr< PricingEngine >  SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure) override;
	double PriceNada_Imane();*/
	virtual Real price();
	boost::shared_ptr<BlackCapFloorEngine> setEngineQuantLibBalckFT();
	boost::shared_ptr<AnalyticCapFloorEngine>  setEngineQuantLibLMM();
	void setEngineQuantLibHullWhite();

#pragma region"CapFloor s Parametres"
private:
	//index
	boost::shared_ptr<IborIndex> myIndex ;
	//Leg
	Leg floatingLeg;
	/* Rate */
	std::vector<Real> Rates;
	EfficiencyProduct::EfficiencyModelProduct modelProduct;
	/*Maket data*/
	Handle<OptionletVolatilityStructure> caplets;
	boost::shared_ptr<CapFloorTermVolSurface> capVolSurface;
	//RelinkableHandle<OptionletVolatilityStructure> caplets;
	Handle<OptionletVolatilityStructure> capletsVolatilies;
	CapFloorVolatility cVol;
	RelinkableHandle<YieldTermStructure> forwardingTermStructure;

public:
	/* TermStructure*/
	boost::shared_ptr<CapFloor> capfloor;
#pragma endregion 


};