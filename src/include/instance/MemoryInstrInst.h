#ifndef WASMVM_INSTANCE_NUMEFICINSTRINST_DEF
#define WASMVM_INSTANCE_NUMEFICINSTRINST_DEF

#include <stdint.h>
#include <instance/InstrInst.h>

typedef struct {
    InstrInst parent;
    uint32_t offset;
    uint32_t align;
} NumericInstrInst;

#endif