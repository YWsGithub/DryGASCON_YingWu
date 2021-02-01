**Compile main.c in Opt-le32 :**
1. Download the folder Opt-le32
2. Open the Terminal in Opt-le32
3. Type `$gcc main.c drygascon128k32.c`
4. Type `$./a.out` to test the code

**Test the code :**
1. Follow the documetation **_drygascon-spec-round2.pdf_** p.83-84 Listing 20 
2. For example :  
   * Typing `$./a.out` means no message so the ouput should be the same as "Digest" of Hash 0 bytes message,<br>which is `1EDC77386E20A37C721D6E77ADABB9C4830F199F5ED25284A13C1D84B9FC257A`
   * Typing `$./a.out 00` means Hash 1 bytes message so the output should be<br>`1BEC89506E75D725BF93BCCFDD6EC81DF05CA281CF5201E3EE0865A7063763EE`
   
   


