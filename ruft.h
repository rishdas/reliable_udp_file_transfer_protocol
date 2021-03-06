
#define MAX_PAYLOAD 1280
#define MAXLINE 50
#define TRUE 1
#define FALSE 0

typedef struct ruft_pkt_info_  
{
    short flags;
    short awnd;
    int   ack_no;
    int   seq_no;
    int   payload_length;
    char  payload[MAX_PAYLOAD];
} ruft_pkt_info_t;

typedef struct ruft_pkt_ctx_
{
    int   is_ack;
    int   is_data_pkt;
    int   is_last_pkt;
    int   ack_no;
    int   seq_no;
    short awnd;
    int   payload_length;
    char  payload[MAX_PAYLOAD];
} ruft_pkt_ctx_t;

typedef struct ruft_server_traff_info_
{
    int            seg_no;
    int            no_ack_recvd;
    int            is_acked;
    int            first_byte;
    int            last_byte;
    struct timeval sent_time;
    struct timeval ack_recv_time;
    unsigned long  rtt;
    char           payload[MAX_PAYLOAD];
} ruft_server_traff_info_t;

typedef struct ruft_client_traff_info_
{
    int            seg_no;
    int            no_ack_sent;
    int            no_data_recvd;
    int            is_acked;
    int            first_byte;
    int            last_byte;
    struct timeval ack_sent_time;
    struct timeval data_recv_time;
    unsigned long  rtt;
    ruft_pkt_ctx_t req_ctx;
} ruft_client_traff_info_t;

typedef enum ruft_client_states_ {
    CL_SEND_REQUEST,
    CL_GET_REPLY,
    CL_RECV_ERROR,
    CL_SLOW_START,
    CL_CONG_AVOID,
    CL_FAST_RECOV,
    CL_FILE_RCVD
}ruft_client_states_t;

typedef enum ruft_server_states_ {
    SV_WAIT,
    SV_PROC_REQ,
    SV_REPLY_ERR,
    SV_SLOW_START,
    SV_CONG_AVOID,
    SV_FAST_RECOV,
    SV_FILE_SENT
}ruft_server_states_t;

typedef enum ruft_client_network_mode_ {
    CL_NO_LOSS,
    CL_VARIABLE_LOSS,
    CL_HIGH_LATENCY
}ruft_client_network_mode_t;
