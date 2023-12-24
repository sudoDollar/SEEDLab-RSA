### Website: www.microsoft.com:443

root@ubuntu-seed-lab-dollar:~/lab3# openssl s_client -connect www.microsoft.com:443 -showcerts
CONNECTED(00000003)
depth=2 C = US, O = DigiCert Inc, OU = www.digicert.com, CN = DigiCert Global Root G2
verify return:1
depth=1 C = US, O = Microsoft Corporation, CN = Microsoft Azure RSA TLS Issuing CA 07
verify return:1
depth=0 C = US, ST = WA, L = Redmond, O = Microsoft Corporation, CN = www.microsoft.com
verify return:1
---
Certificate chain
---
 0 s:C = US, ST = WA, L = Redmond, O = Microsoft Corporation, CN = www.microsoft.com
   i:C = US, O = Microsoft Corporation, CN = Microsoft Azure RSA TLS Issuing CA 07
  ```
    -----BEGIN CERTIFICATE-----
    MIII5TCCBs2gAwIBAgITMwAD4s0QZq2NuBwGCAAAAAPizTANBgkqhkiG9w0BAQwF
    ADBdMQswCQYDVQQGEwJVUzEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBvcmF0aW9u
    MS4wLAYDVQQDEyVNaWNyb3NvZnQgQXp1cmUgUlNBIFRMUyBJc3N1aW5nIENBIDA3
    MB4XDTIzMDkxNDE3MjQyMFoXDTI0MDkwODE3MjQyMFowaDELMAkGA1UEBhMCVVMx
    CzAJBgNVBAgTAldBMRAwDgYDVQQHEwdSZWRtb25kMR4wHAYDVQQKExVNaWNyb3Nv
    ZnQgQ29ycG9yYXRpb24xGjAYBgNVBAMTEXd3dy5taWNyb3NvZnQuY29tMIIBIjAN
    BgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAsmbP4PGEgfIltEV/Wt6NFwC3OkbR
    mtLc/+W9EsJUZNyQZLC5TlLOOy0ux67HPMoiSZrQRJLn99IQJbRXTTZbRR7jz4I9
    e8qYO5VehFS0RHkT6M3XYeDTDQfQOAPO7jbZgMKP9XgGqZXsbqoBKyFRPrszVzZW
    Zc+dGlZTQnMYkAhltEGgEL8+fN25Gquavt6WSY2vc9Li2Yj9Eoo4+Eo4zJMCKVPE
    4bsyC40BBaJEyU5pTdaVMI8K0pyKkLvt2kklryXaamjU9K/zee1joPYGRqVr9fl3
    +hJ1ia0VzdnFq3tP+wXFlEr+m8MtpQTwha1Elx1hnuRmFG/YPa9qj+RlNQIDAQAB
    o4IEkTCCBI0wggF+BgorBgEEAdZ5AgQCBIIBbgSCAWoBaAB3AHb/iD8KtvuVUcJh
    zPWHujS0pM27KdxoQgqf5mdMWjp0AAABipTCG8UAAAQDAEgwRgIhAK9VBkhYoGD8
    smdZpGblkGIxh+s76J9DIu2vylLOSX5DAiEAnW9VG6vFtyf+iv+LTiGE0ISGr0hh
    itmTJxsgsbV2MQAAdQDatr9rP7W2Ip+bwrtca+hwkXFsu1GEhTS9pD0wSNf7qwAA
    AYqUwhw0AAAEAwBGMEQCIGchMFlY/hrw6qyerVfS+IgchU160ugObUp6bbXLcU5x
    AiBNOYgiepuAhstFR0OjvTwG0t2oRk8qr+S6/m6vFVAjTgB2AO7N0GTV2xrOxVy3
    nbTNE6Iyh0Z8vOzew1FIWUZxH7WbAAABipTCG+0AAAQDAEcwRQIgdPH1Un+uZYyz
    /miP1BfUdhmr7FxUSF64j76xNfBr+1ECIQCzUfOkMZuP6HwcBvqUKVnpgGrdGqRl
    FWInDI0GIWts+DAnBgkrBgEEAYI3FQoEGjAYMAoGCCsGAQUFBwMCMAoGCCsGAQUF
    BwMBMDwGCSsGAQQBgjcVBwQvMC0GJSsGAQQBgjcVCIe91xuB5+tGgoGdLo7QDIfw
    2h1dgoTlaYLzpz4CAWQCASYwgbQGCCsGAQUFBwEBBIGnMIGkMHMGCCsGAQUFBzAC
    hmdodHRwOi8vd3d3Lm1pY3Jvc29mdC5jb20vcGtpb3BzL2NlcnRzL01pY3Jvc29m
    dCUyMEF6dXJlJTIwUlNBJTIwVExTJTIwSXNzdWluZyUyMENBJTIwMDclMjAtJTIw
    eHNpZ24uY3J0MC0GCCsGAQUFBzABhiFodHRwOi8vb25lb2NzcC5taWNyb3NvZnQu
    Y29tL29jc3AwHQYDVR0OBBYEFJRG0f2FZsvVCZPogua5ie3N5ocKMA4GA1UdDwEB
    /wQEAwIFoDCBmQYDVR0RBIGRMIGOghN3d3dxYS5taWNyb3NvZnQuY29tghF3d3cu
    bWljcm9zb2Z0LmNvbYIYc3RhdGljdmlldy5taWNyb3NvZnQuY29tghFpLnMtbWlj
    cm9zb2Z0LmNvbYINbWljcm9zb2Z0LmNvbYIRYy5zLW1pY3Jvc29mdC5jb22CFXBy
    aXZhY3kubWljcm9zb2Z0LmNvbTAMBgNVHRMBAf8EAjAAMGoGA1UdHwRjMGEwX6Bd
    oFuGWWh0dHA6Ly93d3cubWljcm9zb2Z0LmNvbS9wa2lvcHMvY3JsL01pY3Jvc29m
    dCUyMEF6dXJlJTIwUlNBJTIwVExTJTIwSXNzdWluZyUyMENBJTIwMDcuY3JsMGYG
    A1UdIARfMF0wUQYMKwYBBAGCN0yDfQEBMEEwPwYIKwYBBQUHAgEWM2h0dHA6Ly93
    d3cubWljcm9zb2Z0LmNvbS9wa2lvcHMvRG9jcy9SZXBvc2l0b3J5Lmh0bTAIBgZn
    gQwBAgIwHwYDVR0jBBgwFoAUzhUWO+oCo6Zr2tkr/eWMUr56UKgwHQYDVR0lBBYw
    FAYIKwYBBQUHAwIGCCsGAQUFBwMBMA0GCSqGSIb3DQEBDAUAA4ICAQBuwQV+NfkB
    BeNDMcuY1XwsnYhREpo03+hghAjMLwgY7HhwRD46jnTFdD+l9JUv4uXU5vy/UreZ
    JbTia0mD76MWwrr70ntDum3nPRLyMDDtr3/n/ZnopCFMrk9WPiITOvcarpNznvaa
    kbDWZccj4s6yHafKsruq2wDF5f/LtIRUt3D8pFLZ1nTmbLyiKcV7BKlaGUJyw83B
    yCBj2ED0ynKqgssXfO8vdTDzBjMsiY1LtcW0AzlqA20o+7XUxCYmwVyx+3/TKSHs
    elRE4hxEZ5lDHwnm2XLBls/BGA/bjIIMRwj+FqKax2jgNA0vBeeLeOt8d75LyupP
    147snQDbauEeHRbrJKmDnpdE1JVsVWnYoEj5O39wQb4uBJ1e7SxDdkieydLQyNcJ
    qJL/DDEtqlXn7BVunNNb6cPYH+d/KZYdF/Xgp9M0VepIvm8wgnnTNgW66RZTPwT2
    7fbI+rnR8lrHSJcFmDPPC7j4IM0RNo2bmEGI4EX9GR7XZ5fuylS1NEIlrap9HIPq
    TOR+MsPH4AeH9UyiYvOmxUNZIRTcQwxfWOEEZmvLpzVvROqIy7yxX5f3KGW4Cf45
    Unyb2Oj6CDA9YFEcjRuaZBDtSKJ6AYOWFJO7CIHsjAZ0rBqfyfNdBd5DG4+ZJkD8
    50WeBZCdbW0GmufXnB4Oa1oIOywDyOG6eQ==
    -----END CERTIFICATE-----
  ```
