// Copyright 2018 yuzu emulator team
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include "core/hle/kernel/hle_ipc.h"
#include "core/hle/service/service.h"

namespace Service {
namespace NVFlinger {
class NVFlinger;
}

namespace AM {

class AppletOE final : public ServiceFramework<AppletOE> {
public:
    explicit AppletOE(std::shared_ptr<NVFlinger::NVFlinger> nvflinger,
                      std::shared_ptr<AppletMessageQueue> msg_queue);
    ~AppletOE() override;

    const std::shared_ptr<AppletMessageQueue>& GetMessageQueue() const;

private:
    void OpenApplicationProxy(Kernel::HLERequestContext& ctx);

    std::shared_ptr<NVFlinger::NVFlinger> nvflinger;
    std::shared_ptr<AppletMessageQueue> msg_queue;
};

} // namespace AM
} // namespace Service
