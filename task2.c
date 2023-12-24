#include <stdio.h>
#include <openssl/bn.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printBN(char *msg, BIGNUM * a)
{
   char * number_str = BN_bn2hex(a);
   printf("%s %s\n", msg, number_str);
   OPENSSL_free(number_str);
}

char* hexToAscii(char *hex_string) {
    FILE *fp;
    int len = strlen(hex_string);

    char *command = malloc(len+53);
    strcat(command, "python3 -c 'print(bytes.fromhex(\"");
    strcat(command, hex_string);
    strcat(command, "\").decode(\"utf-8\"))'");

    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        exit(1);
    }

    char buf[1024];
    char *res = (char*)calloc(len, sizeof(char));
    fflush(stdout);
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        strncat(res, buf, len - strlen(res) - 1);
    }
    pclose(fp);
    return res;
}

void getMessageHex(char *msg, char *res, int len) {
    FILE *fp;

    char *command = malloc(strlen(msg)+45);
    strcat(command, "python3 -c 'print(\"");
    strcat(command, msg);
    strcat(command, "\".encode(\"utf-8\").hex())'");

    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        exit(1);
    }

    char buf[1024];
    fflush(stdout);
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        strncat(res, buf, len - strlen(res));
    }
    pclose(fp);
    return;
}

int main () {

    float chunk_size = 64;  //32 Bytes or 64 chars

    //Convert given Message to Hex Coded format
    char *msg = "A top secret!";
    int len = 2*strlen(msg); 
    float num = ceil(len/chunk_size);
    char *msgHex = (char *)malloc(len*sizeof(char));
    getMessageHex(msg, msgHex, len);
    printf("Message: %s\n", msg);
    printf("Hex Coded Message: %s\n\n", msgHex);

    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();
    BN_CTX *ctx = BN_CTX_new();

    //Initialize Public and Private keys
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    //Declare Arrays to store original msg, cipher, plain text as sequence of integers
    BIGNUM **msgArray = (BIGNUM **)malloc(num*sizeof(BIGNUM *));
    BIGNUM **cipherArray = (BIGNUM **)malloc(num*sizeof(BIGNUM *));
    BIGNUM **plainArray = (BIGNUM **)malloc(num*sizeof(BIGNUM *));

    for (int i = 0; i < num; i++) {
        msgArray[i] = BN_new();
        cipherArray[i] = BN_new();
        plainArray[i] = BN_new();
    }

    char *mPart = (char*)calloc(chunk_size, sizeof(char));
    //Break Hex Coded Message into sequence of integers in the chunks of 32 bytes
    for(int i=0,j=0;i<len;i=i+chunk_size,j++){
        for(int k=0;k<chunk_size && k<len;k++) {
            mPart[k] = msgHex[i+k];
        }
        BN_hex2bn(&msgArray[j], mPart);
    }

    //Encryption
    for (int i = 0; i < num; i++) {
        BN_mod_exp(cipherArray[i], msgArray[i], e, n, ctx);
    }

    printf("Cipher Text: ");
    for(int i = 0; i < num; i++) {
        char *number_str = BN_bn2hex(cipherArray[i]);
        printf("%s", number_str);
    }
    printf("\n\n");

    //Decryption
    for (int i = 0; i < num; i++) {
        BN_mod_exp(plainArray[i], cipherArray[i], d, n, ctx);
    }

    char *plainMsg = (char *)calloc(len, sizeof(char));

    printf("Plain Text after decryption (Hex): ");
    for(int i = 0; i < num; i++) {
        char *number_str = BN_bn2hex(plainArray[i]);
        strcat(plainMsg, number_str);
    }
    printf("%s\n", plainMsg);


    printf("Plain Text after decryption (ASCII): ");
    printf("%s\n", hexToAscii(plainMsg));


    //Free Memory
    BN_free(d);
    BN_free(e);
    BN_free(n);
    BN_CTX_free(ctx);
    free(msgArray);
    free(cipherArray);
    free(plainArray);
    free(plainMsg);
   
    return 0;
}

