
//#include <ql/instruments/swap.hpp>
//#include <ql/time/daycounter.hpp>
//#include <ql/indexes/iborindex.hpp>
//#include <ql/time/daycounters/actual360.hpp>
//
//#include <ql/indexes/iborindex.hpp>
//#include <ql/quantlib.hpp>
#include "SwapFloatingLeg.h"
using namespace QuantLib;

#pragma region"Get & Set"

boost::shared_ptr<IborIndex> SwapFloatingLeg::getfloating_index() const
{
	return this->floating_index;
}

DayCounter SwapFloatingLeg::getfloatingLegDayCounter() const
{
	return this->floatingLegDayCounter;
}

Frequency SwapFloatingLeg::getfloatingLegFrequency() const
{
	return this->floatingLegFrequency;
}

void SwapFloatingLeg::setfloatingLegFrequency(Frequency floatingLegFrequency)
{
	this->floatingLegFrequency = floatingLegFrequency;
}

void SwapFloatingLeg::setfloatingLegDayCounter(DayCounter floatingLegDayCounter)
{
	this->floatingLegDayCounter = floatingLegDayCounter;
}

void SwapFloatingLeg::setfloating_index(boost::shared_ptr<IborIndex> floating_index)
{
	this->floating_index = floating_index;
}
#pragma endregion


//Constructeur
SwapFloatingLeg::SwapFloatingLeg(){}

void SwapFloatingLeg::setComponent(boost::shared_ptr<IborIndex> Floating_index, DayCounter FloatingLegDayCounter, Frequency FloatingLegFrequency)
		{
			floating_index = Floating_index; floatingLegDayCounter = FloatingLegDayCounter; floatingLegFrequency = FloatingLegFrequency;
		}
//SwapFloatingLeg::SwapFloatingLeg(boost::shared_ptr<IborIndex> Floating_index, DayCounter FloatingLegDayCounter, Frequency FloatingLegFrequency, Spread   Spread)
//: floating_index(Floating_index), floatingLegDayCounter(FloatingLegDayCounter), floatingLegFrequency(FloatingLegFrequency), spread(Spread)
//{
//}
//SwapFloatingLeg::SwapFloatingLeg(boost::shared_ptr<IborIndex> Floating_index, DayCounter FloatingLegDayCounter, Frequency FloatingLegFrequency, std::vector<Spread>  Spreads)
//: floating_index(Floating_index), floatingLegDayCounter(FloatingLegDayCounter), floatingLegFrequency(FloatingLegFrequency), spreads(Spreads)
//{
//}



//Schedule
Schedule SwapFloatingLeg::floatSchedule(Date settlementDate, Date maturity) const
{
	return Schedule(settlementDate, maturity, Period(floatingLegFrequency),
		TARGET(), ModifiedFollowing, ModifiedFollowing,
		DateGeneration::Forward, false);
}

Leg SwapFloatingLeg::ConstructLeg(Date settlementDate, Date maturity, std::vector<double> nominals){
	Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
		TARGET(), ModifiedFollowing, ModifiedFollowing,
		DateGeneration::Forward, false);
	return IborLeg(schedule, floating_index)
		//.withNotionals(vectorAdaptFreq(nominals, settlementDate, maturity, floatingLegFrequency))
		.withNotionals(nominals)
		.withPaymentDayCounter(Actual360())
		.withPaymentAdjustment(ModifiedFollowing)
		.withFixingDays(2);

}
//Leg ConstructLeg(Date startDate, Date endDate, double nominals) const;
Leg SwapFloatingLeg::ConstructLeg(Date settlementDate, Date maturity, std::vector<double> nominals, std::vector<std::tuple<Date, Date, Real>>  Spreads){
	Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
		TARGET(), ModifiedFollowing, ModifiedFollowing,
		DateGeneration::Forward, false);

	return IborLeg(schedule, floating_index)
		//.withNotionals(vectorAdaptFreq(nominals, settlementDate, maturity, floatingLegFrequency))
		.withNotionals(nominals)
		.withPaymentDayCounter(floatingLegDayCounter)
		.withPaymentAdjustment(ModifiedFollowing)
		.withFixingDays(2)
		.withSpreads(vectorAdaptFreq(Spreads, settlementDate, maturity, floatingLegFrequency));
}


std::vector<Real> SwapFloatingLeg::vectorAdaptFreq(std::vector<std::tuple<Date, Date, Real>> matrixRate, Date settlementDate, Date maturity, Frequency fixedLegFrequency)
{
	std::vector<Real> fixedRateFreq;
	//int nmbrofPeriode = 12 * Actual360().yearFraction(settlementDate, maturity);

	//int i = 1;


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


//Legs

//Leg SwapFloatingLeg::ConstructLeg(Date settlementDate, Date maturity, double nominals) const {
//	Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
//		TARGET(), ModifiedFollowing, ModifiedFollowing,
//		DateGeneration::Forward, false);
//	return IborLeg(schedule, floating_index)
//		.withNotionals(nominals)
//		.withPaymentDayCounter(Actual360())
//		.withPaymentAdjustment(ModifiedFollowing)
//		.withFixingDays(2);
//	
//}

//AVec Spread(s)

//Leg SwapFloatingLeg::ConstructLeg(Date settlementDate, Date maturity, std::vector<double> nominals, Spread  spread) const {
//	Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
//		TARGET(), ModifiedFollowing, ModifiedFollowing,
//		DateGeneration::Forward, false);
//	return IborLeg(schedule, floating_index)
//		.withNotionals(nominals)
//		.withPaymentDayCounter(floatingLegDayCounter)
//		.withPaymentAdjustment(ModifiedFollowing)
//		.withFixingDays(2)
//		.withSpreads(spread);
//
//}


//Leg SwapFloatingLeg::ConstructLeg(Date settlementDate, Date maturity, double nominals, std::vector<Spread>  Spreads) const {
//	Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
//		TARGET(), ModifiedFollowing, ModifiedFollowing,
//		DateGeneration::Forward, false);
//
//	return IborLeg(schedule, floating_index)
//		.withNotionals(nominals)
//		.withPaymentDayCounter(floatingLegDayCounter)
//		.withPaymentAdjustment(ModifiedFollowing)
//		.withFixingDays(2)
//		.withSpreads(Spreads);
//
//
//}
//Leg SwapFloatingLeg::ConstructLeg(Date settlementDate, Date maturity, double nominals, Spread  spread) const {
//	Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
//		TARGET(), ModifiedFollowing, ModifiedFollowing,
//		DateGeneration::Forward, false);
//	return IborLeg(schedule, floating_index)
//		.withNotionals(nominals)
//		.withPaymentDayCounter(floatingLegDayCounter)
//		.withPaymentAdjustment(ModifiedFollowing)
//		.withFixingDays(2)
//		.withSpreads(spread);
//}



//boost::shared_ptr<IborIndex> myIndex;
//if (index.IndexIndex == "euribor"){
//	myIndex = new Euribor(index.IndexTermQ * Months, forwardingTermStructure);
//}
//else{
//	if (index.IndexIndex == "eurLibor"){
//		myIndex = new EURLibor(index.IndexTermQ * Months, forwardingTermStructure);
//	}
//	else{
//		myIndex = new Euribor6M(forwardingTermStructure);
//	}
//}