#ifndef DLLHEADER_H
#define DLLHEADER_H

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

using namespace QuantLib;
using namespace std;


/* Drective use to export all class and STL objects used in this DLL project*/
#ifdef EFFICIEBCYLIBDLL_EXPORTS
#define EFFICIEBCYLIBDLL_API __declspec(dllexport) 
#    define EXPIMP_TEMPLATE
#else
#define EFFICIEBCYLIBDLL_API __declspec(dllimport) 
#    define EXPIMP_TEMPLATE extern
#endif


EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API std::allocator<char>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API std::basic_string<char, std::char_traits<char>, std::allocator<char> >;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API vector<std::string>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API vector<vector<std::string>>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API vector<Rate>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API vector<std::tuple<Date, Date, Rate>>;

EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API std::vector<Real>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API std::vector<std::tuple<Date, Date, Spread>>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API std::vector<boost::shared_ptr<QuantLib::CashFlow>, std::allocator<boost::shared_ptr<QuantLib::CashFlow>>>;
EXPIMP_TEMPLATE template class EFFICIEBCYLIBDLL_API boost::shared_ptr<QuantLib::SimpleQuote>;

#endif