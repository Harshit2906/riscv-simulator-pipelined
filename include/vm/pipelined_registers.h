/**
 * @file pipelined_registers.h
 * @brief Declaration of the Pilelined_Registers class and related helper functions.
 * @author Nimish Agarwal, https://github.com/Nimish-Agarwal-2006
 */

#ifndef PIPELINED_REGISTERS_H
#define PIPELINED_REGISTERS_H
#include <cstdint>
#include <vector>
#include <array>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stdexcept>
using namespace std;
class Pipelined_Registers {
public:
    // Constructor
    Pipelined_Registers();

    // Reset all registers to default values
    void Reset();

    // General Purpose Registers (GPR) access
    uint64_t ReadGpr(size_t reg) const;
    void WriteGpr(size_t reg, uint64_t value);
    std::vector<uint64_t> GetGprValues() const;

    // Floating Point Registers (FPR) access
    uint64_t ReadFpr(size_t reg) const;
    void WriteFpr(size_t reg, uint64_t value);
    std::vector<uint64_t> GetFprValues() const;

    // Control and Status Registers (CSR) access
    uint64_t ReadCsr(size_t reg) const;
    void WriteCsr(size_t reg, uint64_t value);

    // Modify register by name
    void ModifyRegister(const std::string &reg_name, uint64_t value);

private:
    // Storage for pipeline registers
    std::array<uint64_t, 5> pipgpr_{};   // General Purpose Registers
    std::array<uint64_t, 5> pipfpr_{};   // Floating Point Registers
    std::array<uint64_t, 5> pipcsr_{};   // CSR Registers
};

// Valid registers sets
extern const std::unordered_set<std::string> valid_general_purpose_registers;
extern const std::unordered_set<std::string> valid_floating_point_registers;
extern const std::unordered_set<std::string> valid_csr_registers;

// Mapping CSR names to addresses
extern const std::unordered_map<std::string, int> csr_to_address;

// Helper validation functions
bool IsValidGeneralPurposeRegister(const std::string &reg);
bool IsValidFloatingPointRegister(const std::string &reg);
bool IsValidCsr(const std::string &reg);

#endif // PIPELINED_REGISTERS_H
