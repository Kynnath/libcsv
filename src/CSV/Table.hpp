/*
 * File:   Table.hpp
 * Author: juan.garibotti
 *
 * Created on 16 de julio de 2014, 16:30
 */

#ifndef TABLE_HPP
#define	TABLE_HPP

#include <map>
#include <string>
#include <vector>
#include "Record.hpp"

namespace csv
{
    class Table
    {
        std::vector<Record> m_records;
        std::map<std::string,int> m_fieldNames;

        public:
            Table() = default;
            Table( std::string const& i_filename );
            Record const& GetRecord( std::size_t const& i_line ) const;
            Record const& operator[]( std::size_t const& i_line ) const;
            std::vector<Record>::const_iterator begin() const;
            std::vector<Record>::const_iterator end() const;
    };
}

#endif	/* TABLE_HPP */

