#include "ProgressViewComponentInstance.h"
#include "Props.h"
#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

// 十进制整数转十六进制字符串
string DecimalToHex(int decimalColor) {
    stringstream ss;
    ss << hex << decimalColor;
    string hexColor = ss.str();
    return hexColor;
}
namespace rnoh {

ProgressViewComponentInstance::ProgressViewComponentInstance(Context context)
    : CppComponentInstance(std::move(context)) {}

ProgressViewNode &ProgressViewComponentInstance::getLocalRootArkUINode() { return m_progressNode; }

std::optional<std::string> ProgressViewComponentInstance::getTintColorFromDynamic(folly::dynamic value,
                                                                                  std::string type) {
    auto rawPropsColor = (value.count(type) > 0) ? std::optional(value[type].asString()) : std::nullopt;
    return rawPropsColor;
}

void ProgressViewComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);
    this->getLocalRootArkUINode().setProgress(props->progress);

//     DLOG(INFO) << "[FastImage] Props->isIndeterminate: " << props->rawProps;
    if (props->rawProps != nullptr) {
        

        auto progressViewStyle = getTintColorFromDynamic(props->rawProps, "progressViewStyle");
        if (progressViewStyle.has_value()) {
            if (progressViewStyle.value() == "default") {
                int type = 0;
                this->getLocalRootArkUINode().setIsIndeterminate(type);
            } else {
                int type = 1;
                this->getLocalRootArkUINode().setIsIndeterminate(type);
            }
        }
        auto progressTintColor = getTintColorFromDynamic(props->rawProps, "progressTintColor");
        if (progressTintColor.has_value()) {
            uint32_t COLOR_ALPHA_MASK = std::stol(progressTintColor.value());
            this->getLocalRootArkUINode().setProgressTintColor(COLOR_ALPHA_MASK);
        }
    }
}

} // namespace rnoh
