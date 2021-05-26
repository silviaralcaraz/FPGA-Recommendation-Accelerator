#pragma once
#include <ap_int.h>

//////////////////////////////   TEMPLATE START  //////////////////////////////

// #define AXI_WIDTH_PLRAM 32
#define AXI_WIDTH_HBM 32
// #define AXI_WIDTH_DDR 32

#define INT_BITS 32
// #define INTS_PER_AXI_PLRAM 1
#define INTS_PER_AXI_HBM 1
// #define INTS_PER_AXI_DDR 1

// #define PLRAM_BANK_NUM 4
#define HBM_BANK_NUM 32
// #define DDR_BANK 2

#define TABLE_NUM 32

// #define ACCESS_IDX_SIZE 84
// #define PADDED_ACCESS_IDX_SIZE 84
// #define AXI_PADDED_ACCESS_IDX_SIZE 84

#define TABLE_NUM_HBM 32
// #define TABLE_NUM_DDR 4
// #define TABLE_NUM_PLRAM 16

/////////////////////////   HBM   ///////////////////////// 
// alignment of tables to HBM: 
// table 0 ~ 31 -> HBM 0 ~ 31
// table 32 ~ 63 -> HBM 0 ~ 31

#define DATA_SIZE_HBM_0 16
#define PADDED_SIZE_HBM_0 16
#define AXI_PADDED_SIZE_HBM_0 16
#define TABLE_SIZE_HBM_0 100000
#define DATA_SIZE_HBM_1 16
#define PADDED_SIZE_HBM_1 16
#define AXI_PADDED_SIZE_HBM_1 16
#define TABLE_SIZE_HBM_1 100000
#define DATA_SIZE_HBM_2 16
#define PADDED_SIZE_HBM_2 16
#define AXI_PADDED_SIZE_HBM_2 16
#define TABLE_SIZE_HBM_2 100000
#define DATA_SIZE_HBM_3 16
#define PADDED_SIZE_HBM_3 16
#define AXI_PADDED_SIZE_HBM_3 16
#define TABLE_SIZE_HBM_3 100000
#define DATA_SIZE_HBM_4 16
#define PADDED_SIZE_HBM_4 16
#define AXI_PADDED_SIZE_HBM_4 16
#define TABLE_SIZE_HBM_4 100000
#define DATA_SIZE_HBM_5 16
#define PADDED_SIZE_HBM_5 16
#define AXI_PADDED_SIZE_HBM_5 16
#define TABLE_SIZE_HBM_5 100000
#define DATA_SIZE_HBM_6 16
#define PADDED_SIZE_HBM_6 16
#define AXI_PADDED_SIZE_HBM_6 16
#define TABLE_SIZE_HBM_6 100000
#define DATA_SIZE_HBM_7 16
#define PADDED_SIZE_HBM_7 16
#define AXI_PADDED_SIZE_HBM_7 16
#define TABLE_SIZE_HBM_7 100000
#define DATA_SIZE_HBM_8 16
#define PADDED_SIZE_HBM_8 16
#define AXI_PADDED_SIZE_HBM_8 16
#define TABLE_SIZE_HBM_8 100000
#define DATA_SIZE_HBM_9 16
#define PADDED_SIZE_HBM_9 16
#define AXI_PADDED_SIZE_HBM_9 16
#define TABLE_SIZE_HBM_9 100000
#define DATA_SIZE_HBM_10 16
#define PADDED_SIZE_HBM_10 16
#define AXI_PADDED_SIZE_HBM_10 16
#define TABLE_SIZE_HBM_10 100000
#define DATA_SIZE_HBM_11 16
#define PADDED_SIZE_HBM_11 16
#define AXI_PADDED_SIZE_HBM_11 16
#define TABLE_SIZE_HBM_11 100000
#define DATA_SIZE_HBM_12 16
#define PADDED_SIZE_HBM_12 16
#define AXI_PADDED_SIZE_HBM_12 16
#define TABLE_SIZE_HBM_12 100000
#define DATA_SIZE_HBM_13 16
#define PADDED_SIZE_HBM_13 16
#define AXI_PADDED_SIZE_HBM_13 16
#define TABLE_SIZE_HBM_13 100000
#define DATA_SIZE_HBM_14 16
#define PADDED_SIZE_HBM_14 16
#define AXI_PADDED_SIZE_HBM_14 16
#define TABLE_SIZE_HBM_14 100000
#define DATA_SIZE_HBM_15 16
#define PADDED_SIZE_HBM_15 16
#define AXI_PADDED_SIZE_HBM_15 16
#define TABLE_SIZE_HBM_15 100000
#define DATA_SIZE_HBM_16 16
#define PADDED_SIZE_HBM_16 16
#define AXI_PADDED_SIZE_HBM_16 16
#define TABLE_SIZE_HBM_16 100000
#define DATA_SIZE_HBM_17 16
#define PADDED_SIZE_HBM_17 16
#define AXI_PADDED_SIZE_HBM_17 16
#define TABLE_SIZE_HBM_17 100000
#define DATA_SIZE_HBM_18 16
#define PADDED_SIZE_HBM_18 16
#define AXI_PADDED_SIZE_HBM_18 16
#define TABLE_SIZE_HBM_18 100000
#define DATA_SIZE_HBM_19 16
#define PADDED_SIZE_HBM_19 16
#define AXI_PADDED_SIZE_HBM_19 16
#define TABLE_SIZE_HBM_19 100000
#define DATA_SIZE_HBM_20 16
#define PADDED_SIZE_HBM_20 16
#define AXI_PADDED_SIZE_HBM_20 16
#define TABLE_SIZE_HBM_20 100000
#define DATA_SIZE_HBM_21 16
#define PADDED_SIZE_HBM_21 16
#define AXI_PADDED_SIZE_HBM_21 16
#define TABLE_SIZE_HBM_21 100000
#define DATA_SIZE_HBM_22 16
#define PADDED_SIZE_HBM_22 16
#define AXI_PADDED_SIZE_HBM_22 16
#define TABLE_SIZE_HBM_22 100000
#define DATA_SIZE_HBM_23 16
#define PADDED_SIZE_HBM_23 16
#define AXI_PADDED_SIZE_HBM_23 16
#define TABLE_SIZE_HBM_23 100000
#define DATA_SIZE_HBM_24 16
#define PADDED_SIZE_HBM_24 16
#define AXI_PADDED_SIZE_HBM_24 16
#define TABLE_SIZE_HBM_24 100000
#define DATA_SIZE_HBM_25 16
#define PADDED_SIZE_HBM_25 16
#define AXI_PADDED_SIZE_HBM_25 16
#define TABLE_SIZE_HBM_25 100000
#define DATA_SIZE_HBM_26 16
#define PADDED_SIZE_HBM_26 16
#define AXI_PADDED_SIZE_HBM_26 16
#define TABLE_SIZE_HBM_26 100000
#define DATA_SIZE_HBM_27 16
#define PADDED_SIZE_HBM_27 16
#define AXI_PADDED_SIZE_HBM_27 16
#define TABLE_SIZE_HBM_27 100000
#define DATA_SIZE_HBM_28 16
#define PADDED_SIZE_HBM_28 16
#define AXI_PADDED_SIZE_HBM_28 16
#define TABLE_SIZE_HBM_28 100000
#define DATA_SIZE_HBM_29 16
#define PADDED_SIZE_HBM_29 16
#define AXI_PADDED_SIZE_HBM_29 16
#define TABLE_SIZE_HBM_29 100000
#define DATA_SIZE_HBM_30 16
#define PADDED_SIZE_HBM_30 16
#define AXI_PADDED_SIZE_HBM_30 16
#define TABLE_SIZE_HBM_30 100000
#define DATA_SIZE_HBM_31 16
#define PADDED_SIZE_HBM_31 16
#define AXI_PADDED_SIZE_HBM_31 16
#define TABLE_SIZE_HBM_31 100000
// #define DATA_SIZE_HBM_32 8
// #define PADDED_SIZE_HBM_32 8
// #define AXI_PADDED_SIZE_HBM_32 8
// #define TABLE_SIZE_HBM_32 100000
// #define DATA_SIZE_HBM_33 8
// #define PADDED_SIZE_HBM_33 8
// #define AXI_PADDED_SIZE_HBM_33 8
// #define TABLE_SIZE_HBM_33 100000
// #define DATA_SIZE_HBM_34 8
// #define PADDED_SIZE_HBM_34 8
// #define AXI_PADDED_SIZE_HBM_34 8
// #define TABLE_SIZE_HBM_34 100000
// #define DATA_SIZE_HBM_35 8
// #define PADDED_SIZE_HBM_35 8
// #define AXI_PADDED_SIZE_HBM_35 8
// #define TABLE_SIZE_HBM_35 100000
// #define DATA_SIZE_HBM_36 8
// #define PADDED_SIZE_HBM_36 8
// #define AXI_PADDED_SIZE_HBM_36 8
// #define TABLE_SIZE_HBM_36 100000
// #define DATA_SIZE_HBM_37 8
// #define PADDED_SIZE_HBM_37 8
// #define AXI_PADDED_SIZE_HBM_37 8
// #define TABLE_SIZE_HBM_37 100000
// #define DATA_SIZE_HBM_38 8
// #define PADDED_SIZE_HBM_38 8
// #define AXI_PADDED_SIZE_HBM_38 8
// #define TABLE_SIZE_HBM_38 100000
// #define DATA_SIZE_HBM_39 8
// #define PADDED_SIZE_HBM_39 8
// #define AXI_PADDED_SIZE_HBM_39 8
// #define TABLE_SIZE_HBM_39 100000
// #define DATA_SIZE_HBM_40 8
// #define PADDED_SIZE_HBM_40 8
// #define AXI_PADDED_SIZE_HBM_40 8
// #define TABLE_SIZE_HBM_40 100000
// #define DATA_SIZE_HBM_41 8
// #define PADDED_SIZE_HBM_41 8
// #define AXI_PADDED_SIZE_HBM_41 8
// #define TABLE_SIZE_HBM_41 100000
// #define DATA_SIZE_HBM_42 8
// #define PADDED_SIZE_HBM_42 8
// #define AXI_PADDED_SIZE_HBM_42 8
// #define TABLE_SIZE_HBM_42 150000
// #define DATA_SIZE_HBM_43 8
// #define PADDED_SIZE_HBM_43 8
// #define AXI_PADDED_SIZE_HBM_43 8
// #define TABLE_SIZE_HBM_43 150000
// #define DATA_SIZE_HBM_44 8
// #define PADDED_SIZE_HBM_44 8
// #define AXI_PADDED_SIZE_HBM_44 8
// #define TABLE_SIZE_HBM_44 250000
// #define DATA_SIZE_HBM_45 8
// #define PADDED_SIZE_HBM_45 8
// #define AXI_PADDED_SIZE_HBM_45 8
// #define TABLE_SIZE_HBM_45 250000
// #define DATA_SIZE_HBM_46 16
// #define PADDED_SIZE_HBM_46 16
// #define AXI_PADDED_SIZE_HBM_46 16
// #define TABLE_SIZE_HBM_46 500000
// #define DATA_SIZE_HBM_47 16
// #define PADDED_SIZE_HBM_47 16
// #define AXI_PADDED_SIZE_HBM_47 16
// #define TABLE_SIZE_HBM_47 500000
// #define DATA_SIZE_HBM_48 16
// #define PADDED_SIZE_HBM_48 16
// #define AXI_PADDED_SIZE_HBM_48 16
// #define TABLE_SIZE_HBM_48 500000
// #define DATA_SIZE_HBM_49 16
// #define PADDED_SIZE_HBM_49 16
// #define AXI_PADDED_SIZE_HBM_49 16
// #define TABLE_SIZE_HBM_49 500000
// #define DATA_SIZE_HBM_50 16
// #define PADDED_SIZE_HBM_50 16
// #define AXI_PADDED_SIZE_HBM_50 16
// #define TABLE_SIZE_HBM_50 500000
// #define DATA_SIZE_HBM_51 16
// #define PADDED_SIZE_HBM_51 16
// #define AXI_PADDED_SIZE_HBM_51 16
// #define TABLE_SIZE_HBM_51 500000
// #define DATA_SIZE_HBM_52 16
// #define PADDED_SIZE_HBM_52 16
// #define AXI_PADDED_SIZE_HBM_52 16
// #define TABLE_SIZE_HBM_52 500000
// #define DATA_SIZE_HBM_53 16
// #define PADDED_SIZE_HBM_53 16
// #define AXI_PADDED_SIZE_HBM_53 16
// #define TABLE_SIZE_HBM_53 500000
// #define DATA_SIZE_HBM_54 16
// #define PADDED_SIZE_HBM_54 16
// #define AXI_PADDED_SIZE_HBM_54 16
// #define TABLE_SIZE_HBM_54 500000
// #define DATA_SIZE_HBM_55 16
// #define PADDED_SIZE_HBM_55 16
// #define AXI_PADDED_SIZE_HBM_55 16
// #define TABLE_SIZE_HBM_55 500000
// #define DATA_SIZE_HBM_56 16
// #define PADDED_SIZE_HBM_56 16
// #define AXI_PADDED_SIZE_HBM_56 16
// #define TABLE_SIZE_HBM_56 500000
// #define DATA_SIZE_HBM_57 16
// #define PADDED_SIZE_HBM_57 16
// #define AXI_PADDED_SIZE_HBM_57 16
// #define TABLE_SIZE_HBM_57 500000
// #define DATA_SIZE_HBM_58 16
// #define PADDED_SIZE_HBM_58 16
// #define AXI_PADDED_SIZE_HBM_58 16
// #define TABLE_SIZE_HBM_58 500000
// #define DATA_SIZE_HBM_59 16
// #define PADDED_SIZE_HBM_59 16
// #define AXI_PADDED_SIZE_HBM_59 16
// #define TABLE_SIZE_HBM_59 500000
// #define DATA_SIZE_HBM_60 16
// #define PADDED_SIZE_HBM_60 16
// #define AXI_PADDED_SIZE_HBM_60 16
// #define TABLE_SIZE_HBM_60 500000
// #define DATA_SIZE_HBM_61 16
// #define PADDED_SIZE_HBM_61 16
// #define AXI_PADDED_SIZE_HBM_61 16
// #define TABLE_SIZE_HBM_61 500000
// #define DATA_SIZE_HBM_62 16
// #define PADDED_SIZE_HBM_62 16
// #define AXI_PADDED_SIZE_HBM_62 16
// #define TABLE_SIZE_HBM_62 1000000
// #define DATA_SIZE_HBM_63 16
// #define PADDED_SIZE_HBM_63 16
// #define AXI_PADDED_SIZE_HBM_63 16
// #define TABLE_SIZE_HBM_63 1000000

