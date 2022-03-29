#
# Copyright (C) 2022 VYAGOO TECHNOLOGY Co., Ltd.
#
# HDF is dual licensed: you can use it either under the terms of
# the GPL, or the BSD license, at your option.
# See the LICENSE file in the root of this repository for complete details.
#
WIFI_CONFIG_PATH := $(shell pwd)
$(warning WIFI_CONFIG_PATH=$(WIFI_CONFIG_PATH))

HDF_FRAMEWORKS_INC := \
    -I./ \
    -Idrivers/hdf/framework/ability/sbuf/include \
    -Idrivers/hdf/framework/core/common/include/host \
    -Idrivers/hdf/framework/core/host/include \
    -Idrivers/hdf/framework/core/manager/include \
    -Idrivers/hdf/framework/core/shared/include \
    -Idrivers/hdf/framework/include \
    -Idrivers/hdf/framework/include/config \
    -Idrivers/hdf/framework/include/core \
    -Idrivers/hdf/framework/include/platform \
    -Idrivers/hdf/framework/include/utils \
    -Idrivers/hdf/framework/support/platform/include \
    -Idrivers/hdf/framework/support/platform/include/platform \
    -Idrivers/hdf/framework/utils/include \
    -Idrivers/hdf/khdf/osal/include \
    -Idrivers/hdf/khdf/config/include \
    -Iinclude/hdf \
    -Iinclude/hdf/osal \
    -Iinclude/hdf/utils \
    -Idrivers/hdf/framework/include/ethernet\
    -Idrivers/hdf/framework/include/net\
    -Idrivers/hdf/framework/model/network/common/netdevice\
    -Idrivers/hdf/framework/include/wifi\
    -Idrivers/hdf/framework/model/network/wifi/platform/include \
    -Idrivers/hdf/framework/model/network/wifi/core/components/eapol



HDF_WIFI_FRAMEWORKS_INC := \
    -Idrivers/hdf/framework/model/network/ethernet/include \
    -Idrivers/hdf/framework/model/network/wifi/include

SECURE_LIB_INC := \
    -I./../../../../../third_party/bounds_checking_function/include

HDF_WIFI_ADAPTER_INC := \
    -Idrivers/hdf/khdf/network/include
