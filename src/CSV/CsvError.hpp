/*
 * File:   CsvError.hpp
 * Author: juan.garibotti
 *
 * Created on 17 de julio de 2014, 17:44
 */

#ifndef CSVERROR_HPP
#define	CSVERROR_HPP

#include <stdexcept>

namespace csv
{
    class CsvError
        : public std::runtime_error
    {
        public:
            enum Type
            {
                k_fieldCountMismatch,
                k_badEscape,
                k_missingQuote,
                k_misplacedQuote
            };

        private:
            Type m_type;

        public:
            CsvError( Type const& i_type );
    };
}
#endif	/* CSVERROR_HPP */

