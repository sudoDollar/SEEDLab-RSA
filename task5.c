#include <stdio.h>
#include <openssl/bn.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void convertToUpperCase(char *str) {
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
}

char* hexToAscii(char *hex_string) {
    FILE *fp;
    int len = strlen(hex_string);

    char *command = malloc(len+53);
    strcat(command, "python3 -c 'print(bytes.fromhex(\"");
    strcat(command, hex_string);
    strcat(command, "\").decode(\"utf-8\"))'");

    char *res = (char*)calloc(len, sizeof(char));

    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen");
        return res;
    }

    char buf[1024];
    fflush(stdout);
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        strcat(res, buf);
    }
    int l = strlen(res);
    if (l != 0)
        res[l-1] = '\0';
    pclose(fp);
    return res;
}

char* getMessageHex(char *msg) {
    FILE *fp;

    int l = 2*strlen(msg);
    char *command = malloc(strlen(msg)+45);
    char *msgHex = (char *)calloc(l, sizeof(char));
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
        strcat(msgHex, buf);
    }

    int len = strlen(msgHex);
    if (len != 0)
        msgHex[len-1] = '\0';

    convertToUpperCase(msgHex);

    pclose(fp);
    return msgHex;
}

int main () {
    float chunk_size = 64;

    char *message = "Launch a missile.";
    char *signature = "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F";

    char *msgHex = getMessageHex(message);

    int len = strlen(signature);
    float num = ceil(len/chunk_size);
    printf("Message: %s\n", message);
    printf("Message (Hex): %s\n", msgHex);
    printf("Signature: %s\n\n", signature);

    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BN_CTX *ctx = BN_CTX_new();

    //Initialize Public and Private keys
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");

    //Declare Arrays to store signature, plain text as sequence of integers
    BIGNUM **cipherArray = (BIGNUM **)malloc(num*sizeof(BIGNUM *));
    BIGNUM **plainArray = (BIGNUM **)malloc(num*sizeof(BIGNUM *));

    char *mPart = (char*)calloc(chunk_size, sizeof(char));
    for (int i = 0; i < num; i++) {
        cipherArray[i] = BN_new();
        plainArray[i] = BN_new();
    }

    //Break Signature into sequence of integers in the chunks of 64 bytes
    for(int i=0,j=0;i<len;i=i+chunk_size,j++){
        for(int k=0;k<chunk_size;k++) {
            mPart[k] = signature[i+k];
        }
        BN_hex2bn(&cipherArray[j], mPart);
    }

    //Decryption
    for (int i = 0; i < num; i++) {
        BN_mod_exp(plainArray[i], cipherArray[i], e, n, ctx);
    }

    char *plainMsg = (char *)calloc(len, sizeof(char));

    for(int i = 0; i < num; i++) {
        char *number_str = BN_bn2hex(plainArray[i]);
        strcat(plainMsg, number_str);
    }

    //Compare original message(hex) with decrypted signature
    if (strcmp(msgHex, plainMsg) == 0) {
        printf("Signature Verified.\n\n");
        printf("Plain Text after decryption (Hex): ");
        printf("%s\n", plainMsg);
        printf("Plain Text after decryption (ASCII): ");
        char *ascii_message = hexToAscii(plainMsg);
        printf("%s\n", ascii_message);
    } else {
        printf("\nInvalid Signature!\n");
        printf("Decrypred Signature: %s is different from original message.\n", plainMsg);
    }


    //Free Memory
    BN_free(e);
    BN_free(n);
    BN_CTX_free(ctx);
    free(cipherArray);
    free(plainArray);
    free(plainMsg);

   
    return 0;
}