#define BURST_SIZE_HBM 32

#define ADDR_AXI_HBM_0 0
#define ADDR_AXI_HBM_1 0
#define ADDR_AXI_HBM_2 0
#define ADDR_AXI_HBM_3 0
#define ADDR_AXI_HBM_4 0
#define ADDR_AXI_HBM_5 0
#define ADDR_AXI_HBM_6 0
#define ADDR_AXI_HBM_7 0
#define ADDR_AXI_HBM_8 0
#define ADDR_AXI_HBM_9 0
#define ADDR_AXI_HBM_10 0
#define ADDR_AXI_HBM_11 0
#define ADDR_AXI_HBM_12 0
#define ADDR_AXI_HBM_13 0
#define ADDR_AXI_HBM_14 0
#define ADDR_AXI_HBM_15 0
#define ADDR_AXI_HBM_16 0
#define ADDR_AXI_HBM_17 0
#define ADDR_AXI_HBM_18 0
#define ADDR_AXI_HBM_19 0
#define ADDR_AXI_HBM_20 0
#define ADDR_AXI_HBM_21 0
#define ADDR_AXI_HBM_22 0
#define ADDR_AXI_HBM_23 0
#define ADDR_AXI_HBM_24 0
#define ADDR_AXI_HBM_25 0
#define ADDR_AXI_HBM_26 0
#define ADDR_AXI_HBM_27 0
#define ADDR_AXI_HBM_28 0
#define ADDR_AXI_HBM_29 0
#define ADDR_AXI_HBM_30 0
#define ADDR_AXI_HBM_31 0
// #define ADDR_AXI_HBM_32 400000
// #define ADDR_AXI_HBM_33 400000
// #define ADDR_AXI_HBM_34 400000
// #define ADDR_AXI_HBM_35 400000
// #define ADDR_AXI_HBM_36 400000
// #define ADDR_AXI_HBM_37 400000
// #define ADDR_AXI_HBM_38 400000
// #define ADDR_AXI_HBM_39 400000
// #define ADDR_AXI_HBM_40 400000
// #define ADDR_AXI_HBM_41 400000
// #define ADDR_AXI_HBM_42 400000
// #define ADDR_AXI_HBM_43 400000
// #define ADDR_AXI_HBM_44 400000
// #define ADDR_AXI_HBM_45 400000
// #define ADDR_AXI_HBM_46 400000
// #define ADDR_AXI_HBM_47 400000
// #define ADDR_AXI_HBM_48 400000
// #define ADDR_AXI_HBM_49 400000
// #define ADDR_AXI_HBM_50 400000
// #define ADDR_AXI_HBM_51 400000
// #define ADDR_AXI_HBM_52 400000
// #define ADDR_AXI_HBM_53 400000
// #define ADDR_AXI_HBM_54 400000
// #define ADDR_AXI_HBM_55 400000
// #define ADDR_AXI_HBM_56 400000
// #define ADDR_AXI_HBM_57 400000
// #define ADDR_AXI_HBM_58 400000
// #define ADDR_AXI_HBM_59 400000
// #define ADDR_AXI_HBM_60 400000
// #define ADDR_AXI_HBM_61 400000
// #define ADDR_AXI_HBM_62 400000
// #define ADDR_AXI_HBM_63 800000

