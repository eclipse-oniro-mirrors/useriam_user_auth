/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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

#include "useriam_common.h"

extern "C" {
#include <sys/stat.h>
#include <unistd.h>

#include "pool.h"
#include "idm_database.h"
#include "coauth.h"
#include "context_manager.h"
#include "adaptor_log.h"
#include "lock.h"
#include "token_key.h"
}

namespace OHOS {
namespace UserIAM {
namespace Common {
static bool g_isInitUserIAM = false;

int32_t Init()
{
    GlobalLock();
    if (InitUserAuthContextList() != RESULT_SUCCESS) {
        LOG_ERROR("init user auth failed");
        goto FAIL;
    }

    if (InitResourcePool() != RESULT_SUCCESS) {
        LOG_ERROR("init resource pool failed");
        goto FAIL;
    }
    if (InitUserInfoList() != RESULT_SUCCESS) {
        LOG_ERROR("init user info failed");
        goto FAIL;
    }
    if (InitCoAuth() != RESULT_SUCCESS) {
        LOG_ERROR("init user auth failed");
        goto FAIL;
    }
    if (InitTokenKey() != RESULT_SUCCESS) {
        LOG_ERROR("init token key failed");
        goto FAIL;
    }
    g_isInitUserIAM = true;
    GlobalUnLock();
    return RESULT_SUCCESS;

FAIL:
    Close();
    GlobalUnLock();
    return RESULT_UNKNOWN;
}

int32_t Close()
{
    GlobalLock();
    DestoryUserAuthContextList();
    DestoryCoAuth();
    DestroyUserInfoList();
    DestroyResourcePool();
    g_isInitUserIAM = false;
    GlobalUnLock();
    return RESULT_SUCCESS;
}

bool IsIAMInited()
{
    return g_isInitUserIAM;
}
} // Common
} // UserIAM
} // OHOS