/**
 * Used only in C-API based Architecture.
 */
#pragma once
#include "RNOH/arkui/ArkUINode.h"

namespace rnoh {


class ProgressViewNode : public ArkUINode {
protected:
    ArkUI_NodeHandle m_childArkUINodeHandle;

public:
    ProgressViewNode();
    ProgressViewNode &setProgress(facebook::react::Float value);
    ProgressViewNode &setProgressTintColor(uint32_t sharedColor);
    ProgressViewNode &setIsIndeterminate(int type);
};
} // namespace rnoh