#include <stdio.h>
#include "types.h"
#include "decode.h"
#include <string.h>
#include "common.h"

Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
        if(strcmp(strstr(argv[2],"."),".bmp")==0)
        {
            decInfo->Encoded_fname=argv[2];
        }
        else
        {
                return e_failure;
        }
        if(argv[3]!=NULL)
        {
                decInfo->Decoded_fname=argv[3];
        }
        else
        {
               decInfo->Decoded_fname="default.txt";       
        }
        return e_success;
}
Status open_files(DecodeInfo *decInfo)
{
	decInfo->fptr_encoded_file=fopen(decInfo->Encoded_fname,"r");
	if(decInfo->fptr_encoded_file==NULL)
	{
		return e_failure;
	}
	decInfo->fptr_decoded_file=fopen(decInfo->Decoded_fname,"w");
	if(decInfo->fptr_decoded_file==NULL)
	{
		return e_failure;
	}
	
	return e_success;
}
int Decode_char_to_int(char *str,int size,DecodeInfo *decInfo)
{
	char ptr[8];
	int i,decimal=0;
	for(i=0;i<8;i++)
	{
		ptr[i]=str[7-i]&1;
	}
	for(i=0;i<8;i++)
	{
		decimal = decimal * 2 + ptr[i];
	}
	
	 return decimal;
	
}
Status Decode_Magic_string(char *encodedstr,int size,DecodeInfo *decInfo)
{
	int i;
	fseek(decInfo->fptr_encoded_file,54,SEEK_SET);
	for(i=0;i<size;i++)
	{
	 int decimal=0;
	 char str[8];
	fread(str,8,1,decInfo->fptr_encoded_file);
        decimal=Decode_char_to_int(str,size,decInfo);
	if(decimal!=encodedstr[i])
	{
		return e_failure;
	}
	}
	return e_success;

}
int Decode_int_to_int(char arr[],DecodeInfo *decInfo)
{
        char ptr[32];
        int i,decimal=0;
        for(i=0;i<32;i++)
        {
                ptr[i]=arr[31-i]&1;
        }
        for(i=0;i<32;i++)
        {
                decimal = decimal * 2 + ptr[i];
        }

         return decimal;
}


Status Decode_secret_file_extn_size(int size,DecodeInfo *decInfo)
{
   char arr[32];
   fread(arr,32,1,decInfo->fptr_encoded_file);
   if(Decode_int_to_int(arr,decInfo)!=size)
   {
	   return e_failure;
   }
   return e_success;
}

Status Decode_secret_file_extn(char *str,int size,DecodeInfo *decInfo)
{
	char arr[8];
	for(int i=0;i<size;i++)
	{
           fread(arr,8,1,decInfo->fptr_encoded_file);
	  if(Decode_char_to_int(arr,size,decInfo)!=str[i])
	  {
		  return e_failure;
	  }
	}
	return e_success;
}
long Decode_long_to_int(char *arr,DecodeInfo *decInfo)
{
        char ptr[64];
        int i;
	long decimal=0;
        for(i=0;i<64;i++)
        {
                ptr[i]=arr[63-i]&1;
        }
        for(i=0;i<64;i++)
        {
                decimal = decimal * 2 + ptr[i];
        }
         return decimal;
}
Status Decode_secret_file_size(long size,DecodeInfo *decInfo)
{
   char arr[64];
   fseek(decInfo->fptr_encoded_file,134,SEEK_SET);
   fread(arr,64,1,decInfo->fptr_encoded_file);
   if(Decode_long_to_int(arr,decInfo)!=size)
   {
           return e_failure;
   }
   return e_success;
}
char Decode_char_to_char(char *str,DecodeInfo *decInfo)
{
	char ptr[8];
	int decimal=0;
        for(int i=0;i<8;i++)
        {
                ptr[i]=str[7-i]&1;
        }
	for(int i=0;i<8;i++)
	{
                decimal=decimal*2+ptr[i];
	}
	return decimal;
}
Status Decode_secret_file(long size,DecodeInfo *decInfo)
{
	char decimal[size];
	for(int i=0;i<size;i++)
	{
		char str[8];
		fread(str,8,1,decInfo->fptr_encoded_file);
		decimal[i]=Decode_char_to_char(str,decInfo);
	}
	        fwrite(decimal,size,1,decInfo->fptr_decoded_file);
	return e_success;
	        
}

Status do_Decoding(DecodeInfo *decInfo)
{
	if(open_files(decInfo)==e_success)
	{
	        printf("Open files successfully\n");
               if( Decode_Magic_string(MAGIC_STRING,strlen(MAGIC_STRING),decInfo)==e_success)
	       {
		       printf("Magic string matched successfully\n");
		      if(Decode_secret_file_extn_size(4,decInfo)==e_success)
		      {
			      printf("Secret file extension size matched successfully\n");
			     if (Decode_secret_file_extn(".txt",strlen(".txt"),decInfo)==e_success)
			     {
				     printf("Secret file extension matched successfully\n");
				    if (Decode_secret_file_size(25,decInfo)==e_success)
				    {
					    printf("secret file size matched successfully\n");
					   if(Decode_secret_file(25,decInfo)==e_success)
					   {
						   printf("Decode secret file successfully\n");
		                                   return e_success;
					   }
					   else
					   {
						   printf("Failed to decode secret file\n");
					   }
				    }
				    else
				    {
					    printf("Failed to match secret file size\n");
				    }
			     }
			     else
			     {
                                    printf("Failed to match secretfile extension\n");
			     }
		      }
		      else
		      {
			     printf("Failed to match secret file size extension\n");
		      }
	       }
	       else
	       {
		       printf("Failed to match magic string\n");
	       }
	}
	else
	{
		printf("Failed to open files\n");
		return e_failure;
	}
}
