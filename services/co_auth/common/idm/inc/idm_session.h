/*
 * Copyright (C) 2022 Huawei Device Co., Ltd.
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

#ifndef USER_IDM_SESSION_H
#define USER_IDM_SESSION_H

#include "defines.h"
#include "stdint.h"
#include "stdbool.h"

ResultCode OpenEditSession(int32_t userId, uint64_t *challenge);
ResultCode CloseEditSession();

ResultCode AssociateCoauthSchedule(uint64_t scheduleId);
void BreakOffCoauthSchedule(void);

bool IsSessionTimeout(void);
ResultCode GetUserId(int32_t *userId);
ResultCode GetChallenge(uint64_t *challenge);
ResultCode GetScheduleId(uint64_t *scheduleId);

void RefreshValidTokenTime(void);
bool IsValidTokenTime(uint64_t tokenTime);

#endif // USER_IDM_SESSION_H