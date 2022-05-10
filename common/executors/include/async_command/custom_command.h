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

#ifndef CUSTOM_COMMAND_H
#define CUSTOM_COMMAND_H

#include "async_command_base.h"

namespace OHOS {
namespace UserIAM {
namespace UserAuth {
class CustomCommand : public AsyncCommandBase {
public:
    CustomCommand(std::shared_ptr<Executor> executor, std::shared_ptr<AuthResPool::AuthAttributes> attributes);
    virtual ~CustomCommand() = default;

    void OnAcquireInfo(int32_t acquire, const std::vector<uint8_t> &extraInfo) override;

    ResultCode GetResult();

protected:
    void OnResultInner(ResultCode result, const std::vector<uint8_t> &extraInfo) override;
    ResultCode SendRequest() override;

private:
    std::shared_ptr<AuthResPool::AuthAttributes> attributes_;
    ResultCode result_;
    std::promise<void> promise_;
    std::future<void> future_;
};
} // namespace UserAuth
} // namespace UserIAM
} // namespace OHOS

#endif // CUSTOM_COMMAND_H