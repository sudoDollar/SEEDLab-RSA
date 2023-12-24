#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM * a)
{
   /* Use BN_bn2hex(a) for hex string
    * Use BN_bn2dec(a) for decimal string */
   char * number_str = BN_bn2hex(a);
   printf("%s %s\n", msg, number_str);
   OPENSSL_free(number_str);
}

int main ()
{
  BN_CTX *ctx = BN_CTX_new();

  BIGNUM *p = BN_new();
  BIGNUM *q = BN_new();
  BIGNUM *e = BN_new();
  BIGNUM *n = BN_new();
  BIGNUM *one = BN_new();
  BIGNUM *phi = BN_new();
  BIGNUM *res = BN_new();

  // Initialize p, q, e, n, one
  BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
  BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
  BN_hex2bn(&e, "0D88C3");
  BN_hex2bn(&one, "1");
  BN_mul(n, p, q, ctx); // n=p*q

  //Calc Euler totient function of n  phi(n) = pq-q-p+1
  BN_sub(phi, n, q);
  BN_sub(phi, phi, p);
  BN_add(phi, phi, one);

  //Calculate private key d
  BN_mod_inverse(res, e, phi, ctx);
  printBN("Private key d = ", res);

  /* Clean up. */
  BN_free(p);
  BN_free(q);
  BN_free(e);
  BN_free(n);
  BN_free(phi);
  BN_free(one);
  BN_free(res);
  BN_CTX_free(ctx);

  return 0;
}
