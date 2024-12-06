#include <hls_stream.h>
#include <iostream>
#include <cmath>

#include "constants.hpp"

extern "C" {

/**
 * @name    vadd
 * @brief   Performs vector addition on data from multiple HBM banks and stores the result.
 * 
 * This function reads data from 32 High Bandwidth Memory (HBM) banks, performs vector addition
 * across all data elements, and writes the final result to a designated output memory location.
 * The function is optimized for HLS (High-Level Synthesis) with DATAFLOW and INTERFACE pragmas
 * to maximize data throughput and minimize latency.
 *
 * @param[in]  table_HBM0 to table_HBM31: Pointers to input data in each of the 32 HBM banks.
 * @param[out] out: Pointer to the output memory location for the result.
 */
void vadd(  
    const ap_int<AXI_WIDTH_HBM>* table_HBM0, const ap_int<AXI_WIDTH_HBM>* table_HBM1, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM2, const ap_int<AXI_WIDTH_HBM>* table_HBM3, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM4, const ap_int<AXI_WIDTH_HBM>* table_HBM5, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM6, const ap_int<AXI_WIDTH_HBM>* table_HBM7, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM8, const ap_int<AXI_WIDTH_HBM>* table_HBM9, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM10, const ap_int<AXI_WIDTH_HBM>* table_HBM11, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM12, const ap_int<AXI_WIDTH_HBM>* table_HBM13, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM14, const ap_int<AXI_WIDTH_HBM>* table_HBM15, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM16, const ap_int<AXI_WIDTH_HBM>* table_HBM17, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM18, const ap_int<AXI_WIDTH_HBM>* table_HBM19, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM20, const ap_int<AXI_WIDTH_HBM>* table_HBM21, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM22, const ap_int<AXI_WIDTH_HBM>* table_HBM23, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM24, const ap_int<AXI_WIDTH_HBM>* table_HBM25, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM26, const ap_int<AXI_WIDTH_HBM>* table_HBM27, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM28, const ap_int<AXI_WIDTH_HBM>* table_HBM29, 
    const ap_int<AXI_WIDTH_HBM>* table_HBM30, const ap_int<AXI_WIDTH_HBM>* table_HBM31,
    D_TYPE *out
    );
}

/**
 * @name    load_access_idx
 * @brief   Loads index data into multiple HBM stream buffers for parallel processing.
 *
 * This function initializes and populates 32 streams, each corresponding to a specific HBM bank.
 * The indices loaded into these streams determine which data segments will be accessed from the
 * respective HBM banks in subsequent processing stages. This setup is essential for data parallel
 * operations where each HBM bank can be accessed independently to optimize throughput and minimize
 * access latency.
 *
 * @param[out] s_idx_buffer_HBM0 to s_idx_buffer_HBM31: References to stream buffers for each HBM bank.
 */
void load_access_idx(
    // const int access_idx_local[BATCH_SIZE * BATCH_NUM], 
    hls::stream<int>& s_idx_buffer_HBM0, hls::stream<int>& s_idx_buffer_HBM1, 
    hls::stream<int>& s_idx_buffer_HBM2, hls::stream<int>& s_idx_buffer_HBM3, 
    hls::stream<int>& s_idx_buffer_HBM4, hls::stream<int>& s_idx_buffer_HBM5, 
    hls::stream<int>& s_idx_buffer_HBM6, hls::stream<int>& s_idx_buffer_HBM7, 
    hls::stream<int>& s_idx_buffer_HBM8, hls::stream<int>& s_idx_buffer_HBM9, 
    hls::stream<int>& s_idx_buffer_HBM10, hls::stream<int>& s_idx_buffer_HBM11, 
    hls::stream<int>& s_idx_buffer_HBM12, hls::stream<int>& s_idx_buffer_HBM13, 
    hls::stream<int>& s_idx_buffer_HBM14, hls::stream<int>& s_idx_buffer_HBM15, 
    hls::stream<int>& s_idx_buffer_HBM16, hls::stream<int>& s_idx_buffer_HBM17, 
    hls::stream<int>& s_idx_buffer_HBM18, hls::stream<int>& s_idx_buffer_HBM19, 
    hls::stream<int>& s_idx_buffer_HBM20, hls::stream<int>& s_idx_buffer_HBM21, 
    hls::stream<int>& s_idx_buffer_HBM22, hls::stream<int>& s_idx_buffer_HBM23, 
    hls::stream<int>& s_idx_buffer_HBM24, hls::stream<int>& s_idx_buffer_HBM25, 
    hls::stream<int>& s_idx_buffer_HBM26, hls::stream<int>& s_idx_buffer_HBM27, 
    hls::stream<int>& s_idx_buffer_HBM28, hls::stream<int>& s_idx_buffer_HBM29, 
    hls::stream<int>& s_idx_buffer_HBM30, hls::stream<int>& s_idx_buffer_HBM31);

