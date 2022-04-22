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

#ifndef AUTH_INFO_H
#define AUTH_INFO_H

#include <iostream>

namespace OHOS {
namespace UserIAM {
namespace CoAuth {
class AuthInfo {
public:
    int32_t GetPkgName(std::string &value);
    int32_t GetCallerUid(uint64_t &value);

    int32_t SetPkgName(std::string value);
    int32_t SetCallerUid(uint64_t value);

private:
    std::string pkgName_;
    uint64_t callerUid_;
};
} // namespace CoAuth
} // namespace UserIAM
} // namespace OHOS

#endif // AUTH_INFO_H
