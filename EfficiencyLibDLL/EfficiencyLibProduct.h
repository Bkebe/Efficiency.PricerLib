#ifndef EFFICIENCYLIBPRODUCT_H
#define EFFICIENCYLIBPRODUCT_H
#pragma once
#include <C:/local/boost_1_60_0/boost/algorithm/string.hpp>
#include <string>
#include "Portefeuille.h"
#include "EfficiencyLibComponents.h"
#include "Mapping.h"
#include "DllHeader.h"

class EFFICIEBCYLIBDLL_API EfficiencyLibProduct{

public:
	//EfficiencyLibProduct(){}
	EfficiencyLibProduct(EfficiencyProduct::EfficiencyTypeProduct typeProd,string paths, EfficiencyProduct::EfficiencyModelProduct modelProd, TiXmlHandle hdldoc, string trId) : typeProduct(typeProd),modelProduct(modelProd), Xmlhdldoc(hdldoc), trade_id(trId){
		tab_mapp = Mapping(paths, typeProd);
		}
	
	virtual ~EfficiencyLibProduct(){}
private: 
	EfficiencyProduct::EfficiencyTypeProduct typeProduct;
	EfficiencyProduct::EfficiencyModelProduct modelProduct;
	string trade_id;
	TiXmlHandle Xmlhdldoc;
	/*Table de Mapping*/
	Mapping tab_mapp;

public:
	void EfficiencyLibProduct::setComponentsForSwap(){

		/* Mapping ... à voir  */
		string nominalMust = tab_mapp.search_mapping("NominalQuantLib");
		string startDateMust = tab_mapp.search_mapping("startDateQuantLib");
		string endDateMust = tab_mapp.search_mapping("endDateQuantLib");
		string fixedRateMust = tab_mapp.search_mapping("FixedRateQuantLib");
		string fixedLegMust = tab_mapp.search_mapping("FixedLegQuantLib");
		string floatingLegMust = tab_mapp.search_mapping("FloatingLegQuantLib");
		string indexMust = tab_mapp.search_mapping("IndexQuantLib");

		// nominal
		ComponentPrincipalMust.setComponent(Xmlhdldoc, nominalMust, trade_id);
		Real nominal = ComponentPrincipalMust.nominal[0];

		// settlementDate
		startDateObj.setComponent(Xmlhdldoc, startDateMust, trade_id);
		Date settlementDate = startDateObj.dateQ;

		// maturity
		endDateObj.setComponent(Xmlhdldoc, endDateMust, trade_id);
		Date maturity = endDateObj.dateQ;

		// fixedRate
		fixedRateObj.setComponent(Xmlhdldoc, fixedRateMust, trade_id);
		Rate fixedRate = fixedRateObj.rates[0];
		fixedRateObj.SetMatrixRate(settlementDate, maturity, fixedRateObj.rates);

		//=============FIXED LEG================
		fixedLegObj.setComponent(Xmlhdldoc, fixedLegMust, trade_id);
		Frequency fixedLegFrequency = fixedLegObj.freqQ;
		DayCounter fixedLegDayCounter = fixedLegObj.basisQ;

		//=============FLOATING LEG================
		floatingLegObj.setComponent(Xmlhdldoc, floatingLegMust, trade_id);
		Frequency floatingLegFrequency = floatingLegObj.freqQ;
		DayCounter floatingLegDayCounter = floatingLegObj.basisQ;

		// Index
		ComponentIndexMust.setComponent(Xmlhdldoc, indexMust, trade_id);
		ComponentIndexMust.SetMatrixSpread(settlementDate, maturity, ComponentIndexMust.spreads);

	}
	void EfficiencyLibProduct::setComponentsForCapFloor(){
		/* Mapping .. à vvoir*/
		string nominalMust = tab_mapp.search_mapping("NominalQuantLib");
		string startDateMust = tab_mapp.search_mapping("startDateQuantLib");
		string endDateMust = tab_mapp.search_mapping("endDateQuantLib");
		string fixedRateMust = tab_mapp.search_mapping("StrikeQuantLib");
		string floatingLegMust = tab_mapp.search_mapping("FloatingLegQuantLib");
		string indexMust = tab_mapp.search_mapping("IndexQuantLib");


		// nominal
		ComponentPrincipalMust.setComponent(Xmlhdldoc, nominalMust, trade_id);
		Real nominal = ComponentPrincipalMust.nominal[0];


		// settlementDate
		startDateObj.setComponent(Xmlhdldoc, startDateMust, trade_id);
		Date settlementDate = startDateObj.dateQ;

		// maturity
		endDateObj.setComponent(Xmlhdldoc, endDateMust, trade_id);
		Date maturity = endDateObj.dateQ;

		// fixedRate
		fixedRateObj.setComponent(Xmlhdldoc, fixedRateMust, trade_id);
		Rate fixedRate = fixedRateObj.rates[0];
		fixedRateObj.SetMatrixRate(settlementDate, maturity, fixedRateObj.rates);


		//=============FLOATING LEG================
		floatingLegObj.setComponent(Xmlhdldoc, floatingLegMust, trade_id);
		Frequency floatingLegFrequency = floatingLegObj.freqQ;
		DayCounter floatingLegDayCounter = floatingLegObj.basisQ;


		// Index
		ComponentIndexMust.setComponent(Xmlhdldoc, indexMust, trade_id);
		ComponentIndexMust.SetMatrixSpread(settlementDate, maturity, ComponentIndexMust.spreads);
	}
	void EfficiencyLibProduct::setComponentsForSwaption(){
		string nominalMust = tab_mapp.search_mapping("NominalQuantLib");
		string startDateMust = tab_mapp.search_mapping("startDateQuantLib");
		string maturityOption = tab_mapp.search_mapping("maturityOptionQuantLib");
		string endDateMust = tab_mapp.search_mapping("endDateQuantLib");
		string option = tab_mapp.search_mapping("OptionQuantLib");
		string fixedLegMust = tab_mapp.search_mapping("FixedLegQuantLib");
		string floatingLegMust = tab_mapp.search_mapping("FloatingLegQuantLib");
		string fixedRateMust = tab_mapp.search_mapping("FixedRateQuantLib");
		string indexMust = tab_mapp.search_mapping("IndexQuantLib");

		// nominal
		ComponentPrincipalMust.setComponent(Xmlhdldoc, nominalMust, trade_id);
		Real nominal = ComponentPrincipalMust.nominal[0];

		// First Date : Option
		startDateObj.setComponent(Xmlhdldoc, startDateMust, trade_id);
		Date startDate = startDateObj.dateQ;

		// maturité de l'option
		maturityObj.setComponent(Xmlhdldoc, maturityOption, trade_id);
		Date maturity = maturityObj.dateQ;

		// date de fin de la swaption
		endDateObj.setComponent(Xmlhdldoc, endDateMust, trade_id);
		Date endDate = endDateObj.dateQ;

		// fixedRate
		fixedRateObj.setComponent(Xmlhdldoc, fixedRateMust, trade_id);
		Rate fixedRate = fixedRateObj.rates[0];
		fixedRateObj.SetMatrixRate(maturity, endDate, fixedRateObj.rates);

		// Option
		componentOption.setComponents(Xmlhdldoc, option, trade_id);

		//=============FIXED LEG================
		fixedLegObj.setComponent(Xmlhdldoc, fixedLegMust, trade_id);
		Frequency fixedLegFrequency = fixedLegObj.freqQ;
		DayCounter fixedLegDayCounter = fixedLegObj.basisQ;

		//=============FLOATING LEG================
		floatingLegObj.setComponent(Xmlhdldoc, floatingLegMust, trade_id);
		Frequency floatingLegFrequency = floatingLegObj.freqQ;
		DayCounter floatingLegDayCounter = floatingLegObj.basisQ;

		// Index
		ComponentIndexMust.setComponent(Xmlhdldoc, indexMust, trade_id);
		ComponentIndexMust.SetMatrixSpread(startDate, endDate, ComponentIndexMust.spreads);

	}
	virtual Real price() = 0;//Just for tests



	/* Les Composantes Must*/
	ComponentCashFlowMust ComponentCFlowMust;
	ComponentCashFlowMust floatingLegObj;
	ComponentCashFlowMust fixedLegObj;
	 ComponentIndexMust ComponentIndexMust;
	 MatriceMust MatriceMust;
	 ComponentPrincipalMust ComponentPrincipalMust;
	 DateMust startDateObj;
	 DateMust endDateObj;
	 DateMust maturityObj;
	 RateMust fixedRateObj;
	 SwapFloatingLeg swapFloatingLeg;
	 SwapFixedLeg swapFixedLeg;
	 ComponentOptionMust componentOption;




}; 
#endif