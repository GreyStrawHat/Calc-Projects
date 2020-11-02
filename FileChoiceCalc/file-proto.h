#ifndef _FILE_PROTO
#define _FILE_PROTO

#include <stdint.h>

enum payload_type {FILE_METADATA = 0x00, FILE_DATA = 0x01, FILE_SHUTDOWN = 0x02, FILE_FORWARD = 0x04,
	FILE_WAIT = 0x08, FILE_RESET = 0x10, FILE_ERROR = 0x20, FILE_INFO = 0x40, FILE_SUCCESS = 0x80};

enum file_info {SOCK_DOMAIN = 0x01, SOCK_NET = 0x02, MULTI_THREAD = 0x04, ENC_SUPPORT = 0x08};

//Payload to include with FILE_METADATA typed message
enum meta_info {META_READY = 0x00, META_RECV = 0x01, META_SOLVE = 0x02, META_LIST = 0x04};

//Configuration info to be read by client/server
typedef struct __attribute__((__packed__)) _file_info_payload{
	char * hostname;
	uint8_t supported_ops; //or'd value from file_info enum
	uint32_t up_time; //Time in seconds
}file_info_payload;

//Header included in all payloads as defined in the above enum
typedef struct __attribute__((__packed__)) _file_proto_hdr{
	uint8_t type; //single value from payload_type
	uint8_t xor_byte;
	uint16_t reserved;
	uint32_t payload_len;
	uint32_t xor_key;
}file_proto_hdr;

#endif /*_FILE_PROTO*/
