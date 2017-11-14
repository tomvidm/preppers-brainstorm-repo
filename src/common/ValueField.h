#ifndef VALUEFIELD_H
#define VALUEFIELD_H

#include <string>
#include <sstream>
#include <iomanip>

namespace common {

    enum class FieldType
    {
        INT,
        UINT,
        FLOAT,
        STRING,
        INT_PTR,
        UINT_PTR,
        FLOAT_PTR,
        STRING_PTR
    };

    typedef unsigned int uint;

/*
    The ValueField object represents a field with variable data type. It is used by DebugLine
    to allow for construction of lines with different value types, including pointers to variables
    so that a DebugLine can be used in realtime debug output.
    This class is hacky and probably not well designed.
*/

    class ValueField
    {
    public:
        ValueField(int);
        ValueField(uint);
        ValueField(float);
        ValueField(std::string);
        ValueField(int*);
        ValueField(uint*);
        ValueField(float*);
        ValueField(std::string*);

        std::string get() const;
    private:
        FieldType fieldType;

        unsigned int fieldWidth = 0;
        unsigned int floatPrecision = 2;
        
        std::string string;
        union {
            int intValue;
            uint uintValue;
            float floatValue;
            int* intValuePtr;
            uint* uintValuePtr;
            float* floatValuePtr;
            std::string* stringPtr;
        };
    };
}

#endif