#define HBM_BANK0_ROUND 2
#define HBM_BANK1_ROUND 2
#define HBM_BANK2_ROUND 2
#define HBM_BANK3_ROUND 2
#define HBM_BANK4_ROUND 2
#define HBM_BANK5_ROUND 2
#define HBM_BANK6_ROUND 2
#define HBM_BANK7_ROUND 2
#define HBM_BANK8_ROUND 2
#define HBM_BANK9_ROUND 2
#define HBM_BANK10_ROUND 2
#define HBM_BANK11_ROUND 2
#define HBM_BANK12_ROUND 2
#define HBM_BANK13_ROUND 2
#define HBM_BANK14_ROUND 2
#define HBM_BANK15_ROUND 2
#define HBM_BANK16_ROUND 1
#define HBM_BANK17_ROUND 1
#define HBM_BANK18_ROUND 1
#define HBM_BANK19_ROUND 1
#define HBM_BANK20_ROUND 1
#define HBM_BANK21_ROUND 1
#define HBM_BANK22_ROUND 1
#define HBM_BANK23_ROUND 1
#define HBM_BANK24_ROUND 1
#define HBM_BANK25_ROUND 1
#define HBM_BANK26_ROUND 1
#define HBM_BANK27_ROUND 1
#define HBM_BANK28_ROUND 1
#define HBM_BANK29_ROUND 1
#define HBM_BANK30_ROUND 1
#define HBM_BANK31_ROUND 1

