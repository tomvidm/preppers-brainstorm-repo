#include "ValueField.h"

namespace common {
    ValueField::ValueField(int val)
    : intValue(val), fieldType(FieldType::INT) {;}

    ValueField::ValueField(uint val)
    : uintValue(val), fieldType(FieldType::UINT) {;}

    ValueField::ValueField(float val)
    : floatValue(val), fieldType(FieldType::FLOAT) {;}

    ValueField::ValueField(std::string val)
    : string(val), fieldType(FieldType::STRING) {;}

    ValueField::ValueField(int* valPtr)
    : intValuePtr(valPtr), fieldType(FieldType::INT_PTR) {;}

    ValueField::ValueField(uint* valPtr)
    : uintValuePtr(valPtr), fieldType(FieldType::UINT_PTR) {;}

    ValueField::ValueField(float* valPtr)
    : floatValuePtr(valPtr), fieldType(FieldType::FLOAT_PTR) {;}

    ValueField::ValueField(std::string* valPtr)
    : stringPtr(valPtr), fieldType(FieldType::STRING_PTR) {;}

    std::string ValueField::get() const
    {
        switch (fieldType)
        {
            case FieldType::INT: return std::to_string(intValue);
            case FieldType::UINT: return std::to_string(uintValue);
            case FieldType::FLOAT:
            {
                std::stringstream ss;
                ss << std::fixed << std::setprecision(floatPrecision) << floatValue;
                return ss.str();
            }
            case FieldType::STRING: return string;
            case FieldType::INT_PTR: return std::to_string(*intValuePtr);
            case FieldType::UINT_PTR: return std::to_string(*uintValuePtr);
            case FieldType::FLOAT_PTR: 
            {
                std::stringstream ss;
                ss << std::fixed << std::setprecision(floatPrecision) << *floatValuePtr;
                return ss.str();
            }
            case FieldType::STRING_PTR: return *stringPtr;
            default: return "UNKNOWN TYPE";
        }
    }
}