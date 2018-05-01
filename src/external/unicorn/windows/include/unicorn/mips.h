#ifndef UNICORN_MIPS_H
#define UNICORN_MIPS_H

/* Unicorn Emulator Engine */
/* By Nguyen Anh Quynh <aquynh@gmail.com>, 2015 */

#ifdef __cplusplus
extern "C" {
#endif

// GCC MIPS toolchain has a default macro called "mips" which breaks
// compilation
#undef mips

#ifdef _MSC_VER
#pragma warning(disable : 4201)
#endif

//> MIPS registers
typedef enum UC_MIPS_REG {
    UC_MIPS_REG_INVALID = 0,
    //> General purpose registers
    UC_MIPS_REG_PC,

    UC_MIPS_REG_0,
    UC_MIPS_REG_1,
    UC_MIPS_REG_2,
    UC_MIPS_REG_3,
    UC_MIPS_REG_4,
    UC_MIPS_REG_5,
    UC_MIPS_REG_6,
    UC_MIPS_REG_7,
    UC_MIPS_REG_8,
    UC_MIPS_REG_9,
    UC_MIPS_REG_10,
    UC_MIPS_REG_11,
    UC_MIPS_REG_12,
    UC_MIPS_REG_13,
    UC_MIPS_REG_14,
    UC_MIPS_REG_15,
    UC_MIPS_REG_16,
    UC_MIPS_REG_17,
    UC_MIPS_REG_18,
    UC_MIPS_REG_19,
    UC_MIPS_REG_20,
    UC_MIPS_REG_21,
    UC_MIPS_REG_22,
    UC_MIPS_REG_23,
    UC_MIPS_REG_24,
    UC_MIPS_REG_25,
    UC_MIPS_REG_26,
    UC_MIPS_REG_27,
    UC_MIPS_REG_28,
    UC_MIPS_REG_29,
    UC_MIPS_REG_30,
    UC_MIPS_REG_31,

    //> DSP registers
    UC_MIPS_REG_DSPCCOND,
    UC_MIPS_REG_DSPCARRY,
    UC_MIPS_REG_DSPEFI,
    UC_MIPS_REG_DSPOUTFLAG,
    UC_MIPS_REG_DSPOUTFLAG16_19,
    UC_MIPS_REG_DSPOUTFLAG20,
    UC_MIPS_REG_DSPOUTFLAG21,
    UC_MIPS_REG_DSPOUTFLAG22,
    UC_MIPS_REG_DSPOUTFLAG23,
    UC_MIPS_REG_DSPPOS,
    UC_MIPS_REG_DSPSCOUNT,

    //> ACC registers
    UC_MIPS_REG_AC0,
    UC_MIPS_REG_AC1,
    UC_MIPS_REG_AC2,
    UC_MIPS_REG_AC3,

    //> COP registers
    UC_MIPS_REG_CC0,
    UC_MIPS_REG_CC1,
    UC_MIPS_REG_CC2,
    UC_MIPS_REG_CC3,
    UC_MIPS_REG_CC4,
    UC_MIPS_REG_CC5,
    UC_MIPS_REG_CC6,
    UC_MIPS_REG_CC7,

    //> FPU registers
    UC_MIPS_REG_F0,
    UC_MIPS_REG_F1,
    UC_MIPS_REG_F2,
    UC_MIPS_REG_F3,
    UC_MIPS_REG_F4,
    UC_MIPS_REG_F5,
    UC_MIPS_REG_F6,
    UC_MIPS_REG_F7,
    UC_MIPS_REG_F8,
    UC_MIPS_REG_F9,
    UC_MIPS_REG_F10,
    UC_MIPS_REG_F11,
    UC_MIPS_REG_F12,
    UC_MIPS_REG_F13,
    UC_MIPS_REG_F14,
    UC_MIPS_REG_F15,
    UC_MIPS_REG_F16,
    UC_MIPS_REG_F17,
    UC_MIPS_REG_F18,
    UC_MIPS_REG_F19,
    UC_MIPS_REG_F20,
    UC_MIPS_REG_F21,
    UC_MIPS_REG_F22,
    UC_MIPS_REG_F23,
    UC_MIPS_REG_F24,
    UC_MIPS_REG_F25,
    UC_MIPS_REG_F26,
    UC_MIPS_REG_F27,
    UC_MIPS_REG_F28,
    UC_MIPS_REG_F29,
    UC_MIPS_REG_F30,
    UC_MIPS_REG_F31,

    UC_MIPS_REG_FCC0,
    UC_MIPS_REG_FCC1,
    UC_MIPS_REG_FCC2,
    UC_MIPS_REG_FCC3,
    UC_MIPS_REG_FCC4,
    UC_MIPS_REG_FCC5,
    UC_MIPS_REG_FCC6,
    UC_MIPS_REG_FCC7,

    //> AFPR128
    UC_MIPS_REG_W0,
    UC_MIPS_REG_W1,
    UC_MIPS_REG_W2,
    UC_MIPS_REG_W3,
    UC_MIPS_REG_W4,
    UC_MIPS_REG_W5,
    UC_MIPS_REG_W6,
    UC_MIPS_REG_W7,
    UC_MIPS_REG_W8,
    UC_MIPS_REG_W9,
    UC_MIPS_REG_W10,
    UC_MIPS_REG_W11,
    UC_MIPS_REG_W12,
    UC_MIPS_REG_W13,
    UC_MIPS_REG_W14,
    UC_MIPS_REG_W15,
    UC_MIPS_REG_W16,
    UC_MIPS_REG_W17,
    UC_MIPS_REG_W18,
    UC_MIPS_REG_W19,
    UC_MIPS_REG_W20,
    UC_MIPS_REG_W21,
    UC_MIPS_REG_W22,
    UC_MIPS_REG_W23,
    UC_MIPS_REG_W24,
    UC_MIPS_REG_W25,
    UC_MIPS_REG_W26,
    UC_MIPS_REG_W27,
    UC_MIPS_REG_W28,
    UC_MIPS_REG_W29,
    UC_MIPS_REG_W30,
    UC_MIPS_REG_W31,

    UC_MIPS_REG_HI,
    UC_MIPS_REG_LO,

    UC_MIPS_REG_P0,
    UC_MIPS_REG_P1,
    UC_MIPS_REG_P2,

    UC_MIPS_REG_MPL0,
    UC_MIPS_REG_MPL1,
    UC_MIPS_REG_MPL2,

    UC_MIPS_REG_ENDING, // <-- mark the end of the list or registers

    // alias registers
    UC_MIPS_REG_ZERO = UC_MIPS_REG_0,
    UC_MIPS_REG_AT = UC_MIPS_REG_1,
    UC_MIPS_REG_V0 = UC_MIPS_REG_2,
    UC_MIPS_REG_V1 = UC_MIPS_REG_3,
    UC_MIPS_REG_A0 = UC_MIPS_REG_4,
    UC_MIPS_REG_A1 = UC_MIPS_REG_5,
    UC_MIPS_REG_A2 = UC_MIPS_REG_6,
    UC_MIPS_REG_A3 = UC_MIPS_REG_7,
    UC_MIPS_REG_T0 = UC_MIPS_REG_8,
    UC_MIPS_REG_T1 = UC_MIPS_REG_9,
    UC_MIPS_REG_T2 = UC_MIPS_REG_10,
    UC_MIPS_REG_T3 = UC_MIPS_REG_11,
    UC_MIPS_REG_T4 = UC_MIPS_REG_12,
    UC_MIPS_REG_T5 = UC_MIPS_REG_13,
    UC_MIPS_REG_T6 = UC_MIPS_REG_14,
    UC_MIPS_REG_T7 = UC_MIPS_REG_15,
    UC_MIPS_REG_S0 = UC_MIPS_REG_16,
    UC_MIPS_REG_S1 = UC_MIPS_REG_17,
    UC_MIPS_REG_S2 = UC_MIPS_REG_18,
    UC_MIPS_REG_S3 = UC_MIPS_REG_19,
    UC_MIPS_REG_S4 = UC_MIPS_REG_20,
    UC_MIPS_REG_S5 = UC_MIPS_REG_21,
    UC_MIPS_REG_S6 = UC_MIPS_REG_22,
    UC_MIPS_REG_S7 = UC_MIPS_REG_23,
    UC_MIPS_REG_T8 = UC_MIPS_REG_24,
    UC_MIPS_REG_T9 = UC_MIPS_REG_25,
    UC_MIPS_REG_K0 = UC_MIPS_REG_26,
    UC_MIPS_REG_K1 = UC_MIPS_REG_27,
    UC_MIPS_REG_GP = UC_MIPS_REG_28,
    UC_MIPS_REG_SP = UC_MIPS_REG_29,
    UC_MIPS_REG_FP = UC_MIPS_REG_30,
    UC_MIPS_REG_S8 = UC_MIPS_REG_30,
    UC_MIPS_REG_RA = UC_MIPS_REG_31,

    UC_MIPS_REG_HI0 = UC_MIPS_REG_AC0,
    UC_MIPS_REG_HI1 = UC_MIPS_REG_AC1,
    UC_MIPS_REG_HI2 = UC_MIPS_REG_AC2,
    UC_MIPS_REG_HI3 = UC_MIPS_REG_AC3,

    UC_MIPS_REG_LO0 = UC_MIPS_REG_HI0,
    UC_MIPS_REG_LO1 = UC_MIPS_REG_HI1,
    UC_MIPS_REG_LO2 = UC_MIPS_REG_HI2,
    UC_MIPS_REG_LO3 = UC_MIPS_REG_HI3,
} UC_MIPS_REG;

#ifdef __cplusplus
}
#endif

#endif
