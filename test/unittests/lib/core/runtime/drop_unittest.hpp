#include <skypat/skypat.h>

#define _Bool bool
extern "C" {
#include <core/Runtime.h>
#include <dataTypes/Value.h>
}
#undef _Bool

SKYPAT_F(Runtime_drop, regular)
{
    Stack* stack = new_Stack((void (*)(void*))free_Value);
    int32_t check_value;

    Value *value_1 = new_i32Value(3);
    stack->entries->push(stack->entries, value_1);

    check_value = runtime_drop(stack);

    EXPECT_EQ(check_value, 0);

    // clean
    free_Stack(stack);
}
