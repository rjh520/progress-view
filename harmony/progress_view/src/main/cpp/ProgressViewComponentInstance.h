#pragma once
#include "ShadowNodes.h"
#include "ProgressViewNode.h"
#include "RNOH/CppComponentInstance.h"

namespace rnoh {
class ProgressViewComponentInstance : public CppComponentInstance<facebook::react::RNCProgressViewShadowNode> {
private:
    ProgressViewNode m_progressNode;
    std::optional<std::string> getTintColorFromDynamic(folly::dynamic value,std::string type);

public:
    ProgressViewComponentInstance(Context context);

    ProgressViewNode &getLocalRootArkUINode() override;

protected:
    void onPropsChanged(SharedConcreteProps const &props) override;
};
} // namespace rnoh