#pragma once
#include <ql/quantlib.hpp>
#include "MustVanilleSwap.h"

using namespace std;
using namespace QuantLib;
using namespace boost;


MustVanilleSwap::MustVanilleSwap(EfficiencyProduct::EfficiencyTypeProduct typeProd, string paths, EfficiencyProduct::EfficiencyModelProduct modelProd, TiXmlHandle hdldoc, string trId) : EfficiencyLibProduct(typeProd,paths, modelProd, hdldoc, trId){
	this->modelProduct = modelProd;
}

void MustVanilleSwap::setComponentsQuantLib(Handle<QuantLib::YieldTermStructure> forwardingTermStructure){
	//this->forwardingTermStructure = forwardingTermStructure ;
	this->setComponentsForSwap();

	//index
	MustVanilleSwap::myIndex = ComponentIndexMust.ConstructIndex(forwardingTermStructure);

	//FixedLeg
	SwapFixedLeg fixed_Leg;
	fixed_Leg.setComponent(fixedRateObj.matrixRate, fixedLegObj.basisQ, floatingLegObj.freqQ);

	////FloatingLeg
	SwapFloatingLeg floating_leg;
	floating_leg.setComponent(MustVanilleSwap::myIndex, floatingLegObj.basisQ, floatingLegObj.freqQ);


	if (ComponentIndexMust.spreads.size()<1) //condition to check the Sread
	{
		MustVanilleSwap::fixedLeg = fixed_Leg.constructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal);
		MustVanilleSwap::floatingLeg = floating_leg.ConstructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal);
	}
	else
	{
		MustVanilleSwap::fixedLeg = fixed_Leg.constructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal);
		MustVanilleSwap::floatingLeg = floating_leg.ConstructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal, ComponentIndexMust.matrixSpread);
	}
}

 void MustVanilleSwap::makeSwap(Handle<QuantLib::YieldTermStructure> forwardingTermStructure){
	setComponentsQuantLib(forwardingTermStructure);
	this->swap = boost::shared_ptr<Swap>(new Swap(fixedLeg, floatingLeg));
}

 Real MustVanilleSwap::price(){

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
	 MustVanilleSwap::swap->setPricingEngine(boost::shared_ptr<PricingEngine>(
		 new DiscountingSwapEngine(this->forwardingTermStructure)));
	 return  this->swap->NPV();
 }

//boost::shared_ptr< PricingEngine >  MustVanilleSwap::SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure)
//{
//	boost::shared_ptr<PricingEngine> swapEngine(new DiscountingSwapEngine(discountingTermStructure));
//	return swapEngine;
//}
//double MustVanilleSwap::Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName)
//{
//	//index
//	boost::shared_ptr<IborIndex> myIndex = index.ConstructIndex(forwardingTermStructure);
//
//
//	//FixedLeg
//	SwapFixedLeg* fixed_Leg = new SwapFixedLeg(fixed_Rate.matrixRate, fixed_LegFlow.basisQ, fixed_LegFlow.freqQ);
//
//	//FloatingLeg
//	SwapFloatingLeg* floating_leg = new SwapFloatingLeg(myIndex, floating_LegFlow.basisQ, floating_LegFlow.freqQ);
//
//	Leg fixedLeg;
//	Leg floatingLeg;
//
//
//	if (index.spreads.size()<1) //condition to check the Sread
//	{
//		fixedLeg = fixed_Leg->constructLeg(startDate.dateQ, endDate.dateQ, principal.nominal);
//		floatingLeg = floating_leg->ConstructLeg(startDate.dateQ, endDate.dateQ, principal.nominal);
//	}
//	else
//	{
//		fixedLeg = fixed_Leg->constructLeg(startDate.dateQ, endDate.dateQ, principal.nominal);
//		floatingLeg = floating_leg->ConstructLeg(startDate.dateQ, endDate.dateQ, principal.nominal, index.matrixSpread);
//	}
//
//
//	//SwapType
//	//VanillaSwap::Type swapType = VanillaSwap::Payer;
//	Swap swap(fixedLeg, floatingLeg);
//	boost::shared_ptr<PricingEngine> swapEngine = SetPricingEngine(pricingEngineName, discountingTermStructure, forwardingTermStructure);
//	swap.setPricingEngine(swapEngine);
//
//	if (i == 1)
//	{
//		return swap.NPV();
//	}
//	else{
//		if (i == 2){ return swap.legNPV(0); }
//		else{ return swap.legNPV(1); }
//	}
//
//}