/**
 * @name load_single_embedding_1_tables
 * @brief   Loads data from memory into a stream based on specified indices.
 *
 * This template function reads data from a high-bandwidth memory (HBM) or similar storage
 * based on provided indices, and then loads this data into an output stream for further processing.
 * The function reads a block of data whose size is defined by AXI_PADDED_SIZE_0 for each index
 * in s_idx_buffer. 
 *
 * @tparam START_ADDR_0       The starting address in the memory from where data loading should begin.
 * @tparam AXI_PADDED_SIZE_0  The size of each data block to be accessed, accounting for any padding.
 * @param[in]  s_idx_buffer         Stream of indices indicating which data blocks to load.
 * @param[in]  table_RAM            Pointer to the memory region containing the data to be loaded.
 * @param[out] s_embedding_buffer   Stream where the loaded data will be written for further processing.
 */
template<const long START_ADDR_0, const long AXI_PADDED_SIZE_0>
void load_single_embedding_1_tables(
    hls::stream<int>& s_idx_buffer, const t_hbm* table_RAM, 
    hls::stream<t_hbm>& s_embedding_buffer);

/**
 * @name load_single_embedding_2_tables
 * @brief   Loads data from memory into a stream based on specified indices.
 *
 * @tparam START_ADDR_0       The starting address in the memory from where data loading should begin.
 * @tparam AXI_PADDED_SIZE_0  The size of each data block to be accessed, accounting for any padding.
 * @param[in]  s_idx_buffer         Stream of indices indicating which data blocks to load.
 * @param[in]  table_RAM            Pointer to the memory region containing the data to be loaded.
 * @param[out] s_embedding_buffer   Stream where the loaded data will be written for further processing.
 */
template<const long START_ADDR_0, const long AXI_PADDED_SIZE_0>
void load_single_embedding_2_tables(
    hls::stream<int>& s_idx_buffer, const t_hbm* table_RAM, 
    hls::stream<t_hbm>& s_embedding_buffer);

/**
 * @name    reduction_add_single
 * @brief   Performs reduction (addition) operation on a stream of data.
 *
 * This template function processes a stream of vector data elements from an input buffer, 
 * performs a reduction operation (specifically, adding elements), and writes the result to 
 * an output stream. The function is specialized for scenarios where the result of the addition
 * is a single value from among the vectors (e.g., the first element of each vector), which is
 * then written to the result stream.
 *
 * @tparam TOTAL_VECTOR_LENGTH  The total number of elements in each vector to be processed.
 * @param[in]  s_embedding_buffer  Stream of vectors from which data is read.
 * @param[out] s_result_buffer     Stream where the result of the reduction is written.
 */
template<const int TOTAL_VECTOR_LENGTH>
void reduction_add_single(
    hls::stream<t_hbm>& s_embedding_buffer, 
    hls::stream<D_TYPE>& s_result_buffer);

/**
 * @name    reduction_add_all
 * @brief   Aggregates results from multiple streams into a single output stream.
 *
 * This function reads integer values from multiple input streams (representing different HBM
 * buffers), performs an addition operation to aggregate the values, and writes the cumulative
 * result into a single output stream. The aggregation is structured in stages to minimize the
 * latency and optimize the use of FPGA resources by handling large numbers of input streams efficiently.
 *
 * @param[in]  s_result_buffer_HBM0 to s_result_buffer_HBM31: Input streams containing integer results.
 * @param[out] s_vout_buffer: Output stream where the aggregated result is written.
 */
void reduction_add_all(
    hls::stream<D_TYPE>& s_result_buffer_HBM0, hls::stream<D_TYPE>& s_result_buffer_HBM1, 
    hls::stream<D_TYPE>& s_result_buffer_HBM2, hls::stream<D_TYPE>& s_result_buffer_HBM3, 
    hls::stream<D_TYPE>& s_result_buffer_HBM4, hls::stream<D_TYPE>& s_result_buffer_HBM5, 
    hls::stream<D_TYPE>& s_result_buffer_HBM6, hls::stream<D_TYPE>& s_result_buffer_HBM7, 
    hls::stream<D_TYPE>& s_result_buffer_HBM8, hls::stream<D_TYPE>& s_result_buffer_HBM9, 
    hls::stream<D_TYPE>& s_result_buffer_HBM10, hls::stream<D_TYPE>& s_result_buffer_HBM11, 
    hls::stream<D_TYPE>& s_result_buffer_HBM12, hls::stream<D_TYPE>& s_result_buffer_HBM13, 
    hls::stream<D_TYPE>& s_result_buffer_HBM14, hls::stream<D_TYPE>& s_result_buffer_HBM15, 
    hls::stream<D_TYPE>& s_result_buffer_HBM16, hls::stream<D_TYPE>& s_result_buffer_HBM17, 
    hls::stream<D_TYPE>& s_result_buffer_HBM18, hls::stream<D_TYPE>& s_result_buffer_HBM19, 
    hls::stream<D_TYPE>& s_result_buffer_HBM20, hls::stream<D_TYPE>& s_result_buffer_HBM21, 
    hls::stream<D_TYPE>& s_result_buffer_HBM22, hls::stream<D_TYPE>& s_result_buffer_HBM23, 
    hls::stream<D_TYPE>& s_result_buffer_HBM24, hls::stream<D_TYPE>& s_result_buffer_HBM25, 
    hls::stream<D_TYPE>& s_result_buffer_HBM26, hls::stream<D_TYPE>& s_result_buffer_HBM27, 
    hls::stream<D_TYPE>& s_result_buffer_HBM28, hls::stream<D_TYPE>& s_result_buffer_HBM29, 
    hls::stream<D_TYPE>& s_result_buffer_HBM30, hls::stream<D_TYPE>& s_result_buffer_HBM31,
    hls::stream<D_TYPE>& s_vout_buffer);

