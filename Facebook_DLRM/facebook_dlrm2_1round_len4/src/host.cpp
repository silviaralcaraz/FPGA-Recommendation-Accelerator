#include "host.hpp"

#define BANK_NAME(n) n | XCL_MEM_TOPOLOGY
/* for U280 specifically */
const int bank[40] = {
    /* 0 ~ 31 HBM */
    BANK_NAME(0), BANK_NAME(1), BANK_NAME(2), BANK_NAME(3), BANK_NAME(4),
    BANK_NAME(5), BANK_NAME(6), BANK_NAME(7), BANK_NAME(8), BANK_NAME(9),
    BANK_NAME(10), BANK_NAME(11), BANK_NAME(12), BANK_NAME(13), BANK_NAME(14),
    BANK_NAME(15), BANK_NAME(16), BANK_NAME(17), BANK_NAME(18), BANK_NAME(19),
    BANK_NAME(20), BANK_NAME(21), BANK_NAME(22), BANK_NAME(23), BANK_NAME(24),
    BANK_NAME(25), BANK_NAME(26), BANK_NAME(27), BANK_NAME(28), BANK_NAME(29),
    BANK_NAME(30), BANK_NAME(31),
    /* 32, 33 DDR */
    BANK_NAME(32), BANK_NAME(33),
    /* 34 ~ 39 PLRAM */
    BANK_NAME(34), BANK_NAME(35), BANK_NAME(36), BANK_NAME(37),
    BANK_NAME(38), BANK_NAME(39)};

