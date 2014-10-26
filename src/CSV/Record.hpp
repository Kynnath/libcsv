/*
 * File:   Record.hpp
 * Author: juan.garibotti
 *
 * Created on 16 de julio de 2014, 16:31
 */

#ifndef RECORD_HPP
#define	RECORD_HPP

#include <string>
#include <vector>

namespace csv
{
    class Record
    {
        std::vector<std::string> m_fields;

        public:
            Record() = default;
            Record( std::vector<std::string> const& i_fields );
            std::size_t FieldCount() const;
            std::string const& GetRecord( std::size_t const& i_line ) const;
            std::string const& operator[]( std::size_t const& i_line ) const;
            std::vector<std::string>::const_iterator begin() const;
            std::vector<std::string>::const_iterator end() const;
    };
}

#endif	/* RECORD_HPP */

