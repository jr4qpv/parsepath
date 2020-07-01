/**
 * @file   _parsepath.c
 * @brief  Parse a file elements from a string.
 * @author T.Yokobayashi de JR4QPV
 * @date   2020/07/01
 */

#include <string.h>			/* for strlen,strrchr */
#include "_parsepath.h"

/**
 *****************************************************************************
 * @brief  パス文字列からファイル名要素の位置取得
 * @param  path    パス文字列
 * @param  dirpos  ディレクり名要素開始位置の格納先(NULL時は格納しない)
 * @param  basepos ベース名要素開始位置の格納先(NULL時は格納しない)
 * @param  extpos  拡張子名要素開始位置の格納先(NULL時は格納しない)
 * @return 解析結果 ＝0:ファイル要素なし, ≠0:ファイル要素あり(要素フラグ)\n
 *         (FLG_DIRNAME|FLG_BASENAME|FLG_FILENAME|FLG_EXTENSION| \n
 *          FLG_WILDCARDS|FLG_ABSPATH)
 * @details
 *  - pathの文字長が不正の時は「0」を返す。
 *  - ベース名要素には、ファイル名要素と拡張子要素が含まれる。
 *  - pathの内容は変更しない非破壊で、各要素の開始位置のポインタを返す。\n
 *    各要素は、解析結果のポインタ位置から抽出する。
 *  - 各要素は以下で抽出できる。\n
 *    　ディレクトリ名：*dirpos ～ *basepos (通常は'/'で終わる)\n
 *    　ベース名：      *basepos 以降 \n
 *    　ファイル名：    *basepos ～ *extpos \n
 *    　拡張子：        *extpos 以降 ('.'で始まる)
 *
 * @note
 *  - "."と".."はディレクトリ名に判断し、この時は'/'で終わらない。
 * @attention
 *  - マルチバイト文字には非対応。(UTF-8ならたぶん大丈夫)
 *****************************************************************************
 */
int _parsepath(const char *path, char **dirpos, char **basepos, char **extpos)
{
	int n, flg;
	char *p, *dname, *bname, *ename;

	n = strlen(path);
	if ((n <= 0) || (n >= SZ_PATH_MAX))
		return 0;							/* 文字列長が不正 */
	
	dname = bname = (char*)path;
	ename = (char*)&path[n];
	flg = 0;

	/* ディレクトリ名の有無チェック */
	if ((p = strrchr(dname, '/')) != NULL) {
		/* dirname要素あり */
		bname = p+1;
		flg |= FLG_DIRNAME;

		/* 絶対パス名かチェック */
		if (dname[0] == '/')				/* '/'で始まるか ? */
			flg |= FLG_ABSPATH;
	}
	else if ((strcmp(dname, ".") == 0) || (strcmp(dname, "..") == 0)) {
		/* dirname要素あり */
		n = strlen(dname);
		bname = &dname[n];
		flg |= FLG_DIRNAME;
	}

	/* ベース名の有無チェック */
	n = strlen(bname);
	if (n > 0) {
		/* basename要素あり */
		flg |= FLG_BASENAME;

		/* 拡張子の有無チェック */
		if ((p = strrchr(bname, '.')) != NULL) {
			/* ext要素あり */
			ename = p;
			flg |= FLG_EXTENSION;
			
			/* ファイル名の有無チェック */
			if (bname != ename)
				flg |= FLG_FILENAME;
		}

		/* ワイルドカードの有無チェック */
		p = bname;
		while (*p != '\0') {
			if ((*p == '*') || (*p == '?')) {
				flg |= FLG_WILDCARDS;		/* ワイルドカード文字を含む */
				break;
			}
			p++;
		}
	}
	
	/* チェック結果の格納 */
	if (dirpos != NULL) *dirpos = dname;	/* ディレクトリ名開始位置 */
	if (basepos != NULL) *basepos = bname;	/* ベース名開始位置 */
	if (extpos != NULL) *extpos = ename;	/* 拡張子開始位置 */
	
	return flg;
}

/**
 *----------------------------------------------------------------------------
 * @file   _parsepath.c
 * History
 * -------
 * - 2020/06/28	New created by JR4QPV.
 */