---
 1 s:C = US, O = Microsoft Corporation, CN = Microsoft Azure RSA TLS Issuing CA 07
   i:C = US, O = DigiCert Inc, OU = www.digicert.com, CN = DigiCert Global Root G2
  ```
    -----BEGIN CERTIFICATE-----
    MIIFrDCCBJSgAwIBAgIQCkOpUJsBNS+JlXnscgi6UDANBgkqhkiG9w0BAQwFADBh
    MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3
    d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBH
    MjAeFw0yMzA2MDgwMDAwMDBaFw0yNjA4MjUyMzU5NTlaMF0xCzAJBgNVBAYTAlVT
    MR4wHAYDVQQKExVNaWNyb3NvZnQgQ29ycG9yYXRpb24xLjAsBgNVBAMTJU1pY3Jv
    c29mdCBBenVyZSBSU0EgVExTIElzc3VpbmcgQ0EgMDcwggIiMA0GCSqGSIb3DQEB
    AQUAA4ICDwAwggIKAoICAQC1ZF7KYus5OO3GWqJoR4xznLDNCjocogqeCIVdi4eE
    BmF3zIYeuXXNoJAUF+mn86NBt3yMM0559JZDkiSDi9MpA2By4yqQlTHzfbOrvs7I
    4LWsOYTEClVFQgzXqa2ps2g855HPQW1hZXVh/yfmbtrCNVa//G7FPDqSdrAQ+M8w
    0364kyZApds/RPcqGORjZNokrNzYcGub27vqE6BGP6XeQO5YDFobi9BvvTOO+ZA9
    HGIU7FbdLhRm6YP+FO8NRpvterfqZrRt3bTn8GT5LsOTzIQgJMt4/RWLF4EKNc97
    CXOSCZFn7mFNx4SzTvy23B46z9dQPfWBfTFaxU5pIa0uVWv+jFjG7l1odu0WZqBd
    j0xnvXggu564CXmLz8F3draOH6XS7Ys9sTVM3Ow20MJyHtuA3hBDv+tgRhrGvNRD
    MbSzTO6axNWvL46HWVEChHYlxVBCTfSQmpbcAdZOQtUfs9E4sCFrqKcRPdg7ryhY
    fGbj3q0SLh55559ITttdyYE+wE4RhODgILQ3MaYZoyiL1E/4jqCOoRaFhF5R++vb
    YpemcpWx7unptfOpPRRnnN4U3pqZDj4yXexcyS52Rd8BthFY/cBg8XIR42BPeVRl
    OckZ+ttduvKVbvmGf+rFCSUoy1tyRwQNXzqeZTLrX+REqgFDOMVe0I49Frc2/Avw
    3wIDAQABo4IBYjCCAV4wEgYDVR0TAQH/BAgwBgEB/wIBADAdBgNVHQ4EFgQUzhUW
    O+oCo6Zr2tkr/eWMUr56UKgwHwYDVR0jBBgwFoAUTiJUIBiV5uNu5g/6+rkS7QYX
    jzkwDgYDVR0PAQH/BAQDAgGGMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcD
    AjB2BggrBgEFBQcBAQRqMGgwJAYIKwYBBQUHMAGGGGh0dHA6Ly9vY3NwLmRpZ2lj
    ZXJ0LmNvbTBABggrBgEFBQcwAoY0aHR0cDovL2NhY2VydHMuZGlnaWNlcnQuY29t
    L0RpZ2lDZXJ0R2xvYmFsUm9vdEcyLmNydDBCBgNVHR8EOzA5MDegNaAzhjFodHRw
    Oi8vY3JsMy5kaWdpY2VydC5jb20vRGlnaUNlcnRHbG9iYWxSb290RzIuY3JsMB0G
    A1UdIAQWMBQwCAYGZ4EMAQIBMAgGBmeBDAECAjANBgkqhkiG9w0BAQwFAAOCAQEA
    bbV8m4/LCSvb0nBF9jb7MVLH/9JjHGbn0QjB4R4bMlGHbDXDWtW9pFqMPrRh2Q76
    Bqm+yrrgX83jPZAcvOd7F7+lzDxZnYoFEWhxW9WnuM8Te5x6HBPCPRbIuzf9pSUT
    /ozvbKFCDxxgC2xKmgp6NwxRuGcy5KQQh4xkq/hJrnnF3RLakrkUBYFPUneip+wS
    BzAfK3jHXnkNCPNvKeLIXfLMsffEzP/j8hFkjWL3oh5yaj1HmlW8RE4Tl/GdUVzQ
    D1x42VSusQuRGtuSxLhzBNBeJtyD//2u7wY2uLYpgK0o3X0iIJmwpt7Ovp6Bs4tI
    E/peia+Qcdk9Qsr+1VgCGA==
    -----END CERTIFICATE-----
  ```
