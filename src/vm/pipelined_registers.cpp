#ifndef PIPELINE_H
#define PIPELINE_H

#include<bits/stdc++.h>
#include"control_unit_base.h"
#include"vm/registers.h"
using namespace std;

struct piplelined_register{
    uint64_t IF_IDaddress;
    uint64_t IF_IDinstruction;
    uint64_t ID_EXsr1;
    uint64_t ID_EXsr2;
    uint64_t ID_EXimm;
    uint64_t ID_EXop;
    uint64_t ID_EXdes1;
    bool ID_EXtouseimm;
    uint64_t EX_MEMresult;
    uint64_t EX_MEMdes1;
    bool EX_MEMtofetchfrommem;
    uint64_t MEM_WBdes1;
    uint64_t MEM_WBresult;
    bool MEM_WBtowrite;
}