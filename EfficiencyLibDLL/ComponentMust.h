#ifndef COMPONENTMUST_H
#define COMPONENTMUST_H

//
// the only header you need to use QuantLib
#include <ql/quantlib.hpp>
#include <tuple>
#ifdef BOOST_MSVC
/* Uncomment the following lines to unmask floating-point
exceptions. Warning: unpredictable results can arise...

See http://www.wilmott.com/messageview.cfm?catid=10&threadid=9481
Is there anyone with a definitive word about this?
*/
// #include <float.h>
// namespace { unsigned int u = _controlfp(_EM_INEXACT, _MCW_EM); }
#endif



#include <boost/timer.hpp>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "DllHeader.h"
using namespace QuantLib;

#ifdef BOOST_MSVC
#  ifdef QL_ENABLE_THREAD_SAFE_OBSERVER_PATTERN
#    include <ql/auto_link.hpp>
#    define BOOST_LIB_NAME boost_system
#    include <boost/config/auto_link.hpp>
#    undef BOOST_LIB_NAME
#    define BOOST_LIB_NAME boost_thread
#    include <boost/config/auto_link.hpp>
#    undef BOOST_LIB_NAME
#  endif
#endif

#if defined(QL_ENABLE_SESSIONS)
namespace QuantLib {

	Integer sessionId() { return 0; }

}
#endif


using namespace std;






public class EFFICIEBCYLIBDLL_API  ComponentMust
{
public:
	ComponentMust();

	Frequency eff_convert_frequency(char freq_char) const;

	DayCounter eff_convert_basis(std::string basis) const;

	Date eff_convert_date(std::string dateString) const;

	Rate eff_convert_rate(std::string rateString) const;

	int eff_freq_int(Frequency freq) const;

	std::vector<std::tuple<Date, Date, Rate>> eff_matice_rate(vector<vector<string>> matriceString);

	vector<std::tuple<Date, Date, Real>> eff_matice_spread(vector<vector<string>> matriceString);


};

#endif