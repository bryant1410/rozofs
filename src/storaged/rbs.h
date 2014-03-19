/*
 Copyright (c) 2010 Fizians SAS. <http://www.fizians.com>
 This file is part of Rozofs.

 Rozofs is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published
 by the Free Software Foundation, version 2.

 Rozofs is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see
 <http://www.gnu.org/licenses/>.
 */

#ifndef _RBS_H
#define _RBS_H

#include <stdint.h>
#include <limits.h>
#include <uuid/uuid.h>
#include <sys/param.h>

#include <rozofs/rozofs.h>
#include <rozofs/common/list.h>
#include <rozofs/rpc/sclient.h>
#include <rozofs/rpc/mclient.h>

#include "storage.h"


#define RBS_MAX_PARALLEL 36

/* Timeout in seconds for exportd requests */
#define RBS_TIMEOUT_EPROTO_REQUESTS 25
/* Timeout in seconds for storaged requests with mproto */
#define RBS_TIMEOUT_MPROTO_REQUESTS 15
/* Timeout in seconds for storaged requests with sproto */
#define RBS_TIMEOUT_SPROTO_REQUESTS 10

typedef struct _rebuild_fid_input_t {
  fid_t      fid;
  int        cluster;
  int        layout;
  sid_t      dist[ROZOFS_SAFE_MAX];
} rebuild_fid_input_t;

typedef struct rb_entry {
    fid_t fid; ///< unique file identifier associated with the file
    uint8_t layout; ///< layout used for this file.
    sid_t dist_set_current[ROZOFS_SAFE_MAX]; ///< currents sids of storage nodes
    // target for this file.
    sclient_t **storages;
    list_t list;
} rb_entry_t;


typedef struct rb_stor {
    sid_t sid;
    char host[ROZOFS_HOSTNAME_MAX];
    mclient_t mclient;
    sclient_t sclients[STORAGE_NODE_PORTS_MAX];
    uint8_t sclients_nb;
    list_t list;
} rb_stor_t;

typedef struct rb_cluster {
    cid_t cid;
    list_t storages;
    list_t list;
} rb_cluster_t;

/** Rebuild the storage with CID=cid, SID=sid, root_path=root and managed by the
 *  export server with hostname=export_host.
 *
 * @param export_host: export server hostname.
 * @param cid: unique id of cluster that owns this storage.
 * @param sid: the unique id for the storage to rebuild.
 * @param root: the absolute path where rebuild bins file(s) will be store.
 * @param dev: the atotal number of device.
 * @param dev_mapper: the number of device holding header (mapper) files.
 * @param dev_red: the number of replica of header files.
 * @param stor_idx: storage index used for display statistics.
 * @param device: device to rebuild or -1 when all devices.
 * @param config_file: configuration file name
 *---case of one FID to rebuild
 * @param layout: layout of the file
 * @param dist: distribution of the file
 * @param fid2rebuild: FID of the file
 *
 * @return: 0 on success -1 otherwise (errno is set)
 */
int rbs_rebuild_storage(const char *export_host, cid_t cid, sid_t sid,
        const char *root, uint32_t dev, uint32_t dev_mapper, uint32_t dev_red,
	uint8_t stor_idx, int device,
	int parallel, char * config_file, 
	uint8_t layout, uint8_t * dist, fid_t fid2rebuild);

/** Check if possible to rebuild the storage with CID=cid, SID=sid,
 *  root_path=root and managed by the export server with hostname=export_host.
 *
 * @param export_host: export server hostname.
 * @param cid: unique id of cluster that owns this storage.
 * @param sid: the unique id for the storage to rebuild.
 * @param root: the absolute path where rebuild bins file(s) will be store.
 * @param dev: the atotal number of device.
 * @param dev_mapper: the number of device holding header (mapper) files.
 * @param dev_red: the number of replica of header files.
 *
 * @return: 0 on success -1 otherwise (errno is set)
 */
int rbs_sanity_check(const char *export_host, cid_t cid, sid_t sid,
        const char *root, uint32_t dev, uint32_t dev_mapper, uint32_t dev_red);

/** Get name of temporary rebuild directory
 *
 */
char * get_rebuild_directory_name() ;
/** Init connections for storage members of a given cluster but not for the 
 *  storage with sid=sid
 *
 * @param cluster_entries: list of cluster(s).
 * @param cid: unique id of cluster that owns this storage.
 * @param sid: the unique id for the storage to rebuild.
 *
 * @return: 0 on success -1 otherwise (errno is set)
 */
int rbs_init_cluster_cnts(list_t * cluster_entries, cid_t cid,
        sid_t sid);
	
int rbs_get_rb_entry_cnts(rb_entry_t * rb_entry,
        list_t * clusters_list,
        cid_t cid_to_search,
        sid_t sid_to_rebuild,
        uint8_t nb_cnt_required);

int rbs_restore_one_rb_entry(storage_t * st, rb_entry_t * re, char * path, int device_id, uint8_t proj_id_to_rebuild);
int rbs_restore_one_spare_entry(storage_t * st, rb_entry_t * re, char * path, int device_id, uint8_t proj_id_to_rebuild);

#endif