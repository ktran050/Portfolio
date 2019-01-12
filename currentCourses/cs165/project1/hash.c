#include <openssl/md5.h>

// REQUIRES -lssl -lcrypto flags
//MD5_Init(MD5_CTX *c);
//MD5_Init(&context);
//MD5_Update(&context, string, length);
//MD5_Final(result, &context);

int main(){
  char *hashedPass;
  const char *rawPass = "potato";
  const unsigned long length = 6;
  MD5_CTX *ctx;
  
  MD5(rawPass, length, hashedPass); 

  return 0;
}