int main(int argc, char **argv)
{
        if (argc != 2)
        {
                std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
                return EXIT_FAILURE;
        }

        std::cout << "=========== EXECUTION INFO ==============" << std::endl;
        std::cout << "Data precission: " << sizeof(D_TYPE) * 8 << " bits" << std::endl;
        std::cout << "Debug mode: " << DEBUG << std::endl;
        std::cout << "Batch size: " << BATCH_SIZE << " keys per batch" << std::endl;
        std::cout << "Number of batches: " << BATCH_NUM << std::endl;
        std::cout << "==========================================" << std::endl;

        std::string binaryFile = argv[1];
        //////////////////////////////   TEMPLATE START  //////////////////////////////
        size_t HBM_embedding0_size = HBM_BANK0_SIZE;
        size_t HBM_embedding1_size = HBM_BANK1_SIZE;
        size_t HBM_embedding2_size = HBM_BANK2_SIZE;
        size_t HBM_embedding3_size = HBM_BANK3_SIZE;
        size_t HBM_embedding4_size = HBM_BANK4_SIZE;
        size_t HBM_embedding5_size = HBM_BANK5_SIZE;
        size_t HBM_embedding6_size = HBM_BANK6_SIZE;
        size_t HBM_embedding7_size = HBM_BANK7_SIZE;
        size_t HBM_embedding8_size = HBM_BANK8_SIZE;
        size_t HBM_embedding9_size = HBM_BANK9_SIZE;
        size_t HBM_embedding10_size = HBM_BANK10_SIZE;
        size_t HBM_embedding11_size = HBM_BANK11_SIZE;
        size_t HBM_embedding12_size = HBM_BANK12_SIZE;
        size_t HBM_embedding13_size = HBM_BANK13_SIZE;
        size_t HBM_embedding14_size = HBM_BANK14_SIZE;
        size_t HBM_embedding15_size = HBM_BANK15_SIZE;
        size_t HBM_embedding16_size = HBM_BANK16_SIZE;
        size_t HBM_embedding17_size = HBM_BANK17_SIZE;
        size_t HBM_embedding18_size = HBM_BANK18_SIZE;
        size_t HBM_embedding19_size = HBM_BANK19_SIZE;
        size_t HBM_embedding20_size = HBM_BANK20_SIZE;
        size_t HBM_embedding21_size = HBM_BANK21_SIZE;
        size_t HBM_embedding22_size = HBM_BANK22_SIZE;
        size_t HBM_embedding23_size = HBM_BANK23_SIZE;
        size_t HBM_embedding24_size = HBM_BANK24_SIZE;
        size_t HBM_embedding25_size = HBM_BANK25_SIZE;
        size_t HBM_embedding26_size = HBM_BANK26_SIZE;
        size_t HBM_embedding27_size = HBM_BANK27_SIZE;
        size_t HBM_embedding28_size = HBM_BANK28_SIZE;
        size_t HBM_embedding29_size = HBM_BANK29_SIZE;
        size_t HBM_embedding30_size = HBM_BANK30_SIZE;
        size_t HBM_embedding31_size = HBM_BANK31_SIZE;

        //////////////////////////////   TEMPLATE END  //////////////////////////////

        size_t result_size = BATCH_SIZE;
        size_t idx_size_1_round = BATCH_SIZE;
        //     size_t idx_size_2_round = 2 * BATCH_SIZE;
        cl_int err;
        unsigned fileBufSize;

        // allocate aligned 2D vectors
        std::cout << "Allocating memory..." << std::endl;
        //////////////////////////////   TEMPLATE START  //////////////////////////////
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding0(HBM_embedding0_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding1(HBM_embedding1_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding2(HBM_embedding2_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding3(HBM_embedding3_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding4(HBM_embedding4_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding5(HBM_embedding5_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding6(HBM_embedding6_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding7(HBM_embedding7_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding8(HBM_embedding8_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding9(HBM_embedding9_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding10(HBM_embedding10_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding11(HBM_embedding11_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding12(HBM_embedding12_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding13(HBM_embedding13_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding14(HBM_embedding14_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding15(HBM_embedding15_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding16(HBM_embedding16_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding17(HBM_embedding17_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding18(HBM_embedding18_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding19(HBM_embedding19_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding20(HBM_embedding20_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding21(HBM_embedding21_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding22(HBM_embedding22_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding23(HBM_embedding23_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding24(HBM_embedding24_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding25(HBM_embedding25_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding26(HBM_embedding26_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding27(HBM_embedding27_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding28(HBM_embedding28_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding29(HBM_embedding29_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding30(HBM_embedding30_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> HBM_embedding31(HBM_embedding31_size, 0);

        //////////////////////////////   TEMPLATE END  //////////////////////////////
        std::vector<int, aligned_allocator<int>> access_idx_1_round(idx_size_1_round, 0);
        //     std::vector<int, aligned_allocator<int>> access_idx_2_round(idx_size_2_round, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> source_hw_results(result_size, 0);
        std::vector<D_TYPE, aligned_allocator<D_TYPE>> source_sw_results(result_size, 0);

        //     std::cout << "test mem boundary " << DDR_embedding1[DDR_BANK1_SIZE - 1] << std::endl;
        // NOTE! the following expression will lead to seg fault!
        // since the mul expression assumes "int" input, but its result exceeds the int limit
        // std::cout << "test mem boundary " << DDR_embedding1[PADDED_SIZE_DDR_3 * TABLE_SIZE_DDR_3 - 1] << std::endl;
        // std::cout << "test mem boundary " << DDR_embedding1[ADDR_AXI_DDR_3 + PADDED_SIZE_DDR_3 * TABLE_SIZE_DDR_3 - 1] << std::endl;

        std::cout << "Allocating memory finished" << std::endl;

        // generate embedding table
        //////////////////////////////   TEMPLATE START  //////////////////////////////

        std::cout << "Generating table contents..." << std::endl;
        std::cout << "HBM Round 0..." << std::endl;

        // Round 0
        for (int i = 0; i < TABLE_SIZE_HBM_0; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_0; j++)
                {
#ifdef DEBUG
                        HBM_embedding0[i * PADDED_SIZE_HBM_0 + j + ADDR_AXI_HBM_0] = static_cast<D_TYPE>(i + 0);
#else
                        HBM_embedding0[i * PADDED_SIZE_HBM_0 + j + ADDR_AXI_HBM_0] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_1; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_1; j++)
                {
#ifdef DEBUG
                        HBM_embedding1[i * PADDED_SIZE_HBM_1 + j + ADDR_AXI_HBM_1] = static_cast<D_TYPE>(i + 1);
#else
                        HBM_embedding1[i * PADDED_SIZE_HBM_1 + j + ADDR_AXI_HBM_1] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_2; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_2; j++)
                {
#ifdef DEBUG
                        HBM_embedding2[i * PADDED_SIZE_HBM_2 + j + ADDR_AXI_HBM_2] = static_cast<D_TYPE>(i + 2);
#else
                        HBM_embedding2[i * PADDED_SIZE_HBM_2 + j + ADDR_AXI_HBM_2] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_3; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_3; j++)
                {
#ifdef DEBUG
                        HBM_embedding3[i * PADDED_SIZE_HBM_3 + j + ADDR_AXI_HBM_3] = static_cast<D_TYPE>(i + 3);
#else
                        HBM_embedding3[i * PADDED_SIZE_HBM_3 + j + ADDR_AXI_HBM_3] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_4; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_4; j++)
                {
#ifdef DEBUG
                        HBM_embedding4[i * PADDED_SIZE_HBM_4 + j + ADDR_AXI_HBM_4] = static_cast<D_TYPE>(i + 4);
#else
                        HBM_embedding4[i * PADDED_SIZE_HBM_4 + j + ADDR_AXI_HBM_4] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_5; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_5; j++)
                {
#ifdef DEBUG
                        HBM_embedding5[i * PADDED_SIZE_HBM_5 + j + ADDR_AXI_HBM_5] = static_cast<D_TYPE>(i + 5);
#else
                        HBM_embedding5[i * PADDED_SIZE_HBM_5 + j + ADDR_AXI_HBM_5] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_6; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_6; j++)
                {
#ifdef DEBUG
                        HBM_embedding6[i * PADDED_SIZE_HBM_6 + j + ADDR_AXI_HBM_6] = static_cast<D_TYPE>(i + 6);
#else
                        HBM_embedding6[i * PADDED_SIZE_HBM_6 + j + ADDR_AXI_HBM_6] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_7; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_7; j++)
                {
#ifdef DEBUG
                        HBM_embedding7[i * PADDED_SIZE_HBM_7 + j + ADDR_AXI_HBM_7] = static_cast<D_TYPE>(i + 7);
#else
                        HBM_embedding7[i * PADDED_SIZE_HBM_7 + j + ADDR_AXI_HBM_7] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_8; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_8; j++)
                {
#ifdef DEBUG
                        HBM_embedding8[i * PADDED_SIZE_HBM_8 + j + ADDR_AXI_HBM_8] = static_cast<D_TYPE>(i + 8);
#else
                        HBM_embedding8[i * PADDED_SIZE_HBM_8 + j + ADDR_AXI_HBM_8] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_9; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_9; j++)
                {
#ifdef DEBUG
                        HBM_embedding9[i * PADDED_SIZE_HBM_9 + j + ADDR_AXI_HBM_9] = static_cast<D_TYPE>(i + 9);
#else
                        HBM_embedding9[i * PADDED_SIZE_HBM_9 + j + ADDR_AXI_HBM_9] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_10; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_10; j++)
                {
#ifdef DEBUG
                        HBM_embedding10[i * PADDED_SIZE_HBM_10 + j + ADDR_AXI_HBM_10] = static_cast<D_TYPE>(i + 10);
#else
                        HBM_embedding10[i * PADDED_SIZE_HBM_10 + j + ADDR_AXI_HBM_10] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_11; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_11; j++)
                {
#ifdef DEBUG
                        HBM_embedding11[i * PADDED_SIZE_HBM_11 + j + ADDR_AXI_HBM_11] = static_cast<D_TYPE>(i + 11);
#else
                        HBM_embedding11[i * PADDED_SIZE_HBM_11 + j + ADDR_AXI_HBM_11] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_12; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_12; j++)
                {
#ifdef DEBUG
                        HBM_embedding12[i * PADDED_SIZE_HBM_12 + j + ADDR_AXI_HBM_12] = static_cast<D_TYPE>(i + 12);
#else
                        HBM_embedding12[i * PADDED_SIZE_HBM_12 + j + ADDR_AXI_HBM_12] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_13; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_13; j++)
                {
#ifdef DEBUG
                        HBM_embedding13[i * PADDED_SIZE_HBM_13 + j + ADDR_AXI_HBM_13] = static_cast<D_TYPE>(i + 13);
#else
                        HBM_embedding13[i * PADDED_SIZE_HBM_13 + j + ADDR_AXI_HBM_13] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_14; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_14; j++)
                {
#ifdef DEBUG
                        HBM_embedding14[i * PADDED_SIZE_HBM_14 + j + ADDR_AXI_HBM_14] = static_cast<D_TYPE>(i + 14);
#else
                        HBM_embedding14[i * PADDED_SIZE_HBM_14 + j + ADDR_AXI_HBM_14] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_15; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_15; j++)
                {
#ifdef DEBUG
                        HBM_embedding15[i * PADDED_SIZE_HBM_15 + j + ADDR_AXI_HBM_15] = static_cast<D_TYPE>(i + 15);
#else
                        HBM_embedding15[i * PADDED_SIZE_HBM_15 + j + ADDR_AXI_HBM_15] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_16; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_16; j++)
                {
#ifdef DEBUG
                        HBM_embedding16[i * PADDED_SIZE_HBM_16 + j + ADDR_AXI_HBM_16] = static_cast<D_TYPE>(i + 16);
#else
                        HBM_embedding16[i * PADDED_SIZE_HBM_16 + j + ADDR_AXI_HBM_16] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_17; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_17; j++)
                {
#ifdef DEBUG
                        HBM_embedding17[i * PADDED_SIZE_HBM_17 + j + ADDR_AXI_HBM_17] = static_cast<D_TYPE>(i + 17);
#else
                        HBM_embedding17[i * PADDED_SIZE_HBM_17 + j + ADDR_AXI_HBM_17] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_18; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_18; j++)
                {
#ifdef DEBUG
                        HBM_embedding18[i * PADDED_SIZE_HBM_18 + j + ADDR_AXI_HBM_18] = static_cast<D_TYPE>(i + 18);
#else
                        HBM_embedding18[i * PADDED_SIZE_HBM_18 + j + ADDR_AXI_HBM_18] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_19; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_19; j++)
                {
#ifdef DEBUG
                        HBM_embedding19[i * PADDED_SIZE_HBM_19 + j + ADDR_AXI_HBM_19] = static_cast<D_TYPE>(i + 19);
#else
                        HBM_embedding19[i * PADDED_SIZE_HBM_19 + j + ADDR_AXI_HBM_19] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_20; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_20; j++)
                {
#ifdef DEBUG
                        HBM_embedding20[i * PADDED_SIZE_HBM_20 + j + ADDR_AXI_HBM_20] = static_cast<D_TYPE>(i + 20);
#else
                        HBM_embedding20[i * PADDED_SIZE_HBM_20 + j + ADDR_AXI_HBM_20] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_21; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_21; j++)
                {
#ifdef DEBUG
                        HBM_embedding21[i * PADDED_SIZE_HBM_21 + j + ADDR_AXI_HBM_21] = static_cast<D_TYPE>(i + 21);
#else
                        HBM_embedding21[i * PADDED_SIZE_HBM_21 + j + ADDR_AXI_HBM_21] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_22; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_22; j++)
                {
#ifdef DEBUG
                        HBM_embedding22[i * PADDED_SIZE_HBM_22 + j + ADDR_AXI_HBM_22] = static_cast<D_TYPE>(i + 22);
#else
                        HBM_embedding22[i * PADDED_SIZE_HBM_22 + j + ADDR_AXI_HBM_22] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_23; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_23; j++)
                {
#ifdef DEBUG
                        HBM_embedding23[i * PADDED_SIZE_HBM_23 + j + ADDR_AXI_HBM_23] = static_cast<D_TYPE>(i + 23);
#else
                        HBM_embedding23[i * PADDED_SIZE_HBM_23 + j + ADDR_AXI_HBM_23] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_24; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_24; j++)
                {
#ifdef DEBUG
                        HBM_embedding24[i * PADDED_SIZE_HBM_24 + j + ADDR_AXI_HBM_24] = static_cast<D_TYPE>(i + 24);
#else
                        HBM_embedding24[i * PADDED_SIZE_HBM_24 + j + ADDR_AXI_HBM_24] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_25; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_25; j++)
                {
#ifdef DEBUG
                        HBM_embedding25[i * PADDED_SIZE_HBM_25 + j + ADDR_AXI_HBM_25] = static_cast<D_TYPE>(i + 25);
#else
                        HBM_embedding25[i * PADDED_SIZE_HBM_25 + j + ADDR_AXI_HBM_25] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_26; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_26; j++)
                {
#ifdef DEBUG
                        HBM_embedding26[i * PADDED_SIZE_HBM_26 + j + ADDR_AXI_HBM_26] = static_cast<D_TYPE>(i + 26);
#else
                        HBM_embedding26[i * PADDED_SIZE_HBM_26 + j + ADDR_AXI_HBM_26] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_27; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_27; j++)
                {
#ifdef DEBUG
                        HBM_embedding27[i * PADDED_SIZE_HBM_27 + j + ADDR_AXI_HBM_27] = static_cast<D_TYPE>(i + 27);
#else
                        HBM_embedding27[i * PADDED_SIZE_HBM_27 + j + ADDR_AXI_HBM_27] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_28; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_28; j++)
                {
#ifdef DEBUG
                        HBM_embedding28[i * PADDED_SIZE_HBM_28 + j + ADDR_AXI_HBM_28] = static_cast<D_TYPE>(i + 28);
#else
                        HBM_embedding28[i * PADDED_SIZE_HBM_28 + j + ADDR_AXI_HBM_28] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_29; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_29; j++)
                {
#ifdef DEBUG
                        HBM_embedding29[i * PADDED_SIZE_HBM_29 + j + ADDR_AXI_HBM_29] = static_cast<D_TYPE>(i + 29);
#else
                        HBM_embedding29[i * PADDED_SIZE_HBM_29 + j + ADDR_AXI_HBM_29] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_30; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_30; j++)
                {
#ifdef DEBUG
                        HBM_embedding30[i * PADDED_SIZE_HBM_30 + j + ADDR_AXI_HBM_30] = static_cast<D_TYPE>(i + 30);
#else
                        HBM_embedding30[i * PADDED_SIZE_HBM_30 + j + ADDR_AXI_HBM_30] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }
        for (int i = 0; i < TABLE_SIZE_HBM_31; i++)
        {
                for (int j = 0; j < DATA_SIZE_HBM_31; j++)
                {
#ifdef DEBUG
                        HBM_embedding31[i * PADDED_SIZE_HBM_31 + j + ADDR_AXI_HBM_31] = static_cast<D_TYPE>(i + 31);
#else
                        HBM_embedding31[i * PADDED_SIZE_HBM_31 + j + ADDR_AXI_HBM_31] = static_cast<D_TYPE>(rand() % 23);
#endif
                }
        }

        std::cout << "Generating table contents finished" << std::endl;
        //////////////////////////////   TEMPLATE END  //////////////////////////////
        
        // software result
        
        int idx_random_1_round[] =
            {864, 54, 873, 698, 100, 886, 101, 689, 41, 511, 898, 873, 945,
             322, 277, 628, 159, 511, 438, 699, 414, 954, 263, 329, 780, 488,
             658, 461, 528, 529, 500, 416};
        
        // int idx_random_1_round[] =
        // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
        // 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};


        // generated random index, each batch is the same
        for (int j = 0; j < BATCH_SIZE; j++)
        {
                access_idx_1_round[j] = idx_random_1_round[j];
        }

        for (int j = 0; j < BATCH_SIZE; j++)
        {

                int result_addr = j;

                //////////////////////////////   TEMPLATE START  //////////////////////////////

                // add up the first value of each selected row
                source_sw_results[result_addr] +=
                    HBM_embedding0[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_0];
                source_sw_results[result_addr] +=
                    HBM_embedding1[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_1];
                source_sw_results[result_addr] +=
                    HBM_embedding2[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_2];
                source_sw_results[result_addr] +=
                    HBM_embedding3[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_3];
                source_sw_results[result_addr] +=
                    HBM_embedding4[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_4];
                source_sw_results[result_addr] +=
                    HBM_embedding5[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_5];
                source_sw_results[result_addr] +=
                    HBM_embedding6[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_6];
                source_sw_results[result_addr] +=
                    HBM_embedding7[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_7];
                source_sw_results[result_addr] +=
                    HBM_embedding8[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_8];
                source_sw_results[result_addr] +=
                    HBM_embedding9[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_9];
                source_sw_results[result_addr] +=
                    HBM_embedding10[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_10];
                source_sw_results[result_addr] +=
                    HBM_embedding11[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_11];
                source_sw_results[result_addr] +=
                    HBM_embedding12[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_12];
                source_sw_results[result_addr] +=
                    HBM_embedding13[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_13];
                source_sw_results[result_addr] +=
                    HBM_embedding14[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_14];
                source_sw_results[result_addr] +=
                    HBM_embedding15[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_15];
                source_sw_results[result_addr] +=
                    HBM_embedding16[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_16];
                source_sw_results[result_addr] +=
                    HBM_embedding17[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_17];
                source_sw_results[result_addr] +=
                    HBM_embedding18[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_18];
                source_sw_results[result_addr] +=
                    HBM_embedding19[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_19];
                source_sw_results[result_addr] +=
                    HBM_embedding20[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_20];
                source_sw_results[result_addr] +=
                    HBM_embedding21[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_21];
                source_sw_results[result_addr] +=
                    HBM_embedding22[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_22];
                source_sw_results[result_addr] +=
                    HBM_embedding23[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_23];
                source_sw_results[result_addr] +=
                    HBM_embedding24[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_24];
                source_sw_results[result_addr] +=
                    HBM_embedding25[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_25];
                source_sw_results[result_addr] +=
                    HBM_embedding26[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_26];
                source_sw_results[result_addr] +=
                    HBM_embedding27[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_27];
                source_sw_results[result_addr] +=
                    HBM_embedding28[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_28];
                source_sw_results[result_addr] +=
                    HBM_embedding29[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_29];
                source_sw_results[result_addr] +=
                    HBM_embedding30[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_30];
                source_sw_results[result_addr] +=
                    HBM_embedding31[access_idx_1_round[result_addr] * PADDED_SIZE_HBM_31];
        }

        std::cout << "Software compute result finished" << std::endl;

        // OPENCL HOST CODE AREA START

        // ------------------------------------------------------------------------------------
        // Step 1: Get All PLATFORMS, then search for Target_Platform_Vendor (CL_PLATFORM_VENDOR)
        //	   Search for Platform: Xilinx
        // Check if the current platform matches Target_Platform_Vendor
        // ------------------------------------------------------------------------------------
        std::vector<cl::Device> devices = get_devices("Xilinx");
        devices.resize(1);
        cl::Device device = devices[0];

        // ------------------------------------------------------------------------------------
        // Step 1: Create Context
        // ------------------------------------------------------------------------------------
        OCL_CHECK(err, cl::Context context(device, NULL, NULL, NULL, &err));

        // ------------------------------------------------------------------------------------
        // Step 1: Create Command Queue
        // ------------------------------------------------------------------------------------
        OCL_CHECK(err, cl::CommandQueue q(context, device, CL_QUEUE_PROFILING_ENABLE, &err));

        // ------------------------------------------------------------------
        // Step 1: Load Binary File from disk
        // ------------------------------------------------------------------
        char *fileBuf = read_binary_file(binaryFile, fileBufSize);
        cl::Program::Binaries bins{{fileBuf, fileBufSize}};

        // -------------------------------------------------------------
        // Step 1: Create the program object from the binary and program the FPGA device with it
        // -------------------------------------------------------------
        OCL_CHECK(err, cl::Program program(context, devices, bins, NULL, &err));

        // -------------------------------------------------------------
        // Step 1: Create Kernels
        // -------------------------------------------------------------
        OCL_CHECK(err, cl::Kernel krnl_vector_add(program, "vadd", &err));

        // ================================================================
        // Step 2: Setup Buffers and run Kernels
        // ================================================================
        //   o) Allocate Memory to store the results
        //   o) Create Buffers in Global Memory to store data
        // ================================================================

        // ------------------------------------------------------------------
        // Step 2: Create Buffers in Global Memory to store data
        //             o) buffer_in1 - stores source_in1
        //             o) buffer_in2 - stores source_in2
        //             o) buffer_ouput - stores Results
        // ------------------------------------------------------------------

        // .......................................................
        // Allocate Global Memory for source_in1
        // .......................................................
        //////////////////////////////   TEMPLATE START  //////////////////////////////
        cl_mem_ext_ptr_t HBM_embedding0Ext, HBM_embedding1Ext, HBM_embedding2Ext, HBM_embedding3Ext,
            HBM_embedding4Ext, HBM_embedding5Ext, HBM_embedding6Ext, HBM_embedding7Ext,
            HBM_embedding8Ext, HBM_embedding9Ext, HBM_embedding10Ext, HBM_embedding11Ext,
            HBM_embedding12Ext, HBM_embedding13Ext, HBM_embedding14Ext, HBM_embedding15Ext,
            HBM_embedding16Ext, HBM_embedding17Ext, HBM_embedding18Ext, HBM_embedding19Ext,
            HBM_embedding20Ext, HBM_embedding21Ext, HBM_embedding22Ext, HBM_embedding23Ext,
            HBM_embedding24Ext, HBM_embedding25Ext, HBM_embedding26Ext, HBM_embedding27Ext,
            HBM_embedding28Ext, HBM_embedding29Ext, HBM_embedding30Ext, HBM_embedding31Ext,
            // DDR_embedding0Ext, DDR_embedding1Ext,
            /* PLRAM_embedding0Ext, PLRAM_embedding1Ext, PLRAM_embedding2Ext, PLRAM_embedding3Ext,
            access_idxExt, */
            sourcce_hw_resultsExt;
        //////////////////////////////   TEMPLATE END  //////////////////////////////

        //////////////////////////////   TEMPLATE START  //////////////////////////////
        HBM_embedding0Ext.obj = HBM_embedding0.data();
        HBM_embedding0Ext.param = 0;
        HBM_embedding0Ext.flags = bank[0];
        HBM_embedding1Ext.obj = HBM_embedding1.data();
        HBM_embedding1Ext.param = 0;
        HBM_embedding1Ext.flags = bank[1];
        HBM_embedding2Ext.obj = HBM_embedding2.data();
        HBM_embedding2Ext.param = 0;
        HBM_embedding2Ext.flags = bank[2];
        HBM_embedding3Ext.obj = HBM_embedding3.data();
        HBM_embedding3Ext.param = 0;
        HBM_embedding3Ext.flags = bank[3];
        HBM_embedding4Ext.obj = HBM_embedding4.data();
        HBM_embedding4Ext.param = 0;
        HBM_embedding4Ext.flags = bank[4];
        HBM_embedding5Ext.obj = HBM_embedding5.data();
        HBM_embedding5Ext.param = 0;
        HBM_embedding5Ext.flags = bank[5];
        HBM_embedding6Ext.obj = HBM_embedding6.data();
        HBM_embedding6Ext.param = 0;
        HBM_embedding6Ext.flags = bank[6];
        HBM_embedding7Ext.obj = HBM_embedding7.data();
        HBM_embedding7Ext.param = 0;
        HBM_embedding7Ext.flags = bank[7];
        HBM_embedding8Ext.obj = HBM_embedding8.data();
        HBM_embedding8Ext.param = 0;
        HBM_embedding8Ext.flags = bank[8];
        HBM_embedding9Ext.obj = HBM_embedding9.data();
        HBM_embedding9Ext.param = 0;
        HBM_embedding9Ext.flags = bank[9];
        HBM_embedding10Ext.obj = HBM_embedding10.data();
        HBM_embedding10Ext.param = 0;
        HBM_embedding10Ext.flags = bank[10];
        HBM_embedding11Ext.obj = HBM_embedding11.data();
        HBM_embedding11Ext.param = 0;
        HBM_embedding11Ext.flags = bank[11];
        HBM_embedding12Ext.obj = HBM_embedding12.data();
        HBM_embedding12Ext.param = 0;
        HBM_embedding12Ext.flags = bank[12];
        HBM_embedding13Ext.obj = HBM_embedding13.data();
        HBM_embedding13Ext.param = 0;
        HBM_embedding13Ext.flags = bank[13];
        HBM_embedding14Ext.obj = HBM_embedding14.data();
        HBM_embedding14Ext.param = 0;
        HBM_embedding14Ext.flags = bank[14];
        HBM_embedding15Ext.obj = HBM_embedding15.data();
        HBM_embedding15Ext.param = 0;
        HBM_embedding15Ext.flags = bank[15];
        HBM_embedding16Ext.obj = HBM_embedding16.data();
        HBM_embedding16Ext.param = 0;
        HBM_embedding16Ext.flags = bank[16];
        HBM_embedding17Ext.obj = HBM_embedding17.data();
        HBM_embedding17Ext.param = 0;
        HBM_embedding17Ext.flags = bank[17];
        HBM_embedding18Ext.obj = HBM_embedding18.data();
        HBM_embedding18Ext.param = 0;
        HBM_embedding18Ext.flags = bank[18];
        HBM_embedding19Ext.obj = HBM_embedding19.data();
        HBM_embedding19Ext.param = 0;
        HBM_embedding19Ext.flags = bank[19];
        HBM_embedding20Ext.obj = HBM_embedding20.data();
        HBM_embedding20Ext.param = 0;
        HBM_embedding20Ext.flags = bank[20];
        HBM_embedding21Ext.obj = HBM_embedding21.data();
        HBM_embedding21Ext.param = 0;
        HBM_embedding21Ext.flags = bank[21];
        HBM_embedding22Ext.obj = HBM_embedding22.data();
        HBM_embedding22Ext.param = 0;
        HBM_embedding22Ext.flags = bank[22];
        HBM_embedding23Ext.obj = HBM_embedding23.data();
        HBM_embedding23Ext.param = 0;
        HBM_embedding23Ext.flags = bank[23];
        HBM_embedding24Ext.obj = HBM_embedding24.data();
        HBM_embedding24Ext.param = 0;
        HBM_embedding24Ext.flags = bank[24];
        HBM_embedding25Ext.obj = HBM_embedding25.data();
        HBM_embedding25Ext.param = 0;
        HBM_embedding25Ext.flags = bank[25];
        HBM_embedding26Ext.obj = HBM_embedding26.data();
        HBM_embedding26Ext.param = 0;
        HBM_embedding26Ext.flags = bank[26];
        HBM_embedding27Ext.obj = HBM_embedding27.data();
        HBM_embedding27Ext.param = 0;
        HBM_embedding27Ext.flags = bank[27];
        HBM_embedding28Ext.obj = HBM_embedding28.data();
        HBM_embedding28Ext.param = 0;
        HBM_embedding28Ext.flags = bank[28];
        HBM_embedding29Ext.obj = HBM_embedding29.data();
        HBM_embedding29Ext.param = 0;
        HBM_embedding29Ext.flags = bank[29];
        HBM_embedding30Ext.obj = HBM_embedding30.data();
        HBM_embedding30Ext.param = 0;
        HBM_embedding30Ext.flags = bank[30];
        HBM_embedding31Ext.obj = HBM_embedding31.data();
        HBM_embedding31Ext.param = 0;
        HBM_embedding31Ext.flags = bank[31];

        // DDR_embedding0Ext.obj = DDR_embedding0.data();
        // DDR_embedding0Ext.param = 0;
        // DDR_embedding0Ext.flags = bank[0 + 32];
        // DDR_embedding1Ext.obj = DDR_embedding1.data();
        // DDR_embedding1Ext.param = 0;
        // DDR_embedding1Ext.flags = bank[1 + 32];

        //     PLRAM_embedding0Ext.obj = PLRAM_embedding0.data();
        //     PLRAM_embedding0Ext.param = 0;
        //     PLRAM_embedding0Ext.flags = bank[32];
        //     PLRAM_embedding1Ext.obj = PLRAM_embedding1.data();
        //     PLRAM_embedding1Ext.param = 0;
        //     PLRAM_embedding1Ext.flags = bank[32];
        //     PLRAM_embedding2Ext.obj = PLRAM_embedding2.data();
        //     PLRAM_embedding2Ext.param = 0;
        //     PLRAM_embedding2Ext.flags = bank[32];
        //     PLRAM_embedding3Ext.obj = PLRAM_embedding3.data();
        //     PLRAM_embedding3Ext.param = 0;
        //     PLRAM_embedding3Ext.flags = bank[32];
        //////////////////////////////   TEMPLATE END  //////////////////////////////
        //     access_idxExt.obj = access_idx.data();
        //     access_idxExt.param = 0;
        //     access_idxExt.flags = bank[32];

        // result in PLRAM[0]
        sourcce_hw_resultsExt.obj = source_hw_results.data();
        sourcce_hw_resultsExt.param = 0;
        sourcce_hw_resultsExt.flags = bank[34];

        // CL_MEM_EXT_PTR_XILINX
        //////////////////////////////   TEMPLATE START  //////////////////////////////
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding0(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding0_size * sizeof(D_TYPE), &HBM_embedding0Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding1(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding1_size * sizeof(D_TYPE), &HBM_embedding1Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding2(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding2_size * sizeof(D_TYPE), &HBM_embedding2Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding3(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding3_size * sizeof(D_TYPE), &HBM_embedding3Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding4(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding4_size * sizeof(D_TYPE), &HBM_embedding4Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding5(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding5_size * sizeof(D_TYPE), &HBM_embedding5Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding6(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding6_size * sizeof(D_TYPE), &HBM_embedding6Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding7(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding7_size * sizeof(D_TYPE), &HBM_embedding7Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding8(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding8_size * sizeof(D_TYPE), &HBM_embedding8Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding9(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                        HBM_embedding9_size * sizeof(D_TYPE), &HBM_embedding9Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding10(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding10_size * sizeof(D_TYPE), &HBM_embedding10Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding11(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding11_size * sizeof(D_TYPE), &HBM_embedding11Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding12(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding12_size * sizeof(D_TYPE), &HBM_embedding12Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding13(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding13_size * sizeof(D_TYPE), &HBM_embedding13Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding14(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding14_size * sizeof(D_TYPE), &HBM_embedding14Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding15(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding15_size * sizeof(D_TYPE), &HBM_embedding15Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding16(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding16_size * sizeof(D_TYPE), &HBM_embedding16Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding17(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding17_size * sizeof(D_TYPE), &HBM_embedding17Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding18(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding18_size * sizeof(D_TYPE), &HBM_embedding18Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding19(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding19_size * sizeof(D_TYPE), &HBM_embedding19Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding20(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding20_size * sizeof(D_TYPE), &HBM_embedding20Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding21(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding21_size * sizeof(D_TYPE), &HBM_embedding21Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding22(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding22_size * sizeof(D_TYPE), &HBM_embedding22Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding23(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding23_size * sizeof(D_TYPE), &HBM_embedding23Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding24(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding24_size * sizeof(D_TYPE), &HBM_embedding24Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding25(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding25_size * sizeof(D_TYPE), &HBM_embedding25Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding26(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding26_size * sizeof(D_TYPE), &HBM_embedding26Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding27(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding27_size * sizeof(D_TYPE), &HBM_embedding27Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding28(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding28_size * sizeof(D_TYPE), &HBM_embedding28Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding29(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding29_size * sizeof(D_TYPE), &HBM_embedding29Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding30(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding30_size * sizeof(D_TYPE), &HBM_embedding30Ext, &err));
        OCL_CHECK(err, cl::Buffer buffer_HBM_embedding31(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
                                                         HBM_embedding31_size * sizeof(D_TYPE), &HBM_embedding31Ext, &err));

        // OCL_CHECK(err, cl::Buffer buffer_DDR_embedding0(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
        //         DDR_embedding0_size *sizeof(int), &DDR_embedding0Ext, &err));
        // OCL_CHECK(err, cl::Buffer buffer_DDR_embedding1(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
        //         DDR_embedding1_size *sizeof(int), &DDR_embedding1Ext, &err));

        //     OCL_CHECK(err, cl::Buffer buffer_PLRAM_embedding0(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
        //             PLRAM_embedding0_size *sizeof(int), &PLRAM_embedding0Ext, &err));
        //     OCL_CHECK(err, cl::Buffer buffer_PLRAM_embedding1(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
        //             PLRAM_embedding1_size *sizeof(int), &PLRAM_embedding1Ext, &err));
        //     OCL_CHECK(err, cl::Buffer buffer_PLRAM_embedding2(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
        //             PLRAM_embedding2_size *sizeof(int), &PLRAM_embedding2Ext, &err));
        //     OCL_CHECK(err, cl::Buffer buffer_PLRAM_embedding3(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
        //             PLRAM_embedding3_size *sizeof(int), &PLRAM_embedding3Ext, &err));
        //////////////////////////////   TEMPLATE END  //////////////////////////////
        //     OCL_CHECK(err, cl::Buffer buffer_idx(context,
        //         CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY | CL_MEM_EXT_PTR_XILINX,
        //         idx_size *sizeof(int), &access_idxExt, &err));
        // .......................................................
        // Allocate Global Memory for sourcce_hw_results
        // .......................................................
        OCL_CHECK(err, cl::Buffer buffer_output(
                           context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY | CL_MEM_EXT_PTR_XILINX,
                           result_size * sizeof(D_TYPE), &sourcce_hw_resultsExt, &err));

        // ============================================================================
        // Step 2: Set Kernel Arguments and Run the Application
        //         o) Set Kernel Arguments
        //         o) Copy Input Data from Host to Global Memory on the device
        //         o) Submit Kernels for Execution
        //         o) Copy Results from Global Memory, device to Host
        // ============================================================================

        std::vector<D_TYPE> host_buffer(HBM_embedding0_size);
        // Read back the buffer content
        OCL_CHECK(err, err = q.enqueueReadBuffer(buffer_HBM_embedding0, CL_TRUE, 0,
                                                 HBM_embedding0_size * sizeof(D_TYPE),
                                                 host_buffer.data()));

        //////////////////////////////   TEMPLATE START  //////////////////////////////
        OCL_CHECK(err, err = krnl_vector_add.setArg(0, buffer_HBM_embedding0));
        OCL_CHECK(err, err = krnl_vector_add.setArg(1, buffer_HBM_embedding1));
        OCL_CHECK(err, err = krnl_vector_add.setArg(2, buffer_HBM_embedding2));
        OCL_CHECK(err, err = krnl_vector_add.setArg(3, buffer_HBM_embedding3));
        OCL_CHECK(err, err = krnl_vector_add.setArg(4, buffer_HBM_embedding4));
        OCL_CHECK(err, err = krnl_vector_add.setArg(5, buffer_HBM_embedding5));
        OCL_CHECK(err, err = krnl_vector_add.setArg(6, buffer_HBM_embedding6));
        OCL_CHECK(err, err = krnl_vector_add.setArg(7, buffer_HBM_embedding7));
        OCL_CHECK(err, err = krnl_vector_add.setArg(8, buffer_HBM_embedding8));
        OCL_CHECK(err, err = krnl_vector_add.setArg(9, buffer_HBM_embedding9));
        OCL_CHECK(err, err = krnl_vector_add.setArg(10, buffer_HBM_embedding10));
        OCL_CHECK(err, err = krnl_vector_add.setArg(11, buffer_HBM_embedding11));
        OCL_CHECK(err, err = krnl_vector_add.setArg(12, buffer_HBM_embedding12));
        OCL_CHECK(err, err = krnl_vector_add.setArg(13, buffer_HBM_embedding13));
        OCL_CHECK(err, err = krnl_vector_add.setArg(14, buffer_HBM_embedding14));
        OCL_CHECK(err, err = krnl_vector_add.setArg(15, buffer_HBM_embedding15));
        OCL_CHECK(err, err = krnl_vector_add.setArg(16, buffer_HBM_embedding16));
        OCL_CHECK(err, err = krnl_vector_add.setArg(17, buffer_HBM_embedding17));
        OCL_CHECK(err, err = krnl_vector_add.setArg(18, buffer_HBM_embedding18));
        OCL_CHECK(err, err = krnl_vector_add.setArg(19, buffer_HBM_embedding19));
        OCL_CHECK(err, err = krnl_vector_add.setArg(20, buffer_HBM_embedding20));
        OCL_CHECK(err, err = krnl_vector_add.setArg(21, buffer_HBM_embedding21));
        OCL_CHECK(err, err = krnl_vector_add.setArg(22, buffer_HBM_embedding22));
        OCL_CHECK(err, err = krnl_vector_add.setArg(23, buffer_HBM_embedding23));
        OCL_CHECK(err, err = krnl_vector_add.setArg(24, buffer_HBM_embedding24));
        OCL_CHECK(err, err = krnl_vector_add.setArg(25, buffer_HBM_embedding25));
        OCL_CHECK(err, err = krnl_vector_add.setArg(26, buffer_HBM_embedding26));
        OCL_CHECK(err, err = krnl_vector_add.setArg(27, buffer_HBM_embedding27));
        OCL_CHECK(err, err = krnl_vector_add.setArg(28, buffer_HBM_embedding28));
        OCL_CHECK(err, err = krnl_vector_add.setArg(29, buffer_HBM_embedding29));
        OCL_CHECK(err, err = krnl_vector_add.setArg(30, buffer_HBM_embedding30));
        OCL_CHECK(err, err = krnl_vector_add.setArg(31, buffer_HBM_embedding31));

        // OCL_CHECK(err, err = krnl_vector_add.setArg(0 + 32, buffer_DDR_embedding0));
        // OCL_CHECK(err, err = krnl_vector_add.setArg(1 + 32, buffer_DDR_embedding1));

        //     OCL_CHECK(err, err = krnl_vector_add.setArg(0 + 34, buffer_PLRAM_embedding0));
        //     OCL_CHECK(err, err = krnl_vector_add.setArg(1 + 34, buffer_PLRAM_embedding1));
        //     OCL_CHECK(err, err = krnl_vector_add.setArg(2 + 34, buffer_PLRAM_embedding2));
        //     OCL_CHECK(err, err = krnl_vector_add.setArg(3 + 34, buffer_PLRAM_embedding3));
        //////////////////////////////   TEMPLATE END  //////////////////////////////

        // NOTE! Manually adjust this!
        // use replicate_str.py, set totol_num = 1 start=47
        //////////////////////////////   TEMPLATE START  //////////////////////////////
        //     OCL_CHECK(err, err = krnl_vector_add.setArg(38, buffer_idx));
        //////////////////////////////   TEMPLATE END  //////////////////////////////
        //////////////////////////////   TEMPLATE START  //////////////////////////////
        OCL_CHECK(err, err = krnl_vector_add.setArg(32, buffer_output));
        //////////////////////////////   TEMPLATE END  //////////////////////////////
        // ------------------------------------------------------
        // Step 2: Copy Input data from Host to Global Memory on the device
        // ------------------------------------------------------
        //////////////////////////////   TEMPLATE START  //////////////////////////////
        cl::Event write_event;

        OCL_CHECK(
            err, err = q.enqueueMigrateMemObjects({
                                                      buffer_HBM_embedding0, buffer_HBM_embedding1, buffer_HBM_embedding2, buffer_HBM_embedding3,
                                                      buffer_HBM_embedding4, buffer_HBM_embedding5, buffer_HBM_embedding6, buffer_HBM_embedding7,
                                                      buffer_HBM_embedding8, buffer_HBM_embedding9, buffer_HBM_embedding10, buffer_HBM_embedding11,
                                                      buffer_HBM_embedding12, buffer_HBM_embedding13, buffer_HBM_embedding14, buffer_HBM_embedding15,
                                                      buffer_HBM_embedding16, buffer_HBM_embedding17, buffer_HBM_embedding18, buffer_HBM_embedding19,
                                                      buffer_HBM_embedding20, buffer_HBM_embedding21, buffer_HBM_embedding22, buffer_HBM_embedding23,
                                                      buffer_HBM_embedding24, buffer_HBM_embedding25, buffer_HBM_embedding26, buffer_HBM_embedding27,
                                                      buffer_HBM_embedding28, buffer_HBM_embedding29, buffer_HBM_embedding30, buffer_HBM_embedding31,
                                                      // buffer_DDR_embedding0, buffer_DDR_embedding1 ,
                                                      /* buffer_PLRAM_embedding0, buffer_PLRAM_embedding1, buffer_PLRAM_embedding2, buffer_PLRAM_embedding3,
                                                      buffer_idx */
                                                  },
                                                  0 /* 0 means from host*/, nullptr, &write_event));

        //////////////////////////////   TEMPLATE END  //////////////////////////////
        // ----------------------------------------
        // Step 2: Submit Kernels for Execution
        // ----------------------------------------
        cl::Event kernel_event, read_event;
        OCL_CHECK(err, err = q.enqueueTask(krnl_vector_add, nullptr, &kernel_event));
        std::vector<cl::Event> wait_list = {kernel_event};
        // --------------------------------------------------
        // Step 2: Copy Results from Device Global Memory to Host
        // --------------------------------------------------
        OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output}, CL_MIGRATE_MEM_OBJECT_HOST, &wait_list, &read_event));

        q.finish();

        // OPENCL HOST CODE AREA END

        // Compare the results of the Device to the simulation
        // only check the last batch (since other are not transfered back)
        bool match = true;
        for (int i = 0; i < BATCH_SIZE; i++)
        {
                if (static_cast<D_TYPE>(source_hw_results[i]) != static_cast<D_TYPE>(source_sw_results[i]))
                {
                        std::cout << "Error: Result mismatch" << std::endl;
                        std::cout << "i = " << i << " CPU result = " << static_cast<D_TYPE>(source_sw_results[i])
                                  << " Device result = " << static_cast<D_TYPE>(source_hw_results[i]) << std::endl;
                        match = false;
                }
                else
                {
                        std::cout << "i = " << i << "\tresult = " << static_cast<D_TYPE>(source_sw_results[i]) << std::endl;
                }
        }

        // ============================================================================
        // Step 3: Release Allocated Resources
        // ============================================================================
        delete[] fileBuf;

        // ============================================================================
        // Extra step: measuring times
        // ============================================================================
        std::cout << "==== PROFILING INFO ====" << '\n';
        cl_ulong kernel_start_time = kernel_event.getProfilingInfo<CL_PROFILING_COMMAND_START>();
        cl_ulong kernel_end_time = kernel_event.getProfilingInfo<CL_PROFILING_COMMAND_END>();
        cl_ulong kernel_time = kernel_end_time - kernel_start_time;
        std::cout << "Kernel execution time: " << kernel_time / 1e6 << " ms" << '\n';

        cl_ulong read_start_time = read_event.getProfilingInfo<CL_PROFILING_COMMAND_START>();
        cl_ulong read_end_time = read_event.getProfilingInfo<CL_PROFILING_COMMAND_END>();
        cl_ulong write_start_time = write_event.getProfilingInfo<CL_PROFILING_COMMAND_START>();
        cl_ulong write_end_time = write_event.getProfilingInfo<CL_PROFILING_COMMAND_END>();
        cl_ulong transfer_time = ((write_end_time - write_start_time) + (read_end_time - read_start_time));

        std::cout << "Data transfer time: " << transfer_time / 1e6 << " ms" << '\n';
        std::cout << "\tHost to device: " << (write_end_time - write_start_time) / 1e6 << " ms" << '\n';
        std::cout << "\tDevice to host: " << (read_end_time - read_start_time) / 1e6 << " ms" << '\n';
        std::cout << "Total time: " << (kernel_time + transfer_time) / 1e6 << " ms" << '\n';
        std::cout << "========================" << '\n';

        std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;
        return (match ? EXIT_SUCCESS : EXIT_FAILURE);
}