---
Server certificate
subject=C = US, ST = WA, L = Redmond, O = Microsoft Corporation, CN = www.microsoft.com

issuer=C = US, O = Microsoft Corporation, CN = Microsoft Azure RSA TLS Issuing CA 07

---
No client certificate CA names sent
Peer signing digest: SHA256
Peer signature type: RSA-PSS
Server Temp Key: X25519, 253 bits
---
SSL handshake has read 4312 bytes and written 389 bytes
Verification: OK
---
New, TLSv1.3, Cipher is TLS_AES_256_GCM_SHA384
Server public key is 2048 bit
Secure Renegotiation IS NOT supported
Compression: NONE
Expansion: NONE
No ALPN negotiated
Early data was not sent
Verify return code: 0 (ok)
---
---
Post-Handshake New Session Ticket arrived:
SSL-Session:
    Protocol  : TLSv1.3
    Cipher    : TLS_AES_256_GCM_SHA384
    Session-ID: CD80F9B0AC09DD39F113B6DE3BE915C81BC15870CE397ECD59B5CBA4DDCF6E4A
    Session-ID-ctx: 
    Resumption PSK: 0FFD447EDF10ACFD0CD839153A229DCA348CCEDB9AC73BC995694127CF62C2156136DD48A6ADF6B17891553E33122FA6
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 83100 (seconds)
    TLS session ticket:
    0000 - 00 00 35 6e 53 d5 49 14-7d ee f3 c9 ca f5 80 2e   ..5nS.I.}.......
    0010 - 77 e2 78 15 9f 37 91 90-b5 00 a2 be 4f d4 35 b6   w.x..7......O.5.
    0020 - 9a ff 19 a1 16 78 32 f3-76 05 87 19 89 76 6b a6   .....x2.v....vk.
    0030 - f7 84 78 c6 86 53 c9 1c-be ea 30 fa 7c bd cf e0   ..x..S....0.|...
    0040 - 85 8e 21 cd 66 a3 46 a7-c0 2f f7 4d ae 5a 7e 1b   ..!.f.F../.M.Z~.
    0050 - 80 1d c4 59 00 82 84 8d-ee 54 b7 67 8c ed 7d f9   ...Y.....T.g..}.
    0060 - 04 00 8a a0 92 ec 30 ea-41 af 79 8a e5 4e f3 4a   ......0.A.y..N.J
    0070 - 0b 37 e7 97 b4 a4 4c 39-43 6d 6f e9 08 80 5d dd   .7....L9Cmo...].
    0080 - b2 cf a7 21 75 2a e2 9c-ed c2 30 49 c5 64 9e 40   ...!u*....0I.d.@
    0090 - 93 b2 a9 e4 63 ae 54 44-7f 8d 86 f9 fc 58 33 a1   ....c.TD.....X3.
    00a0 - af 78 b3 c0 cc 9a ca b4-b3 5d 4d fe ea da 02 62   .x.......]M....b
    00b0 - 83 7f 9c 22 70 7a b1 39-cb 81 73 2d 08 c5 9a 2e   ..."pz.9..s-....
    00c0 - 55 83 f1 36 ed d1 79 e8-82 15 48 fe 10 fc f8 8a   U..6..y...H.....
    00d0 - 60 eb 68 80 f7 1a bd 0e-a3 88 14 6a e3 47 c5 a5   `.h........j.G..

    Start Time: 1703395038
    Timeout   : 7200 (sec)
    Verify return code: 0 (ok)
    Extended master secret: no
    Max Early Data: 0
---
read R BLOCK
---
Post-Handshake New Session Ticket arrived:
SSL-Session:
    Protocol  : TLSv1.3
    Cipher    : TLS_AES_256_GCM_SHA384
    Session-ID: E22CC57E91A8D49E64294CE92160908C7F1D3FDB2F1890AE724489A998930A60
    Session-ID-ctx: 
    Resumption PSK: 4A9EFA76A96FE75C09DAAA4445068604DB1FBE3EB50F90CB8F072F406BB48E38A9CD886C768F5EF1587923DAA3D67748
    PSK identity: None
    PSK identity hint: None
    SRP username: None
    TLS session ticket lifetime hint: 83100 (seconds)
    TLS session ticket:
    0000 - 00 00 35 6e 53 d5 49 14-7d ee f3 c9 ca f5 80 2e   ..5nS.I.}.......
    0010 - 7f 59 bf 6d 10 ea a4 8f-a9 cd 26 53 5c 33 c5 ec   .Y.m......&S\3..
    0020 - 0b 22 c2 af dd 7a 7b 63-0b 7f 1b 41 d5 99 59 ce   ."...z{c...A..Y.
    0030 - dd 38 65 30 c8 43 e0 8e-91 d9 48 c5 6f 07 8d 97   .8e0.C....H.o...
    0040 - 28 37 58 ca 97 bc 45 46-b8 f7 16 66 7f 35 6a 7b   (7X...EF...f.5j{
    0050 - 4d 82 ba 30 09 18 03 c5-59 09 fa 7c 6d 87 ed 83   M..0....Y..|m...
    0060 - ff 70 02 13 8c ae df 7f-57 57 f2 9c 03 08 1e df   .p......WW......
    0070 - 93 f0 82 72 8b 58 b0 9f-ab 34 6d 0a 2c 7d e3 93   ...r.X...4m.,}..
    0080 - 17 c2 a0 d3 ed ae 6b b7-61 dd dd fc 8d 2c 9e f1   ......k.a....,..
    0090 - 77 5b 80 e2 16 74 12 01-de 58 67 ea e1 d2 7a 80   w[...t...Xg...z.
    00a0 - 41 f7 e3 d0 53 19 9d e4-35 02 d5 3c d3 5d 06 a9   A...S...5..<.]..
    00b0 - 63 46 22 1a 61 e6 3e 9c-78 e4 c7 6c 9d 5c ff 64   cF".a.>.x..l.\.d
    00c0 - 48 ef 97 25 84 30 78 8e-68 8e db 07 7e 20 b3 ac   H..%.0x.h...~ ..
    00d0 - 83 4b e3 85 d0 25 de 3d-d1 46 b5 17 5b d6 da 2b   .K...%.=.F..[..+

    Start Time: 1703395038
    Timeout   : 7200 (sec)
    Verify return code: 0 (ok)
    Extended master secret: no
    Max Early Data: 0
---
read R BLOCK
closed
