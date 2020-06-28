/**
 * @file   _parsepath.h
 * @brief  Parse a file elements from a string function header.
 * @author T.Yokobayashi de JR4QPV
 * @date   2020/06/28
 */
#ifndef ___PARSEPATH_H__
#define ___PARSEPATH_H__

/**** Constant define ****/
#define	SZ_PATH_MAX       (256)

#define	FLG_EXTENSION     (1)
#define	FLG_FILENAME      (2)
#define	FLG_DIRNAME       (4)
#define	FLG_BASENAME      (8)
#define	FLG_WILDCARDS     (0x10)
#define	FLG_ABSPATH       (0x20)

/**** Interface define ****/
#ifdef __cplusplus
extern "C" {
#endif

/* ----- _parsepath.c ----- */
extern int _parsepath(const char *path, char **dirpos, char **basepos, char **extpos);

#ifdef __cplusplus
}
#endif
#endif /* ___PARSEPATH_H__ */

/**
 *----------------------------------------------------------------------------
 * @file   _parsepath.h
 * History
 * -------
 * - 2020/06/28	New created by JR4QPV.
 */
