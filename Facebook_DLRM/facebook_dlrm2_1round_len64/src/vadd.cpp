#include "vadd.hpp"

void vadd(
    const ap_int<AXI_WIDTH_HBM > *table_HBM0, const ap_int<AXI_WIDTH_HBM > *table_HBM1,
    const ap_int<AXI_WIDTH_HBM > *table_HBM2, const ap_int<AXI_WIDTH_HBM > *table_HBM3,
    const ap_int<AXI_WIDTH_HBM > *table_HBM4, const ap_int<AXI_WIDTH_HBM > *table_HBM5,
    const ap_int<AXI_WIDTH_HBM > *table_HBM6, const ap_int<AXI_WIDTH_HBM > *table_HBM7,
    const ap_int<AXI_WIDTH_HBM > *table_HBM8, const ap_int<AXI_WIDTH_HBM > *table_HBM9,
    const ap_int<AXI_WIDTH_HBM > *table_HBM10, const ap_int<AXI_WIDTH_HBM > *table_HBM11,
    const ap_int<AXI_WIDTH_HBM > *table_HBM12, const ap_int<AXI_WIDTH_HBM > *table_HBM13,
    const ap_int<AXI_WIDTH_HBM > *table_HBM14, const ap_int<AXI_WIDTH_HBM > *table_HBM15,
    const ap_int<AXI_WIDTH_HBM > *table_HBM16, const ap_int<AXI_WIDTH_HBM > *table_HBM17,
    const ap_int<AXI_WIDTH_HBM > *table_HBM18, const ap_int<AXI_WIDTH_HBM > *table_HBM19,
    const ap_int<AXI_WIDTH_HBM > *table_HBM20, const ap_int<AXI_WIDTH_HBM > *table_HBM21,
    const ap_int<AXI_WIDTH_HBM > *table_HBM22, const ap_int<AXI_WIDTH_HBM > *table_HBM23,
    const ap_int<AXI_WIDTH_HBM > *table_HBM24, const ap_int<AXI_WIDTH_HBM > *table_HBM25,
    const ap_int<AXI_WIDTH_HBM > *table_HBM26, const ap_int<AXI_WIDTH_HBM > *table_HBM27,
    const ap_int<AXI_WIDTH_HBM > *table_HBM28, const ap_int<AXI_WIDTH_HBM > *table_HBM29,
    const ap_int<AXI_WIDTH_HBM > *table_HBM30, const ap_int<AXI_WIDTH_HBM > *table_HBM31,
    D_TYPE *out)
{
    // Enable task-level parallelism
    #pragma HLS DATAFLOW

    // Interfaces for each HBM bank, enabling independent memory access with AXI protocol
    #pragma HLS INTERFACE m_axi port = table_HBM0 offset = slave bundle = gmem0
    #pragma HLS INTERFACE m_axi port = table_HBM1 offset = slave bundle = gmem1
    #pragma HLS INTERFACE m_axi port = table_HBM2 offset = slave bundle = gmem2
    #pragma HLS INTERFACE m_axi port = table_HBM3 offset = slave bundle = gmem3
    #pragma HLS INTERFACE m_axi port = table_HBM4 offset = slave bundle = gmem4
    #pragma HLS INTERFACE m_axi port = table_HBM5 offset = slave bundle = gmem5
    #pragma HLS INTERFACE m_axi port = table_HBM6 offset = slave bundle = gmem6
    #pragma HLS INTERFACE m_axi port = table_HBM7 offset = slave bundle = gmem7
    #pragma HLS INTERFACE m_axi port = table_HBM8 offset = slave bundle = gmem8
    #pragma HLS INTERFACE m_axi port = table_HBM9 offset = slave bundle = gmem9
    #pragma HLS INTERFACE m_axi port = table_HBM10 offset = slave bundle = gmem10
    #pragma HLS INTERFACE m_axi port = table_HBM11 offset = slave bundle = gmem11
    #pragma HLS INTERFACE m_axi port = table_HBM12 offset = slave bundle = gmem12
    #pragma HLS INTERFACE m_axi port = table_HBM13 offset = slave bundle = gmem13
    #pragma HLS INTERFACE m_axi port = table_HBM14 offset = slave bundle = gmem14
    #pragma HLS INTERFACE m_axi port = table_HBM15 offset = slave bundle = gmem15
    #pragma HLS INTERFACE m_axi port = table_HBM16 offset = slave bundle = gmem16
    #pragma HLS INTERFACE m_axi port = table_HBM17 offset = slave bundle = gmem17
    #pragma HLS INTERFACE m_axi port = table_HBM18 offset = slave bundle = gmem18
    #pragma HLS INTERFACE m_axi port = table_HBM19 offset = slave bundle = gmem19
    #pragma HLS INTERFACE m_axi port = table_HBM20 offset = slave bundle = gmem20
    #pragma HLS INTERFACE m_axi port = table_HBM21 offset = slave bundle = gmem21
    #pragma HLS INTERFACE m_axi port = table_HBM22 offset = slave bundle = gmem22
    #pragma HLS INTERFACE m_axi port = table_HBM23 offset = slave bundle = gmem23
    #pragma HLS INTERFACE m_axi port = table_HBM24 offset = slave bundle = gmem24
    #pragma HLS INTERFACE m_axi port = table_HBM25 offset = slave bundle = gmem25
    #pragma HLS INTERFACE m_axi port = table_HBM26 offset = slave bundle = gmem26
    #pragma HLS INTERFACE m_axi port = table_HBM27 offset = slave bundle = gmem27
    #pragma HLS INTERFACE m_axi port = table_HBM28 offset = slave bundle = gmem28
    #pragma HLS INTERFACE m_axi port = table_HBM29 offset = slave bundle = gmem29
    #pragma HLS INTERFACE m_axi port = table_HBM30 offset = slave bundle = gmem30
    #pragma HLS INTERFACE m_axi port = table_HBM31 offset = slave bundle = gmem31

    #pragma HLS INTERFACE m_axi port = out offset = slave bundle = gmem34 

    // Set up AXILite control interfaces for each HBM port and output
    #pragma HLS INTERFACE s_axilite port = table_HBM0 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM1 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM2 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM3 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM4 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM5 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM6 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM7 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM8 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM9 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM10 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM11 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM12 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM13 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM14 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM15 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM16 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM17 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM18 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM19 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM20 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM21 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM22 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM23 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM24 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM25 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM26 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM27 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM28 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM29 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM30 bundle = control
    #pragma HLS INTERFACE s_axilite port = table_HBM31 bundle = control

    #pragma HLS INTERFACE s_axilite port = out bundle = control
    #pragma HLS INTERFACE s_axilite port = return bundle = control

    // Stream declarations for buffering embedding
    hls::stream<t_hbm> s_embedding_buffer_HBM0;
    hls::stream<t_hbm> s_embedding_buffer_HBM1;
    hls::stream<t_hbm> s_embedding_buffer_HBM2;
    hls::stream<t_hbm> s_embedding_buffer_HBM3;
    hls::stream<t_hbm> s_embedding_buffer_HBM4;
    hls::stream<t_hbm> s_embedding_buffer_HBM5;
    hls::stream<t_hbm> s_embedding_buffer_HBM6;
    hls::stream<t_hbm> s_embedding_buffer_HBM7;
    hls::stream<t_hbm> s_embedding_buffer_HBM8;
    hls::stream<t_hbm> s_embedding_buffer_HBM9;
    hls::stream<t_hbm> s_embedding_buffer_HBM10;
    hls::stream<t_hbm> s_embedding_buffer_HBM11;
    hls::stream<t_hbm> s_embedding_buffer_HBM12;
    hls::stream<t_hbm> s_embedding_buffer_HBM13;
    hls::stream<t_hbm> s_embedding_buffer_HBM14;
    hls::stream<t_hbm> s_embedding_buffer_HBM15;
    hls::stream<t_hbm> s_embedding_buffer_HBM16;
    hls::stream<t_hbm> s_embedding_buffer_HBM17;
    hls::stream<t_hbm> s_embedding_buffer_HBM18;
    hls::stream<t_hbm> s_embedding_buffer_HBM19;
    hls::stream<t_hbm> s_embedding_buffer_HBM20;
    hls::stream<t_hbm> s_embedding_buffer_HBM21;
    hls::stream<t_hbm> s_embedding_buffer_HBM22;
    hls::stream<t_hbm> s_embedding_buffer_HBM23;
    hls::stream<t_hbm> s_embedding_buffer_HBM24;
    hls::stream<t_hbm> s_embedding_buffer_HBM25;
    hls::stream<t_hbm> s_embedding_buffer_HBM26;
    hls::stream<t_hbm> s_embedding_buffer_HBM27;
    hls::stream<t_hbm> s_embedding_buffer_HBM28;
    hls::stream<t_hbm> s_embedding_buffer_HBM29;
    hls::stream<t_hbm> s_embedding_buffer_HBM30;
    hls::stream<t_hbm> s_embedding_buffer_HBM31;
    
    // Set the FIFO depth for the stream buffer of s_embedding_buffer_HBM0  
    // to s_embedding_buffer_HBM31 to manage data flow efficiently
    #pragma HLS stream variable = s_embedding_buffer_HBM0 depth = depth_s_embedding_buffer_HBM0
    #pragma HLS stream variable = s_embedding_buffer_HBM1 depth = depth_s_embedding_buffer_HBM1
    #pragma HLS stream variable = s_embedding_buffer_HBM2 depth = depth_s_embedding_buffer_HBM2
    #pragma HLS stream variable = s_embedding_buffer_HBM3 depth = depth_s_embedding_buffer_HBM3
    #pragma HLS stream variable = s_embedding_buffer_HBM4 depth = depth_s_embedding_buffer_HBM4
    #pragma HLS stream variable = s_embedding_buffer_HBM5 depth = depth_s_embedding_buffer_HBM5
    #pragma HLS stream variable = s_embedding_buffer_HBM6 depth = depth_s_embedding_buffer_HBM6
    #pragma HLS stream variable = s_embedding_buffer_HBM7 depth = depth_s_embedding_buffer_HBM7
    #pragma HLS stream variable = s_embedding_buffer_HBM8 depth = depth_s_embedding_buffer_HBM8
    #pragma HLS stream variable = s_embedding_buffer_HBM9 depth = depth_s_embedding_buffer_HBM9
    #pragma HLS stream variable = s_embedding_buffer_HBM10 depth = depth_s_embedding_buffer_HBM10
    #pragma HLS stream variable = s_embedding_buffer_HBM11 depth = depth_s_embedding_buffer_HBM11
    #pragma HLS stream variable = s_embedding_buffer_HBM12 depth = depth_s_embedding_buffer_HBM12
    #pragma HLS stream variable = s_embedding_buffer_HBM13 depth = depth_s_embedding_buffer_HBM13
    #pragma HLS stream variable = s_embedding_buffer_HBM14 depth = depth_s_embedding_buffer_HBM14
    #pragma HLS stream variable = s_embedding_buffer_HBM15 depth = depth_s_embedding_buffer_HBM15
    #pragma HLS stream variable = s_embedding_buffer_HBM16 depth = depth_s_embedding_buffer_HBM16
    #pragma HLS stream variable = s_embedding_buffer_HBM17 depth = depth_s_embedding_buffer_HBM17
    #pragma HLS stream variable = s_embedding_buffer_HBM18 depth = depth_s_embedding_buffer_HBM18
    #pragma HLS stream variable = s_embedding_buffer_HBM19 depth = depth_s_embedding_buffer_HBM19
    #pragma HLS stream variable = s_embedding_buffer_HBM20 depth = depth_s_embedding_buffer_HBM20
    #pragma HLS stream variable = s_embedding_buffer_HBM21 depth = depth_s_embedding_buffer_HBM21
    #pragma HLS stream variable = s_embedding_buffer_HBM22 depth = depth_s_embedding_buffer_HBM22
    #pragma HLS stream variable = s_embedding_buffer_HBM23 depth = depth_s_embedding_buffer_HBM23
    #pragma HLS stream variable = s_embedding_buffer_HBM24 depth = depth_s_embedding_buffer_HBM24
    #pragma HLS stream variable = s_embedding_buffer_HBM25 depth = depth_s_embedding_buffer_HBM25
    #pragma HLS stream variable = s_embedding_buffer_HBM26 depth = depth_s_embedding_buffer_HBM26
    #pragma HLS stream variable = s_embedding_buffer_HBM27 depth = depth_s_embedding_buffer_HBM27
    #pragma HLS stream variable = s_embedding_buffer_HBM28 depth = depth_s_embedding_buffer_HBM28
    #pragma HLS stream variable = s_embedding_buffer_HBM29 depth = depth_s_embedding_buffer_HBM29
    #pragma HLS stream variable = s_embedding_buffer_HBM30 depth = depth_s_embedding_buffer_HBM30
    #pragma HLS stream variable = s_embedding_buffer_HBM31 depth = depth_s_embedding_buffer_HBM31

    // Stream declarations for index data
    hls::stream<int> s_idx_buffer_HBM0;
    hls::stream<int> s_idx_buffer_HBM1;
    hls::stream<int> s_idx_buffer_HBM2;
    hls::stream<int> s_idx_buffer_HBM3;
    hls::stream<int> s_idx_buffer_HBM4;
    hls::stream<int> s_idx_buffer_HBM5;
    hls::stream<int> s_idx_buffer_HBM6;
    hls::stream<int> s_idx_buffer_HBM7;
    hls::stream<int> s_idx_buffer_HBM8;
    hls::stream<int> s_idx_buffer_HBM9;
    hls::stream<int> s_idx_buffer_HBM10;
    hls::stream<int> s_idx_buffer_HBM11;
    hls::stream<int> s_idx_buffer_HBM12;
    hls::stream<int> s_idx_buffer_HBM13;
    hls::stream<int> s_idx_buffer_HBM14;
    hls::stream<int> s_idx_buffer_HBM15;
    hls::stream<int> s_idx_buffer_HBM16;
    hls::stream<int> s_idx_buffer_HBM17;
    hls::stream<int> s_idx_buffer_HBM18;
    hls::stream<int> s_idx_buffer_HBM19;
    hls::stream<int> s_idx_buffer_HBM20;
    hls::stream<int> s_idx_buffer_HBM21;
    hls::stream<int> s_idx_buffer_HBM22;
    hls::stream<int> s_idx_buffer_HBM23;
    hls::stream<int> s_idx_buffer_HBM24;
    hls::stream<int> s_idx_buffer_HBM25;
    hls::stream<int> s_idx_buffer_HBM26;
    hls::stream<int> s_idx_buffer_HBM27;
    hls::stream<int> s_idx_buffer_HBM28;
    hls::stream<int> s_idx_buffer_HBM29;
    hls::stream<int> s_idx_buffer_HBM30;
    hls::stream<int> s_idx_buffer_HBM31;

    // Stream depth specification to control the FIFO sizes used in index buffering
    #pragma HLS stream variable = s_idx_buffer_HBM0 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM1 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM2 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM3 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM4 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM5 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM6 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM7 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM8 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM9 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM10 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM11 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM12 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM13 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM14 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM15 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM16 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM17 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM18 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM19 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM20 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM21 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM22 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM23 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM24 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM25 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM26 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM27 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM28 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM29 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM30 depth = fifo_batch_size
    #pragma HLS stream variable = s_idx_buffer_HBM31 depth = fifo_batch_size

    // Stream declarations for results
    hls::stream<D_TYPE> s_result_buffer_HBM0;
    hls::stream<D_TYPE> s_result_buffer_HBM1;
    hls::stream<D_TYPE> s_result_buffer_HBM2;
    hls::stream<D_TYPE> s_result_buffer_HBM3;
    hls::stream<D_TYPE> s_result_buffer_HBM4;
    hls::stream<D_TYPE> s_result_buffer_HBM5;
    hls::stream<D_TYPE> s_result_buffer_HBM6;
    hls::stream<D_TYPE> s_result_buffer_HBM7;
    hls::stream<D_TYPE> s_result_buffer_HBM8;
    hls::stream<D_TYPE> s_result_buffer_HBM9;
    hls::stream<D_TYPE> s_result_buffer_HBM10;
    hls::stream<D_TYPE> s_result_buffer_HBM11;
    hls::stream<D_TYPE> s_result_buffer_HBM12;
    hls::stream<D_TYPE> s_result_buffer_HBM13;
    hls::stream<D_TYPE> s_result_buffer_HBM14;
    hls::stream<D_TYPE> s_result_buffer_HBM15;
    hls::stream<D_TYPE> s_result_buffer_HBM16;
    hls::stream<D_TYPE> s_result_buffer_HBM17;
    hls::stream<D_TYPE> s_result_buffer_HBM18;
    hls::stream<D_TYPE> s_result_buffer_HBM19;
    hls::stream<D_TYPE> s_result_buffer_HBM20;
    hls::stream<D_TYPE> s_result_buffer_HBM21;
    hls::stream<D_TYPE> s_result_buffer_HBM22;
    hls::stream<D_TYPE> s_result_buffer_HBM23;
    hls::stream<D_TYPE> s_result_buffer_HBM24;
    hls::stream<D_TYPE> s_result_buffer_HBM25;
    hls::stream<D_TYPE> s_result_buffer_HBM26;
    hls::stream<D_TYPE> s_result_buffer_HBM27;
    hls::stream<D_TYPE> s_result_buffer_HBM28;
    hls::stream<D_TYPE> s_result_buffer_HBM29;
    hls::stream<D_TYPE> s_result_buffer_HBM30;
    hls::stream<D_TYPE> s_result_buffer_HBM31;

    // Stream depth specification to control the FIFO sizes used in results buffering
    #pragma HLS stream variable = s_result_buffer_HBM0 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM1 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM2 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM3 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM4 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM5 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM6 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM7 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM8 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM9 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM10 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM11 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM12 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM13 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM14 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM15 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM16 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM17 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM18 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM19 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM20 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM21 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM22 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM23 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM24 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM25 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM26 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM27 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM28 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM29 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM30 depth = fifo_batch_size
    #pragma HLS stream variable = s_result_buffer_HBM31 depth = fifo_batch_size

    hls::stream<D_TYPE> s_vout_buffer;
    #pragma HLS stream variable = s_vout_buffer depth = fifo_batch_size

    // Load index values for each HBM bank
    load_access_idx(
        s_idx_buffer_HBM0, s_idx_buffer_HBM1, s_idx_buffer_HBM2, s_idx_buffer_HBM3,
        s_idx_buffer_HBM4, s_idx_buffer_HBM5, s_idx_buffer_HBM6, s_idx_buffer_HBM7,
        s_idx_buffer_HBM8, s_idx_buffer_HBM9, s_idx_buffer_HBM10, s_idx_buffer_HBM11,
        s_idx_buffer_HBM12, s_idx_buffer_HBM13, s_idx_buffer_HBM14, s_idx_buffer_HBM15,
        s_idx_buffer_HBM16, s_idx_buffer_HBM17, s_idx_buffer_HBM18, s_idx_buffer_HBM19,
        s_idx_buffer_HBM20, s_idx_buffer_HBM21, s_idx_buffer_HBM22, s_idx_buffer_HBM23,
        s_idx_buffer_HBM24, s_idx_buffer_HBM25, s_idx_buffer_HBM26, s_idx_buffer_HBM27,
        s_idx_buffer_HBM28, s_idx_buffer_HBM29, s_idx_buffer_HBM30, s_idx_buffer_HBM31);

    //////////////////////////////     Load Vectors & Concatenate     //////////////////////////////
    /** Specifically for this application: *******************************/ 
    // 8 ~ 12 table x 4 vector / table = 32 ~ 48 loads
    // maximum: 48 = 32 + 16, half of the channels has the second round
    /****************************************************************** */
    
    // Load and process embedding vectors from each HBM bank
    load_single_embedding_1_tables<ADDR_AXI_HBM_0, AXI_PADDED_SIZE_HBM_0>(
        s_idx_buffer_HBM0, table_HBM0, s_embedding_buffer_HBM0);
    load_single_embedding_1_tables<ADDR_AXI_HBM_1, AXI_PADDED_SIZE_HBM_1>(
        s_idx_buffer_HBM1, table_HBM1, s_embedding_buffer_HBM1);
    load_single_embedding_1_tables<ADDR_AXI_HBM_2, AXI_PADDED_SIZE_HBM_2>(
        s_idx_buffer_HBM2, table_HBM2, s_embedding_buffer_HBM2);
    load_single_embedding_1_tables<ADDR_AXI_HBM_3, AXI_PADDED_SIZE_HBM_3>(
        s_idx_buffer_HBM3, table_HBM3, s_embedding_buffer_HBM3);
    load_single_embedding_1_tables<ADDR_AXI_HBM_4, AXI_PADDED_SIZE_HBM_4>(
        s_idx_buffer_HBM4, table_HBM4, s_embedding_buffer_HBM4);
    load_single_embedding_1_tables<ADDR_AXI_HBM_5, AXI_PADDED_SIZE_HBM_5>(
        s_idx_buffer_HBM5, table_HBM5, s_embedding_buffer_HBM5);
    load_single_embedding_1_tables<ADDR_AXI_HBM_6, AXI_PADDED_SIZE_HBM_6>(
        s_idx_buffer_HBM6, table_HBM6, s_embedding_buffer_HBM6);
    load_single_embedding_1_tables<ADDR_AXI_HBM_7, AXI_PADDED_SIZE_HBM_7>(
        s_idx_buffer_HBM7, table_HBM7, s_embedding_buffer_HBM7);
    load_single_embedding_1_tables<ADDR_AXI_HBM_8, AXI_PADDED_SIZE_HBM_8>(
        s_idx_buffer_HBM8, table_HBM8, s_embedding_buffer_HBM8);
    load_single_embedding_1_tables<ADDR_AXI_HBM_9, AXI_PADDED_SIZE_HBM_9>(
        s_idx_buffer_HBM9, table_HBM9, s_embedding_buffer_HBM9);
    load_single_embedding_1_tables<ADDR_AXI_HBM_10, AXI_PADDED_SIZE_HBM_10>(
        s_idx_buffer_HBM10, table_HBM10, s_embedding_buffer_HBM10);
    load_single_embedding_1_tables<ADDR_AXI_HBM_11, AXI_PADDED_SIZE_HBM_11>(
        s_idx_buffer_HBM11, table_HBM11, s_embedding_buffer_HBM11);
    load_single_embedding_1_tables<ADDR_AXI_HBM_12, AXI_PADDED_SIZE_HBM_12>(
        s_idx_buffer_HBM12, table_HBM12, s_embedding_buffer_HBM12);
    load_single_embedding_1_tables<ADDR_AXI_HBM_13, AXI_PADDED_SIZE_HBM_13>(
        s_idx_buffer_HBM13, table_HBM13, s_embedding_buffer_HBM13);
    load_single_embedding_1_tables<ADDR_AXI_HBM_14, AXI_PADDED_SIZE_HBM_14>(
        s_idx_buffer_HBM14, table_HBM14, s_embedding_buffer_HBM14);
    load_single_embedding_1_tables<ADDR_AXI_HBM_15, AXI_PADDED_SIZE_HBM_15>(
        s_idx_buffer_HBM15, table_HBM15, s_embedding_buffer_HBM15);
    load_single_embedding_1_tables<ADDR_AXI_HBM_16, AXI_PADDED_SIZE_HBM_16>(
        s_idx_buffer_HBM16, table_HBM16, s_embedding_buffer_HBM16);
    load_single_embedding_1_tables<ADDR_AXI_HBM_17, AXI_PADDED_SIZE_HBM_17>(
        s_idx_buffer_HBM17, table_HBM17, s_embedding_buffer_HBM17);
    load_single_embedding_1_tables<ADDR_AXI_HBM_18, AXI_PADDED_SIZE_HBM_18>(
        s_idx_buffer_HBM18, table_HBM18, s_embedding_buffer_HBM18);
    load_single_embedding_1_tables<ADDR_AXI_HBM_19, AXI_PADDED_SIZE_HBM_19>(
        s_idx_buffer_HBM19, table_HBM19, s_embedding_buffer_HBM19);
    load_single_embedding_1_tables<ADDR_AXI_HBM_20, AXI_PADDED_SIZE_HBM_20>(
        s_idx_buffer_HBM20, table_HBM20, s_embedding_buffer_HBM20);
    load_single_embedding_1_tables<ADDR_AXI_HBM_21, AXI_PADDED_SIZE_HBM_21>(
        s_idx_buffer_HBM21, table_HBM21, s_embedding_buffer_HBM21);
    load_single_embedding_1_tables<ADDR_AXI_HBM_22, AXI_PADDED_SIZE_HBM_22>(
        s_idx_buffer_HBM22, table_HBM22, s_embedding_buffer_HBM22);
    load_single_embedding_1_tables<ADDR_AXI_HBM_23, AXI_PADDED_SIZE_HBM_23>(
        s_idx_buffer_HBM23, table_HBM23, s_embedding_buffer_HBM23);
    load_single_embedding_1_tables<ADDR_AXI_HBM_24, AXI_PADDED_SIZE_HBM_24>(
        s_idx_buffer_HBM24, table_HBM24, s_embedding_buffer_HBM24);
    load_single_embedding_1_tables<ADDR_AXI_HBM_25, AXI_PADDED_SIZE_HBM_25>(
        s_idx_buffer_HBM25, table_HBM25, s_embedding_buffer_HBM25);
    load_single_embedding_1_tables<ADDR_AXI_HBM_26, AXI_PADDED_SIZE_HBM_26>(
        s_idx_buffer_HBM26, table_HBM26, s_embedding_buffer_HBM26);
    load_single_embedding_1_tables<ADDR_AXI_HBM_27, AXI_PADDED_SIZE_HBM_27>(
        s_idx_buffer_HBM27, table_HBM27, s_embedding_buffer_HBM27);
    load_single_embedding_1_tables<ADDR_AXI_HBM_28, AXI_PADDED_SIZE_HBM_28>(
        s_idx_buffer_HBM28, table_HBM28, s_embedding_buffer_HBM28);
    load_single_embedding_1_tables<ADDR_AXI_HBM_29, AXI_PADDED_SIZE_HBM_29>(
        s_idx_buffer_HBM29, table_HBM29, s_embedding_buffer_HBM29);
    load_single_embedding_1_tables<ADDR_AXI_HBM_30, AXI_PADDED_SIZE_HBM_30>(
        s_idx_buffer_HBM30, table_HBM30, s_embedding_buffer_HBM30);
    load_single_embedding_1_tables<ADDR_AXI_HBM_31, AXI_PADDED_SIZE_HBM_31>(
        s_idx_buffer_HBM31, table_HBM31, s_embedding_buffer_HBM31);

    // Perform reduction (addition) across vectors from each bank
    reduction_add_single<VECTOR_SIZE_HBM_BANK_0>(s_embedding_buffer_HBM0, s_result_buffer_HBM0);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_1>(s_embedding_buffer_HBM1, s_result_buffer_HBM1);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_2>(s_embedding_buffer_HBM2, s_result_buffer_HBM2);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_3>(s_embedding_buffer_HBM3, s_result_buffer_HBM3);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_4>(s_embedding_buffer_HBM4, s_result_buffer_HBM4);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_5>(s_embedding_buffer_HBM5, s_result_buffer_HBM5);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_6>(s_embedding_buffer_HBM6, s_result_buffer_HBM6);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_7>(s_embedding_buffer_HBM7, s_result_buffer_HBM7);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_8>(s_embedding_buffer_HBM8, s_result_buffer_HBM8);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_9>(s_embedding_buffer_HBM9, s_result_buffer_HBM9);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_10>(s_embedding_buffer_HBM10, s_result_buffer_HBM10);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_11>(s_embedding_buffer_HBM11, s_result_buffer_HBM11);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_12>(s_embedding_buffer_HBM12, s_result_buffer_HBM12);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_13>(s_embedding_buffer_HBM13, s_result_buffer_HBM13);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_14>(s_embedding_buffer_HBM14, s_result_buffer_HBM14);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_15>(s_embedding_buffer_HBM15, s_result_buffer_HBM15);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_16>(s_embedding_buffer_HBM16, s_result_buffer_HBM16);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_17>(s_embedding_buffer_HBM17, s_result_buffer_HBM17);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_18>(s_embedding_buffer_HBM18, s_result_buffer_HBM18);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_19>(s_embedding_buffer_HBM19, s_result_buffer_HBM19);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_20>(s_embedding_buffer_HBM20, s_result_buffer_HBM20);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_21>(s_embedding_buffer_HBM21, s_result_buffer_HBM21);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_22>(s_embedding_buffer_HBM22, s_result_buffer_HBM22);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_23>(s_embedding_buffer_HBM23, s_result_buffer_HBM23);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_24>(s_embedding_buffer_HBM24, s_result_buffer_HBM24);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_25>(s_embedding_buffer_HBM25, s_result_buffer_HBM25);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_26>(s_embedding_buffer_HBM26, s_result_buffer_HBM26);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_27>(s_embedding_buffer_HBM27, s_result_buffer_HBM27);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_28>(s_embedding_buffer_HBM28, s_result_buffer_HBM28);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_29>(s_embedding_buffer_HBM29, s_result_buffer_HBM29);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_30>(s_embedding_buffer_HBM30, s_result_buffer_HBM30);
    reduction_add_single<VECTOR_SIZE_HBM_BANK_31>(s_embedding_buffer_HBM31, s_result_buffer_HBM31);

    // Final reduction to accumulate results from all banks
    reduction_add_all(
        s_result_buffer_HBM0, s_result_buffer_HBM1, s_result_buffer_HBM2, s_result_buffer_HBM3,
        s_result_buffer_HBM4, s_result_buffer_HBM5, s_result_buffer_HBM6, s_result_buffer_HBM7,
        s_result_buffer_HBM8, s_result_buffer_HBM9, s_result_buffer_HBM10, s_result_buffer_HBM11,
        s_result_buffer_HBM12, s_result_buffer_HBM13, s_result_buffer_HBM14, s_result_buffer_HBM15,
        s_result_buffer_HBM16, s_result_buffer_HBM17, s_result_buffer_HBM18, s_result_buffer_HBM19,
        s_result_buffer_HBM20, s_result_buffer_HBM21, s_result_buffer_HBM22, s_result_buffer_HBM23,
        s_result_buffer_HBM24, s_result_buffer_HBM25, s_result_buffer_HBM26, s_result_buffer_HBM27,
        s_result_buffer_HBM28, s_result_buffer_HBM29, s_result_buffer_HBM30, s_result_buffer_HBM31,
        s_vout_buffer);

    // Write the final result to the output memory
    write_results(s_vout_buffer, out);
}

