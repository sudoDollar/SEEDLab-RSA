#include <stdio.h>
#include <openssl/bn.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main () {
    float chunk_size = 1024; //512 bytes or 1024 chars since length of n (key) is 512 bytes

    char *sha384sum = "BB9439D7CAE06A96858157AF070501EEC19641C43F04E4661831E4A47D85A998C65AA209390AF84F72D3B7EBD7577843";
    char *signature = "6ec1057e35f90105e34331cb98d57c2c9d8851129a34dfe8608408cc2f0818ec7870443e3a8e74c5743fa5f4952fe2e5d4e6fcbf52b79925b4e26b4983efa316c2bafbd27b43ba6de73d12f23030edaf7fe7fd99e8a4214cae4f563e22133af71aae93739ef69a91b0d665c723e2ceb21da7cab2bbaadb00c5e5ffcbb48454b770fca452d9d674e66cbca229c57b04a95a194272c3cdc1c82063d840f4ca72aa82cb177cef2f7530f306332c898d4bb5c5b403396a036d28fbb5d4c42626c15cb1fb7fd32921ec7a5444e21c446799431f09e6d972c196cfc1180fdb8c820c4708fe16a29ac768e0340d2f05e78b78eb7c77be4bcaea4fd78eec9d00db6ae11e1d16eb24a9839e9744d4956c5569d8a048f93b7f7041be2e049d5eed2c4376489ec9d2d0c8d709a892ff0c312daa55e7ec156e9cd35be9c3d81fe77f29961d17f5e0a7d33455ea48be6f308279d33605bae916533f04f6edf6c8fab9d1f25ac74897059833cf0bb8f820cd11368d9b984188e045fd191ed76797eeca54b5344225adaa7d1c83ea4ce47e32c3c7e00787f54ca262f3a6c543592114dc430c5f58e104666bcba7356f44ea88cbbcb15f97f72865b809fe39527c9bd8e8fa08303d60511c8d1b9a6410ed48a27a0183961493bb0881ec8c0674ac1a9fc9f35d05de431b8f992640fce7459e05909d6d6d069ae7d79c1e0e6b5a083b2c03c8e1ba79";

    int len = strlen(signature);
    float num = ceil(len/chunk_size);
    printf("sha384sum: %s\n\n", sha384sum);
    printf("Signature: %s\n\n", signature);

    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BN_CTX *ctx = BN_CTX_new();

    //Initialize Public key
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "B5645ECA62EB3938EDC65AA268478C739CB0CD0A3A1CA20A9E08855D8B8784066177CC861EB975CDA0901417E9A7F3A341B77C8C334E79F496439224838BD329036072E32A909531F37DB3ABBECEC8E0B5AC3984C40A5545420CD7A9ADA9B3683CE791CF416D61657561FF27E66EDAC23556BFFC6EC53C3A9276B010F8CF30D37EB8932640A5DB3F44F72A18E46364DA24ACDCD8706B9BDBBBEA13A0463FA5DE40EE580C5A1B8BD06FBD338EF9903D1C6214EC56DD2E1466E983FE14EF0D469BED7AB7EA66B46DDDB4E7F064F92EC393CC842024CB78FD158B17810A35CF7B097392099167EE614DC784B34EFCB6DC1E3ACFD7503DF5817D315AC54E6921AD2E556BFE8C58C6EE5D6876ED1666A05D8F4C67BD7820BB9EB809798BCFC17776B68E1FA5D2ED8B3DB1354CDCEC36D0C2721EDB80DE1043BFEB60461AC6BCD44331B4B34CEE9AC4D5AF2F8E87595102847625C550424DF4909A96DC01D64E42D51FB3D138B0216BA8A7113DD83BAF28587C66E3DEAD122E1E79E79F484EDB5DC9813EC04E1184E0E020B43731A619A3288BD44FF88EA08EA11685845E51FBEBDB6297A67295B1EEE9E9B5F3A93D14679CDE14DE9A990E3E325DEC5CC92E7645DF01B61158FDC060F17211E3604F79546539C919FADB5DBAF2956EF9867FEAC5092528CB5B7247040D5F3A9E6532EB5FE444AA014338C55ED08E3D16B736FC0BF0DF");

    //Declare Arrays to store signature, plain text as sequence of integers
    BIGNUM **cipherArray = (BIGNUM **)malloc(num*sizeof(BIGNUM *));
    BIGNUM **plainArray = (BIGNUM **)malloc(num*sizeof(BIGNUM *));

    char *mPart = (char*)calloc(chunk_size, sizeof(char));
    for (int i = 0; i < num; i++) {
        cipherArray[i] = BN_new();
        plainArray[i] = BN_new();
    }

    //Break Signature into sequence of integers in the chunks of 512 bytes/1024 chars
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

    printf("Decrypted Padded Signature: ");
    for(int i = 0; i < num; i++) {
        char *number_str = BN_bn2hex(plainArray[i]);
        strcat(plainMsg, number_str);
        OPENSSL_free(number_str);
    }
    printf("%s\n\n", plainMsg);

    int l = strlen(plainMsg);

    printf("Extracting last 48 bytes or 96 chars since for hashing SHA384 was used which is 48 bytes long\n");

    printf("Decrypted Signature: ");
    printf("%s\n\n", plainMsg+l-96);

    if (strcmp(sha384sum, plainMsg+l-96) == 0) {
        printf("Signature Verified as original sha384sum is same as Decrypted Signature\n");
    } else {
        printf("\nInvalid Signature!\n");
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