#define HBM_BANK0_SIZE 1600000
#define HBM_BANK1_SIZE 1600000
#define HBM_BANK2_SIZE 1600000
#define HBM_BANK3_SIZE 1600000
#define HBM_BANK4_SIZE 1600000
#define HBM_BANK5_SIZE 1600000
#define HBM_BANK6_SIZE 1600000
#define HBM_BANK7_SIZE 1600000
#define HBM_BANK8_SIZE 1600000
#define HBM_BANK9_SIZE 1600000
#define HBM_BANK10_SIZE 1600000
#define HBM_BANK11_SIZE 1600000
#define HBM_BANK12_SIZE 1600000
#define HBM_BANK13_SIZE 1600000
#define HBM_BANK14_SIZE 1600000
#define HBM_BANK15_SIZE 1600000
#define HBM_BANK16_SIZE 1600000
#define HBM_BANK17_SIZE 1600000
#define HBM_BANK18_SIZE 1600000
#define HBM_BANK19_SIZE 1600000
#define HBM_BANK20_SIZE 1600000
#define HBM_BANK21_SIZE 1600000
#define HBM_BANK22_SIZE 1600000
#define HBM_BANK23_SIZE 1600000
#define HBM_BANK24_SIZE 1600000
#define HBM_BANK25_SIZE 1600000
#define HBM_BANK26_SIZE 1600000
#define HBM_BANK27_SIZE 1600000
#define HBM_BANK28_SIZE 1600000
#define HBM_BANK29_SIZE 1600000
#define HBM_BANK30_SIZE 1600000
#define HBM_BANK31_SIZE 1600000

