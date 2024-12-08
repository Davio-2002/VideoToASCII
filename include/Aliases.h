#ifndef METRIC_ALIAS_H
#define METRIC_ALIAS_H

// Local headers
#include <PixelToAsciiConverter.h>

/*
    * I shouldn't write the template this way because it violates the KISS template,
    * but I'm experimenting with the language right now, so don't be too hard on me)  
*/

// Metrics
template <class MetricTypes>
using Resolution = MetricTypes;

// Strings and characters
namespace CommonStringAliases {
    using StrView = std::string_view;
    using Str = std::string;
}

namespace FilePaths {
    using namespace CommonStringAliases;
}

namespace AsciiArt {
    using namespace CommonStringAliases;
}



// Smart pointers
using PixelToAsciiConverterPtr = std::shared_ptr<PixelToAsciiConverter>;

#endif