/**
 * @name    write_results
 * @brief   Writes results from a stream to an output array.
 *
 * This function reads integer values from an input stream and writes them into an array in memory.
 * It's designed to process a batch of results stored in a stream, transferring them to local memory.
 * This function handles the transfer in two stages: reading from the
 * stream into a local buffer, then writing from the local buffer to the output array.
 *
 * @param[in]  s_vout_buffer  Input stream containing the results to be written.
 * @param[out] out_RAM        Array where the results are stored after reading from the stream.
 */
void write_results(
    hls::stream<D_TYPE>& s_vout_buffer, D_TYPE out_RAM[BATCH_SIZE]);


const int trip_count_item_num = BATCH_NUM * BATCH_SIZE;

const int fifo_batch_size = FIFO_BATCH_SIZE;

const int depth_s_embedding_buffer_HBM0 = VECTOR_SIZE_HBM_BANK_0 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM1 = VECTOR_SIZE_HBM_BANK_1 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM2 = VECTOR_SIZE_HBM_BANK_2 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM3 = VECTOR_SIZE_HBM_BANK_3 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM4 = VECTOR_SIZE_HBM_BANK_4 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM5 = VECTOR_SIZE_HBM_BANK_5 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM6 = VECTOR_SIZE_HBM_BANK_6 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM7 = VECTOR_SIZE_HBM_BANK_7 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM8 = VECTOR_SIZE_HBM_BANK_8 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM9 = VECTOR_SIZE_HBM_BANK_9 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM10 = VECTOR_SIZE_HBM_BANK_10 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM11 = VECTOR_SIZE_HBM_BANK_11 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM12 = VECTOR_SIZE_HBM_BANK_12 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM13 = VECTOR_SIZE_HBM_BANK_13 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM14 = VECTOR_SIZE_HBM_BANK_14 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM15 = VECTOR_SIZE_HBM_BANK_15 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM16 = VECTOR_SIZE_HBM_BANK_16 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM17 = VECTOR_SIZE_HBM_BANK_17 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM18 = VECTOR_SIZE_HBM_BANK_18 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM19 = VECTOR_SIZE_HBM_BANK_19 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM20 = VECTOR_SIZE_HBM_BANK_20 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM21 = VECTOR_SIZE_HBM_BANK_21 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM22 = VECTOR_SIZE_HBM_BANK_22 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM23 = VECTOR_SIZE_HBM_BANK_23 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM24 = VECTOR_SIZE_HBM_BANK_24 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM25 = VECTOR_SIZE_HBM_BANK_25 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM26 = VECTOR_SIZE_HBM_BANK_26 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM27 = VECTOR_SIZE_HBM_BANK_27 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM28 = VECTOR_SIZE_HBM_BANK_28 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM29 = VECTOR_SIZE_HBM_BANK_29 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM30 = VECTOR_SIZE_HBM_BANK_30 * FIFO_BATCH_SIZE;
const int depth_s_embedding_buffer_HBM31 = VECTOR_SIZE_HBM_BANK_31 * FIFO_BATCH_SIZE;

// const int depth_s_embedding_buffer_PLRAM0 = VECTOR_SIZE_PLRAM_BANK_0 * FIFO_BATCH_SIZE;
// const int depth_s_embedding_buffer_PLRAM1 = VECTOR_SIZE_PLRAM_BANK_1 * FIFO_BATCH_SIZE;
// const int depth_s_embedding_buffer_PLRAM2 = VECTOR_SIZE_PLRAM_BANK_2 * FIFO_BATCH_SIZE;
// const int depth_s_embedding_buffer_PLRAM3 = VECTOR_SIZE_PLRAM_BANK_3 * FIFO_BATCH_SIZE;

// const int depth_s_embedding_buffer_DDR0 = VECTOR_SIZE_DDR_BANK_0 * FIFO_BATCH_SIZE;
// const int depth_s_embedding_buffer_DDR1 = VECTOR_SIZE_DDR_BANK_1 * FIFO_BATCH_SIZE;