void load_access_idx(
    // Stream references for each HBM index buffer
    // const int access_idx_local[BATCH_SIZE * BATCH_NUM],
    hls::stream<int> &s_idx_buffer_HBM0, hls::stream<int> &s_idx_buffer_HBM1,
    hls::stream<int> &s_idx_buffer_HBM2, hls::stream<int> &s_idx_buffer_HBM3,
    hls::stream<int> &s_idx_buffer_HBM4, hls::stream<int> &s_idx_buffer_HBM5,
    hls::stream<int> &s_idx_buffer_HBM6, hls::stream<int> &s_idx_buffer_HBM7,
    hls::stream<int> &s_idx_buffer_HBM8, hls::stream<int> &s_idx_buffer_HBM9,
    hls::stream<int> &s_idx_buffer_HBM10, hls::stream<int> &s_idx_buffer_HBM11,
    hls::stream<int> &s_idx_buffer_HBM12, hls::stream<int> &s_idx_buffer_HBM13,
    hls::stream<int> &s_idx_buffer_HBM14, hls::stream<int> &s_idx_buffer_HBM15,
    hls::stream<int> &s_idx_buffer_HBM16, hls::stream<int> &s_idx_buffer_HBM17,
    hls::stream<int> &s_idx_buffer_HBM18, hls::stream<int> &s_idx_buffer_HBM19,
    hls::stream<int> &s_idx_buffer_HBM20, hls::stream<int> &s_idx_buffer_HBM21,
    hls::stream<int> &s_idx_buffer_HBM22, hls::stream<int> &s_idx_buffer_HBM23,
    hls::stream<int> &s_idx_buffer_HBM24, hls::stream<int> &s_idx_buffer_HBM25,
    hls::stream<int> &s_idx_buffer_HBM26, hls::stream<int> &s_idx_buffer_HBM27,
    hls::stream<int> &s_idx_buffer_HBM28, hls::stream<int> &s_idx_buffer_HBM29,
    hls::stream<int> &s_idx_buffer_HBM30, hls::stream<int> &s_idx_buffer_HBM31)
{

    // Local storage for indices. These variables might be used to store intermediate values
    int idx_HBM0, idx_HBM1, idx_HBM2, idx_HBM3,
        idx_HBM4, idx_HBM5, idx_HBM6, idx_HBM7,
        idx_HBM8, idx_HBM9, idx_HBM10, idx_HBM11,
        idx_HBM12, idx_HBM13, idx_HBM14, idx_HBM15,
        idx_HBM16, idx_HBM17, idx_HBM18, idx_HBM19,
        idx_HBM20, idx_HBM21, idx_HBM22, idx_HBM23,
        idx_HBM24, idx_HBM25, idx_HBM26, idx_HBM27,
        idx_HBM28, idx_HBM29, idx_HBM30, idx_HBM31;
    int idx_PLRAM0, idx_PLRAM1, idx_PLRAM2, idx_PLRAM3;
    int idx_DDR0, idx_DDR1;

    // Example index values for one round of data fetching, hardcoded for testing purpose.
    // Typically, these values would be dynamically calculated or read from an external source.
    int idx_random_1_round[] =
        {864, 54, 873, 698, 100, 886, 101, 689, 41, 511, 898, 873, 945,
         322, 277, 628, 159, 511, 438, 699, 414, 954, 263, 329, 780, 488,
         658, 461, 528, 529, 500, 416};
        // int idx_random_1_round[] =
        // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
        // 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

    // Loop through batches of data; BATCH_NUM defines the number of such batches
    for (int i = 0; i < BATCH_NUM; i++)
    {
        // #pragma HLS LOOP_TRIPCOUNT min=trip_count_item_num max=trip_count_item_num
        for (int j = 0; j < BATCH_SIZE; j++)
        {
            // Set the pipeline initiation interval to 1 to ensure the loop 
            // is executed in a single clock cycle
            #pragma HLS pipeline II = 1

            // Load a single index from the predefined list and write it to all HBM streams.
            // This step effectively simulates simultaneous access to a set of data located
            // at the same index in different HBM banks.
            int idx_1_round = idx_random_1_round[j];

            s_idx_buffer_HBM0.write(idx_1_round);
            s_idx_buffer_HBM1.write(idx_1_round);
            s_idx_buffer_HBM2.write(idx_1_round);
            s_idx_buffer_HBM3.write(idx_1_round);
            s_idx_buffer_HBM4.write(idx_1_round);
            s_idx_buffer_HBM5.write(idx_1_round);
            s_idx_buffer_HBM6.write(idx_1_round);
            s_idx_buffer_HBM7.write(idx_1_round);
            s_idx_buffer_HBM8.write(idx_1_round);
            s_idx_buffer_HBM9.write(idx_1_round);
            s_idx_buffer_HBM10.write(idx_1_round);
            s_idx_buffer_HBM11.write(idx_1_round);
            s_idx_buffer_HBM12.write(idx_1_round);
            s_idx_buffer_HBM13.write(idx_1_round);
            s_idx_buffer_HBM14.write(idx_1_round);
            s_idx_buffer_HBM15.write(idx_1_round);
            s_idx_buffer_HBM16.write(idx_1_round);
            s_idx_buffer_HBM17.write(idx_1_round);
            s_idx_buffer_HBM18.write(idx_1_round);
            s_idx_buffer_HBM19.write(idx_1_round);
            s_idx_buffer_HBM20.write(idx_1_round);
            s_idx_buffer_HBM21.write(idx_1_round);
            s_idx_buffer_HBM22.write(idx_1_round);
            s_idx_buffer_HBM23.write(idx_1_round);
            s_idx_buffer_HBM24.write(idx_1_round);
            s_idx_buffer_HBM25.write(idx_1_round);
            s_idx_buffer_HBM26.write(idx_1_round);
            s_idx_buffer_HBM27.write(idx_1_round);
            s_idx_buffer_HBM28.write(idx_1_round);
            s_idx_buffer_HBM29.write(idx_1_round);
            s_idx_buffer_HBM30.write(idx_1_round);
            s_idx_buffer_HBM31.write(idx_1_round);
        }
    }
}

