#include "type.h"

void preprocess(f64* memory, i64 mem_size, cpu_t *cpu)
{
    for (i64 i = 0; i < mem_size; i++)
    {
        if (memory[i] == "")
        {
            memory[i] = 0.0;
        }
    }
}
