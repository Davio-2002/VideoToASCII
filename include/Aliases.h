#ifndef METRIC_ALIAS_H
#define METRIC_ALIAS_H

// Local headers
#include <string_view>
#include <string>
#include <memory>
/*
    * I shouldn't write the template this way because it violates the KISS template,
    * but I'm experimenting with the language right now, so don't be too hard on me )
*/

// Metrics
template <class MetricTypes>
using ResolutionAlias = MetricTypes;

// Strings and characters
namespace CommonStringAliases {
    using StringView = std::string_view;
    using String = std::string;
}

namespace FilePathsAliases = CommonStringAliases;
namespace AsciiArtAliases = CommonStringAliases;

// Smart pointers
class PixelToAsciiConverter;
using PixelToAsciiConverterPtr = std::shared_ptr<PixelToAsciiConverter>;

#endif