template <const long START_ADDR_0, const long AXI_PADDED_SIZE_0>
void load_single_embedding_1_tables(
    hls::stream<int> &s_idx_buffer, const t_hbm *table_RAM,
    hls::stream<t_hbm> &s_embedding_buffer)
{
    // Disables inlining of this function to ensure it is treated as a distinct module, 
    // improving readability in synthesis reports
    #pragma HLS INLINE off
    // Iterate over each batch and batch size to process multiple data blocks 
    // This code operates element by element, but this is a batch emulation (streaming)
    // 8 < data size <= 16, load 2 times
    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; i++)
    {
        // Specifies the expected number of iterations to aid the HLS tool in optimization
        #pragma HLS LOOP_TRIPCOUNT min = trip_count_item_num max = trip_count_item_num
        // Read index from the index buffer stream
        long idx = s_idx_buffer.read(); // Divide by 2 to account for the 16-bit data width

        // Calculate the base address for this index
        long base_addr_0 = START_ADDR_0 + idx * AXI_PADDED_SIZE_0; 
        // Load data block from memory into the stream, one element at a time
        for (int j = 0; j < AXI_PADDED_SIZE_0; j++)
        {
            // Enables pipelining, allowing one data element to be processed each clock cycle
            #pragma HLS pipeline II = 1
            // Write data to output stream
           s_embedding_buffer.write(table_RAM[base_addr_0 + j]);        
        }
    }
}

