
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>
#include "ComponentCashFlowMust.h"
#include "ComponentIndexMust.h"
#include "ComponentOptionMust.h"
#include "ComponentPrincipalMust.h"
#include "RateMust.h"
#include "EnumMust.h"
#include "SwapFloatingLeg.h"
#include "SwapFixedLeg.h"
using namespace QuantLib;

namespace EfficiencyLibComponents {
//
//	public class SwapFloatingLeg 
//	{
//	public:
//		//Constructeur
//		SwapFloatingLeg(){};
//		void setComponent(boost::shared_ptr<IborIndex> Floating_index, DayCounter FloatingLegDayCounter, Frequency FloatingLegFrequency) 
//		{
//			floating_index = Floating_index; floatingLegDayCounter = FloatingLegDayCounter; floatingLegFrequency = FloatingLegFrequency;
//		}
//		boost::shared_ptr<IborIndex> getfloating_index() const
//		{
//			return this->floating_index;
//		}
//		DayCounter getfloatingLegDayCounter() const
//		{
//			return this->floatingLegDayCounter;
//		}
//		Frequency getfloatingLegFrequency() const
//		{
//			return this->floatingLegFrequency;
//		}
//		void setfloatingLegFrequency(Frequency floatingLegFrequency)
//		{
//			this->floatingLegFrequency = floatingLegFrequency;
//		}
//		void setfloatingLegDayCounter(DayCounter floatingLegDayCounter)
//		{
//			this->floatingLegDayCounter = floatingLegDayCounter;
//		}
//		void setfloating_index(boost::shared_ptr<IborIndex> floating_index)
//		{
//			this->floating_index = floating_index;
//		}
//		Leg ConstructLeg(Date settlementDate, Date maturity, std::vector<double> nominals){
//			Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
//				TARGET(), ModifiedFollowing, ModifiedFollowing,
//				DateGeneration::Forward, false);
//			return IborLeg(schedule, floating_index)
//				//.withNotionals(vectorAdaptFreq(nominals, settlementDate, maturity, floatingLegFrequency))
//				.withNotionals(nominals)
//				.withPaymentDayCounter(Actual360())
//				.withPaymentAdjustment(ModifiedFollowing)
//				.withFixingDays(2);
//
//		}
//		Leg ConstructLeg(Date settlementDate, Date maturity, std::vector<double> nominals, std::vector<std::tuple<Date, Date, Real>>  Spreads){
//			Schedule  schedule(settlementDate, maturity, Period(floatingLegFrequency),
//				TARGET(), ModifiedFollowing, ModifiedFollowing,
//				DateGeneration::Forward, false);
//
//			return IborLeg(schedule, floating_index)
//				//.withNotionals(vectorAdaptFreq(nominals, settlementDate, maturity, floatingLegFrequency))
//				.withNotionals(nominals)
//				.withPaymentDayCounter(floatingLegDayCounter)
//				.withPaymentAdjustment(ModifiedFollowing)
//				.withFixingDays(2)
//				.withSpreads(vectorAdaptFreq(Spreads, settlementDate, maturity, floatingLegFrequency));
//		}
//		/* Schedule*/
//		Schedule floatSchedule(Date settlementDate, Date maturity) const
//		{
//			return Schedule(settlementDate, maturity, Period(floatingLegFrequency),
//				TARGET(), ModifiedFollowing, ModifiedFollowing,
//				DateGeneration::Forward, false);
//		}
//			
//		std::vector<Real> vectorAdaptFreq(std::vector<std::tuple<Date, Date, Real>> matrixRate, Date settlementDate, Date maturity, Frequency fixedLegFrequency)
//		{
//			std::vector<Real> fixedRateFreq;
//			//int nmbrofPeriode = 12 * Actual360().yearFraction(settlementDate, maturity);
//
//			//int i = 1;
//
//
//			Date startDate = settlementDate;
//			startDate.operator+=(Period(fixedLegFrequency));
//			int j = 0;
//			while (startDate < maturity){
//
//				while (startDate > std::get<1>(matrixRate[j])) { j++; }
//
//				fixedRateFreq.push_back(std::get<2>(matrixRate[j]));
//				startDate.operator+=(Period(fixedLegFrequency));
//			}
//			return fixedRateFreq;
//
//		}
//		
//	private:
//		boost::shared_ptr<IborIndex> floating_index;
//		DayCounter floatingLegDayCounter;
//		Frequency floatingLegFrequency;
//	};
//	public class SwapFixedLeg
//	{
//	public:
//		SwapFixedLeg(){}
//		void setComponent(std::vector<std::tuple<Date, Date, Real>>  FixedRates, DayCounter FixedLegDayCounter, Frequency FixedLegFrequency)
//		{
//			fixedRates = FixedRates; fixedLegDayCounter = FixedLegDayCounter; fixedLegFrequency = FixedLegFrequency;
//		}
//
//#pragma region"Get&Set"
//	
//
//		void SwapFixedLeg::setfixedRates(std::vector<std::tuple<Date, Date, Real>>  fixedRates)
//		{
//			this->fixedRates = fixedRates;
//		}
//
//		void SwapFixedLeg::setfixedLegDayCounter(DayCounter fixedLegDayCounter)
//		{
//			this->fixedLegDayCounter = fixedLegDayCounter;
//		}
//
//	
//
//		std::vector<std::tuple<Date, Date, Real>> SwapFixedLeg::getfixedRates() const
//		{
//			return this->fixedRates;
//		}
//
//		DayCounter SwapFixedLeg::getfixedLegDayCounter() const
//		{
//			return this->fixedLegDayCounter;
//		}
//
//		Frequency SwapFixedLeg::getfixedLegFrequency() const
//		{
//			return this->fixedLegFrequency;
//		}
//
//		void SwapFixedLeg::setfixedLegFrequency(Frequency fixedLegFrequency)
//		{
//			this->fixedLegFrequency;
//		}
//#pragma endregion
//
//		//Fonctions
//		Schedule fixedSchedule(Date settlementDate, Date maturity) const
//		{
//			return Schedule(settlementDate, maturity, Period(fixedLegFrequency),
//				TARGET(), ModifiedFollowing, ModifiedFollowing,
//				DateGeneration::Forward, false);
//		}
//		Leg constructLeg(Date settlementDate, Date maturity, std::vector<double> nominals)
//		{
//			Schedule  schedule(settlementDate, maturity, Period(fixedLegFrequency),
//				TARGET(), ModifiedFollowing, ModifiedFollowing,
//				DateGeneration::Forward, false);
//			return FixedRateLeg(schedule)
//				.withNotionals(nominals)
//				.withCouponRates(this->fixedRatesFreq(fixedRates, settlementDate, maturity, fixedLegFrequency), fixedLegDayCounter, Simple, fixedLegFrequency)
//				.withPaymentAdjustment(ModifiedFollowing);
//		}
//
//		std::vector<Real> fixedRatesFreq(std::vector<std::tuple<Date, Date, Real>> matrixRate, Date settlementDate, Date maturity, Frequency fixedLegFrequency)
//		{
//			std::vector<Real> fixedRateFreq;
//			//int nmbrofPeriode = 12 * Actual360().yearFraction(settlementDate, maturity);
//
//			//int i = 1;
//
//
//			Date startDate = settlementDate;
//			startDate.operator+=(Period(fixedLegFrequency));
//			int j = 0;
//			while (startDate < maturity){
//
//				while (startDate > std::get<1>(matrixRate[j])) { j++; }
//
//				fixedRateFreq.push_back(std::get<2>(matrixRate[j]));
//				startDate.operator+=(Period(fixedLegFrequency));
//			}
//			return fixedRateFreq;
//
//		}
//		
//	private:
//		//Real fixedRate;
//
//		std::vector<std::tuple<Date, Date, Real>> fixedRates;
//		DayCounter fixedLegDayCounter;
//		Frequency fixedLegFrequency;
//
//	};
//	
//
}
