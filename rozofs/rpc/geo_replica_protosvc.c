/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "geo_replica_proto.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif
#include <rozofs/rozofs.h>

void
geo_program_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		geo_sync_req_arg_t geo_sync_req_1_arg;
		geo_sync_get_next_req_arg_t geo_sync_get_next_req_1_arg;
		geo_sync_delete_req_arg_t geo_sync_delete_req_1_arg;
		geo_sync_close_req_arg_t geo_sync_close_req_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case GEO_NULL:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) geo_null_1_svc;
		break;

	case GEO_SYNC_REQ:
		_xdr_argument = (xdrproc_t) xdr_geo_sync_req_arg_t;
		_xdr_result = (xdrproc_t) xdr_geo_sync_req_ret_t;
		local = (char *(*)(char *, struct svc_req *)) geo_sync_req_1_svc;
		break;

	case GEO_SYNC_GET_NEXT_REQ:
		_xdr_argument = (xdrproc_t) xdr_geo_sync_get_next_req_arg_t;
		_xdr_result = (xdrproc_t) xdr_geo_sync_req_ret_t;
		local = (char *(*)(char *, struct svc_req *)) geo_sync_get_next_req_1_svc;
		break;

	case GEO_SYNC_DELETE_REQ:
		_xdr_argument = (xdrproc_t) xdr_geo_sync_delete_req_arg_t;
		_xdr_result = (xdrproc_t) xdr_geo_status_ret_t;
		local = (char *(*)(char *, struct svc_req *)) geo_sync_delete_req_1_svc;
		break;

	case GEO_SYNC_CLOSE_REQ:
		_xdr_argument = (xdrproc_t) xdr_geo_sync_close_req_arg_t;
		_xdr_result = (xdrproc_t) xdr_geo_status_ret_t;
		local = (char *(*)(char *, struct svc_req *)) geo_sync_close_req_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}