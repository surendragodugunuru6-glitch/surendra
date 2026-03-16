#ifndef DECODE_H
#define DECODE_H

#include "types.h"

typedef struct _DecodeInfo
{
	char *Encoded_fname;
	FILE *fptr_encoded_file;

	char *Decoded_fname;
	FILE *fptr_decoded_file;
}DecodeInfo;

OperationType check_operation_type(char *argv[]);

/* Read and validate Encode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the encoding */
Status do_Decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
Status open_files(DecodeInfo *decInfo);

Status Decode_Magic_string(char *Magic_string,int size,DecodeInfo *decInfo);

int  Decode_char_to_int(char *str,int size,DecodeInfo *decInfo);

Status Decode_secret_file_extn_size(int size,DecodeInfo *decInfo);

int Decode_int_to_int(char *arr,DecodeInfo *decInfo);

Status Decode_secret_file_extn(char *str,int size,DecodeInfo *decInfo);

long Decode_long_to_int(char *arr,DecodeInfo *decInfo);

Status Decode_secret_file_size(long size,DecodeInfo *decInfo);

char  Decode_char_to_char(char *str,DecodeInfo *decInfo);

Status Decode_secret_file(long size,DecodeInfo *decInfo);

#endif

