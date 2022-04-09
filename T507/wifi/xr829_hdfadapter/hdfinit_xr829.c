/*
 * Copyright (C) 2022 VYAGOO TECHNOLOGY Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "hdf_wifi_product.h"
#include "wifi_mac80211_ops.h"
#include "hdf_wlan_utils.h"

#define HDF_LOG_TAG Xr829Driver

/***********************************************************/
/*      variable and function declare                      */
/***********************************************************/
struct net_device *save_kernel_net = NULL;

/***********************************************************/
/*      variable and function declare                      */
/***********************************************************/
extern int32_t hdf_netdev_init(struct NetDevice *netDev);
extern int32_t hdf_netdev_open(struct NetDevice *netDev);
extern int32_t hdf_netdev_stop(struct NetDevice *netDev);
extern struct net_device *GetLinuxInfByNetDevice(const struct NetDevice *netDevice);
extern void set_krn_netdev(struct net_device *dev);
/***********************************************************/
/*      Function declare                                   */
/***********************************************************/
int32_t InitXr829Chip(struct HdfWlanDevice *device)
{
    HDF_LOGE("%s: start...", __func__);
    return HDF_SUCCESS; 
}

int32_t DeinitXr829Chip(struct HdfWlanDevice *device)
{
    int32_t ret = 0;

    (void)device;
    HDF_LOGE("%s: start...", __func__);
    /*if (ret != 0)
    {
        HDF_LOGE("%s:Deinit failed!ret=%d", __func__, ret);
    }*/
    return ret;
}

int32_t Xr829Init(struct HdfChipDriver *chipDriver, struct NetDevice *netDevice)
{
    struct HdfWifiNetDeviceData *data = NULL;
    struct net_device *netdev = NULL;

    (void)chipDriver;
    HDF_LOGE("%s: start...", __func__);

    if (netDevice == NULL)
    {
        HDF_LOGE("%s:para is null!", __func__);
        return HDF_FAILURE;
    }

    netdev = GetLinuxInfByNetDevice(netDevice);
    if (netdev == NULL) {
        HDF_LOGE("%s net_device is null!", __func__);
        return HDF_FAILURE;
    }

    set_krn_netdev(netdev);

    data = GetPlatformData(netDevice);
    if (data == NULL)
    {
        HDF_LOGE("%s:netdevice data null!", __func__);
        return HDF_FAILURE;
    }

    /* set netdevice ops to netDevice */
    hdf_netdev_init(netDevice);
    netDevice->classDriverPriv = data;

    xradio_init();
    NetDeviceAdd(netDevice);

    HDF_LOGE("%s: success", __func__);

    //ret = hdf_netdev_open(netDevice);
    return HDF_SUCCESS;
}

int32_t Xr829Deinit(struct HdfChipDriver *chipDriver, struct NetDevice *netDevice)
{
    HDF_LOGE("%s: start...", __func__);
    (void)netDevice;
    (void)chipDriver;
    xradio_exit();
    return HDF_SUCCESS;
}

void set_krn_netdev(struct net_device *dev) {
    save_kernel_net = dev;
}

struct net_device *get_krn_netdev(void) {
    return save_kernel_net;
}

EXPORT_SYMBOL(set_krn_netdev);
EXPORT_SYMBOL(get_krn_netdev);
