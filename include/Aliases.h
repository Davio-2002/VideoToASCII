#ifndef METRIC_ALIAS_H
#define METRIC_ALIAS_H

#include <PixelToAsciiConverter.h>

/* I shouldn't write the template this way because it violates the KISS template,
 * but I'm experimenting with the language right now, so don't be too hard on me) */

// Metrics
template <class MetricTypes>
using Resolution = MetricTypes;

template <class StringType>
using Path = StringType;

// Strings and characters
using StrView = std::string_view;
using Str = std::string;

// Smart pointers
using PixelToAsciiConverterPtr = std::shared_ptr<PixelToAsciiConverter>;

#endif
