#pragma once
#include <ql/quantlib.hpp>
#include "MustCapFloor.h"

MustCapFloor::MustCapFloor(Date valuationDate, EfficiencyProduct::EfficiencyTypeProduct typeProd, string paths, EfficiencyProduct::EfficiencyModelProduct modelProd, TiXmlDocument hdldoc, string trId) : EfficiencyLibProduct(valuationDate, typeProd, paths, modelProd, hdldoc, trId){
	modelProduct = modelProd;
	//cVol = new CapFloorVolatility();
	//capletsVolatilies = (cVol.buildFlatCurveVol(cVol));
	
}
void MustCapFloor::setComponentsQuantLib(){
	this->setComponentsForCapFloor();
	//index
	MustCapFloor::myIndex = ComponentIndexMust.ConstructIndex(forwardingTermStructure);

	////FloatingLeg
	SwapFloatingLeg floating_leg;
	floating_leg.setComponent(MustCapFloor::myIndex, floatingLegObj.basisQ, floatingLegObj.freqQ);

	Rates = floating_leg.vectorAdaptFreq(fixedRateObj.matrixRate, startDateObj.dateQ, endDateObj.dateQ, floatingLegObj.freqQ);

	if (ComponentIndexMust.spreads.size()<1) //condition to check the Sread
	{
		MustCapFloor::floatingLeg = floating_leg.ConstructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal);
	}
	else
	{
		MustCapFloor::floatingLeg = floating_leg.ConstructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal, ComponentIndexMust.matrixSpread);
	}
}

void MustCapFloor::makeCapFloor(Handle<QuantLib::YieldTermStructure> forwardingTermStructure){
//	this->forwardingTermStructure.linkTo(forwardingTermStructure);
	this->setComponentsQuantLib();
	//MustCapFloor::capfloor =  CapFloor(QuantLib::CapFloor::Cap, floatingLeg, Rates);
	MustCapFloor::capfloor = boost::shared_ptr<CapFloor> (new Cap(floatingLeg, Rates));
	//return boost::shared_ptr<CapFloor> CapFloor(new Cap(floatingLeg, Rates));
}

Real MustCapFloor::price(){
	switch (modelProduct) {
	case EfficiencyProduct::EfficiencyModelProduct::EFFICIENCY_LMM:
	{
		//TO DO
		return 0;
	}
	break;
	case EfficiencyProduct::EfficiencyModelProduct::QUANTLIB_LMM:
	{
		boost::shared_ptr<AnalyticCapFloorEngine> LmEngine = setEngineQuantLibLMM();

		capfloor->setPricingEngine(LmEngine);
		Real npv = capfloor->NPV();
		vega = capfloor->result<Real>("vega");
		return npv;
		//return 0;
	}
	break;
	case EfficiencyProduct::EfficiencyModelProduct::QUANTLIB_BLACKFT:
	{
		//TO DO

		boost::shared_ptr<BlackCapFloorEngine> strippedVolEngine = setEngineQuantLibBalckFT();
		 capfloor->setPricingEngine(strippedVolEngine);
		 Real npv = capfloor->NPV();
		 vega = capfloor->result<Real>("vega");
		return npv;
	}
	break;
	case EfficiencyProduct::EfficiencyModelProduct::QUANTLIB_HULLWHITE:
	{
		//TO DO
		return 0;
	}
	break;
	default://just to do something
	{
		return 0;
	}
	break;
	}
}

boost::shared_ptr<BlackCapFloorEngine> MustCapFloor::setEngineQuantLibBalckFT(){

	CurveData cData;
	// Fill out with some sample market data
	cData.sampleMktData(cData);

	// Build a curve linked to this market data
	boost::shared_ptr<YieldTermStructure> ocurve = (cData.buildCurve(cData));

	// Link the curve to the term structure
	this->forwardingTermStructure.linkTo(ocurve);
	//Date today(6, October, 2014);
	Settings::instance().evaluationDate() = today;

	//Date todaysDate = Date(8, Apr, 2015);
	//capletsVolatilies = buildCurveOptionletAtmVol(cVol);
	//capletsVolatilies = buildOptionletSurfaceVol(cVol);
	//capletsVolatilies = buildOptionletCurveVol(cVol);

	cVol.termStructure.linkTo(ocurve);
	capletsVolatilies = (cVol.buildFlatCurveVol(cVol));

	//capVol->enableExtrapolation();
	return boost::shared_ptr<BlackCapFloorEngine>(new
		BlackCapFloorEngine(forwardingTermStructure, capletsVolatilies));
}
boost::shared_ptr<AnalyticCapFloorEngine> MustCapFloor::setEngineQuantLibLMM(){
	CurveData cData;
	// Fill out with some sample market data
	cData.sampleMktData(cData);
	//Date today(10, October, 2014);
	//Settings::instance().evaluationDate() = today;
	// Build a curve linked to this market data
	boost::shared_ptr<YieldTermStructure> ocurve = (cData.buildCurve(cData));

	// Link the curve to the term structure
	boost::shared_ptr<IborIndex> index = boost::shared_ptr<IborIndex>(new Euribor6M(forwardingTermStructure));
	Date todaysDate =
		myIndex->fixingCalendar().adjust(today);
	Settings::instance().evaluationDate() = todaysDate;

	this->forwardingTermStructure.linkTo(ocurve);

	

	const Size size = floatingLeg.size();
	boost::shared_ptr<LiborForwardModelProcess> process(
		new LiborForwardModelProcess(size, myIndex));

	//// set-up the model
	///*	const Real a = 0.02;
	//const Real b = 0.12;
	//const Real c = 0.1;
	//const Real d = 0.01;*/

	const Real a = 0.025;
	const Real b = 0.12;
	const Real c = 0.1;
	const Real d = 0.01;

	boost::shared_ptr<LmVolatilityModel> volaModel(
		new LmLinearExponentialVolatilityModel(process->fixingTimes(), a, b, c, d));

	boost::shared_ptr<LmCorrelationModel> corrModel(
		new LmLinearExponentialCorrelationModel(size, 0.1, 0.1));

	boost::shared_ptr<LiborForwardModel> liborModel(
		new LiborForwardModel(process, volaModel, corrModel));

return	boost::shared_ptr<AnalyticCapFloorEngine> (
		new AnalyticCapFloorEngine(liborModel, forwardingTermStructure));
}
void MustCapFloor::setEngineQuantLibHullWhite(){

}

