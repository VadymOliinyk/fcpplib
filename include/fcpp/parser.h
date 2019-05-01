#ifndef PARSER_H
#define  PARSER_H

#include <vector>

#include "fcpp/market.h"
#include "nlohmann/json.hpp"

using namespace nlohmann;


/// Returns vector of native market objects.
///
vector <Market> get_market_objects(json json_obj);


#endif // PARSER_H
