/*
 * File:   Table.cpp
 * Author: juan.garibotti
 *
 * Created on 16 de julio de 2014, 16:30
 */

#include "Table.hpp"

#include <fstream>
#include "CsvError.hpp"

namespace csv
{
    struct CsvData;
    typedef void(*StateFunction)( CsvData& );

    struct CsvData
    {
        std::ifstream m_csvFile;
        std::vector<Record> m_records;
        std::map<std::string,int> m_fieldNames;
        StateFunction m_state;
        std::vector<std::string> m_currentRecord;
        std::string m_currentField;
        char m_currentCharacter;

        CsvData( std::string const& i_csvFile );
    };

    static void Unquoted( CsvData & io_data );
    static void Quoted( CsvData & io_data );

    static void ReadRecord( CsvData & io_data )
    {
        if ( io_data.m_csvFile.get( io_data.m_currentCharacter ) )
        {
            if ( io_data.m_currentCharacter == ',' )
            {
                io_data.m_currentRecord.push_back( io_data.m_currentField );
            }
            else if ( io_data.m_currentCharacter == '\n' )
            {
                io_data.m_currentRecord.push_back( io_data.m_currentField );
                io_data.m_records.push_back( io_data.m_currentRecord );
                io_data.m_currentRecord.clear();
                if ( io_data.m_records.back().FieldCount() != io_data.m_records.front().FieldCount() )
                {
                    throw CsvError{ CsvError::k_fieldCountMismatch }; // Field count differs from first field count
                }
            }
            else if ( io_data.m_currentCharacter == '"' )
            {
                io_data.m_state = Quoted;
            }
            else
            {
                io_data.m_state = Unquoted;
            }
        }
        else
        {
            io_data.m_currentRecord.push_back( io_data.m_currentField );
            io_data.m_records.push_back( io_data.m_currentRecord );
            if ( io_data.m_records.back().FieldCount() == io_data.m_records.front().FieldCount() )
            {
                io_data.m_state = nullptr;
            }
            else
            {
                throw CsvError{ CsvError::k_fieldCountMismatch };; // Field count differs from first field count
            }
        }
    }

    static void Quoted( CsvData & io_data )
    {
        if ( io_data.m_csvFile.get( io_data.m_currentCharacter ) )
        {
            if ( io_data.m_currentCharacter == '"' )
            {
                if ( io_data.m_csvFile.get( io_data.m_currentCharacter ) )
                {
                    if ( io_data.m_currentCharacter == ',' )
                    {
                        io_data.m_currentRecord.push_back( io_data.m_currentField );
                        io_data.m_currentField.clear();
                        io_data.m_state = ReadRecord;
                    }
                    else if ( io_data.m_currentCharacter == '\n' )
                    {
                        io_data.m_currentRecord.push_back( io_data.m_currentField );
                        io_data.m_currentField.clear();
                        io_data.m_records.push_back( io_data.m_currentRecord );
                        io_data.m_currentRecord.clear();
                        if ( io_data.m_records.back().FieldCount() != io_data.m_records.front().FieldCount() )
                        {
                            throw CsvError{ CsvError::k_fieldCountMismatch };; // Field count differs from first field count
                        }
                        io_data.m_state = ReadRecord;
                    }
                    else if ( io_data.m_currentCharacter == '"' )
                    {
                        io_data.m_currentField += io_data.m_currentCharacter;
                    }
                    else
                    {
                        throw CsvError{ CsvError::k_badEscape }; // Escaped unspecified character
                    }
                }
                else
                {
                    io_data.m_currentRecord.push_back( io_data.m_currentField );
                    io_data.m_currentField.clear();
                    io_data.m_records.push_back( io_data.m_currentRecord );
                    io_data.m_currentRecord.clear();
                    if ( io_data.m_records.back().FieldCount() != io_data.m_records.front().FieldCount() )
                    {
                        throw CsvError{ CsvError::k_fieldCountMismatch }; // Field count differs from first field count
                    }
                    io_data.m_state = nullptr;
                }
            }
            else
            {
                io_data.m_currentField += io_data.m_currentCharacter;
            }
        }
        else
        {
            throw CsvError{ CsvError::k_missingQuote }; // Quoted field missing closing quote
        }
    }

    static void Unquoted( CsvData & io_data )
    {
        io_data.m_currentField += io_data.m_currentCharacter;
        if ( io_data.m_csvFile.get( io_data.m_currentCharacter ) )
        {
            if ( io_data.m_currentCharacter == ',' )
            {
                io_data.m_currentRecord.push_back( io_data.m_currentField );
                io_data.m_currentField.clear();
                io_data.m_state = ReadRecord;
            }
            else if ( io_data.m_currentCharacter == '\n' )
            {
                io_data.m_currentRecord.push_back( io_data.m_currentField );
                io_data.m_currentField.clear();
                io_data.m_records.push_back( io_data.m_currentRecord );
                io_data.m_currentRecord.clear();
                if ( io_data.m_records.back().FieldCount() != io_data.m_records.front().FieldCount() )
                {
                    throw CsvError{ CsvError::k_fieldCountMismatch }; // Field count differs from first field count
                }
                io_data.m_state = ReadRecord;
            }
            else if ( io_data.m_currentCharacter == '"')
            {
                throw CsvError{ CsvError::k_misplacedQuote };; // Added '"' in the middle of unquoted string
            }
        }
        else
        {
            io_data.m_currentRecord.push_back( io_data.m_currentField );
            io_data.m_currentField.clear();
            io_data.m_records.push_back( io_data.m_currentRecord );
            io_data.m_currentRecord.clear();
            if ( io_data.m_records.back().FieldCount() != io_data.m_records.front().FieldCount() )
            {
                throw CsvError{ CsvError::k_fieldCountMismatch }; // Field count differs from first field count
            }
            io_data.m_state = nullptr;
        }
    }

    CsvData::CsvData( std::string const& i_csvFilename )
        : m_csvFile { i_csvFilename }
        , m_state { ReadRecord }
    {}

    Table::Table( std::string const& i_filename )
    {
        CsvData csvData { i_filename };

        if ( !csvData.m_csvFile.good() )
        {
            throw 0;
        }

        while ( csvData.m_state )
        {
            csvData.m_state( csvData );
        }

        std::swap( m_records, csvData.m_records );
        std::swap( m_fieldNames, csvData.m_fieldNames );
    }

    Record const& Table::GetRecord( std::size_t const& i_line ) const
    {
        return m_records[ i_line ];
    }

    Record const& Table::operator[]( std::size_t const& i_line ) const
    {
        return GetRecord( i_line );
    }

    std::vector<Record>::const_iterator Table::begin() const
    {
        return m_records.begin();
    }

    std::vector<Record>::const_iterator Table::end() const
    {
        return m_records.end();
    }
}