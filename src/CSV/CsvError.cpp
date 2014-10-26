/*
 * File:   CsvError.cpp
 * Author: juan.garibotti
 *
 * Created on 17 de julio de 2014, 17:44
 */

#include "CsvError.hpp"

namespace csv
{
    char const k_description[][54] =
    {
        "Record field count does not match header field count.",
        "Escaped unrecognized character.",
        "Missing closing quote.",
        "Quote found in unquoted field."
    };

    CsvError::CsvError( Type const& i_type )
        : std::runtime_error ( k_description[ i_type ] )
        , m_type ( i_type )
    {}
}