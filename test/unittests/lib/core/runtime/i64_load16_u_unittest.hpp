#include <skypat/skypat.h>
#define _Bool bool
extern "C" {
#include <dataTypes/Value.h>
#include <core/Runtime.h>
#include <instance/MemInst.h>
#include <string.h>
#include <stdint.h>
}
#undef _Bool

SKYPAT_F(runtime_i64_load16_u, regular)
{
    // Prepare
    Stack* stack = new_Stack((void (*)(void*))free_Value);
    MemInst* memory = new_MemInst();
    memory->max = 1;
    int64_t data[] = { 0, 1, 4, 16, 64, 256, 518, 1040
                       -1, -4, -16, -64, -256, -518, -1040
                     };
    int32_t dataSize = sizeof(data) / sizeof(data[0]);
    uint32_t byteLen = sizeof(data);
    uint32_t offset = 4 * sizeof(int64_t);
    uint8_t* bytePtr = (uint8_t*) data;
    uint8_t zero = 0;

    for(int32_t lop = 0; lop < offset; lop++) {
        memory->data->push_back(memory->data, (const void *) &zero);
    }
    for(int32_t lop = 0; lop < byteLen; lop++) {
        memory->data->push_back(memory->data, (const void *) (bytePtr + lop));
    }
    for(uint8_t lop = 0; lop < dataSize; lop++) {
        // Set load location
        stack->entries->push(stack->entries, new_i32Value(lop * sizeof(int64_t)));
        // Run
        runtime_i64_load16_u(stack, memory, offset, 0);
        // Check
        Value *check = NULL;
        stack->entries->pop(stack->entries, (void**) &check);
        EXPECT_EQ(check->value.i64, (uint16_t) data[lop]);
        // Clean
        free_Value(check);
    }
    // error check
    stack->entries->push(stack->entries, new_i32Value(65540));
    int ret = runtime_i64_load16_u(stack, memory, offset, 0);
    EXPECT_EQ(ret, -1);
    // clean datas
    free_MemInst(memory);
    free_Stack(stack);
}
