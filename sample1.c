#include <stdio.h>
#include <string.h>
#include "_parsepath.h"

int main(int argc, char *argv[])
{
  char *inpath = "/home/user/test.txt";
  char *dname, *bname;
  char dir[SZ_PATH_MAX], base[SZ_PATH_MAX];
  int flg;

  if (argc > 1)
    inpath = argv[1];
  
  flg = _parsepath(inpath, &dname, &bname, NULL);
  if (flg & FLG_DIRNAME) {             /* dirname要素あり ? */
    int n = bname - dname;             /* dir文字数(最後の'/'含む) */
    strncpy(dir, dname, n);
    dir[n] = '\0';
  }
  else {                               /* dirname要素なし */
    strcpy(dir, "");
  }
  
  if (flg & FLG_BASENAME) {            /* basename要素あり ? */
    strcpy(base, bname);
  }
  else {                               /* basename要素なし */
    strcpy(base, "");
  }
  
  printf("dir=%s, base=%s\n", dir, base);   /* "/home/user/", "test.txt" */
  
  return 0;
}
