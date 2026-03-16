#include <stdio.h>
#include "types.h"
#include "decode.h"
#include <string.h>

int main(int argc,char *argv[])
{
	if(argc>=3 && argc<=4)
	{
		int ret;
		ret=check_operation_type(argv);
		DecodeInfo D1;
		if(ret==e_decode)
		{
			printf("Decode is selected\n");
			if(read_and_validate_decode_args(argv,&D1)==e_success)
			{
				printf("read and validate arguments is successful\n");
			       if (do_Decoding(&D1)==e_success)
			       {
				       printf("Decoding is success\n");
			       }
			       else
			       {
				       printf("Failed to decode\n");
			       }
			}
			else
			{
				printf("Info : Pass ./a.out -d stego.bmp [Decode.txt]\n");
			}
		}
		else
		{
			printf("Unsupported format is selected\n");
		}

	}
	else
	{
		printf("Pass the valid arguments\n");
	}
}

	OperationType check_operation_type(char *argv[])
{
        if(strcmp(argv[1],"-d")==0)
        {
                return e_decode;
        }
        else
        {
                return e_unsupported;
        }
}

Status read_and_validate_encode_args(char *argv[], DecodeInfo *decInfo)
{
	if(strcmp(argv[1],"-d")==0)
	{
		return e_success;
	}
	else
	{
		return e_failure;
	}
}
