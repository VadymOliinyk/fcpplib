#ifndef PARSER_H
#define  PARSER_H

#include <vector>

#include "fairlay/market.h"
#include "nlohmann/json.hpp"

using namespace nlohmann;

namespace fairlay {
/// Returns vector of native market objects.
///
vector <Market> get_market_objects(json json_obj);


} // namespace fairlay

#endif // PARSER_H
