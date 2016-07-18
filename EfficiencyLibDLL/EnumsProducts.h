#include <string>
#include <iostream>
#include "DllHeader.h"



using namespace System;
namespace  EfficiencyProduct{

	enum class EFFICIEBCYLIBDLL_API SwaptionStyle {
		EURO = 0,
		AMER = 1,
		BERM = 2,
	};

	enum class EFFICIEBCYLIBDLL_API EfficiencyTypeProduct {
		SWAP = 0,
		CAPFLOOR = 1,
		SWAPTION = 2,
	};
	enum class EFFICIEBCYLIBDLL_API EfficiencyModelProduct {
		EFFICIENCY_LMM = 0,
		QUANTLIB_LMM = 1,
		QUANTLIB_BLACKFT = 2,
		QUANTLIB_HULLWHITE = 3,
	};
	inline std::string  modelProductToString(EfficiencyModelProduct modelProd)
	{
		// return Enum::GetName(typeProd::typeid, 0);
		switch (modelProd)
		{
		case EfficiencyModelProduct::EFFICIENCY_LMM:   return "EFFICIENCY_LMM";
		case EfficiencyModelProduct::QUANTLIB_LMM:   return "QUANTLIB_LMM";
		case EfficiencyModelProduct::QUANTLIB_BLACKFT: return "QUANTLIB_BLACKFT";
		case EfficiencyModelProduct::QUANTLIB_HULLWHITE: return "QUANTLIB_HULLWHITE";
		default:      return "[Unknown Product_type]";
		}
	}
	inline EfficiencyModelProduct  stringToModelProduct(std::string modelProduct)
	{

		if (modelProduct == "EFFICIENCY_LMM")
			return EfficiencyModelProduct::EFFICIENCY_LMM;
		if (modelProduct == "QUANTLIB_LMM")
			return EfficiencyModelProduct::QUANTLIB_LMM;
		if (modelProduct == "QUANTLIB_BLACKFT")
			return EfficiencyModelProduct::QUANTLIB_BLACKFT;
		if (modelProduct == "QUANTLIB_HULLWHITE")
			return EfficiencyModelProduct::QUANTLIB_HULLWHITE;

		return EfficiencyModelProduct::QUANTLIB_BLACKFT;
	}

	inline std::string  typeProductToString(EfficiencyTypeProduct typeProd)
	  {
		 // return Enum::GetName(typeProd::typeid, 0);

		  switch (typeProd)
		  {
		  case EfficiencyTypeProduct::SWAP:   return "SWAP";
		  case EfficiencyTypeProduct::CAPFLOOR:   return "CAPFLOOR";
		  case EfficiencyTypeProduct::SWAPTION: return "SWAPTION";
		  default:      return "[Unknown Product_type]";
		  }
	  }
	inline EfficiencyTypeProduct  stringToTypeProduct(std::string typeProduct)
	 {
		 
		 if (typeProduct == "SWAP")
			 return EfficiencyTypeProduct::SWAP;
		 if (typeProduct == "CAPFLOOR")
			 return EfficiencyTypeProduct::CAPFLOOR;
		 if (typeProduct == "SWAPTION")
			 return EfficiencyTypeProduct::SWAPTION;

		 return EfficiencyTypeProduct::SWAP;
	 }


	inline std::string  typeProductToString(SwaptionStyle swaptionStyle)
	{
		switch (swaptionStyle)
		{
		case SwaptionStyle::EURO:   return "EURO";
		case SwaptionStyle::AMER:   return "AMER";
		case SwaptionStyle::BERM: return "BERM";
		default:      return "[Unknown Product_type]";
		}
	}
	inline SwaptionStyle  stringToSwaptionStyle(std::string style)
	{

		if (style == "EURO")
			return SwaptionStyle::EURO;
		if (style == "AMER")
			return SwaptionStyle::AMER;
		if (style == "BERM")
			return SwaptionStyle::BERM;

		return SwaptionStyle::EURO;
	}

		/* switch (typeProduct)
		 {
		 case "MYSWAP":
			 return typrProd;
		 case  "MYCAPFLOOR";
			 return typrProd;
		 case  "MYSWAPTION";
			 return typrProd;
		 default:      return "[Unknown Product_type]";
		 }
	 }*/
}