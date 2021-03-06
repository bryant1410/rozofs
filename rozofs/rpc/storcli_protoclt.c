/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "storcli_proto.h"
#include <rozofs/rozofs.h>

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

void *
storcli_null_1(void *argp, CLIENT *clnt)
{
	static char clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, STORCLI_NULL,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_void, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return ((void *)&clnt_res);
}

storcli_status_ret_t *
storcli_write_1(storcli_write_arg_t *argp, CLIENT *clnt)
{
	static storcli_status_ret_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, STORCLI_WRITE,
		(xdrproc_t) xdr_storcli_write_arg_t, (caddr_t) argp,
		(xdrproc_t) xdr_storcli_status_ret_t, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

storcli_read_ret_t *
storcli_read_1(storcli_read_arg_t *argp, CLIENT *clnt)
{
	static storcli_read_ret_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, STORCLI_READ,
		(xdrproc_t) xdr_storcli_read_arg_t, (caddr_t) argp,
		(xdrproc_t) xdr_storcli_read_ret_t, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

storcli_status_ret_t *
storcli_truncate_1(storcli_truncate_arg_t *argp, CLIENT *clnt)
{
	static storcli_status_ret_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, STORCLI_TRUNCATE,
		(xdrproc_t) xdr_storcli_truncate_arg_t, (caddr_t) argp,
		(xdrproc_t) xdr_storcli_status_ret_t, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

storcli_status_ret_t *
storcli_delete_1(storcli_delete_arg_t *argp, CLIENT *clnt)
{
	static storcli_status_ret_t clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, STORCLI_DELETE,
		(xdrproc_t) xdr_storcli_delete_arg_t, (caddr_t) argp,
		(xdrproc_t) xdr_storcli_status_ret_t, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