template <const int TOTAL_VECTOR_LENGTH>
void reduction_add_single(
    hls::stream<t_hbm> &s_embedding_buffer,
    hls::stream<D_TYPE> &s_result_buffer)
{
    // Disables inlining
    #pragma HLS INLINE off
    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; i++)
    {
        // Specifies expected trip count range for the loop to aid in performance estimation and optimization.
        #pragma HLS LOOP_TRIPCOUNT min = trip_count_item_num max = trip_count_item_num
        // Read the first element of the vector to initialize the result
        D_TYPE result = s_embedding_buffer.read(); 
        // Consume the rest of the vector elements without processing them
        for (int j = 0; j < TOTAL_VECTOR_LENGTH - 1; j++)
        {
            s_embedding_buffer.read();
        }
        // Write the result (the first element of the vector) to the result buffer
        s_result_buffer.write(result);
    }
}

void reduction_add_all(
    hls::stream<D_TYPE> &s_result_buffer_HBM0, hls::stream<D_TYPE> &s_result_buffer_HBM1,
    hls::stream<D_TYPE> &s_result_buffer_HBM2, hls::stream<D_TYPE> &s_result_buffer_HBM3,
    hls::stream<D_TYPE> &s_result_buffer_HBM4, hls::stream<D_TYPE> &s_result_buffer_HBM5,
    hls::stream<D_TYPE> &s_result_buffer_HBM6, hls::stream<D_TYPE> &s_result_buffer_HBM7,
    hls::stream<D_TYPE> &s_result_buffer_HBM8, hls::stream<D_TYPE> &s_result_buffer_HBM9,
    hls::stream<D_TYPE> &s_result_buffer_HBM10, hls::stream<D_TYPE> &s_result_buffer_HBM11,
    hls::stream<D_TYPE> &s_result_buffer_HBM12, hls::stream<D_TYPE> &s_result_buffer_HBM13,
    hls::stream<D_TYPE> &s_result_buffer_HBM14, hls::stream<D_TYPE> &s_result_buffer_HBM15,
    hls::stream<D_TYPE> &s_result_buffer_HBM16, hls::stream<D_TYPE> &s_result_buffer_HBM17,
    hls::stream<D_TYPE> &s_result_buffer_HBM18, hls::stream<D_TYPE> &s_result_buffer_HBM19,
    hls::stream<D_TYPE> &s_result_buffer_HBM20, hls::stream<D_TYPE> &s_result_buffer_HBM21,
    hls::stream<D_TYPE> &s_result_buffer_HBM22, hls::stream<D_TYPE> &s_result_buffer_HBM23,
    hls::stream<D_TYPE> &s_result_buffer_HBM24, hls::stream<D_TYPE> &s_result_buffer_HBM25,
    hls::stream<D_TYPE> &s_result_buffer_HBM26, hls::stream<D_TYPE> &s_result_buffer_HBM27,
    hls::stream<D_TYPE> &s_result_buffer_HBM28, hls::stream<D_TYPE> &s_result_buffer_HBM29,
    hls::stream<D_TYPE> &s_result_buffer_HBM30, hls::stream<D_TYPE> &s_result_buffer_HBM31,
    hls::stream<D_TYPE> &s_vout_buffer)
{
    // Process each batch of results
    for (int i = 0; i < BATCH_NUM * BATCH_SIZE; i++)
    {
        // Inform HLS about the expected range of iterations for this loop to optimize the design.
        #pragma HLS LOOP_TRIPCOUNT min = trip_count_item_num max = trip_count_item_num
        // #pragma HLS pipeline II=1
        // Temporary variables to hold intermediate sums to reduce timing pressure on addition operations
        int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9;

        // Read and sum groups of four results to reduce the number of operations per step
        tmp0 = s_result_buffer_HBM0.read() + s_result_buffer_HBM1.read() + s_result_buffer_HBM2.read() + s_result_buffer_HBM3.read();
        tmp1 = s_result_buffer_HBM4.read() + s_result_buffer_HBM5.read() + s_result_buffer_HBM6.read() + s_result_buffer_HBM7.read();
        tmp2 = s_result_buffer_HBM8.read() + s_result_buffer_HBM9.read() + s_result_buffer_HBM10.read() + s_result_buffer_HBM11.read();
        tmp3 = s_result_buffer_HBM12.read() + s_result_buffer_HBM13.read() + s_result_buffer_HBM14.read() + s_result_buffer_HBM15.read();
        tmp4 = s_result_buffer_HBM16.read() + s_result_buffer_HBM17.read() + s_result_buffer_HBM18.read() + s_result_buffer_HBM19.read();
        tmp5 = s_result_buffer_HBM20.read() + s_result_buffer_HBM21.read() + s_result_buffer_HBM22.read() + s_result_buffer_HBM23.read();
        tmp6 = s_result_buffer_HBM24.read() + s_result_buffer_HBM25.read() + s_result_buffer_HBM26.read() + s_result_buffer_HBM27.read();
        tmp7 = s_result_buffer_HBM28.read() + s_result_buffer_HBM29.read() + s_result_buffer_HBM30.read() + s_result_buffer_HBM31.read();

        // tmp8 = s_result_buffer_DDR0.read() + s_result_buffer_DDR1.read();

        // tmp9 = /*s_result_buffer_PLRAM0.read()+ s_result_buffer_PLRAM1.read()+ */s_result_buffer_PLRAM2.read()+ s_result_buffer_PLRAM3.read();

        // Calculate the final result by summing all intermediate sums
        int result = tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 + tmp6 + tmp7; // + tmp8 + tmp9;

        // s_result_buffer_HBM0.read();
        // s_result_buffer_HBM1.read();
        // s_result_buffer_HBM2.read();
        // s_result_buffer_HBM3.read();
        // s_result_buffer_HBM4.read();
        // s_result_buffer_HBM5.read();
        // s_result_buffer_HBM6.read();
        // s_result_buffer_HBM7.read();
        // s_result_buffer_HBM8.read();
        // s_result_buffer_HBM9.read();
        // s_result_buffer_HBM10.read();
        // s_result_buffer_HBM11.read();
        // s_result_buffer_HBM12.read();
        // s_result_buffer_HBM13.read();
        // s_result_buffer_HBM14.read();
        // s_result_buffer_HBM15.read();
        // s_result_buffer_HBM16.read();
        // s_result_buffer_HBM17.read();
        // s_result_buffer_HBM18.read();
        // s_result_buffer_HBM19.read();
        // s_result_buffer_HBM20.read();
        // s_result_buffer_HBM21.read();
        // s_result_buffer_HBM22.read();
        // s_result_buffer_HBM23.read();
        // s_result_buffer_HBM24.read();
        // s_result_buffer_HBM25.read();
        // s_result_buffer_HBM26.read();
        // s_result_buffer_HBM27.read();
        // s_result_buffer_HBM28.read();
        // s_result_buffer_HBM29.read();
        // s_result_buffer_HBM30.read();

        // int result = s_result_buffer_HBM31.read() + s_result_buffer_PLRAM3.read() + s_result_buffer_DDR1.read();
        
        // Write the aggregated result to the output stream
        s_vout_buffer.write(result);
    }
}

void write_results(hls::stream<D_TYPE> &s_vout_buffer, D_TYPE out_RAM[BATCH_SIZE])
{
    // Local array to temporarily hold data read from the stream
    D_TYPE out_local[BATCH_SIZE];

    // Loop through all batches of data
    for (int i = 0; i < BATCH_NUM; i++)
    {
        // Read each element from the stream and store it in the local array
        for (int j = 0; j < BATCH_SIZE; j++)
        {
            // Read data from the stream into the local buffer
            out_local[j] = s_vout_buffer.read();
        }
    }
    // After reading all data for a batch, write the data from the local array to the output array
    for (int j = 0; j < BATCH_SIZE; j++)
    {
        // Transfer data from local buffer to the output array
        out_RAM[j] = out_local[j];
    }
}
