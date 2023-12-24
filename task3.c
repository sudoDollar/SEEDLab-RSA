#include <stdio.h>
#include <openssl/bn.h>
#include <stdlib.h>
#include <string.h>


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

int main () {

    char *cipherText = "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F";
    int len = strlen(cipherText);
    printf("Cipher Text: %s\n", cipherText);

    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();
    BN_CTX *ctx = BN_CTX_new();

    //Initialize Public and Private keys
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    //Declare Arrays to store cipher, plain text as sequence of integers
    BIGNUM **cipherArray = (BIGNUM **)malloc((len/64)*sizeof(BIGNUM *));
    BIGNUM **plainArray = (BIGNUM **)malloc((len/64)*sizeof(BIGNUM *));

    char mPart[64];
    for (int i = 0; i < len/64; i++) {
        cipherArray[i] = BN_new();
        plainArray[i] = BN_new();
    }

    //Break Cipher into sequence of integers in the chunks of 32 bytes/64 chars
    for(int i=0,j=0;i<len;i=i+64,j++){
        for(int k=0;k<64;k++) {
            mPart[k] = cipherText[i+k];
        }
        BN_hex2bn(&cipherArray[j], mPart);
    }

    //Decryption
    for (int i = 0; i < len/64; i++) {
        BN_mod_exp(plainArray[i], cipherArray[i], d, n, ctx);
    }

    char *plainMsg = (char *)calloc(len, sizeof(char));

    printf("Plain Text after decryption (Hex): ");
    for(int i = 0; i < len/64; i++) {
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
    free(cipherArray);
    free(plainArray);
    free(plainMsg);

   
    return 0;
}