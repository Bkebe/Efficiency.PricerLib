
#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>
#include <ql/indexes/iborindex.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/schedule.hpp>
#include <ql/quantlib.hpp>


using namespace QuantLib;

#include "DllHeader.h"




class EFFICIEBCYLIBDLL_API SwapFixedLeg
{
public:
	//Constructeur
	SwapFixedLeg();
	~SwapFixedLeg();
	//SwapFixedLeg(Real FixedRate, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency);
	SwapFixedLeg(std::vector<std::tuple<Date, Date, Real>>  FixedRates, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency);
	void setComponent(std::vector<std::tuple<Date, Date, Real>>  FixedRates, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency);
#pragma region"Get & Set Fonctions"
	//void setfixedRate(Real fixedRate);
	void setfixedRates(std::vector<std::tuple<Date, Date, Real>>  fixedRates);
	void setfixedLegDayCounter(DayCounter fixedLegDayCounter);
	void setfixedLegFrequency(Frequency fixedLegFrequency);
	//Real getfixedRate() const;
	std::vector<std::tuple<Date, Date, Real>> getfixedRates() const;
	DayCounter getfixedLegDayCounter() const;
	Frequency getfixedLegFrequency() const;
#pragma endregion 

	Schedule fixedSchedule(Date settlementDate, Date maturity) const;
	//Leg constructLeg(Date startDate, Date endDate, std::vector<double> nominals) const;
	//Leg constructLeg(Date startDate, Date endDate, double nominals) const;
	//std::vector<Real> fixedRatesFreq(std::vector<std::tuple<Date, Date, Real>> matrixRateDate, Date maturity, Date settlementDate, Frequency fixedLegFrequency)const;
	Leg constructLeg(Date settlementDate, Date maturity, std::vector<double> nominals);
	

	std::vector<Real> fixedRatesFreq(std::vector<std::tuple<Date, Date, Real>> matrixRate, Date settlementDate, Date maturity, Frequency fixedLegFrequency);



private:
	//Real fixedRate;


	std::vector<std::tuple<Date, Date, Real>> fixedRates;
	DayCounter fixedLegDayCounter;
	Frequency fixedLegFrequency;

};