#define VECTOR_SIZE_HBM_BANK_0 32
#define VECTOR_SIZE_HBM_BANK_1 32
#define VECTOR_SIZE_HBM_BANK_2 32
#define VECTOR_SIZE_HBM_BANK_3 32
#define VECTOR_SIZE_HBM_BANK_4 32
#define VECTOR_SIZE_HBM_BANK_5 32
#define VECTOR_SIZE_HBM_BANK_6 32
#define VECTOR_SIZE_HBM_BANK_7 32
#define VECTOR_SIZE_HBM_BANK_8 32
#define VECTOR_SIZE_HBM_BANK_9 32
#define VECTOR_SIZE_HBM_BANK_10 32
#define VECTOR_SIZE_HBM_BANK_11 32
#define VECTOR_SIZE_HBM_BANK_12 32
#define VECTOR_SIZE_HBM_BANK_13 32
#define VECTOR_SIZE_HBM_BANK_14 32
#define VECTOR_SIZE_HBM_BANK_15 32
#define VECTOR_SIZE_HBM_BANK_16 16
#define VECTOR_SIZE_HBM_BANK_17 16
#define VECTOR_SIZE_HBM_BANK_18 16
#define VECTOR_SIZE_HBM_BANK_19 16
#define VECTOR_SIZE_HBM_BANK_20 16
#define VECTOR_SIZE_HBM_BANK_21 16
#define VECTOR_SIZE_HBM_BANK_22 16
#define VECTOR_SIZE_HBM_BANK_23 16
#define VECTOR_SIZE_HBM_BANK_24 16
#define VECTOR_SIZE_HBM_BANK_25 16
#define VECTOR_SIZE_HBM_BANK_26 16
#define VECTOR_SIZE_HBM_BANK_27 16
#define VECTOR_SIZE_HBM_BANK_28 16
#define VECTOR_SIZE_HBM_BANK_29 16
#define VECTOR_SIZE_HBM_BANK_30 16
#define VECTOR_SIZE_HBM_BANK_31 16

