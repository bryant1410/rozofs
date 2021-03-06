/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _STCPPROTO_H_RPCGEN
#define _STCPPROTO_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#include <rozofs/rozofs.h>

enum stcpp_status_t {
	STCPP_SUCCESS = 0,
	STCPP_FAILURE = 1,
};
typedef enum stcpp_status_t stcpp_status_t;

struct stcpp_status_ret_t {
	stcpp_status_t status;
	union {
		int error;
	} stcpp_status_ret_t_u;
};
typedef struct stcpp_status_ret_t stcpp_status_ret_t;

struct stcpp_profiler_t {
	uint64_t uptime;
	uint64_t now;
	uint8_t vers[20];
	uint64_t stat[2];
	uint64_t ports[2];
	uint64_t remove[2];
	uint64_t read_req[3];
	uint64_t read[3];
	uint64_t trans_inv[3];
	uint64_t write[3];
	uint64_t write_req[3];
	uint64_t trans_forward[3];
	uint64_t truncate[3];
	uint64_t truncate_prj[3];
	uint64_t truncate_prj_tmo[2];
	uint64_t truncate_prj_err[2];
	uint64_t delete[3];
	uint64_t delete_prj[3];
	uint64_t delete_prj_tmo[2];
	uint64_t delete_prj_err[2];
	uint64_t read_prj[3];
	uint64_t write_prj[3];
	uint64_t read_prj_tmo[2];
	uint64_t read_prj_err[2];
	uint64_t read_prj_enoent[2];
	uint64_t read_blk_footer[2];
	uint64_t read_blk_crc[2];
	uint64_t read_blk_prjid[2];
	uint64_t read_blk_corrupted[2];
	uint64_t write_prj_tmo[2];
	uint64_t write_prj_nospace[2];
	uint64_t write_prj_sid_err[2];
	uint64_t write_prj_err[2];
	uint64_t read_sid_miss[2];
	uint64_t write_sid_miss[2];
	uint64_t truncate_sid_miss[2];
	uint64_t repair[3];
	uint64_t repair_prj[3];
	uint64_t repair_prj_tmo[2];
	uint64_t repair_prj_err[2];
	uint64_t resize[2];
	uint64_t resize_prj[2];
	uint64_t resize_prj_err[2];
	uint16_t io_process_ports[32];
};
typedef struct stcpp_profiler_t stcpp_profiler_t;

struct stcpp_profiler_ret_t {
	stcpp_status_t status;
	union {
		stcpp_profiler_t profiler;
		int error;
	} stcpp_profiler_ret_t_u;
};
typedef struct stcpp_profiler_ret_t stcpp_profiler_ret_t;

#define STORCLI_PROFILE_PROGRAM 0x20000008
#define STORCLI_PROFILE_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define STCPP_NULL 0
extern  void * stcpp_null_1(void *, CLIENT *);
extern  void * stcpp_null_1_svc(void *, struct svc_req *);
#define STCPP_GET_PROFILER 1
extern  stcpp_profiler_ret_t * stcpp_get_profiler_1(void *, CLIENT *);
extern  stcpp_profiler_ret_t * stcpp_get_profiler_1_svc(void *, struct svc_req *);
#define STCPP_CLEAR 2
extern  stcpp_status_ret_t * stcpp_clear_1(void *, CLIENT *);
extern  stcpp_status_ret_t * stcpp_clear_1_svc(void *, struct svc_req *);
extern int storcli_profile_program_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define STCPP_NULL 0
extern  void * stcpp_null_1();
extern  void * stcpp_null_1_svc();
#define STCPP_GET_PROFILER 1
extern  stcpp_profiler_ret_t * stcpp_get_profiler_1();
extern  stcpp_profiler_ret_t * stcpp_get_profiler_1_svc();
#define STCPP_CLEAR 2
extern  stcpp_status_ret_t * stcpp_clear_1();
extern  stcpp_status_ret_t * stcpp_clear_1_svc();
extern int storcli_profile_program_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_stcpp_status_t (XDR *, stcpp_status_t*);
extern  bool_t xdr_stcpp_status_ret_t (XDR *, stcpp_status_ret_t*);
extern  bool_t xdr_stcpp_profiler_t (XDR *, stcpp_profiler_t*);
extern  bool_t xdr_stcpp_profiler_ret_t (XDR *, stcpp_profiler_ret_t*);

#else /* K&R C */
extern bool_t xdr_stcpp_status_t ();
extern bool_t xdr_stcpp_status_ret_t ();
extern bool_t xdr_stcpp_profiler_t ();
extern bool_t xdr_stcpp_profiler_ret_t ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_STCPPROTO_H_RPCGEN */
