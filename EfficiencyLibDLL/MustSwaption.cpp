#pragma once
#include <ql/quantlib.hpp>
#include "MustSwaption.h"


MustSwaption::MustSwaption(Date valuationDate, EfficiencyProduct::EfficiencyTypeProduct typeProd, string paths, EfficiencyProduct::EfficiencyModelProduct modelProd, TiXmlDocument hdldoc, string trId) : EfficiencyLibProduct(valuationDate, typeProd, paths, modelProd, hdldoc, trId){
	modelProduct = modelProd;
}
void MustSwaption::setComponentsQuantLib(){
	
	this->setComponentsForSwaption();
	//index
	MustSwaption::myIndex = ComponentIndexMust.ConstructIndex(forwardingTermStructure);

	//FixedLeg
	SwapFixedLeg fixed_Leg;
	fixed_Leg.setComponent(fixedRateObj.matrixRate, fixedLegObj.basisQ, floatingLegObj.freqQ);

	////FloatingLeg
	SwapFloatingLeg floating_leg;
	floating_leg.setComponent(MustSwaption::myIndex, floatingLegObj.basisQ, floatingLegObj.freqQ);


	if (ComponentIndexMust.spreads.size()<1) //condition to check the Sread
	{
		MustSwaption::fixedLeg = fixed_Leg.constructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal);
		MustSwaption::floatingLeg = floating_leg.ConstructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal);
	}
	else
	{
		MustSwaption::fixedLeg = fixed_Leg.constructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal);
		MustSwaption::floatingLeg = floating_leg.ConstructLeg(startDateObj.dateQ, endDateObj.dateQ, ComponentPrincipalMust.nominal, ComponentIndexMust.matrixSpread);
	}

	//SwapType
	VanillaSwap::Type swapType = VanillaSwap::Payer;
	Settlement::Type settlementType = Settlement::Physical;
	if (style == EfficiencyProduct::SwaptionStyle::BERM){
		/* set vetcor of exercise dates*/
		Date exDate = startDateObj.dateQ;
		while (exDate <= endDateObj.dateQ)
		{
			exerciseDates.push_back(exDate);
			exDate.operator+=(Period(componentOption.freqQ));
		}

	}

}
std::vector<Real> MustSwaption::fixedRatesFreq(std::vector<std::tuple<Date, Date, Real>> matrixRate, Date settlementDate, Date maturity, Frequency fixedLegFrequency)
{
	std::vector<Real> fixedRateFreq;

	Date startDate = settlementDate;
	startDate.operator+=(Period(fixedLegFrequency));
	int j = 0;
	while (startDate < maturity){

		while (startDate > std::get<1>(matrixRate[j])) { j++; }

		fixedRateFreq.push_back(std::get<2>(matrixRate[j]));
		startDate.operator+=(Period(fixedLegFrequency));
	}
	return fixedRateFreq;

}
boost::shared_ptr< VanillaSwap >  MustSwaption::constructVanillaSwap(boost::shared_ptr<IborIndex> myIndex){

	//FixedLeg
	SwapFixedLeg fixed_Leg;
	fixed_Leg.setComponent(fixedRateObj.matrixRate, fixedLegObj.basisQ, floatingLegObj.freqQ);

	//FloatingLeg
	SwapFloatingLeg floating_leg;
	floating_leg.setComponent(MustSwaption::myIndex, floatingLegObj.basisQ, floatingLegObj.freqQ);

	VanillaSwap::Type swapType = VanillaSwap::Payer;
	Settlement::Type settlementType = Settlement::Cash;


	Real fixedrate = MustSwaption::fixedRatesFreq(fixedRateObj.matrixRate, maturityObj.dateQ, endDateObj.dateQ, fixedLegObj.freqQ)[0];
	
	switch (style){
	case EfficiencyProduct::SwaptionStyle::EURO:
	{
		boost::shared_ptr<VanillaSwap> swap(
			new VanillaSwap(swapType, ComponentPrincipalMust.nominal[0],
			fixed_Leg.fixedSchedule(maturityObj.dateQ, endDateObj.dateQ), fixedrate, fixedLegObj.basisQ,
			floating_leg.floatSchedule(maturityObj.dateQ, endDateObj.dateQ), myIndex, 0.0,
			floatingLegObj.basisQ));
		return swap;
	}
	break;
	case EfficiencyProduct::SwaptionStyle::AMER:
	{
		Date startDate = TARGET().advance(startDateObj.dateQ, 2, Days);
		boost::shared_ptr<VanillaSwap> swap(
			new VanillaSwap(swapType, ComponentPrincipalMust.nominal[0],
			fixed_Leg.fixedSchedule(startDate, endDateObj.dateQ), fixedrate, fixedLegObj.basisQ,
			floating_leg.floatSchedule(startDate, endDateObj.dateQ), myIndex, 0.0,
			floatingLegObj.basisQ));
		return swap;
	}
	break;
	case EfficiencyProduct::SwaptionStyle::BERM:
	{
		Date startDate = startDateObj.dateQ.operator+=(Period(componentOption.freqQ));

		boost::shared_ptr<VanillaSwap> swap(
			new VanillaSwap(swapType, ComponentPrincipalMust.nominal[0],
			fixed_Leg.fixedSchedule(startDate, endDateObj.dateQ), fixedrate, fixedLegObj.basisQ,
			floating_leg.floatSchedule(startDate, endDateObj.dateQ), myIndex, 0.0,
			floatingLegObj.basisQ));
		return swap;
	}
	break;
	default:
	{
		boost::shared_ptr<VanillaSwap> swap(
			new VanillaSwap(swapType, ComponentPrincipalMust.nominal[0],
			fixed_Leg.fixedSchedule(maturityObj.dateQ, endDateObj.dateQ), fixedrate, fixedLegObj.basisQ,
			floating_leg.floatSchedule(maturityObj.dateQ, endDateObj.dateQ), myIndex, 0.0,
			floatingLegObj.basisQ));
		return swap;
	}
	break;
	}

	boost::shared_ptr<VanillaSwap> swap(
		new VanillaSwap(swapType, ComponentPrincipalMust.nominal[0],
		fixed_Leg.fixedSchedule(maturityObj.dateQ, endDateObj.dateQ), fixedrate, fixedLegObj.basisQ,
		floating_leg.floatSchedule(maturityObj.dateQ, endDateObj.dateQ), myIndex, 0.0,
		floatingLegObj.basisQ));
	return swap;
}
void MustSwaption::makeSwaption(Handle<QuantLib::YieldTermStructure> forwardingTermStructure){
	
	this->setComponentsQuantLib();
	boost::shared_ptr<VanillaSwap> swap = MustSwaption::constructVanillaSwap(myIndex);

	switch (style){
		case EfficiencyProduct::SwaptionStyle::EURO:
		{
			MustSwaption::swaption = boost::shared_ptr<Swaption>(new Swaption(swap, boost::shared_ptr<Exercise>(
				new EuropeanExercise(maturityObj.dateQ)),
				settlementType));
		}
		break;
		case EfficiencyProduct::SwaptionStyle::AMER:
		{
			Date startDate = TARGET().advance(startDateObj.dateQ, 2, Days);
			MustSwaption::swaption = boost::shared_ptr<Swaption>(new Swaption(swap, boost::shared_ptr<Exercise>(
				new AmericanExercise(startDate, maturityObj.dateQ, false)), settlementType));
		}
		break;
		case EfficiencyProduct::SwaptionStyle::BERM:
		{
			MustSwaption::swaption = boost::shared_ptr<Swaption>(new Swaption(swap, boost::shared_ptr<Exercise>(
				new BermudanExercise(exerciseDates)),
				settlementType));
		}
		break;
		default:
		{
			MustSwaption::swaption = boost::shared_ptr<Swaption>(new Swaption(swap, boost::shared_ptr<Exercise>(
				new EuropeanExercise(maturityObj.dateQ)),
				settlementType));
		}
		break;
		}
}
Real MustSwaption::price(){
	switch (modelProduct) {
		case EfficiencyProduct::EfficiencyModelProduct::EFFICIENCY_LMM:
		{
			//TO DO
			return 0;
		}
		break;
		case EfficiencyProduct::EfficiencyModelProduct::QUANTLIB_LMM:
		{
			//TO DO
			boost::shared_ptr<PricingEngine> QLMMEngine = setEngineQuantLibLMM();
			swaption->setPricingEngine(QLMMEngine);
			Real npv = swaption->NPV();
			try{
				vega = swaption->result<Real>("vega");
			}
			catch (...){
				vega = 0;
			}
			return npv;
		} 
		break;
		case EfficiencyProduct::EfficiencyModelProduct::QUANTLIB_BLACKFT:
		{
			boost::shared_ptr<PricingEngine> QBftEngine = setEngineQuantLibBlackFT();
			swaption->setPricingEngine(QBftEngine);
			Real npv = swaption->NPV();
			vega = swaption->result<Real>("vega");
			return npv;
		}
		break;
		case EfficiencyProduct::EfficiencyModelProduct::QUANTLIB_HULLWHITE:
		{
			//TO DO
			boost::shared_ptr<PricingEngine> HwEngine = setEngineQuantLibHullWhite();
			swaption->setPricingEngine(HwEngine);
			return	swaption->NPV();
		}
		break;
		default://just to do something
		{
			return 0;
		}
		break;
		}

}
boost::shared_ptr<PricingEngine> MustSwaption::setEngineQuantLibLMM(){
	CurveData cData;
	// Fill out with some sample market data
	cData.sampleMktData(cData);
	
	// Build a curve linked to this market data
	boost::shared_ptr<YieldTermStructure> ocurve = (cData.buildCurve(cData));

	// Link the curve to the term structure
	//boost::shared_ptr<IborIndex> index = boost::shared_ptr<IborIndex>(new Euribor6M(forwardingTermStructure));
	Date todaysDate =
		myIndex->fixingCalendar().adjust(Date(6, October, 2014));
	Settings::instance().evaluationDate() = today;

	this->forwardingTermStructure.linkTo(ocurve);

	const Size size = floatingLeg.size();

	boost::shared_ptr<LiborForwardModelProcess> process(
		new LiborForwardModelProcess(size, myIndex));

	// set-up the model

	const Real a = 0.025;
	const Real b = 0.12;
	const Real c = 0.1;
	const Real d = 0.01;

	boost::shared_ptr<LmVolatilityModel> volaModel(
		new LmLinearExponentialVolatilityModel(process->fixingTimes(), a, b, c, d));

	boost::shared_ptr<LmCorrelationModel> corrModel(
		new LmLinearExponentialCorrelationModel(size, 0.1, 0.1));

	// set-up pricing engine
	/*	process->setCovarParam(boost::shared_ptr<LfmCovarianceParameterization>(
	new LfmCovarianceProxy(volaModel, corrModel)));
	*/
	boost::shared_ptr<LiborForwardModel>
		liborModel(new LiborForwardModel(process, volaModel, corrModel));

	return boost::shared_ptr<PricingEngine> (
		new LfmSwaptionEngine(liborModel,
		myIndex->forwardingTermStructure()));
}
boost::shared_ptr<PricingEngine> MustSwaption::setEngineQuantLibBlackFT(){
	//TO DO
	CurveData cData;
	// Fill out with some sample market data
	cData.sampleMktData(cData);
	boost::shared_ptr<YieldTermStructure> ocurve = (cData.buildCurve(cData));
	Date todaysDate =
		myIndex->fixingCalendar().adjust(Date(6, October, 2014));
	Settings::instance().evaluationDate() = today;
	// Link the curve to the term structure
	this->forwardingTermStructure.linkTo(ocurve);

	SwaptionVolatility vol;
	vol.termStructure.linkTo(ocurve);
	volatility = vol.atmVolMatrix;

	return boost::shared_ptr<PricingEngine>(
		new BlackSwaptionEngine(forwardingTermStructure, volatility));

	
}
boost::shared_ptr<PricingEngine> MustSwaption::setEngineQuantLibHullWhite(){
	
	Real a = 0.020275, sigma = 0.0001;
	// For American Swaption

	CurveData cData;
	// Fill out with some sample market data
	cData.sampleMktData(cData);
	boost::shared_ptr<YieldTermStructure> ocurve = (cData.buildCurve(cData));

	// Link the curve to the term structure
	this->forwardingTermStructure.linkTo(ocurve);
	const boost::shared_ptr<HullWhite> model(new HullWhite(forwardingTermStructure, a, sigma));
	/*boost::shared_ptr<G2> modelG2(new G2(termStructure));
	return boost::shared_ptr<PricingEngine>(
	new G2SwaptionEngine(modelG2, 6, 1000));*/
	/*return boost::shared_ptr<PricingEngine>(
	new TreeSwaptionEngine(model, 100));*/

	return boost::shared_ptr<PricingEngine>(
		new FdHullWhiteSwaptionEngine(model, 1000, 1000));
}
//
//void MustSwaption::SetPricingEngine(string pricingEngineName, Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure)
//{
//
//	RelinkableHandle<YieldTermStructure> termStructure;
//	termStructure.linkTo(termStructureforLMM());
//	boost::shared_ptr<IborIndex> index2(new Euribor6M(termStructure));
//	//index2->fixingCalendar().adjust(Date(6, October, 2014));
//
//
//	const Size size = 2 * Actual360().yearFraction(maturity.dateQ, tenor.dateQ);
//	boost::shared_ptr<LiborForwardModelProcess> process(
//		new LiborForwardModelProcess(size, index2));
//	// set-up the model
//	const Real a = 0.02;
//	const Real b = 0.4;
//	const Real c = 0.12;
//	const Real d = 0.01;
//
//	boost::shared_ptr<LmVolatilityModel> volaModel(
//		new LmLinearExponentialVolatilityModel(process->fixingTimes(), a, b, c, d));
//	boost::shared_ptr<LmCorrelationModel> corrModel(
//		new LmLinearExponentialCorrelationModel(size, 0.1, 0.1));
//
//	boost::shared_ptr<LiborForwardModel>
//		liborModel(new LiborForwardModel(process, volaModel, corrModel));
//
//
//	if (pricingEngineName == "LMM_QuantLib"){
//		boost::shared_ptr<PricingEngine> engine(
//			new LfmSwaptionEngine(liborModel,
//			index2->forwardingTermStructure()));
//		swaptionquantlibEngine = engine;
//	}
//	else{
//		if (pricingEngineName == "SwapLMMEngine"){
//			boost::shared_ptr<PricingEngine> engine(new DiscountingSwapEngine(index2->forwardingTermStructure()));
//			swapquantlibEngine = engine;
//		}
//
//
//		else {
//			SwaptionVolatility vol;
//			vol.termStructure.linkTo(discountingTermStructure.currentLink());
//			Handle<SwaptionVolatilityStructure> volatility = vol.atmVolMatrix;
//			swaptionquantlibEngine = boost::shared_ptr<PricingEngine>(
//				new BlackSwaptionEngine(discountingTermStructure, volatility));
//		}
//	}
//}
//double MustSwaption::Price(Handle<QuantLib::YieldTermStructure> discountingTermStructure, Handle<QuantLib::YieldTermStructure> forwardingTermStructure, int i, string pricingEngineName)
//{
//	RelinkableHandle<YieldTermStructure> termStructure;
//	termStructure.linkTo(termStructureforLMM());
//	//index
//	boost::shared_ptr<IborIndex> myIndex = index.ConstructIndex(termStructure);
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
//		fixedLeg = fixed_Leg->constructLeg(maturity.dateQ, tenor.dateQ, principal.nominal);
//		floatingLeg = floating_leg->ConstructLeg(maturity.dateQ, tenor.dateQ, principal.nominal);
//	}
//	else
//	{
//		fixedLeg = fixed_Leg->constructLeg(maturity.dateQ, tenor.dateQ, principal.nominal);
//		floatingLeg = floating_leg->ConstructLeg(maturity.dateQ, tenor.dateQ, principal.nominal, index.matrixSpread);
//	}
//
//
//	//SwapType
//	VanillaSwap::Type swapType = VanillaSwap::Payer;
//	Settlement::Type settlementType = Settlement::Physical;
//	//Swap swap(fixedLeg, floatingLeg);
//	boost::shared_ptr<VanillaSwap> swap = constructVanillaSwap(myIndex);
//
//	if (pricingEngineName != "LMM_QuantLib") swapquantlibEngine = boost::shared_ptr<PricingEngine>(new DiscountingSwapEngine(discountingTermStructure));
//	else {
//		SetPricingEngine("SwapLMMEngine", discountingTermStructure, forwardingTermStructure);
//	}
//
//	swap->setPricingEngine(swapquantlibEngine);
//	Real a = swap->NPV();
//	Date maturityDate = TARGET().advance(maturity.dateQ, -2, Days);
//	boost::shared_ptr<Swaption> swaption(new Swaption(swap,
//		boost::shared_ptr<Exercise>(
//		new EuropeanExercise(maturity.dateQ)),
//		settlementType));
//	swaption->setPricingEngine(swaptionquantlibEngine);
//	Real b = swaption->NPV();
//
//
//	return b;
//}
