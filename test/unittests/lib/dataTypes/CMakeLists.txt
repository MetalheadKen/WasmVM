macro(add_dataTypes_unittest unittest)
    add_unittest(${unittest} lib/dataTypes/)
endmacro(add_dataTypes_unittest unittest)

add_dataTypes_unittest(FuncType_unittest)
add_dataTypes_unittest(Value_unittest)
add_dataTypes_unittest(stack_type_unittest)
add_dataTypes_unittest(vector_type_unittest)