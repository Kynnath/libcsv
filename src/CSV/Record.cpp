/*
 * File:   Record.cpp
 * Author: juan.garibotti
 *
 * Created on 16 de julio de 2014, 16:31
 */

#include "Record.hpp"

namespace csv
{
    Record::Record( std::vector<std::string> const& i_fields )
        : m_fields { i_fields }
    {}

    std::size_t Record::FieldCount() const
    {
        return m_fields.size();
    }

    std::string const& Record::GetRecord( std::size_t const& i_line ) const
    {
        return m_fields[ i_line ];
    }

    std::string const& Record::operator[]( std::size_t const& i_line ) const
    {
        return GetRecord( i_line );
    }

    std::vector<std::string>::const_iterator Record::begin() const
    {
        return m_fields.begin();
    }

    std::vector<std::string>::const_iterator Record::end() const
    {
        return m_fields.end();
    }
}