// #define VECTOR_START_IDX_HBM_BANK_0 0
// #define VECTOR_START_IDX_HBM_BANK_1 16
// #define VECTOR_START_IDX_HBM_BANK_2 32
// #define VECTOR_START_IDX_HBM_BANK_3 48
// #define VECTOR_START_IDX_HBM_BANK_4 64
// #define VECTOR_START_IDX_HBM_BANK_5 80
// #define VECTOR_START_IDX_HBM_BANK_6 96
// #define VECTOR_START_IDX_HBM_BANK_7 112
// #define VECTOR_START_IDX_HBM_BANK_8 128
// #define VECTOR_START_IDX_HBM_BANK_9 144
// #define VECTOR_START_IDX_HBM_BANK_10 160
// #define VECTOR_START_IDX_HBM_BANK_11 176
// #define VECTOR_START_IDX_HBM_BANK_12 192
// #define VECTOR_START_IDX_HBM_BANK_13 208
// #define VECTOR_START_IDX_HBM_BANK_14 224
// #define VECTOR_START_IDX_HBM_BANK_15 248
// #define VECTOR_START_IDX_HBM_BANK_16 272
// #define VECTOR_START_IDX_HBM_BANK_17 296
// #define VECTOR_START_IDX_HBM_BANK_18 320
// #define VECTOR_START_IDX_HBM_BANK_19 344
// #define VECTOR_START_IDX_HBM_BANK_20 368
// #define VECTOR_START_IDX_HBM_BANK_21 392
// #define VECTOR_START_IDX_HBM_BANK_22 416
// #define VECTOR_START_IDX_HBM_BANK_23 440
// #define VECTOR_START_IDX_HBM_BANK_24 464
// #define VECTOR_START_IDX_HBM_BANK_25 488
// #define VECTOR_START_IDX_HBM_BANK_26 512
// #define VECTOR_START_IDX_HBM_BANK_27 536
// #define VECTOR_START_IDX_HBM_BANK_28 560
// #define VECTOR_START_IDX_HBM_BANK_29 584
// #define VECTOR_START_IDX_HBM_BANK_30 608
// #define VECTOR_START_IDX_HBM_BANK_31 632

