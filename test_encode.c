#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>

int main(int argc,char *argv[] )
{
    if(argc>=4 && argc<=5||argc>=3&&argc==4)
    {	    int ret;
	     ret=check_operation_type(argv);
	     EncodeInfo E1;
     
      if(ret == e_encode)
      {
	      printf("Info : Encoding is selected\n");
	     if( read_and_validate_encode_args(argv,&E1)==e_success)
	     {
		     printf("Info : Read and validate args is success\n");
		    if(do_encoding(&E1)==0)
		    {
			printf("Encoding is success\n");}
		    else
		    {
			    printf("Failed to encode\n");
		    }
	     }
	     else
	     {
		     printf("Info : Read and validate args is failed\n");
	     }

      }
      else if(ret == e_decode)
      {
	      printf("Info : Decoding is selected\n");
	      if( read_and_validate_encode_args(argv,&E1)==e_success)
             {
                     printf("Info : Read and validate args is success\n");
	     }
	      else
	      {
		      printf("Info : Read and validate args is failed\n");
	      }
      }
      else
      {
	      printf("Error : unsupported type\n");
	      printf("Usage : For Enoding : ./a.out  -e beautiful.bmp secret.txt [stegano.bmp]\n");
	      printf("Usage : For Decoding : ./a.out -d stegano.bmp [decode.txt]\n");
      }
    }
    else
    {
	    printf("Pass the valid arguments in cla\n");
    }

    return 0;
}

OperationType check_operation_type(char *argv[])
{
        if(strcmp(argv[1],"-e")==0)
        {
                return e_encode;
        }
	else if(strcmp(argv[1],"-d")==0)
        {
                return e_decode;
        }
        else
        {
                return e_unsupported;
        }
}