//////////////////////////////   TEMPLATE END  //////////////////////////////


typedef ap_int<AXI_WIDTH_HBM> t_hbm;
// typedef ap_int<AXI_WIDTH_DDR> t_ddr;
// typedef ap_int<AXI_WIDTH_PLRAM> t_plram;

typedef int D_TYPE;
// typedef ap_int<128> W_TYPE;  // weights / feature width
// typedef ap_int<256> FIFO_TYPE;  // stream width

// #define INTS_PER_W 4 // 64 bit = 2 x 32 bit int
// #define INTS_PER_FIFO 8

// #define INPUT_SIZE 876
// #define HIDDEN_SIZE1 1024
// #define HIDDEN_SIZE2 512
// #define HIDDEN_SIZE3 256
// #define OUTPUT_SIZE 1

// #define PE_NUM1 128
// #define PE_NUM2 128
// #define PE_NUM3 32
// #define PE_NUM_OUT 1

// This row means after transpose it is row, before is col
// #define ROW_PER_PE1 (HIDDEN_SIZE1 / PE_NUM1) // 1024 / 128 = 8
// #define ROW_PER_PE2 (HIDDEN_SIZE2 / PE_NUM2) // 512 / 128 = 4
// #define ROW_PER_PE3 (HIDDEN_SIZE3 / PE_NUM3) // 256 / 32 = 8
// #define ROW_PER_PE_OUT (OUTPUT_SIZE / PE_NUM_OUT) // 1 / 1 = 1

#define FIFO_BATCH_SIZE 8   // cache 2 batches at max in FIFO
#define BATCH_SIZE 32
// #define BATCH_NUM 1000000
// #define BATCH_NUM 2
// #define BATCH_NUM 1
#define BATCH_NUM 5000 // NOTE! load access idx to BRAM!